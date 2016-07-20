/* Generated automatically with "cito". Do not edit. */
#ifndef _RECOIL_H_
#define _RECOIL_H_
typedef int cibool;
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef struct RECOIL RECOIL;

RECOIL *RECOIL_New(void);
void RECOIL_Delete(RECOIL *self);

/**
 * Short license notice.
 * Display after the credits.
 */
#define RECOIL_COPYRIGHT  "This program is free software; you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published\nby the Free Software Foundation; either version 2 of the License,\nor (at your option) any later version."

/**
 * Short credits for RECOIL.
 */
#define RECOIL_CREDITS  "Retro Computer Image Library (C) 2009-2016 Piotr Fusik and Adrian Matoga\n"

/**
 * Decodes Atari picture file to an RGB bitmap.
 * Returns <code>true</code> on success.
 * @param filename Name of the file to decode. Only the extension is processed, for format recognition.
 * @param content File contents.
 * @param contentLength File length.
 */
cibool RECOIL_Decode(RECOIL *self, const char *filename, unsigned char const *content, int contentLength);

/**
 * Returns number of unique colors in the decoded picture.
 */
int RECOIL_GetColors(RECOIL *self);

/**
 * Returns the number of alternating frames the pictures is composed of.
 * 
 * <ul>
 * <li>1 means the picture doesn't flicker.</li>
 * <li>2 means the picture is displayed by quickly alternating two sub-pictures.</li>
 * <li>3 means the picture is displayed by alternating three sub-pictures.</li>
 * </ul>
 * 
 */
int RECOIL_GetFrames(RECOIL const *self);

/**
 * Returns decoded image height.
 */
int RECOIL_GetHeight(RECOIL const *self);

/**
 * Returns original height of the decoded image (informational).
 */
int RECOIL_GetOriginalHeight(RECOIL const *self);

/**
 * Returns original width of the decoded image (informational).
 */
int RECOIL_GetOriginalWidth(RECOIL const *self);

/**
 * Returns pixels of the decoded image, top-down, left-to-right.
 * Each pixel is a 24-bit integer 0xRRGGBB.
 */
int const *RECOIL_GetPixels(RECOIL const *self);

/**
 * Returns the computer family of the decoded file format.
 */
const char *RECOIL_GetPlatform(RECOIL const *self);

/**
 * Returns decoded image width.
 */
int RECOIL_GetWidth(RECOIL const *self);

/**
 * Checks whether the filename extension is supported by RECOIL.
 * <code>true</code> doesn't necessarily mean that the file contents is valid for RECOIL.
 * This function is meant to avoid reading files which are known to be
 * not supported (another criterium is the maximum file size, <code>MaxContentLength</code>).
 */
cibool RECOIL_IsOurFile(const char *filename);

/**
 * Maximum length of a supported input file.
 * You may assume that files longer than this are not supported by RECOIL.
 */
#define RECOIL_MAX_CONTENT_LENGTH  6291456

/**
 * Maximum height of a decoded image.
 */
#define RECOIL_MAX_HEIGHT  1200

/**
 * Maximum number of pixels in a decoded image.
 */
#define RECOIL_MAX_PIXELS_LENGTH  1572864

/**
 * Maximum length of a string returned by <code>GetPlatform()</code>.
 */
#define RECOIL_MAX_PLATFORM_LENGTH  21

/**
 * Maximum width of a decoded image.
 */
#define RECOIL_MAX_WIDTH  2048

/**
 * Sets Atari 8-bit palette from a 768-byte array (256 times RGB).
 */
void RECOIL_SetAtari8Palette(RECOIL *self, unsigned char const *content);

/**
 * Converts the decoded picture to palette-indexed.
 * Returns palette of 256 0xRRGGBB entries.
 * Call <code>GetColors()</code> for the actual number of colors.
 * Returns <code>null</code> if conversion fails,
 * because there are more than 256 colors.
 * @param indexes Out: palette-indexed picture.
 */
int const *RECOIL_ToPalette(RECOIL *self, unsigned char *indexes);

/**
 * RECOIL version as a string.
 */
#define RECOIL_VERSION  "3.4.0"

/**
 * RECOIL version - major part.
 */
#define RECOIL_VERSION_MAJOR  3

/**
 * RECOIL version - micro part.
 */
#define RECOIL_VERSION_MICRO  0

/**
 * RECOIL version - minor part.
 */
#define RECOIL_VERSION_MINOR  4

/**
 * Years RECOIL was created in.
 */
#define RECOIL_YEARS  "2009-2016"

#ifdef __cplusplus
}
#endif
#endif
