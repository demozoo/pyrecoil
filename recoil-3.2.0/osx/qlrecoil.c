/*
 * qlrecoil.c - RECOIL plugin for OS X QuickLook
 *
 * Copyright (C) 2014  Petri Pyy and Piotr Fusik
 *
 * This file is part of RECOIL (Retro Computer Image Library),
 * see http://recoil.sourceforge.net
 *
 * RECOIL is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * RECOIL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RECOIL; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libkern/OSAtomic.h>
#include <CoreFoundation/CFPlugInCOM.h>
#include <QuickLook/QuickLook.h>

#include "recoil.h"

#define RECOIL_MAX_EXT_CHARS 5

static CGImageRef CreateImage(CFURLRef url)
{
	CFStringRef ext = CFURLCopyPathExtension(url);
	if (ext == NULL)
		return NULL;
	char filename[2 + RECOIL_MAX_EXT_CHARS + 1];
	filename[0] = 'x';
	filename[1] = '.';
	bool ok = CFStringGetCString(ext, filename + 2, RECOIL_MAX_EXT_CHARS + 1, kCFStringEncodingMacRoman);
	CFRelease(ext);
	if (!ok)
		return NULL;

	CFDataRef data;
	SInt32 errorCode;
	if (!CFURLCreateDataAndPropertiesFromResource(NULL, url, &data, NULL, NULL, &errorCode))
		return NULL;

	RECOIL *recoil = RECOIL_New();
	if (recoil == NULL) {
		CFRelease(data);
		return NULL;
	}
	ok = RECOIL_Decode(recoil, filename, CFDataGetBytePtr(data), CFDataGetLength(data));
	CFRelease(data);
	if (!ok) {
		RECOIL_Delete(recoil);
		return NULL;
	}

	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	if (colorSpace == NULL) {
		RECOIL_Delete(recoil);
		return NULL;
	}
	int width = RECOIL_GetWidth(recoil);
	int height = RECOIL_GetHeight(recoil);
	CGContextRef context = CGBitmapContextCreate((void *) RECOIL_GetPixels(recoil), width, height, 8, width << 2, colorSpace, kCGBitmapByteOrder32Host | kCGImageAlphaNoneSkipFirst);
	CFRelease(colorSpace);
	if (context == NULL) {
		RECOIL_Delete(recoil);
		return NULL;
	}
	CGImageRef image = CGBitmapContextCreateImage(context);
	CFRelease(context);
	RECOIL_Delete(recoil);
	return image;
}

typedef struct
{
	const QLGeneratorInterfaceStruct *vtbl;
	int refCount;
	CFUUIDRef factoryID;
} Plugin;

static ULONG AddRef(void *thisInstance)
{
	Plugin *self = (Plugin *) thisInstance;
	return OSAtomicIncrement32(&self->refCount);
}

static HRESULT QueryInterface(void *thisInstance, REFIID iid, LPVOID *ppv)
{
	CFUUIDRef interfaceID = CFUUIDCreateFromUUIDBytes(kCFAllocatorDefault, iid);
	if (CFEqual(interfaceID, kQLGeneratorCallbacksInterfaceID)) {
		CFRelease(interfaceID);
		AddRef(thisInstance);
		*ppv = thisInstance;
		return S_OK;
	}
	CFRelease(interfaceID);
	*ppv = NULL;
	return E_NOINTERFACE;
}

static void Dealloc(Plugin *self)
{
	CFUUIDRef factoryID = self->factoryID;
	CFPlugInRemoveInstanceForFactory(factoryID);
	CFRelease(factoryID);
	free(self);
}

static ULONG Release(void *thisInstance)
{
	Plugin *self = (Plugin *) thisInstance;
	ULONG r = OSAtomicDecrement32(&self->refCount);
	if (r == 0)
		Dealloc(self);
	return r;
}

static OSStatus GenerateThumbnailForURL(void *thisInstance, QLThumbnailRequestRef thumbnail, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options, CGSize maxSize)
{
	CGImageRef image = CreateImage(url);
	if (image != NULL) {
		QLThumbnailRequestSetImage(thumbnail, image, NULL);
		CFRelease(image);
	}
	return noErr;
}

static void CancelThumbnailGeneration(void* thisInstance, QLThumbnailRequestRef thumbnail)
{
}

static OSStatus GeneratePreviewForURL(void *thisInstance, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options)
{
	CGImageRef image = CreateImage(url);
	if (image == NULL)
		return noErr;

	size_t width = CGImageGetWidth(image);
	size_t height = CGImageGetHeight(image);
	CGContextRef context = QLPreviewRequestCreateContext(preview, CGSizeMake(width, height), true, NULL);
	if (context == NULL) {
		CGImageRelease(image);
		return noErr;
	}
	CGContextDrawImage(context, CGRectMake(0, 0, width, height), image);
	CGImageRelease(image);
	QLPreviewRequestFlushContext(preview, context);
	CFRelease(context);
	return noErr;
}

static void CancelPreviewGeneration(void *thisInstance, QLPreviewRequestRef preview)
{
}

static Plugin *Alloc(CFUUIDRef factoryID)
{
	static const QLGeneratorInterfaceStruct pluginVtbl = {
		NULL,
		QueryInterface,
		AddRef,
		Release,
		GenerateThumbnailForURL,
		CancelThumbnailGeneration,
		GeneratePreviewForURL,
		CancelPreviewGeneration
	};
	Plugin *self = (Plugin *) malloc(sizeof(Plugin));
	self->vtbl = &pluginVtbl;
	self->refCount = 1;
	self->factoryID = CFRetain(factoryID);
	CFPlugInAddInstanceForFactory(factoryID);
	return self;
}

void *QuickLookGeneratorPluginFactory(CFAllocatorRef allocator, CFUUIDRef typeID)
{
	if (CFEqual(typeID, kQLGeneratorTypeID)) {
		CFUUIDRef uuid = CFUUIDCreateFromString(kCFAllocatorDefault, CFSTR("B4EBAF99-E681-49A5-91CA-78459C948EEA"));
		Plugin *result = Alloc(uuid);
		CFRelease(uuid);
		return result;
	}
	return NULL;
}
