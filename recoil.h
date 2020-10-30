// Generated automatically with "cito". Do not edit.
#pragma once
#include <stdbool.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct RECOIL RECOIL;

RECOIL *RECOIL_New(void);
void RECOIL_Delete(RECOIL *self);

/**
 * RECOIL version - major part.
 */
#define RECOIL_VERSION_MAJOR 5

/**
 * RECOIL version - minor part.
 */
#define RECOIL_VERSION_MINOR 1

/**
 * RECOIL version - micro part.
 */
#define RECOIL_VERSION_MICRO 1

/**
 * RECOIL version as a string.
 */
#define RECOIL_VERSION "5.1.1"

/**
 * Years RECOIL was created in.
 */
#define RECOIL_YEARS "2009-2020"

/**
 * Short credits for RECOIL.
 */
#define RECOIL_CREDITS "Retro Computer Image Library (C) 2009-2020 Piotr Fusik and Adrian Matoga\n"

/**
 * Short license notice.
 * Display after the credits.
 */
#define RECOIL_COPYRIGHT "This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version."

/**
 * Maximum length of a supported input file.
 * You may assume that files longer than this are not supported by RECOIL.
 */
#define RECOIL_MAX_CONTENT_LENGTH 6291456

/**
 * Maximum width of a decoded image.
 */
#define RECOIL_MAX_WIDTH 10000

/**
 * Maximum height of a decoded image.
 */
#define RECOIL_MAX_HEIGHT 2560

/**
 * Maximum number of pixels in a decoded image.
 */
#define RECOIL_MAX_PIXELS_LENGTH 2854278

/**
 * Maximum length of a string returned by <code>GetPlatform()</code>.
 */
#define RECOIL_MAX_PLATFORM_LENGTH 21

/**
 * Returns decoded image width.
 * @param self This <code>RECOIL</code>.
 */
int RECOIL_GetWidth(const RECOIL *self);

/**
 * Returns decoded image height.
 * @param self This <code>RECOIL</code>.
 */
int RECOIL_GetHeight(const RECOIL *self);

/**
 * Returns pixels of the decoded image, top-down, left-to-right.
 * Each pixel is a 24-bit integer 0xRRGGBB.
 * @param self This <code>RECOIL</code>.
 */
int const *RECOIL_GetPixels(const RECOIL *self);

/**
 * Returns the computer family of the decoded file format.
 * @param self This <code>RECOIL</code>.
 */
const char *RECOIL_GetPlatform(const RECOIL *self);

/**
 * Returns original width of the decoded image (informational).
 * @param self This <code>RECOIL</code>.
 */
int RECOIL_GetOriginalWidth(const RECOIL *self);

/**
 * Returns original height of the decoded image (informational).
 * @param self This <code>RECOIL</code>.
 */
int RECOIL_GetOriginalHeight(const RECOIL *self);

/**
 * Returns the number of alternating frames the pictures is composed of.
 * 
 * <ul>
 * <li>1 means the picture doesn't flicker.</li>
 * <li>2 means the picture is displayed by quickly alternating two sub-pictures.</li>
 * <li>3 means the picture is displayed by alternating three sub-pictures.</li>
 * </ul>
 * @param self This <code>RECOIL</code>.
 */
int RECOIL_GetFrames(const RECOIL *self);

/**
 * Sets Atari 8-bit palette.
 * @param self This <code>RECOIL</code>.
 * @param content 768-byte array (256 times RGB).
 */
void RECOIL_SetAtari8Palette(RECOIL *self, uint8_t const *content);

/**
 * Checks whether the filename extension is supported by RECOIL.
 * <code>true</code> doesn't necessarily mean that the file contents is valid for RECOIL.
 * This function is meant to avoid reading files which are known to be unsupported.
 * Another criterium is the maximum file size, <code>MaxContentLength</code>.
 * @param filename Name of the file to be checked.
 */
bool RECOIL_IsOurFile(const char *filename);

/**
 * Decodes a picture file to an RGB bitmap.
 * Returns <code>true</code> on success.
 * @param self This <code>RECOIL</code>.
 * @param filename Name of the file to decode. Only the extension is processed, for format recognition.
 * @param content File contents.
 * @param contentLength File length.
 */
bool RECOIL_Decode(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

/**
 * Returns number of unique colors in the decoded picture.
 * @param self This <code>RECOIL</code>.
 */
int RECOIL_GetColors(RECOIL *self);

/**
 * Converts the decoded picture to palette-indexed.
 * Returns palette of 256 0xRRGGBB entries.
 * Call <code>GetColors()</code> for the actual number of colors.
 * Returns <code>null</code> if conversion fails,
 * because there are more than 256 colors.
 * @param self This <code>RECOIL</code>.
 * @param indexes Out: palette-indexed picture.
 */
int const *RECOIL_ToPalette(RECOIL *self, uint8_t *indexes);

#ifdef __cplusplus
}
#endif
