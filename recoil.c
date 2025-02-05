// Generated automatically with "fut". Do not edit.
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "recoil.h"

static int FuInt_Min(int x, int y)
{
	return x < y ? x : y;
}

static int FuInt_Max(int x, int y)
{
	return x > y ? x : y;
}

static char *FuString_Substring(const char *str, size_t len)
{
	char *p = malloc(len + 1);
	memcpy(p, str, len);
	p[len] = '\0';
	return p;
}

static void FuString_AppendSubstring(char **str, const char *suffix, size_t suffixLen)
{
	if (suffixLen == 0)
		return;
	size_t prefixLen = *str == NULL ? 0 : strlen(*str);
	*str = realloc(*str, prefixLen + suffixLen + 1);
	memcpy(*str + prefixLen, suffix, suffixLen);
	(*str)[prefixLen + suffixLen] = '\0';
}

static void FuString_Append(char **str, const char *suffix)
{
	FuString_AppendSubstring(str, suffix, strlen(suffix));
}

static int FuCompare_int(const void *pa, const void *pb)
{
	int a = *(const int *) pa;
	int b = *(const int *) pb;
	return (a > b) - (a < b);
}

/**
 * Platform and pixel ratio.
 */
typedef enum {
	RECOILResolution_AMIGA1X1,
	RECOILResolution_AMIGA2X1,
	RECOILResolution_AMIGA4X1,
	RECOILResolution_AMIGA8X1,
	RECOILResolution_AMIGA1X2,
	RECOILResolution_AMIGA1X4,
	RECOILResolution_AMIGA_DCTV1X1,
	RECOILResolution_AMIGA_DCTV1X2,
	RECOILResolution_AMIGA_HAME1X1,
	RECOILResolution_AMIGA_HAME2X1,
	RECOILResolution_AMSTRAD1X1,
	RECOILResolution_AMSTRAD2X1,
	RECOILResolution_AMSTRAD1X2,
	RECOILResolution_APPLE_I_I1X1,
	RECOILResolution_APPLE_I_IE1X2,
	RECOILResolution_APPLE_I_I_G_S1X1,
	RECOILResolution_APPLE_I_I_G_S1X2,
	RECOILResolution_MACINTOSH1X1,
	RECOILResolution_XE1X1,
	RECOILResolution_XE2X1,
	RECOILResolution_XE4X1,
	RECOILResolution_XE2X2,
	RECOILResolution_XE4X2,
	RECOILResolution_XE4X4,
	RECOILResolution_XE8X8,
	RECOILResolution_VBXE1X1,
	RECOILResolution_VBXE2X1,
	RECOILResolution_PORTFOLIO1X1,
	RECOILResolution_ST1X1,
	RECOILResolution_ST1X2,
	RECOILResolution_STE1X1,
	RECOILResolution_STE1X2,
	RECOILResolution_TT1X1,
	RECOILResolution_TT2X1,
	RECOILResolution_FALCON1X1,
	RECOILResolution_FALCON2X1,
	RECOILResolution_BBC1X1,
	RECOILResolution_BBC2X1,
	RECOILResolution_BBC1X2,
	RECOILResolution_VIC201X1,
	RECOILResolution_VIC202X1,
	RECOILResolution_C161X1,
	RECOILResolution_C162X1,
	RECOILResolution_C641X1,
	RECOILResolution_C642X1,
	RECOILResolution_C1281X1,
	RECOILResolution_BK1X1,
	RECOILResolution_BK1X2,
	RECOILResolution_MC05151X2,
	RECOILResolution_FM_TOWNS1X1,
	RECOILResolution_HP481X1,
	RECOILResolution_MSX11X1,
	RECOILResolution_MSX14X4,
	RECOILResolution_MSX21X1,
	RECOILResolution_MSX21X2,
	RECOILResolution_MSX21X1I,
	RECOILResolution_MSX22X1I,
	RECOILResolution_MSX2_PLUS1X1,
	RECOILResolution_MSX2_PLUS2X1I,
	RECOILResolution_MSX_V99901X1,
	RECOILResolution_ORIC1X1,
	RECOILResolution_PC1X1,
	RECOILResolution_PC801X2,
	RECOILResolution_PC881X2,
	RECOILResolution_PC88_VA1X1,
	RECOILResolution_PC981X1,
	RECOILResolution_PLAY_STATION1X1,
	RECOILResolution_PSION31X1,
	RECOILResolution_SAM_COUPE1X1,
	RECOILResolution_SAM_COUPE1X2,
	RECOILResolution_SAM_COUPE2X1I,
	RECOILResolution_X68_K1X1,
	RECOILResolution_TANDY1X1,
	RECOILResolution_VECTOR1X1,
	RECOILResolution_ZX811X1,
	RECOILResolution_SPECTRUM1X1,
	RECOILResolution_SPECTRUM4X4,
	RECOILResolution_SPECTRUM_PROFI1X2,
	RECOILResolution_SPECTRUM_ULA_PLUS1X1,
	RECOILResolution_ZX_EVOLUTION1X1,
	RECOILResolution_SPECTRUM_NEXT1X1,
	RECOILResolution_TIMEX1X1,
	RECOILResolution_TIMEX1X2,
	RECOILResolution_TRS1X1,
	RECOILResolution_TRS1X2,
	RECOILResolution_COCO1X1,
	RECOILResolution_COCO2X2
} RECOILResolution;

typedef enum {
	IffType_ILBM,
	IffType_PBM,
	IffType_ACBM,
	IffType_RGB8,
	IffType_RGBN
} IffType;

typedef enum {
	IceFrameMode_GR0,
	IceFrameMode_GR0_GTIA9,
	IceFrameMode_GR0_GTIA10,
	IceFrameMode_GR0_GTIA11,
	IceFrameMode_GR12,
	IceFrameMode_GR12_GTIA9,
	IceFrameMode_GR12_GTIA10,
	IceFrameMode_GR12_GTIA11,
	IceFrameMode_GR13_GTIA9,
	IceFrameMode_GR13_GTIA10,
	IceFrameMode_GR13_GTIA11
} IceFrameMode;

typedef enum {
	AnticMode_BLANK,
	AnticMode_FOUR_COLOR,
	AnticMode_FIVE_COLOR,
	AnticMode_HI_RES
} AnticMode;
typedef struct Stream Stream;
typedef struct GdosFntStream GdosFntStream;
typedef struct DaliStream DaliStream;
typedef struct ZxpStream ZxpStream;
typedef struct AppleSprStream AppleSprStream;
typedef struct VplStream VplStream;
typedef struct BitStream BitStream;
typedef struct X68KPicStream X68KPicStream;
typedef struct Mx1Stream Mx1Stream;
typedef struct MppPaletteStream MppPaletteStream;
typedef struct MultiPalette MultiPalette;
typedef struct ArtPalette ArtPalette;
typedef struct GfaArtistPalette GfaArtistPalette;
typedef struct RastPalette RastPalette;
typedef struct HblPalette HblPalette;
typedef struct CtblPalette CtblPalette;
typedef struct ShamLacePalette ShamLacePalette;
typedef struct PchgPalette PchgPalette;
typedef struct RleStream RleStream;
typedef struct BldStream BldStream;
typedef struct BbgStream BbgStream;
typedef struct MspStream MspStream;
typedef struct C64KoalaStream C64KoalaStream;
typedef struct CmpStream CmpStream;
typedef struct DrpStream DrpStream;
typedef struct HpmStream HpmStream;
typedef struct UflStream UflStream;
typedef struct UifStream UifStream;
typedef struct PgcStream PgcStream;
typedef struct DaVinciStream DaVinciStream;
typedef struct VectorSprStream VectorSprStream;
typedef struct ScStream ScStream;
typedef struct CciStream CciStream;
typedef struct PackBitsStream PackBitsStream;
typedef struct SpcStream SpcStream;
typedef struct SpsStream SpsStream;
typedef struct VhiStream VhiStream;
typedef struct PrintfoxStream PrintfoxStream;
typedef struct ArtMaster88Stream ArtMaster88Stream;
typedef struct SrStream SrStream;
typedef struct PacStream PacStream;
typedef struct Bdp4Stream Bdp4Stream;
typedef struct Bdp5Stream Bdp5Stream;
typedef struct XlpStream XlpStream;
typedef struct AmstradStream AmstradStream;
typedef struct CpiStream CpiStream;
typedef struct VbmStream VbmStream;
typedef struct XeKoalaStream XeKoalaStream;
typedef struct ImgStream ImgStream;
typedef struct CaStream CaStream;
typedef struct RgbStream RgbStream;
typedef struct TnyPcsStream TnyPcsStream;
typedef struct TnyStream TnyStream;
typedef struct PcsStream PcsStream;
typedef struct VdatStream VdatStream;
typedef struct HimStream HimStream;
typedef struct IcStream IcStream;
typedef struct DeepStream DeepStream;
typedef struct PackBytesStream PackBytesStream;
typedef struct Lz4Stream Lz4Stream;
typedef struct Tre1Stream Tre1Stream;
typedef struct MciStream MciStream;
typedef struct Nl3Stream Nl3Stream;
typedef struct SfdnStream SfdnStream;
typedef struct G9bStream G9bStream;
typedef struct MigStream MigStream;
typedef struct Ice21Stream Ice21Stream;
typedef struct SpxStream SpxStream;
typedef struct Q4Stream Q4Stream;
typedef struct PiStream PiStream;
typedef struct A4rStream A4rStream;
typedef struct ZimStream ZimStream;
typedef struct FanoTree FanoTree;
typedef struct RecentInts RecentInts;
typedef struct BlazingPaddlesBoundingBox BlazingPaddlesBoundingBox;
typedef struct IcnParser IcnParser;
typedef struct PInterpreter PInterpreter;
typedef struct GtiaRenderer GtiaRenderer;
typedef struct HcmRenderer HcmRenderer;
typedef struct GedRenderer GedRenderer;
typedef struct PgrRenderer PgrRenderer;
typedef struct MchRenderer MchRenderer;
typedef struct G2fRenderer G2fRenderer;
typedef struct RastaRenderer RastaRenderer;
typedef struct RastaStream RastaStream;
typedef struct InflateStream InflateStream;

/**
 * Read-only stream backed by a byte array.
 */
struct Stream {
	uint8_t const *content;
	int contentOffset;
	int contentLength;
};

/**
 * Returns the next byte or -1 on EOF.
 * @param self This <code>Stream</code>.
 */
static int Stream_ReadByte(Stream *self);

/**
 * Advances the stream until after the first byte with the given value.
 * Returns <code>false</code> on EOF.
 * @param self This <code>Stream</code>.
 */
static bool Stream_SkipUntilByte(Stream *self, int expected);

static bool Stream_Expect(Stream *self, const char *s);

/**
 * Reads <code>count</code> bytes to <code>dest</code> starting at <code>destOffset</code>.
 * Returns <code>true</code> on success, <code>false</code> if not enough data.
 * @param self This <code>Stream</code>.
 */
static bool Stream_ReadBytes(Stream *self, uint8_t *dest, int destOffset, int count);

/**
 * Reads a hexadecimal ASCII digit and returns its value.
 * If there's no digit at the current stream position,
 * leaves the position intact and returns -1.
 * @param self This <code>Stream</code>.
 */
static int Stream_ReadHexDigit(Stream *self);

static int Stream_ReadHexByte(Stream *self);

/**
 * Reads an integer in range <code>0</code>..<code>maxValue</code>
 * in base <code>b</code>.
 * Returns -1 on error.
 * @param self This <code>Stream</code>.
 */
static int Stream_ParseInt(Stream *self, int b, int maxValue);

/**
 * Reads a decimal integer in range 0-32000
 * stored as ASCII digits followed by CRLF.
 * Returns -1 on error.
 * @param self This <code>Stream</code>.
 */
static int Stream_ParseDaliInt(Stream *self);

struct GdosFntStream {
	Stream base;
	bool bigEndian;
	int bitmapWidth;
	int width;
	int leftX;
	int rightX;
	int nextX;
};

/**
 * Reads a 16-bit unsigned integer.
 * Returns -1 on EOF.
 * @param self This <code>GdosFntStream</code>.
 */
static int GdosFntStream_ReadWord(GdosFntStream *self);

/**
 * Reads a 32-bit integer assuming there's enough data.
 * @param self This <code>GdosFntStream</code>.
 */
static int GdosFntStream_ReadInt(GdosFntStream *self);

static bool GdosFntStream_FitRow(GdosFntStream *self);

struct DaliStream {
	Stream base;
};

static bool DaliStream_Decode(DaliStream *self, int countLength, RECOIL *recoil, int paletteOffset, int mode);

struct ZxpStream {
	Stream base;
};

static int ZxpStream_ReadChar(ZxpStream *self);

static bool ZxpStream_IsEof(const ZxpStream *self);

struct AppleSprStream {
	Stream base;
};

/**
 * Reads a decimal, hexadecimal (with <code>$</code> prefix)
 * or binary (with <code>%</code> prefix) integer.
 * Skips leading whitespace.
 * Returns -1 on error.
 * @param self This <code>AppleSprStream</code>.
 */
static int AppleSprStream_ReadSprInt(AppleSprStream *self);

struct VplStream {
	Stream base;
	int palette[128];
};

static int VplStream_SkipWhitespace(VplStream *self);

static int VplStream_Decode(VplStream *self);

static void VplStream_CopyTo(const VplStream *self, int *palette, int colors);

typedef struct {
	int (*readBit)(BitStream *self);
} BitStreamVtbl;
/**
 * Readable in-memory stream of bits, most-significant bit first.
 */
struct BitStream {
	const BitStreamVtbl *vtbl;
	Stream base;
	int bits;
};
static void BitStream_Construct(BitStream *self);

/**
 * Reads one bit (0 or 1).
 * Returns -1 on end of stream.
 * @param self This <code>BitStream</code>.
 */
static int BitStream_ReadBit(BitStream *self);

/**
 * Reads the requested number of bits and returns them
 * as an unsigned integer with the first bit read as the most significant.
 * Returns -1 on end of stream.
 * @param self This <code>BitStream</code>.
 */
static int BitStream_ReadBits(BitStream *self, int count);

static int BitStream_ReadNl3Char(BitStream *self, bool skipSpace);

struct X68KPicStream {
	BitStream base;
};
static void X68KPicStream_Construct(X68KPicStream *self);

static int X68KPicStream_ReadLength(X68KPicStream *self);

struct Mx1Stream {
	X68KPicStream base;
	uint8_t decodeTable[256];
};
static void Mx1Stream_Construct(Mx1Stream *self);

static bool Mx1Stream_FindImage(Mx1Stream *self);

static int Mx1Stream_ReadBit(Mx1Stream *self);

struct MppPaletteStream {
	BitStream base;
};
static void MppPaletteStream_Construct(MppPaletteStream *self);

static int MppPaletteStream_Read(MppPaletteStream *self);

typedef struct {
	int (*readBit)(BitStream *self);
	void (*setLinePalette)(MultiPalette *self, RECOIL *recoil, int y);
} MultiPaletteVtbl;
struct MultiPalette {
	BitStream base;
};
static void MultiPalette_Construct(MultiPalette *self);

struct ArtPalette {
	MultiPalette base;
};
static void ArtPalette_Construct(ArtPalette *self);

static void ArtPalette_SetLinePalette(ArtPalette *self, RECOIL *recoil, int y);

struct GfaArtistPalette {
	MultiPalette base;
};
static void GfaArtistPalette_Construct(GfaArtistPalette *self);

static void GfaArtistPalette_SetLinePalette(GfaArtistPalette *self, RECOIL *recoil, int y);

struct RastPalette {
	MultiPalette base;
	int colors;
};
static void RastPalette_Construct(RastPalette *self);

static void RastPalette_SetLinePalette(RastPalette *self, RECOIL *recoil, int y);

struct HblPalette {
	MultiPalette base;
};
static void HblPalette_Construct(HblPalette *self);

static bool HblPalette_HasPalette(const HblPalette *self, int row);

static bool HblPalette_Init(HblPalette *self);

static void HblPalette_SetLinePalette(HblPalette *self, RECOIL *recoil, int y);

struct CtblPalette {
	MultiPalette base;
	int colors;
};
static void CtblPalette_Construct(CtblPalette *self);

static void CtblPalette_SetLinePalette(CtblPalette *self, RECOIL *recoil, int y);

struct ShamLacePalette {
	MultiPalette base;
};
static void ShamLacePalette_Construct(ShamLacePalette *self);

static void ShamLacePalette_SetLinePalette(ShamLacePalette *self, RECOIL *recoil, int y);

struct PchgPalette {
	MultiPalette base;
	bool ocs;
	int startLine;
	int lineCount;
	uint8_t *havePaletteChange;
	int treeOffset;
	int treeLastOffset;
	bool compressed;
};
static void PchgPalette_Construct(PchgPalette *self);
static void PchgPalette_Destruct(PchgPalette *self);

static int PchgPalette_ReadHuffman(PchgPalette *self);

static bool PchgPalette_Init(PchgPalette *self);

static int PchgPalette_UnpackByte(PchgPalette *self);

static void PchgPalette_SetOcsColors(PchgPalette *self, RECOIL *recoil, int paletteOffset, int count);

static void PchgPalette_SetLinePalette(PchgPalette *self, RECOIL *recoil, int y);

typedef struct {
	int (*readBit)(BitStream *self);
	bool (*readCommand)(RleStream *self);
	int (*readValue)(RleStream *self);
} RleStreamVtbl;
/**
 * Readable in-memory Run-Length-Encoded stream.
 * This class contains the compression logic.
 * Subclasses must implement <code>ReadCommand()</code>
 * and are allowed to override <code>ReadValue()</code>.
 */
struct RleStream {
	BitStream base;
	/**
	 * Block length.
	 */
	int repeatCount;
	/**
	 * Value for an RLE block, -1 for a block of literals.
	 */
	int repeatValue;
};
static void RleStream_Construct(RleStream *self);

static int RleStream_ReadValue(RleStream *self);

/**
 * Returns the next uncompressed byte or -1 on error.
 * @param self This <code>RleStream</code>.
 */
static int RleStream_ReadRle(RleStream *self);

/**
 * Uncompresses bytes to <code>unpacked[unpackedOffset]</code>,
 * <code>unpacked[unpackedOffset + unpackedStride]</code>,
 * <code>unpacked[unpackedOffset + 2 * unpackedStride]</code>,
 * ... as long as indexes are smaller than <code>unpackedEnd</code>.
 * Returns <code>true</code> on success, <code>false</code> on error.
 * @param self This <code>RleStream</code>.
 */
static bool RleStream_Unpack(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedEnd);

/**
 * Uncompresses laiding out bytes vertically column by column,
 * <code>unpackedStride</code> being line width.
 * Returns <code>true</code> on success, <code>false</code> on error.
 * @param self This <code>RleStream</code>.
 */
static bool RleStream_UnpackColumns(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedEnd);

/**
 * Uncompresses bytes to <code>unpacked[unpackedOffset]</code>, <code>unpacked[unpackedOffset + 1]</code>,
 * <code>unpacked[unpackedOffset + unpackedStride]</code>, <code>unpacked[unpackedOffset + unpackedStride + 1]</code>,
 * <code>unpacked[unpackedOffset + 2 * unpackedStride]</code>, <code>unpacked[unpackedOffset + 2 * unpackedStride + 1]</code>,
 * ... as long as indexes are smaller than <code>unpackedEnd</code>.
 * Returns <code>true</code> on success, <code>false</code> on error.
 * @param self This <code>RleStream</code>.
 */
static bool RleStream_UnpackWords(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedEnd);

/**
 * Uncompresses writing first byte to <code>unpacked[unpackedEnd]</code>, <code>unpacked[unpackedEnd - 1]</code>, ...
 * until <code>unpacked[unpackedOffset]</code>.
 * Returns <code>true</code> on success, <code>false</code> on error.
 * @param self This <code>RleStream</code>.
 */
static bool RleStream_UnpackBackwards(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedEnd);

struct BldStream {
	RleStream base;
};
static void BldStream_Construct(BldStream *self);

static bool BldStream_ReadCommand(BldStream *self);

struct BbgStream {
	RleStream base;
	int valueBits;
	int countBits;
};
static void BbgStream_Construct(BbgStream *self);

/**
 * Reads the requested number of bits and returns them
 * as an unsigned integer with the first bit read as the least significant.
 * Returns -1 on end of stream.
 * @param self This <code>BbgStream</code>.
 */
static int BbgStream_ReadBitsReverse(BbgStream *self, int count);

static bool BbgStream_ReadCommand(BbgStream *self);

struct MspStream {
	RleStream base;
};
static void MspStream_Construct(MspStream *self);

static bool MspStream_ReadCommand(MspStream *self);

struct C64KoalaStream {
	RleStream base;
};
static void C64KoalaStream_Construct(C64KoalaStream *self);

static bool C64KoalaStream_ReadCommand(C64KoalaStream *self);

struct CmpStream {
	RleStream base;
	int escape;
};
static void CmpStream_Construct(CmpStream *self);

static bool CmpStream_ReadCommand(CmpStream *self);

struct DrpStream {
	RleStream base;
	int escape;
};
static void DrpStream_Construct(DrpStream *self);

static bool DrpStream_ReadCommand(DrpStream *self);

static uint8_t const *DrpStream_UnpackFile(uint8_t const *content, int contentLength, const char *signature, uint8_t *unpacked, int unpackedLength);

struct HpmStream {
	RleStream base;
};
static void HpmStream_Construct(HpmStream *self);

static bool HpmStream_ReadCommand(HpmStream *self);

struct UflStream {
	RleStream base;
	int escape;
};
static void UflStream_Construct(UflStream *self);

static bool UflStream_ReadCommand(UflStream *self);

struct UifStream {
	UflStream base;
};
static void UifStream_Construct(UifStream *self);

static int UifStream_ReadValue(UifStream *self);

static bool UifStream_StartSifFrame(UifStream *self, int contentOffset);

typedef struct {
	int (*readBit)(BitStream *self);
	bool (*readCommand)(RleStream *self);
	int (*readValue)(RleStream *self);
	int (*readCommandByte)(PgcStream *self);
} PgcStreamVtbl;
struct PgcStream {
	RleStream base;
};
static void PgcStream_Construct(PgcStream *self);

static int PgcStream_ReadCommandByte(PgcStream *self);

static bool PgcStream_ReadCommand(PgcStream *self);

struct DaVinciStream {
	PgcStream base;
};
static void DaVinciStream_Construct(DaVinciStream *self);

static int DaVinciStream_ReadValue(DaVinciStream *self);

struct VectorSprStream {
	PgcStream base;
};
static void VectorSprStream_Construct(VectorSprStream *self);

static int VectorSprStream_ReadValue(VectorSprStream *self);

static int VectorSprStream_ReadCommandByte(VectorSprStream *self);

struct ScStream {
	RleStream base;
};
static void ScStream_Construct(ScStream *self);

static bool ScStream_ReadCommand(ScStream *self);

struct CciStream {
	RleStream base;
};
static void CciStream_Construct(CciStream *self);

static bool CciStream_ReadCommand(CciStream *self);

static bool CciStream_UnpackGr15(CciStream *self, uint8_t *unpacked, int unpackedOffset);

struct PackBitsStream {
	RleStream base;
};
static void PackBitsStream_Construct(PackBitsStream *self);

static bool PackBitsStream_ReadCommand(PackBitsStream *self);

static bool PackBitsStream_UnpackBitplaneLines(PackBitsStream *self, uint8_t *unpacked, int width, int height, int bitplanes, bool compressed, bool hasMask);

struct SpcStream {
	RleStream base;
};
static void SpcStream_Construct(SpcStream *self);

static bool SpcStream_ReadCommand(SpcStream *self);

struct SpsStream {
	RleStream base;
};
static void SpsStream_Construct(SpsStream *self);

static bool SpsStream_ReadCommand(SpsStream *self);

struct VhiStream {
	RleStream base;
};
static void VhiStream_Construct(VhiStream *self);

static bool VhiStream_ReadCommand(VhiStream *self);

struct PrintfoxStream {
	RleStream base;
};
static void PrintfoxStream_Construct(PrintfoxStream *self);

static bool PrintfoxStream_ReadCommand(PrintfoxStream *self);

struct ArtMaster88Stream {
	RleStream base;
	int escape;
	uint8_t planes[4][32000];
};
static void ArtMaster88Stream_Construct(ArtMaster88Stream *self);

static bool ArtMaster88Stream_ReadCommand(ArtMaster88Stream *self);

static bool ArtMaster88Stream_SkipChunk(ArtMaster88Stream *self);

static bool ArtMaster88Stream_ReadPlanes(ArtMaster88Stream *self, int planes, int planeLength);

struct SrStream {
	RleStream base;
};
static void SrStream_Construct(SrStream *self);

static bool SrStream_ReadCommand(SrStream *self);

struct PacStream {
	RleStream base;
};
static void PacStream_Construct(PacStream *self);

static bool PacStream_ReadCommand(PacStream *self);

struct Bdp4Stream {
	RleStream base;
};
static void Bdp4Stream_Construct(Bdp4Stream *self);

static bool Bdp4Stream_ReadCommand(Bdp4Stream *self);

struct Bdp5Stream {
	RleStream base;
};
static void Bdp5Stream_Construct(Bdp5Stream *self);

static bool Bdp5Stream_ReadCommand(Bdp5Stream *self);

struct XlpStream {
	RleStream base;
};
static void XlpStream_Construct(XlpStream *self);

static bool XlpStream_ReadCommand(XlpStream *self);

struct AmstradStream {
	RleStream base;
	int blockLength;
};
static void AmstradStream_Construct(AmstradStream *self);

static bool AmstradStream_ReadCommand(AmstradStream *self);

static bool AmstradStream_UnpackFile(uint8_t const *content, int contentOffset, int contentLength, uint8_t *unpacked, int unpackedLength);

struct CpiStream {
	RleStream base;
};
static void CpiStream_Construct(CpiStream *self);

static bool CpiStream_ReadCommand(CpiStream *self);

struct VbmStream {
	RleStream base;
};
static void VbmStream_Construct(VbmStream *self);

static bool VbmStream_ReadCommand(VbmStream *self);

struct XeKoalaStream {
	RleStream base;
	uint8_t unpacked[7680];
};
static void XeKoalaStream_Construct(XeKoalaStream *self);

static bool XeKoalaStream_ReadCommand(XeKoalaStream *self);

static bool XeKoalaStream_UnpackRaw(XeKoalaStream *self, int type, int unpackedLength);

static bool XeKoalaStream_UnpackWrapped(XeKoalaStream *self, int unpackedLength);

struct ImgStream {
	RleStream base;
	int patternRepeatCount;
};
static void ImgStream_Construct(ImgStream *self);

static int ImgStream_GetLineRepeatCount(ImgStream *self);

static bool ImgStream_ReadCommand(ImgStream *self);

static bool ImgStream_UnpackLine(ImgStream *self, uint8_t *unpacked, int unpackedLength, int y);

struct CaStream {
	RleStream base;
	int escape;
	int defaultValue;
};
static void CaStream_Construct(CaStream *self);

static bool CaStream_ReadCommand(CaStream *self);

static bool CaStream_UnpackCa(CaStream *self, uint8_t *unpacked, int unpackedOffset);

static bool CaStream_UnpackDel(uint8_t const *content, int contentLength, uint8_t *unpacked, int blocks);

struct RgbStream {
	RleStream base;
};
static void RgbStream_Construct(RgbStream *self);

static int RgbStream_ReadValue(RgbStream *self);

static bool RgbStream_ReadCommand(RgbStream *self);

struct TnyPcsStream {
	RleStream base;
};
static void TnyPcsStream_Construct(TnyPcsStream *self);

static bool TnyPcsStream_ReadTnyCommand(TnyPcsStream *self);

struct TnyStream {
	TnyPcsStream base;
	int valueOffset;
	int valueLength;
};
static void TnyStream_Construct(TnyStream *self);

static bool TnyStream_ReadCommand(TnyStream *self);

static int TnyStream_ReadValue(TnyStream *self);

struct PcsStream {
	TnyPcsStream base;
	int commandCount;
	bool palette;
};
static void PcsStream_Construct(PcsStream *self);

static bool PcsStream_ReadCommand(PcsStream *self);

static int PcsStream_ReadValue(PcsStream *self);

static bool PcsStream_StartBlock(PcsStream *self);

static bool PcsStream_EndBlock(PcsStream *self);

static bool PcsStream_UnpackPcs(PcsStream *self, uint8_t *unpacked);

struct VdatStream {
	TnyStream base;
};
static void VdatStream_Construct(VdatStream *self);

static bool VdatStream_ReadCommand(VdatStream *self);

struct HimStream {
	RleStream base;
};
static void HimStream_Construct(HimStream *self);

static int HimStream_ReadValue(HimStream *self);

static bool HimStream_ReadCommand(HimStream *self);

struct IcStream {
	RleStream base;
};
static void IcStream_Construct(IcStream *self);

static bool IcStream_ReadCount(IcStream *self);

static bool IcStream_ReadCommand(IcStream *self);

struct DeepStream {
	PackBitsStream base;
	int components;
	int componentShift[6];
	int currentByte;
	int *line;
};
static void DeepStream_Construct(DeepStream *self);
static void DeepStream_Destruct(DeepStream *self);

static bool DeepStream_SetDpel(DeepStream *self, int chunkOffset, int chunkLength);

static int DeepStream_ReadValue(DeepStream *self);

static int DeepStream_ReadNibble(DeepStream *self);

static bool DeepStream_ReadDeltaLine(DeepStream *self, int width, int tvdcOffset);

struct PackBytesStream {
	Stream base;
	int count;
	int pattern;
};
static void PackBytesStream_Construct(PackBytesStream *self);

static int PackBytesStream_ReadUnpacked(PackBytesStream *self);

struct Lz4Stream {
	Stream base;
	uint8_t *unpacked;
	int unpackedOffset;
	int unpackedLength;
};

static bool Lz4Stream_Copy(Lz4Stream *self, int count);

static int Lz4Stream_ReadCount(Lz4Stream *self, int count);

struct Tre1Stream {
	RleStream base;
	int lastRgb;
};
static void Tre1Stream_Construct(Tre1Stream *self);

static bool Tre1Stream_ReadCommand(Tre1Stream *self);

static int Tre1Stream_ReadValue(Tre1Stream *self);

struct MciStream {
	RleStream base;
};
static void MciStream_Construct(MciStream *self);

static bool MciStream_ReadCommand(MciStream *self);

struct Nl3Stream {
	RleStream base;
};
static void Nl3Stream_Construct(Nl3Stream *self);

static int Nl3Stream_ReadValue(Nl3Stream *self);

static bool Nl3Stream_ReadCommand(Nl3Stream *self);

struct SfdnStream {
	BitStream base;
};
static void SfdnStream_Construct(SfdnStream *self);

static bool SfdnStream_Unpack(SfdnStream *self, uint8_t *unpacked, int unpackedLength);

struct G9bStream {
	BitStream base;
};
static void G9bStream_Construct(G9bStream *self);

static int G9bStream_ReadLength(G9bStream *self);

static bool G9bStream_Unpack(G9bStream *self, uint8_t *unpacked, int headerLength, int unpackedLength);

struct MigStream {
	BitStream base;
};
static void MigStream_Construct(MigStream *self);

static int MigStream_Unpack(MigStream *self, uint8_t *unpacked);

struct Ice21Stream {
	uint8_t const *content;
	int contentOffset;
	int contentStart;
	int bits;
};

static int Ice21Stream_GetUnpackedLength(const Ice21Stream *self);

static int Ice21Stream_ReadBit(Ice21Stream *self);

static int Ice21Stream_ReadBits(Ice21Stream *self, int count);

static int Ice21Stream_CountOnes(Ice21Stream *self, int max);

static int Ice21Stream_ReadLiteralLength(Ice21Stream *self);

static int Ice21Stream_ReadEncoded(Ice21Stream *self, int maxCount, uint8_t const *extraBits, int const *offsets);

static bool Ice21Stream_Unpack(Ice21Stream *self, uint8_t *unpacked, int unpackedStart, int unpackedEnd);

struct SpxStream {
	Ice21Stream base;
};

static int SpxStream_ReadCount(SpxStream *self);

static bool SpxStream_UnpackV2(SpxStream *self, uint8_t *unpacked, int unpackedLength);

struct Q4Stream {
	RleStream base;
	int codeBits;
	uint8_t unpacked[65536];
	int lastRepeatValue;
};
static void Q4Stream_Construct(Q4Stream *self);

static int Q4Stream_StartChunk(Q4Stream *self);

static int Q4Stream_ReadCode(Q4Stream *self);

static bool Q4Stream_UnpackQ4(Q4Stream *self);

static bool Q4Stream_ReadCommand(Q4Stream *self);

struct PiStream {
	BitStream base;
	uint8_t *indexes;
	uint8_t recentColors[65536];
};
static void PiStream_Construct(PiStream *self);
static void PiStream_Destruct(PiStream *self);

static int PiStream_ReadInt(PiStream *self, int bits, int maxBits);

static bool PiStream_UnpackLiteral(PiStream *self, int indexesOffset, int depth);

static bool PiStream_UnpackTwoLiterals(PiStream *self, int indexesOffset, int indexesLength, int depth);

static int PiStream_ReadPosition(PiStream *self);

static bool PiStream_Unpack(PiStream *self, int width, int height, int depth);

struct A4rStream {
	Stream base;
	int outerFlags;
	int innerFlags;
	uint8_t unpacked[11248];
	int unpackedOffset;
};
static void A4rStream_Construct(A4rStream *self);

static int A4rStream_ReadFlag(A4rStream *self);

static bool A4rStream_CopyByte(A4rStream *self);

static bool A4rStream_CopyBlock(A4rStream *self, int distance, int count);

static bool A4rStream_UnpackA4r(A4rStream *self);

struct ZimStream {
	Stream base;
	uint8_t flags1[1];
	uint8_t flags2[8];
};

static int ZimStream_ReadWord(ZimStream *self);

static int ZimStream_ReadUnpacked(ZimStream *self, uint8_t const *flags, int unpackedOffset);

static bool ZimStream_Unpack(ZimStream *self, uint8_t const *flags, uint8_t *unpacked, int unpackedLength);

static bool ZimStream_UnpackFlags2(ZimStream *self);

struct FanoTree {
	/**
	 * Count[n] == number of codes of bit length n.
	 */
	int count[16];
	/**
	 * Values sorted by code length.
	 */
	uint8_t values[256];
};

static void FanoTree_Create(FanoTree *self, uint8_t const *content, int contentOffset, int codeCount);

static int FanoTree_ReadCode(const FanoTree *self, BitStream *bitStream);

/**
 * Dictionary of <code>Count</code> key-value pairs.
 * A key is an integer between zero and <code>Count-1</code>. A value is an int.
 * The dictionary always contains exactly <code>Count</code> mappings. The values are initially all zeros.
 * The pairs are ordered by their last usage, from Most Recently Used (MRU) to Least Recently Used (LRU).
 * When you add or retrieve a value, it becomes the Most Recently Used.
 * When you add a value, the Least Recently Used is discarded.
 */
struct RecentInts {
	int value[128];
	uint8_t prev[128];
	uint8_t next[128];
	int head;
};
static void RecentInts_Construct(RecentInts *self);

/**
 * Store the value.
 * Will use the Least Recently Used key.
 * Its previous value is discarded and now it maps to <code>value</code>
 * and becomes the Most Recently Used.
 * @param self This <code>RecentInts</code>.
 */
static void RecentInts_Add(RecentInts *self, int value);

/**
 * Retrieve a value by key.
 * @param self This <code>RecentInts</code>.
 */
static int RecentInts_Get(RecentInts *self, int key);

struct BlazingPaddlesBoundingBox {
	int left;
	int top;
	int right;
	int bottom;
};

static bool BlazingPaddlesBoundingBox_Calculate(BlazingPaddlesBoundingBox *self, uint8_t const *content, int contentLength, int index, int startAddress);

struct IcnParser {
	Stream base;
};

static bool IcnParser_SkipWhitespaceAndComments(IcnParser *self);

static bool IcnParser_ExpectAfterWhitespace(IcnParser *self, const char *s);

static int IcnParser_ParseHex(IcnParser *self);

static int IcnParser_ParseDefine(IcnParser *self, const char *s);

struct PInterpreter {
	Stream base;
	uint8_t screen[768];
	int screenOffset;
	bool newLineWorks;
	int bottomOffset;
	int bottomCode;
};

static int PInterpreter_ReadNumber(PInterpreter *self);

static int PInterpreter_PrintString(PInterpreter *self, int offset);

static bool PInterpreter_Print(PInterpreter *self);

static bool PInterpreter_DPeek(PInterpreter *self, int expectedX, int expectedAddress);

static bool PInterpreter_Let(PInterpreter *self);

static bool PInterpreter_DoIf(PInterpreter *self);

static bool PInterpreter_DoFor(PInterpreter *self);

static bool PInterpreter_Poke(PInterpreter *self);

static bool PInterpreter_Next(PInterpreter *self);

static bool PInterpreter_Run(PInterpreter *self);

typedef struct {
	int (*getHiresColor)(const GtiaRenderer *self, int c);
	int (*getPlayfieldByte)(GtiaRenderer *self, int y, int column);
} GtiaRendererVtbl;
struct GtiaRenderer {
	const GtiaRendererVtbl *vtbl;
	uint8_t playerHpos[4];
	uint8_t missileHpos[4];
	uint8_t playerSize[4];
	uint8_t missileSize[4];
	uint8_t playerSizeCounter[4];
	uint8_t missileSizeCounter[4];
	uint8_t playerGraphics[4];
	int missileGraphics;
	uint8_t playerShiftRegister[4];
	int missileShiftRegister;
	uint8_t colors[9];
	int prior;
	uint8_t const *content;
	int playfieldColumns;
};

static void GtiaRenderer_SetPlayerSize(GtiaRenderer *self, int i, int size);

static void GtiaRenderer_SetSpriteSizes(uint8_t *sizes, int value);

static void GtiaRenderer_Poke(GtiaRenderer *self, int addr, int value);

static void GtiaRenderer_ProcessPlayerDma(GtiaRenderer *self, uint8_t const *content, int playersOffset);

static void GtiaRenderer_ProcessSpriteDma(GtiaRenderer *self, uint8_t const *content, int missileOffset);

static int GtiaRenderer_GetPmg(GtiaRenderer *self, int hpos, int objects);

static int GtiaRenderer_GetColor(const GtiaRenderer *self, int objects);

static void GtiaRenderer_StartLine(GtiaRenderer *self, int startHpos);

static int GtiaRenderer_GetHiresColor(const GtiaRenderer *self, int c);

static int GtiaRenderer_DrawSpan(GtiaRenderer *self, int y, int hpos, int untilHpos, AnticMode anticMode, uint8_t *frame, int width, int yOffset);

static void GtiaRenderer_SetG2fColors(GtiaRenderer *self, int contentOffset, int contentStride, int count, int gtiaMode);

static int GtiaRenderer_AdvanceCpuCycles(const GtiaRenderer *self, int hpos, int cpuCycles, bool nonBlank);

struct HcmRenderer {
	GtiaRenderer base;
};
static void HcmRenderer_Construct(HcmRenderer *self);

static int HcmRenderer_GetPlayfieldByte(HcmRenderer *self, int y, int column);

struct GedRenderer {
	GtiaRenderer base;
};
static void GedRenderer_Construct(GedRenderer *self);

static int GedRenderer_GetPlayfieldByte(GedRenderer *self, int y, int column);

struct PgrRenderer {
	GtiaRenderer base;
	int screenOffset;
};
static void PgrRenderer_Construct(PgrRenderer *self);

static int PgrRenderer_GetPlayfieldByte(PgrRenderer *self, int y, int column);

struct MchRenderer {
	GtiaRenderer base;
	bool dliPlus;
};
static void MchRenderer_Construct(MchRenderer *self);

static int MchRenderer_GetPlayfieldByte(MchRenderer *self, int y, int column);

struct G2fRenderer {
	GtiaRenderer base;
	int fontOffset;
	int inverse2Offset;
	int vbxeOffset;
};
static void G2fRenderer_Construct(G2fRenderer *self);

static int G2fRenderer_GetHiresColor(const G2fRenderer *self, int c);

static int G2fRenderer_GetPlayfieldByte(G2fRenderer *self, int y, int column);

static bool G2fRenderer_SetSprite(uint8_t *hpos, uint8_t *sizes, int i, uint8_t const *content, int spriteOffset);

struct RastaRenderer {
	GtiaRenderer base;
};
static void RastaRenderer_Construct(RastaRenderer *self);

static int RastaRenderer_GetPlayfieldByte(RastaRenderer *self, int y, int column);

struct RastaStream {
	Stream base;
	RastaRenderer gtia;
	uint8_t cpuRegisters[3];
	int cpuRegisterIndex;
	int gtiaRegisterIndex;
	uint8_t players[1024];
};
static void RastaStream_Construct(RastaStream *self);

static bool RastaStream_EndLine(RastaStream *self);

static int RastaStream_ReadCpuRegister(RastaStream *self);

static int RastaStream_ParseHexByte(RastaStream *self);

static int RastaStream_ReadDigit(RastaStream *self, int offset, int maxValue);

static int RastaStream_ReadGtiaRegister(RastaStream *self);

static bool RastaStream_IsLetter(int b);

static bool RastaStream_SkipUntilMnemonic(RastaStream *self);

static int RastaStream_ExecuteUntilPoke(RastaStream *self);

static void RastaStream_Poke(RastaStream *self);

static bool RastaStream_ReadIni(RastaStream *self);

static bool RastaStream_ReadPmg(RastaStream *self);

static bool RastaStream_ExpectCmpZp(RastaStream *self);

static bool RastaStream_ReadRp(RastaStream *self, uint8_t const *bitmap, int height, uint8_t *frame);

struct InflateStream {
	Stream base;
	int bits;
	uint8_t symbolCodeLength[318];
	int nBitCodeCount[32];
	int nBitCodeOffset[32];
	int16_t codeToSymbol[318];
};

static int InflateStream_ReadBit(InflateStream *self);

static int InflateStream_ReadBits(InflateStream *self, int count);

static void InflateStream_BuildHuffmanTrees(InflateStream *self);

static int InflateStream_FetchCode(InflateStream *self, int tree);

static int InflateStream_Inflate(InflateStream *self, uint8_t *unpacked, int unpackedLength);

static int InflateStream_Uncompress(InflateStream *self, uint8_t *unpacked, int unpackedLength);

typedef struct {
	int (*readFile)(const RECOIL *self, const char *filename, uint8_t *content, int contentLength);
} RECOILVtbl;
/**
 * Decoder of images in formats native to vintage computers.
 * Decodes file contents passed as a byte array
 * into a 24-bit RGB bitmap.
 */
struct RECOIL {
	const RECOILVtbl *vtbl;
	/**
	 * Decoded image width.
	 */
	int width;
	/**
	 * Decoded image height.
	 */
	int height;
	/**
	 * Decoded image pixels as 0xRRGGBB.
	 */
	int *pixels;
	/**
	 * Length of the currently allocated <code>Pixels</code>.
	 */
	int pixelsLength;
	/**
	 * Platform and pixel ratio.
	 */
	RECOILResolution resolution;
	/**
	 * Number of frames (normally 1; 2 or 3 for flickering pictures).
	 */
	int frames;
	/**
	 * <code>true</code> if NTSC is preferred over PAL.
	 */
	bool ntsc;
	int c64Palette[16];
	int c16Palette[128];
	int atari8Palette[256];
	int leftSkip;
	/**
	 * RGB palette decoded from the image file.
	 */
	int contentPalette[256];
	uint8_t gtiaColors[16];
	uint8_t *colorInUse;
	int colors;
	int palette[256];
	uint8_t *indexes;
	int indexesLength;
};
static void RECOIL_Construct(RECOIL *self);
static void RECOIL_Destruct(RECOIL *self);

static int RECOIL_GetPackedExt(const char *filename);

/**
 * Initializes decoded image size and resolution.
 * @param self This <code>RECOIL</code>.
 */
static bool RECOIL_SetSize(RECOIL *self, int width, int height, RECOILResolution resolution, int frames);

static bool RECOIL_SetSizeStOrFalcon(RECOIL *self, int width, int height, int bitplanes, bool squarePixels);

static bool RECOIL_SetScaledSize(RECOIL *self, int width, int height, RECOILResolution resolution);

static void RECOIL_SetScaledPixel(RECOIL *self, int x, int y, int rgb);

/**
 * Reads a 32-bit big endian integer from a byte array.
 */
static int RECOIL_Get32BigEndian(uint8_t const *content, int contentOffset);

/**
 * Reads a 32-bit little endian integer from a byte array.
 */
static int RECOIL_Get32LittleEndian(uint8_t const *content, int contentOffset);

static int RECOIL_GetNibble(uint8_t const *content, int contentOffset, int index);

static bool RECOIL_IsStringAt(uint8_t const *content, int contentOffset, const char *s);

static bool RECOIL_CopyPrevious(uint8_t *unpacked, int unpackedOffset, int distance, int count);

static bool RECOIL_ApplyBlend(RECOIL *self);

/**
 * Reads a companion file to the specified byte array.
 * Implement this method in a subclass to enable support for multi-file images.
 * Returns the number of bytes read (up to <code>contentLength</code>) or -1 on error.
 * @param self This <code>RECOIL</code>.
 * @param filename Name of the file to read.
 * @param content Out: target for the file contents.
 * @param contentLength Maximum number of bytes to read.
 */
static int RECOIL_ReadFile(const RECOIL *self, const char *filename, uint8_t *content, int contentLength);

static int RECOIL_ReadCompanionFile(const RECOIL *self, const char *baseFilename, const char *upperExt, const char *lowerExt, uint8_t *content, int contentLength);

static int RECOIL_ReadSiblingFile(const RECOIL *self, const char *baseFilename, const char *newFilename, uint8_t *content, int contentLength);

static bool RECOIL_DecodeBru(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetGrayscalePalette(RECOIL *self, int inverse);

static void RECOIL_DecodeBytes(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_DecodeNibbles(RECOIL *self, uint8_t const *content, int contentOffset, int contentStride);

static int RECOIL_GetR8G8B8Color(uint8_t const *content, int contentOffset);

static void RECOIL_DecodeR8G8B8Colors(uint8_t const *content, int contentOffset, int count, int *destination, int destinationOffset);

static int RECOIL_GetB5G5R5Color(int c);

static int RECOIL_GetR5G5B5Color(int c);

static int RECOIL_GetG6R5B5Color(int c);

static int RECOIL_Get729Color(int c);

static int RECOIL_GetFalconTrueColor(uint8_t const *content, int contentOffset);

static int RECOIL_GetBitplanePixel(uint8_t const *content, int contentOffset, int x, int bitplanes, int bytesPerBitplane);

static bool RECOIL_DecodeAmigaPlanar(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height, RECOILResolution resolution, int bitplanes, int const *palette);

static int RECOIL_GetBitplaneWordsPixel(uint8_t const *content, int contentOffset, int x, int bitplanes);

/**
 * Decodes Atari ST/Falcon interleaved bitplanes.
 * Each 16 pixels are encoded in N consecutive 16-bit words.
 * @param self This <code>RECOIL</code>.
 */
static void RECOIL_DecodeBitplanes(RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, int bitplanes, int pixelsOffset, int width, int height);

static void RECOIL_DecodeScaledBitplanes(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height, int bitplanes, bool ehb, MultiPalette *multiPalette);

static bool RECOIL_DecodeMono(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, bool wordAlign);

static bool RECOIL_DecodeBlackAndWhite(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, bool wordAlign, int backgroundColor);

static bool RECOIL_DecodeRleBlackAndWhite(RECOIL *self, RleStream *rle, int backgroundColor);

static void RECOIL_DecodeBlackAndWhiteFont(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int fontHeight);

static bool RECOIL_DecodePgf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePgc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePsion3Pic(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGrb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTrsHr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTrsShr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRle(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCocoClp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCocoMax(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeP11(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMac(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodePlayStation(uint8_t const *content, int contentOffset, int *pixels, int pixelsLength);

static int RECOIL_DecodeTimPalette(RECOIL *self, uint8_t const *content, int contentLength, int colors);

static bool RECOIL_DecodeTim(RECOIL *self, uint8_t const *content, int contentLength);
static const int RECOIL_BBC_PALETTE[16] = { 0, 16711680, 65280, 16776960, 255, 16711935, 65535, 16777215, 0, 16711680, 65280, 16776960, 255, 16711935, 65535, 16777215 };
static const int RECOIL_BBC_PALETTE2_BIT[4] = { 0, 16711680, 16776960, 16777215 };
static const int RECOIL_BBC_PALETTE1_BIT[2] = { 0, 16777215 };

static bool RECOIL_DecodeBb0(RECOIL *self, uint8_t const *content, int contentLength, int const *palette);

static bool RECOIL_DecodeBb1(RECOIL *self, uint8_t const *content, int contentLength, int const *palette);

static bool RECOIL_DecodeBb2(RECOIL *self, uint8_t const *content, int contentLength, int const *palette);

static bool RECOIL_DecodeBb4(RECOIL *self, uint8_t const *content, int contentLength, int const *palette);

static bool RECOIL_DecodeBb5(RECOIL *self, uint8_t const *content, int contentLength, int const *palette);

static bool RECOIL_DecodeBbg(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetOricHeader(uint8_t const *content, int contentLength);

static bool RECOIL_DecodeChs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHrs(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetAmstradHeader(uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAmstradFnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAmstradMode2(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height);

static bool RECOIL_DecodeHgb(RECOIL *self, uint8_t const *content, int contentLength);
static const int RECOIL_AMSTRAD_PALETTE[32] = { 8421504, 8421504, 65408, 16777088, 128, 16711808, 32896, 16744576, 16711808, 16777088, 16776960, 16777215, 16711680, 16711935, 16744448, 16744703,
	128, 65408, 65280, 65535, 0, 255, 32768, 33023, 8388736, 8454016, 8453888, 8454143, 8388608, 8388863, 8421376, 8421631 };

static int RECOIL_SetAmstradPalette(RECOIL *self, const char *filename);

static void RECOIL_DecodeAmstradMode0Line(RECOIL *self, uint8_t const *content, int lineOffset, int y);

static void RECOIL_DecodeAmstradMode1Line(RECOIL *self, uint8_t const *content, int lineOffset, int y);

static bool RECOIL_DecodeAmstradScr(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeWin(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCm5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSgx(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_SetAmstradFirmwarePalette(RECOIL *self, uint8_t const *content, int contentOffset, int count);

static bool RECOIL_SetAmstradFirmwarePalette16(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodePphFrame(RECOIL *self, const char *filename, const char *upperExt, const char *lowerExt, uint8_t *bitmap, uint8_t const *pph, int yOffset);

static bool RECOIL_DecodePph(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZx81(RECOIL *self, uint8_t const *screen);

static bool RECOIL_DecodeZx81Raw(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZp1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeP(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetZxColor(int c);

static void RECOIL_SetZxPalette(RECOIL *self);

static bool RECOIL_SetZxSize(RECOIL *self, int width, int height, RECOILResolution resolution, int frames);

static void RECOIL_SetZx(RECOIL *self, RECOILResolution resolution, int frames);

static int RECOIL_GetG3R3B2Color(int c);

static void RECOIL_SetUlaPlus(RECOIL *self, uint8_t const *content, int paletteOffset);

static int RECOIL_GetZxLineOffset(int y);

static void RECOIL_DecodeZx(RECOIL *self, uint8_t const *content, int bitmapOffset, int attributesOffset, int attributesMode, int pixelsOffset);

static void RECOIL_DecodeTimexHires(RECOIL *self, uint8_t const *content, int contentOffset, int pixelsOffset);

static bool RECOIL_DecodeHrg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZxIfl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMcMlt(RECOIL *self, uint8_t const *content, int contentLength, int bitmapOffset);

static bool RECOIL_DecodeZxImg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHlr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZxRgb3(RECOIL *self, uint8_t const *content, int contentLength, uint8_t const *frameComponents);

static bool RECOIL_DecodeZxRgb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZxs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSev(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCh8(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetChxTileOffset(uint8_t const *content, int tile);

static bool RECOIL_DecodeChx(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZxp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBsc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeChrd(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetBspBitmapPixel(uint8_t const *content, int bitmapOffset, int x, int y);

static bool RECOIL_DecodeBspFrame(RECOIL *self, int pixelsOffset, uint8_t const *content, int contentLength, int bitmapOffset, int borderOffset);

static bool RECOIL_DecodeBsp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeNxi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeProfiGrf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSxg(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetMsx1Palette(RECOIL *self);
static const uint8_t RECOIL_MSX2_DEFAULT_PALETTE[32] = { 0, 0, 0, 0, 17, 6, 51, 7, 23, 1, 39, 3, 81, 1, 39, 6,
	113, 1, 115, 3, 97, 6, 100, 6, 17, 4, 101, 2, 85, 5, 119, 7 };

static int RECOIL_GetMsxHeader(uint8_t const *content);

static bool RECOIL_IsMsxPalette(uint8_t const *content, int contentOffset);

static void RECOIL_SetMsxPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors);

static void RECOIL_SetMsx2Palette(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength);

static void RECOIL_DecodeSc2Sc4(RECOIL *self, uint8_t const *content, int contentOffset, RECOILResolution resolution);

static void RECOIL_DecodeMsxSprites(RECOIL *self, uint8_t const *content, int mode, int attributesOffset, int patternsOffset);

static bool RECOIL_DecodeSc2(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeSc3Screen(RECOIL *self, uint8_t const *content, int contentOffset, bool isLong);

static bool RECOIL_DecodeSc3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSc4(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetMsx128Height(const RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_ClampU5(int x);

static int RECOIL_DecodeMsxYjk(const RECOIL *self, uint8_t const *content, int contentOffset, int x, int width, bool usePalette);

static void RECOIL_DecodeMsxScreen(RECOIL *self, uint8_t const *content, int contentOffset, uint8_t const *interlace, int height, int mode, int interlaceMask);

static bool RECOIL_DecodeMsxSc(RECOIL *self, const char *filename, uint8_t const *content, int contentOffset, const char *upperExt, const char *lowerExt, int height, int mode);

static bool RECOIL_DecodeSc5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static void RECOIL_SetMsxCompanionPalette(RECOIL *self, const char *filename, const char *upperExt, const char *lowerExt);

static bool RECOIL_DecodeSr5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMsx6(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetMsx6DefaultPalette(RECOIL *self);

static bool RECOIL_DecodeSc6(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static void RECOIL_SetMsx6Palette(RECOIL *self, const char *filename);

static bool RECOIL_DecodeSr6(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGl6(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static uint8_t const *RECOIL_UnpackSr(uint8_t const *content, int contentLength, uint8_t *unpacked);

static bool RECOIL_DecodeSc7(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSri(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSr7(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGl16(RECOIL *self, const char *filename, uint8_t const *content, int contentLength, RECOILResolution resolution, const char *upperExt, const char *lowerExt);

static bool RECOIL_DecodeGl5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGl7(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static void RECOIL_SetSc8Palette(RECOIL *self);

static bool RECOIL_DecodeSc8(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGl8(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePct(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDdGraph(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static void RECOIL_DecodeMsxYjkScreen(RECOIL *self, uint8_t const *content, int contentOffset, bool usePalette);

static void RECOIL_DecodeSccSca(RECOIL *self, const char *filename, uint8_t const *content, int contentLength, int height, bool usePalette);

static bool RECOIL_DecodeScc(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSca(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGlYjk(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_SetG9bPalette(RECOIL *self, uint8_t const *content, int colors);

static void RECOIL_DecodeG9bUnpacked(RECOIL *self, uint8_t const *content, int depth, int headerLength);

static bool RECOIL_DecodeG9b(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_UnpackMif(RECOIL *self, uint8_t const *content, int contentLength, uint8_t *unpacked, int unpackedLength, bool palette);

static bool RECOIL_DecodeMif(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetMigMode(int reg0, int reg1, int reg19, int length);

static bool RECOIL_DecodeMig(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHgr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAppleIIDhr(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetAppleIIGSPalette(RECOIL *self, uint8_t const *content, int contentOffset, int reverse);

static void RECOIL_DecodeShrLine(RECOIL *self, uint8_t const *content, int y);

static bool RECOIL_DecodeAppleIIShrUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeAppleIIShr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSh3(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DrawSprByte(RECOIL *self, int x1, int y, int b);

static bool RECOIL_DecodeAppleSpr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePackBytes(RECOIL *self, PackBytesStream *stream, int pixelsOffset, int unpackedBytes);

static bool RECOIL_DecodePaintworks(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode3201(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeApfShr(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetSamCoupeColor(int c);

static void RECOIL_SetSamCoupePalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors);

static int RECOIL_GetSamCoupeMode12Color(uint8_t const *content, int bitmapOffset, int attributeOffset, int x);

static int RECOIL_DecodeSamCoupeScreen(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int mode, int interruptOffset);

static bool RECOIL_DecodeSs1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSs2(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSs3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSs4(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeLce(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetSamCoupeAttrPalette(RECOIL *self, uint8_t const *content, int contentOffset);

static bool RECOIL_DecodeSsx(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetX68KColor(int color);

static int RECOIL_RestrictPlatformColor(const RECOIL *self, int rgb, int colors);

static bool RECOIL_DecodeX68KPicChain(RECOIL *self, BitStream *stream, int pixelsOffset, int color);

static bool RECOIL_DecodeX68KPicScreen(RECOIL *self, X68KPicStream *stream, int pixelsLength, int platform, int depth);

static bool RECOIL_DecodeX68KPic(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetPc88EightPixels(RECOIL *self, int column, int y, int b);

static bool RECOIL_DecodeDaVinci(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeArtMaster88(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetKtyTile(uint8_t const *content, int contentOffset);

static void RECOIL_SetKtyFourPixels(RECOIL *self, int pixelsOffset, int tile);

static void RECOIL_SetKtyTileOffset(RECOIL *self, int pixelsOffset, int mode, uint8_t const *content, int tileOffset);

static void RECOIL_SetKtyTile(RECOIL *self, int x, int y, int mode, uint8_t const *content, int tileOffset);

static bool RECOIL_DecodeKty(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEbd(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeNl3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMl1Chain(RECOIL *self, X68KPicStream *stream, int pixelsOffset, int rgb);

static int RECOIL_DecodeMl1Mx1(RECOIL *self, X68KPicStream *stream, int imageOffset);

static bool RECOIL_DecodeMl1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMx1Tiles(RECOIL *self, Mx1Stream *stream, int width, int height, int shift);

static bool RECOIL_DecodeMx1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZim(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeQ4(RECOIL *self, uint8_t const *content, int contentLength);

static RECOILResolution RECOIL_GetPiPlatform(uint8_t const *content, int contentOffset, bool highPixel);

static void RECOIL_SetPiPalette(RECOIL *self, uint8_t const *content, int paletteOffset, int colors, int rOffset);

static bool RECOIL_DecodePi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMaki1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_UnpackMag(uint8_t const *content, int headerOffset, int contentLength, int bytesPerLine, int height, uint8_t *unpacked);

static bool RECOIL_DecodeMag(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVbm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBrus(RECOIL *self, uint8_t const *content, int contentLength);
static const int RECOIL_VIC20_PALETTE[16] = { 0, 16777215, 7152423, 10551032, 9321623, 8313461, 2433936, 16777094, 10773563, 16763041, 15902635, 14417919, 16758015, 14155726, 10328831, 16777161 };

static bool RECOIL_DecodeBp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePic0(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVic20Mg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeP4i(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeG(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode64c(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePrintfox(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeC64FourColor(RECOIL *self, uint8_t const *content, int contentOffset, int frame);

static bool RECOIL_DecodeCle(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIle(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCfli(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_IsGodot(uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGodot(RECOIL *self, int width, int height, uint8_t const *content, int contentOffset, int contentLength, bool compressed);

static bool RECOIL_Decode4bt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGodotClp(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeC64HiresFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, bool afli, int stride, int pixelsOffset);

static bool RECOIL_DecodeC64Hires(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset);

static bool RECOIL_DecodeRpo(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeC64Hir(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIph(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHed(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeJj(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDd(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetC64Multicolor(const RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, bool bottomBfli, int x, int y, int strideColumns);

static void RECOIL_DecodeC64MulticolorLine(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, bool bottomBfli, int y, int pixelsOffset, int width, int strideColumns);

static void RECOIL_DecodeC64MulticolorFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset, int pixelsOffset);

static bool RECOIL_DecodeC64Multicolor(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset);

static bool RECOIL_DecodeIpt(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeOcp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBpl(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeC64MulticolorFliFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, bool bottomBfli, int pixelsOffset);

static void RECOIL_DecodeC64MulticolorFliBarsFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset, int pixelsOffset);

static bool RECOIL_DecodeC64MulticolorFli(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background);

static bool RECOIL_DecodeC64MulticolorFliBars(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset);

static bool RECOIL_DecodeHfc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAfl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePmg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeKoa(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeZom(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeKoaPacked(RECOIL *self, RleStream *rle);

static bool RECOIL_DecodeGg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDol(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAmi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBdp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMwi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeC64Shp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeC64HiresInterlace(RECOIL *self, uint8_t const *content, int bitmap1Offset, int videoMatrix1Offset, int bitmap2Offset, int videoMatrix2Offset);

static bool RECOIL_DecodeIhe(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHlf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHle(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVhi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMciLike(RECOIL *self, uint8_t const *content, int bitmap1Offset, int videoMatrix1Offset, int bitmap2Offset, int videoMatrix2Offset, int colorOffset, int backgroundOffset, int shift);

static bool RECOIL_DecodeFp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMciUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeMci(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDrz(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDrl(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeMleFrame(RECOIL *self, uint8_t const *content, int contentOffset, int pixelsOffset);

static bool RECOIL_DecodeMle(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHcb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFed(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHimUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeHim(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEci(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEcp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFli(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFbi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBml(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEmc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFlm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFfli(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIfli(RECOIL *self, uint8_t const *content, int bitmap1Offset, int bitmap2Offset, int videoMatrix1Offset, int videoMatrix2Offset, int colorOffset, int background);

static bool RECOIL_DecodePpUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodePp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFunUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeC64Fun(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeGunFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int pixelsOffset);

static bool RECOIL_DecodeGun(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBfli(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeLp3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMilPacked(RECOIL *self, uint8_t const *content, int contentLength, bool vertical);

static bool RECOIL_DecodeMil(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVic(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeA(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSpd(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetAtari8Gr0Pixel(uint8_t const *font, int fontOffset, int ch, int x, int y);

static bool RECOIL_DecodePetScreenCustom(RECOIL *self, uint8_t const *content, int screenOffset, int fontOffset, uint8_t const *colors, int colorsOffset, int background, int columns, int rows);

static bool RECOIL_DecodePetScreen(RECOIL *self, uint8_t const *content, int screenOffset, int colorsOffset, int background, int columns, int rows);

static bool RECOIL_DecodePet(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePdr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePbot(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeScrCol(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCgx(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFpr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCtm(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeEshFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int spriteOffset, int pixelsOffset);

static bool RECOIL_DecodeEshUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeEsh(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeShx(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetShsPixel(uint8_t const *content, int x, int y);

static bool RECOIL_DecodeShs(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetShSpriteOffset(int x, int y, int rowShift);

static void RECOIL_DecodeSh1Frame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int screenStride, int foreSpriteOffset, int backSpriteOffset, int foreColorOffset, int backColorOffset, int rowShift, int pixelsOffset);

static bool RECOIL_DecodeSh1Unpacked(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int screenStride, int foreSpriteOffset, int backSpriteOffset, int foreColorOffset, int backColorOffset, int rowShift);

static bool RECOIL_UnpackSh(uint8_t const *content, int contentLength, uint8_t *unpacked, int unpackedLength);

static bool RECOIL_DecodeSh1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeShiUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeShi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSuperHires2(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int screenStride, int spritesOffset, int spritesY, int spriteColorsOffset);

static bool RECOIL_DecodeSh2(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetShe1Pixel(uint8_t const *content, int x, int y);

static bool RECOIL_DecodeShe(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetIshPixel(uint8_t const *content, int contentOffset, int x, int y);

static void RECOIL_DecodeIshFrame(RECOIL *self, uint8_t const *content, int contentOffset, int pixelsOffset);

static bool RECOIL_DecodeIsh(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetShfPixel(uint8_t const *content, int x, int y);

static void RECOIL_DecodeShfFrame(RECOIL *self, uint8_t const *content, int foreColor, int backColor, int pixelsOffset);

static bool RECOIL_DecodeShf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeC64Sif(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeUflFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int spritesOffset, int spriteColorsOffset, int pixelsOffset);

static bool RECOIL_DecodeUflUnpacked(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeUfl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeUif(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeXfl(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetNufVideoMatrixOffset(int y);

static int RECOIL_GetMufTableOffset(int spriteInLine);

static bool RECOIL_DecodeMufFrame(RECOIL *self, uint8_t const *content, int pixelsOffset);

static bool RECOIL_DecodeMuf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMup(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMui(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeNuf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeNup(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDoo(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDa4(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStCmp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBld(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCrg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePac(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_FillPscLine(uint8_t *unpacked, int unpackedOffset, int unpackedStride, int value);

static int RECOIL_CopyPscLines(uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedLength, int count);

static bool RECOIL_DecodePsc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCp3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStFnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGdosFnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_IsStePalette(uint8_t const *content, int contentOffset, int colors);

static int RECOIL_GetStColor(const RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetStPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors, int c);

static int RECOIL_GetSteInterlacedColor(int rgb);

static int RECOIL_GetStVdiColor(uint8_t const *content, int contentOffset);

static void RECOIL_SetStVdiColor(RECOIL *self, int i, int rgb, int bitplanes);

static void RECOIL_SetStVdiPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors, int bitplanes);

static int RECOIL_GetStLowPixel(uint8_t const *content, int contentOffset, int x);

static bool RECOIL_DecodeStLowWithStride(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, int bitmapStride, uint8_t const *palette, int paletteOffset, int width, int height, int frames);

static bool RECOIL_DecodeStLow(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int width, int height, int frames);

static void RECOIL_DecodeStMedium(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int width, int height, int frames);

static bool RECOIL_DecodeSrt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSt(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int mode, int doubleHeight);

static bool RECOIL_DecodeStPi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEza(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeNeo(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeArtDirector(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSsb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGfaArtist(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBil(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePaletteMaster(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCel(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMur(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeKid(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStPpp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStRgb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSd(RECOIL *self, uint8_t const *content, int contentLength, int mode);

static bool RECOIL_DecodeObj(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGraphicsProcessor(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDaliCompressed(RECOIL *self, uint8_t const *content, int contentLength, int mode);

static bool RECOIL_DecodeRgh(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGfb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCa(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTny(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_UnpackGrx(uint8_t const *packed, int packedOffset, int packedLength, uint8_t *unpacked, int unpackedOffset, int unpackedLength);

static bool RECOIL_DecodeGrx(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCptFul(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, HblPalette *palette);

static bool RECOIL_DecodeCpt(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFul(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetDefaultStPalette(RECOIL *self, int bitplanes);

static bool RECOIL_IsXimg(uint8_t const *content);

static bool RECOIL_DecodeSttt(RECOIL *self, ImgStream *rle, int width, int bytesPerBitplane);

static bool RECOIL_DecodeStImg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStLowBlend(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int width, int height);

static bool RECOIL_DecodeDuo(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDu2(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeP3c(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_UnpackLz4(const RECOIL *self, uint8_t const *content, int contentLength, uint8_t *unpacked, int unpackedLength);

static bool RECOIL_DecodePl4(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSpuVariable(RECOIL *self, uint8_t const *content, int height, int bitmapOffset, int paletteOffset, bool enhanced);

static bool RECOIL_DecodeSpuScreen(RECOIL *self, uint8_t const *content, bool enhanced);

static bool RECOIL_DecodeSpu(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_UnpackSpc(RleStream *rle, uint8_t *unpacked);

static bool RECOIL_DecodeStSpc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSps(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSpxV2(RECOIL *self, uint8_t const *content, int contentLength, SpxStream *stream);

static bool RECOIL_DecodeSpx(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_GetStLowSeparateBitplanes(uint8_t const *content, int contentOffset, int bitplaneLength, int x);

static bool RECOIL_DecodePci(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodePcsScreen(RECOIL *self, uint8_t const *unpacked, int pixelsOffset);

static bool RECOIL_DecodePcs(RECOIL *self, uint8_t const *content, int contentLength);

static uint8_t const *RECOIL_UnpackPbx(const RECOIL *self, uint8_t const *content, int contentLength, uint8_t *unpacked, int bitmapOffset, int bytesPer16Pixels, int unpackedLength);

static bool RECOIL_DecodePbx01(RECOIL *self, uint8_t const *content, int contentLength, int bitplanes, int lineHeight);

static void RECOIL_DecodePbx8(RECOIL *self, uint8_t const *content, int paletteOffset, int bitmapOffset, int pixelsOffset);

static bool RECOIL_DecodePbx(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeMppScreen(RECOIL *self, uint8_t const *content, int paletteOffset, int paletteLength, int pixelsOffset);

static bool RECOIL_DecodeMpp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHrm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeStIcn(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCol(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCe(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIbi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBw(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFalconHir(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRw(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeR8G8G8X8Colors(RECOIL *self, uint8_t const *content, int contentOffset, int count);

static bool RECOIL_DecodeIim(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetFalconPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors);

static void RECOIL_DecodeFalconPalette(RECOIL *self, uint8_t const *content, int bitplanesOffset, int paletteOffset, int width, int height);

static bool RECOIL_DecodeFuckpaint(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDg1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDc1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDel(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDph(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFalconTrueColor(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height, RECOILResolution resolution);

static bool RECOIL_DecodeFalconTrueColorVariable(RECOIL *self, uint8_t const *content, int contentLength, int widthOffset, int dataOffset);

static bool RECOIL_DecodeFtc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeXga(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGod(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTrp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTru(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTg1(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTcp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTre(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_IsRag(uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRag(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRagc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFalconFun(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEsm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFalconPix(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePntUnpacked(RECOIL *self, uint8_t const *content, uint8_t const *bitmap, int bitmapOffset, int width, int height);

static bool RECOIL_DecodeFalconPnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeUimg(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_SetOcsColor(RECOIL *self, int c, int r, int gb);

static void RECOIL_SetOcsPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors);

static bool RECOIL_DecodeInfo(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAbkSprite(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAbk(RECOIL *self, uint8_t const *content, int contentLength);

static RECOILResolution RECOIL_GetAmigaAspectRatio(int xRatio, int yRatio, RECOILResolution resolution);

static RECOILResolution RECOIL_GetCamgAspectRatio(int camg, RECOILResolution resolution);

static bool RECOIL_DecodeDeep(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRgbn(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int width, int height, bool rgb8);

static bool RECOIL_DecodeRast(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, uint8_t const *unpacked, int width, int height, int bitplanes);

static void RECOIL_DecodeHam(RECOIL *self, uint8_t const *unpacked, int width, int height, int bitplanes, MultiPalette *multiPalette);

static int RECOIL_GetHameNibble(const RECOIL *self, uint8_t const *content, int contentOffset, int x);

static int RECOIL_GetHameByte(const RECOIL *self, uint8_t const *content, int contentOffset, int x);

static bool RECOIL_IsHame(const RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_DecodeHame(RECOIL *self, uint8_t const *content, int width);

static int RECOIL_GetDctvValue(const RECOIL *self, uint8_t const *content, int contentOffset, int x, int bitplanes);

static bool RECOIL_IsDctv(const RECOIL *self, uint8_t const *content, int contentOffset, int bitplanes);

static int RECOIL_ClampByte(int x);

static bool RECOIL_DecodeDctv(RECOIL *self, uint8_t const *content, int width, int height, RECOILResolution resolution, int bitplanes);

static bool RECOIL_DecodeIffUnpacked(RECOIL *self, uint8_t const *unpacked, int width, int height, RECOILResolution resolution, int bitplanes, int colors, int camg, MultiPalette *multiPalette);

static bool RECOIL_DecodeIff(RECOIL *self, uint8_t const *content, int contentLength, RECOILResolution resolution);

static int RECOIL_ParseAtari8ExecutableHeader(uint8_t const *content, int contentOffset);

static int RECOIL_GetAtari8ExecutableOffset(uint8_t const *content, int contentLength);

static bool RECOIL_SetAtari8RawSize(RECOIL *self, uint8_t const *content, int contentLength, RECOILResolution resolution);

static void RECOIL_SetGtiaColor(RECOIL *self, int reg, int value);

static void RECOIL_SetPM123PF0123Bak(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetGtiaColors(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetPF21(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetXeOsDefaultColors(RECOIL *self);

static void RECOIL_SetGr15DefaultColors(RECOIL *self);

static void RECOIL_SetBakPF012(RECOIL *self, uint8_t const *content, int contentOffset, int contentStride);

static void RECOIL_SetBakPF0123(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetPF012Bak(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetPF0123Bak(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_SetPF0123Even(RECOIL *self, uint8_t const *content, int contentOffset);

static void RECOIL_DecodeAtari8Gr8(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int height);

static void RECOIL_DecodeAtari8Gr15(const RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, uint8_t *frame, int frameOffset, int frameStride, int height);

static void RECOIL_DecodeAtari8Gr7(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int height);

static void RECOIL_DecodeAtari8Gr3(const RECOIL *self, uint8_t const *content, uint8_t *frame);

static void RECOIL_DecodeAtari8Gr9(const RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, uint8_t *frame, int frameOffset, int frameStride, int width, int height);

static void RECOIL_DecodeAtari8Gr11(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int frameStride, int height);

static void RECOIL_DecodeAtari8Gr10(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int frameStride, int height);

static void RECOIL_DecodeAtari8Gr11PalBlend(const RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, uint8_t *frame, int y);

static int RECOIL_ToAtari8Char(int ascii);

static void RECOIL_DecodeAtari8Gr0Line(const RECOIL *self, uint8_t const *characters, int charactersOffset, uint8_t const *font, int fontOffset, uint8_t *frame, int frameOffset, int lines);

static void RECOIL_DecodeAtari8Gr0(RECOIL *self, uint8_t const *characters, int charactersOffset, int charactersStride, uint8_t const *font, int fontOffset, uint8_t *frame);

static void RECOIL_DecodeAtari8Gr1Line(const RECOIL *self, uint8_t const *content, int charactersOffset, uint8_t const *font, int fontOffset, uint8_t *frame, int frameOffset, int doubleLine);

static void RECOIL_DecodeAtari8Gr12Line(const RECOIL *self, uint8_t const *characters, int charactersOffset, uint8_t const *font, int fontOffset, uint8_t *frame, int frameOffset, int doubleLine);

static void RECOIL_DecodeAtari8Player(const RECOIL *self, uint8_t const *content, int contentOffset, int color, uint8_t *frame, int frameOffset, int height, bool multi);

static bool RECOIL_ApplyAtari8Palette(RECOIL *self, uint8_t const *frame);

static bool RECOIL_ApplyAtari8PaletteBlend(RECOIL *self, uint8_t const *frame1, uint8_t const *frame2);

static bool RECOIL_ApplyAtari8PaletteBlend3(RECOIL *self, uint8_t const *frame1, uint8_t const *frame2, uint8_t const *frame3);

static bool RECOIL_DecodeGr8(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDrg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr8Raw(RECOIL *self, uint8_t const *content, int contentLength, int width, int height);

static bool RECOIL_DecodePsf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMonoArt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGhg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCpr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSg3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDit(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVisualizer(RECOIL *self, uint8_t const *content);

static bool RECOIL_DecodeGr7(RECOIL *self, uint8_t const *content, int contentOffset, int contentSize);

static bool RECOIL_DecodeRys(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBkg(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Artist(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr9(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRap(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTxe(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr9x4(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height);

static bool RECOIL_DecodeZm4(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr9p(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFge(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode16x16x16(RECOIL *self, uint8_t const *content, int contentOffset, int colbak);

static bool RECOIL_DecodeTx0(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTxs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeA4r(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeG11(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeG10(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeG09(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSkp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeKss(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMic(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePi8(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHpm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCpi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeWnd(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Koala(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength);

static bool RECOIL_DecodeAtari8Pix(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeAt800Players(const RECOIL *self, uint8_t const *content, uint8_t *frame);

static void RECOIL_DecodeAt800Missiles(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset);

static bool RECOIL_DecodePla(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMis(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode4pl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode4mi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode4pm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Spr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMsl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMpl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeLdm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePmd(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeApl(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_GetSprEdPixel(uint8_t const *content, int bitmapOffset, int bitmapStride, int x);

static int RECOIL_GetSprEdPair(uint8_t const *content, int bitmapOffset, int bitmapStride, int colorOffset, int colorStride, int x, int gap01);

static bool RECOIL_DecodeSprEd(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Hr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMcppVariable(RECOIL *self, uint8_t const *content, int bitmapOffset, int colorsOffset, int width, int height);

static bool RECOIL_DecodeMcpp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIld(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeInp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIge(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeInt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIst(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr15Blend(RECOIL *self, uint8_t const *content, int bitmapOffset, int colorsOffset, int height);

static bool RECOIL_DecodeMcp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Raw(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeXlp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Max(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHr2(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeLum(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeApc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_Decode256(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMga(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAp3(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeBgp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHip(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeG9s(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIns(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePls(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAps(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeIls(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeApp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHps(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTip(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCin(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeCci(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAgs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_UnpackRip(const RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, uint8_t *unpacked, int unpackedLength);

static bool RECOIL_DecodeRip(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVzi(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeRmUnpacked(RECOIL *self, uint8_t const *content, int colorsOffset, int dliOffset, uint8_t const *bitmap, int mode, RECOILResolution resolution);

static bool RECOIL_DecodeRm(RECOIL *self, uint8_t const *content, int contentLength, int mode, RECOILResolution resolution);

static bool RECOIL_DecodeAgp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeShc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMgp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGad(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFwa(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Font(RECOIL *self, uint8_t const *characters, uint8_t const *font, int fontOffset);

static bool RECOIL_DecodeAtari8Fnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeF80(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSxs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFn2(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeOdf(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeNlq(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGr1(RECOIL *self, uint8_t const *content, int contentLength, int doubleHeight);

static bool RECOIL_DecodeAcs(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeJgp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeLeo(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAtari8Sif(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDlm(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeAtari8Gr0Screen(RECOIL *self, uint8_t const *content, uint8_t const *font);

static bool RECOIL_DecodeGr0(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeSge(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAn2(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAn4(RECOIL *self, uint8_t const *content, int contentLength, int doubleHeight);

static bool RECOIL_DecodeTl4(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAsciiArtEditor(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAll(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeKpr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEnvisionCommon(RECOIL *self, uint8_t const *content, int mode, int columns, int rows, int charactersOffset, int const *fontId2Offset);

static bool RECOIL_DecodeEnvision(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeEnvisionPC(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMcs(RECOIL *self, uint8_t const *content, int contentLength);

static int RECOIL_Gr12GtiaNibbleToGr8(int nibble, int ch, bool gtia10);

static int RECOIL_Gr12GtiaByteToGr8(int b, int ch, bool gtia10);

static void RECOIL_DecodeIceFrame(const RECOIL *self, uint8_t const *content, int charactersOffset, int fontOffset, uint8_t *frame, IceFrameMode mode);

static bool RECOIL_VerifyIce(RECOIL *self, uint8_t const *content, int contentLength, bool font, int fontLength, int imageLength, RECOILResolution resolution);

static void RECOIL_DecodeIce20Frame(const RECOIL *self, uint8_t const *content, bool second, int fontOffset, uint8_t *frame, int mode);

static bool RECOIL_DecodeAtari8Ice(RECOIL *self, uint8_t const *content, int contentLength, bool font, int mode);

static bool RECOIL_DecodeIp2(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeAtari8RgbScreen(RECOIL *self, uint8_t const *screens, int screensOffset, int color, uint8_t *frame);

static bool RECOIL_DecodeAtari8Rgb(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DrawBlazingPaddlesVector(const RECOIL *self, uint8_t const *content, int contentLength, uint8_t *frame, int frameOffset, int index, int startAddress);

static bool RECOIL_DecodeBlazingPaddlesVectors(RECOIL *self, uint8_t const *content, int contentLength, int startAddress);

static bool RECOIL_DecodeChr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeShp(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DrawSpcChar(uint8_t *pixels, int x1, int y1, int ch);

static void RECOIL_DrawSpcLine(uint8_t *pixels, int x1, int y1, int x2, int y2, int color);

static void RECOIL_PlotSpcPattern(uint8_t *pixels, int x, int y, int pattern);

static void RECOIL_DrawSpcBrush(uint8_t *pixels, int x1, int y1, int brush, int pattern);

static bool RECOIL_FillSpc(uint8_t *pixels, int x, int y, int pattern);

static bool RECOIL_DecodeAtari8Spc(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHcm(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeGed(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePgr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_HasG2fRaster(uint8_t const *content, int contentOffset, int count, int hitClr);

static bool RECOIL_DecodeMch(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_G2fHasRaster(uint8_t const *content, int contentOffset);

static bool RECOIL_DecodeG2fUnpacked(RECOIL *self, uint8_t const *content, int contentLength, uint8_t *frame, int yOffset);

static bool RECOIL_DecodeG2fFrame(RECOIL *self, uint8_t const *content, int contentLength, uint8_t *frame, int yOffset);

static bool RECOIL_DecodeG2f(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVsc(RECOIL *self, const char *vscFilename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeDap(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeTandyPnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeHs2(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeImage72Fnt(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeMsp(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeAwbmPalette(RECOIL *self, uint8_t const *content, int contentLength, int paletteOffset, int colors);

static bool RECOIL_DecodeAwbm(RECOIL *self, uint8_t const *content, int contentLength);
static const int RECOIL_CGA_PALETTE[16] = { 0, 170, 43520, 43690, 11141120, 11141290, 11162880, 11184810, 5592405, 5592575, 5635925, 5636095, 16733525, 16733695, 16777045, 16777215 };

static bool RECOIL_DecodeEpa(RECOIL *self, uint8_t const *content, int contentLength);

static void RECOIL_DecodeBkMono(RECOIL *self, uint8_t const *content, int height);

static void RECOIL_DecodeBkColorFrame(RECOIL *self, uint8_t const *content, int paletteOffset, int frame);

static bool RECOIL_DecodeBkColor(RECOIL *self, uint8_t const *content, int palette);

static bool RECOIL_DecodeBks(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeVectorSpr(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodePi9(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_IsPaint256(const char *filename);

static bool RECOIL_DecodePic(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeScr(RECOIL *self, const char *filename, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFlfFont(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int columns, int rows, RECOILResolution resolution, int const *palette, int colors, int xMask, int cMask);

static bool RECOIL_DecodeFlfBytes(RECOIL *self, uint8_t const *content, int contentLength);

static bool RECOIL_DecodeFlf(RECOIL *self, uint8_t const *content, int contentLength);

/**
 * Calculates palette for the decoded picture.
 * @param self This <code>RECOIL</code>.
 */
static void RECOIL_CalculatePalette(RECOIL *self);

/**
 * Find the index of the <code>rgb</code> color in the sorted palette.
 * @param self This <code>RECOIL</code>.
 */
static int RECOIL_FindInSortedPalette(const RECOIL *self, int rgb);

static const uint8_t FuResource_altirrantsc_pal[768] = {
	0, 0, 0, 1, 1, 1, 22, 21, 23, 42, 41, 43, 62, 60, 63, 81,
	78, 83, 103, 100, 106, 122, 118, 124, 131, 126, 133, 149, 144, 152, 170, 164,
	173, 188, 181, 192, 205, 198, 210, 223, 215, 227, 243, 235, 248, 255, 252, 255,
	0, 2, 0, 0, 20, 0, 7, 42, 0, 33, 61, 0, 54, 79, 0, 75,
	96, 0, 98, 117, 0, 118, 134, 0, 127, 142, 0, 146, 159, 0, 167, 179,
	39, 186, 196, 63, 203, 213, 85, 221, 230, 106, 242, 249, 129, 255, 255, 148,
	12, 0, 0, 35, 2, 0, 61, 24, 0, 81, 43, 0, 101, 61, 0, 120,
	79, 0, 143, 100, 0, 161, 117, 0, 170, 126, 0, 188, 143, 28, 210, 163,
	58, 228, 180, 80, 245, 197, 100, 255, 214, 120, 255, 234, 143, 255, 251, 162,
	40, 0, 0, 63, 0, 0, 90, 0, 0, 111, 21, 0, 131, 41, 0, 150,
	60, 0, 173, 82, 22, 192, 100, 47, 200, 109, 57, 219, 126, 78, 240, 147,
	101, 255, 164, 121, 255, 182, 140, 255, 199, 158, 255, 219, 180, 255, 236, 198,
	54, 0, 0, 77, 0, 0, 103, 0, 0, 124, 0, 19, 144, 24, 41, 164,
	46, 62, 187, 69, 86, 205, 87, 105, 214, 96, 114, 233, 114, 133, 254, 135,
	155, 255, 153, 173, 255, 170, 191, 255, 188, 209, 255, 208, 231, 255, 225, 248,
	51, 0, 16, 73, 0, 37, 99, 2, 61, 120, 8, 81, 140, 26, 101, 160,
	44, 120, 183, 66, 142, 201, 85, 160, 210, 93, 169, 229, 111, 187, 250, 132,
	209, 255, 150, 227, 255, 167, 244, 255, 184, 255, 255, 204, 255, 255, 221, 255,
	26, 10, 66, 50, 15, 86, 76, 21, 109, 98, 27, 128, 119, 39, 147, 139,
	54, 166, 161, 74, 187, 180, 91, 205, 189, 100, 214, 207, 117, 232, 229, 137,
	253, 246, 154, 255, 255, 171, 255, 255, 188, 255, 255, 208, 255, 255, 225, 255,
	0, 19, 95, 0, 25, 114, 34, 31, 137, 59, 39, 156, 81, 52, 174, 102,
	67, 193, 125, 86, 214, 144, 103, 232, 153, 111, 241, 172, 128, 255, 193, 148,
	255, 211, 165, 255, 229, 182, 255, 246, 198, 255, 255, 218, 255, 255, 235, 255,
	0, 20, 99, 0, 26, 118, 0, 35, 141, 0, 47, 160, 18, 62, 178, 49,
	78, 196, 76, 98, 218, 97, 115, 236, 106, 124, 244, 125, 141, 255, 148, 161,
	255, 166, 178, 255, 185, 194, 255, 203, 211, 255, 224, 231, 255, 241, 248, 255,
	0, 14, 77, 0, 21, 97, 0, 37, 120, 0, 54, 139, 0, 72, 157, 0,
	90, 176, 0, 110, 197, 23, 128, 216, 42, 136, 224, 69, 153, 242, 96, 174,
	255, 117, 191, 255, 137, 208, 255, 156, 224, 255, 179, 244, 255, 197, 255, 255,
	0, 4, 33, 0, 21, 54, 0, 44, 77, 0, 63, 97, 0, 82, 116, 0,
	100, 135, 0, 121, 157, 0, 139, 175, 0, 147, 184, 0, 165, 202, 34, 185,
	223, 69, 202, 241, 94, 219, 255, 117, 236, 255, 142, 255, 255, 162, 255, 255,
	0, 11, 0, 0, 31, 0, 0, 53, 18, 0, 72, 40, 0, 91, 60, 0,
	109, 80, 0, 130, 103, 0, 148, 122, 0, 156, 131, 0, 173, 150, 0, 194,
	171, 40, 211, 190, 74, 227, 208, 100, 244, 225, 127, 255, 246, 148, 255, 255,
	0, 18, 0, 0, 37, 0, 0, 59, 0, 0, 77, 0, 0, 95, 0, 0,
	113, 14, 0, 134, 43, 0, 151, 65, 0, 159, 74, 0, 177, 94, 38, 197,
	117, 72, 214, 136, 97, 230, 154, 119, 247, 173, 144, 255, 194, 164, 255, 212,
	0, 15, 0, 0, 35, 0, 0, 57, 0, 0, 75, 0, 0, 93, 0, 0,
	110, 0, 0, 131, 0, 33, 148, 0, 49, 156, 13, 75, 173, 43, 101, 193,
	70, 122, 210, 90, 142, 227, 110, 161, 243, 130, 183, 255, 152, 201, 255, 171,
	0, 5, 0, 0, 24, 0, 0, 47, 0, 4, 65, 0, 35, 83, 0, 58,
	100, 0, 83, 121, 0, 103, 138, 0, 112, 146, 0, 132, 163, 0, 154, 183,
	41, 172, 200, 65, 190, 217, 86, 208, 233, 107, 229, 253, 130, 247, 255, 149,
	3, 0, 0, 25, 7, 0, 50, 30, 0, 70, 48, 0, 90, 67, 0, 109,
	84, 0, 132, 105, 0, 150, 122, 0, 159, 131, 0, 177, 148, 13, 199, 168,
	49, 217, 185, 72, 234, 202, 93, 252, 219, 113, 255, 239, 136, 255, 255, 155 };
static const uint8_t FuResource_altirrapal_pal[768] = {
	0, 0, 0, 17, 17, 17, 34, 34, 34, 51, 51, 51, 68, 68, 68, 85,
	85, 85, 102, 102, 102, 119, 119, 119, 136, 136, 136, 153, 153, 153, 170, 170,
	170, 187, 187, 187, 204, 204, 204, 221, 221, 221, 238, 238, 238, 255, 255, 255,
	63, 0, 0, 80, 5, 0, 97, 22, 0, 114, 39, 0, 131, 56, 0, 148,
	73, 0, 165, 90, 1, 182, 107, 18, 199, 124, 35, 216, 141, 52, 233, 158,
	69, 250, 175, 86, 255, 192, 103, 255, 209, 120, 255, 226, 137, 255, 243, 154,
	80, 0, 0, 97, 0, 0, 114, 3, 0, 131, 20, 3, 148, 37, 20, 165,
	54, 37, 182, 71, 54, 199, 88, 71, 216, 105, 88, 233, 122, 105, 250, 139,
	122, 255, 156, 139, 255, 173, 156, 255, 190, 173, 255, 207, 190, 255, 224, 207,
	84, 0, 3, 101, 0, 20, 118, 0, 37, 135, 8, 54, 152, 25, 71, 169,
	42, 88, 186, 59, 105, 203, 76, 122, 220, 93, 139, 237, 110, 156, 254, 127,
	173, 255, 144, 190, 255, 161, 207, 255, 178, 224, 255, 195, 241, 255, 212, 255,
	79, 0, 53, 96, 0, 70, 113, 0, 87, 130, 1, 104, 147, 18, 121, 164,
	35, 138, 181, 52, 155, 198, 69, 172, 215, 86, 189, 232, 103, 206, 249, 120,
	223, 255, 137, 240, 255, 154, 255, 255, 171, 255, 255, 188, 255, 255, 205, 255,
	61, 0, 104, 78, 0, 121, 95, 0, 138, 112, 0, 155, 129, 17, 172, 146,
	34, 189, 163, 51, 206, 180, 68, 223, 197, 85, 240, 214, 102, 255, 231, 119,
	255, 248, 136, 255, 255, 153, 255, 255, 170, 255, 255, 187, 255, 255, 204, 255,
	32, 0, 139, 49, 0, 156, 66, 0, 173, 83, 8, 190, 100, 25, 207, 117,
	42, 224, 134, 59, 241, 151, 76, 255, 168, 93, 255, 185, 110, 255, 202, 127,
	255, 219, 144, 255, 236, 161, 255, 253, 178, 255, 255, 195, 255, 255, 212, 255,
	0, 0, 137, 0, 8, 154, 0, 25, 171, 16, 42, 188, 33, 59, 205, 50,
	76, 222, 67, 93, 239, 84, 110, 255, 101, 127, 255, 118, 144, 255, 135, 161,
	255, 152, 178, 255, 169, 195, 255, 186, 212, 255, 203, 229, 255, 220, 246, 255,
	0, 12, 101, 0, 29, 118, 0, 46, 135, 0, 63, 152, 5, 80, 169, 22,
	97, 186, 39, 114, 203, 56, 131, 220, 73, 148, 237, 90, 165, 254, 107, 182,
	255, 124, 199, 255, 141, 216, 255, 158, 233, 255, 175, 250, 255, 192, 255, 255,
	0, 31, 48, 0, 48, 65, 0, 65, 82, 0, 82, 99, 0, 99, 116, 5,
	116, 133, 22, 133, 150, 39, 150, 167, 56, 167, 184, 73, 184, 201, 90, 201,
	218, 107, 218, 235, 124, 235, 252, 141, 252, 255, 158, 255, 255, 175, 255, 255,
	0, 43, 0, 0, 60, 14, 0, 77, 31, 0, 94, 48, 0, 111, 65, 1,
	128, 82, 18, 145, 99, 35, 162, 116, 52, 179, 133, 69, 196, 150, 86, 213,
	167, 103, 230, 184, 120, 247, 201, 137, 255, 218, 154, 255, 235, 171, 255, 252,
	0, 51, 0, 0, 68, 0, 0, 85, 0, 0, 102, 0, 7, 119, 0, 24,
	136, 0, 41, 153, 0, 58, 170, 15, 75, 187, 32, 92, 204, 49, 109, 221,
	66, 126, 238, 83, 143, 255, 100, 160, 255, 117, 177, 255, 134, 194, 255, 151,
	0, 43, 0, 0, 60, 0, 2, 77, 0, 19, 94, 0, 36, 111, 0, 53,
	128, 0, 70, 145, 0, 87, 162, 0, 104, 179, 0, 121, 196, 14, 138, 213,
	31, 155, 230, 48, 172, 247, 65, 189, 255, 82, 206, 255, 99, 223, 255, 116,
	1, 28, 0, 18, 45, 0, 35, 62, 0, 52, 79, 0, 69, 96, 0, 86,
	113, 0, 103, 130, 0, 120, 147, 0, 137, 164, 0, 154, 181, 3, 171, 198,
	20, 188, 215, 37, 205, 232, 54, 222, 249, 71, 239, 255, 88, 255, 255, 105,
	35, 9, 0, 52, 26, 0, 69, 43, 0, 86, 60, 0, 103, 77, 0, 120,
	94, 0, 137, 111, 0, 154, 128, 0, 171, 145, 0, 188, 162, 16, 205, 179,
	33, 222, 196, 50, 239, 213, 67, 255, 230, 84, 255, 247, 101, 255, 255, 118,
	63, 0, 0, 80, 5, 0, 97, 22, 0, 114, 39, 0, 131, 56, 0, 148,
	73, 0, 165, 90, 1, 182, 107, 18, 199, 124, 35, 216, 141, 52, 233, 158,
	69, 250, 175, 86, 255, 192, 103, 255, 209, 120, 255, 226, 137, 255, 243, 154 };
static const uint8_t FuResource_atari8_fnt[1024] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 24, 24, 24, 0, 24, 0,
	0, 102, 102, 102, 0, 0, 0, 0, 0, 102, 255, 102, 102, 255, 102, 0,
	24, 62, 96, 60, 6, 124, 24, 0, 0, 102, 108, 24, 48, 102, 70, 0,
	28, 54, 28, 56, 111, 102, 59, 0, 0, 24, 24, 24, 0, 0, 0, 0,
	0, 14, 28, 24, 24, 28, 14, 0, 0, 112, 56, 24, 24, 56, 112, 0,
	0, 102, 60, 255, 60, 102, 0, 0, 0, 24, 24, 126, 24, 24, 0, 0,
	0, 0, 0, 0, 0, 24, 24, 48, 0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 24, 24, 0, 0, 6, 12, 24, 48, 96, 64, 0,
	0, 60, 102, 110, 118, 102, 60, 0, 0, 24, 56, 24, 24, 24, 126, 0,
	0, 60, 102, 12, 24, 48, 126, 0, 0, 126, 12, 24, 12, 102, 60, 0,
	0, 12, 28, 60, 108, 126, 12, 0, 0, 126, 96, 124, 6, 102, 60, 0,
	0, 60, 96, 124, 102, 102, 60, 0, 0, 126, 6, 12, 24, 48, 48, 0,
	0, 60, 102, 60, 102, 102, 60, 0, 0, 60, 102, 62, 6, 12, 56, 0,
	0, 0, 24, 24, 0, 24, 24, 0, 0, 0, 24, 24, 0, 24, 24, 48,
	6, 12, 24, 48, 24, 12, 6, 0, 0, 0, 126, 0, 0, 126, 0, 0,
	96, 48, 24, 12, 24, 48, 96, 0, 0, 60, 102, 12, 24, 0, 24, 0,
	0, 60, 102, 110, 110, 96, 62, 0, 0, 24, 60, 102, 102, 126, 102, 0,
	0, 124, 102, 124, 102, 102, 124, 0, 0, 60, 102, 96, 96, 102, 60, 0,
	0, 120, 108, 102, 102, 108, 120, 0, 0, 126, 96, 124, 96, 96, 126, 0,
	0, 126, 96, 124, 96, 96, 96, 0, 0, 62, 96, 96, 110, 102, 62, 0,
	0, 102, 102, 126, 102, 102, 102, 0, 0, 126, 24, 24, 24, 24, 126, 0,
	0, 6, 6, 6, 6, 102, 60, 0, 0, 102, 108, 120, 120, 108, 102, 0,
	0, 96, 96, 96, 96, 96, 126, 0, 0, 99, 119, 127, 107, 99, 99, 0,
	0, 102, 118, 126, 126, 110, 102, 0, 0, 60, 102, 102, 102, 102, 60, 0,
	0, 124, 102, 102, 124, 96, 96, 0, 0, 60, 102, 102, 102, 108, 54, 0,
	0, 124, 102, 102, 124, 108, 102, 0, 0, 60, 96, 60, 6, 6, 60, 0,
	0, 126, 24, 24, 24, 24, 24, 0, 0, 102, 102, 102, 102, 102, 126, 0,
	0, 102, 102, 102, 102, 60, 24, 0, 0, 99, 99, 107, 127, 119, 99, 0,
	0, 102, 102, 60, 60, 102, 102, 0, 0, 102, 102, 60, 24, 24, 24, 0,
	0, 126, 12, 24, 48, 96, 126, 0, 0, 30, 24, 24, 24, 24, 30, 0,
	0, 64, 96, 48, 24, 12, 6, 0, 0, 120, 24, 24, 24, 24, 120, 0,
	0, 8, 28, 54, 99, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0,
	0, 54, 127, 127, 62, 28, 8, 0, 24, 24, 24, 31, 31, 24, 24, 24,
	3, 3, 3, 3, 3, 3, 3, 3, 24, 24, 24, 248, 248, 0, 0, 0,
	24, 24, 24, 248, 248, 24, 24, 24, 0, 0, 0, 248, 248, 24, 24, 24,
	3, 7, 14, 28, 56, 112, 224, 192, 192, 224, 112, 56, 28, 14, 7, 3,
	1, 3, 7, 15, 31, 63, 127, 255, 0, 0, 0, 0, 15, 15, 15, 15,
	128, 192, 224, 240, 248, 252, 254, 255, 15, 15, 15, 15, 0, 0, 0, 0,
	240, 240, 240, 240, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 240, 240, 240, 240,
	0, 28, 28, 119, 119, 8, 28, 0, 0, 0, 0, 31, 31, 24, 24, 24,
	0, 0, 0, 255, 255, 0, 0, 0, 24, 24, 24, 255, 255, 24, 24, 24,
	0, 0, 60, 126, 126, 126, 60, 0, 0, 0, 0, 0, 255, 255, 255, 255,
	192, 192, 192, 192, 192, 192, 192, 192, 0, 0, 0, 255, 255, 24, 24, 24,
	24, 24, 24, 255, 255, 0, 0, 0, 240, 240, 240, 240, 240, 240, 240, 240,
	24, 24, 24, 31, 31, 0, 0, 0, 120, 96, 120, 96, 126, 24, 30, 0,
	0, 24, 60, 126, 24, 24, 24, 0, 0, 24, 24, 24, 126, 60, 24, 0,
	0, 24, 48, 126, 48, 24, 0, 0, 0, 24, 12, 126, 12, 24, 0, 0,
	0, 24, 60, 126, 126, 60, 24, 0, 0, 0, 60, 6, 62, 102, 62, 0,
	0, 96, 96, 124, 102, 102, 124, 0, 0, 0, 60, 96, 96, 96, 60, 0,
	0, 6, 6, 62, 102, 102, 62, 0, 0, 0, 60, 102, 126, 96, 60, 0,
	0, 14, 24, 62, 24, 24, 24, 0, 0, 0, 62, 102, 102, 62, 6, 124,
	0, 96, 96, 124, 102, 102, 102, 0, 0, 24, 0, 56, 24, 24, 60, 0,
	0, 6, 0, 6, 6, 6, 6, 60, 0, 96, 96, 108, 120, 108, 102, 0,
	0, 56, 24, 24, 24, 24, 60, 0, 0, 0, 102, 127, 127, 107, 99, 0,
	0, 0, 124, 102, 102, 102, 102, 0, 0, 0, 60, 102, 102, 102, 60, 0,
	0, 0, 124, 102, 102, 124, 96, 96, 0, 0, 62, 102, 102, 62, 6, 6,
	0, 0, 124, 102, 96, 96, 96, 0, 0, 0, 62, 96, 60, 6, 124, 0,
	0, 24, 126, 24, 24, 24, 14, 0, 0, 0, 102, 102, 102, 102, 62, 0,
	0, 0, 102, 102, 102, 60, 24, 0, 0, 0, 99, 107, 127, 62, 54, 0,
	0, 0, 102, 60, 24, 60, 102, 0, 0, 0, 102, 102, 102, 62, 12, 120,
	0, 0, 126, 12, 24, 48, 126, 0, 0, 24, 60, 126, 126, 24, 60, 0,
	24, 24, 24, 24, 24, 24, 24, 24, 0, 126, 120, 124, 110, 102, 6, 0,
	8, 24, 56, 120, 56, 24, 8, 0, 16, 24, 28, 30, 28, 24, 16, 0 };
static const uint8_t FuResource_c16_pal[384] = {
	3, 3, 3, 47, 47, 47, 104, 16, 16, 0, 66, 66, 88, 0, 109, 0,
	78, 0, 25, 28, 148, 56, 56, 0, 86, 32, 0, 75, 40, 0, 22, 72,
	0, 105, 7, 47, 0, 70, 38, 6, 42, 128, 42, 20, 155, 11, 73, 0,
	3, 3, 3, 61, 61, 61, 117, 30, 32, 0, 80, 79, 106, 16, 120, 4,
	92, 0, 42, 42, 163, 76, 71, 0, 105, 47, 0, 89, 56, 0, 38, 86,
	0, 117, 21, 65, 0, 88, 61, 21, 61, 143, 57, 34, 174, 25, 89, 0,
	3, 3, 3, 66, 66, 66, 123, 40, 32, 2, 86, 89, 111, 26, 130, 10,
	101, 9, 48, 52, 167, 80, 81, 0, 110, 54, 0, 101, 64, 0, 44, 92,
	0, 125, 30, 69, 1, 97, 69, 28, 69, 153, 66, 45, 173, 29, 98, 0,
	3, 3, 3, 86, 85, 90, 144, 60, 59, 23, 109, 114, 135, 45, 153, 31,
	123, 21, 70, 73, 193, 102, 99, 0, 132, 76, 13, 115, 85, 0, 64, 114,
	0, 145, 51, 94, 25, 116, 92, 50, 89, 174, 89, 63, 195, 50, 118, 0,
	3, 3, 3, 132, 126, 133, 187, 103, 104, 69, 150, 150, 175, 88, 195, 74,
	167, 62, 115, 115, 236, 146, 141, 17, 175, 120, 50, 161, 128, 32, 108, 158,
	18, 186, 95, 137, 70, 159, 131, 97, 133, 221, 132, 108, 239, 93, 163, 41,
	3, 3, 3, 178, 172, 179, 233, 146, 146, 108, 195, 193, 217, 134, 240, 121,
	209, 118, 157, 161, 255, 189, 190, 64, 220, 162, 97, 209, 169, 76, 147, 200,
	61, 233, 138, 177, 111, 205, 171, 138, 180, 255, 178, 154, 255, 136, 203, 89,
	3, 3, 3, 202, 202, 202, 255, 172, 172, 133, 216, 224, 243, 156, 255, 146,
	234, 138, 183, 186, 255, 214, 211, 91, 243, 190, 121, 230, 197, 101, 176, 224,
	87, 255, 164, 207, 137, 229, 200, 164, 202, 255, 200, 184, 255, 162, 229, 122,
	3, 3, 3, 249, 249, 249, 255, 246, 242, 209, 255, 255, 255, 233, 255, 219,
	255, 211, 240, 255, 255, 255, 255, 163, 255, 255, 193, 255, 255, 178, 252, 255,
	162, 255, 238, 255, 209, 255, 255, 235, 255, 255, 255, 248, 255, 237, 255, 188 };
static const uint8_t FuResource_c64_fnt[1024] = {
	60, 102, 110, 110, 96, 98, 60, 0, 24, 60, 102, 126, 102, 102, 102, 0,
	124, 102, 102, 124, 102, 102, 124, 0, 60, 102, 96, 96, 96, 102, 60, 0,
	120, 108, 102, 102, 102, 108, 120, 0, 126, 96, 96, 120, 96, 96, 126, 0,
	126, 96, 96, 120, 96, 96, 96, 0, 60, 102, 96, 110, 102, 102, 60, 0,
	102, 102, 102, 126, 102, 102, 102, 0, 60, 24, 24, 24, 24, 24, 60, 0,
	30, 12, 12, 12, 12, 108, 56, 0, 102, 108, 120, 112, 120, 108, 102, 0,
	96, 96, 96, 96, 96, 96, 126, 0, 99, 119, 127, 107, 99, 99, 99, 0,
	102, 118, 126, 126, 110, 102, 102, 0, 60, 102, 102, 102, 102, 102, 60, 0,
	124, 102, 102, 124, 96, 96, 96, 0, 60, 102, 102, 102, 102, 60, 14, 0,
	124, 102, 102, 124, 120, 108, 102, 0, 60, 102, 96, 60, 6, 102, 60, 0,
	126, 24, 24, 24, 24, 24, 24, 0, 102, 102, 102, 102, 102, 102, 60, 0,
	102, 102, 102, 102, 102, 60, 24, 0, 99, 99, 99, 107, 127, 119, 99, 0,
	102, 102, 60, 24, 60, 102, 102, 0, 102, 102, 102, 60, 24, 24, 24, 0,
	126, 6, 12, 24, 48, 96, 126, 0, 60, 48, 48, 48, 48, 48, 60, 0,
	12, 18, 48, 124, 48, 98, 252, 0, 60, 12, 12, 12, 12, 12, 60, 0,
	0, 24, 60, 126, 24, 24, 24, 24, 0, 16, 48, 127, 127, 48, 16, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 24, 24, 24, 24, 0, 0, 24, 0,
	102, 102, 102, 0, 0, 0, 0, 0, 102, 102, 255, 102, 255, 102, 102, 0,
	24, 62, 96, 60, 6, 124, 24, 0, 98, 102, 12, 24, 48, 102, 70, 0,
	60, 102, 60, 56, 103, 102, 63, 0, 6, 12, 24, 0, 0, 0, 0, 0,
	12, 24, 48, 48, 48, 24, 12, 0, 48, 24, 12, 12, 12, 24, 48, 0,
	0, 102, 60, 255, 60, 102, 0, 0, 0, 24, 24, 126, 24, 24, 0, 0,
	0, 0, 0, 0, 0, 24, 24, 48, 0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 24, 24, 0, 0, 3, 6, 12, 24, 48, 96, 0,
	60, 102, 110, 118, 102, 102, 60, 0, 24, 24, 56, 24, 24, 24, 126, 0,
	60, 102, 6, 12, 48, 96, 126, 0, 60, 102, 6, 28, 6, 102, 60, 0,
	6, 14, 30, 102, 127, 6, 6, 0, 126, 96, 124, 6, 6, 102, 60, 0,
	60, 102, 96, 124, 102, 102, 60, 0, 126, 102, 12, 24, 24, 24, 24, 0,
	60, 102, 102, 60, 102, 102, 60, 0, 60, 102, 102, 62, 6, 102, 60, 0,
	0, 0, 24, 0, 0, 24, 0, 0, 0, 0, 24, 0, 0, 24, 24, 48,
	14, 24, 48, 96, 48, 24, 14, 0, 0, 0, 126, 0, 126, 0, 0, 0,
	112, 24, 12, 6, 12, 24, 112, 0, 60, 102, 6, 12, 24, 0, 24, 0,
	0, 0, 0, 255, 255, 0, 0, 0, 8, 28, 62, 127, 127, 28, 62, 0,
	24, 24, 24, 24, 24, 24, 24, 24, 0, 0, 0, 255, 255, 0, 0, 0,
	0, 0, 255, 255, 0, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 0, 0, 48, 48, 48, 48, 48, 48, 48, 48,
	12, 12, 12, 12, 12, 12, 12, 12, 0, 0, 0, 224, 240, 56, 24, 24,
	24, 24, 28, 15, 7, 0, 0, 0, 24, 24, 56, 240, 224, 0, 0, 0,
	192, 192, 192, 192, 192, 192, 255, 255, 192, 224, 112, 56, 28, 14, 7, 3,
	3, 7, 14, 28, 56, 112, 224, 192, 255, 255, 192, 192, 192, 192, 192, 192,
	255, 255, 3, 3, 3, 3, 3, 3, 0, 60, 126, 126, 126, 126, 60, 0,
	0, 0, 0, 0, 0, 255, 255, 0, 54, 127, 127, 127, 62, 28, 8, 0,
	96, 96, 96, 96, 96, 96, 96, 96, 0, 0, 0, 7, 15, 28, 24, 24,
	195, 231, 126, 60, 60, 126, 231, 195, 0, 60, 126, 102, 102, 126, 60, 0,
	24, 24, 102, 102, 24, 24, 60, 0, 6, 6, 6, 6, 6, 6, 6, 6,
	8, 28, 62, 127, 62, 28, 8, 0, 24, 24, 24, 255, 255, 24, 24, 24,
	192, 192, 48, 48, 192, 192, 48, 48, 24, 24, 24, 24, 24, 24, 24, 24,
	0, 0, 3, 62, 118, 54, 54, 0, 255, 127, 63, 31, 15, 7, 3, 1,
	0, 0, 0, 0, 0, 0, 0, 0, 240, 240, 240, 240, 240, 240, 240, 240,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 255, 192, 192, 192, 192, 192, 192, 192, 192,
	204, 204, 51, 51, 204, 204, 51, 51, 3, 3, 3, 3, 3, 3, 3, 3,
	0, 0, 0, 0, 204, 204, 51, 51, 255, 254, 252, 248, 240, 224, 192, 128,
	3, 3, 3, 3, 3, 3, 3, 3, 24, 24, 24, 31, 31, 24, 24, 24,
	0, 0, 0, 0, 15, 15, 15, 15, 24, 24, 24, 31, 31, 0, 0, 0,
	0, 0, 0, 248, 248, 24, 24, 24, 0, 0, 0, 0, 0, 0, 255, 255,
	0, 0, 0, 31, 31, 24, 24, 24, 24, 24, 24, 255, 255, 0, 0, 0,
	0, 0, 0, 255, 255, 24, 24, 24, 24, 24, 24, 248, 248, 24, 24, 24,
	192, 192, 192, 192, 192, 192, 192, 192, 224, 224, 224, 224, 224, 224, 224, 224,
	7, 7, 7, 7, 7, 7, 7, 7, 255, 255, 0, 0, 0, 0, 0, 0,
	255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255,
	3, 3, 3, 3, 3, 3, 255, 255, 0, 0, 0, 0, 240, 240, 240, 240,
	15, 15, 15, 15, 0, 0, 0, 0, 24, 24, 24, 248, 248, 0, 0, 0,
	240, 240, 240, 240, 0, 0, 0, 0, 240, 240, 240, 240, 15, 15, 15, 15 };
static const uint8_t FuResource_zx81_fnt[512] = {
	0, 0, 0, 0, 0, 0, 0, 0, 240, 240, 240, 240, 0, 0, 0, 0,
	15, 15, 15, 15, 0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240, 240,
	15, 15, 15, 15, 240, 240, 240, 240, 255, 255, 255, 255, 240, 240, 240, 240,
	170, 85, 170, 85, 170, 85, 170, 85, 0, 0, 0, 0, 170, 85, 170, 85,
	170, 85, 170, 85, 0, 0, 0, 0, 0, 36, 36, 0, 0, 0, 0, 0,
	0, 28, 34, 120, 32, 32, 126, 0, 0, 8, 62, 40, 62, 10, 62, 8,
	0, 0, 0, 16, 0, 0, 16, 0, 0, 60, 66, 4, 8, 0, 8, 0,
	0, 4, 8, 8, 8, 8, 4, 0, 0, 32, 16, 16, 16, 16, 32, 0,
	0, 0, 16, 8, 4, 8, 16, 0, 0, 0, 4, 8, 16, 8, 4, 0,
	0, 0, 0, 62, 0, 62, 0, 0, 0, 0, 8, 8, 62, 8, 8, 0,
	0, 0, 0, 0, 62, 0, 0, 0, 0, 0, 20, 8, 62, 8, 20, 0,
	0, 0, 2, 4, 8, 16, 32, 0, 0, 0, 16, 0, 0, 16, 16, 32,
	0, 0, 0, 0, 0, 8, 8, 16, 0, 0, 0, 0, 0, 24, 24, 0,
	0, 60, 70, 74, 82, 98, 60, 0, 0, 24, 40, 8, 8, 8, 62, 0,
	0, 60, 66, 2, 60, 64, 126, 0, 0, 60, 66, 12, 2, 66, 60, 0,
	0, 8, 24, 40, 72, 126, 8, 0, 0, 126, 64, 124, 2, 66, 60, 0,
	0, 60, 64, 124, 66, 66, 60, 0, 0, 126, 2, 4, 8, 16, 16, 0,
	0, 60, 66, 60, 66, 66, 60, 0, 0, 60, 66, 66, 62, 2, 60, 0,
	0, 60, 66, 66, 126, 66, 66, 0, 0, 124, 66, 124, 66, 66, 124, 0,
	0, 60, 66, 64, 64, 66, 60, 0, 0, 120, 68, 66, 66, 68, 120, 0,
	0, 126, 64, 124, 64, 64, 126, 0, 0, 126, 64, 124, 64, 64, 64, 0,
	0, 60, 66, 64, 78, 66, 60, 0, 0, 66, 66, 126, 66, 66, 66, 0,
	0, 62, 8, 8, 8, 8, 62, 0, 0, 2, 2, 2, 66, 66, 60, 0,
	0, 68, 72, 112, 72, 68, 66, 0, 0, 64, 64, 64, 64, 64, 126, 0,
	0, 66, 102, 90, 66, 66, 66, 0, 0, 66, 98, 82, 74, 70, 66, 0,
	0, 60, 66, 66, 66, 66, 60, 0, 0, 124, 66, 66, 124, 64, 64, 0,
	0, 60, 66, 66, 82, 74, 60, 0, 0, 124, 66, 66, 124, 68, 66, 0,
	0, 60, 64, 60, 2, 66, 60, 0, 0, 254, 16, 16, 16, 16, 16, 0,
	0, 66, 66, 66, 66, 66, 60, 0, 0, 66, 66, 66, 66, 36, 24, 0,
	0, 66, 66, 66, 66, 90, 36, 0, 0, 66, 36, 24, 24, 36, 66, 0,
	0, 130, 68, 40, 16, 16, 16, 0, 0, 126, 4, 8, 16, 32, 126, 0 };

static int Stream_ReadByte(Stream *self)
{
	if (self->contentOffset >= self->contentLength)
		return -1;
	return self->content[self->contentOffset++];
}

static bool Stream_SkipUntilByte(Stream *self, int expected)
{
	for (;;) {
		int b = Stream_ReadByte(self);
		if (b < 0)
			return false;
		if (b == expected)
			return true;
	}
}

static bool Stream_Expect(Stream *self, const char *s)
{
	for (const char *c = s; *c != '\0'; c++)
		if (Stream_ReadByte(self) != *c)
			return false;
	return true;
}

static bool Stream_ReadBytes(Stream *self, uint8_t *dest, int destOffset, int count)
{
	int nextOffset = self->contentOffset + count;
	if (nextOffset > self->contentLength)
		return false;
	memcpy(dest + destOffset, self->content + self->contentOffset, count);
	self->contentOffset = nextOffset;
	return true;
}

static int Stream_ReadHexDigit(Stream *self)
{
	if (self->contentOffset >= self->contentLength)
		return -1;
	int c = self->content[self->contentOffset++];
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'A' && c <= 'F')
		return c - 55;
	if (c >= 'a' && c <= 'f')
		return c - 87;
	self->contentOffset--;
	return -1;
}

static int Stream_ReadHexByte(Stream *self)
{
	int hi = Stream_ReadHexDigit(self);
	if (hi < 0)
		return -1;
	int lo = Stream_ReadHexDigit(self);
	if (lo < 0)
		return -1;
	return hi << 4 | lo;
}

static int Stream_ParseInt(Stream *self, int b, int maxValue)
{
	int r = Stream_ReadHexDigit(self);
	if (r < 0 || r >= b)
		return -1;
	do {
		int d = Stream_ReadHexDigit(self);
		if (d < 0)
			return r;
		if (d >= b)
			return -1;
		r = r * b + d;
	}
	while (r <= maxValue);
	return -1;
}

static int Stream_ParseDaliInt(Stream *self)
{
	int r = Stream_ParseInt(self, 10, 32000);
	if (r < 0 || Stream_ReadByte(self) != '\r' || Stream_ReadByte(self) != '\n')
		return -1;
	return r;
}

static int GdosFntStream_ReadWord(GdosFntStream *self)
{
	if (self->base.contentOffset + 1 >= self->base.contentLength)
		return -1;
	int first = self->base.content[self->base.contentOffset];
	int second = self->base.content[self->base.contentOffset + 1];
	self->base.contentOffset += 2;
	return self->bigEndian ? first << 8 | second : first | second << 8;
}

static int GdosFntStream_ReadInt(GdosFntStream *self)
{
	int value = self->bigEndian ? RECOIL_Get32BigEndian(self->base.content, self->base.contentOffset) : RECOIL_Get32LittleEndian(self->base.content, self->base.contentOffset);
	self->base.contentOffset += 4;
	return value;
}

static bool GdosFntStream_FitRow(GdosFntStream *self)
{
	self->leftX = self->rightX;
	do {
		self->rightX = self->nextX;
		self->nextX = GdosFntStream_ReadWord(self);
		if (self->nextX < self->rightX)
			return self->nextX < 0;
		if (self->nextX > self->bitmapWidth) {
			self->nextX = -1;
			return true;
		}
	}
	while (self->nextX - self->leftX <= self->width);
	return true;
}

static bool DaliStream_Decode(DaliStream *self, int countLength, RECOIL *recoil, int paletteOffset, int mode)
{
	uint8_t unpacked[32000];
	int valueOffset = self->base.contentOffset + countLength - 4;
	int count = 1;
	for (int x = 0; x < 160; x += 4) {
		for (int unpackedOffset = x; unpackedOffset < 32000; unpackedOffset += 160) {
			if (--count <= 0) {
				if (valueOffset + 7 >= self->base.contentLength)
					return false;
				count = self->base.content[self->base.contentOffset++];
				if (count == 0)
					return false;
				valueOffset += 4;
			}
			memcpy(unpacked + unpackedOffset, self->base.content + valueOffset, 4);
		}
	}
	return RECOIL_DecodeSt(recoil, unpacked, 0, self->base.content, paletteOffset, mode, 0);
}

static int ZxpStream_ReadChar(ZxpStream *self)
{
	int c = Stream_ReadByte(&self->base);
	if (c == '\r' && self->base.contentOffset < self->base.contentLength && self->base.content[self->base.contentOffset] == '\n') {
		self->base.contentOffset++;
		return '\n';
	}
	return c;
}

static bool ZxpStream_IsEof(const ZxpStream *self)
{
	return self->base.contentOffset >= self->base.contentLength;
}

static int AppleSprStream_ReadSprInt(AppleSprStream *self)
{
	while (self->base.contentOffset < self->base.contentLength) {
		int c = self->base.content[self->base.contentOffset];
		switch (c) {
		case ' ':
		case '\t':
		case '\r':
		case '\n':
			self->base.contentOffset++;
			break;
		case '$':
			self->base.contentOffset++;
			return Stream_ParseInt(&self->base, 16, 319);
		case '%':
			self->base.contentOffset++;
			return Stream_ParseInt(&self->base, 2, 319);
		default:
			return Stream_ParseInt(&self->base, 10, 319);
		}
	}
	return -1;
}

static int VplStream_SkipWhitespace(VplStream *self)
{
	while (self->base.contentOffset < self->base.contentLength) {
		int b = self->base.content[self->base.contentOffset];
		switch (b) {
		case ' ':
		case '\t':
		case '\r':
			self->base.contentOffset++;
			break;
		default:
			return b;
		}
	}
	return -1;
}

static int VplStream_Decode(VplStream *self)
{
	int colors = 0;
	for (;;) {
		switch (VplStream_SkipWhitespace(self)) {
		case -1:
			return colors;
		case '#':
		case '\n':
			Stream_SkipUntilByte(&self->base, '\n');
			break;
		default:
			if (colors >= 128)
				return -1;
			int r = Stream_ParseInt(&self->base, 16, 255);
			if (r < 0)
				return -1;
			VplStream_SkipWhitespace(self);
			int g = Stream_ParseInt(&self->base, 16, 255);
			if (g < 0)
				return -1;
			VplStream_SkipWhitespace(self);
			int b = Stream_ParseInt(&self->base, 16, 255);
			if (b < 0)
				return -1;
			VplStream_SkipWhitespace(self);
			if (Stream_ParseInt(&self->base, 16, 15) < 0)
				return -1;
			self->palette[colors++] = r << 16 | g << 8 | b;
			switch (VplStream_SkipWhitespace(self)) {
			case -1:
				return colors;
			case '\n':
				self->base.contentOffset++;
				break;
			default:
				return -1;
			}
			break;
		}
	}
}

static void VplStream_CopyTo(const VplStream *self, int *palette, int colors)
{
	memcpy(palette, self->palette, colors * sizeof(int));
}

static void BitStream_Construct(BitStream *self)
{
	static const BitStreamVtbl vtbl = {
		BitStream_ReadBit,
	};
	self->vtbl = &vtbl;
	self->bits = 0;
}

static int BitStream_ReadBit(BitStream *self)
{
	if ((self->bits & 127) == 0) {
		if (self->base.contentOffset >= self->base.contentLength)
			return -1;
		self->bits = self->base.content[self->base.contentOffset++] << 1 | 1;
	}
	else
		self->bits <<= 1;
	return self->bits >> 8 & 1;
}

static int BitStream_ReadBits(BitStream *self, int count)
{
	int result = 0;
	while (--count >= 0) {
		int bit = self->vtbl->readBit(self);
		if (bit < 0)
			return -1;
		result = result << 1 | bit;
	}
	return result;
}

static int BitStream_ReadNl3Char(BitStream *self, bool skipSpace)
{
	int e;
	do
		e = Stream_ReadByte(&self->base);
	while (e == '\r' || e == '\n' || (skipSpace && e == ' '));
	if (e != 239)
		return e;
	if (self->base.contentOffset + 1 >= self->base.contentLength)
		return -1;
	switch (self->base.content[self->base.contentOffset++]) {
	case 189:
		e = self->base.content[self->base.contentOffset++];
		if (e >= 160 && e <= 191)
			return e;
		break;
	case 190:
		e = self->base.content[self->base.contentOffset++];
		if (e >= 128 && e <= 159)
			return e + 64;
		break;
	default:
		break;
	}
	return -1;
}

static void X68KPicStream_Construct(X68KPicStream *self)
{
	BitStream_Construct(&self->base);
}

static int X68KPicStream_ReadLength(X68KPicStream *self)
{
	for (int bits = 1; bits < 21; bits++) {
		switch (self->base.vtbl->readBit(&self->base)) {
		case 0:
			;
			int length = BitStream_ReadBits(&self->base, bits);
			if (length < 0)
				return -1;
			return length + (1 << bits) - 1;
		case 1:
			break;
		default:
			return -1;
		}
	}
	return -1;
}

static void Mx1Stream_Construct(Mx1Stream *self)
{
	X68KPicStream_Construct(&self->base);
	static const BitStreamVtbl vtbl = {
		(int (*)(BitStream *self)) Mx1Stream_ReadBit,
	};
	self->base.base.vtbl = &vtbl;
	int d = 0;
	for (int e = 0; e < 256; e++) {
		if ((e >= '!' && e <= '~' && e != '"' && e != '\'' && e != ',' && e != '@' && e != '\\' && e != '`') || (e >= 161 && e <= 200))
			self->decodeTable[e] = (uint8_t) d++;
		else
			self->decodeTable[e] = 128;
	}
}

static bool Mx1Stream_FindImage(Mx1Stream *self)
{
	for (;;) {
		int lineOffset = self->base.base.base.contentOffset;
		for (;;) {
			int c = Stream_ReadByte(&self->base.base.base);
			if (c < 0)
				return false;
			if (c == '\r' || c == '\n')
				break;
		}
		if (self->base.base.base.contentOffset - lineOffset >= 17 && RECOIL_IsStringAt(self->base.base.base.content, lineOffset, "@@@ ") && RECOIL_IsStringAt(self->base.base.base.content, self->base.base.base.contentOffset - 11, "lines) @@@")) {
			self->base.base.bits = 0;
			return true;
		}
	}
}

static int Mx1Stream_ReadBit(Mx1Stream *self)
{
	if ((self->base.base.bits & 63) == 0) {
		int e = BitStream_ReadNl3Char(&self->base.base, true);
		if (e < 0)
			return -1;
		int d = self->decodeTable[e];
		if (d >= 128)
			return -1;
		self->base.base.bits = d << 1 | 1;
	}
	else
		self->base.base.bits <<= 1;
	return self->base.base.bits >> 7 & 1;
}

static void MppPaletteStream_Construct(MppPaletteStream *self)
{
	BitStream_Construct(&self->base);
}

static int MppPaletteStream_Read(MppPaletteStream *self)
{
	int rgb;
	switch (self->base.base.content[4] & 3) {
	case 0:
		rgb = BitStream_ReadBits(&self->base, 9);
		rgb = (rgb & 448) << 10 | (rgb & 56) << 5 | (rgb & 7);
		return rgb << 5 | rgb << 2 | (rgb >> 1 & 197379);
	case 1:
		rgb = BitStream_ReadBits(&self->base, 12);
		rgb = (rgb & 1792) << 9 | (rgb & 2160) << 5 | (rgb & 135) << 1 | (rgb & 8) >> 3;
		return rgb << 4 | rgb;
	case 3:
		return RECOIL_GetSteInterlacedColor(BitStream_ReadBits(&self->base, 15));
	default:
		return 0;
	}
}

static void MultiPalette_Construct(MultiPalette *self)
{
	BitStream_Construct(&self->base);
}

static void ArtPalette_Construct(ArtPalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) ArtPalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static void ArtPalette_SetLinePalette(ArtPalette *self, RECOIL *recoil, int y)
{
	if (y == 0)
		RECOIL_SetStPalette(recoil, self->base.base.base.content, 32768, 16, 0);
	else if (self->base.base.base.contentOffset < 36864 && self->base.base.base.content[self->base.base.base.contentOffset] == 0 && self->base.base.base.content[self->base.base.base.contentOffset + 1] == y) {
		RECOIL_SetStPalette(recoil, self->base.base.base.content, self->base.base.base.contentOffset, 16, 1);
		self->base.base.base.contentOffset += 32;
	}
}

static void GfaArtistPalette_Construct(GfaArtistPalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) GfaArtistPalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static void GfaArtistPalette_SetLinePalette(GfaArtistPalette *self, RECOIL *recoil, int y)
{
	RECOIL_SetStPalette(recoil, self->base.base.base.content, 32036 + ((y + 5) / 3 << 5), 16, 0);
}

static void RastPalette_Construct(RastPalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) RastPalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static void RastPalette_SetLinePalette(RastPalette *self, RECOIL *recoil, int y)
{
	int paletteLength = (1 + self->colors) << 1;
	for (int offset = self->base.base.base.contentOffset; offset <= self->base.base.base.contentLength - paletteLength; offset += paletteLength) {
		if (y == (self->base.base.base.content[offset] << 8 | self->base.base.base.content[offset + 1])) {
			RECOIL_SetStPalette(recoil, self->base.base.base.content, offset + 2, self->colors, 0);
			break;
		}
	}
}

static void HblPalette_Construct(HblPalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) HblPalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool HblPalette_HasPalette(const HblPalette *self, int row)
{
	return self->base.base.base.content[row << 1] != 255 || self->base.base.base.content[row << 1 | 1] != 255;
}

static bool HblPalette_Init(HblPalette *self)
{
	if (!HblPalette_HasPalette(self, 0))
		return false;
	self->base.base.base.contentOffset = 896;
	for (int row = 1; row < 50; row++) {
		if (HblPalette_HasPalette(self, row))
			self->base.base.base.contentOffset += 48;
	}
	return self->base.base.base.contentOffset <= self->base.base.base.contentLength;
}

static void HblPalette_SetLinePalette(HblPalette *self, RECOIL *recoil, int y)
{
	if ((y & 3) == 0 && HblPalette_HasPalette(self, y >> 2)) {
		self->base.base.base.contentOffset -= 48;
		int bitplanes = RECOIL_GetWidth(recoil) == 320 || y == 0 ? 4 : 2;
		for (int c = 0; c < 1 << bitplanes; c++) {
			int offset = self->base.base.base.contentOffset + c * 3;
			int rgb = (self->base.base.base.content[offset] << 16 | self->base.base.base.content[offset + 1] << 8 | self->base.base.base.content[offset + 2]) & 460551;
			RECOIL_SetStVdiColor(recoil, c, rgb << 5 | rgb << 2 | (rgb >> 1 & 197379), bitplanes);
		}
	}
}

static void CtblPalette_Construct(CtblPalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) CtblPalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static void CtblPalette_SetLinePalette(CtblPalette *self, RECOIL *recoil, int y)
{
	RECOIL_SetOcsPalette(recoil, self->base.base.base.content, self->base.base.base.contentOffset + (y * self->colors << 1), self->colors);
}

static void ShamLacePalette_Construct(ShamLacePalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) ShamLacePalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static void ShamLacePalette_SetLinePalette(ShamLacePalette *self, RECOIL *recoil, int y)
{
	RECOIL_SetOcsPalette(recoil, self->base.base.base.content, self->base.base.base.contentOffset + (y >> 1 << 5), 16);
}

static void PchgPalette_Construct(PchgPalette *self)
{
	MultiPalette_Construct(&self->base);
	static const MultiPaletteVtbl vtbl = {
		BitStream_ReadBit,
		(void (*)(MultiPalette *self, RECOIL *recoil, int y)) PchgPalette_SetLinePalette,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
	self->havePaletteChange = NULL;
}

static void PchgPalette_Destruct(PchgPalette *self)
{
	free(self->havePaletteChange);
}

static int PchgPalette_ReadHuffman(PchgPalette *self)
{
	int offset = self->treeLastOffset;
	for (;;) {
		switch (self->base.base.vtbl->readBit(&self->base.base)) {
		case 0:
			offset -= 2;
			if (offset < self->treeOffset)
				return -1;
			if ((self->base.base.base.content[offset] & 129) == 1)
				return self->base.base.base.content[offset + 1];
			break;
		case 1:
			;
			int hi = self->base.base.base.content[offset];
			int lo = self->base.base.base.content[offset + 1];
			if (hi < 128)
				return lo;
			offset += (hi - 256) << 8 | lo;
			if (offset < self->treeOffset)
				return -1;
			break;
		default:
			return -1;
		}
	}
}

static bool PchgPalette_Init(PchgPalette *self)
{
	if (self->base.base.base.contentOffset + 20 > self->base.base.base.contentLength || self->base.base.base.content[self->base.base.base.contentOffset] != 0)
		return false;
	switch (self->base.base.base.content[self->base.base.base.contentOffset + 3] & 3) {
	case 1:
		self->ocs = true;
		break;
	case 2:
		self->ocs = false;
		break;
	default:
		return false;
	}
	self->startLine = self->base.base.base.content[self->base.base.base.contentOffset + 4] << 8 | self->base.base.base.content[self->base.base.base.contentOffset + 5];
	self->lineCount = self->base.base.base.content[self->base.base.base.contentOffset + 6] << 8 | self->base.base.base.content[self->base.base.base.contentOffset + 7];
	int havePaletteChangeLength = (self->lineCount + 31) >> 5 << 2;
	free(self->havePaletteChange);
	self->havePaletteChange = (uint8_t *) malloc(havePaletteChangeLength * sizeof(uint8_t));
	switch (self->base.base.base.content[self->base.base.base.contentOffset + 1]) {
	case 0:
		self->base.base.base.contentOffset += 20;
		if (!Stream_ReadBytes(&self->base.base.base, self->havePaletteChange, 0, havePaletteChangeLength))
			return false;
		self->compressed = false;
		break;
	case 1:
		self->treeOffset = self->base.base.base.contentOffset + 28;
		if (self->treeOffset > self->base.base.base.contentLength)
			return false;
		int treeLength = RECOIL_Get32BigEndian(self->base.base.base.content, self->base.base.base.contentOffset + 20);
		if (treeLength < 2 || treeLength > 1022)
			return false;
		self->base.base.base.contentOffset = self->treeOffset + treeLength;
		self->treeLastOffset = self->base.base.base.contentOffset - 2;
		for (int i = 0; i < havePaletteChangeLength; i++) {
			int b = PchgPalette_ReadHuffman(self);
			if (b < 0)
				return false;
			self->havePaletteChange[i] = (uint8_t) b;
		}
		self->compressed = true;
		break;
	default:
		return false;
	}
	return true;
}

static int PchgPalette_UnpackByte(PchgPalette *self)
{
	return self->compressed ? PchgPalette_ReadHuffman(self) : Stream_ReadByte(&self->base.base.base);
}

static void PchgPalette_SetOcsColors(PchgPalette *self, RECOIL *recoil, int paletteOffset, int count)
{
	while (--count >= 0) {
		int rr = PchgPalette_UnpackByte(self);
		if (rr < 0)
			return;
		int gb = PchgPalette_UnpackByte(self);
		if (gb < 0)
			return;
		RECOIL_SetOcsColor(recoil, paletteOffset + (rr >> 4), rr, gb);
	}
}

static void PchgPalette_SetLinePalette(PchgPalette *self, RECOIL *recoil, int y)
{
	y -= self->startLine;
	if (y < 0 || y >= self->lineCount)
		return;
	if ((self->havePaletteChange[y >> 3] >> (~y & 7) & 1) == 0)
		return;
	int count = PchgPalette_UnpackByte(self);
	if (count < 0)
		return;
	int count2 = PchgPalette_UnpackByte(self);
	if (count2 < 0)
		return;
	if (self->ocs) {
		PchgPalette_SetOcsColors(self, recoil, 0, count);
		PchgPalette_SetOcsColors(self, recoil, 16, count2);
	}
	else {
		count = count << 8 | count2;
		while (--count >= 0) {
			if (PchgPalette_UnpackByte(self) != 0)
				return;
			int c = PchgPalette_UnpackByte(self);
			if (c < 0 || PchgPalette_UnpackByte(self) < 0)
				return;
			int r = PchgPalette_UnpackByte(self);
			if (r < 0)
				return;
			int b = PchgPalette_UnpackByte(self);
			if (b < 0)
				return;
			int g = PchgPalette_UnpackByte(self);
			if (g < 0)
				return;
			recoil->contentPalette[c] = r << 16 | g << 8 | b;
		}
	}
}

static void RleStream_Construct(RleStream *self)
{
	BitStream_Construct(&self->base);
	self->repeatCount = 0;
}

static int RleStream_ReadValue(RleStream *self)
{
	return Stream_ReadByte(&self->base.base);
}

static int RleStream_ReadRle(RleStream *self)
{
	while (self->repeatCount == 0) {
		if (!((const RleStreamVtbl *) self->base.vtbl)->readCommand(self))
			return -1;
	}
	self->repeatCount--;
	if (self->repeatValue >= 0)
		return self->repeatValue;
	return ((const RleStreamVtbl *) self->base.vtbl)->readValue(self);
}

static bool RleStream_Unpack(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedEnd)
{
	for (; unpackedOffset < unpackedEnd; unpackedOffset += unpackedStride) {
		int b = RleStream_ReadRle(self);
		if (b < 0)
			return false;
		unpacked[unpackedOffset] = (uint8_t) b;
	}
	return true;
}

static bool RleStream_UnpackColumns(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedEnd)
{
	for (int x = 0; x < unpackedStride; x++) {
		if (!RleStream_Unpack(self, unpacked, unpackedOffset + x, unpackedStride, unpackedEnd))
			return false;
	}
	return true;
}

static bool RleStream_UnpackWords(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedEnd)
{
	for (; unpackedOffset < unpackedEnd; unpackedOffset += unpackedStride) {
		int b = RleStream_ReadRle(self);
		if (b < 0)
			return false;
		unpacked[unpackedOffset] = (uint8_t) b;
		b = RleStream_ReadRle(self);
		if (b < 0)
			return false;
		unpacked[unpackedOffset + 1] = (uint8_t) b;
	}
	return true;
}

static bool RleStream_UnpackBackwards(RleStream *self, uint8_t *unpacked, int unpackedOffset, int unpackedEnd)
{
	while (unpackedEnd >= unpackedOffset) {
		int b = RleStream_ReadRle(self);
		if (b < 0)
			return false;
		unpacked[unpackedEnd--] = (uint8_t) b;
	}
	return true;
}

static void BldStream_Construct(BldStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) BldStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool BldStream_ReadCommand(BldStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	self->base.repeatValue = b;
	if (b == 0 || b == 255) {
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		self->base.repeatCount = b + 1;
	}
	else
		self->base.repeatCount = 1;
	return true;
}

static void BbgStream_Construct(BbgStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) BbgStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int BbgStream_ReadBitsReverse(BbgStream *self, int count)
{
	int result = 0;
	for (int i = 0; i < count; i++) {
		switch (self->base.base.vtbl->readBit(&self->base.base)) {
		case 0:
			break;
		case 1:
			result |= 1 << i;
			break;
		default:
			return -1;
		}
	}
	return result;
}

static bool BbgStream_ReadCommand(BbgStream *self)
{
	switch (self->base.base.vtbl->readBit(&self->base.base)) {
	case 0:
		self->base.repeatCount = 1;
		break;
	case 1:
		self->base.repeatCount = BbgStream_ReadBitsReverse(self, self->countBits);
		if (self->base.repeatCount <= 0)
			return false;
		break;
	default:
		return false;
	}
	self->base.repeatValue = BbgStream_ReadBitsReverse(self, self->valueBits);
	return true;
}

static void MspStream_Construct(MspStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) MspStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool MspStream_ReadCommand(MspStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b == 0) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		return self->base.repeatValue >= 0;
	}
	self->base.repeatCount = b;
	self->base.repeatValue = -1;
	return true;
}

static void C64KoalaStream_Construct(C64KoalaStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) C64KoalaStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool C64KoalaStream_ReadCommand(C64KoalaStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b == 254) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		return self->base.repeatCount >= 0;
	}
	self->base.repeatValue = b;
	self->base.repeatCount = 1;
	return true;
}

static void CmpStream_Construct(CmpStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) CmpStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool CmpStream_ReadCommand(CmpStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b == self->escape) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base) + 1;
		b = Stream_ReadByte(&self->base.base.base);
	}
	else
		self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return b >= 0;
}

static void DrpStream_Construct(DrpStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) DrpStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool DrpStream_ReadCommand(DrpStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b == self->escape) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		b = Stream_ReadByte(&self->base.base.base);
	}
	else
		self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return b >= 0;
}

static uint8_t const *DrpStream_UnpackFile(uint8_t const *content, int contentLength, const char *signature, uint8_t *unpacked, int unpackedLength)
{
	if (contentLength > 16 && RECOIL_IsStringAt(content, 2, signature)) {
		DrpStream rle;
		DrpStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 16;
		rle.base.base.base.contentLength = contentLength;
		rle.escape = content[15];
		return RleStream_Unpack(&rle.base, unpacked, 2, 1, unpackedLength) ? unpacked : NULL;
	}
	if (contentLength != unpackedLength)
		return NULL;
	return content;
}

static void HpmStream_Construct(HpmStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) HpmStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool HpmStream_ReadCommand(HpmStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b == 0) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		b = Stream_ReadByte(&self->base.base.base);
	}
	else
		self->base.repeatValue = -1;
	self->base.repeatCount = b;
	return b >= 0;
}

static void UflStream_Construct(UflStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) UflStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool UflStream_ReadCommand(UflStream *self)
{
	int b = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	if (b == self->escape) {
		self->base.repeatCount = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		b = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	}
	else
		self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return b >= 0;
}

static void UifStream_Construct(UifStream *self)
{
	UflStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) UflStream_ReadCommand,
		(int (*)(RleStream *self)) UifStream_ReadValue,
	};
	self->base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int UifStream_ReadValue(UifStream *self)
{
	if (self->base.base.base.base.contentOffset <= 2)
		return -1;
	return self->base.base.base.base.content[--self->base.base.base.base.contentOffset];
}

static bool UifStream_StartSifFrame(UifStream *self, int contentOffset)
{
	if (contentOffset + 5 >= self->base.base.base.base.contentLength)
		return false;
	int packedLength = self->base.base.base.base.content[contentOffset] + (self->base.base.base.base.content[contentOffset + 1] << 8) - 37890;
	if (packedLength <= 0 || contentOffset + 2 + packedLength > self->base.base.base.base.contentLength)
		return false;
	self->base.base.base.base.contentOffset = contentOffset + 2 + packedLength;
	self->base.escape = self->base.base.base.base.content[contentOffset + 2];
	return true;
}

static void PgcStream_Construct(PgcStream *self)
{
	RleStream_Construct(&self->base);
	static const PgcStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PgcStream_ReadCommand,
		RleStream_ReadValue,
		PgcStream_ReadCommandByte,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int PgcStream_ReadCommandByte(PgcStream *self)
{
	return Stream_ReadByte(&self->base.base.base);
}

static bool PgcStream_ReadCommand(PgcStream *self)
{
	int b = ((const PgcStreamVtbl *) self->base.base.vtbl)->readCommandByte(self);
	if (b < 0)
		return false;
	if (b < 128) {
		self->base.repeatCount = b;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = b - 128;
		self->base.repeatValue = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	}
	return true;
}

static void DaVinciStream_Construct(DaVinciStream *self)
{
	PgcStream_Construct(&self->base);
	static const PgcStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PgcStream_ReadCommand,
		(int (*)(RleStream *self)) DaVinciStream_ReadValue,
		PgcStream_ReadCommandByte,
	};
	self->base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int DaVinciStream_ReadValue(DaVinciStream *self)
{
	if (self->base.base.base.base.contentOffset + 3 > self->base.base.base.base.contentLength)
		return -1;
	self->base.base.base.base.contentOffset += 3;
	return self->base.base.base.base.content[self->base.base.base.base.contentOffset - 2] << 16 | self->base.base.base.base.content[self->base.base.base.base.contentOffset - 1] << 8 | self->base.base.base.base.content[self->base.base.base.base.contentOffset - 3];
}

static void VectorSprStream_Construct(VectorSprStream *self)
{
	PgcStream_Construct(&self->base);
	static const PgcStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PgcStream_ReadCommand,
		(int (*)(RleStream *self)) VectorSprStream_ReadValue,
		(int (*)(PgcStream *self)) VectorSprStream_ReadCommandByte,
	};
	self->base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int VectorSprStream_ReadValue(VectorSprStream *self)
{
	if (self->base.base.base.base.contentOffset <= 16)
		return -1;
	return self->base.base.base.base.content[--self->base.base.base.base.contentOffset];
}

static int VectorSprStream_ReadCommandByte(VectorSprStream *self)
{
	return ((const PgcStreamVtbl *) self->base.base.base.vtbl)->readValue(&self->base.base);
}

static void ScStream_Construct(ScStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) ScStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool ScStream_ReadCommand(ScStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		self->base.repeatCount = b;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = b - 128;
		self->base.repeatValue = -1;
	}
	return true;
}

static void CciStream_Construct(CciStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) CciStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool CciStream_ReadCommand(CciStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		self->base.repeatCount = b + 1;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = b - 127;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	return true;
}

static bool CciStream_UnpackGr15(CciStream *self, uint8_t *unpacked, int unpackedOffset)
{
	self->base.base.base.contentOffset += 4;
	self->base.repeatCount = 0;
	for (int x = 0; x < 40; x++) {
		if (!RleStream_Unpack(&self->base, unpacked, unpackedOffset + x, 80, 7680))
			return false;
	}
	return true;
}

static void PackBitsStream_Construct(PackBitsStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PackBitsStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool PackBitsStream_ReadCommand(PackBitsStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		self->base.repeatCount = b + 1;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = 257 - b;
		self->base.repeatValue = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	}
	return true;
}

static bool PackBitsStream_UnpackBitplaneLines(PackBitsStream *self, uint8_t *unpacked, int width, int height, int bitplanes, bool compressed, bool hasMask)
{
	int bytesPerBitplane = (width + 15) >> 4 << 1;
	int bytesPerLine = bitplanes * bytesPerBitplane;
	for (int y = 0; y < height; y++) {
		for (int bitplane = 0; bitplane < bitplanes; bitplane++) {
			for (int w = bitplane << 1; w < bytesPerLine; w += bitplanes << 1) {
				for (int x = 0; x < 2; x++) {
					int b = compressed ? RleStream_ReadRle(&self->base) : Stream_ReadByte(&self->base.base.base);
					if (b < 0)
						return false;
					unpacked[y * bytesPerLine + w + x] = (uint8_t) b;
				}
			}
		}
		if (hasMask) {
			for (int x = 0; x < bytesPerBitplane; x++) {
				int b = compressed ? RleStream_ReadRle(&self->base) : Stream_ReadByte(&self->base.base.base);
				if (b < 0)
					return false;
			}
		}
	}
	return true;
}

static void SpcStream_Construct(SpcStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) SpcStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool SpcStream_ReadCommand(SpcStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		self->base.repeatCount = b + 1;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = 258 - b;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	return true;
}

static void SpsStream_Construct(SpsStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) SpsStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool SpsStream_ReadCommand(SpsStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		self->base.repeatCount = b + 3;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = b - 127;
		self->base.repeatValue = -1;
	}
	return true;
}

static void VhiStream_Construct(VhiStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) VhiStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool VhiStream_ReadCommand(VhiStream *self)
{
	int c;
	switch (Stream_ReadByte(&self->base.base.base)) {
	case 0:
		c = Stream_ReadByte(&self->base.base.base);
		self->base.repeatValue = -1;
		break;
	case 1:
		c = Stream_ReadByte(&self->base.base.base);
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		break;
	default:
		return false;
	}
	self->base.repeatCount = c == 0 ? 256 : c;
	return true;
}

static void PrintfoxStream_Construct(PrintfoxStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PrintfoxStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool PrintfoxStream_ReadCommand(PrintfoxStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b == 155) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.base.base.content[0] != 'P')
			self->base.repeatCount += Stream_ReadByte(&self->base.base.base) << 8;
		else if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		b = Stream_ReadByte(&self->base.base.base);
	}
	else
		self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return b >= 0;
}

static void ArtMaster88Stream_Construct(ArtMaster88Stream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) ArtMaster88Stream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
	self->escape = -1;
}

static bool ArtMaster88Stream_ReadCommand(ArtMaster88Stream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b == self->escape) {
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		self->base.repeatCount = (b - 1) & 255;
		self->escape = -1;
	}
	else {
		self->base.repeatCount = 1;
		self->escape = self->base.repeatValue = b;
	}
	return true;
}

static bool ArtMaster88Stream_SkipChunk(ArtMaster88Stream *self)
{
	if (self->base.base.base.contentOffset + 1 >= self->base.base.base.contentLength)
		return false;
	int length = self->base.base.base.content[self->base.base.base.contentOffset] | self->base.base.base.content[self->base.base.base.contentOffset + 1] << 8;
	if (length < 2)
		return false;
	self->base.base.base.contentOffset += length;
	return true;
}

static bool ArtMaster88Stream_ReadPlanes(ArtMaster88Stream *self, int planes, int planeLength)
{
	for (int plane = 0; plane < planes; plane++) {
		if (!RleStream_Unpack(&self->base, self->planes[plane], 0, 1, planeLength))
			return false;
	}
	return true;
}

static void SrStream_Construct(SrStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) SrStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool SrStream_ReadCommand(SrStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	switch (b) {
	case -1:
		return false;
	case 0:
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		return true;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		self->base.repeatCount = b;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		return true;
	default:
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return true;
	}
}

static void PacStream_Construct(PacStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PacStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool PacStream_ReadCommand(PacStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b == self->base.base.base.content[4]) {
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		self->base.repeatCount = b + 1;
		self->base.repeatValue = self->base.base.base.content[5];
	}
	else if (b == self->base.base.base.content[6]) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatValue < 0)
			return false;
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		self->base.repeatCount = b + 1;
	}
	else {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
	}
	return true;
}

static void Bdp4Stream_Construct(Bdp4Stream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) Bdp4Stream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool Bdp4Stream_ReadCommand(Bdp4Stream *self)
{
	switch (Stream_ReadByte(&self->base.base.base)) {
	case 255:
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		return self->base.repeatValue >= 0;
	case 254:
		;
		int lo = Stream_ReadByte(&self->base.base.base);
		int hi = Stream_ReadByte(&self->base.base.base);
		if (hi < 0)
			return false;
		self->base.repeatCount = lo | hi << 8;
		self->base.repeatValue = -1;
		return true;
	default:
		return false;
	}
}

static void Bdp5Stream_Construct(Bdp5Stream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) Bdp5Stream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool Bdp5Stream_ReadCommand(Bdp5Stream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b == self->base.base.base.content[10] || b == self->base.base.base.content[11]) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (b == self->base.base.base.content[11])
			self->base.repeatCount |= Stream_ReadByte(&self->base.base.base) << 8;
		else if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		b = Stream_ReadByte(&self->base.base.base);
	}
	else
		self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return b >= 0;
}

static void XlpStream_Construct(XlpStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) XlpStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool XlpStream_ReadCommand(XlpStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	bool rle;
	if (b < 128)
		rle = false;
	else {
		b -= 128;
		rle = true;
	}
	self->base.repeatCount = b;
	if (b >= 64) {
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		self->base.repeatCount = (self->base.repeatCount - 64) << 8 | b;
	}
	self->base.repeatValue = rle ? Stream_ReadByte(&self->base.base.base) : -1;
	return true;
}

static void AmstradStream_Construct(AmstradStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) AmstradStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
	self->blockLength = 0;
}

static bool AmstradStream_ReadCommand(AmstradStream *self)
{
	while (self->blockLength <= 0) {
		if (Stream_ReadByte(&self->base.base.base) != 'M' || Stream_ReadByte(&self->base.base.base) != 'J' || Stream_ReadByte(&self->base.base.base) != 'H')
			return false;
		int lo = Stream_ReadByte(&self->base.base.base);
		if (lo < 0)
			return false;
		int hi = Stream_ReadByte(&self->base.base.base);
		if (hi < 0)
			return false;
		self->blockLength = hi << 8 | lo;
	}
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b == 1) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
	}
	self->blockLength -= self->base.repeatCount;
	return true;
}

static bool AmstradStream_UnpackFile(uint8_t const *content, int contentOffset, int contentLength, uint8_t *unpacked, int unpackedLength)
{
	AmstradStream rle;
	AmstradStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_Unpack(&rle.base, unpacked, 0, 1, unpackedLength);
}

static void CpiStream_Construct(CpiStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) CpiStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool CpiStream_ReadCommand(CpiStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (self->base.base.base.contentOffset + 1 < self->base.base.base.contentLength && self->base.base.base.content[self->base.base.base.contentOffset] == b) {
		self->base.base.base.contentOffset++;
		self->base.repeatCount = 1 + self->base.base.base.content[self->base.base.base.contentOffset++];
	}
	else
		self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return true;
}

static void VbmStream_Construct(VbmStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) VbmStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool VbmStream_ReadCommand(VbmStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b == self->base.base.base.content[9]) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		return self->base.repeatCount > 0;
	}
	if (b == self->base.base.base.content[10]) {
		self->base.repeatValue = 0;
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		return self->base.repeatCount > 0;
	}
	if (b == self->base.base.base.content[11]) {
		self->base.repeatValue = 255;
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		return self->base.repeatCount > 0;
	}
	if (b == self->base.base.base.content[12]) {
		self->base.repeatValue = 0;
		self->base.repeatCount = 2;
		return true;
	}
	if (b == self->base.base.base.content[13]) {
		self->base.repeatValue = 255;
		self->base.repeatCount = 2;
		return true;
	}
	self->base.repeatValue = b;
	self->base.repeatCount = 1;
	return true;
}

static void XeKoalaStream_Construct(XeKoalaStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) XeKoalaStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool XeKoalaStream_ReadCommand(XeKoalaStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	bool rle;
	if (b < 128)
		rle = true;
	else {
		b -= 128;
		rle = false;
	}
	if (b == 0) {
		int hi = Stream_ReadByte(&self->base.base.base);
		if (hi < 0)
			return false;
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		b |= hi << 8;
	}
	self->base.repeatCount = b;
	self->base.repeatValue = rle ? Stream_ReadByte(&self->base.base.base) : -1;
	return true;
}

static bool XeKoalaStream_UnpackRaw(XeKoalaStream *self, int type, int unpackedLength)
{
	switch (type) {
	case 0:
		if (self->base.base.base.contentLength - self->base.base.base.contentOffset != unpackedLength)
			return false;
		memcpy(self->unpacked, self->base.base.base.content + self->base.base.base.contentOffset, unpackedLength);
		return true;
	case 1:
		for (int x = 0; x < 40; x++) {
			for (int unpackedOffset = x; unpackedOffset < 80; unpackedOffset += 40) {
				if (!RleStream_Unpack(&self->base, self->unpacked, unpackedOffset, 80, unpackedLength))
					return false;
			}
		}
		return true;
	case 2:
		return RleStream_Unpack(&self->base, self->unpacked, 0, 1, unpackedLength);
	default:
		return false;
	}
}

static bool XeKoalaStream_UnpackWrapped(XeKoalaStream *self, int unpackedLength)
{
	if (Stream_ReadByte(&self->base.base.base) != 255 || Stream_ReadByte(&self->base.base.base) != 128 || Stream_ReadByte(&self->base.base.base) != 201 || Stream_ReadByte(&self->base.base.base) != 199)
		return false;
	int offset = Stream_ReadByte(&self->base.base.base);
	offset |= Stream_ReadByte(&self->base.base.base) << 8;
	if (offset < 26 || Stream_ReadByte(&self->base.base.base) != 1)
		return false;
	int type = Stream_ReadByte(&self->base.base.base);
	self->base.base.base.contentOffset++;
	if (Stream_ReadByte(&self->base.base.base) != 0 || Stream_ReadByte(&self->base.base.base) != 40 || Stream_ReadByte(&self->base.base.base) != 0)
		return false;
	self->base.base.base.contentOffset += 9;
	if (Stream_ReadByte(&self->base.base.base) != 0)
		return false;
	self->base.base.base.contentOffset += offset - 21;
	return XeKoalaStream_UnpackRaw(self, type, unpackedLength);
}

static void ImgStream_Construct(ImgStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) ImgStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
	self->patternRepeatCount = 0;
}

static int ImgStream_GetLineRepeatCount(ImgStream *self)
{
	if (self->base.repeatCount == 0 && self->base.base.base.contentOffset < self->base.base.base.contentLength - 4 && self->base.base.base.content[self->base.base.base.contentOffset] == 0 && self->base.base.base.content[self->base.base.base.contentOffset + 1] == 0 && self->base.base.base.content[self->base.base.base.contentOffset + 2] == 255) {
		self->base.base.base.contentOffset += 4;
		return self->base.base.base.content[self->base.base.base.contentOffset - 1];
	}
	return 1;
}

static bool ImgStream_ReadCommand(ImgStream *self)
{
	if (self->patternRepeatCount > 1) {
		self->patternRepeatCount--;
		self->base.repeatCount = self->base.base.base.content[6] << 8 | self->base.base.base.content[7];
		self->base.base.base.contentOffset -= self->base.repeatCount;
		return true;
	}
	int b = Stream_ReadByte(&self->base.base.base);
	switch (b) {
	case -1:
		return false;
	case 0:
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		if (b == 0) {
			b = Stream_ReadByte(&self->base.base.base);
			if (b < 0)
				return false;
			self->base.repeatCount = b + 1;
			self->base.repeatValue = 256;
			return true;
		}
		self->patternRepeatCount = b;
		self->base.repeatCount = self->base.base.base.content[6] << 8 | self->base.base.base.content[7];
		self->base.repeatValue = -1;
		return true;
	case 128:
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount < 0)
			return false;
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		self->base.repeatValue = -1;
		return true;
	default:
		self->base.repeatCount = b & 127;
		self->base.repeatValue = b >= 128 ? 255 : 0;
		return true;
	}
}

static bool ImgStream_UnpackLine(ImgStream *self, uint8_t *unpacked, int unpackedLength, int y)
{
	for (int x = 0; x < unpackedLength; x++) {
		int b = RleStream_ReadRle(&self->base);
		if (b < 0)
			return false;
		if (b != 256)
			unpacked[x] = (uint8_t) b;
		else if (y == 0)
			unpacked[x] = 0;
	}
	return true;
}

static void CaStream_Construct(CaStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) CaStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool CaStream_ReadCommand(CaStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b != self->escape) {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return true;
	}
	int c = Stream_ReadByte(&self->base.base.base);
	if (c < 0)
		return false;
	if (c == self->escape) {
		self->base.repeatCount = 1;
		self->base.repeatValue = c;
		return true;
	}
	b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	switch (c) {
	case 0:
		self->base.repeatCount = b + 1;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		break;
	case 1:
		c = Stream_ReadByte(&self->base.base.base);
		if (c < 0)
			return false;
		self->base.repeatCount = (b << 8) + c + 1;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		break;
	case 2:
		if (b == 0)
			self->base.repeatCount = 32000;
		else {
			c = Stream_ReadByte(&self->base.base.base);
			if (c < 0)
				return false;
			self->base.repeatCount = (b << 8) + c + 1;
		}
		self->base.repeatValue = self->defaultValue;
		break;
	default:
		self->base.repeatCount = c + 1;
		self->base.repeatValue = b;
		break;
	}
	return true;
}

static bool CaStream_UnpackCa(CaStream *self, uint8_t *unpacked, int unpackedOffset)
{
	if (self->base.base.base.contentOffset > self->base.base.base.contentLength - 4)
		return false;
	self->escape = self->base.base.base.content[self->base.base.base.contentOffset];
	self->defaultValue = self->base.base.base.content[self->base.base.base.contentOffset + 1];
	int unpackedStep = self->base.base.base.content[self->base.base.base.contentOffset + 2] << 8 | self->base.base.base.content[self->base.base.base.contentOffset + 3];
	if (unpackedStep >= 32000)
		return false;
	self->base.repeatCount = 0;
	if (unpackedStep == 0) {
		self->base.repeatCount = 32000;
		self->base.repeatValue = self->defaultValue;
		unpackedStep = 1;
	}
	self->base.base.base.contentOffset += 4;
	return RleStream_UnpackColumns(&self->base, unpacked, unpackedOffset, unpackedStep, unpackedOffset + 32000);
}

static bool CaStream_UnpackDel(uint8_t const *content, int contentLength, uint8_t *unpacked, int blocks)
{
	CaStream rle;
	CaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = blocks << 2;
	if (rle.base.base.base.contentOffset >= contentLength)
		return false;
	for (int block = 0; block < blocks; block++) {
		rle.base.base.base.contentLength = rle.base.base.base.contentOffset + RECOIL_Get32BigEndian(content, block << 2);
		if (rle.base.base.base.contentLength > contentLength || rle.base.base.base.contentLength < rle.base.base.base.contentOffset || !CaStream_UnpackCa(&rle, unpacked, block * 32000))
			return false;
		rle.base.base.base.contentOffset = rle.base.base.base.contentLength;
	}
	if (blocks == 2) {
		rle.base.base.base.contentLength = contentLength;
		return CaStream_UnpackCa(&rle, unpacked, 64000);
	}
	return true;
}

static void RgbStream_Construct(RgbStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) RgbStream_ReadCommand,
		(int (*)(RleStream *self)) RgbStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int RgbStream_ReadValue(RgbStream *self)
{
	return BitStream_ReadBits(&self->base.base, 12);
}

static bool RgbStream_ReadCommand(RgbStream *self)
{
	int b = BitStream_ReadBits(&self->base.base, 4);
	if (b < 0)
		return false;
	bool rle;
	if (b < 8)
		rle = true;
	else {
		b -= 8;
		rle = false;
	}
	if (b == 0) {
		b = BitStream_ReadBits(&self->base.base, 4);
		if (b < 0)
			return false;
		b += 7;
	}
	if (rle) {
		self->base.repeatValue = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
		b++;
	}
	else
		self->base.repeatValue = -1;
	self->base.repeatCount = b;
	return true;
}

static void TnyPcsStream_Construct(TnyPcsStream *self)
{
	RleStream_Construct(&self->base);
}

static bool TnyPcsStream_ReadTnyCommand(TnyPcsStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		if (b == 0 || b == 1) {
			if (self->base.base.base.contentOffset >= self->base.base.base.contentLength - 1)
				return false;
			self->base.repeatCount = self->base.base.base.content[self->base.base.base.contentOffset] << 8 | self->base.base.base.content[self->base.base.base.contentOffset + 1];
			self->base.base.base.contentOffset += 2;
		}
		else
			self->base.repeatCount = b;
		self->base.repeatValue = b == 1 ? -1 : ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	}
	else {
		self->base.repeatCount = 256 - b;
		self->base.repeatValue = -1;
	}
	return true;
}

static void TnyStream_Construct(TnyStream *self)
{
	TnyPcsStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) TnyStream_ReadCommand,
		(int (*)(RleStream *self)) TnyStream_ReadValue,
	};
	self->base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool TnyStream_ReadCommand(TnyStream *self)
{
	return TnyPcsStream_ReadTnyCommand(&self->base);
}

static int TnyStream_ReadValue(TnyStream *self)
{
	if (self->valueOffset + 1 >= self->valueLength)
		return -1;
	int value = self->base.base.base.base.content[self->valueOffset] << 8 | self->base.base.base.base.content[self->valueOffset + 1];
	self->valueOffset += 2;
	return value;
}

static void PcsStream_Construct(PcsStream *self)
{
	TnyPcsStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PcsStream_ReadCommand,
		(int (*)(RleStream *self)) PcsStream_ReadValue,
	};
	self->base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool PcsStream_ReadCommand(PcsStream *self)
{
	if (self->commandCount <= 0)
		return false;
	self->commandCount--;
	return TnyPcsStream_ReadTnyCommand(&self->base);
}

static int PcsStream_ReadValue(PcsStream *self)
{
	if (!self->palette)
		return Stream_ReadByte(&self->base.base.base.base);
	if (self->base.base.base.base.contentOffset >= self->base.base.base.base.contentLength - 1)
		return -1;
	int value = self->base.base.base.base.content[self->base.base.base.base.contentOffset] << 8 | self->base.base.base.base.content[self->base.base.base.base.contentOffset + 1];
	self->base.base.base.base.contentOffset += 2;
	return value;
}

static bool PcsStream_StartBlock(PcsStream *self)
{
	if (self->base.base.base.base.contentOffset >= self->base.base.base.base.contentLength - 1)
		return false;
	self->commandCount = self->base.base.base.base.content[self->base.base.base.base.contentOffset] << 8 | self->base.base.base.base.content[self->base.base.base.base.contentOffset + 1];
	self->base.base.base.base.contentOffset += 2;
	return true;
}

static bool PcsStream_EndBlock(PcsStream *self)
{
	while (self->base.base.repeatCount > 0 || self->commandCount > 0) {
		if (RleStream_ReadRle(&self->base.base) < 0)
			return false;
	}
	return true;
}

static bool PcsStream_UnpackPcs(PcsStream *self, uint8_t *unpacked)
{
	self->palette = false;
	if (!PcsStream_StartBlock(self) || !RleStream_Unpack(&self->base.base, unpacked, 0, 1, 32000) || !PcsStream_EndBlock(self))
		return false;
	self->palette = true;
	if (!PcsStream_StartBlock(self))
		return false;
	for (int unpackedOffset = 32000; unpackedOffset < 51136; unpackedOffset += 2) {
		int b = RleStream_ReadRle(&self->base.base);
		if (b < 0)
			return false;
		unpacked[unpackedOffset] = (uint8_t) (b >> 8);
		unpacked[unpackedOffset + 1] = (uint8_t) b;
	}
	return PcsStream_EndBlock(self);
}

static void VdatStream_Construct(VdatStream *self)
{
	TnyStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) VdatStream_ReadCommand,
		(int (*)(RleStream *self)) TnyStream_ReadValue,
	};
	self->base.base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool VdatStream_ReadCommand(VdatStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base.base.base);
	if (b < 0)
		return false;
	if (b < 128) {
		if (b == 0 || b == 1) {
			self->base.base.base.repeatCount = ((const RleStreamVtbl *) self->base.base.base.base.vtbl)->readValue(&self->base.base.base);
			if (self->base.base.base.repeatCount < 0)
				return false;
		}
		else
			self->base.base.base.repeatCount = b;
		self->base.base.base.repeatValue = b == 0 ? -1 : ((const RleStreamVtbl *) self->base.base.base.base.vtbl)->readValue(&self->base.base.base);
	}
	else {
		self->base.base.base.repeatCount = 256 - b;
		self->base.base.base.repeatValue = -1;
	}
	return true;
}

static void HimStream_Construct(HimStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) HimStream_ReadCommand,
		(int (*)(RleStream *self)) HimStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int HimStream_ReadValue(HimStream *self)
{
	if (self->base.base.base.contentOffset < 18)
		return -1;
	return self->base.base.base.content[self->base.base.base.contentOffset--];
}

static bool HimStream_ReadCommand(HimStream *self)
{
	int b = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	switch (b) {
	case -1:
		return false;
	case 0:
		self->base.repeatCount = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
		if (self->base.repeatCount <= 0)
			return false;
		self->base.repeatValue = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
		return true;
	default:
		self->base.repeatCount = b - 1;
		self->base.repeatValue = -1;
		return true;
	}
}

static void IcStream_Construct(IcStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) IcStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool IcStream_ReadCount(IcStream *self)
{
	self->base.repeatCount = 257;
	while (Stream_ReadByte(&self->base.base.base) == 1)
		self->base.repeatCount += 256;
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	self->base.repeatCount += b;
	return true;
}

static bool IcStream_ReadCommand(IcStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	int escape = self->base.base.base.content[66];
	if (b != escape) {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return true;
	}
	b = Stream_ReadByte(&self->base.base.base);
	if (b == escape) {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return true;
	}
	switch (b) {
	case -1:
		return false;
	case 0:
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return false;
		self->base.repeatCount = b + 1;
		break;
	case 1:
		if (!IcStream_ReadCount(self))
			return false;
		break;
	case 2:
		b = Stream_ReadByte(&self->base.base.base);
		switch (b) {
		case -1:
			return false;
		case 0:
			self->base.repeatCount = 32000;
			break;
		case 1:
			if (!IcStream_ReadCount(self))
				return false;
			break;
		case 2:
			while (Stream_ReadByte(&self->base.base.base) > 0) {
			}
			self->base.repeatCount = 0;
			break;
		default:
			self->base.repeatCount = b + 1;
			break;
		}
		self->base.repeatValue = 0;
		return true;
	default:
		self->base.repeatCount = b + 1;
		break;
	}
	self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	return true;
}

static void DeepStream_Construct(DeepStream *self)
{
	PackBitsStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) PackBitsStream_ReadCommand,
		(int (*)(RleStream *self)) DeepStream_ReadValue,
	};
	self->base.base.base.vtbl = (const BitStreamVtbl *) &vtbl;
	self->components = 0;
	self->line = NULL;
}

static void DeepStream_Destruct(DeepStream *self)
{
	free(self->line);
}

static bool DeepStream_SetDpel(DeepStream *self, int chunkOffset, int chunkLength)
{
	if (chunkLength < 8 || self->base.base.base.base.content[chunkOffset + 8] != 0 || self->base.base.base.base.content[chunkOffset + 9] != 0 || self->base.base.base.base.content[chunkOffset + 10] != 0)
		return false;
	self->components = self->base.base.base.base.content[chunkOffset + 11];
	if (self->components > 6 || chunkLength != (self->components + 1) << 2)
		return false;
	for (int c = 0; c < self->components; c++) {
		int offset = chunkOffset + 12 + c * 4;
		if (self->base.base.base.base.content[offset] != 0 || self->base.base.base.base.content[offset + 2] != 0 || self->base.base.base.base.content[offset + 3] != 8)
			return false;
		int shift;
		switch (self->base.base.base.base.content[offset + 1]) {
		case 1:
			shift = 16;
			break;
		case 2:
			shift = 8;
			break;
		case 3:
			shift = 0;
			break;
		case 4:
		case 9:
		case 10:
		case 11:
		case 17:
			shift = -1;
			break;
		default:
			return false;
		}
		self->componentShift[c] = shift;
	}
	return true;
}

static int DeepStream_ReadValue(DeepStream *self)
{
	int rgb = 0;
	for (int c = 0; c < self->components; c++) {
		int b = Stream_ReadByte(&self->base.base.base.base);
		if (b < 0)
			return -1;
		int shift = self->componentShift[c];
		if (shift >= 0)
			rgb |= b << shift;
	}
	return rgb;
}

static int DeepStream_ReadNibble(DeepStream *self)
{
	if (self->currentByte < 0) {
		self->currentByte = Stream_ReadByte(&self->base.base.base.base);
		if (self->currentByte < 0)
			return -1;
		return self->currentByte >> 4;
	}
	int result = self->currentByte & 15;
	self->currentByte = -1;
	return result;
}

static bool DeepStream_ReadDeltaLine(DeepStream *self, int width, int tvdcOffset)
{
	if (self->line == NULL) {
		free(self->line);
		self->line = (int *) malloc(width * sizeof(int));
	}
	for (int c = 0; c < self->components; c++) {
		int count = 0;
		int value = 0;
		self->currentByte = -1;
		for (int x = 0; x < width; x++) {
			if (count == 0) {
				int i = DeepStream_ReadNibble(self);
				if (i < 0)
					return false;
				int delta = self->base.base.base.base.content[tvdcOffset + i * 2 + 1];
				if (delta == 0) {
					if (self->base.base.base.base.content[tvdcOffset + i * 2] == 0) {
						count = DeepStream_ReadNibble(self);
						if (count < 0)
							return false;
					}
				}
				else
					value = (value + delta) & 255;
			}
			else
				count--;
			int rgb = c == 0 ? 0 : self->line[x];
			int shift = self->componentShift[c];
			if (shift >= 0)
				rgb |= value << shift;
			self->line[x] = rgb;
		}
	}
	return true;
}

static void PackBytesStream_Construct(PackBytesStream *self)
{
	self->count = 1;
	self->pattern = 0;
}

static int PackBytesStream_ReadUnpacked(PackBytesStream *self)
{
	if (--self->count == 0) {
		if (self->base.contentOffset >= self->base.contentLength)
			return -1;
		int b = self->base.content[self->base.contentOffset++];
		self->count = (b & 63) + 1;
		if (b >= 128)
			self->count <<= 2;
		static const uint8_t PATTERNS[4] = { 0, 1, 4, 1 };
		self->pattern = PATTERNS[b >> 6];
	}
	else if ((self->count & (self->pattern - 1)) == 0)
		self->base.contentOffset -= self->pattern;
	return Stream_ReadByte(&self->base);
}

static bool Lz4Stream_Copy(Lz4Stream *self, int count)
{
	if (self->unpackedOffset + count > self->unpackedLength || !Stream_ReadBytes(&self->base, self->unpacked, self->unpackedOffset, count))
		return false;
	self->unpackedOffset += count;
	return true;
}

static int Lz4Stream_ReadCount(Lz4Stream *self, int count)
{
	if (count == 15) {
		int b;
		do {
			b = Stream_ReadByte(&self->base);
			if (b < 0)
				return -1;
			count += b;
		}
		while (b == 255);
	}
	return count;
}

static void Tre1Stream_Construct(Tre1Stream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) Tre1Stream_ReadCommand,
		(int (*)(RleStream *self)) Tre1Stream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
	self->lastRgb = -1;
}

static bool Tre1Stream_ReadCommand(Tre1Stream *self)
{
	self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
	if (self->base.repeatCount <= 0)
		return false;
	if (self->base.repeatCount == 255) {
		if (self->base.base.base.contentOffset + 1 >= self->base.base.base.contentLength)
			return false;
		self->base.repeatCount = 255 + (self->base.base.base.content[self->base.base.base.contentOffset] << 8) + self->base.base.base.content[self->base.base.base.contentOffset + 1];
		self->base.base.base.contentOffset += 2;
	}
	self->base.repeatValue = self->lastRgb;
	self->lastRgb = -1;
	return true;
}

static int Tre1Stream_ReadValue(Tre1Stream *self)
{
	if (self->base.base.base.contentOffset + 1 >= self->base.base.base.contentLength)
		return -1;
	self->lastRgb = RECOIL_GetFalconTrueColor(self->base.base.base.content, self->base.base.base.contentOffset);
	self->base.base.base.contentOffset += 2;
	return self->lastRgb;
}

static void MciStream_Construct(MciStream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) MciStream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static bool MciStream_ReadCommand(MciStream *self)
{
	if (self->base.base.base.contentOffset < 2)
		return false;
	int b = self->base.base.base.content[self->base.base.base.contentOffset--];
	for (int e = 8; e >= 0; e--) {
		if (b == self->base.base.base.content[129 + e]) {
			switch (self->base.base.base.content[120 + e]) {
			case 0:
				self->base.repeatCount = 2;
				self->base.repeatValue = self->base.base.base.content[133 + e];
				return true;
			case 7:
				if (self->base.base.base.contentOffset < 2)
					return false;
				self->base.repeatCount = 2 + self->base.base.base.content[self->base.base.base.contentOffset--];
				self->base.repeatValue = self->base.base.base.content[79];
				return true;
			case 11:
				self->base.repeatCount = 3;
				self->base.repeatValue = self->base.base.base.content[79];
				return true;
			case 17:
				if (self->base.base.base.contentOffset < 3)
					return false;
				self->base.repeatCount = 2 + self->base.base.base.content[self->base.base.base.contentOffset--];
				self->base.repeatValue = self->base.base.base.content[self->base.base.base.contentOffset--];
				return true;
			case 23:
				if (self->base.base.base.contentOffset < 2)
					return false;
				self->base.repeatCount = 3;
				self->base.repeatValue = self->base.base.base.content[self->base.base.base.contentOffset--];
				return true;
			case 25:
				if (self->base.base.base.contentOffset < 2)
					return false;
				b = self->base.base.base.content[self->base.base.base.contentOffset--];
				break;
			default:
				break;
			}
			break;
		}
	}
	self->base.repeatCount = 1;
	self->base.repeatValue = b;
	return true;
}

static void Nl3Stream_Construct(Nl3Stream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) Nl3Stream_ReadCommand,
		(int (*)(RleStream *self)) Nl3Stream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int Nl3Stream_ReadValue(Nl3Stream *self)
{
	int e = BitStream_ReadNl3Char(&self->base.base, false);
	if (e < 32)
		return -1;
	if (e < 127)
		return e - 32;
	if (e < 160)
		return -1;
	if (e < 224)
		return e - 65;
	if (e == 253)
		return 159;
	if (e == 254)
		return 160;
	return -1;
}

static bool Nl3Stream_ReadCommand(Nl3Stream *self)
{
	int b = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
	if (b < 0 || b > 127)
		return false;
	self->base.repeatValue = b & 63;
	if (b < 64)
		self->base.repeatCount = 1;
	else {
		b = ((const RleStreamVtbl *) self->base.base.vtbl)->readValue(&self->base);
		if (b < 0)
			return false;
		self->base.repeatCount = b + 2;
	}
	return true;
}

static void SfdnStream_Construct(SfdnStream *self)
{
	BitStream_Construct(&self->base);
}

static bool SfdnStream_Unpack(SfdnStream *self, uint8_t *unpacked, int unpackedLength)
{
	if (self->base.base.contentLength < 22 + (unpackedLength >> 1) || !RECOIL_IsStringAt(self->base.base.content, 0, "S101") || (self->base.base.content[4] | self->base.base.content[5] << 8) != unpackedLength)
		return false;
	self->base.base.contentOffset = 22;
	int current = BitStream_ReadBits(&self->base, 4);
	int hi = -1;
	for (int unpackedOffset = 0;;) {
		if (hi < 0)
			hi = current;
		else {
			unpacked[unpackedOffset++] = (uint8_t) (hi << 4 | current);
			if (unpackedOffset >= unpackedLength)
				return true;
			hi = -1;
		}
		int code;
		int bit;
		for (code = 0;; code += 2) {
			bit = self->base.vtbl->readBit(&self->base);
			if (bit == 0)
				break;
			if (bit < 0 || code >= 14)
				return false;
		}
		bit = self->base.vtbl->readBit(&self->base);
		if (bit < 0)
			return false;
		code += bit;
		current = (current - self->base.base.content[6 + code]) & 15;
	}
}

static void G9bStream_Construct(G9bStream *self)
{
	BitStream_Construct(&self->base);
}

static int G9bStream_ReadLength(G9bStream *self)
{
	for (int length = 1; length < 65536;) {
		switch (self->base.vtbl->readBit(&self->base)) {
		case 0:
			return length + 1;
		case 1:
			break;
		default:
			return -1;
		}
		length <<= 1;
		switch (self->base.vtbl->readBit(&self->base)) {
		case 0:
			break;
		case 1:
			length++;
			break;
		default:
			return -1;
		}
	}
	return -2;
}

static bool G9bStream_Unpack(G9bStream *self, uint8_t *unpacked, int headerLength, int unpackedLength)
{
	self->base.base.contentOffset = headerLength + 3;
	for (int unpackedOffset = headerLength; unpackedOffset < unpackedLength;) {
		int b;
		switch (self->base.vtbl->readBit(&self->base)) {
		case 0:
			b = Stream_ReadByte(&self->base.base);
			if (b < 0)
				return false;
			unpacked[unpackedOffset++] = (uint8_t) b;
			break;
		case 1:
			;
			int length = G9bStream_ReadLength(self);
			if (length == -2) {
				self->base.base.contentOffset += 2;
				self->base.bits = 0;
				break;
			}
			if (length < 0 || unpackedOffset + length > unpackedLength)
				return false;
			int distance = Stream_ReadByte(&self->base.base);
			if (distance < 0)
				return false;
			if (distance >= 128) {
				b = BitStream_ReadBits(&self->base, 4);
				if (b < 0)
					return false;
				distance += (b - 1) << 7;
			}
			distance++;
			if (unpackedOffset - distance < headerLength)
				return false;
			do {
				unpacked[unpackedOffset] = unpacked[unpackedOffset - distance];
				unpackedOffset++;
			}
			while (--length > 0);
			break;
		default:
			return false;
		}
	}
	return true;
}

static void MigStream_Construct(MigStream *self)
{
	BitStream_Construct(&self->base);
}

static int MigStream_Unpack(MigStream *self, uint8_t *unpacked)
{
	self->base.base.contentOffset = 15;
	for (int unpackedOffset = 0; unpackedOffset < 108800;) {
		int c = self->base.vtbl->readBit(&self->base);
		if (c < 0)
			return -1;
		int b = Stream_ReadByte(&self->base.base);
		if (b < 0)
			return -1;
		if (c == 0)
			unpacked[unpackedOffset++] = (uint8_t) b;
		else {
			if (b >= 128) {
				c = BitStream_ReadBits(&self->base, 4);
				if (c < 0)
					return -1;
				b += (c - 1) << 7;
			}
			int distance = b + 1;
			if (unpackedOffset - distance < 0)
				return -1;
			c = -1;
			do {
				b = self->base.vtbl->readBit(&self->base);
				if (b < 0)
					return -1;
				c++;
			}
			while (b != 0);
			int length = BitStream_ReadBits(&self->base, c);
			if (length < 0)
				return -1;
			if (c >= 16) {
				self->base.base.contentOffset += 4;
				if (self->base.base.contentOffset >= self->base.base.contentLength)
					return unpackedOffset;
				self->base.bits = 0;
			}
			else {
				length += (1 << c) + 1;
				if (unpackedOffset + length > 108800)
					return -1;
				do {
					unpacked[unpackedOffset] = unpacked[unpackedOffset - distance];
					unpackedOffset++;
				}
				while (--length > 0);
			}
		}
	}
	return -1;
}

static int Ice21Stream_GetUnpackedLength(const Ice21Stream *self)
{
	if (self->contentStart + 16 > self->contentOffset || !RECOIL_IsStringAt(self->content, self->contentStart, "Ice!") || RECOIL_Get32BigEndian(self->content, self->contentStart + 4) != self->contentOffset - self->contentStart)
		return -1;
	return RECOIL_Get32BigEndian(self->content, self->contentStart + 8);
}

static int Ice21Stream_ReadBit(Ice21Stream *self)
{
	int b = self->bits;
	int next = b & 2147483647;
	if (next == 0) {
		self->contentOffset -= 4;
		if (self->contentOffset < self->contentStart)
			return -1;
		b = RECOIL_Get32BigEndian(self->content, self->contentOffset);
		self->bits = (b & 2147483647) << 1 | 1;
	}
	else
		self->bits = next << 1;
	return b >> 31 & 1;
}

static int Ice21Stream_ReadBits(Ice21Stream *self, int count)
{
	int result = 0;
	while (--count >= 0) {
		int bit = Ice21Stream_ReadBit(self);
		if (bit < 0)
			return -1;
		result = result << 1 | bit;
	}
	return result;
}

static int Ice21Stream_CountOnes(Ice21Stream *self, int max)
{
	for (int result = 0; result < max; result++) {
		switch (Ice21Stream_ReadBit(self)) {
		case -1:
			return -1;
		case 0:
			return result;
		default:
			break;
		}
	}
	return max;
}

static int Ice21Stream_ReadLiteralLength(Ice21Stream *self)
{
	int o = 1;
	for (int n = 0;; n++) {
		static const uint8_t BITS[6] = { 1, 2, 2, 3, 8, 15 };
		int c = BITS[n];
		int b = Ice21Stream_ReadBits(self, c);
		if (b < 0)
			return -1;
		c = (1 << c) - 1;
		if (b < c || n == 5)
			return o + b;
		o += c;
	}
}

static int Ice21Stream_ReadEncoded(Ice21Stream *self, int maxCount, uint8_t const *extraBits, int const *offsets)
{
	int n = Ice21Stream_CountOnes(self, maxCount);
	if (n < 0)
		return -1;
	int b = Ice21Stream_ReadBits(self, extraBits[n]);
	if (b < 0)
		return -1;
	return offsets[n] + b;
}

static bool Ice21Stream_Unpack(Ice21Stream *self, uint8_t *unpacked, int unpackedStart, int unpackedEnd)
{
	self->contentStart += 12;
	self->contentOffset -= 4;
	self->bits = RECOIL_Get32BigEndian(self->content, self->contentOffset);
	for (int unpackedOffset = unpackedEnd; unpackedOffset > unpackedStart;) {
		int length;
		switch (Ice21Stream_ReadBit(self)) {
		case -1:
			return false;
		case 1:
			length = Ice21Stream_ReadLiteralLength(self);
			if (length < 0)
				return false;
			if (length > unpackedOffset - unpackedStart)
				length = unpackedOffset - unpackedStart;
			self->contentOffset -= length;
			if (self->contentOffset < self->contentStart)
				return false;
			unpackedOffset -= length;
			memcpy(unpacked + unpackedOffset, self->content + self->contentOffset, length);
			if (unpackedOffset == unpackedStart)
				return true;
			break;
		default:
			break;
		}
		static const uint8_t LENGTH_EXTRA_BITS[5] = { 0, 0, 1, 2, 10 };
		static const int LENGTH_OFFSETS[5] = { 0, 1, 2, 4, 8 };
		length = Ice21Stream_ReadEncoded(self, 4, LENGTH_EXTRA_BITS, LENGTH_OFFSETS);
		int offset;
		switch (length) {
		case -1:
			return false;
		case 0:
			switch (Ice21Stream_ReadBit(self)) {
			case -1:
				return false;
			case 0:
				offset = Ice21Stream_ReadBits(self, 6);
				if (offset < 0)
					return false;
				break;
			default:
				offset = Ice21Stream_ReadBits(self, 9);
				if (offset < 0)
					return false;
				offset += 64;
				break;
			}
			break;
		default:
			;
			static const uint8_t OFFSET_EXTRA_BITS[3] = { 8, 5, 12 };
			static const int OFFSET_OFFSETS[3] = { 32, 0, 288 };
			offset = Ice21Stream_ReadEncoded(self, 2, OFFSET_EXTRA_BITS, OFFSET_OFFSETS);
			if (offset < 0)
				return false;
			break;
		}
		length += 2;
		offset += length;
		if (unpackedOffset + offset > unpackedEnd)
			return false;
		if (length > unpackedOffset - unpackedStart)
			length = unpackedOffset - unpackedStart;
		unpackedOffset -= length;
		memcpy(unpacked + unpackedOffset, unpacked + (unpackedOffset + offset), length);
	}
	return true;
}

static int SpxStream_ReadCount(SpxStream *self)
{
	int b = Ice21Stream_ReadBits(&self->base, 2);
	if (b < 0)
		return -1;
	return Ice21Stream_ReadBits(&self->base, (b + 1) << 2);
}

static bool SpxStream_UnpackV2(SpxStream *self, uint8_t *unpacked, int unpackedLength)
{
	self->base.bits = 0;
	for (int unpackedOffset = unpackedLength; unpackedOffset > 0;) {
		int count;
		switch (Ice21Stream_ReadBit(&self->base)) {
		case -1:
			return false;
		case 0:
			count = SpxStream_ReadCount(self);
			if (count <= 0)
				return false;
			if (count > unpackedOffset)
				count = unpackedOffset;
			for (int i = 0; i < count; i++) {
				int b = Ice21Stream_ReadBits(&self->base, 8);
				if (b < 0)
					return false;
				unpacked[--unpackedOffset] = (uint8_t) b;
			}
			if (unpackedOffset == 0)
				return true;
			if (count == 65535)
				continue;
			break;
		default:
			break;
		}
		int distance = SpxStream_ReadCount(self);
		if (distance <= 0 || unpackedOffset + distance > unpackedLength)
			return false;
		count = SpxStream_ReadCount(self);
		if (count < 0)
			return false;
		count = FuInt_Min(count + 3, unpackedOffset);
		do {
			unpackedOffset--;
			unpacked[unpackedOffset] = unpacked[unpackedOffset + distance];
		}
		while (--count > 0);
	}
	return true;
}

static void Q4Stream_Construct(Q4Stream *self)
{
	RleStream_Construct(&self->base);
	static const RleStreamVtbl vtbl = {
		BitStream_ReadBit,
		(bool (*)(RleStream *self)) Q4Stream_ReadCommand,
		RleStream_ReadValue,
	};
	self->base.base.vtbl = (const BitStreamVtbl *) &vtbl;
}

static int Q4Stream_StartChunk(Q4Stream *self)
{
	if (self->base.base.base.contentOffset + 6 > self->base.base.base.contentLength)
		return -1;
	int chunkLength = self->base.base.base.content[self->base.base.base.contentOffset] | self->base.base.base.content[self->base.base.base.contentOffset + 1] << 8;
	self->base.base.base.contentOffset += 6;
	self->base.base.base.contentLength = self->base.base.base.contentOffset + chunkLength;
	return self->base.base.base.contentLength;
}

static int Q4Stream_ReadCode(Q4Stream *self)
{
	do {
		int value = BitStream_ReadBits(&self->base.base, self->codeBits);
		switch (value) {
		case -1:
		case 0:
			return -1;
		case 1:
			break;
		default:
			return value - 2;
		}
	}
	while (++self->codeBits <= 15);
	return -1;
}

static bool Q4Stream_UnpackQ4(Q4Stream *self)
{
	self->base.base.bits = 0;
	self->codeBits = 3;
	int unpackedLength = 0;
	uint16_t offsets[16384];
	for (int codes = 17; codes < 16384; codes++) {
		int code = Q4Stream_ReadCode(self);
		if (code < 0 || code >= codes) {
			self->base.base.base.content = self->unpacked;
			self->base.base.base.contentOffset = 0;
			self->base.base.base.contentLength = unpackedLength;
			self->lastRepeatValue = 0;
			return true;
		}
		if (unpackedLength >= 65536)
			return false;
		offsets[codes] = (uint16_t) unpackedLength;
		if (code <= 16) {
			self->unpacked[unpackedLength++] = (uint8_t) code;
		}
		else {
			int sourceOffset = offsets[code];
			int endOffset = offsets[code + 1];
			if (unpackedLength + endOffset - sourceOffset >= 65536)
				return false;
			do
				self->unpacked[unpackedLength++] = self->unpacked[sourceOffset++];
			while (sourceOffset <= endOffset);
		}
	}
	return false;
}

static bool Q4Stream_ReadCommand(Q4Stream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	if (b < 16) {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return true;
	}
	b = Stream_ReadByte(&self->base.base.base);
	if (b == 0) {
		self->lastRepeatValue = Stream_ReadByte(&self->base.base.base);
		if (self->lastRepeatValue < 0 || self->lastRepeatValue >= 16)
			return false;
		b = Stream_ReadByte(&self->base.base.base);
	}
	if (b < 0)
		return false;
	self->base.repeatCount = b * 17;
	b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return false;
	self->base.repeatCount += b;
	self->base.repeatValue = self->lastRepeatValue;
	return true;
}

static void PiStream_Construct(PiStream *self)
{
	BitStream_Construct(&self->base);
	self->indexes = NULL;
}

static void PiStream_Destruct(PiStream *self)
{
	free(self->indexes);
}

static int PiStream_ReadInt(PiStream *self, int bits, int maxBits)
{
	for (; bits < maxBits; bits++) {
		int b = self->base.vtbl->readBit(&self->base);
		if (b == 0)
			break;
		if (b < 0)
			return -1;
	}
	return 1 << bits | BitStream_ReadBits(&self->base, bits);
}

static bool PiStream_UnpackLiteral(PiStream *self, int indexesOffset, int depth)
{
	int offset;
	switch (self->base.vtbl->readBit(&self->base)) {
	case 1:
		offset = self->base.vtbl->readBit(&self->base);
		break;
	case 0:
		offset = PiStream_ReadInt(self, 1, depth - 1);
		break;
	default:
		return false;
	}
	if (offset < 0)
		return false;
	int recentOffset = indexesOffset == 0 ? 0 : self->indexes[indexesOffset - 1] << 8;
	offset += recentOffset;
	int c = self->recentColors[offset];
	for (; offset > recentOffset; offset--)
		self->recentColors[offset] = self->recentColors[offset - 1];
	self->recentColors[offset] = (uint8_t) c;
	self->indexes[indexesOffset] = (uint8_t) c;
	return true;
}

static bool PiStream_UnpackTwoLiterals(PiStream *self, int indexesOffset, int indexesLength, int depth)
{
	if (!PiStream_UnpackLiteral(self, indexesOffset, depth))
		return false;
	return indexesOffset + 1 >= indexesLength || PiStream_UnpackLiteral(self, indexesOffset + 1, depth);
}

static int PiStream_ReadPosition(PiStream *self)
{
	int position = BitStream_ReadBits(&self->base, 2);
	if (position != 3)
		return position;
	position = self->base.vtbl->readBit(&self->base);
	if (position < 0)
		return -1;
	return 3 + position;
}

static bool PiStream_Unpack(PiStream *self, int width, int height, int depth)
{
	int colors = 1 << depth;
	for (int i = 0; i < colors; i++)
		for (int j = 0; j < colors; j++)
			self->recentColors[i << 8 | j] = (uint8_t) ((i - j) & (colors - 1));
	int indexesLength = width * height;
	free(self->indexes);
	self->indexes = (uint8_t *) malloc(indexesLength * sizeof(uint8_t));
	if (!PiStream_UnpackTwoLiterals(self, 0, indexesLength, depth))
		return false;
	int lastPosition = -1;
	for (int indexesOffset = 0; indexesOffset < indexesLength;) {
		int position = PiStream_ReadPosition(self);
		if (position < 0)
			return false;
		if (position == lastPosition) {
			do {
				if (!PiStream_UnpackTwoLiterals(self, indexesOffset, indexesLength, depth))
					return false;
				indexesOffset += 2;
			}
			while (indexesOffset < indexesLength && self->base.vtbl->readBit(&self->base) == 1);
			lastPosition = -1;
		}
		else {
			int length = PiStream_ReadInt(self, 0, 23);
			if (length < 0)
				return false;
			lastPosition = position;
			switch (position) {
			case 0:
				position = indexesOffset == 0 ? 0 : indexesOffset - 2;
				position = self->indexes[position] == self->indexes[position + 1] ? 2 : 4;
				break;
			case 1:
				position = width;
				break;
			case 2:
				position = width << 1;
				break;
			case 3:
				position = width - 1;
				break;
			case 4:
				position = width + 1;
				break;
			default:
				abort();
			}
			int copyEnd = FuInt_Min(indexesOffset + (length << 1), indexesLength);
			for (; indexesOffset < copyEnd; indexesOffset++) {
				int sourceOffset = indexesOffset - position;
				if (sourceOffset < 0)
					sourceOffset &= 1;
				self->indexes[indexesOffset] = self->indexes[sourceOffset];
			}
		}
	}
	return true;
}

static void A4rStream_Construct(A4rStream *self)
{
	self->outerFlags = 0;
	self->innerFlags = 0;
}

static int A4rStream_ReadFlag(A4rStream *self)
{
	if ((self->innerFlags & 127) == 0) {
		if ((self->outerFlags & 127) == 0) {
			if (self->base.contentOffset >= self->base.contentLength)
				return -1;
			self->outerFlags = self->base.content[self->base.contentOffset++] << 1 | 1;
		}
		else
			self->outerFlags <<= 1;
		if ((self->outerFlags & 256) == 0)
			self->innerFlags = 1;
		else {
			if (self->base.contentOffset >= self->base.contentLength)
				return -1;
			self->innerFlags = self->base.content[self->base.contentOffset++] << 1 | 1;
		}
	}
	else
		self->innerFlags <<= 1;
	return self->innerFlags >> 8 & 1;
}

static bool A4rStream_CopyByte(A4rStream *self)
{
	int b = Stream_ReadByte(&self->base);
	if (b < 0 || self->unpackedOffset < 0 || self->unpackedOffset >= 11248)
		return false;
	self->unpacked[self->unpackedOffset++] = (uint8_t) b;
	return true;
}

static bool A4rStream_CopyBlock(A4rStream *self, int distance, int count)
{
	if (self->unpackedOffset < 0)
		return false;
	int nextOffset = self->unpackedOffset + count;
	if (nextOffset > 11248 || !RECOIL_CopyPrevious(self->unpacked, self->unpackedOffset, distance, count))
		return false;
	self->unpackedOffset = nextOffset;
	return true;
}

static bool A4rStream_UnpackA4r(A4rStream *self)
{
	memset(self->unpacked, 0, sizeof(self->unpacked));
	self->unpackedOffset = -1;
	for (;;) {
		switch (A4rStream_ReadFlag(self)) {
		case 0:
			if (!A4rStream_CopyByte(self))
				return false;
			break;
		case 1:
			;
			int b = Stream_ReadByte(&self->base);
			switch (b) {
			case -1:
				return false;
			case 0:
				if (self->base.contentOffset >= self->base.contentLength - 2)
					return false;
				b = Stream_ReadByte(&self->base);
				self->unpackedOffset = b + (Stream_ReadByte(&self->base) << 8) + 128 - 19984;
				if (!A4rStream_CopyByte(self))
					return false;
				break;
			case 1:
				b = Stream_ReadByte(&self->base);
				switch (b) {
				case -1:
					return false;
				case 0:
					return true;
				default:
					if (!A4rStream_CopyBlock(self, 1, b + 2))
						return false;
					break;
				}
				break;
			default:
				if (!A4rStream_CopyBlock(self, 128 - (b >> 1), 2 + (b & 1)))
					return false;
				break;
			}
			break;
		default:
			return false;
		}
	}
}

static int ZimStream_ReadWord(ZimStream *self)
{
	if (self->base.contentOffset + 1 >= self->base.contentLength)
		return -1;
	int result = self->base.content[self->base.contentOffset] | self->base.content[self->base.contentOffset + 1] << 8;
	self->base.contentOffset += 2;
	return result;
}

static int ZimStream_ReadUnpacked(ZimStream *self, uint8_t const *flags, int unpackedOffset)
{
	return (flags[unpackedOffset >> 3] >> (~unpackedOffset & 7) & 1) != 0 ? Stream_ReadByte(&self->base) : 0;
}

static bool ZimStream_Unpack(ZimStream *self, uint8_t const *flags, uint8_t *unpacked, int unpackedLength)
{
	bool enough = true;
	for (int unpackedOffset = 0; unpackedOffset < unpackedLength; unpackedOffset++) {
		int b = ZimStream_ReadUnpacked(self, flags, unpackedOffset);
		if (b < 0) {
			enough = false;
			b = 0;
		}
		unpacked[unpackedOffset] = (uint8_t) b;
	}
	return enough;
}

static bool ZimStream_UnpackFlags2(ZimStream *self)
{
	int b = Stream_ReadByte(&self->base);
	if (b < 0)
		return false;
	self->flags1[0] = (uint8_t) b;
	return ZimStream_Unpack(self, self->flags1, self->flags2, 8);
}

static void FanoTree_Create(FanoTree *self, uint8_t const *content, int contentOffset, int codeCount)
{
	memset(self->count, 0, sizeof(self->count));
	for (int code = 0; code < codeCount; code++)
		self->count[RECOIL_GetNibble(content, contentOffset, code)]++;
	int positions[16];
	int position = 0;
	for (int bits = 0; bits < 16; bits++) {
		positions[bits] = position;
		position += self->count[bits];
	}
	for (int code = 0; code < codeCount; code++)
		self->values[positions[RECOIL_GetNibble(content, contentOffset, code)]++] = (uint8_t) code;
}

static int FanoTree_ReadCode(const FanoTree *self, BitStream *bitStream)
{
	int code = 0;
	int valuesOffset = self->count[0];
	for (int bits = 1; bits < 16; bits++) {
		int bit = bitStream->vtbl->readBit(bitStream);
		if (bit < 0)
			return -1;
		code = code << 1 | bit;
		int count = self->count[bits];
		if (code < count)
			return self->values[valuesOffset + code];
		code -= count;
		valuesOffset += count;
	}
	return -1;
}

static void RecentInts_Construct(RecentInts *self)
{
	for (size_t _i0 = 0; _i0 < 128; _i0++) {
		self->value[_i0] = 0;
	}
	self->head = 0;
	for (int i = 0; i < 128; i++) {
		self->prev[i] = (uint8_t) ((i + 1) & 127);
		self->next[i] = (uint8_t) ((i - 1) & 127);
	}
}

static void RecentInts_Add(RecentInts *self, int value)
{
	self->head = self->prev[self->head];
	self->value[self->head] = value;
}

static int RecentInts_Get(RecentInts *self, int key)
{
	if (key != self->head) {
		int prev = self->prev[key];
		int next = self->next[key];
		self->next[prev] = (uint8_t) next;
		self->prev[next] = (uint8_t) prev;
		int tail = self->prev[self->head];
		self->next[tail] = (uint8_t) key;
		self->prev[key] = (uint8_t) tail;
		self->prev[self->head] = (uint8_t) key;
		self->next[key] = (uint8_t) self->head;
		self->head = key;
	}
	return self->value[key];
}

static bool BlazingPaddlesBoundingBox_Calculate(BlazingPaddlesBoundingBox *self, uint8_t const *content, int contentLength, int index, int startAddress)
{
	index <<= 1;
	if (index + 1 >= contentLength)
		return false;
	int contentOffset = content[index] + (content[index + 1] << 8) - startAddress;
	if (contentOffset < 0)
		return false;
	self->left = self->top = self->right = self->bottom = 0;
	int x = 0;
	int y = 0;
	while (contentOffset < contentLength) {
		int control = content[contentOffset++];
		if (control == 8)
			return true;
		int len = (control >> 4) + 1;
		switch (control & 3) {
		case 0:
			x += len;
			if (self->right < x)
				self->right = x;
			break;
		case 1:
			x -= len;
			if (self->left > x)
				self->left = x;
			break;
		case 2:
			y -= len;
			if (self->top > y)
				self->top = y;
			break;
		case 3:
			y += len;
			if (self->bottom < y)
				self->bottom = y;
			break;
		default:
			abort();
		}
	}
	return false;
}

static bool IcnParser_SkipWhitespaceAndComments(IcnParser *self)
{
	bool got = false;
	while (self->base.contentOffset < self->base.contentLength) {
		switch (self->base.content[self->base.contentOffset]) {
		case ' ':
		case '\t':
		case '\r':
		case '\n':
			self->base.contentOffset++;
			got = true;
			break;
		case '/':
			if (self->base.contentOffset >= self->base.contentLength - 3 || self->base.content[self->base.contentOffset + 1] != '*')
				return false;
			self->base.contentOffset += 3;
			do {
				if (++self->base.contentOffset > self->base.contentLength)
					return false;
			}
			while (self->base.content[self->base.contentOffset - 2] != '*' || self->base.content[self->base.contentOffset - 1] != '/');
			got = true;
			break;
		default:
			return got;
		}
	}
	return true;
}

static bool IcnParser_ExpectAfterWhitespace(IcnParser *self, const char *s)
{
	return IcnParser_SkipWhitespaceAndComments(self) && Stream_Expect(&self->base, s);
}

static int IcnParser_ParseHex(IcnParser *self)
{
	if (!IcnParser_ExpectAfterWhitespace(self, "0x"))
		return -1;
	return Stream_ParseInt(&self->base, 16, 65535);
}

static int IcnParser_ParseDefine(IcnParser *self, const char *s)
{
	if (!IcnParser_ExpectAfterWhitespace(self, "#define") || !IcnParser_ExpectAfterWhitespace(self, s))
		return -1;
	return IcnParser_ParseHex(self);
}

static int PInterpreter_ReadNumber(PInterpreter *self)
{
	for (;;) {
		switch (Stream_ReadByte(&self->base)) {
		case 21:
		case 22:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 42:
			break;
		case 126:
			if (self->base.contentOffset > self->base.contentLength - 5)
				return -1;
			int exp = Stream_ReadByte(&self->base);
			int m0 = Stream_ReadByte(&self->base);
			int m1 = Stream_ReadByte(&self->base);
			self->base.contentOffset += 2;
			if (exp > 144 || m0 >= 128)
				return -1;
			if (exp <= 128)
				return 0;
			return ((m0 | 128) << 8 | m1) >> (144 - exp);
		default:
			return -1;
		}
	}
}

static int PInterpreter_PrintString(PInterpreter *self, int offset)
{
	for (;;) {
		if (offset >= self->base.contentLength)
			return -1;
		int c = self->base.content[offset++];
		if (c == 11)
			break;
		if (self->screenOffset >= 768)
			return -1;
		if (c == 192)
			c = 11;
		else if ((c & 127) >= 64)
			return -1;
		self->screen[self->screenOffset++] = (uint8_t) c;
		self->newLineWorks = (self->screenOffset & 31) != 0;
	}
	return offset;
}

static bool PInterpreter_Print(PInterpreter *self)
{
	for (;;) {
		switch (Stream_ReadByte(&self->base)) {
		case 11:
			self->base.contentOffset = PInterpreter_PrintString(self, self->base.contentOffset);
			if (self->base.contentOffset < 0)
				return false;
			break;
		case 193:
			;
			int row = PInterpreter_ReadNumber(self);
			if (row < 0 || row > 21 || Stream_ReadByte(&self->base) != 26)
				return false;
			int column = PInterpreter_ReadNumber(self);
			if (column < 0 || column > 31)
				return false;
			self->screenOffset = row << 5 | column;
			self->newLineWorks = true;
			break;
		case 0:
		case 25:
			break;
		case 118:
			self->base.contentOffset--;
			if (self->base.content[self->base.contentOffset - 1] != 25) {
				if (self->newLineWorks)
					self->screenOffset = (self->screenOffset & ~31) + 32;
				self->newLineWorks = true;
			}
			return true;
		default:
			return false;
		}
	}
}

static bool PInterpreter_DPeek(PInterpreter *self, int expectedX, int expectedAddress)
{
	return Stream_ReadByte(&self->base) == 20 && PInterpreter_ReadNumber(self) == expectedX && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 211 && PInterpreter_ReadNumber(self) == expectedAddress && Stream_ReadByte(&self->base) == 21 && PInterpreter_ReadNumber(self) == 256 && Stream_ReadByte(&self->base) == 23 && Stream_ReadByte(&self->base) == 211 && PInterpreter_ReadNumber(self) == expectedAddress + 1;
}

static bool PInterpreter_Let(PInterpreter *self)
{
	switch (Stream_ReadByte(&self->base)) {
	case 38:
		if (Stream_ReadByte(&self->base) != 13 || Stream_ReadByte(&self->base) != 20 || Stream_ReadByte(&self->base) != 11)
			return false;
		self->bottomOffset = self->base.contentOffset;
		for (;;) {
			switch (Stream_ReadByte(&self->base)) {
			case -1:
				return false;
			case 11:
				return true;
			default:
				break;
			}
		}
	case 56:
		self->bottomCode |= 1;
		return PInterpreter_DPeek(self, 3, 16400);
	case 41:
		self->bottomCode |= 2;
		return PInterpreter_DPeek(self, 727, 16396);
	default:
		return false;
	}
}

static bool PInterpreter_DoIf(PInterpreter *self)
{
	return Stream_ReadByte(&self->base) == 198 && Stream_ReadByte(&self->base) == 38 && Stream_ReadByte(&self->base) == 13 && Stream_ReadByte(&self->base) == 221 && PInterpreter_ReadNumber(self) == 64 && Stream_ReadByte(&self->base) == 222 && Stream_ReadByte(&self->base) == 227;
}

static bool PInterpreter_DoFor(PInterpreter *self)
{
	self->bottomCode |= 4;
	return Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 20 && PInterpreter_ReadNumber(self) == 0 && Stream_ReadByte(&self->base) == 223 && PInterpreter_ReadNumber(self) == 63;
}

static bool PInterpreter_Poke(PInterpreter *self)
{
	self->bottomCode |= 8;
	return Stream_ReadByte(&self->base) == 41 && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 16 && Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 18 && PInterpreter_ReadNumber(self) == 31 && Stream_ReadByte(&self->base) == 17 && Stream_ReadByte(&self->base) == 26 && Stream_ReadByte(&self->base) == 211 && Stream_ReadByte(&self->base) == 16 && Stream_ReadByte(&self->base) == 56 && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 17;
}

static bool PInterpreter_Next(PInterpreter *self)
{
	if (Stream_ReadByte(&self->base) == 43 && self->bottomOffset > 0 && self->bottomCode == 15) {
		self->screenOffset = 704;
		return PInterpreter_PrintString(self, self->bottomOffset) >= 0;
	}
	return false;
}

static bool PInterpreter_Run(PInterpreter *self)
{
	self->base.contentOffset = 116;
	memset(self->screen, 0, sizeof(self->screen));
	self->screenOffset = 0;
	self->newLineWorks = true;
	self->bottomOffset = -1;
	self->bottomCode = 0;
	for (;;) {
		if (self->base.contentOffset > self->base.contentLength - 8)
			return false;
		if (Stream_ReadByte(&self->base) == 118)
			return true;
		self->base.contentOffset += 3;
		switch (Stream_ReadByte(&self->base)) {
		case 228:
		case 229:
		case 251:
		case 253:
			break;
		case 227:
		case 236:
		case 242:
			return true;
		case 245:
			if (!PInterpreter_Print(self))
				return false;
			break;
		case 241:
			if (!PInterpreter_Let(self))
				return false;
			break;
		case 250:
			if (!PInterpreter_DoIf(self))
				return false;
			break;
		case 235:
			if (!PInterpreter_DoFor(self))
				return false;
			break;
		case 244:
			if (!PInterpreter_Poke(self))
				return false;
			break;
		case 243:
			if (!PInterpreter_Next(self))
				return false;
			break;
		default:
			return false;
		}
		if (Stream_ReadByte(&self->base) != 118)
			return false;
	}
}

static void GtiaRenderer_SetPlayerSize(GtiaRenderer *self, int i, int size)
{
	size &= 3;
	self->playerSize[i] = (uint8_t) (size == 2 ? 1 : size + 1);
}

static void GtiaRenderer_SetSpriteSizes(uint8_t *sizes, int value)
{
	for (int i = 0; i < 4; i++) {
		int size = value >> (i << 1) & 3;
		sizes[i] = (uint8_t) (size == 2 ? 1 : size + 1);
	}
}

static void GtiaRenderer_Poke(GtiaRenderer *self, int addr, int value)
{
	switch (addr) {
	case 0:
	case 1:
	case 2:
	case 3:
		self->playerHpos[addr] = (uint8_t) value;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		self->missileHpos[addr - 4] = (uint8_t) value;
		break;
	case 8:
	case 9:
	case 10:
	case 11:
		GtiaRenderer_SetPlayerSize(self, addr - 8, value);
		break;
	case 12:
		GtiaRenderer_SetSpriteSizes(self->missileSize, value);
		break;
	case 13:
	case 14:
	case 15:
	case 16:
		self->playerGraphics[addr - 13] = (uint8_t) value;
		break;
	case 17:
		self->missileGraphics = value;
		break;
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
		self->colors[addr - 18] = (uint8_t) (value & 254);
		break;
	case 27:
		self->prior = value;
		break;
	default:
		break;
	}
}

static void GtiaRenderer_ProcessPlayerDma(GtiaRenderer *self, uint8_t const *content, int playersOffset)
{
	for (int i = 0; i < 4; i++)
		self->playerGraphics[i] = content[playersOffset + (i << 8)];
}

static void GtiaRenderer_ProcessSpriteDma(GtiaRenderer *self, uint8_t const *content, int missileOffset)
{
	self->missileGraphics = content[missileOffset];
	GtiaRenderer_ProcessPlayerDma(self, content, missileOffset + 256);
}

static int GtiaRenderer_GetPmg(GtiaRenderer *self, int hpos, int objects)
{
	for (int i = 0; i < 4; i++) {
		if (self->playerHpos[i] == hpos) {
			self->playerShiftRegister[i] |= self->playerGraphics[i];
			self->playerSizeCounter[i] = self->playerSize[i];
		}
		if (self->missileHpos[i] == hpos) {
			self->missileShiftRegister |= self->missileGraphics & 3 << (i << 1);
			self->missileSizeCounter[i] = self->missileSize[i];
		}
	}
	if ((self->prior & 16) != 0 && (self->missileShiftRegister & 170) != 0)
		objects |= 128;
	for (int i = 0; i < 4; i++) {
		if ((self->playerShiftRegister[i] & 128) != 0 || ((self->prior & 16) == 0 && (self->missileShiftRegister & 2 << (i << 1)) != 0))
			objects |= 1 << i;
		if (--self->playerSizeCounter[i] == 0) {
			self->playerShiftRegister[i] = (uint8_t) (self->playerShiftRegister[i] << 1);
			self->playerSizeCounter[i] = self->playerSize[i];
		}
		if (--self->missileSizeCounter[i] == 0) {
			int mask = 1 << (i << 1);
			self->missileShiftRegister = (self->missileShiftRegister & ~(mask * 3)) | (self->missileShiftRegister & mask) << 1;
			self->missileSizeCounter[i] = self->missileSize[i];
		}
	}
	return objects;
}

static int GtiaRenderer_GetColor(const GtiaRenderer *self, int objects)
{
	if (objects == 0)
		return self->colors[8];
	int prior = self->prior;
	int color = 0;
	if ((objects & 3) != 0) {
		if (((objects & 48) == 0 || (prior & 12) == 0) && ((objects & 192) == 0 || (prior & 4) == 0)) {
			if ((objects & 1) != 0) {
				color = self->colors[0];
				if ((objects & 2) != 0 && (prior & 32) != 0)
					color |= self->colors[1];
			}
			else
				color = self->colors[1];
		}
	}
	else if ((objects & 12) != 0) {
		if (((objects & 192) == 0 || (prior & 6) == 0) && ((objects & 48) == 0 || (prior & 1) != 0)) {
			if ((objects & 4) != 0) {
				color = self->colors[2];
				if ((objects & 8) != 0 && (prior & 32) != 0)
					color |= self->colors[3];
			}
			else
				color = self->colors[3];
		}
	}
	if ((objects & 192) != 0 && ((objects & 12) == 0 || (prior & 9) == 0) && ((objects & 3) == 0 || (prior & 4) != 0)) {
		return color | self->colors[(objects & 128) != 0 ? 7 : 6];
	}
	if ((objects & 48) != 0 && ((objects & 12) == 0 || (prior & 1) == 0) && ((objects & 3) == 0 || (prior & 3) == 0)) {
		return color | self->colors[(objects & 16) != 0 ? 4 : 5];
	}
	return color;
}

static void GtiaRenderer_StartLine(GtiaRenderer *self, int startHpos)
{
	memset(self->playerShiftRegister, 0, sizeof(self->playerShiftRegister));
	self->missileShiftRegister = 0;
	for (int hpos = startHpos - 31; hpos < startHpos; hpos++)
		GtiaRenderer_GetPmg(self, hpos, 0);
}

static int GtiaRenderer_GetHiresColor(const GtiaRenderer *self, int c)
{
	return (c & 240) + (self->colors[5] & 14);
}

static int GtiaRenderer_DrawSpan(GtiaRenderer *self, int y, int hpos, int untilHpos, AnticMode anticMode, uint8_t *frame, int width, int yOffset)
{
	int gtiaMode = self->prior >> 6;
	for (; hpos < untilHpos; hpos++) {
		int x = hpos;
		int objects = 0;
		int playfield = 0;
		if (gtiaMode == 2) {
			x--;
			objects = 1;
		}
		if (anticMode != AnticMode_BLANK) {
			int column = (x >> 2) + (self->playfieldColumns >> 1) - 32;
			if (column >= 0 && column < self->playfieldColumns) {
				playfield = self->vtbl->getPlayfieldByte(self, y, column);
				bool inverseChar = playfield >= 256;
				if (inverseChar && anticMode == AnticMode_HI_RES)
					playfield = 511 - playfield;
				if (gtiaMode == 0) {
					playfield = playfield >> ((~x & 3) << 1) & 3;
					objects = anticMode == AnticMode_HI_RES ? 64 : anticMode == AnticMode_FIVE_COLOR && playfield == 3 && inverseChar ? 128 : 8 << playfield & 112;
				}
				else {
					if ((x & 2) == 0)
						playfield >>= 4;
					playfield &= 15;
					if (gtiaMode == 2) {
						static const uint8_t GTIA10_OBJECTS[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 0, 0, 0, 0, 16, 32, 64, 128 };
						objects = GTIA10_OBJECTS[playfield];
					}
				}
			}
		}
		objects = GtiaRenderer_GetPmg(self, hpos, objects);
		int c = GtiaRenderer_GetColor(self, objects);
		int frameOffset = (yOffset + y) * width + ((hpos + (width >> 2) - 128) << 1);
		switch (gtiaMode) {
		case 0:
			if (anticMode != AnticMode_HI_RES)
				break;
			frame[frameOffset] = (uint8_t) ((playfield & 2) == 0 ? c : self->vtbl->getHiresColor(self, c));
			frame[frameOffset + 1] = (uint8_t) ((playfield & 1) == 0 ? c : self->vtbl->getHiresColor(self, c));
			continue;
		case 2:
			break;
		default:
			if ((objects & 15) != 0)
				break;
			assert(objects == 0 || objects == 128);
			if (gtiaMode == 1)
				c |= playfield;
			else if (playfield == 0)
				c &= 240;
			else
				c |= playfield << 4;
			break;
		}
		frame[frameOffset + 1] = frame[frameOffset] = (uint8_t) c;
	}
	return hpos;
}

static void GtiaRenderer_SetG2fColors(GtiaRenderer *self, int contentOffset, int contentStride, int count, int gtiaMode)
{
	static const uint8_t NORMAL_REGISTERS[9] = { 8, 4, 5, 6, 7, 0, 1, 2, 3 };
	for (int i = 0; i < count; i++)
		self->colors[(gtiaMode & 192) == 128 ? i : NORMAL_REGISTERS[i]] = (uint8_t) (self->content[contentOffset + i * contentStride] & 254);
}

static int GtiaRenderer_AdvanceCpuCycles(const GtiaRenderer *self, int hpos, int cpuCycles, bool nonBlank)
{
	for (;;) {
		hpos += 2;
		int x = (hpos - 118) >> 1;
		if ((x & 1) != 0 ? nonBlank && x >= -self->playfieldColumns && x < self->playfieldColumns : x >= -36 && x < 0 && (x & 2) != 0) {
		}
		else if (--cpuCycles == 0)
			return hpos;
	}
}

static void HcmRenderer_Construct(HcmRenderer *self)
{
	static const GtiaRendererVtbl vtbl = {
		GtiaRenderer_GetHiresColor,
		(int (*)(GtiaRenderer *self, int y, int column)) HcmRenderer_GetPlayfieldByte,
	};
	self->base.vtbl = &vtbl;
}

static int HcmRenderer_GetPlayfieldByte(HcmRenderer *self, int y, int column)
{
	return self->base.content[2064 + (y << 5) + column];
}

static void GedRenderer_Construct(GedRenderer *self)
{
	static const GtiaRendererVtbl vtbl = {
		GtiaRenderer_GetHiresColor,
		(int (*)(GtiaRenderer *self, int y, int column)) GedRenderer_GetPlayfieldByte,
	};
	self->base.vtbl = &vtbl;
}

static int GedRenderer_GetPlayfieldByte(GedRenderer *self, int y, int column)
{
	return self->base.content[3302 + y * 40 + column];
}

static void PgrRenderer_Construct(PgrRenderer *self)
{
	static const GtiaRendererVtbl vtbl = {
		GtiaRenderer_GetHiresColor,
		(int (*)(GtiaRenderer *self, int y, int column)) PgrRenderer_GetPlayfieldByte,
	};
	self->base.vtbl = &vtbl;
}

static int PgrRenderer_GetPlayfieldByte(PgrRenderer *self, int y, int column)
{
	return self->base.content[self->screenOffset + column];
}

static void MchRenderer_Construct(MchRenderer *self)
{
	static const GtiaRendererVtbl vtbl = {
		GtiaRenderer_GetHiresColor,
		(int (*)(GtiaRenderer *self, int y, int column)) MchRenderer_GetPlayfieldByte,
	};
	self->base.vtbl = &vtbl;
}

static int MchRenderer_GetPlayfieldByte(MchRenderer *self, int y, int column)
{
	int offset = ((y >> 3) * self->base.playfieldColumns + column) * 9;
	int shift = self->dliPlus && (y & 4) != 0 ? 2 : 1;
	return (self->base.content[offset] << shift & 256) | self->base.content[offset + 1 + (y & 7)];
}

static void G2fRenderer_Construct(G2fRenderer *self)
{
	static const GtiaRendererVtbl vtbl = {
		(int (*)(const GtiaRenderer *self, int c)) G2fRenderer_GetHiresColor,
		(int (*)(GtiaRenderer *self, int y, int column)) G2fRenderer_GetPlayfieldByte,
	};
	self->base.vtbl = &vtbl;
}

static int G2fRenderer_GetHiresColor(const G2fRenderer *self, int c)
{
	return self->vbxeOffset >= 0 ? self->base.colors[5] : (c & 240) + (self->base.colors[5] & 14);
}

static int G2fRenderer_GetPlayfieldByte(G2fRenderer *self, int y, int column)
{
	if (self->vbxeOffset >= 0) {
		int colorOffset = self->vbxeOffset + 3 + ((24 - (self->base.playfieldColumns >> 1) + column) * 240 + y / self->base.content[self->vbxeOffset + 2]) * 12 + 2;
		self->base.colors[4] = self->base.content[colorOffset];
		self->base.colors[5] = self->base.content[colorOffset + 2];
		self->base.colors[6] = self->base.content[colorOffset + 4];
	}
	int charOffset = (y >> 3) * self->base.playfieldColumns + column;
	int ch = self->base.content[3 + charOffset];
	int inverse = self->inverse2Offset >= 0 && (y & 4) != 0 ? self->base.content[self->inverse2Offset + charOffset] : ch;
	return (inverse & 128) << 1 | self->base.content[self->fontOffset + ((ch & 127) << 3) + (y & 7)];
}

static bool G2fRenderer_SetSprite(uint8_t *hpos, uint8_t *sizes, int i, uint8_t const *content, int spriteOffset)
{
	spriteOffset += i << 10;
	int value = content[spriteOffset + 1];
	if (value >= 128) {
		hpos[i] = 0;
		return true;
	}
	value &= 15;
	switch (value) {
	case 0:
		value = 1;
		break;
	case 1:
	case 2:
	case 4:
		break;
	default:
		return false;
	}
	sizes[i] = (uint8_t) value;
	hpos[i] = (uint8_t) (32 + content[spriteOffset]);
	return true;
}

static void RastaRenderer_Construct(RastaRenderer *self)
{
	static const GtiaRendererVtbl vtbl = {
		GtiaRenderer_GetHiresColor,
		(int (*)(GtiaRenderer *self, int y, int column)) RastaRenderer_GetPlayfieldByte,
	};
	self->base.vtbl = &vtbl;
}

static int RastaRenderer_GetPlayfieldByte(RastaRenderer *self, int y, int column)
{
	return self->base.content[y * 40 + column];
}

static void RastaStream_Construct(RastaStream *self)
{
	RastaRenderer_Construct(&self->gtia);
	for (size_t _i0 = 0; _i0 < 3; _i0++) {
		self->cpuRegisters[_i0] = 0;
	}
}

static bool RastaStream_EndLine(RastaStream *self)
{
	for (;;) {
		switch (Stream_ReadByte(&self->base)) {
		case ' ':
		case '\t':
		case '\r':
			break;
		case '\n':
			return true;
		case ';':
			return Stream_SkipUntilByte(&self->base, '\n');
		default:
			return false;
		}
	}
}

static int RastaStream_ReadCpuRegister(RastaStream *self)
{
	switch (Stream_ReadByte(&self->base)) {
	case 'a':
		return 0;
	case 'x':
		return 1;
	case 'y':
		return 2;
	default:
		return -1;
	}
}

static int RastaStream_ParseHexByte(RastaStream *self)
{
	return Stream_ParseInt(&self->base, 16, 255);
}

static int RastaStream_ReadDigit(RastaStream *self, int offset, int maxValue)
{
	int digit = Stream_ReadByte(&self->base) - '0';
	return digit >= 0 && digit <= maxValue ? offset + digit : -1;
}

static int RastaStream_ReadGtiaRegister(RastaStream *self)
{
	switch (Stream_ReadByte(&self->base)) {
	case 'C':
		if (Stream_ReadByte(&self->base) != 'O' || Stream_ReadByte(&self->base) != 'L')
			return -1;
		switch (Stream_ReadByte(&self->base)) {
		case 'B':
			return Stream_ReadByte(&self->base) == 'A' && Stream_ReadByte(&self->base) == 'K' ? 26 : -1;
		case 'O':
			return Stream_ReadByte(&self->base) == 'R' ? RastaStream_ReadDigit(self, 22, 2) : -1;
		case 'P':
			return Stream_ReadByte(&self->base) == 'M' ? RastaStream_ReadDigit(self, 18, 3) : -1;
		default:
			return -1;
		}
	case 'H':
		return Stream_Expect(&self->base, "POSP") ? RastaStream_ReadDigit(self, 0, 3) : -1;
	default:
		return -1;
	}
}

static bool RastaStream_IsLetter(int b)
{
	if (b == '_')
		return true;
	b &= ~32;
	return b >= 'A' && b <= 'Z';
}

static bool RastaStream_SkipUntilMnemonic(RastaStream *self)
{
	for (;;) {
		int b = Stream_ReadByte(&self->base);
		switch (b) {
		case -1:
			return false;
		case ';':
			if (!Stream_SkipUntilByte(&self->base, '\n'))
				return false;
			break;
		case '\r':
		case '\n':
			break;
		case '\t':
			return true;
		default:
			if (RastaStream_IsLetter(b)) {
				do
					b = Stream_ReadByte(&self->base);
				while (RastaStream_IsLetter(b) || (b >= '0' && b <= '9'));
				if (RastaStream_EndLine(self))
					break;
			}
			return false;
		}
	}
}

static int RastaStream_ExecuteUntilPoke(RastaStream *self)
{
	int cpuCycles = 4;
	while (RastaStream_SkipUntilMnemonic(self)) {
		switch (Stream_ReadByte(&self->base)) {
		case 'l':
			if (Stream_ReadByte(&self->base) != 'd')
				return -1;
			int reg = RastaStream_ReadCpuRegister(self);
			if (reg < 0 || !Stream_Expect(&self->base, " #$"))
				return -1;
			int value = RastaStream_ParseHexByte(self);
			if (value < 0 || !RastaStream_EndLine(self))
				return -1;
			self->cpuRegisters[reg] = (uint8_t) value;
			break;
		case 's':
			if (Stream_ReadByte(&self->base) != 't')
				return -1;
			self->cpuRegisterIndex = RastaStream_ReadCpuRegister(self);
			if (self->cpuRegisterIndex < 0 || Stream_ReadByte(&self->base) != ' ')
				return -1;
			self->gtiaRegisterIndex = RastaStream_ReadGtiaRegister(self);
			if (self->gtiaRegisterIndex < 0 || !RastaStream_EndLine(self))
				return -1;
			return cpuCycles;
		case 'n':
			if (Stream_ReadByte(&self->base) != 'o' || Stream_ReadByte(&self->base) != 'p' || !RastaStream_EndLine(self))
				return -1;
			break;
		default:
			self->base.contentOffset--;
			return 0;
		}
		cpuCycles += 2;
	}
	return -1;
}

static void RastaStream_Poke(RastaStream *self)
{
	GtiaRenderer_Poke(&self->gtia.base, self->gtiaRegisterIndex, self->cpuRegisters[self->cpuRegisterIndex]);
}

static bool RastaStream_ReadIni(RastaStream *self)
{
	memset(self->gtia.base.playerHpos, 0, sizeof(self->gtia.base.playerHpos));
	memset(self->gtia.base.colors, 0, sizeof(self->gtia.base.colors));
	self->base.contentOffset = 0;
	for (;;) {
		switch (RastaStream_ExecuteUntilPoke(self)) {
		case -1:
			return false;
		case 0:
			return Stream_Expect(&self->base, ":2 sta wsync") && RastaStream_EndLine(self);
		default:
			RastaStream_Poke(self);
			break;
		}
	}
}

static bool RastaStream_ReadPmg(RastaStream *self)
{
	self->base.contentOffset = 0;
	if (!RastaStream_SkipUntilMnemonic(self) || !Stream_Expect(&self->base, ".ds $100") || !RastaStream_EndLine(self))
		return false;
	bool beginLine = true;
	for (int i = 0; i < 1024; i++) {
		if (beginLine) {
			if (!RastaStream_SkipUntilMnemonic(self) || !Stream_Expect(&self->base, ".he "))
				return false;
			beginLine = false;
		}
		int b = RastaStream_ParseHexByte(self);
		if (b < 0)
			return false;
		self->players[i] = (uint8_t) b;
		if (Stream_ReadByte(&self->base) != ' ') {
			self->base.contentOffset--;
			if (!RastaStream_EndLine(self))
				return false;
			beginLine = true;
		}
	}
	return true;
}

static bool RastaStream_ExpectCmpZp(RastaStream *self)
{
	return Stream_Expect(&self->base, "cmp byt2") && RastaStream_EndLine(self);
}

static bool RastaStream_ReadRp(RastaStream *self, uint8_t const *bitmap, int height, uint8_t *frame)
{
	self->base.contentOffset = 0;
	for (int i = 0; i < 4; i++) {
		if (!RastaStream_SkipUntilMnemonic(self) || !Stream_Expect(&self->base, "nop") || !RastaStream_EndLine(self))
			return false;
	}
	if (!RastaStream_SkipUntilMnemonic(self) || !RastaStream_ExpectCmpZp(self))
		return false;
	memset(self->gtia.base.missileHpos, 0, sizeof(self->gtia.base.missileHpos));
	GtiaRenderer_SetSpriteSizes(self->gtia.base.playerSize, 255);
	GtiaRenderer_SetSpriteSizes(self->gtia.base.missileSize, 0);
	self->gtia.base.missileGraphics = 0;
	self->gtia.base.prior = 20;
	self->gtia.base.content = bitmap;
	self->gtia.base.playfieldColumns = 40;
	for (int y = 0; y < height; y++) {
		GtiaRenderer_ProcessPlayerDma(&self->gtia.base, self->players, 8 + y);
		GtiaRenderer_StartLine(&self->gtia.base, 48);
		for (int hpos = 7;;) {
			int cpuCycles = RastaStream_ExecuteUntilPoke(self);
			if (cpuCycles > 0) {
				int untilHpos = GtiaRenderer_AdvanceCpuCycles(&self->gtia.base, hpos, cpuCycles, true);
				GtiaRenderer_DrawSpan(&self->gtia.base, y, hpos >= 48 ? hpos : 48, untilHpos < 208 ? untilHpos : 208, AnticMode_FOUR_COLOR, frame, 320, 0);
				hpos = untilHpos;
				RastaStream_Poke(self);
				continue;
			}
			if (cpuCycles == 0 && RastaStream_ExpectCmpZp(self)) {
				GtiaRenderer_DrawSpan(&self->gtia.base, y, hpos >= 48 ? hpos : 48, 208, AnticMode_FOUR_COLOR, frame, 320, 0);
				break;
			}
			return false;
		}
	}
	return true;
}

static int InflateStream_ReadBit(InflateStream *self)
{
	if (self->bits <= 1) {
		if (self->base.contentOffset >= self->base.contentLength)
			return -1;
		self->bits = self->base.content[self->base.contentOffset++] | 256;
	}
	int result = self->bits & 1;
	self->bits >>= 1;
	return result;
}

static int InflateStream_ReadBits(InflateStream *self, int count)
{
	int result = 0;
	for (int rank = 0; rank < count; rank++) {
		switch (InflateStream_ReadBit(self)) {
		case -1:
			return -1;
		case 1:
			result |= 1 << rank;
			break;
		default:
			break;
		}
	}
	return result;
}

static void InflateStream_BuildHuffmanTrees(InflateStream *self)
{
	memset(self->nBitCodeCount, 0, sizeof(self->nBitCodeCount));
	for (int i = 0; i < 318; i++)
		self->nBitCodeCount[self->symbolCodeLength[i]]++;
	int offset = 0;
	for (int i = 0; i < 32; i++) {
		self->nBitCodeOffset[i] = offset;
		offset += self->nBitCodeCount[i];
	}
	for (int i = 0; i < 318; i++)
		self->codeToSymbol[self->nBitCodeOffset[self->symbolCodeLength[i]]++] = (int16_t) i;
}

static int InflateStream_FetchCode(InflateStream *self, int tree)
{
	int code = 0;
	do {
		int bit = InflateStream_ReadBit(self);
		if (bit < 0)
			return -1;
		code = (code << 1) + bit - self->nBitCodeCount[++tree];
		if (code < 0)
			return self->codeToSymbol[self->nBitCodeOffset[tree] + code];
	}
	while ((tree & 15) != 15);
	return -1;
}

static int InflateStream_Inflate(InflateStream *self, uint8_t *unpacked, int unpackedLength)
{
	int unpackedOffset = 0;
	self->bits = 0;
	int lastBlock;
	do {
		lastBlock = InflateStream_ReadBit(self);
		int count;
		switch (InflateStream_ReadBits(self, 2)) {
		case 0:
			self->bits = 0;
			count = InflateStream_ReadBits(self, 16);
			if (InflateStream_ReadBits(self, 16) != (count ^ 65535))
				return -1;
			if (count > unpackedLength - unpackedOffset)
				count = unpackedLength - unpackedOffset;
			if (!Stream_ReadBytes(&self->base, unpacked, unpackedOffset, count))
				return -1;
			unpackedOffset += count;
			if (unpackedOffset == unpackedLength)
				return unpackedOffset;
			continue;
		case 1:
			for (int i = 0; i < 144; i++)
				self->symbolCodeLength[i] = 8;
			for (int i = 144; i < 256; i++)
				self->symbolCodeLength[i] = 9;
			for (int i = 256; i < 280; i++)
				self->symbolCodeLength[i] = 7;
			for (int i = 280; i < 288; i++)
				self->symbolCodeLength[i] = 8;
			for (int i = 288; i < 318; i++)
				self->symbolCodeLength[i] = 21;
			break;
		case 2:
			;
			int primaryCodes = 257 + InflateStream_ReadBits(self, 5);
			int codes = 289 + InflateStream_ReadBits(self, 5);
			if (codes > 318)
				return -1;
			int temporaryCodes = InflateStream_ReadBits(self, 4);
			if (temporaryCodes < 0)
				return -1;
			temporaryCodes += 4;
			memset(self->symbolCodeLength, 0, sizeof(self->symbolCodeLength));
			for (int i = 0; i < temporaryCodes; i++) {
				int bits = InflateStream_ReadBits(self, 3);
				if (bits < 0)
					return -1;
				static const uint8_t TEMP_SYMBOLS[19] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2,
					14, 1, 15 };
				self->symbolCodeLength[TEMP_SYMBOLS[i]] = (uint8_t) bits;
			}
			InflateStream_BuildHuffmanTrees(self);
			int length = 0;
			count = 1;
			for (int i = 0; i < codes; i++) {
				if (--count == 0) {
					int symbol = InflateStream_FetchCode(self, 0);
					switch (symbol) {
					case -1:
						return -1;
					case 16:
						count = InflateStream_ReadBits(self, 2);
						if (count < 0)
							return -1;
						count += 3;
						break;
					case 17:
						length = 0;
						count = InflateStream_ReadBits(self, 3);
						if (count < 0)
							return -1;
						count += 3;
						break;
					case 18:
						length = 0;
						count = InflateStream_ReadBits(self, 7);
						if (count < 0)
							return -1;
						count += 11;
						break;
					default:
						length = symbol;
						count = 1;
						break;
					}
				}
				if (i == primaryCodes)
					i = 288;
				self->symbolCodeLength[i] = (uint8_t) (i < 288 ? length : 16 + length);
			}
			break;
		default:
			return -1;
		}
		InflateStream_BuildHuffmanTrees(self);
		for (;;) {
			int symbol = InflateStream_FetchCode(self, 0);
			if (symbol < 0)
				return -1;
			else if (symbol < 256)
				unpacked[unpackedOffset++] = (uint8_t) symbol;
			else if (symbol == 256)
				break;
			else {
				switch (symbol) {
				case 257:
				case 258:
				case 259:
				case 260:
				case 261:
				case 262:
				case 263:
				case 264:
					count = symbol - 254;
					break;
				case 285:
					count = 258;
					break;
				case 286:
				case 287:
					return -1;
				default:
					symbol -= 261;
					count = InflateStream_ReadBits(self, symbol >> 2);
					if (count < 0)
						return -1;
					count += ((4 + (symbol & 3)) << (symbol >> 2)) + 3;
					break;
				}
				symbol = InflateStream_FetchCode(self, 16);
				int distance;
				switch (symbol) {
				case -1:
					return -1;
				case 288:
				case 289:
				case 290:
				case 291:
					distance = symbol - 287;
					break;
				default:
					symbol -= 290;
					distance = InflateStream_ReadBits(self, symbol >> 1);
					if (distance < 0)
						return -1;
					distance += ((2 + (symbol & 1)) << (symbol >> 1)) + 1;
					break;
				}
				if (count > unpackedLength - unpackedOffset)
					count = unpackedLength - unpackedOffset;
				if (!RECOIL_CopyPrevious(unpacked, unpackedOffset, distance, count))
					return -1;
				unpackedOffset += count;
			}
			if (unpackedOffset == unpackedLength)
				return unpackedOffset;
		}
	}
	while (lastBlock == 0);
	return unpackedOffset;
}

static int InflateStream_Uncompress(InflateStream *self, uint8_t *unpacked, int unpackedLength)
{
	int b0 = Stream_ReadByte(&self->base);
	if ((b0 & 143) != 8)
		return -1;
	int b1 = Stream_ReadByte(&self->base);
	if ((b1 & 32) != 0 || (b0 << 8 | b1) % 31 != 0)
		return -1;
	return InflateStream_Inflate(self, unpacked, unpackedLength);
}

static void RECOIL_Construct(RECOIL *self)
{
	static const RECOILVtbl vtbl = {
		RECOIL_ReadFile,
	};
	self->vtbl = &vtbl;
	self->pixels = NULL;
	self->pixelsLength = 0;
	self->colorInUse = NULL;
	self->indexes = NULL;
	self->indexesLength = 0;
	RECOIL_SetNtsc(self, false);
}

static void RECOIL_Destruct(RECOIL *self)
{
	free(self->indexes);
	free(self->colorInUse);
	free(self->pixels);
}

RECOIL *RECOIL_New(void)
{
	RECOIL *self = (RECOIL *) malloc(sizeof(RECOIL));
	if (self != NULL)
		RECOIL_Construct(self);
	return self;
}

void RECOIL_Delete(RECOIL *self)
{
	if (self == NULL)
		return;
	RECOIL_Destruct(self);
	free(self);
}

void RECOIL_SetNtsc(RECOIL *self, bool ntsc)
{
	self->ntsc = ntsc;
	self->c64Palette[0] = 0;
	self->c64Palette[1] = 16777215;
	self->c64Palette[2] = 6829867;
	self->c64Palette[3] = 7382194;
	self->c64Palette[4] = 7290246;
	self->c64Palette[5] = 5803331;
	self->c64Palette[6] = 3483769;
	self->c64Palette[7] = 12109679;
	self->c64Palette[8] = 7294757;
	self->c64Palette[9] = 4405504;
	self->c64Palette[10] = 10119001;
	self->c64Palette[11] = 4473924;
	self->c64Palette[12] = 7105644;
	self->c64Palette[13] = 10146436;
	self->c64Palette[14] = 7102133;
	self->c64Palette[15] = 9803157;
	RECOIL_DecodeR8G8B8Colors(FuResource_c16_pal, 0, 128, self->c16Palette, 0);
	RECOIL_DecodeR8G8B8Colors(self->ntsc ? FuResource_altirrantsc_pal : FuResource_altirrapal_pal, 0, 256, self->atari8Palette, 0);
}

bool RECOIL_IsNtsc(const RECOIL *self)
{
	return self->ntsc;
}

static int RECOIL_GetPackedExt(const char *filename)
{
	int ext = 0;
	for (ptrdiff_t i = (ptrdiff_t) strlen(filename); --i >= 0;) {
		int c = filename[i];
		if (c == '.')
			return ext | 538976288;
		if (c <= ' ' || c > 'z' || ext >= 16777216)
			return 0;
		ext = (ext << 8) + c;
	}
	return 0;
}

bool RECOIL_SetPlatformPalette(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	switch (RECOIL_GetPackedExt(filename)) {
	case 544498529:
	case 543973744:
		if (contentLength != 768)
			return false;
		RECOIL_DecodeR8G8B8Colors(content, 0, 256, self->atari8Palette, 0);
		return true;
	case 543977590:
		;
		VplStream vpl;
		vpl.base.content = content;
		vpl.base.contentOffset = 0;
		vpl.base.contentLength = contentLength;
		switch (VplStream_Decode(&vpl)) {
		case 16:
			VplStream_CopyTo(&vpl, self->c64Palette, 16);
			return true;
		case 128:
			VplStream_CopyTo(&vpl, self->c16Palette, 128);
			return true;
		default:
			return false;
		}
	default:
		return false;
	}
}

static bool RECOIL_SetSize(RECOIL *self, int width, int height, RECOILResolution resolution, int frames)
{
	if (width <= 0 || height <= 0 || height > 134217728 / width / frames)
		return false;
	self->width = width;
	self->height = height;
	self->resolution = resolution;
	self->frames = frames;
	self->colors = -1;
	self->leftSkip = 0;
	int pixelsLength = width * height * frames;
	if (self->pixelsLength < pixelsLength) {
		free(self->pixels);
		self->pixels = (int *) malloc(pixelsLength * sizeof(int));
		self->pixelsLength = pixelsLength;
	}
	return true;
}

static bool RECOIL_SetSizeStOrFalcon(RECOIL *self, int width, int height, int bitplanes, bool squarePixels)
{
	RECOILResolution resolution = RECOILResolution_FALCON1X1;
	switch (bitplanes) {
	case 1:
		if (width <= 640 && height <= 400)
			resolution = RECOILResolution_ST1X1;
		break;
	case 2:
		if (!squarePixels && width == 640 && height == 200) {
			height <<= 1;
			resolution = RECOILResolution_STE1X2;
		}
		break;
	case 4:
		if (width <= 320 && height <= 200)
			resolution = RECOILResolution_STE1X1;
		break;
	case 8:
		if (!squarePixels && width == 320 && height == 480) {
			width <<= 1;
			resolution = RECOILResolution_TT2X1;
		}
		break;
	default:
		break;
	}
	return RECOIL_SetSize(self, width, height, resolution, 1);
}

static bool RECOIL_SetScaledSize(RECOIL *self, int width, int height, RECOILResolution resolution)
{
	switch (resolution) {
	case RECOILResolution_AMIGA2X1:
	case RECOILResolution_FALCON2X1:
	case RECOILResolution_MSX22X1I:
	case RECOILResolution_MSX2_PLUS2X1I:
		width <<= 1;
		break;
	case RECOILResolution_AMIGA4X1:
		width <<= 2;
		break;
	case RECOILResolution_AMIGA8X1:
		width <<= 3;
		break;
	case RECOILResolution_AMIGA1X2:
	case RECOILResolution_AMIGA_DCTV1X2:
	case RECOILResolution_ST1X2:
	case RECOILResolution_STE1X2:
	case RECOILResolution_MSX21X2:
	case RECOILResolution_PC801X2:
	case RECOILResolution_PC881X2:
		height <<= 1;
		break;
	case RECOILResolution_AMIGA1X4:
		height <<= 2;
		break;
	default:
		break;
	}
	return RECOIL_SetSize(self, width, height, resolution, 1);
}

static void RECOIL_SetScaledPixel(RECOIL *self, int x, int y, int rgb)
{
	int offset = y * self->width;
	switch (self->resolution) {
	case RECOILResolution_AMIGA2X1:
	case RECOILResolution_AMIGA_HAME2X1:
	case RECOILResolution_AMSTRAD2X1:
	case RECOILResolution_TT2X1:
	case RECOILResolution_FALCON2X1:
	case RECOILResolution_BBC2X1:
	case RECOILResolution_MSX22X1I:
	case RECOILResolution_MSX2_PLUS2X1I:
	case RECOILResolution_SAM_COUPE2X1I:
		offset += x << 1;
		self->pixels[offset + 1] = self->pixels[offset] = rgb;
		break;
	case RECOILResolution_AMIGA4X1:
		offset += x << 2;
		self->pixels[offset + 3] = self->pixels[offset + 2] = self->pixels[offset + 1] = self->pixels[offset] = rgb;
		break;
	case RECOILResolution_AMIGA8X1:
		offset += x << 3;
		for (x = 0; x < 8; x++)
			self->pixels[offset + x] = rgb;
		break;
	case RECOILResolution_AMIGA1X2:
	case RECOILResolution_AMIGA_DCTV1X2:
	case RECOILResolution_APPLE_I_I_G_S1X2:
	case RECOILResolution_ST1X2:
	case RECOILResolution_STE1X2:
	case RECOILResolution_MC05151X2:
	case RECOILResolution_PC801X2:
	case RECOILResolution_PC881X2:
	case RECOILResolution_MSX21X2:
	case RECOILResolution_SAM_COUPE1X2:
	case RECOILResolution_TRS1X2:
		offset = (offset << 1) + x;
		self->pixels[offset + self->width] = self->pixels[offset] = rgb;
		break;
	case RECOILResolution_AMIGA1X4:
		offset = (offset << 2) + x;
		self->pixels[offset + self->width * 3] = self->pixels[offset + self->width * 2] = self->pixels[offset + self->width] = self->pixels[offset] = rgb;
		break;
	default:
		self->pixels[offset + x] = rgb;
		break;
	}
}

static int RECOIL_Get32BigEndian(uint8_t const *content, int contentOffset)
{
	return content[contentOffset] << 24 | content[contentOffset + 1] << 16 | content[contentOffset + 2] << 8 | content[contentOffset + 3];
}

static int RECOIL_Get32LittleEndian(uint8_t const *content, int contentOffset)
{
	return content[contentOffset] | content[contentOffset + 1] << 8 | content[contentOffset + 2] << 16 | content[contentOffset + 3] << 24;
}

static int RECOIL_GetNibble(uint8_t const *content, int contentOffset, int index)
{
	int b = content[contentOffset + (index >> 1)];
	return (index & 1) == 0 ? b >> 4 : b & 15;
}

static bool RECOIL_IsStringAt(uint8_t const *content, int contentOffset, const char *s)
{
	for (const char *c = s; *c != '\0'; c++)
		if (content[contentOffset++] != *c)
			return false;
	return true;
}

static bool RECOIL_CopyPrevious(uint8_t *unpacked, int unpackedOffset, int distance, int count)
{
	if (distance > unpackedOffset)
		return false;
	do {
		unpacked[unpackedOffset] = unpacked[unpackedOffset - distance];
		unpackedOffset++;
	}
	while (--count > 0);
	return true;
}

static bool RECOIL_ApplyBlend(RECOIL *self)
{
	int pixelsLength = self->width * self->height;
	for (int i = 0; i < pixelsLength; i++) {
		int rgb1 = self->pixels[i];
		int rgb2 = self->pixels[pixelsLength + i];
		self->pixels[i] = (rgb1 & rgb2) + ((rgb1 ^ rgb2) >> 1 & 8355711);
	}
	return true;
}

static int RECOIL_ReadFile(const RECOIL *self, const char *filename, uint8_t *content, int contentLength)
{
	return -1;
}

static int RECOIL_ReadCompanionFile(const RECOIL *self, const char *baseFilename, const char *upperExt, const char *lowerExt, uint8_t *content, int contentLength)
{
	ptrdiff_t i = (ptrdiff_t) strlen(baseFilename);
	bool lower = false;
	for (;;) {
		int c = baseFilename[--i];
		if (c >= 'a')
			lower = true;
		else if (c == '.')
			break;
	}
	char *filename = FuString_Substring(baseFilename, i + 1);
	FuString_Append(&filename, lower ? lowerExt : upperExt);
	int returnValue = self->vtbl->readFile(self, filename, content, contentLength);
	free(filename);
	return returnValue;
}

static int RECOIL_ReadSiblingFile(const RECOIL *self, const char *baseFilename, const char *newFilename, uint8_t *content, int contentLength)
{
	ptrdiff_t i = (ptrdiff_t) strlen(baseFilename);
	while (i > 0 && baseFilename[i - 1] != '/' && baseFilename[i - 1] != '\\')
		i--;
	char *filename = FuString_Substring(baseFilename, i);
	FuString_Append(&filename, newFilename);
	int returnValue = self->vtbl->readFile(self, filename, content, contentLength);
	free(filename);
	return returnValue;
}

static bool RECOIL_DecodeBru(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 64)
		return false;
	RECOIL_SetSize(self, 8, 8, RECOILResolution_ST1X1, 1);
	for (int i = 0; i < 64; i++) {
		switch (content[i]) {
		case 0:
			self->pixels[i] = 0;
			break;
		case 1:
			self->pixels[i] = 16777215;
			break;
		default:
			return false;
		}
	}
	return true;
}

static void RECOIL_SetGrayscalePalette(RECOIL *self, int inverse)
{
	for (int c = 0; c < 256; c++)
		self->contentPalette[c] = (c ^ inverse) * 65793;
}

static void RECOIL_DecodeBytes(RECOIL *self, uint8_t const *content, int contentOffset)
{
	int width = RECOIL_GetOriginalWidth(self);
	int height = RECOIL_GetOriginalHeight(self);
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			RECOIL_SetScaledPixel(self, x, y, self->contentPalette[content[contentOffset + y * width + x]]);
}

static void RECOIL_DecodeNibbles(RECOIL *self, uint8_t const *content, int contentOffset, int contentStride)
{
	int width = RECOIL_GetOriginalWidth(self);
	int height = RECOIL_GetOriginalHeight(self);
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			RECOIL_SetScaledPixel(self, x, y, self->contentPalette[RECOIL_GetNibble(content, contentOffset + y * contentStride, x)]);
}

static int RECOIL_GetR8G8B8Color(uint8_t const *content, int contentOffset)
{
	return content[contentOffset] << 16 | content[contentOffset + 1] << 8 | content[contentOffset + 2];
}

static void RECOIL_DecodeR8G8B8Colors(uint8_t const *content, int contentOffset, int count, int *destination, int destinationOffset)
{
	for (int i = 0; i < count; i++)
		destination[destinationOffset + i] = RECOIL_GetR8G8B8Color(content, contentOffset + i * 3);
}

static int RECOIL_GetB5G5R5Color(int c)
{
	c = (c & 31) << 19 | (c & 992) << 6 | (c >> 7 & 248);
	return c | (c >> 5 & 460551);
}

static int RECOIL_GetR5G5B5Color(int c)
{
	c = (c & 31744) << 9 | (c & 992) << 6 | (c & 31) << 3;
	return c | (c >> 5 & 460551);
}

static int RECOIL_GetG6R5B5Color(int c)
{
	c = (c & 992) << 14 | (c & 64512) | (c & 31) << 3;
	return c | (c >> 5 & 458759) | (c >> 6 & 768);
}

static int RECOIL_Get729Color(int c)
{
	int r = c / 81;
	int g = c / 9 % 9;
	int b = c % 9;
	return r * 255 >> 3 << 16 | g * 255 >> 3 << 8 | b * 255 >> 3;
}

static int RECOIL_GetFalconTrueColor(uint8_t const *content, int contentOffset)
{
	int rg = content[contentOffset];
	int gb = content[contentOffset + 1];
	int rgb = (rg & 248) << 16 | (rg & 7) << 13 | (gb & 224) << 5 | (gb & 31) << 3;
	rgb |= (rgb >> 5 & 458759) | (rgb >> 6 & 768);
	return rgb;
}

static int RECOIL_GetBitplanePixel(uint8_t const *content, int contentOffset, int x, int bitplanes, int bytesPerBitplane)
{
	int bit = ~x & 7;
	int c = 0;
	for (int bitplane = bitplanes; --bitplane >= 0;)
		c = c << 1 | (content[contentOffset + bitplane * bytesPerBitplane] >> bit & 1);
	return c;
}

static bool RECOIL_DecodeAmigaPlanar(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height, RECOILResolution resolution, int bitplanes, int const *palette)
{
	if (!RECOIL_SetScaledSize(self, width, height, resolution))
		return false;
	int bytesPerLine = (width + 15) >> 4 << 1;
	int bitplaneLength = height * bytesPerLine;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int c = RECOIL_GetBitplanePixel(content, contentOffset + y * bytesPerLine + (x >> 3), x, bitplanes, bitplaneLength);
			RECOIL_SetScaledPixel(self, x, y, palette[c]);
		}
	}
	return true;
}

static int RECOIL_GetBitplaneWordsPixel(uint8_t const *content, int contentOffset, int x, int bitplanes)
{
	return RECOIL_GetBitplanePixel(content, contentOffset + (x >> 3 & ~1) * bitplanes + (x >> 3 & 1), x, bitplanes, 2);
}

static void RECOIL_DecodeBitplanes(RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, int bitplanes, int pixelsOffset, int width, int height)
{
	while (--height >= 0) {
		for (int x = 0; x < width; x++) {
			int c = RECOIL_GetBitplaneWordsPixel(content, contentOffset, x, bitplanes);
			self->pixels[pixelsOffset + x] = self->contentPalette[c];
		}
		contentOffset += contentStride;
		pixelsOffset += self->width;
	}
}

static void RECOIL_DecodeScaledBitplanes(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height, int bitplanes, bool ehb, MultiPalette *multiPalette)
{
	int contentStride = ((width + 15) >> 4 << 1) * bitplanes;
	for (int y = 0; y < height; y++) {
		if (multiPalette != NULL)
			((const MultiPaletteVtbl *) multiPalette->base.vtbl)->setLinePalette(multiPalette, self, y);
		if (ehb) {
			for (int c = 0; c < 32; c++)
				self->contentPalette[32 + c] = self->contentPalette[c] >> 1 & 8355711;
		}
		for (int x = 0; x < width; x++) {
			int c = RECOIL_GetBitplaneWordsPixel(content, contentOffset, x, bitplanes);
			RECOIL_SetScaledPixel(self, x, y, self->contentPalette[c]);
		}
		contentOffset += contentStride;
	}
}

static bool RECOIL_DecodeMono(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, bool wordAlign)
{
	int contentStride = (self->width + 7) >> 3;
	if (wordAlign)
		contentStride += contentStride & 1;
	if (contentLength != contentOffset + contentStride * self->height)
		return false;
	RECOIL_DecodeBitplanes(self, content, contentOffset, contentStride, 1, 0, self->width, self->height);
	return true;
}

static bool RECOIL_DecodeBlackAndWhite(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, bool wordAlign, int backgroundColor)
{
	self->contentPalette[0] = backgroundColor;
	self->contentPalette[1] = backgroundColor ^ 16777215;
	return RECOIL_DecodeMono(self, content, contentOffset, contentLength, wordAlign);
}

static bool RECOIL_DecodeRleBlackAndWhite(RECOIL *self, RleStream *rle, int backgroundColor)
{
	int width = RECOIL_GetOriginalWidth(self);
	int height = RECOIL_GetOriginalHeight(self);
	for (int y = 0; y < height; y++) {
		int b = 0;
		for (int x = 0; x < width; x++) {
			if ((x & 7) == 0) {
				b = RleStream_ReadRle(rle);
				if (b < 0)
					return false;
			}
			RECOIL_SetScaledPixel(self, x, y, (b >> (~x & 7) & 1) == 0 ? backgroundColor : backgroundColor ^ 16777215);
		}
	}
	return true;
}

static void RECOIL_DecodeBlackAndWhiteFont(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int fontHeight)
{
	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < 256; x++) {
			int row = y % fontHeight;
			int offset = contentOffset + ((y - row) << 5) + (x >> 3) * fontHeight + row;
			int c;
			if (offset < contentLength) {
				c = content[offset] >> (~x & 7) & 1;
				if (c != 0)
					c = 16777215;
			}
			else
				c = 0;
			self->pixels[(y << 8) + x] = c;
		}
	}
}

static bool RECOIL_DecodePgf(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 240, 64, RECOILResolution_PORTFOLIO1X1, 1);
	return RECOIL_DecodeBlackAndWhite(self, content, 0, contentLength, false, 16777215);
}

static bool RECOIL_DecodePgc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 33 || content[0] != 'P' || content[1] != 'G' || content[2] != 1)
		return false;
	RECOIL_SetSize(self, 240, 64, RECOILResolution_PORTFOLIO1X1, 1);
	PgcStream rle;
	PgcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 16777215);
}

static bool RECOIL_DecodePsion3Pic(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 22 || content[0] != 'P' || content[1] != 'I' || content[2] != 'C' || content[3] != 220 || content[4] != '0' || content[5] != '0' || (content[6] == 0 && content[7] == 0))
		return false;
	int width = content[10] | content[11] << 8;
	int height = content[12] | content[13] << 8;
	int bitmapLength = content[14] | content[15] << 8;
	int stride = (width + 15) >> 4 << 1;
	if (bitmapLength != height * stride)
		return false;
	int bitmapOffset = 20 + RECOIL_Get32LittleEndian(content, 16);
	if (bitmapOffset < 20 || contentLength < bitmapOffset + bitmapLength)
		return false;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_PSION31X1, 1))
		return false;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			self->pixels[y * width + x] = (content[bitmapOffset + (x >> 3)] >> (x & 7) & 1) == 0 ? 16777215 : 0;
		}
		bitmapOffset += stride;
	}
	return true;
}

static bool RECOIL_DecodeGrb(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 19)
		return false;
	if (RECOIL_IsStringAt(content, 0, "HPHP48-") && content[8] == 30 && content[9] == 43 && (content[10] & 15) == 0) {
		int nibbles = content[10] >> 4 | content[11] << 4 | content[12] << 12;
		int height = content[13] | content[14] << 8 | (content[15] & 15) << 16;
		int width = content[15] >> 4 | content[16] << 4 | content[17] << 12;
		int bytesPerLine = (width + 7) >> 3;
		if (nibbles != (contentLength << 1) - 21 || contentLength != 18 + height * bytesPerLine || !RECOIL_SetSize(self, width, height, RECOILResolution_HP481X1, 1))
			return false;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++)
				self->pixels[y * width + x] = (content[18 + y * bytesPerLine + (x >> 3)] >> (x & 7) & 1) == 0 ? 16777215 : 0;
		}
		return true;
	}
	if (contentLength >= 31 && RECOIL_IsStringAt(content, 0, "%%HP: T(0)A(D)F(.);\rGROB ")) {
		Stream s;
		s.content = content;
		s.contentOffset = 25;
		s.contentLength = contentLength;
		int width = Stream_ParseInt(&s, 10, 65535);
		if (width <= 0 || Stream_ReadByte(&s) != ' ')
			return false;
		int height = Stream_ParseInt(&s, 10, 65535);
		if (height <= 0 || Stream_ReadByte(&s) != '\r' || !RECOIL_SetSize(self, width, height, RECOILResolution_HP481X1, 1))
			return false;
		int b = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int bit = x & 7;
				if (bit == 0) {
					b = Stream_ReadHexByte(&s);
					if (b < 0)
						return false;
				}
				self->pixels[y * width + x] = (b >> (bit ^ 4) & 1) == 0 ? 16777215 : 0;
			}
		}
		return true;
	}
	return false;
}

static bool RECOIL_DecodeTrsHr(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 19200:
	case 19328:
	case 19456:
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 640, 480, RECOILResolution_TRS1X2, 1);
	for (int y = 0; y < 240; y++) {
		for (int x = 0; x < 640; x++) {
			int c = content[y * 80 + (x >> 3)] >> (~x & 7) & 1;
			if (c != 0)
				c = 16777215;
			int pixelsOffset = y * 1280 + x;
			self->pixels[pixelsOffset + 640] = self->pixels[pixelsOffset] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeTrsShr(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 640, 480, RECOILResolution_TRS1X2, 1);
	PgcStream rle;
	PgcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 0);
}

static bool RECOIL_DecodeRle(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 520 || content[0] != 27 || content[1] != 71 || content[2] != 72)
		return false;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_TRS1X1, 1);
	int count = 0;
	int contentOffset = 3;
	int c = 16777215;
	for (int pixelsOffset = 0; pixelsOffset < 49152; pixelsOffset++) {
		while (count == 0) {
			if (contentOffset >= contentLength)
				return false;
			count = content[contentOffset++];
			if (count < 32 || count > 127) {
				if (pixelsOffset == 49151) {
					self->pixels[pixelsOffset] = c;
					return true;
				}
				return false;
			}
			c ^= 16777215;
			count -= 32;
		}
		self->pixels[pixelsOffset] = c;
		count--;
	}
	return true;
}

static bool RECOIL_DecodeCocoClp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 306 || content[305] != 100)
		return false;
	for (int i = 0; i < 25; i++) {
		static const uint8_t HEADER[25] = { 0, 0, 0, 3, 1, 94, 0, 0, 32, 0, 32, 1, 1, 44, 0, 10,
			0, 56, 0, 32, 0, 56, 0, 32, 5 };
		if (content[i] != HEADER[i])
			return false;
	}
	RECOIL_SetSize(self, 40, 56, RECOILResolution_COCO1X1, 1);
	return RECOIL_DecodeBlackAndWhite(self, content, 25, 305, false, 16777215);
}

static bool RECOIL_DecodeCocoMax(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 6154:
	case 6155:
	case 6272:
	case 7168:
		break;
	default:
		return false;
	}
	if (content[0] != 0 || content[1] != 24 || content[2] > 1 || content[3] != 14 || content[4] != 0)
		return false;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_COCO1X1, 1);
	return RECOIL_DecodeBlackAndWhite(self, content, 5, 6149, false, 0);
}

static bool RECOIL_DecodeP11(RECOIL *self, uint8_t const *content, int contentLength)
{
	if ((contentLength != 3083 && contentLength != 3243) || content[0] != 0 || content[1] != 12 || content[3] != 14 || content[4] != 0)
		return false;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_COCO2X2, 1);
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 256; x++) {
			static const int PALETTE[4] = { 524032, 16776960, 3868927, 13369403 };
			int c = content[5 + ((y & ~1) << 4) + (x >> 3)] >> (~x & 6) & 3;
			self->pixels[(y << 8) + x] = PALETTE[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeMac(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 512)
		return false;
	int contentOffset = RECOIL_IsStringAt(content, 65, "PNTG") ? 128 : 0;
	if (content[contentOffset] != 0 || content[contentOffset + 1] != 0 || content[contentOffset + 2] != 0 || content[contentOffset + 3] > 3)
		return false;
	RECOIL_SetSize(self, 576, 720, RECOILResolution_MACINTOSH1X1, 1);
	PackBitsStream rle;
	PackBitsStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset + 512;
	rle.base.base.base.contentLength = contentLength;
	return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 16777215);
}

static void RECOIL_DecodePlayStation(uint8_t const *content, int contentOffset, int *pixels, int pixelsLength)
{
	for (int i = 0; i < pixelsLength; i++)
		pixels[i] = RECOIL_GetB5G5R5Color(content[contentOffset + (i << 1)] | content[contentOffset + (i << 1) + 1] << 8);
}

static int RECOIL_DecodeTimPalette(RECOIL *self, uint8_t const *content, int contentLength, int colors)
{
	if ((content[16] | content[17] << 8) != colors)
		return -1;
	int paletteCount = content[18] | content[19] << 8;
	if (paletteCount == 0)
		return -1;
	int bitmapOffset = 20 + (paletteCount * colors << 1);
	if (RECOIL_Get32LittleEndian(content, 8) != bitmapOffset - 8 || contentLength < bitmapOffset + 12)
		return -1;
	int width = (content[bitmapOffset + 8] | content[bitmapOffset + 9] << 8) << 1;
	int height = content[bitmapOffset + 10] | content[bitmapOffset + 11] << 8;
	if (contentLength < bitmapOffset + 12 + width * height)
		return -1;
	if (colors == 16)
		width <<= 1;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_PLAY_STATION1X1, 1))
		return -1;
	RECOIL_DecodePlayStation(content, 20, self->contentPalette, colors);
	return bitmapOffset + 12;
}

static bool RECOIL_DecodeTim(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 20 || RECOIL_Get32LittleEndian(content, 0) != 16)
		return false;
	int width;
	int height;
	int pixelsLength;
	int bitmapOffset;
	switch (content[4] & 15) {
	case 2:
		width = content[16] | content[17] << 8;
		height = content[18] | content[19] << 8;
		pixelsLength = width * height;
		if (contentLength < 20 + (pixelsLength << 1) || !RECOIL_SetSize(self, width, height, RECOILResolution_PLAY_STATION1X1, 1))
			return false;
		RECOIL_DecodePlayStation(content, 20, self->pixels, pixelsLength);
		return true;
	case 3:
		width = (content[16] | content[17] << 8) * 2 / 3;
		height = content[18] | content[19] << 8;
		pixelsLength = width * height;
		if (contentLength != 20 + pixelsLength * 3 || !RECOIL_SetSize(self, width, height, RECOILResolution_PLAY_STATION1X1, 1))
			return false;
		RECOIL_DecodeR8G8B8Colors(content, 20, pixelsLength, self->pixels, 0);
		return true;
	case 8:
		bitmapOffset = RECOIL_DecodeTimPalette(self, content, contentLength, 16);
		if (bitmapOffset < 0)
			return false;
		pixelsLength = self->width * self->height;
		for (int i = 0; i < pixelsLength; i++) {
			int b = content[bitmapOffset + (i >> 1)];
			self->pixels[i] = self->contentPalette[(i & 1) == 0 ? b & 15 : b >> 4];
		}
		return true;
	case 9:
		bitmapOffset = RECOIL_DecodeTimPalette(self, content, contentLength, 256);
		if (bitmapOffset < 0)
			return false;
		RECOIL_DecodeBytes(self, content, bitmapOffset);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeBb0(RECOIL *self, uint8_t const *content, int contentLength, int const *palette)
{
	if (contentLength != 20480)
		return false;
	RECOIL_SetSize(self, 640, 512, RECOILResolution_BBC1X2, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 640; x++) {
			int c = content[(y & ~7) * 80 + (x & ~7) + (y & 7)] >> (~x & 7) & 1;
			int pixelsOffset = y * 1280 + x;
			self->pixels[pixelsOffset + 640] = self->pixels[pixelsOffset] = palette[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeBb1(RECOIL *self, uint8_t const *content, int contentLength, int const *palette)
{
	if (contentLength != 20480)
		return false;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC1X1, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 320; x++) {
			int c = content[(y & ~7) * 80 + ((x & ~3) << 1) + (y & 7)] >> (~x & 3);
			self->pixels[y * 320 + x] = palette[(c >> 3 & 2) + (c & 1)];
		}
	}
	return true;
}

static bool RECOIL_DecodeBb2(RECOIL *self, uint8_t const *content, int contentLength, int const *palette)
{
	if (contentLength != 20480)
		return false;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC2X1, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 160; x++) {
			int c = content[(y & ~7) * 80 + ((x & ~1) << 2) + (y & 7)] >> (~x & 1);
			int pixelsOffset = (y * 160 + x) << 1;
			self->pixels[pixelsOffset + 1] = self->pixels[pixelsOffset] = palette[(c >> 3 & 8) + (c >> 2 & 4) + (c >> 1 & 2) + (c & 1)];
		}
	}
	return true;
}

static bool RECOIL_DecodeBb4(RECOIL *self, uint8_t const *content, int contentLength, int const *palette)
{
	if (contentLength != 10240)
		return false;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC1X1, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 320; x++) {
			int c = content[(y & ~7) * 40 + (x & ~7) + (y & 7)] >> (~x & 7) & 1;
			self->pixels[y * 320 + x] = palette[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeBb5(RECOIL *self, uint8_t const *content, int contentLength, int const *palette)
{
	if (contentLength != 10240)
		return false;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC2X1, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 160; x++) {
			int c = content[(y & ~7) * 40 + ((x & ~3) << 1) + (y & 7)] >> (~x & 3);
			int pixelsOffset = (y * 160 + x) << 1;
			self->pixels[pixelsOffset + 1] = self->pixels[pixelsOffset] = palette[(c >> 3 & 2) + (c & 1)];
		}
	}
	return true;
}

static bool RECOIL_DecodeBbg(RECOIL *self, uint8_t const *content, int contentLength)
{
	BbgStream rle;
	BbgStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	rle.valueBits = BbgStream_ReadBitsReverse(&rle, 8);
	if (rle.valueBits < 1 || rle.valueBits > 8)
		return false;
	int mode = BbgStream_ReadBitsReverse(&rle, 8);
	int unpackedLength;
	switch (mode) {
	case 0:
	case 1:
	case 2:
		unpackedLength = 20480;
		break;
	case 4:
	case 5:
		unpackedLength = 10240;
		break;
	default:
		return false;
	}
	for (int i = 15; i >= 0; i--) {
		int c = BbgStream_ReadBitsReverse(&rle, 4);
		if (c < 0)
			return false;
		self->contentPalette[i] = RECOIL_BBC_PALETTE[c];
	}
	int unpackedStep = BbgStream_ReadBitsReverse(&rle, 8);
	if (unpackedStep <= 0)
		return false;
	rle.countBits = BbgStream_ReadBitsReverse(&rle, 8);
	if (rle.countBits < 1 || rle.countBits > 8)
		return false;
	uint8_t unpacked[20480];
	for (int x = unpackedStep - 1; x >= 0; x--) {
		if (!RleStream_Unpack(&rle.base, unpacked, x, unpackedStep, unpackedLength))
			return false;
	}
	switch (mode) {
	case 0:
		return RECOIL_DecodeBb0(self, unpacked, unpackedLength, self->contentPalette);
	case 1:
		return RECOIL_DecodeBb1(self, unpacked, unpackedLength, self->contentPalette);
	case 2:
		return RECOIL_DecodeBb2(self, unpacked, unpackedLength, self->contentPalette);
	case 4:
		return RECOIL_DecodeBb4(self, unpacked, unpackedLength, self->contentPalette);
	case 5:
		return RECOIL_DecodeBb5(self, unpacked, unpackedLength, self->contentPalette);
	default:
		return false;
	}
}

static int RECOIL_GetOricHeader(uint8_t const *content, int contentLength)
{
	if (contentLength < 26 || content[0] != 22 || content[1] != 22 || content[2] != 22 || content[3] != 36 || content[4] != 0 || content[5] != 0 || content[6] != 128 || content[7] != 0 || content[12] != 0)
		return 0;
	int contentOffset = 13;
	while (content[contentOffset++] != 0) {
		if (contentOffset >= 26)
			return 0;
	}
	return contentOffset;
}

static bool RECOIL_DecodeChs(RECOIL *self, uint8_t const *content, int contentLength)
{
	int contentOffset = RECOIL_GetOricHeader(content, contentLength);
	switch (contentLength - contentOffset) {
	case 768:
	case 769:
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 256, 24, RECOILResolution_ORIC1X1, 1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, contentOffset, contentLength, 8);
	return true;
}

static bool RECOIL_DecodeHrs(RECOIL *self, uint8_t const *content, int contentLength)
{
	int contentOffset = RECOIL_GetOricHeader(content, contentLength);
	if (contentOffset + 8000 != contentLength)
		return false;
	RECOIL_SetSize(self, 240, 200, RECOILResolution_ORIC1X1, 1);
	for (int y = 0; y < 200; y++) {
		int paper = 0;
		int ink = 7;
		for (int col = 0; col < 40; col++) {
			int offset = y * 40 + col;
			int b = content[contentOffset + offset];
			int inverse = b >= 128 ? 7 : 0;
			switch (b & 120) {
			case 0:
				ink = b & 7;
				b = 0;
				break;
			case 8:
			case 24:
				b = 0;
				break;
			case 16:
				paper = b & 7;
				b = 0;
				break;
			default:
				break;
			}
			for (int x = 0; x < 6; x++)
				self->pixels[offset * 6 + x] = RECOIL_BBC_PALETTE[((b >> (5 - x) & 1) == 0 ? paper : ink) ^ inverse];
		}
	}
	return true;
}

static int RECOIL_GetAmstradHeader(uint8_t const *content, int contentLength)
{
	if (contentLength < 128 || (content[24] | content[25] << 8) != contentLength - 128 || content[64] != content[24] || content[65] != content[25] || content[66] != 0)
		return 0;
	int sum = 0;
	for (int i = 0; i < 67; i++)
		sum += content[i];
	if ((content[67] | content[68] << 8) != sum)
		return 0;
	return 128;
}

static bool RECOIL_DecodeAmstradFnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	if (contentLength != contentOffset + 768 && (contentLength != 896 || contentOffset != 0))
		return false;
	RECOIL_SetSize(self, 256, 24, RECOILResolution_AMSTRAD1X1, 1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, contentOffset, contentLength, 8);
	return true;
}

static bool RECOIL_DecodeAmstradMode2(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height)
{
	RECOIL_SetSize(self, width, height << 1, RECOILResolution_AMSTRAD1X2, 1);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int offset = (y * width << 1) + x;
			int c = content[contentOffset + ((y & 7) << 11) + (((y >> 3) * width + x) >> 3)] >> (~x & 7) & 1;
			self->pixels[offset + width] = self->pixels[offset] = self->contentPalette[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeHgb(RECOIL *self, uint8_t const *content, int contentLength)
{
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	if (contentLength != contentOffset + 16384)
		return false;
	self->contentPalette[0] = 0;
	self->contentPalette[1] = 16777215;
	return RECOIL_DecodeAmstradMode2(self, content, contentOffset, 512, 256);
}

static int RECOIL_SetAmstradPalette(RECOIL *self, const char *filename)
{
	uint8_t pal[368];
	int palLength = RECOIL_ReadCompanionFile(self, filename, "PAL", "pal", pal, 368);
	int palOffset = RECOIL_GetAmstradHeader(pal, palLength);
	if (palLength != palOffset + 239)
		return -1;
	for (int i = 0; i < 16; i++) {
		int c = pal[palOffset + 3 + i * 12];
		if (c < 64 || c > 95)
			return -1;
		self->contentPalette[i] = RECOIL_AMSTRAD_PALETTE[c - 64];
	}
	return pal[palOffset];
}

static void RECOIL_DecodeAmstradMode0Line(RECOIL *self, uint8_t const *content, int lineOffset, int y)
{
	int skip = self->resolution == RECOILResolution_AMSTRAD1X1 ? (y ^ (y >= self->height ? 1 : 0)) & 1 : 0;
	for (int x = 0; x < self->width; x++) {
		int i = x + skip;
		int b = i >= self->width ? 0 : content[lineOffset + (i >> 2)];
		if ((i & 2) == 0)
			b >>= 1;
		self->pixels[y * self->width + x] = self->contentPalette[((b & 1) << 3) + (b >> 2 & 4) + (b >> 1 & 2) + (b >> 6 & 1)];
	}
}

static void RECOIL_DecodeAmstradMode1Line(RECOIL *self, uint8_t const *content, int lineOffset, int y)
{
	for (int x = 0; x < self->width; x++) {
		int b = content[lineOffset + (x >> 2)] >> (~x & 3);
		self->pixels[y * self->width + x] = self->contentPalette[((b & 1) << 1) + (b >> 4 & 1)];
	}
}

static bool RECOIL_DecodeAmstradScr(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[16384];
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	switch (contentLength - contentOffset) {
	case 16336:
	case 16384:
		break;
	default:
		if (!AmstradStream_UnpackFile(content, contentOffset, contentLength, unpacked, 16384))
			return false;
		content = unpacked;
		contentOffset = 0;
		break;
	}
	switch (RECOIL_SetAmstradPalette(self, filename)) {
	case 0:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_AMSTRAD2X1, 1);
		for (int y = 0; y < 200; y++)
			RECOIL_DecodeAmstradMode0Line(self, content, contentOffset + ((y & 7) << 11) + (y >> 3) * 80, y);
		return true;
	case 1:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_AMSTRAD1X1, 1);
		for (int y = 0; y < 200; y++)
			RECOIL_DecodeAmstradMode1Line(self, content, contentOffset + ((y & 7) << 11) + (y >> 3) * 80, y);
		return true;
	case 2:
		return RECOIL_DecodeAmstradMode2(self, content, contentOffset, 640, 200);
	default:
		return false;
	}
}

static bool RECOIL_DecodeWin(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 6)
		return false;
	int width = content[contentLength - 4] | content[contentLength - 3] << 8;
	if (width == 0 || width > 640)
		return false;
	int height = content[contentLength - 2];
	if (height == 0 || height > 200)
		return false;
	int bytesPerLine = (width + 7) >> 3;
	uint8_t unpacked[16000];
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	if (contentLength != contentOffset + bytesPerLine * height + 5) {
		if (!AmstradStream_UnpackFile(content, contentOffset, contentLength, unpacked, bytesPerLine * height))
			return false;
		content = unpacked;
		contentOffset = 0;
	}
	if (RECOIL_SetAmstradPalette(self, filename) != 0)
		return false;
	width >>= 1;
	RECOIL_SetSize(self, width, height, RECOILResolution_AMSTRAD2X1, 1);
	for (int y = 0; y < height; y++)
		RECOIL_DecodeAmstradMode0Line(self, content, contentOffset + y * bytesPerLine, y);
	return true;
}

static bool RECOIL_DecodeCm5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength != 2049)
		return false;
	uint8_t gfx[18433];
	if (RECOIL_ReadCompanionFile(self, filename, "GFX", "gfx", gfx, 18433) != 18432)
		return false;
	RECOIL_SetSize(self, 288, 256, RECOILResolution_AMSTRAD1X1, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 288; x++) {
			int c;
			switch (gfx[y * 72 + (x >> 2)] >> (~x & 3) & 17) {
			case 0:
				c = 3 + (y << 3) + x / 48;
				break;
			case 1:
				c = 1 + (y << 3);
				break;
			case 16:
				c = 2 + (y << 3);
				break;
			default:
				c = 0;
				break;
			}
			c = content[c];
			if (c < 64 || c > 95)
				return false;
			self->pixels[y * 288 + x] = RECOIL_AMSTRAD_PALETTE[c - 64];
		}
	}
	return true;
}

static bool RECOIL_DecodeSgx(RECOIL *self, uint8_t const *content, int contentLength)
{
	int width = 0;
	int height = 0;
	int chunkLeft = 0;
	int rowHeight = 0;
	for (int contentOffset = 0; contentOffset + 3 < contentLength;) {
		int chunkStride = content[contentOffset];
		if (chunkStride == 0)
			break;
		if (chunkStride == 255) {
			if (width == 0)
				width = chunkLeft;
			else if (chunkLeft != width)
				return false;
			chunkLeft = 0;
			contentOffset += 3;
		}
		else {
			int chunkWidth;
			int chunkHeight;
			if (chunkStride <= 63) {
				chunkWidth = content[contentOffset + 1];
				if ((chunkWidth + 3) >> 2 != chunkStride)
					return false;
				chunkHeight = content[contentOffset + 2];
				contentOffset += 3;
			}
			else if (chunkStride == 64) {
				if (contentOffset + 8 >= contentLength || content[contentOffset + 1] != 5)
					return false;
				chunkStride = content[contentOffset + 2] | content[contentOffset + 3] << 8;
				chunkWidth = content[contentOffset + 4] | content[contentOffset + 5] << 8;
				if ((chunkWidth + 1) >> 1 != chunkStride)
					return false;
				chunkHeight = content[contentOffset + 6] | content[contentOffset + 7] << 8;
				contentOffset += 8;
			}
			else
				return false;
			if (chunkLeft == 0)
				height += rowHeight = chunkHeight;
			else if (chunkHeight != rowHeight)
				return false;
			chunkLeft += chunkWidth;
			contentOffset += chunkHeight * chunkStride;
			if (contentOffset > contentLength)
				return false;
		}
	}
	if (width == 0)
		width = chunkLeft;
	else if (chunkLeft != width)
		return false;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_AMSTRAD1X1, 1))
		return false;
	chunkLeft = 0;
	int chunkTop = 0;
	rowHeight = 0;
	for (int contentOffset = 0; contentOffset + 3 < contentLength;) {
		int chunkStride = content[contentOffset];
		if (chunkStride == 0)
			break;
		if (chunkStride == 255) {
			chunkLeft = 0;
			chunkTop += rowHeight;
			contentOffset += 3;
		}
		else {
			int chunkWidth;
			if (chunkStride <= 63) {
				chunkWidth = content[contentOffset + 1];
				rowHeight = content[contentOffset + 2];
				contentOffset += 3;
				for (int y = 0; y < rowHeight; y++) {
					for (int x = 0; x < chunkWidth; x++) {
						int b = content[contentOffset + (x >> 2)] >> (~x & 3);
						static const int PALETTE4[4] = { 16777215, 11184810, 0, 5592405 };
						self->pixels[(chunkTop + y) * width + chunkLeft + x] = PALETTE4[(b >> 3 & 2) + (b & 1)];
					}
					contentOffset += chunkStride;
				}
			}
			else {
				chunkStride = content[contentOffset + 2] | content[contentOffset + 3] << 8;
				chunkWidth = content[contentOffset + 4] | content[contentOffset + 5] << 8;
				rowHeight = content[contentOffset + 6] | content[contentOffset + 7] << 8;
				contentOffset += 8;
				for (int y = 0; y < rowHeight; y++) {
					for (int x = 0; x < chunkWidth; x++) {
						int c = RECOIL_GetNibble(content, contentOffset, x);
						static const int PALETTE16[16] = { 16777088, 0, 16744448, 8388608, 65535, 128, 8421631, 255, 16777215, 32768, 65280, 16711935, 16776960, 8421504, 16744576, 16711680 };
						self->pixels[(chunkTop + y) * width + chunkLeft + x] = PALETTE16[c];
					}
					contentOffset += chunkStride;
				}
			}
			chunkLeft += chunkWidth;
		}
	}
	return true;
}

static bool RECOIL_SetAmstradFirmwarePalette(RECOIL *self, uint8_t const *content, int contentOffset, int count)
{
	for (int i = 0; i < count; i++) {
		int c = content[contentOffset + i];
		if (c > 26)
			return false;
		static const uint8_t TRI_LEVEL[3] = { 0, 128, 255 };
		self->contentPalette[i] = TRI_LEVEL[c / 3 % 3] << 16 | TRI_LEVEL[c / 9] << 8 | TRI_LEVEL[c % 3];
	}
	return true;
}

static bool RECOIL_SetAmstradFirmwarePalette16(RECOIL *self, uint8_t const *content)
{
	return content[5] == 1 && RECOIL_SetAmstradFirmwarePalette(self, content, 6, 16);
}

static bool RECOIL_DecodePphFrame(RECOIL *self, const char *filename, const char *upperExt, const char *lowerExt, uint8_t *bitmap, uint8_t const *pph, int yOffset)
{
	int bitmapStride = self->width >> 2;
	int bitmapLength = self->height * bitmapStride;
	if (RECOIL_ReadCompanionFile(self, filename, upperExt, lowerExt, bitmap, bitmapLength + 1) != bitmapLength)
		return false;
	if (pph[0] == 5) {
		int paletteOffset = 6;
		int paletteLines = 0;
		for (int y = 0; y < self->height; y++) {
			if (paletteLines == 0) {
				if (!RECOIL_SetAmstradFirmwarePalette(self, pph, paletteOffset, 4))
					return false;
				paletteOffset += 4;
				if (paletteOffset < (1 + pph[5]) * 5) {
					paletteLines = pph[paletteOffset++];
					if (paletteLines == 0)
						return false;
				}
				else
					paletteLines = 272;
			}
			RECOIL_DecodeAmstradMode1Line(self, bitmap, y * bitmapStride, yOffset + y);
			paletteLines--;
		}
	}
	else {
		for (int y = 0; y < self->height; y++)
			RECOIL_DecodeAmstradMode0Line(self, bitmap, y * bitmapStride, yOffset + y);
	}
	return true;
}

static bool RECOIL_DecodePph(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 10)
		return false;
	RECOILResolution resolution;
	switch (content[0]) {
	case 3:
		if (contentLength != 22 || !RECOIL_SetAmstradFirmwarePalette16(self, content))
			return false;
		resolution = RECOILResolution_AMSTRAD1X1;
		break;
	case 4:
		if (contentLength != 22 || !RECOIL_SetAmstradFirmwarePalette16(self, content))
			return false;
		resolution = RECOILResolution_AMSTRAD2X1;
		break;
	case 5:
		if (contentLength != (1 + content[5]) * 5)
			return false;
		resolution = RECOILResolution_AMSTRAD1X1;
		break;
	default:
		return false;
	}
	int width = content[1] | content[2] << 8;
	if (width == 0 || width > 384 || (width & 3) != 0)
		return false;
	int height = content[3] | content[4] << 8;
	if (height == 0 || height > 272)
		return false;
	RECOIL_SetSize(self, width, height, resolution, 2);
	uint8_t bitmap[26113];
	return RECOIL_DecodePphFrame(self, filename, "ODD", "odd", bitmap, content, 0) && RECOIL_DecodePphFrame(self, filename, "EVE", "eve", bitmap, content, height) && RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeZx81(RECOIL *self, uint8_t const *screen)
{
	RECOIL_SetSize(self, 256, 192, RECOILResolution_ZX811X1, 1);
	uint8_t const *font = FuResource_zx81_fnt;
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 256; x++) {
			int c = screen[y >> 3 << 5 | x >> 3];
			int b = font[(c & 63) << 3 | (y & 7)] >> (~x & 7) & 1;
			self->pixels[(y << 8) + x] = b == c >> 7 ? 16777215 : 0;
		}
	}
	return true;
}

static bool RECOIL_DecodeZx81Raw(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 792)
		return false;
	uint8_t screen[768];
	for (int y = 0; y < 24; y++) {
		if (content[y * 33 + 32] != 118)
			return false;
		memcpy(screen + y * 32, content + y * 33, 32);
	}
	return RECOIL_DecodeZx81(self, screen);
}

static bool RECOIL_DecodeZp1(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t screen[768];
	Stream s;
	s.content = content;
	s.contentOffset = 0;
	s.contentLength = contentLength;
	for (int i = 0; i < 768; i++) {
		int b = Stream_ReadHexByte(&s);
		if (b < 0)
			return false;
		screen[i] = (uint8_t) b;
	}
	return RECOIL_DecodeZx81(self, screen);
}

static bool RECOIL_DecodeP(RECOIL *self, uint8_t const *content, int contentLength)
{
	PInterpreter interp;
	interp.base.content = content;
	interp.base.contentLength = contentLength;
	return PInterpreter_Run(&interp) && RECOIL_DecodeZx81(self, interp.screen);
}

static int RECOIL_GetZxColor(int c)
{
	return (c >> 1 & 1) * 16711680 | (c >> 2 & 1) * 65280 | (c & 1) * 255;
}

static void RECOIL_SetZxPalette(RECOIL *self)
{
	for (int i = 0; i < 64; i++) {
		int rgb = RECOIL_GetZxColor(i);
		if ((i & 16) == 0)
			rgb &= 13487565;
		self->contentPalette[i] = rgb;
	}
}

static bool RECOIL_SetZxSize(RECOIL *self, int width, int height, RECOILResolution resolution, int frames)
{
	if (!RECOIL_SetSize(self, width, height, resolution, frames))
		return false;
	RECOIL_SetZxPalette(self);
	return true;
}

static void RECOIL_SetZx(RECOIL *self, RECOILResolution resolution, int frames)
{
	RECOIL_SetZxSize(self, 256, 192, resolution, frames);
}

static int RECOIL_GetG3R3B2Color(int c)
{
	return (c & 28) * 73 >> 3 << 16 | (c >> 5) * 73 >> 1 << 8 | (c & 3) * 85;
}

static void RECOIL_SetUlaPlus(RECOIL *self, uint8_t const *content, int paletteOffset)
{
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM_ULA_PLUS1X1, 1);
	for (int i = 0; i < 64; i++)
		self->contentPalette[i] = RECOIL_GetG3R3B2Color(content[paletteOffset + i]);
}

static int RECOIL_GetZxLineOffset(int y)
{
	return ((y & 192) << 5) + ((y & 7) << 8) + ((y & 56) << 2);
}

static void RECOIL_DecodeZx(RECOIL *self, uint8_t const *content, int bitmapOffset, int attributesOffset, int attributesMode, int pixelsOffset)
{
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 256; x++) {
			int col = x >> 3;
			int c;
			switch (bitmapOffset) {
			case -3:
				c = x ^ y;
				break;
			case -2:
				c = content[84 + (y & 7)] >> (~x & 7);
				break;
			case -1:
				c = content[y << 5 | col] >> (~x & 7);
				break;
			default:
				c = content[bitmapOffset + RECOIL_GetZxLineOffset(y) + col] >> (~x & 7);
				break;
			}
			c &= 1;
			if (attributesMode == -3) {
				if (c != 0)
					c = 16777215;
			}
			else {
				int a;
				switch (attributesMode) {
				case -2:
					if (col < 8)
						a = attributesOffset + (y >> 3 << 4);
					else if (col < 24)
						a = (attributesOffset == 18688 ? 12536 : 15608) + (y << 4);
					else
						a = attributesOffset + (y >> 3 << 4) - 16;
					break;
				case -1:
					a = attributesOffset + RECOIL_GetZxLineOffset(y);
					break;
				default:
					a = attributesOffset + (y >> attributesMode << 5);
					break;
				}
				a = content[a + col];
				c = self->contentPalette[(a >> 2 & 48) | (c == 0 ? 8 | (a >> 3 & 7) : a & 7)];
			}
			self->pixels[pixelsOffset + (y << 8) + x] = c;
		}
	}
}

static void RECOIL_DecodeTimexHires(RECOIL *self, uint8_t const *content, int contentOffset, int pixelsOffset)
{
	int inkColor = RECOIL_GetZxColor(content[contentOffset + 12288] >> 3);
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 512; x++) {
			int c = content[contentOffset + (x & 8) * 768 + RECOIL_GetZxLineOffset(y) + (x >> 4)] >> (~x & 7) & 1;
			int offset = pixelsOffset + (y << 10) + x;
			self->pixels[offset + 512] = self->pixels[offset] = c == 0 ? inkColor ^ 16777215 : inkColor;
		}
	}
}

static bool RECOIL_DecodeHrg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 24578)
		return false;
	RECOIL_SetSize(self, 512, 384, RECOILResolution_TIMEX1X2, 2);
	RECOIL_DecodeTimexHires(self, content, 0, 0);
	RECOIL_DecodeTimexHires(self, content, 12289, 196608);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeZxIfl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 9216)
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
	RECOIL_DecodeZx(self, content, 0, 6144, 1, 0);
	return true;
}

static bool RECOIL_DecodeMcMlt(RECOIL *self, uint8_t const *content, int contentLength, int bitmapOffset)
{
	if (contentLength != 12288)
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
	RECOIL_DecodeZx(self, content, bitmapOffset, 6144, 0, 0);
	return true;
}

static bool RECOIL_DecodeZxImg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 13824)
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 2);
	RECOIL_DecodeZx(self, content, 0, 6144, 3, 0);
	RECOIL_DecodeZx(self, content, 6912, 13056, 3, 49152);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeMg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 14080 || content[0] != 'M' || content[1] != 'G' || content[2] != 'H' || content[3] != 1)
		return false;
	int attributesMode;
	switch (content[4]) {
	case 1:
		if (contentLength != 19456)
			return false;
		RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 2);
		RECOIL_DecodeZx(self, content, 256, 18688, -2, 0);
		RECOIL_DecodeZx(self, content, 6400, 19072, -2, 49152);
		return RECOIL_ApplyBlend(self);
	case 2:
		attributesMode = 1;
		break;
	case 4:
		attributesMode = 2;
		break;
	case 8:
		attributesMode = 3;
		break;
	default:
		return false;
	}
	if (contentLength != 12544 + (12288 >> attributesMode))
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 2);
	RECOIL_DecodeZx(self, content, 256, 12544, attributesMode, 0);
	RECOIL_DecodeZx(self, content, 6400, 12544 + (6144 >> attributesMode), attributesMode, 49152);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeAtr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 768)
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
	RECOIL_DecodeZx(self, content, -3, 0, 3, 0);
	return true;
}

static bool RECOIL_DecodeHlr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1628 || content[0] != 118 || content[1] != 175 || content[2] != 211 || content[3] != 254 || content[4] != 33 || content[5] != 0 || content[6] != 88)
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 2);
	RECOIL_DecodeZx(self, content, -2, 92, 3, 0);
	RECOIL_DecodeZx(self, content, -2, 860, 3, 49152);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeStl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3072)
		return false;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM4X4, 2);
	for (int f = 0; f < 2; f++) {
		for (int y = 0; y < 192; y++) {
			for (int x = 0; x < 256; x++) {
				int b = content[(y & ~3) << 4 | (x >> 2 & ~3) | f << 1 | (x >> 3 & 1)];
				int rgb = RECOIL_GetZxColor((x & 4) == 0 ? b >> 3 : b);
				if ((b & 64) == 0)
					rgb &= 13487565;
				self->pixels[((f * 192 + y) << 8) + x] = rgb;
			}
		}
	}
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeZxRgb3(RECOIL *self, uint8_t const *content, int contentLength, uint8_t const *frameComponents)
{
	if (contentLength != 18432)
		return false;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1, 1);
	self->frames = 3;
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 256; x++) {
			int offset = RECOIL_GetZxLineOffset(y) + (x >> 3);
			int c = 0;
			for (int frame = 0; frame < 3; frame++) {
				if ((content[frame * 6144 + offset] >> (~x & 7) & 1) != 0)
					c |= 255 << frameComponents[frame];
			}
			self->pixels[(y << 8) + x] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeZxRgb(RECOIL *self, uint8_t const *content, int contentLength)
{
	static const uint8_t FRAME_COMPONENTS[3] = { 16, 8, 0 };
	return RECOIL_DecodeZxRgb3(self, content, contentLength, FRAME_COMPONENTS);
}

static bool RECOIL_Decode3(RECOIL *self, uint8_t const *content, int contentLength)
{
	static const uint8_t FRAME_COMPONENTS[3] = { 0, 16, 8 };
	return RECOIL_DecodeZxRgb3(self, content, contentLength, FRAME_COMPONENTS);
}

static bool RECOIL_DecodeZxs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 2452 || !RECOIL_IsStringAt(content, 0, "ZX_SSCII") || content[8] != 148 || content[9] != 9 || content[10] != 0 || content[11] != 0)
		return false;
	RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 256; x++) {
			int offset = (x & ~7) * 3 + (y >> 3);
			int c = content[908 + offset];
			if (c >= 112)
				return false;
			c = content[12 + (c << 3) + (y & 7)] >> (~x & 7) & 1;
			int a = content[1676 + offset];
			self->pixels[(y << 8) + x] = self->contentPalette[(a >> 2 & 48) | (c == 0 ? 8 | (a >> 3 & 7) : a & 7)];
		}
	}
	return true;
}

static bool RECOIL_DecodeSev(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 23 || content[0] != 'S' || content[1] != 'e' || content[2] != 'v' || content[3] != 0 || content[6] != 1 || content[7] != 0)
		return false;
	int width = content[10] | content[11] << 8;
	int height = content[12] | content[13] << 8;
	int columns = (width + 7) >> 3;
	int rows = (height + 7) >> 3;
	if (contentLength < 14 + rows * columns * 9 || !RECOIL_SetZxSize(self, width, height, RECOILResolution_SPECTRUM1X1, 1))
		return false;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int offset = 14 + ((y >> 3) * columns + (x >> 3)) * 9;
			int c = content[offset + (y & 7)] >> (~x & 7) & 1;
			int a = content[offset + 8];
			self->pixels[y * width + x] = self->contentPalette[(a >> 2 & 48) | (c == 0 ? 8 | (a >> 3 & 7) : a & 7)];
		}
	}
	return true;
}

static bool RECOIL_DecodeCh8(RECOIL *self, uint8_t const *content, int contentLength)
{
	if ((contentLength & 7) != 0 || !RECOIL_SetSize(self, 256, (contentLength + 248) >> 8 << 3, RECOILResolution_SPECTRUM1X1, 1))
		return false;
	RECOIL_DecodeBlackAndWhiteFont(self, content, 0, contentLength, 8);
	return true;
}

static int RECOIL_GetChxTileOffset(uint8_t const *content, int tile)
{
	return content[5 + (tile << 1)] | content[6 + (tile << 1)] << 8;
}

static bool RECOIL_DecodeChx(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 517 || content[0] != 'C' || content[1] != 'H' || content[2] != 'X' || content[3] != 0 || content[4] != 0)
		return false;
	int maxColumns = 0;
	int maxRows = 0;
	for (int tile = 0; tile < 256; tile++) {
		int offset = RECOIL_GetChxTileOffset(content, tile);
		if (offset == 0)
			continue;
		if (offset + 2 >= contentLength)
			return false;
		int transparent = content[offset];
		if (transparent > 1)
			return false;
		int columns = content[offset + 1];
		int rows = content[offset + 2];
		if (offset + 3 + rows * columns * (9 - transparent) > contentLength)
			return false;
		if (maxColumns < columns)
			maxColumns = columns;
		if (maxRows < rows)
			maxRows = rows;
	}
	int width = maxColumns << 7;
	int height = maxRows << 7;
	if (!RECOIL_SetZxSize(self, width, height, RECOILResolution_SPECTRUM1X1, 1))
		return false;
	for (int y = 0; y < height; y++) {
		int row = y >> 3;
		int rowTile = row / maxRows << 4;
		row %= maxRows;
		for (int x = 0; x < width; x++) {
			int column = x >> 3;
			int tile = rowTile + column / maxColumns;
			column %= maxColumns;
			int c = ~x ^ y;
			int a = 56;
			int offset = RECOIL_GetChxTileOffset(content, tile);
			if (offset > 0) {
				int columns = content[offset + 1];
				if (column < columns && row < content[offset + 2]) {
					int transparent = content[offset];
					offset += 3 + (row * columns + column) * (9 - transparent);
					c = content[offset + (y & 7)] >> (~x & 7);
					if (transparent == 0)
						a = content[offset + 8];
				}
			}
			self->pixels[y * width + x] = self->contentPalette[(a >> 2 & 48) | ((c & 1) == 0 ? 8 | (a >> 3 & 7) : a & 7)];
		}
	}
	return true;
}

static bool RECOIL_DecodeZxp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 25 || !RECOIL_IsStringAt(content, 0, "ZX-Paintbrush "))
		return false;
	ZxpStream s;
	s.base.content = content;
	s.base.contentOffset = RECOIL_IsStringAt(content, 14, "extended ") ? 23 : 14;
	s.base.contentLength = contentLength;
	if (!Stream_Expect(&s.base, "image") || ZxpStream_ReadChar(&s) != '\n' || ZxpStream_ReadChar(&s) != '\n')
		return false;
	int bitmapOffset = s.base.contentOffset;
	int width = 0;
	int height = 0;
	for (int x = 0;;) {
		switch (ZxpStream_ReadChar(&s)) {
		case '*':
		case '0':
		case '1':
			x++;
			continue;
		case '\n':
			break;
		default:
			return false;
		}
		if (x == 0)
			break;
		if (height == 0)
			width = x;
		else if (x != width)
			return false;
		height++;
		x = 0;
	}
	int attributesOffset = s.base.contentOffset;
	int attributesHeight = 0;
	RECOILResolution resolution = RECOILResolution_SPECTRUM1X1;
	RECOIL_SetZxPalette(self);
	while (!ZxpStream_IsEof(&s)) {
		int b = content[s.base.contentOffset];
		if (b == '\r' || b == '\n') {
			for (int i = 0; i < 64; i++) {
				if (ZxpStream_ReadChar(&s) != (i == 0 ? '\n' : ' '))
					return false;
				b = Stream_ReadHexByte(&s.base);
				if (b < 0)
					return false;
				self->contentPalette[i] = RECOIL_GetG3R3B2Color(b);
			}
			if (ZxpStream_ReadChar(&s) != '\n' || !ZxpStream_IsEof(&s))
				return false;
			resolution = RECOILResolution_SPECTRUM_ULA_PLUS1X1;
			break;
		}
		if (Stream_ReadHexByte(&s.base) < 0)
			return false;
		switch (ZxpStream_ReadChar(&s)) {
		case ' ':
			break;
		case '\n':
			attributesHeight++;
			break;
		default:
			return false;
		}
	}
	if ((attributesHeight != height && attributesHeight != (height + 7) >> 3) || !RECOIL_SetSize(self, width, height, resolution, 1))
		return false;
	s.base.contentOffset = attributesOffset;
	for (int y = 0; y < height; y++) {
		if (attributesHeight != height) {
			if ((y & 7) == 0)
				attributesOffset = s.base.contentOffset;
			else
				s.base.contentOffset = attributesOffset;
		}
		int a = 0;
		for (int x = 0; x < width; x++) {
			if ((x & 7) == 0) {
				if (x > 0 && ZxpStream_ReadChar(&s) != ' ')
					return false;
				a = Stream_ReadHexByte(&s.base);
			}
			self->pixels[y * width + x] = self->contentPalette[(a >> 2 & 48) | (content[bitmapOffset++] != '1' ? 8 | (a >> 3 & 7) : a & 7)];
		}
		if (content[bitmapOffset] == '\r')
			bitmapOffset++;
		if (content[bitmapOffset++] != '\n' || ZxpStream_ReadChar(&s) != '\n')
			return false;
	}
	return true;
}

static bool RECOIL_DecodeBsc(RECOIL *self, uint8_t const *content, int contentLength)
{
	int borderOffset;
	switch (contentLength) {
	case 11136:
		borderOffset = 6912;
		break;
	case 11904:
		borderOffset = 7680;
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 384, 304, RECOILResolution_SPECTRUM1X1, 1);
	for (int y = 0; y < 304; y++) {
		int c = 0;
		for (int x = 0; x < 384; x++) {
			if (y >= 64 && y < 256 && x >= 64 && x < 320) {
				int bY = y - 64;
				int col = (x >> 3) - 8;
				int a = 6144 + (bY >> 3 << 5) + col;
				if (contentLength == 11904 && (bY & 4) != 0)
					a += 768;
				c = a = content[a];
				if ((content[RECOIL_GetZxLineOffset(bY) + col] >> (~x & 7) & 1) == 0)
					c >>= 3;
				c = RECOIL_GetZxColor(c);
				if ((a & 64) == 0)
					c &= 13487565;
			}
			else if ((x & 7) == 0) {
				c = content[borderOffset];
				if ((x & 8) != 0) {
					borderOffset++;
					c >>= 3;
				}
				c = RECOIL_GetZxColor(c) & 13487565;
			}
			self->pixels[y * 384 + x] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeChrd(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 15 || !RECOIL_IsStringAt(content, 0, "chr$"))
		return false;
	int columns = content[4];
	int rows = content[5];
	int bytesPerCell = content[6];
	int cells = rows * columns;
	int frames;
	switch (bytesPerCell) {
	case 9:
		frames = 1;
		break;
	case 18:
		frames = 2;
		break;
	default:
		return false;
	}
	if (contentLength != 7 + cells * bytesPerCell || !RECOIL_SetSize(self, columns << 3, rows << 3, RECOILResolution_SPECTRUM1X1, frames))
		return false;
	int contentOffset = 7;
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			for (int frame = 0; frame < frames; frame++) {
				int a = content[contentOffset + 8];
				for (int y = 0; y < 8; y++) {
					for (int x = 0; x < 8; x++) {
						int c = content[contentOffset + y] >> (7 - x) & 1;
						c = RECOIL_GetZxColor(c == 0 ? a >> 3 : a);
						if ((a & 64) == 0)
							c &= 13487565;
						self->pixels[(((((frame * rows + row) << 3) + y) * columns + column) << 3) + x] = c;
					}
				}
				contentOffset += 9;
			}
		}
	}
	if (frames == 2)
		RECOIL_ApplyBlend(self);
	return true;
}

static int RECOIL_GetBspBitmapPixel(uint8_t const *content, int bitmapOffset, int x, int y)
{
	int col = x >> 3;
	int a = content[bitmapOffset + 6144 + (y >> 3 << 5) + col];
	int c = a;
	if ((content[bitmapOffset + RECOIL_GetZxLineOffset(y) + col] >> (~x & 7) & 1) == 0)
		c >>= 3;
	c = RECOIL_GetZxColor(c);
	if ((a & 64) == 0)
		c &= 13487565;
	return c;
}

static bool RECOIL_DecodeBspFrame(RECOIL *self, int pixelsOffset, uint8_t const *content, int contentLength, int bitmapOffset, int borderOffset)
{
	for (int y = 0; y < self->height; y++) {
		int c = 0;
		int b = 1;
		for (int x = 0; x < self->width; x++) {
			if (borderOffset < 0)
				c = RECOIL_GetBspBitmapPixel(content, bitmapOffset, x, y);
			else if (x >= 64 && x < 320 && y >= 64 && y < 256) {
				c = RECOIL_GetBspBitmapPixel(content, bitmapOffset, x - 64, y - 64);
				b = 1;
			}
			else if (b > 0) {
				if (--b == 0) {
					if (borderOffset >= contentLength)
						return false;
					b = content[borderOffset++];
					c = RECOIL_GetZxColor(b) & 13487565;
					b >>= 3;
					switch (b) {
					case 0:
						break;
					case 1:
						if (borderOffset >= contentLength)
							return false;
						b = content[borderOffset++];
						break;
					case 2:
						b = 12;
						break;
					default:
						b += 13;
						break;
					}
					b <<= 1;
				}
			}
			self->pixels[pixelsOffset + y * self->width + x] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeBsp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 6982)
		return false;
	if ((content[3] & 64) == 0) {
		if (content[3] < 128) {
			RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1, 1);
			return RECOIL_DecodeBspFrame(self, 0, content, contentLength, 70, -1);
		}
		return contentLength == 13894 && RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1, 2) && RECOIL_DecodeBspFrame(self, 0, content, contentLength, 70, -1) && RECOIL_DecodeBspFrame(self, 49152, content, contentLength, 6982, -1) && RECOIL_ApplyBlend(self);
	}
	if (content[3] < 128) {
		RECOIL_SetSize(self, 384, 304, RECOILResolution_SPECTRUM1X1, 1);
		return RECOIL_DecodeBspFrame(self, 0, content, contentLength, 70, 6982);
	}
	RECOIL_SetSize(self, 384, 304, RECOILResolution_SPECTRUM1X1, 2);
	return RECOIL_DecodeBspFrame(self, 0, content, contentLength, 72, 13896) && RECOIL_DecodeBspFrame(self, 116736, content, contentLength, 6984, content[70] | content[71] << 8) && RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeNxi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 49664)
		return false;
	for (int i = 0; i < 256; i++) {
		int c = content[i << 1];
		self->contentPalette[i] = (c >> 5) * 73 >> 1 << 16 | (c >> 2 & 7) * 73 >> 1 << 8 | ((c & 3) << 1 | (content[(i << 1) + 1] & 1)) * 73 >> 1;
	}
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM_NEXT1X1, 1);
	RECOIL_DecodeBytes(self, content, 512);
	return true;
}

static bool RECOIL_DecodeProfiGrf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 30848 || content[0] != 0 || content[1] != 2 || content[2] != 240 || content[3] != 0 || content[4] != 4 || content[5] != 0 || content[6] != 128 || content[7] != 0 || content[8] != 1 || content[9] != 19)
		return false;
	RECOIL_SetSize(self, 512, 480, RECOILResolution_SPECTRUM_PROFI1X2, 1);
	for (int c = 0; c < 16; c++)
		self->contentPalette[c] = RECOIL_GetG3R3B2Color(content[10 + c]);
	for (int y = 0; y < 480; y++) {
		for (int x = 0; x < 512; x++) {
			int offset = 128 + (y >> 1 << 7) + (x >> 3 << 1);
			int b = content[offset] >> (~x & 7) & 1;
			int a = content[offset + 1];
			self->pixels[(y << 9) + x] = self->contentPalette[b == 0 ? (a >> 4 & 8) | (a >> 3 & 7) : (a >> 3 & 8) | (a & 7)];
		}
	}
	return true;
}

static bool RECOIL_DecodeSxg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 19 || content[0] != 127 || content[1] != 'S' || content[2] != 'X' || content[3] != 'G' || content[6] != 0)
		return false;
	int width = content[8] | content[9] << 8;
	int height = content[10] | content[11] << 8;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_ZX_EVOLUTION1X1, 1))
		return false;
	int paletteOffset = 14 + content[12] + (content[13] << 8);
	int bitmapOffset = 16 + content[14] + (content[15] << 8);
	int paletteLength = bitmapOffset - paletteOffset;
	if ((paletteLength & 1) != 0 || paletteLength > 512 || contentLength < paletteOffset + paletteLength)
		return false;
	memset(self->contentPalette, 0, sizeof(self->contentPalette));
	int colors = paletteLength >> 1;
	for (int i = 0; i < colors; i++) {
		int offset = paletteOffset + (i << 1);
		int c = content[offset] | content[offset + 1] << 8;
		if (c < 32768) {
			int r = c >> 10;
			int g = c >> 5 & 31;
			int b = c & 31;
			if (r > 24 || g > 24 || b > 24)
				return false;
			c = r * 255 / 24 << 16 | g * 255 / 24 << 8 | b * 255 / 24;
		}
		else
			c = RECOIL_GetR5G5B5Color(c);
		self->contentPalette[i] = c;
	}
	switch (content[7]) {
	case 1:
		width = (width + 1) >> 1;
		if (contentLength != bitmapOffset + width * height)
			return false;
		RECOIL_DecodeNibbles(self, content, bitmapOffset, width);
		return true;
	case 2:
		if (contentLength != bitmapOffset + width * height)
			return false;
		RECOIL_DecodeBytes(self, content, bitmapOffset);
		return true;
	default:
		return false;
	}
}

static void RECOIL_SetMsx1Palette(RECOIL *self)
{
	self->contentPalette[0] = 2048;
	self->contentPalette[1] = 1024;
	self->contentPalette[2] = 3849027;
	self->contentPalette[3] = 7394167;
	self->contentPalette[4] = 5528023;
	self->contentPalette[5] = 8092648;
	self->contentPalette[6] = 11756363;
	self->contentPalette[7] = 6414311;
	self->contentPalette[8] = 13920851;
	self->contentPalette[9] = 16289399;
	self->contentPalette[10] = 13092697;
	self->contentPalette[11] = 14275713;
	self->contentPalette[12] = 3581243;
	self->contentPalette[13] = 11561902;
	self->contentPalette[14] = 13095109;
	self->contentPalette[15] = 16449528;
}

static int RECOIL_GetMsxHeader(uint8_t const *content)
{
	if (content[1] != 0 || content[2] != 0 || content[5] != 0 || content[6] != 0)
		return -1;
	return content[3] | content[4] << 8;
}

static bool RECOIL_IsMsxPalette(uint8_t const *content, int contentOffset)
{
	int ored = 0;
	for (int i = 0; i < 16; i++) {
		int rb = content[contentOffset + (i << 1)];
		int g = content[contentOffset + (i << 1) + 1];
		if ((rb & 136) != 0 || (g & 248) != 0)
			return false;
		ored |= rb | g;
	}
	return ored != 0;
}

static void RECOIL_SetMsxPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors)
{
	for (int i = 0; i < colors; i++) {
		int rb = content[contentOffset + (i << 1)];
		int g = content[contentOffset + (i << 1) + 1];
		int rgb = (rb & 112) << 12 | (rb & 7) | (g & 7) << 8;
		self->contentPalette[i] = rgb << 5 | rgb << 2 | (rgb >> 1 & 197379);
	}
}

static void RECOIL_SetMsx2Palette(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength)
{
	if (contentLength >= contentOffset + 32)
		RECOIL_SetMsxPalette(self, content, contentOffset, 16);
	else
		RECOIL_SetMsxPalette(self, RECOIL_MSX2_DEFAULT_PALETTE, 0, 16);
}

static void RECOIL_DecodeSc2Sc4(RECOIL *self, uint8_t const *content, int contentOffset, RECOILResolution resolution)
{
	RECOIL_SetSize(self, 256, 192, resolution, 1);
	for (int y = 0; y < 192; y++) {
		int fontOffset = contentOffset + ((y & 192) << 5) + (y & 7);
		for (int x = 0; x < 256; x++) {
			int b = fontOffset + (content[contentOffset + 6144 + ((y & ~7) << 2) + (x >> 3)] << 3);
			int c = content[8192 + b];
			self->pixels[(y << 8) + x] = self->contentPalette[(content[b] >> (~x & 7) & 1) == 0 ? c & 15 : c >> 4];
		}
	}
}

static void RECOIL_DecodeMsxSprites(RECOIL *self, uint8_t const *content, int mode, int attributesOffset, int patternsOffset)
{
	int height = mode <= 4 ? 192 : 212;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < 256; x++) {
			int color = 0;
			bool enableOr = false;
			int spritesPerLine = mode >= 4 ? 8 : 4;
			for (int sprite = 0; sprite < 32; sprite++) {
				int attributeOffset = attributesOffset + (sprite << 2);
				int spriteY = content[attributeOffset];
				if (spriteY == (mode >= 4 ? 216 : 208))
					break;
				int row = (y - spriteY - 1) & 255;
				if (row >= 16)
					continue;
				if (--spritesPerLine < 0)
					break;
				int c = content[mode >= 4 ? attributesOffset - 512 + (sprite << 4) + row : attributeOffset + 3];
				if (mode < 4 || (c & 64) == 0) {
					if (color != 0)
						break;
					enableOr = true;
				}
				else if (!enableOr)
					continue;
				int column = x - content[attributeOffset + 1];
				if (c >= 128)
					column += 32;
				if (column < 0 || column >= 16)
					continue;
				int pattern = patternsOffset + ((content[attributeOffset + 2] & 252) << 3) + row;
				if ((content[pattern + ((column & 8) << 1)] >> (~column & 7) & 1) == 0)
					continue;
				color |= c;
				if (mode >= 4)
					color |= 16;
			}
			if (color != 0) {
				int offset;
				switch (mode) {
				case 6:
					offset = (y << 10) + (x << 1);
					self->pixels[offset + 512] = self->pixels[offset] = self->contentPalette[color >> 2 & 3];
					self->pixels[offset + 513] = self->pixels[offset + 1] = self->contentPalette[color & 3];
					break;
				case 7:
					offset = (y << 10) + (x << 1);
					self->pixels[offset + 513] = self->pixels[offset + 512] = self->pixels[offset + 1] = self->pixels[offset] = self->contentPalette[color & 15];
					break;
				default:
					self->pixels[(y << 8) + x] = self->contentPalette[color & 15];
					break;
				}
			}
		}
	}
}

static bool RECOIL_DecodeSc2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 14343 || content[0] != 254 || RECOIL_GetMsxHeader(content) < 14335)
		return false;
	if (RECOIL_IsMsxPalette(content, 7047)) {
		RECOIL_SetMsxPalette(self, content, 7047, 16);
		RECOIL_DecodeSc2Sc4(self, content, 7, RECOILResolution_MSX21X1);
	}
	else {
		RECOIL_SetMsx1Palette(self);
		RECOIL_DecodeSc2Sc4(self, content, 7, RECOILResolution_MSX11X1);
	}
	if (contentLength == 16391)
		RECOIL_DecodeMsxSprites(self, content, 2, 6919, 14343);
	return true;
}

static void RECOIL_DecodeSc3Screen(RECOIL *self, uint8_t const *content, int contentOffset, bool isLong)
{
	RECOIL_SetSize(self, 256, 192, RECOILResolution_MSX14X4, 1);
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 256; x++) {
			int c = isLong ? content[2055 + ((y & ~7) << 2) + (x >> 3)] : (y & 224) + (x >> 3);
			c = content[contentOffset + (c << 3) + (y >> 2 & 7)] >> (~x & 4) & 15;
			self->pixels[(y << 8) + x] = self->contentPalette[c];
		}
	}
}

static bool RECOIL_DecodeSc3(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1543 || content[0] != 254 || RECOIL_GetMsxHeader(content) < 1535)
		return false;
	if (contentLength >= 8263 && RECOIL_IsMsxPalette(content, 8231))
		RECOIL_SetMsxPalette(self, content, 8231, 16);
	else
		RECOIL_SetMsx1Palette(self);
	RECOIL_DecodeSc3Screen(self, content, 7, contentLength >= 2823);
	if (contentLength == 16391)
		RECOIL_DecodeMsxSprites(self, content, 3, 6919, 14343);
	return true;
}

static bool RECOIL_DecodeSc4(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 14343 || content[0] != 254 || RECOIL_GetMsxHeader(content) < 14335)
		return false;
	if (RECOIL_IsMsxPalette(content, 7047))
		RECOIL_SetMsxPalette(self, content, 7047, 16);
	else
		RECOIL_SetMsxPalette(self, RECOIL_MSX2_DEFAULT_PALETTE, 0, 16);
	RECOIL_DecodeSc2Sc4(self, content, 7, RECOILResolution_MSX21X1);
	if (contentLength >= 16391)
		RECOIL_DecodeMsxSprites(self, content, 4, 7687, 14343);
	return true;
}

static int RECOIL_GetMsx128Height(const RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 135 || content[0] != 254)
		return -1;
	int header = RECOIL_GetMsxHeader(content);
	if (header < 127)
		return -1;
	int height = (header + 1) >> 7;
	if (contentLength < 7 + (height << 7))
		return -1;
	return height < 212 ? height : 212;
}

static int RECOIL_ClampU5(int x)
{
	return x < 0 ? 0 : x > 31 ? 31 : x;
}

static int RECOIL_DecodeMsxYjk(const RECOIL *self, uint8_t const *content, int contentOffset, int x, int width, bool usePalette)
{
	int y = content[contentOffset + x] >> 3;
	if (usePalette && (y & 1) != 0)
		return self->contentPalette[y >> 1];
	int rgb;
	if ((x | 3) >= width) {
		rgb = y * 65793;
	}
	else {
		x = contentOffset + (x & ~3);
		int k = (content[x] & 7) | (content[x + 1] & 7) << 3;
		int j = (content[x + 2] & 7) | (content[x + 3] & 7) << 3;
		k -= (k & 32) << 1;
		j -= (j & 32) << 1;
		int r = RECOIL_ClampU5(y + j);
		int g = RECOIL_ClampU5(y + k);
		int b = RECOIL_ClampU5((5 * y - 2 * j - k + 2) >> 2);
		rgb = r << 16 | g << 8 | b;
	}
	return rgb << 3 | (rgb >> 2 & 460551);
}

static void RECOIL_DecodeMsxScreen(RECOIL *self, uint8_t const *content, int contentOffset, uint8_t const *interlace, int height, int mode, int interlaceMask)
{
	if (interlaceMask != 0) {
		RECOIL_SetSize(self, 512, height << 1, mode >= 10 ? RECOILResolution_MSX2_PLUS2X1I : mode >> 1 == 3 ? RECOILResolution_MSX21X1I : RECOILResolution_MSX22X1I, 1);
		self->frames = 2;
	}
	else if (mode >> 1 == 3)
		RECOIL_SetSize(self, 512, height << 1, RECOILResolution_MSX21X2, 1);
	else
		RECOIL_SetSize(self, 256, height, mode >= 10 ? RECOILResolution_MSX2_PLUS1X1 : RECOILResolution_MSX21X1, 1);
	for (int y = 0; y < self->height; y++) {
		uint8_t const *screen = (y & interlaceMask) == 0 ? content : interlace;
		int screenOffset = (y & interlaceMask) == 0 || content != interlace ? contentOffset : contentOffset + (mode <= 6 ? 27143 : 54279);
		for (int x = 0; x < self->width; x++) {
			int rgb = 0;
			switch (mode) {
			case 5:
				rgb = self->contentPalette[RECOIL_GetNibble(screen, screenOffset + (y >> interlaceMask << 7), x >> interlaceMask)];
				break;
			case 6:
				rgb = self->contentPalette[screen[screenOffset + (y >> 1 << 7) + (x >> 2)] >> ((~x & 3) << 1) & 3];
				break;
			case 7:
				rgb = self->contentPalette[RECOIL_GetNibble(screen, screenOffset + (y >> 1 << 8), x)];
				break;
			case 8:
				rgb = self->contentPalette[screen[screenOffset + (y >> interlaceMask << 8) + (x >> interlaceMask)]];
				break;
			case 10:
				rgb = RECOIL_DecodeMsxYjk(self, screen, screenOffset + (y >> interlaceMask << 8), x >> interlaceMask, 256, true);
				break;
			case 12:
				rgb = RECOIL_DecodeMsxYjk(self, screen, screenOffset + (y >> interlaceMask << 8), x >> interlaceMask, 256, false);
				break;
			default:
				abort();
			}
			self->pixels[y * self->width + x] = rgb;
		}
	}
}

static bool RECOIL_DecodeMsxSc(RECOIL *self, const char *filename, uint8_t const *content, int contentOffset, const char *upperExt, const char *lowerExt, int height, int mode)
{
	if (filename != NULL) {
		uint8_t interlace[54279];
		int interlaceLength = 7 + (height << (mode <= 6 ? 7 : 8));
		if (RECOIL_ReadCompanionFile(self, filename, upperExt, lowerExt, interlace, interlaceLength) == interlaceLength && interlace[0] == 254 && RECOIL_GetMsxHeader(interlace) >= interlaceLength - 8) {
			RECOIL_DecodeMsxScreen(self, content, contentOffset, interlace, height, mode, 1);
			return true;
		}
	}
	RECOIL_DecodeMsxScreen(self, content, contentOffset, NULL, height, mode, 0);
	return false;
}

static bool RECOIL_DecodeSc5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	int height = RECOIL_GetMsx128Height(self, content, contentLength);
	if (height <= 0)
		return false;
	RECOIL_SetMsx2Palette(self, content, 30343, contentLength);
	if (!RECOIL_DecodeMsxSc(self, filename, content, 7, "S15", "s15", height, 5) && contentLength == 32775)
		RECOIL_DecodeMsxSprites(self, content, 5, 30215, 30727);
	return true;
}

static void RECOIL_SetMsxCompanionPalette(RECOIL *self, const char *filename, const char *upperExt, const char *lowerExt)
{
	uint8_t palette[32];
	RECOIL_SetMsxPalette(self, RECOIL_ReadCompanionFile(self, filename, upperExt, lowerExt, palette, 32) == 32 ? palette : RECOIL_MSX2_DEFAULT_PALETTE, 0, 16);
}

static bool RECOIL_DecodeSr5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	int height = RECOIL_GetMsx128Height(self, content, contentLength);
	if (height <= 0)
		return false;
	RECOIL_SetMsxCompanionPalette(self, filename, "PL5", "pl5");
	RECOIL_SetSize(self, 256, height, RECOILResolution_MSX21X1, 1);
	RECOIL_DecodeNibbles(self, content, 7, 128);
	return true;
}

static bool RECOIL_DecodeMsx6(RECOIL *self, uint8_t const *content, int contentOffset)
{
	int height = RECOIL_GetOriginalHeight(self);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < self->width; x++) {
			int offset = y * self->width + x;
			int b = content[contentOffset + (offset >> 2)];
			RECOIL_SetScaledPixel(self, x, y, self->contentPalette[b >> ((~offset & 3) << 1) & 3]);
		}
	}
	return true;
}

static void RECOIL_SetMsx6DefaultPalette(RECOIL *self)
{
	self->contentPalette[0] = 0;
	self->contentPalette[1] = 2396708;
	self->contentPalette[2] = 2415396;
	self->contentPalette[3] = 7208813;
}

static bool RECOIL_DecodeSc6(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	int height = RECOIL_GetMsx128Height(self, content, contentLength);
	if (height <= 0)
		return false;
	if (contentLength >= 30351)
		RECOIL_SetMsxPalette(self, content, 30343, 4);
	else
		RECOIL_SetMsx6DefaultPalette(self);
	if (!RECOIL_DecodeMsxSc(self, filename, content, 7, "S16", "s16", height, 6) && contentLength == 32775)
		RECOIL_DecodeMsxSprites(self, content, 6, 30215, 30727);
	return true;
}

static void RECOIL_SetMsx6Palette(RECOIL *self, const char *filename)
{
	uint8_t palette[8];
	if (RECOIL_ReadCompanionFile(self, filename, "PL6", "pl6", palette, 8) == 8)
		RECOIL_SetMsxPalette(self, palette, 0, 4);
	else
		RECOIL_SetMsx6DefaultPalette(self);
}

static bool RECOIL_DecodeSr6(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	int height = RECOIL_GetMsx128Height(self, content, contentLength);
	if (height <= 0)
		return false;
	RECOIL_SetSize(self, 512, height << 1, RECOILResolution_MSX21X2, 1);
	RECOIL_SetMsx6Palette(self, filename);
	return RECOIL_DecodeMsx6(self, content, 7);
}

static bool RECOIL_DecodeGl6(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 5)
		return false;
	int width = content[0] | content[1] << 8;
	int height = content[2] | content[3] << 8;
	if (contentLength < 4 + ((width * height + 3) >> 2) || !RECOIL_SetSize(self, width, height << 1, RECOILResolution_MSX21X2, 1))
		return false;
	if (filename != NULL)
		RECOIL_SetMsx6Palette(self, filename);
	else {
		self->contentPalette[0] = 16777215;
		self->contentPalette[1] = 0;
		self->contentPalette[3] = self->contentPalette[2] = 0;
	}
	return RECOIL_DecodeMsx6(self, content, 4);
}

static uint8_t const *RECOIL_UnpackSr(uint8_t const *content, int contentLength, uint8_t *unpacked)
{
	if (contentLength < 7)
		return NULL;
	switch (content[0]) {
	case 254:
		if (contentLength < 54279 || RECOIL_GetMsxHeader(content) < 54271)
			return NULL;
		return content;
	case 253:
		if (7 + RECOIL_GetMsxHeader(content) != contentLength)
			return NULL;
		SrStream rle;
		SrStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 7;
		rle.base.base.base.contentLength = contentLength;
		RleStream_Unpack(&rle.base, unpacked, 7, 1, 54279);
		return unpacked;
	default:
		return NULL;
	}
}

static bool RECOIL_DecodeSc7(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 54279 || content[0] != 254 || RECOIL_GetMsxHeader(content) < 54271)
		return false;
	RECOIL_SetMsx2Palette(self, content, 64135, contentLength);
	if (!RECOIL_DecodeMsxSc(self, filename, content, 7, "S17", "s17", 212, 7) && contentLength == 64167)
		RECOIL_DecodeMsxSprites(self, content, 7, 64007, 61447);
	return true;
}

static bool RECOIL_DecodeSri(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength != 108544)
		return false;
	RECOIL_SetMsxCompanionPalette(self, filename, "PL7", "pl7");
	RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX21X1I, 1);
	self->frames = 2;
	RECOIL_DecodeNibbles(self, content, 0, 256);
	return true;
}

static bool RECOIL_DecodeSr7(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[54279] = { 0 };
	uint8_t const *source = RECOIL_UnpackSr(content, contentLength, unpacked);
	if (source == NULL)
		return false;
	RECOIL_SetMsxCompanionPalette(self, filename, "PL7", "pl7");
	RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX21X2, 1);
	RECOIL_DecodeNibbles(self, source, 7, 256);
	return true;
}

static bool RECOIL_DecodeGl16(RECOIL *self, const char *filename, uint8_t const *content, int contentLength, RECOILResolution resolution, const char *upperExt, const char *lowerExt)
{
	if (contentLength < 5)
		return false;
	int width = content[0] | content[1] << 8;
	int height = content[2] | content[3] << 8;
	if (contentLength < 4 + ((width * height + 1) >> 1) || !RECOIL_SetScaledSize(self, width, height, resolution))
		return false;
	RECOIL_SetMsxCompanionPalette(self, filename, upperExt, lowerExt);
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			RECOIL_SetScaledPixel(self, x, y, self->contentPalette[RECOIL_GetNibble(content, 4, y * width + x)]);
	return true;
}

static bool RECOIL_DecodeGl5(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	return RECOIL_DecodeGl16(self, filename, content, contentLength, RECOILResolution_MSX21X1, "PL5", "pl5");
}

static bool RECOIL_DecodeGl7(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	return RECOIL_DecodeGl16(self, filename, content, contentLength, RECOILResolution_MSX21X2, "PL7", "pl7");
}

static void RECOIL_SetSc8Palette(RECOIL *self)
{
	for (int c = 0; c < 256; c++) {
		static const uint8_t BLUES[4] = { 0, 2, 4, 7 };
		int rgb = (c & 28) << 14 | (c & 224) << 3 | BLUES[c & 3];
		self->contentPalette[c] = rgb << 5 | rgb << 2 | (rgb >> 1 & 197379);
	}
}

static bool RECOIL_DecodeSc8(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[54279] = { 0 };
	uint8_t const *source = RECOIL_UnpackSr(content, contentLength, unpacked);
	if (source == NULL)
		return false;
	RECOIL_SetSc8Palette(self);
	if (!RECOIL_DecodeMsxSc(self, filename, source, 7, "S18", "s18", 212, 8) && contentLength == 64167) {
		static const uint8_t SPRITE_PALETTE[32] = { 0, 0, 2, 0, 48, 0, 50, 0, 0, 3, 2, 3, 48, 3, 50, 3,
			114, 4, 7, 0, 112, 0, 119, 0, 0, 7, 7, 7, 112, 7, 119, 7 };
		RECOIL_SetMsxPalette(self, SPRITE_PALETTE, 0, 16);
		RECOIL_DecodeMsxSprites(self, content, 8, 64007, 61447);
	}
	return true;
}

static bool RECOIL_DecodeGl8(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 5)
		return false;
	int width = content[0] | content[1] << 8;
	int height = content[2] | content[3] << 8;
	if (contentLength != 4 + width * height || !RECOIL_SetSize(self, width, height, RECOILResolution_MSX21X1, 1))
		return false;
	RECOIL_SetSc8Palette(self);
	RECOIL_DecodeBytes(self, content, 4);
	return true;
}

static bool RECOIL_DecodePct(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 384 || (!RECOIL_IsStringAt(content, 0, "DYNAMIC") && !RECOIL_IsStringAt(content, 0, "E U R O")) || !RECOIL_IsStringAt(content, 7, " PUBLISHER "))
		return false;
	int height;
	int contentOffset;
	if (RECOIL_IsStringAt(content, 18, "SCREEN")) {
		height = 704;
		contentOffset = 384;
	}
	else if (RECOIL_IsStringAt(content, 18, "FONT")) {
		height = 160;
		contentOffset = 512;
	}
	else
		return false;
	RECOIL_SetSize(self, 512, height << 1, RECOILResolution_MSX21X2, 1);
	CciStream rle;
	CciStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset;
	rle.base.base.base.contentLength = contentLength;
	for (int y = 0; y < height; y++) {
		int b = 0;
		for (int x = 0; x < 512; x++) {
			if ((x & 7) == 0) {
				b = RleStream_ReadRle(&rle.base);
				if (b < 0)
					return false;
			}
			int offset = (y << 10) + x;
			self->pixels[offset + 512] = self->pixels[offset] = (b >> ((x ^ 3) & 7) & 1) == 0 ? 16777215 : 0;
		}
	}
	return true;
}

static bool RECOIL_DecodeDdGraph(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 4)
		return false;
	int width = content[0];
	if (width == 0 || width > 128)
		return false;
	int height = content[1];
	if (height == 0 || height > 212)
		return false;
	int verbatimLines = content[2];
	if (verbatimLines == 0 || verbatimLines > height)
		return false;
	ZimStream stream;
	stream.base.content = content;
	stream.base.contentOffset = 3;
	stream.base.contentLength = contentLength;
	int flagsOffset = 64;
	uint8_t unpacked[27136];
	int unpackedOffset = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (flagsOffset >= 64) {
				if (!ZimStream_UnpackFlags2(&stream))
					return false;
				flagsOffset = 0;
			}
			int b = ZimStream_ReadUnpacked(&stream, stream.flags2, flagsOffset++);
			if (b < 0)
				return false;
			if (y >= verbatimLines)
				b ^= unpacked[unpackedOffset - width];
			unpacked[unpackedOffset++] = (uint8_t) b;
		}
	}
	if (stream.base.contentOffset != stream.base.contentLength)
		return false;
	RECOIL_SetMsxCompanionPalette(self, filename, "PL5", "pl5");
	RECOIL_SetSize(self, width << 1, height, RECOILResolution_MSX21X1, 1);
	RECOIL_DecodeNibbles(self, unpacked, 0, width);
	return true;
}

static void RECOIL_DecodeMsxYjkScreen(RECOIL *self, uint8_t const *content, int contentOffset, bool usePalette)
{
	int width = RECOIL_GetOriginalWidth(self);
	for (int y = 0; y < self->height; y++)
		for (int x = 0; x < width; x++)
			RECOIL_SetScaledPixel(self, x, y, RECOIL_DecodeMsxYjk(self, content, contentOffset + y * width, x, width, usePalette));
}

static void RECOIL_DecodeSccSca(RECOIL *self, const char *filename, uint8_t const *content, int contentLength, int height, bool usePalette)
{
	if (!RECOIL_DecodeMsxSc(self, filename, content, 7, usePalette ? "S1A" : "S1C", usePalette ? "s1a" : "s1c", height, usePalette ? 10 : 12) && contentLength == 64167 && content[0] == 254) {
		RECOIL_SetMsxPalette(self, content, 64135, 16);
		RECOIL_DecodeMsxSprites(self, content, 12, 64007, 61447);
	}
}

static bool RECOIL_DecodeScc(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	int height;
	if (contentLength >= 49159 && content[0] == 254 && RECOIL_GetMsxHeader(content) == 49151)
		height = 192;
	else {
		uint8_t unpacked[54279] = { 0 };
		uint8_t const *source = RECOIL_UnpackSr(content, contentLength, unpacked);
		if (source == NULL)
			return false;
		content = source;
		height = 212;
	}
	RECOIL_DecodeSccSca(self, filename, content, contentLength, height, false);
	return true;
}

static bool RECOIL_DecodeSca(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 64167 || content[0] != 254 || RECOIL_GetMsxHeader(content) < 54271)
		return false;
	RECOIL_SetMsxPalette(self, content, 64135, 16);
	RECOIL_DecodeSccSca(self, filename, content, contentLength, 212, true);
	return true;
}

static bool RECOIL_DecodeGlYjk(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 8)
		return false;
	int width = content[0] | content[1] << 8;
	int height = content[2] | content[3] << 8;
	if (contentLength != 4 + width * height || !RECOIL_SetSize(self, width, height, RECOILResolution_MSX2_PLUS1X1, 1))
		return false;
	if (filename != NULL)
		RECOIL_SetMsxCompanionPalette(self, filename, "PLA", "pla");
	RECOIL_DecodeMsxYjkScreen(self, content, 4, filename != NULL);
	return true;
}

static bool RECOIL_SetG9bPalette(RECOIL *self, uint8_t const *content, int colors)
{
	for (int c = 0; c < colors; c++) {
		int offset = 16 + c * 3;
		int rgb = content[offset] << 16 | content[offset + 1] << 8 | content[offset + 2];
		if ((rgb & 14737632) != 0)
			return false;
		self->contentPalette[c] = rgb << 3 | (rgb >> 2 & 460551);
	}
	return true;
}

static void RECOIL_DecodeG9bUnpacked(RECOIL *self, uint8_t const *content, int depth, int headerLength)
{
	int pixelsLength;
	switch (depth) {
	case 2:
		RECOIL_DecodeMsx6(self, content, 28);
		break;
	case 4:
		RECOIL_DecodeNibbles(self, content, 64, (self->width + 1) >> 1);
		break;
	case 8:
		RECOIL_DecodeBytes(self, content, headerLength);
		break;
	case 0:
		RECOIL_DecodeMsxYjkScreen(self, content, 16, false);
		break;
	case 1:
		pixelsLength = self->width * self->height;
		for (int i = 0; i < pixelsLength; i++) {
			int y = content[16 + i] >> 3;
			int x = 16 + (i & ~3);
			int v = (content[x] & 7) | (content[x + 1] & 7) << 3;
			int u = (content[x + 2] & 7) | (content[x + 3] & 7) << 3;
			u -= (u & 32) << 1;
			v -= (v & 32) << 1;
			int r = RECOIL_ClampU5(y + u);
			int g = RECOIL_ClampU5((((5 * y - v) >> 1) - u) >> 1);
			int b = RECOIL_ClampU5(y + v);
			int rgb = r << 16 | g << 8 | b;
			self->pixels[i] = rgb << 3 | (rgb >> 2 & 460551);
		}
		break;
	case 16:
		pixelsLength = self->width * self->height;
		for (int i = 0; i < pixelsLength; i++) {
			int c = content[16 + (i << 1)] | content[17 + (i << 1)] << 8;
			int rgb = (c & 992) << 14 | (c & 31744) << 1 | (c & 31) << 3;
			self->pixels[i] = rgb | (rgb >> 5 & 460551);
		}
		break;
	default:
		abort();
	}
}

static bool RECOIL_DecodeG9b(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 17 || content[0] != 'G' || content[1] != '9' || content[2] != 'B' || content[3] != 11 || content[4] != 0)
		return false;
	int depth = content[5];
	int headerLength = 16 + content[7] * 3;
	int width = content[8] | content[9] << 8;
	int height = content[10] | content[11] << 8;
	if (contentLength <= headerLength || !RECOIL_SetSize(self, width, height, RECOILResolution_MSX_V99901X1, 1))
		return false;
	int unpackedLength = headerLength + ((width * depth + 7) >> 3) * height;
	switch (depth) {
	case 2:
		if (content[7] != 4 || !RECOIL_SetG9bPalette(self, content, 4))
			return false;
		break;
	case 4:
		if (content[7] != 16 || !RECOIL_SetG9bPalette(self, content, 16))
			return false;
		break;
	case 8:
		switch (content[7]) {
		case 0:
			if ((width & 3) != 0)
				return false;
			switch (content[6]) {
			case 64:
				RECOIL_SetSc8Palette(self);
				break;
			case 128:
				depth = 0;
				break;
			case 192:
				depth = 1;
				break;
			default:
				return false;
			}
			break;
		case 64:
			if (!RECOIL_SetG9bPalette(self, content, 64))
				return false;
			memset(self->contentPalette + 64, 0, 192 * sizeof(int));
			break;
		default:
			return false;
		}
		break;
	case 16:
		break;
	default:
		return false;
	}
	switch (content[12]) {
	case 0:
		if (contentLength != unpackedLength)
			return false;
		RECOIL_DecodeG9bUnpacked(self, content, depth, headerLength);
		return true;
	case 1:
		;
		uint8_t *unpacked = (uint8_t *) malloc(unpackedLength * sizeof(uint8_t));
		G9bStream s;
		G9bStream_Construct(&s);
		s.base.base.content = content;
		s.base.base.contentLength = contentLength;
		bool ok = G9bStream_Unpack(&s, unpacked, headerLength, unpackedLength);
		if (ok)
			RECOIL_DecodeG9bUnpacked(self, unpacked, depth, headerLength);
		free(unpacked);
		return ok;
	default:
		return false;
	}
}

static bool RECOIL_UnpackMif(RECOIL *self, uint8_t const *content, int contentLength, uint8_t *unpacked, int unpackedLength, bool palette)
{
	BitStream s;
	BitStream_Construct(&s);
	s.base.content = content;
	s.base.contentOffset = palette ? 34 : 2;
	s.base.contentLength = contentLength;
	int offsets[5461];
	int codes = 0;
	int codeBits = 2;
	for (int unpackedOffset = 0; unpackedOffset < unpackedLength;) {
		if (codes >= 5461)
			return false;
		offsets[codes++] = unpackedOffset;
		if (codes >> codeBits != 0)
			codeBits++;
		switch (s.vtbl->readBit(&s)) {
		case 0:
			;
			int code = BitStream_ReadBits(&s, codeBits);
			if (code < 0 || code >= codes)
				return false;
			if (code == codes - 1) {
				codes = 0;
				codeBits = 2;
				break;
			}
			int sourceOffset = offsets[code];
			int endOffset = offsets[code + 1];
			if (unpackedOffset + endOffset - sourceOffset >= unpackedLength)
				return false;
			do
				unpacked[unpackedOffset++] = unpacked[sourceOffset++];
			while (sourceOffset <= endOffset);
			break;
		case 1:
			;
			int b = BitStream_ReadBits(&s, 8);
			if (b < 0)
				return false;
			unpacked[unpackedOffset++] = (uint8_t) b;
			break;
		default:
			return false;
		}
	}
	if (s.vtbl->readBit(&s) != 0 || BitStream_ReadBits(&s, codeBits) <= codes || s.base.contentOffset != contentLength)
		return false;
	if (palette)
		RECOIL_SetMsxPalette(self, content, 2, 16);
	return true;
}

static bool RECOIL_DecodeMif(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 35)
		return false;
	uint8_t unpacked[108544];
	switch (content[0]) {
	case 0:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 27136, true))
			return false;
		RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX21X1, 1);
		RECOIL_DecodeNibbles(self, unpacked, 0, 128);
		return true;
	case 1:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 27136, true))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX21X2, 1);
		RECOIL_DecodeMsx6(self, unpacked, 0);
		return true;
	case 2:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 54272, true))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX21X2, 1);
		RECOIL_DecodeNibbles(self, unpacked, 0, 256);
		return true;
	case 3:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 54272, false))
			return false;
		RECOIL_SetSc8Palette(self);
		RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX21X1, 1);
		RECOIL_DecodeBytes(self, unpacked, 0);
		return true;
	case 4:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 54272, true))
			return false;
		RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX2_PLUS1X1, 1);
		RECOIL_DecodeMsxYjkScreen(self, unpacked, 0, true);
		return true;
	case 5:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 54272, false))
			return false;
		RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX2_PLUS1X1, 1);
		RECOIL_DecodeMsxYjkScreen(self, unpacked, 0, false);
		return true;
	case 8:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 14336, true))
			return false;
		RECOIL_DecodeSc2Sc4(self, unpacked, 0, RECOILResolution_MSX21X1);
		return true;
	case 9:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 1536, true))
			return false;
		RECOIL_DecodeSc3Screen(self, unpacked, 0, false);
		return true;
	case 16:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 54272, true))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX22X1I, 1);
		self->frames = 2;
		RECOIL_DecodeNibbles(self, unpacked, 0, 128);
		return true;
	case 17:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 54272, true))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX21X1I, 1);
		self->frames = 2;
		RECOIL_DecodeMsx6(self, unpacked, 0);
		return true;
	case 18:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 108544, true))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX21X1I, 1);
		self->frames = 2;
		RECOIL_DecodeNibbles(self, unpacked, 0, 256);
		return true;
	case 19:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 108544, false))
			return false;
		RECOIL_SetSc8Palette(self);
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX22X1I, 1);
		self->frames = 2;
		RECOIL_DecodeBytes(self, unpacked, 0);
		return true;
	case 20:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 108544, true))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX2_PLUS2X1I, 1);
		self->frames = 2;
		RECOIL_DecodeMsxYjkScreen(self, unpacked, 0, true);
		return true;
	case 21:
		if (!RECOIL_UnpackMif(self, content, contentLength, unpacked, 108544, false))
			return false;
		RECOIL_SetSize(self, 512, 424, RECOILResolution_MSX2_PLUS2X1I, 1);
		self->frames = 2;
		RECOIL_DecodeMsxYjkScreen(self, unpacked, 0, false);
		return true;
	default:
		return false;
	}
}

static int RECOIL_GetMigMode(int reg0, int reg1, int reg19, int length)
{
	return (reg0 & 14) | (reg1 & 24) << 1 | (reg19 & 24) << 3 | length << 8;
}

static bool RECOIL_DecodeMig(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 16 || !RECOIL_IsStringAt(content, 0, "MSXMIG") || RECOIL_Get32LittleEndian(content, 6) != contentLength - 6)
		return false;
	uint8_t unpacked[108800];
	MigStream s;
	MigStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	int unpackedLength = MigStream_Unpack(&s, unpacked);
	int colors = 0;
	uint8_t registers[256] = { 0 };
	for (int unpackedOffset = 0; unpackedOffset < unpackedLength;) {
		switch (unpacked[unpackedOffset]) {
		case 0:
			if (unpackedOffset + 1 >= unpackedLength)
				return false;
			int c = unpacked[unpackedOffset + 1];
			if (unpackedOffset + 2 + c * 3 > unpackedLength)
				return false;
			for (int i = 0; i < c; i++) {
				int offset = unpackedOffset + 2 + i * 3;
				int r = unpacked[offset];
				int m = unpacked[offset + 2];
				registers[r] = (uint8_t) ((registers[r] & ~m) | (unpacked[offset + 1] & m));
			}
			unpackedOffset += 2 + c * 3;
			break;
		case 1:
			if (unpackedOffset + 2 >= unpackedLength || unpacked[unpackedOffset + 1] != 0)
				return false;
			colors = unpacked[unpackedOffset + 2];
			if (unpackedOffset + 3 + (colors << 1) > unpackedLength)
				return false;
			RECOIL_SetMsxPalette(self, unpacked, unpackedOffset + 3, colors);
			unpackedOffset += 3 + (colors << 1);
			break;
		case 2:
			if (unpackedOffset + 7 >= unpackedLength || unpacked[unpackedOffset + 1] != 0 || unpacked[unpackedOffset + 2] != 0 || unpacked[unpackedOffset + 3] != 0 || unpacked[unpackedOffset + 4] != 0 || unpacked[unpackedOffset + 6] != 0)
				return false;
			int length = unpacked[unpackedOffset + 5];
			unpackedOffset += 7;
			int interlaceMask;
			switch (registers[9] & 12) {
			case 0:
				if (unpackedOffset + (length << 8) + 1 != unpackedLength)
					return false;
				interlaceMask = 0;
				break;
			case 12:
				if (unpackedOffset + (length << 9) + 7 + 1 != unpackedLength || unpacked[unpackedOffset + (length << 8)] != 2 || unpacked[unpackedOffset + (length << 8) + 1] != 0 || unpacked[unpackedOffset + (length << 8) + 4] != 0 || unpacked[unpackedOffset + (length << 8) + 5] != length || unpacked[unpackedOffset + (length << 8) + 6] != 0)
					return false;
				interlaceMask = 1;
				break;
			default:
				return false;
			}
			int mode;
			switch (RECOIL_GetMigMode(registers[0], registers[1], registers[25], length)) {
			case 14338:
				if (colors < 16 || interlaceMask != 0)
					return false;
				RECOIL_DecodeSc2Sc4(self, unpacked, unpackedOffset, RECOILResolution_MSX21X1);
				return true;
			case 1552:
				if (colors < 16 || interlaceMask != 0)
					return false;
				RECOIL_DecodeSc3Screen(self, unpacked, unpackedOffset, false);
				return true;
			case 27142:
				if (colors < 16)
					return false;
				mode = 5;
				break;
			case 27144:
				if (colors < 4)
					return false;
				mode = 6;
				break;
			case 54282:
				if (colors < 16)
					return false;
				mode = 7;
				break;
			case 54286:
				RECOIL_SetSc8Palette(self);
				mode = 8;
				break;
			case 54478:
				if (colors < 16)
					return false;
				mode = 10;
				break;
			case 54350:
				mode = 12;
				break;
			default:
				return false;
			}
			RECOIL_DecodeMsxScreen(self, unpacked, unpackedOffset, unpacked, 212, mode, interlaceMask);
			return true;
		default:
			return false;
		}
	}
	return false;
}

static bool RECOIL_DecodeHgr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8184)
		return false;
	RECOIL_SetSize(self, 280, 192, RECOILResolution_APPLE_I_I1X1, 1);
	for (int y = 0; y < 192; y++) {
		int lineOffset = (y & 7) << 10 | (y & 56) << 4 | (y >> 6) * 40;
		for (int x = 0; x < 280; x++) {
			int c = content[lineOffset + x / 7] >> x % 7 & 1;
			if (c != 0)
				c = 16777215;
			self->pixels[y * 280 + x] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeAppleIIDhr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 16384)
		return false;
	RECOIL_SetSize(self, 560, 384, RECOILResolution_APPLE_I_IE1X2, 1);
	for (int y = 0; y < 192; y++) {
		int lineOffset = (y & 7) << 10 | (y & 56) << 4 | (y >> 6) * 40;
		for (int x = 0; x < 560; x++) {
			int b = x / 7;
			int c = content[((b & 1) << 13) + lineOffset + (b >> 1)] >> x % 7 & 1;
			if (c != 0)
				c = 16777215;
			int pixelsOffset = y * 1120 + x;
			self->pixels[pixelsOffset + 560] = self->pixels[pixelsOffset] = c;
		}
	}
	return true;
}

static void RECOIL_SetAppleIIGSPalette(RECOIL *self, uint8_t const *content, int contentOffset, int reverse)
{
	for (int c = 0; c < 16; c++) {
		int offset = contentOffset + ((c ^ reverse) << 1);
		int gb = content[offset];
		int r = content[offset + 1] & 15;
		int g = gb >> 4;
		int b = gb & 15;
		int rgb = r << 16 | g << 8 | b;
		rgb |= rgb << 4;
		self->contentPalette[c] = rgb;
	}
}

static void RECOIL_DecodeShrLine(RECOIL *self, uint8_t const *content, int y)
{
	for (int x = 0; x < 320; x++)
		self->pixels[y * 320 + x] = self->contentPalette[RECOIL_GetNibble(content, y * 160, x)];
}

static bool RECOIL_DecodeAppleIIShrUnpacked(RECOIL *self, uint8_t const *content)
{
	RECOIL_SetSize(self, 320, 200, RECOILResolution_APPLE_I_I_G_S1X1, 1);
	for (int y = 0; y < 200; y++) {
		RECOIL_SetAppleIIGSPalette(self, content, 32256 + ((content[32000 + y] & 15) << 5), 0);
		RECOIL_DecodeShrLine(self, content, y);
	}
	return true;
}

static bool RECOIL_DecodeAppleIIShr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 32768)
		return RECOIL_DecodeAppleIIShrUnpacked(self, content);
	uint8_t unpacked[32768];
	PackBytesStream stream;
	PackBytesStream_Construct(&stream);
	stream.base.content = content;
	stream.base.contentOffset = 0;
	stream.base.contentLength = contentLength;
	for (int unpackedOffset = 0; unpackedOffset < 32768; unpackedOffset++) {
		int b = PackBytesStream_ReadUnpacked(&stream);
		if (b < 0)
			return false;
		unpacked[unpackedOffset] = (uint8_t) b;
	}
	return PackBytesStream_ReadUnpacked(&stream) < 0 && RECOIL_DecodeAppleIIShrUnpacked(self, unpacked);
}

static bool RECOIL_DecodeSh3(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 38400)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_APPLE_I_I_G_S1X1, 1);
	for (int y = 0; y < 200; y++) {
		RECOIL_SetAppleIIGSPalette(self, content, 32000 + (y << 5), 15);
		RECOIL_DecodeShrLine(self, content, y);
	}
	return true;
}

static void RECOIL_DrawSprByte(RECOIL *self, int x1, int y, int b)
{
	for (int x = 0; x < 8; x++) {
		if ((b >> (7 - x) & 1) != 0)
			self->pixels[y * 320 + x1 + x] = 16777215;
	}
}

static bool RECOIL_DecodeAppleSpr(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 320, 200, RECOILResolution_APPLE_I_I1X1, 1);
	memset(self->pixels, 0, 64000 * sizeof(int));
	AppleSprStream s;
	s.base.content = content;
	s.base.contentOffset = 0;
	s.base.contentLength = contentLength;
	for (;;) {
		int cols = AppleSprStream_ReadSprInt(&s);
		if (cols < 0)
			return false;
		int rows = AppleSprStream_ReadSprInt(&s);
		if (rows < 0)
			return false;
		int order = AppleSprStream_ReadSprInt(&s);
		if (order < 0)
			return false;
		int x = AppleSprStream_ReadSprInt(&s);
		if (x < 0)
			return false;
		int y = AppleSprStream_ReadSprInt(&s);
		if (y < 0)
			return false;
		if (rows == 0)
			break;
		if (cols == 0 || x + (cols << 3) > 320 || y + rows > 200)
			return false;
		if (order == 2) {
			for (int col = 0; col < cols; col++) {
				for (int row = 0; row < rows; row++) {
					int b = AppleSprStream_ReadSprInt(&s);
					if (b < 0)
						return false;
					RECOIL_DrawSprByte(self, x + (col << 3), y + row, b);
				}
			}
		}
		else {
			for (int row = 0; row < rows; row++) {
				for (int col = 0; col < cols; col++) {
					int b = AppleSprStream_ReadSprInt(&s);
					if (b < 0)
						return false;
					RECOIL_DrawSprByte(self, x + (col << 3), y + row, b);
				}
			}
		}
	}
	return true;
}

static bool RECOIL_DecodePackBytes(RECOIL *self, PackBytesStream *stream, int pixelsOffset, int unpackedBytes)
{
	for (int x = 0; x < unpackedBytes; x++) {
		int b = PackBytesStream_ReadUnpacked(stream);
		if (b < 0)
			return false;
		if (self->resolution == RECOILResolution_APPLE_I_I_G_S1X2) {
			int offset = (pixelsOffset << 1) + (x << 2);
			self->pixels[offset + self->width] = self->pixels[offset] = self->contentPalette[8 + (b >> 6)];
			self->pixels[offset + self->width + 1] = self->pixels[offset + 1] = self->contentPalette[12 + (b >> 4 & 3)];
			self->pixels[offset + self->width + 2] = self->pixels[offset + 2] = self->contentPalette[b >> 2 & 3];
			self->pixels[offset + self->width + 3] = self->pixels[offset + 3] = self->contentPalette[4 + (b & 3)];
		}
		else {
			self->pixels[pixelsOffset + (x << 1)] = self->contentPalette[b >> 4];
			self->pixels[pixelsOffset + (x << 1) + 1] = self->contentPalette[b & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodePaintworks(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1041)
		return false;
	RECOIL_SetSize(self, 320, 396, RECOILResolution_APPLE_I_I_G_S1X1, 1);
	RECOIL_SetAppleIIGSPalette(self, content, 0, 0);
	PackBytesStream stream;
	PackBytesStream_Construct(&stream);
	stream.base.content = content;
	stream.base.contentOffset = 546;
	stream.base.contentLength = contentLength;
	return RECOIL_DecodePackBytes(self, &stream, 0, 63360);
}

static bool RECOIL_Decode3201(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 6654 || content[0] != 193 || content[1] != 208 || content[2] != 208 || content[3] != 0)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_APPLE_I_I_G_S1X1, 1);
	PackBytesStream stream;
	PackBytesStream_Construct(&stream);
	stream.base.content = content;
	stream.base.contentOffset = 6404;
	stream.base.contentLength = contentLength;
	for (int y = 0; y < 200; y++) {
		RECOIL_SetAppleIIGSPalette(self, content, 4 + (y << 5), 15);
		if (!RECOIL_DecodePackBytes(self, &stream, y * 320, 160))
			return false;
	}
	return true;
}

static bool RECOIL_DecodeApfShr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1249 || content[4] != 4 || !RECOIL_IsStringAt(content, 5, "MAIN") || content[14] != 0)
		return false;
	int paletteCount = content[13];
	if (paletteCount > 16)
		return false;
	int dirOffset = 17 + (paletteCount << 5);
	if (dirOffset >= contentLength)
		return false;
	int mode = content[9] & 240;
	int width = content[11] | content[12] << 8;
	int height = content[dirOffset - 2] | content[dirOffset - 1] << 8;
	int bytesPerLine;
	switch (mode) {
	case 0:
		if ((width & 1) != 0 || !RECOIL_SetSize(self, width, height, RECOILResolution_APPLE_I_I_G_S1X1, 1))
			return false;
		bytesPerLine = width >> 1;
		break;
	case 128:
		if ((width & 3) != 0 || !RECOIL_SetSize(self, width, height << 1, RECOILResolution_APPLE_I_I_G_S1X2, 1))
			return false;
		bytesPerLine = width >> 2;
		break;
	default:
		return false;
	}
	int multipalOffset = -1;
	int contentOffset = 0;
	if (height == 200) {
		for (int chunkLength = RECOIL_Get32LittleEndian(content, 0);;) {
			if (chunkLength <= 0)
				return false;
			contentOffset += chunkLength;
			if (contentOffset < 0 || contentOffset > contentLength - 6415)
				break;
			chunkLength = RECOIL_Get32LittleEndian(content, contentOffset);
			if (chunkLength == 6415 && content[contentOffset + 4] == 8 && RECOIL_IsStringAt(content, contentOffset + 5, "MULTIPAL") && content[contentOffset + 13] == 200 && content[contentOffset + 14] == 0) {
				multipalOffset = contentOffset + 15;
				break;
			}
		}
	}
	contentOffset = dirOffset + (height << 2);
	if (contentOffset >= contentLength)
		return false;
	PackBytesStream stream;
	PackBytesStream_Construct(&stream);
	stream.base.content = content;
	stream.base.contentOffset = contentOffset;
	stream.base.contentLength = contentLength;
	for (int y = 0; y < height; y++) {
		if (multipalOffset >= 0)
			RECOIL_SetAppleIIGSPalette(self, content, multipalOffset + (y << 5), 0);
		else {
			int lineMode = content[dirOffset + (y << 2) + 2];
			int palette = lineMode & 15;
			if ((lineMode & 240) != mode || palette >= paletteCount || content[dirOffset + (y << 2) + 3] != 0)
				return false;
			RECOIL_SetAppleIIGSPalette(self, content, 15 + (palette << 5), 0);
		}
		int nextLineOffset = stream.base.contentOffset + content[dirOffset + (y << 2)] + (content[dirOffset + (y << 2) + 1] << 8);
		if (!RECOIL_DecodePackBytes(self, &stream, y * width, bytesPerLine))
			return false;
		stream.base.contentOffset = nextLineOffset;
	}
	return true;
}

static int RECOIL_GetSamCoupeColor(int c)
{
	int rgb = 0;
	if ((c & 1) != 0)
		rgb |= 73;
	if ((c & 2) != 0)
		rgb |= 4784128;
	if ((c & 4) != 0)
		rgb |= 18688;
	if ((c & 8) != 0)
		rgb |= 2368548;
	if ((c & 16) != 0)
		rgb |= 146;
	if ((c & 32) != 0)
		rgb |= 9568256;
	if ((c & 64) != 0)
		rgb |= 37376;
	return rgb;
}

static void RECOIL_SetSamCoupePalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors)
{
	for (int i = 0; i < colors; i++)
		self->contentPalette[i] = RECOIL_GetSamCoupeColor(content[contentOffset + i]);
}

static int RECOIL_GetSamCoupeMode12Color(uint8_t const *content, int bitmapOffset, int attributeOffset, int x)
{
	int a = content[attributeOffset + (x >> 3)];
	return (a >> 3 & 8) | (((content[bitmapOffset + (x >> 3)] >> (~x & 7) & 1) == 0 ? a >> 3 : a) & 7);
}

static int RECOIL_DecodeSamCoupeScreen(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int mode, int interruptOffset)
{
	if (interruptOffset >= contentLength)
		return -1;
	RECOIL_SetSamCoupePalette(self, content, interruptOffset - 40, 16);
	int width = RECOIL_GetOriginalWidth(self);
	for (int y = 0; y < 192; y++) {
		while (interruptOffset + 3 < contentLength && y == content[interruptOffset] + 1) {
			int c = content[interruptOffset + 1];
			if (c > 15)
				return -1;
			self->contentPalette[c] = RECOIL_GetSamCoupeColor(content[interruptOffset + 2]);
			interruptOffset += 4;
		}
		int row = y << (self->frames - 1);
		if (contentOffset != 0)
			row++;
		for (int x = 0; x < width; x++) {
			int c;
			switch (mode) {
			case 1:
				c = RECOIL_GetSamCoupeMode12Color(content, RECOIL_GetZxLineOffset(y), 6144 + (y >> 3 << 5), x);
				break;
			case 2:
				c = RECOIL_GetSamCoupeMode12Color(content, y << 5, 8192 + (y << 5), x);
				break;
			case 3:
				c = content[y << 7 | x >> 2] >> ((~x & 3) << 1);
				c = (c & 1) << 1 | (c >> 1 & 1);
				break;
			case 4:
				c = RECOIL_GetNibble(content, contentOffset + (y << 7), x);
				break;
			default:
				abort();
			}
			RECOIL_SetScaledPixel(self, x, row, self->contentPalette[c]);
		}
	}
	if (interruptOffset >= contentLength || content[interruptOffset] != 255)
		return -1;
	return interruptOffset + 1;
}

static bool RECOIL_DecodeSs1(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1, 1);
	return RECOIL_DecodeSamCoupeScreen(self, content, 0, contentLength, 1, 6952) == contentLength;
}

static bool RECOIL_DecodeSs2(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1, 1);
	return RECOIL_DecodeSamCoupeScreen(self, content, 0, contentLength, 2, 14376) == contentLength;
}

static bool RECOIL_DecodeSs3(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 512, 384, RECOILResolution_SAM_COUPE1X2, 1);
	return RECOIL_DecodeSamCoupeScreen(self, content, 0, contentLength, 3, 24616) == contentLength;
}

static bool RECOIL_DecodeSs4(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1, 1);
	return RECOIL_DecodeSamCoupeScreen(self, content, 0, contentLength, 4, 24616) == contentLength;
}

static bool RECOIL_DecodeLce(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 512, 384, RECOILResolution_SAM_COUPE2X1I, 1);
	self->frames = 2;
	int contentOffset = RECOIL_DecodeSamCoupeScreen(self, content, 0, contentLength, 4, 24616);
	if (contentOffset < 0)
		return false;
	return RECOIL_DecodeSamCoupeScreen(self, content, contentOffset, contentLength, 4, contentOffset + 24616) == contentLength;
}

static void RECOIL_SetSamCoupeAttrPalette(RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 64; i++)
		self->contentPalette[i] = RECOIL_GetSamCoupeColor(content[contentOffset + (i >> 1 & 8) + (i & 7)]);
}

static bool RECOIL_DecodeSsx(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 6928:
		RECOIL_SetSamCoupeAttrPalette(self, content, 6912);
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1, 1);
		RECOIL_DecodeZx(self, content, 0, 6144, 3, 0);
		return true;
	case 12304:
		RECOIL_SetSamCoupeAttrPalette(self, content, 12288);
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1, 1);
		RECOIL_DecodeZx(self, content, -1, 6144, 0, 0);
		return true;
	case 24580:
		RECOIL_SetSamCoupePalette(self, content, 24576, 4);
		RECOIL_SetSize(self, 512, 384, RECOILResolution_SAM_COUPE1X2, 1);
		for (int y = 0; y < 192; y++) {
			for (int x = 0; x < 512; x++) {
				int c = content[y << 7 | x >> 2] >> ((~x & 3) << 1) & 3;
				self->pixels[(y << 10) + x + 512] = self->pixels[(y << 10) + x] = self->contentPalette[c];
			}
		}
		return true;
	case 24592:
		RECOIL_SetSamCoupePalette(self, content, 24576, 16);
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1, 1);
		RECOIL_DecodeNibbles(self, content, 0, 128);
		return true;
	case 98304:
		for (int c = 0; c < 128; c++)
			self->contentPalette[c] = RECOIL_GetSamCoupeColor(c);
		RECOIL_SetSize(self, 512, 384, RECOILResolution_SAM_COUPE1X2, 1);
		for (int y = 0; y < 192; y++) {
			for (int x = 0; x < 512; x++) {
				int c = content[(y << 9) + x];
				if (c >= 128)
					return false;
				self->pixels[(y << 10) + x + 512] = self->pixels[(y << 10) + x] = self->contentPalette[c];
			}
		}
		return true;
	default:
		return false;
	}
}

static int RECOIL_GetX68KColor(int color)
{
	int rgb = (color & 1984) << 13 | (color & 63488) | (color & 62) << 2;
	if ((color & 1) != 0)
		rgb |= 263172;
	return rgb | (rgb >> 6 & 197379);
}

static int RECOIL_RestrictPlatformColor(const RECOIL *self, int rgb, int colors)
{
	switch (self->resolution) {
	case RECOILResolution_FM_TOWNS1X1:
		return (rgb & 16316664) | (rgb >> 5 & 460551);
	case RECOILResolution_MSX21X1:
	case RECOILResolution_MSX21X2:
	case RECOILResolution_MSX21X1I:
	case RECOILResolution_MSX22X1I:
	case RECOILResolution_MSX2_PLUS1X1:
	case RECOILResolution_MSX2_PLUS2X1I:
		rgb &= 14737632;
		return rgb | rgb >> 3 | (rgb >> 6 & 197379);
	case RECOILResolution_PC881X2:
		rgb &= 15790320;
		return rgb | rgb >> 4;
	case RECOILResolution_PC88_VA1X1:
		return (rgb & 16317688) | (rgb >> 5 & 458759) | (rgb >> 6 & 768);
	case RECOILResolution_PC981X1:
		if (colors == 16) {
			rgb &= 15790320;
			rgb |= rgb >> 4;
		}
		return rgb;
	case RECOILResolution_X68_K1X1:
		return (rgb & 16316664) | (rgb >> 10 & 1) * 263172 | (rgb >> 6 & 197379);
	default:
		return rgb;
	}
}

static bool RECOIL_DecodeX68KPicChain(RECOIL *self, BitStream *stream, int pixelsOffset, int color)
{
	for (;;) {
		switch (BitStream_ReadBits(stream, 2)) {
		case 0:
			switch (stream->vtbl->readBit(stream)) {
			case 0:
				return true;
			case 1:
				break;
			default:
				return false;
			}
			switch (stream->vtbl->readBit(stream)) {
			case 0:
				pixelsOffset -= 2;
				break;
			case 1:
				pixelsOffset += 2;
				break;
			default:
				return false;
			}
			break;
		case 1:
			pixelsOffset--;
			break;
		case 2:
			break;
		case 3:
			pixelsOffset++;
			break;
		default:
			return false;
		}
		pixelsOffset += self->width;
		if (pixelsOffset < 0 || pixelsOffset >= self->width * self->height)
			return false;
		self->pixels[pixelsOffset] = color;
	}
}

static bool RECOIL_DecodeX68KPicScreen(RECOIL *self, X68KPicStream *stream, int pixelsLength, int platform, int depth)
{
	for (int pixelsOffset = 0; pixelsOffset < pixelsLength; pixelsOffset++)
		self->pixels[pixelsOffset] = -1;
	RecentInts colors;
	RecentInts_Construct(&colors);
	int color = 0;
	for (int pixelsOffset = -1;;) {
		int length = X68KPicStream_ReadLength(stream);
		if (length < 0)
			return false;
		while (--length > 0) {
			int got = self->pixels[++pixelsOffset];
			if (got < 0)
				self->pixels[pixelsOffset] = color;
			else
				color = got;
			if (pixelsOffset >= pixelsLength - 1)
				return true;
		}
		if (depth <= 8) {
			color = BitStream_ReadBits(&stream->base, depth);
			if (color < 0)
				return false;
			color = self->contentPalette[color];
		}
		else {
			switch (stream->base.vtbl->readBit(&stream->base)) {
			case 0:
				color = BitStream_ReadBits(&stream->base, depth);
				if (color < 0)
					return false;
				switch (platform) {
				case 0:
					if (depth == 15)
						color <<= 1;
					color = RECOIL_GetX68KColor(color);
					break;
				case 17:
					color = RECOIL_GetG6R5B5Color(color);
					break;
				default:
					break;
				}
				RecentInts_Add(&colors, color);
				break;
			case 1:
				color = BitStream_ReadBits(&stream->base, 7);
				if (color < 0)
					return false;
				color = RecentInts_Get(&colors, color);
				break;
			default:
				return false;
			}
		}
		self->pixels[++pixelsOffset] = color;
		if (pixelsOffset >= pixelsLength - 1)
			return true;
		switch (stream->base.vtbl->readBit(&stream->base)) {
		case 0:
			break;
		case 1:
			if (!RECOIL_DecodeX68KPicChain(self, &stream->base, pixelsOffset, color))
				return false;
			break;
		default:
			return false;
		}
	}
}

static bool RECOIL_DecodeX68KPic(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 14 || content[0] != 'P' || content[1] != 'I' || content[2] != 'C')
		return false;
	RECOILResolution resolution = RECOIL_IsStringAt(content, 3, "/MM/") ? RECOILResolution_MSX21X1 : RECOILResolution_X68_K1X1;
	X68KPicStream stream;
	X68KPicStream_Construct(&stream);
	stream.base.base.content = content;
	stream.base.base.contentOffset = 3;
	stream.base.base.contentLength = contentLength;
	for (;;) {
		int b = Stream_ReadByte(&stream.base.base);
		if (b < 0)
			return false;
		if (b == 26)
			break;
		if (b == '/' && resolution == RECOILResolution_MSX21X1 && stream.base.base.contentOffset + 4 < contentLength && content[stream.base.base.contentOffset] == 'M' && content[stream.base.base.contentOffset + 1] == 'S') {
			b = content[stream.base.base.contentOffset + 2];
			if (b >= 'A' && b <= 'C')
				resolution = RECOILResolution_MSX2_PLUS1X1;
		}
	}
	if (!Stream_SkipUntilByte(&stream.base.base, 0))
		return false;
	int platform = BitStream_ReadBits(&stream.base, 16);
	int depth = BitStream_ReadBits(&stream.base, 16);
	int width = BitStream_ReadBits(&stream.base, 16);
	int height = BitStream_ReadBits(&stream.base, 16);
	int pixelsLength = width * height;
	switch (platform) {
	case 0:
		if (!RECOIL_SetSize(self, width, height, resolution, 1))
			return false;
		break;
	case 2:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_FM_TOWNS1X1, 1))
			return false;
		stream.base.base.contentOffset += 6;
		break;
	case 17:
		return depth == 16 && RECOIL_SetSize(self, width, height, RECOILResolution_PC88_VA1X1, 1) && RECOIL_DecodeX68KPicScreen(self, &stream, pixelsLength, 17, 16);
	case 31:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_X68_K1X1, 1))
			return false;
		stream.base.base.contentOffset += 6;
		break;
	case 33:
		if (depth != 16 || !RECOIL_SetSize(self, width, height << 1, RECOILResolution_PC88_VA1X1, 1) || !RECOIL_DecodeX68KPicScreen(self, &stream, pixelsLength, 33, 16))
			return false;
		for (int offset = pixelsLength - 1; offset >= 0; offset--) {
			int color = self->pixels[offset];
			self->pixels[(offset << 1) + 1] = RECOIL_GetG3R3B2Color(color >> 8);
			self->pixels[offset << 1] = RECOIL_GetG3R3B2Color(color & 255);
		}
		return true;
	case 194:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_FM_TOWNS1X1, 1))
			return false;
		break;
	default:
		return false;
	}
	switch (depth) {
	case 4:
	case 8:
		for (int c = 0; c < 1 << depth; c++) {
			int color = BitStream_ReadBits(&stream.base, 16);
			if (color < 0)
				return false;
			self->contentPalette[c] = RECOIL_RestrictPlatformColor(self, RECOIL_GetX68KColor(color), 1 << depth);
		}
		break;
	case 15:
	case 16:
		break;
	default:
		return false;
	}
	return RECOIL_DecodeX68KPicScreen(self, &stream, pixelsLength, 0, depth);
}

static void RECOIL_SetPc88EightPixels(RECOIL *self, int column, int y, int b)
{
	for (int x = 0; x < 8; x++) {
		int offset = y * 1280 + column + x;
		self->pixels[offset + 640] = self->pixels[offset] = (b >> (7 - x) & 65793) * 255;
	}
}

static bool RECOIL_DecodeDaVinci(RECOIL *self, uint8_t const *content, int contentLength)
{
	if ((contentLength & 255) != 0)
		return false;
	RECOIL_SetSize(self, 640, 400, RECOILResolution_PC881X2, 1);
	DaVinciStream rle;
	DaVinciStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = 0;
	rle.base.base.base.base.contentLength = contentLength;
	for (int y = 0; y < 200; y++) {
		for (int column = 0; column < 640; column += 8) {
			int b = RleStream_ReadRle(&rle.base.base);
			if (b < 0)
				return false;
			RECOIL_SetPc88EightPixels(self, column, y, b);
		}
	}
	return rle.base.base.repeatCount == 0 && contentLength - rle.base.base.base.base.contentOffset < 256;
}

static bool RECOIL_DecodeArtMaster88(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 42 || !RECOIL_IsStringAt(content, 0, "SS_SIF    0.0") || content[19] != 'B' || content[20] != 'R' || content[21] != 'G' || content[24] != 128 || content[25] != 2)
		return false;
	ArtMaster88Stream rle;
	ArtMaster88Stream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 40;
	rle.base.base.base.contentLength = contentLength;
	if (content[16] == 'I' && !ArtMaster88Stream_SkipChunk(&rle))
		return false;
	switch (content[26] | content[27] << 8) {
	case 200:
		RECOIL_SetSize(self, 640, 400, RECOILResolution_PC881X2, 1);
		if (content[18] == 'B' && !ArtMaster88Stream_SkipChunk(&rle))
			return false;
		if (!ArtMaster88Stream_ReadPlanes(&rle, 3, 16000))
			return false;
		for (int y = 0; y < 200; y++) {
			for (int column = 0; column < 80; column++) {
				int offset = y * 80 + column;
				RECOIL_SetPc88EightPixels(self, column << 3, y, rle.planes[1][offset] << 16 | rle.planes[2][offset] << 8 | rle.planes[0][offset]);
			}
		}
		break;
	case 400:
		RECOIL_SetSize(self, 640, 400, RECOILResolution_PC981X1, 1);
		if (content[17] != 'R' || rle.base.base.base.contentOffset + 50 >= contentLength || content[rle.base.base.base.contentOffset + 1] != 0)
			return false;
		int paletteLength = content[rle.base.base.base.contentOffset];
		int planes;
		switch (paletteLength) {
		case 50:
			planes = 3;
			break;
		case 98:
			planes = 4;
			break;
		default:
			return false;
		}
		if (rle.base.base.base.contentOffset + paletteLength >= contentLength)
			return false;
		for (int c = 0; c < 1 << planes; c++) {
			int offset = rle.base.base.base.contentOffset + 2 + c * 6;
			int rgb = content[offset] << 16 | content[offset + 2] << 8 | content[offset + 4];
			if ((rgb & 15790320) != 0 || content[offset + 1] != 0 || content[offset + 3] != 0 || content[offset + 5] != 0)
				return false;
			self->contentPalette[c] = rgb * 17;
		}
		rle.base.base.base.contentOffset += paletteLength;
		if (content[18] == 'B' && !ArtMaster88Stream_SkipChunk(&rle))
			return false;
		if (!ArtMaster88Stream_ReadPlanes(&rle, planes, 32000))
			return false;
		for (int y = 0; y < 400; y++) {
			for (int column = 0; column < 80; column++) {
				int offset = y * 80 + column;
				for (int x = 0; x < 8; x++) {
					int c = 0;
					for (int plane = 0; plane < planes; plane++)
						c |= (rle.planes[plane][offset] >> (7 - x) & 1) << plane;
					self->pixels[y * 640 + (column << 3) + x] = self->contentPalette[c];
				}
			}
		}
		break;
	default:
		return false;
	}
	return true;
}

static int RECOIL_GetKtyTile(uint8_t const *content, int contentOffset)
{
	return content[contentOffset + 1] << 16 | content[contentOffset + 2] << 8 | content[contentOffset];
}

static void RECOIL_SetKtyFourPixels(RECOIL *self, int pixelsOffset, int tile)
{
	for (int x = 0; x < 4; x++)
		self->pixels[pixelsOffset + x] = (tile >> (3 - x) & 65793) * 255;
}

static void RECOIL_SetKtyTileOffset(RECOIL *self, int pixelsOffset, int mode, uint8_t const *content, int tileOffset)
{
	int tile = RECOIL_GetKtyTile(content, tileOffset);
	RECOIL_SetKtyFourPixels(self, pixelsOffset, tile >> 4);
	RECOIL_SetKtyFourPixels(self, pixelsOffset + 640, tile);
	if (mode != 0) {
		if (mode >= 2)
			tile = RECOIL_GetKtyTile(content, tileOffset + 3);
		RECOIL_SetKtyFourPixels(self, pixelsOffset + 1280, tile >> 4);
		RECOIL_SetKtyFourPixels(self, pixelsOffset + 1920, tile);
	}
}

static void RECOIL_SetKtyTile(RECOIL *self, int x, int y, int mode, uint8_t const *content, int tileOffset)
{
	if (mode != 0)
		y <<= 1;
	RECOIL_SetKtyTileOffset(self, (y * 320 + x) << 2, mode, content, tileOffset);
}

static bool RECOIL_DecodeKty(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 640, 400, RECOILResolution_PC88_VA1X1, 1);
	for (int i = 0; i < 256000; i += 4)
		self->pixels[i] = 1;
	int mode = 0;
	for (int contentOffset = 0; contentOffset < contentLength;) {
		int b = content[contentOffset++];
		if (b == 255) {
			if (mode != 0)
				mode = 2;
			for (int y = 0; y < 100; y++) {
				for (int x = 0; x < 160; x++) {
					int pixelsOffset = (y * (mode == 0 ? 320 : 640) + x) << 2;
					if (self->pixels[pixelsOffset] == 1) {
						int nextOffset = contentOffset + (mode == 0 ? 3 : 6);
						if (nextOffset > contentLength)
							return false;
						RECOIL_SetKtyTileOffset(self, pixelsOffset, mode, content, contentOffset);
						contentOffset = nextOffset;
					}
				}
			}
			if (contentOffset != contentLength)
				return false;
			if (mode == 0) {
				for (int pixelsOffset = 127360; pixelsOffset >= 0; pixelsOffset -= 640) {
					memcpy(self->pixels + ((pixelsOffset << 1) + 640), self->pixels + pixelsOffset, 640 * sizeof(int));
					memcpy(self->pixels + (pixelsOffset << 1), self->pixels + pixelsOffset, 640 * sizeof(int));
				}
				self->resolution = RECOILResolution_PC881X2;
			}
			return true;
		}
		mode = b;
		int tileOffset = contentOffset;
		contentOffset += mode < 2 ? 3 : 6;
		for (;;) {
			if (contentOffset >= contentLength)
				return false;
			int hi = content[contentOffset++];
			if (hi == 255)
				break;
			if (contentOffset + 2 > contentLength)
				return false;
			int offset = (hi & 63) << 8 | content[contentOffset++];
			int left = offset % 160;
			int top = offset / 160;
			if (top >= 100)
				return false;
			int right;
			int bottom;
			if (hi >= 128) {
				right = left;
				bottom = content[contentOffset++];
			}
			else {
				right = content[contentOffset++];
				if (right < left || right >= 160)
					return false;
				if (hi >= 64)
					bottom = top;
				else if (contentOffset >= contentLength)
					return false;
				else {
					bottom = content[contentOffset++];
					if (bottom < top || bottom >= 100)
						return false;
				}
			}
			for (int y = top; y <= bottom; y++) {
				for (int x = left; x <= right; x++)
					RECOIL_SetKtyTile(self, x, y, mode, content, tileOffset);
			}
		}
		for (;;) {
			if (contentOffset >= contentLength)
				return false;
			int x = content[contentOffset++];
			if (x == 255)
				break;
			if (x >= 160 || contentOffset >= contentLength)
				return false;
			int y = content[contentOffset++];
			if (y >= 100)
				return false;
			RECOIL_SetKtyTile(self, x, y, mode, content, tileOffset);
		}
	}
	return false;
}

static bool RECOIL_DecodeEbd(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 368 || contentLength % 320 != 48)
		return false;
	for (int c = 0; c < 16; c++) {
		int rgb = content[c * 3] << 16 | content[c * 3 + 1] << 8 | content[c * 3 + 2];
		if (((rgb >> 4 ^ rgb) & 986895) != 0) {
			if ((rgb & 15790320) != 0)
				return false;
			rgb *= 17;
		}
		self->contentPalette[c] = rgb;
	}
	return RECOIL_DecodeAmigaPlanar(self, content, 48, 640, contentLength / 320, RECOILResolution_PC981X1, 4, self->contentPalette);
}

static bool RECOIL_DecodeNl3(RECOIL *self, uint8_t const *content, int contentLength)
{
	Nl3Stream stream;
	Nl3Stream_Construct(&stream);
	stream.base.base.base.content = content;
	stream.base.base.base.contentOffset = 0;
	stream.base.base.base.contentLength = contentLength;
	for (int i = 0; i < 64; i++) {
		int c = ((const RleStreamVtbl *) stream.base.base.vtbl)->readValue(&stream.base);
		if (c < 0 || c > 127)
			return false;
		c |= ((const RleStreamVtbl *) stream.base.base.vtbl)->readValue(&stream.base) << 7;
		if (c < 0 || c >= 729)
			return false;
		self->contentPalette[i] = RECOIL_Get729Color(c);
	}
	RECOIL_SetSize(self, 160, 100, RECOILResolution_PC981X1, 1);
	for (int x = 0; x < 160; x++) {
		for (int y = 0; y < 100; y++) {
			int b = RleStream_ReadRle(&stream.base);
			if (b < 0)
				return false;
			self->pixels[y * 160 + x] = self->contentPalette[b];
		}
	}
	return true;
}

static bool RECOIL_DecodeMl1Chain(RECOIL *self, X68KPicStream *stream, int pixelsOffset, int rgb)
{
	for (;;) {
		switch (stream->base.vtbl->readBit(&stream->base)) {
		case 0:
			break;
		case 1:
			switch (BitStream_ReadBits(&stream->base, 2)) {
			case 0:
				pixelsOffset++;
				break;
			case 1:
				pixelsOffset--;
				break;
			case 2:
				return true;
			case 3:
				switch (stream->base.vtbl->readBit(&stream->base)) {
				case 0:
					pixelsOffset += 2;
					break;
				case 1:
					pixelsOffset -= 2;
					break;
				default:
					return false;
				}
				break;
			default:
				return false;
			}
			break;
		default:
			return false;
		}
		pixelsOffset += self->width;
		if (pixelsOffset < 0 || pixelsOffset >= self->width * self->height)
			return false;
		self->pixels[pixelsOffset] = rgb;
	}
}

static int RECOIL_DecodeMl1Mx1(RECOIL *self, X68KPicStream *stream, int imageOffset)
{
	if (BitStream_ReadBits(&stream->base, 32) != 825241626 || BitStream_ReadBits(&stream->base, 32) < 0 || BitStream_ReadBits(&stream->base, 16) < 0)
		return -1;
	int left = BitStream_ReadBits(&stream->base, 16);
	int top = BitStream_ReadBits(&stream->base, 16);
	int width = BitStream_ReadBits(&stream->base, 16) - left + 1;
	int height = BitStream_ReadBits(&stream->base, 16) - top + 1;
	for (int i = 0; i < 624; i++) {
		if (stream->base.vtbl->readBit(&stream->base) < 0)
			return -1;
	}
	int mode = BitStream_ReadBits(&stream->base, 2);
	int lastColor;
	switch (mode) {
	case 0:
		lastColor = 127;
		break;
	case 1:
	case 2:
		lastColor = BitStream_ReadBits(&stream->base, 7);
		break;
	default:
		return -1;
	}
	if (imageOffset == -1) {
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_PC981X1, 1))
			return -1;
		imageOffset = 0;
	}
	memset(self->contentPalette, 0, sizeof(self->contentPalette));
	for (int i = 0; i <= lastColor; i++) {
		int j = 0;
		if (mode > 0)
			j = BitStream_ReadBits(&stream->base, 7);
		int c = BitStream_ReadBits(&stream->base, 10);
		if (c < 0 || c >= 729)
			return -1;
		self->contentPalette[mode == 1 ? j : i] = RECOIL_Get729Color(c);
	}
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
			self->pixels[imageOffset + y * self->width + x] = 1;
	}
	int distance = 1;
	int rgb = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int pixelsOffset = imageOffset + y * self->width + x;
			if (--distance > 0) {
				int old = self->pixels[pixelsOffset];
				if (old == 1)
					self->pixels[pixelsOffset] = rgb;
				else
					rgb = old;
			}
			else {
				distance = X68KPicStream_ReadLength(stream);
				if (distance < 0)
					return -1;
				int c = mode == 2 ? X68KPicStream_ReadLength(stream) - 1 : BitStream_ReadBits(&stream->base, 7);
				if (c < 0 || c >= 128)
					return -1;
				rgb = self->contentPalette[c];
				switch (stream->base.vtbl->readBit(&stream->base)) {
				case 0:
					break;
				case 1:
					if (!RECOIL_DecodeMl1Chain(self, stream, pixelsOffset, rgb))
						return -1;
					break;
				default:
					return -1;
				}
				self->pixels[pixelsOffset] = rgb;
			}
		}
	}
	return distance == 1 && X68KPicStream_ReadLength(stream) == width * height + 1 ? height : -1;
}

static bool RECOIL_DecodeMl1(RECOIL *self, uint8_t const *content, int contentLength)
{
	X68KPicStream stream;
	X68KPicStream_Construct(&stream);
	stream.base.base.content = content;
	stream.base.base.contentOffset = 0;
	stream.base.base.contentLength = contentLength;
	return RECOIL_DecodeMl1Mx1(self, &stream, -1) > 0;
}

static bool RECOIL_DecodeMx1Tiles(RECOIL *self, Mx1Stream *stream, int width, int height, int shift)
{
	if (!RECOIL_SetSize(self, width << shift, height << shift, RECOILResolution_PC981X1, 1))
		return false;
	for (int y = 0; y < self->height; y += height) {
		for (int x = 0; x < self->width; x += width) {
			if (!Mx1Stream_FindImage(stream) || RECOIL_DecodeMl1Mx1(self, &stream->base, y * self->width + x) < 0)
				return false;
		}
	}
	return true;
}

static bool RECOIL_DecodeMx1(RECOIL *self, uint8_t const *content, int contentLength)
{
	Mx1Stream stream;
	Mx1Stream_Construct(&stream);
	stream.base.base.base.content = content;
	stream.base.base.base.contentOffset = 0;
	stream.base.base.base.contentLength = contentLength;
	if (!Mx1Stream_FindImage(&stream) || RECOIL_DecodeMl1Mx1(self, &stream.base, -1) < 0)
		return false;
	if (!Mx1Stream_FindImage(&stream))
		return true;
	int sameSizeImages = 1;
	int width = self->width;
	int height = self->height;
	do {
		if (RECOIL_DecodeMl1Mx1(self, &stream.base, -1) < 0)
			return false;
		if (sameSizeImages > 0 && self->width == width && self->height == height)
			sameSizeImages++;
		else {
			if (width < self->width)
				width = self->width;
			if (sameSizeImages > 0) {
				height *= sameSizeImages;
				sameSizeImages = 0;
			}
			height += self->height;
		}
	}
	while (Mx1Stream_FindImage(&stream));
	stream.base.base.base.contentOffset = 0;
	switch (sameSizeImages) {
	case 4:
		return RECOIL_DecodeMx1Tiles(self, &stream, width, height, 1);
	case 16:
		return RECOIL_DecodeMx1Tiles(self, &stream, width, height, 2);
	case 0:
		break;
	default:
		height *= sameSizeImages;
		break;
	}
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_PC981X1, 1))
		return false;
	memset(self->pixels, 0, width * height * sizeof(int));
	int imageOffset = 0;
	while (Mx1Stream_FindImage(&stream))
		imageOffset += RECOIL_DecodeMl1Mx1(self, &stream.base, imageOffset) * width;
	return true;
}

static bool RECOIL_DecodeZim(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 700 || !RECOIL_IsStringAt(content, 0, "FORMAT-A"))
		return false;
	int contentOffset = 512 + ((content[506] | content[507] << 8) << 1);
	if (contentOffset + 26 > contentLength || content[contentOffset] != 0 || content[contentOffset + 1] != 0 || content[contentOffset + 2] != 0 || content[contentOffset + 3] != 0 || content[contentOffset + 20] != 1 || content[contentOffset + 21] != 0)
		return false;
	int width = content[contentOffset + 4] + (content[contentOffset + 5] << 8) + 1;
	int height = content[contentOffset + 6] + (content[contentOffset + 7] << 8) + 1;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_PC981X1, 1))
		return false;
	contentOffset += 24;
	if (content[contentOffset - 2] != 0 || content[contentOffset - 1] != 0) {
		if (contentOffset + 66 > contentLength)
			return false;
		for (int c = 0; c < 16; c++) {
			self->contentPalette[c] = RECOIL_GetKtyTile(content, contentOffset);
			contentOffset += 4;
		}
	}
	else {
		for (int c = 0; c < 16; c++)
			self->contentPalette[c] = RECOIL_GetZxColor(c);
		self->contentPalette[8] = 16777215;
	}
	int pixelsLength = width * height;
	for (int pixelsOffset = 0; pixelsOffset < pixelsLength; pixelsOffset++)
		self->pixels[pixelsOffset] = self->contentPalette[0];
	uint8_t flags3[64];
	uint8_t data[512];
	ZimStream stream;
	stream.base.content = content;
	stream.base.contentOffset = contentOffset;
	stream.base.contentLength = contentLength;
	int skip = ZimStream_ReadWord(&stream);
	stream.base.contentOffset += skip << 1;
	for (;;) {
		int dot = ZimStream_ReadWord(&stream);
		switch (dot) {
		case -1:
			return false;
		case 0:
			return true;
		default:
			break;
		}
		int x = ZimStream_ReadWord(&stream);
		if (x < 0 || x >= width)
			return false;
		int y = ZimStream_ReadWord(&stream);
		if (y < 0 || y >= height)
			return false;
		int len = ZimStream_ReadWord(&stream);
		if (len < 0)
			return false;
		stream.base.contentLength = stream.base.contentOffset + len;
		if (stream.base.contentLength >= contentLength)
			return false;
		int size = ZimStream_ReadWord(&stream);
		if (size > 512 || (size & 3) != 0 || size << 1 < dot)
			return false;
		int pixelsOffset = y * width + x;
		if (pixelsOffset + dot > pixelsLength)
			return false;
		ZimStream_UnpackFlags2(&stream);
		ZimStream_Unpack(&stream, stream.flags2, flags3, 64);
		ZimStream_Unpack(&stream, flags3, data, size);
		stream.base.contentLength = contentLength;
		for (int i = 1; i < size; i++)
			data[i] ^= data[i - 1];
		for (int i = 2; i < size; i++)
			data[i] ^= data[i - 2];
		size >>= 2;
		for (int i = 0; i < dot; i++) {
			int bit = ~i & 7;
			int c = (data[i >> 3] >> bit & 1) << 3 | (data[size + (i >> 3)] >> bit & 1) << 2 | (data[2 * size + (i >> 3)] >> bit & 1) << 1 | (data[3 * size + (i >> 3)] >> bit & 1);
			self->pixels[pixelsOffset + i] = self->contentPalette[c];
		}
	}
}

static bool RECOIL_DecodeQ4(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 22 || (content[2] != 2 && (content[1] > 1 || content[3] > 1)) || content[8] + (content[9] << 8) != contentLength || !RECOIL_IsStringAt(content, 11, "MAJYO"))
		return false;
	Q4Stream rle;
	Q4Stream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 16;
	rle.base.base.base.contentLength = contentLength;
	int nextChunkOffset = Q4Stream_StartChunk(&rle);
	if (nextChunkOffset < 0 || !Q4Stream_UnpackQ4(&rle))
		return false;
	for (int i = 0; i < 16; i++) {
		int rgb = 0;
		for (int c = 0; c < 3; c++) {
			if (RleStream_ReadRle(&rle.base) < 0)
				return false;
			int b = RleStream_ReadRle(&rle.base);
			if (b < 0)
				return false;
			rgb = rgb << 8 | b * 17;
		}
		self->contentPalette[(i & 8) | (i & 1) << 2 | (i >> 1 & 3)] = rgb;
	}
	RECOIL_SetSize(self, 640, 400, RECOILResolution_PC981X1, 1);
	int chunkPixels = 0;
	for (int i = 0; i < 256000; i++) {
		if (--chunkPixels <= 0) {
			if (nextChunkOffset >= contentLength - 6)
				return false;
			chunkPixels = (content[nextChunkOffset + 4] | content[nextChunkOffset + 5] << 8) << 1;
			rle.base.base.base.content = content;
			rle.base.base.base.contentOffset = nextChunkOffset;
			rle.base.base.base.contentLength = contentLength;
			nextChunkOffset = Q4Stream_StartChunk(&rle);
			if (nextChunkOffset < 0 || !Q4Stream_UnpackQ4(&rle))
				return false;
		}
		self->pixels[i] = self->contentPalette[FuInt_Max(RleStream_ReadRle(&rle.base), 0)];
	}
	return true;
}

static RECOILResolution RECOIL_GetPiPlatform(uint8_t const *content, int contentOffset, bool highPixel)
{
	switch (RECOIL_Get32LittleEndian(content, contentOffset)) {
	case 1314344788:
		return RECOILResolution_FM_TOWNS1X1;
	case 808993616:
		return RECOILResolution_PC801X2;
	case 943211344:
		return RECOILResolution_PC881X2;
	case 1096172368:
		return highPixel ? RECOILResolution_PC881X2 : RECOILResolution_PC88_VA1X1;
	case 827872077:
	case 844649293:
	case 1347965773:
	case 1381520205:
		return highPixel ? RECOILResolution_MSX21X2 : RECOILResolution_MSX21X1;
	case 1261975128:
		return RECOILResolution_X68_K1X1;
	default:
		return highPixel ? RECOILResolution_PC881X2 : RECOILResolution_PC981X1;
	}
}

static void RECOIL_SetPiPalette(RECOIL *self, uint8_t const *content, int paletteOffset, int colors, int rOffset)
{
	for (int c = 0; c < colors; c++) {
		int offset = paletteOffset + c * 3;
		self->contentPalette[c] = RECOIL_RestrictPlatformColor(self, content[offset + rOffset] << 16 | content[offset + 1 - rOffset] << 8 | content[offset + 2], colors);
	}
}

static bool RECOIL_DecodePi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 18 || content[0] != 'P' || content[1] != 'i')
		return false;
	PiStream s;
	PiStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentOffset = 2;
	s.base.base.contentLength = contentLength;
	if (!Stream_SkipUntilByte(&s.base.base, 26) || !Stream_SkipUntilByte(&s.base.base, 0)) {
		PiStream_Destruct(&s);
		return false;
	}
	int contentOffset = s.base.base.contentOffset;
	if (contentOffset + 14 > contentLength || content[contentOffset] != 0) {
		PiStream_Destruct(&s);
		return false;
	}
	int depth = content[contentOffset + 3];
	if (depth != 4 && depth != 8) {
		PiStream_Destruct(&s);
		return false;
	}
	RECOILResolution resolution = RECOIL_GetPiPlatform(content, contentOffset + 4, content[contentOffset + 1] == 2 && content[contentOffset + 2] == 1);
	contentOffset += 8 + (content[contentOffset + 8] << 8) + content[contentOffset + 9];
	if (contentOffset + 6 >= contentLength) {
		PiStream_Destruct(&s);
		return false;
	}
	int width = content[contentOffset + 2] << 8 | content[contentOffset + 3];
	int height = content[contentOffset + 4] << 8 | content[contentOffset + 5];
	if (!RECOIL_SetScaledSize(self, width, height, resolution)) {
		PiStream_Destruct(&s);
		return false;
	}
	s.base.base.contentOffset = contentOffset + 6 + (3 << depth);
	if (PiStream_Unpack(&s, width, height, depth)) {
		RECOIL_SetPiPalette(self, content, contentOffset + 6, 1 << depth, 0);
		RECOIL_DecodeBytes(self, s.indexes, 0);
		PiStream_Destruct(&s);
		return true;
	}
	PiStream_Destruct(&s);
	return false;
}

static bool RECOIL_DecodeMaki1(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1096 || content[40] != 0 || content[41] != 0 || content[42] != 0 || content[43] != 0 || content[44] != 2 || content[45] != 128 || content[46] != 1 || content[47] != 144)
		return false;
	RECOIL_SetSize(self, 640, 400, RECOIL_GetPiPlatform(content, 8, false), 1);
	RECOIL_SetPiPalette(self, content, 48, 16, 1);
	int contentOffset = 1096;
	uint16_t haveBuffer[8000];
	BitStream haveBlock;
	BitStream_Construct(&haveBlock);
	haveBlock.base.content = content;
	haveBlock.base.contentOffset = 96;
	haveBlock.base.contentLength = 1096;
	for (int i = 0; i < 8000; i++) {
		int have = 0;
		if (haveBlock.vtbl->readBit(&haveBlock) == 1) {
			if (contentOffset + 1 >= contentLength)
				return false;
			have = content[contentOffset] << 8 | content[contentOffset + 1];
			contentOffset += 2;
		}
		haveBuffer[i] = (uint16_t) have;
	}
	int xorYOffset = content[6] == 'A' ? 2 : 0;
	uint8_t indexBuffer[1280] = { 0 };
	for (int y = 0; y < 400; y++) {
		for (int x = 0; x < 320; x++) {
			int row = y & 3;
			int index = indexBuffer[(row ^ xorYOffset) * 320 + x];
			if ((haveBuffer[(y & ~3) * 20 + (x >> 2)] >> (15 - (row << 2) - (x & 3)) & 1) != 0) {
				if (contentOffset >= contentLength)
					return false;
				index ^= content[contentOffset++];
			}
			indexBuffer[row * 320 + x] = (uint8_t) index;
			int pixelsOffset = (y * 320 + x) << 1;
			self->pixels[pixelsOffset] = self->contentPalette[index >> 4];
			self->pixels[pixelsOffset + 1] = self->contentPalette[index & 15];
		}
	}
	return true;
}

static bool RECOIL_UnpackMag(uint8_t const *content, int headerOffset, int contentLength, int bytesPerLine, int height, uint8_t *unpacked)
{
	BitStream haveDelta;
	BitStream_Construct(&haveDelta);
	haveDelta.base.content = content;
	haveDelta.base.contentOffset = headerOffset + RECOIL_Get32LittleEndian(content, headerOffset + 12);
	haveDelta.base.contentLength = contentLength;
	int deltaOffset = headerOffset + RECOIL_Get32LittleEndian(content, headerOffset + 16);
	int colorOffset = headerOffset + RECOIL_Get32LittleEndian(content, headerOffset + 24);
	if (haveDelta.base.contentOffset < 0 || deltaOffset < 0 || colorOffset < 0)
		return false;
	uint8_t *deltas = (uint8_t *) malloc(((bytesPerLine + 3) >> 2) * sizeof(uint8_t));
	memset(deltas, 0, ((bytesPerLine + 3) >> 2) * sizeof(uint8_t));
	for (int y = 0; y < height; y++) {
		int delta = 0;
		for (int x = 0; x < bytesPerLine; x++) {
			if ((x & 1) == 0) {
				delta = deltas[x >> 2];
				if ((x & 2) == 0) {
					switch (haveDelta.vtbl->readBit(&haveDelta)) {
					case 0:
						break;
					case 1:
						if (deltaOffset >= contentLength) {
							free(deltas);
							return false;
						}
						delta ^= content[deltaOffset++];
						deltas[x >> 2] = (uint8_t) delta;
						break;
					default:
						free(deltas);
						return false;
					}
					delta >>= 4;
				}
				else
					delta &= 15;
			}
			if (delta == 0) {
				if (colorOffset >= contentLength) {
					free(deltas);
					return false;
				}
				unpacked[y * bytesPerLine + x] = content[colorOffset++];
			}
			else {
				static const uint8_t DELTA_X[16] = { 0, 2, 4, 8, 0, 2, 0, 2, 4, 0, 2, 4, 0, 2, 4, 0 };
				static const uint8_t DELTA_Y[16] = { 0, 0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 4, 8, 8, 8, 16 };
				int sourceX = x - DELTA_X[delta];
				int sourceY = y - DELTA_Y[delta];
				if (sourceX < 0 || sourceY < 0) {
					free(deltas);
					return false;
				}
				unpacked[y * bytesPerLine + x] = unpacked[sourceY * bytesPerLine + sourceX];
			}
		}
		if ((bytesPerLine & 1) != 0 && delta == 0)
			colorOffset++;
		if (((bytesPerLine + 1) & 2) != 0 && (deltas[bytesPerLine >> 2] & 15) == 0)
			colorOffset += 2;
	}
	free(deltas);
	return true;
}

static bool RECOIL_DecodeMag(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8)
		return false;
	if (RECOIL_IsStringAt(content, 0, "MAKI01A ") || RECOIL_IsStringAt(content, 0, "MAKI01B "))
		return RECOIL_DecodeMaki1(self, content, contentLength);
	if (!RECOIL_IsStringAt(content, 0, "MAKI02  "))
		return false;
	int headerOffset = 0;
	do {
		if (headerOffset >= contentLength)
			return false;
	}
	while (content[headerOffset++] != 26);
	if (headerOffset + 80 > contentLength || content[headerOffset] != 0)
		return false;
	int left = content[headerOffset + 4] + (content[headerOffset + 5] << 8);
	int width = content[headerOffset + 8] + (content[headerOffset + 9] << 8) + 1;
	int bytesPerLine;
	int colors;
	if (content[headerOffset + 3] < 128) {
		width -= left & ~7;
		bytesPerLine = (width + 1) >> 1;
		colors = 16;
	}
	else {
		if (headerOffset + 800 >= contentLength)
			return false;
		bytesPerLine = width -= left & ~3;
		colors = 256;
	}
	RECOILResolution resolution;
	int msxMode = 0;
	switch (content[headerOffset + 1]) {
	case 0:
	case 136:
		resolution = (content[headerOffset + 3] & 1) == 0 ? RECOILResolution_PC88_VA1X1 : RECOILResolution_PC881X2;
		break;
	case 3:
		msxMode = content[headerOffset + 2] & 252;
		switch (msxMode) {
		case 0:
		case 20:
		case 84:
			resolution = RECOILResolution_MSX21X1;
			break;
		case 4:
			resolution = RECOILResolution_MSX21X2;
			break;
		case 16:
		case 80:
			resolution = RECOILResolution_MSX22X1I;
			break;
		case 32:
		case 64:
			if (colors == 16)
				width >>= 1;
			resolution = RECOILResolution_MSX2_PLUS2X1I;
			break;
		case 36:
		case 68:
			if (colors == 16)
				width >>= 1;
			resolution = RECOILResolution_MSX2_PLUS1X1;
			break;
		case 96:
			width = bytesPerLine << 2;
			resolution = RECOILResolution_MSX21X1I;
			break;
		case 100:
			width = bytesPerLine << 2;
			resolution = RECOILResolution_MSX21X2;
			break;
		default:
			return false;
		}
		break;
	case 98:
	case 112:
		resolution = RECOILResolution_PC981X1;
		break;
	case 104:
		resolution = RECOILResolution_X68_K1X1;
		break;
	case 128:
		resolution = RECOILResolution_PC801X2;
		break;
	case 153:
		resolution = RECOILResolution_MACINTOSH1X1;
		break;
	default:
		resolution = (content[headerOffset + 3] & 1) == 0 ? RECOILResolution_MSX21X1 : RECOILResolution_MSX21X2;
		break;
	}
	int height = content[headerOffset + 10] - content[headerOffset + 6] + ((content[headerOffset + 11] - content[headerOffset + 7]) << 8) + 1;
	if (!RECOIL_SetScaledSize(self, width, height, resolution))
		return false;
	uint8_t *unpacked = (uint8_t *) malloc(bytesPerLine * height * sizeof(uint8_t));
	if (!RECOIL_UnpackMag(content, headerOffset, contentLength, bytesPerLine, height, unpacked)) {
		free(unpacked);
		return false;
	}
	RECOIL_SetPiPalette(self, content, headerOffset + 32, colors, 1);
	switch (msxMode) {
	case 32:
	case 36:
		RECOIL_DecodeMsxYjkScreen(self, unpacked, 0, true);
		break;
	case 64:
	case 68:
		RECOIL_DecodeMsxYjkScreen(self, unpacked, 0, false);
		break;
	case 96:
	case 100:
		RECOIL_DecodeMsx6(self, unpacked, 0);
		break;
	default:
		if (colors == 16)
			RECOIL_DecodeNibbles(self, unpacked, 0, bytesPerLine);
		else
			RECOIL_DecodeBytes(self, unpacked, 0);
		break;
	}
	free(unpacked);
	return true;
}

static bool RECOIL_DecodeVbm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 9 || content[0] != 'B' || content[1] != 'M' || content[2] != 203)
		return false;
	int width = content[4] << 8 | content[5];
	int height = content[6] << 8 | content[7];
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_C1281X1, 1))
		return false;
	switch (content[3]) {
	case 2:
		return RECOIL_DecodeBlackAndWhite(self, content, 8, contentLength, false, 16777215);
	case 3:
		if (contentLength < 19)
			return false;
		int contentOffset = 18 + (content[16] << 8) + content[17];
		if (content[8] == 0)
			return RECOIL_DecodeBlackAndWhite(self, content, contentOffset, contentLength, false, 0);
		VbmStream rle;
		VbmStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = contentOffset;
		rle.base.base.base.contentLength = contentLength;
		return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 0);
	default:
		return false;
	}
}

static bool RECOIL_DecodeBrus(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 20 || !RECOIL_IsStringAt(content, 2, "BRUS") || content[6] != 4 || content[10] != 1 || content[11] != 2)
		return false;
	int columns = content[12];
	if (columns == 0 || columns > 90)
		return false;
	int height = content[13] | content[14] << 8;
	if (height == 0 || height > 700)
		return false;
	int width = columns << 3;
	RECOIL_SetSize(self, width, height, RECOILResolution_C1281X1, 1);
	int bitmapLength = height * columns;
	uint8_t bitmap[63000];
	PgcStream rle;
	PgcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 18;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, bitmap, 0, 1, bitmapLength))
		return false;
	int contentOffset = rle.base.base.base.contentOffset;
	if (contentOffset + 4 >= contentLength || !RECOIL_IsStringAt(content, contentOffset, "COLR")) {
		return RECOIL_DecodeBlackAndWhite(self, bitmap, 0, bitmapLength, false, 16777215);
	}
	rle.base.base.base.contentOffset = contentOffset + 4;
	uint8_t colors[180];
	for (int y = 0; y < height; y++) {
		if ((y & 7) == 0 && !RleStream_Unpack(&rle.base, colors, 0, 1, columns << 1))
			return false;
		for (int x = 0; x < width; x++) {
			int column = x >> 3;
			int c = colors[(y & 1) * columns + column];
			if ((bitmap[y * columns + column] >> (~x & 7) & 1) == 0)
				c >>= 4;
			static const int PALETTE[16] = { 0, 5592405, 170, 5592575, 43520, 5635925, 43690, 5636095, 11141120, 16733525, 11141290, 16733695, 11162880, 16777045, 11184810, 16777215 };
			self->pixels[y * width + x] = PALETTE[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeBp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 4083 || content[0] != 0 || content[1] != 17)
		return false;
	RECOIL_SetSize(self, 160, 192, RECOILResolution_VIC201X1, 1);
	int screenColor = content[4082] >> 4;
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 160; x++) {
			int c;
			if ((content[2 + (((x >> 3) * 12 + (y >> 4)) << 4) + (y & 15)] >> (~x & 7) & 1) == 0)
				c = screenColor;
			else {
				c = content[3842 + (y >> 4) * 20 + (x >> 3)] & 15;
				if (c >= 8)
					return false;
			}
			self->pixels[y * 160 + x] = RECOIL_VIC20_PALETTE[c];
		}
	}
	return true;
}

static bool RECOIL_DecodePic0(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength != 3890 || content[0] != 0 || content[1] != 13 || content[3876] != 150 || content[3877] != 23 || content[3879] != 140)
		return false;
	uint8_t colors[245];
	if (RECOIL_ReadCompanionFile(self, filename, "PIC1", "pic1", colors, 245) != 244)
		return false;
	RECOIL_SetSize(self, 176, 176, RECOILResolution_VIC202X1, 1);
	for (int y = 0; y < 176; y++) {
		for (int x = 0; x < 176; x++) {
			int charOffset = (y >> 4) * 22 + (x >> 3);
			int c = colors[2 + charOffset];
			if ((c & 8) == 0)
				return false;
			switch (content[2 + (charOffset << 4) + (y & 15)] >> (~x & 6) & 3) {
			case 0:
				c = content[3889] >> 4;
				break;
			case 1:
				c = content[3889] & 7;
				break;
			case 2:
				c &= 7;
				break;
			default:
				c = content[3888] >> 4;
				break;
			}
			self->pixels[y * 176 + x] = RECOIL_VIC20_PALETTE[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeVic20Mg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 4097 || content[0] != 241 || content[1] != 16 || content[2] != 12 || content[3] != 18 || content[4] != 216 || content[5] != 7 || content[6] != 158 || content[7] != 32 || content[8] != '8' || content[9] != '5' || content[10] != '8' || content[11] != '4' || content[12] != 0 || content[13] != 0 || content[14] != 0)
		return false;
	RECOIL_SetSize(self, 160, 192, RECOILResolution_VIC202X1, 1);
	uint8_t palette[4];
	palette[0] = (uint8_t) (content[16] >> 4);
	palette[1] = (uint8_t) (content[16] & 7);
	palette[3] = (uint8_t) (content[15] >> 4);
	int invert = ~(content[16] >> 3) & 1;
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 160; x++) {
			palette[2] = (uint8_t) (content[3857 + (y >> 4) * 10 + (x >> 4)] >> (x >> 1 & 4) & 15);
			int b = content[17 + (x >> 3) * 192 + y];
			if (palette[2] >= 8) {
				palette[2] &= 7;
				b = b >> (~x & 6) & 3;
			}
			else {
				self->resolution = RECOILResolution_VIC201X1;
				b = ((b >> (~x & 7) & 1) ^ invert) << 1;
			}
			self->pixels[y * 160 + x] = RECOIL_VIC20_PALETTE[palette[b]];
		}
	}
	return true;
}

static bool RECOIL_DecodeP4i(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 10050:
		if (RECOIL_IsStringAt(content, 1020, "MULT")) {
			RECOIL_SetSize(self, 320, 200, RECOILResolution_C162X1, 1);
			for (int y = 0; y < 200; y++) {
				for (int x = 0; x < 320; x++) {
					int offset = (y & ~7) * 40 + (x & ~7) + (y & 7);
					int c = content[2050 + offset] >> (~x & 6) & 3;
					switch (c) {
					case 0:
						c = (content[1025] & 7) << 4 | content[1025] >> 4;
						break;
					case 1:
						offset >>= 3;
						c = (content[2 + offset] & 7) << 4 | content[1026 + offset] >> 4;
						break;
					case 2:
						offset >>= 3;
						c = (content[2 + offset] & 112) | (content[1026 + offset] & 15);
						break;
					default:
						c = (content[1024] & 7) << 4 | content[1024] >> 4;
						break;
					}
					self->pixels[y * 320 + x] = self->c16Palette[c];
				}
			}
		}
		else {
			RECOIL_SetSize(self, 320, 200, RECOILResolution_C161X1, 1);
			for (int y = 0; y < 200; y++) {
				for (int x = 0; x < 320; x++) {
					int offset = (y & ~7) * 40 + (x & ~7) + (y & 7);
					int c = content[2050 + offset] >> (~x & 7) & 1;
					offset >>= 3;
					if (c == 0)
						c = (content[2 + offset] & 112) | (content[1026 + offset] & 15);
					else
						c = (content[2 + offset] & 7) << 4 | content[1026 + offset] >> 4;
					self->pixels[y * 320 + x] = self->c16Palette[c];
				}
			}
		}
		break;
	case 2050:
		RECOIL_SetSize(self, 256, 64, RECOILResolution_C162X1, 1);
		for (int y = 0; y < 64; y++) {
			for (int x = 0; x < 256; x++) {
				static const uint8_t LOGO_COLORS[4] = { 0, 49, 81, 113 };
				int c = LOGO_COLORS[content[2 + ((x & ~7) << 3) + y] >> (~x & 6) & 3];
				self->pixels[(y << 8) + x] = self->c16Palette[c];
			}
		}
		break;
	default:
		return false;
	}
	return true;
}

static bool RECOIL_DecodeZs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1026 || content[0] != 176 || content[1] != 240)
		return false;
	RECOIL_SetSize(self, 256, 32, RECOILResolution_C641X1, 1);
	for (int y = 0; y < 32; y++) {
		for (int x = 0; x < 256; x++) {
			int c = y >> 3 << 5 | x >> 3;
			if (c < 113) {
				c = content[3 + c * 9 + (y & 7)] >> (~x & 7) & 1;
				if (c != 0)
					c = 16777215;
			}
			else
				c = 0;
			self->pixels[(y << 8) + x] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeG(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 514 || content[0] != 66 || content[1] != 0)
		return false;
	RECOIL_SetSize(self, 256, 16, RECOILResolution_C641X1, 1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, 2, 514, 8);
	return true;
}

static bool RECOIL_Decode64c(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 10 || contentLength > 2050 || content[0] != 0)
		return false;
	RECOIL_SetSize(self, 256, (contentLength + 253) >> 8 << 3, RECOILResolution_C641X1, 1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, 2, contentLength, 8);
	return true;
}

static bool RECOIL_DecodePrintfox(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 4)
		return false;
	int columns;
	int rows;
	PrintfoxStream rle;
	PrintfoxStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 1;
	rle.base.base.base.contentLength = contentLength;
	switch (content[0]) {
	case 'B':
		columns = 40;
		rows = 25;
		break;
	case 'G':
		columns = 80;
		rows = 50;
		break;
	case 'P':
		columns = content[2];
		rows = content[1];
		if (!Stream_SkipUntilByte(&rle.base.base.base, 0))
			return false;
		break;
	default:
		return false;
	}
	if (!RECOIL_SetSize(self, columns << 3, rows << 3, RECOILResolution_C641X1, 1))
		return false;
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			for (int y = 0; y < 8; y++) {
				int b = RleStream_ReadRle(&rle.base);
				if (b < 0)
					return false;
				for (int x = 0; x < 8; x++)
					self->pixels[((((row << 3) + y) * columns + column) << 3) + x] = (b >> (7 - x) & 1) == 0 ? 16777215 : 0;
			}
		}
	}
	return true;
}

static void RECOIL_DecodeC64FourColor(RECOIL *self, uint8_t const *content, int contentOffset, int frame)
{
	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < 320; x++) {
			int i = x - frame;
			int c = i < 0 ? 0 : content[contentOffset + (y & ~7) * 40 + (i & ~7) + (y & 7)] >> (~i & 6) & 3;
			self->pixels[(frame * self->height + y) * 320 + x] = self->contentPalette[c];
		}
	}
}

static bool RECOIL_DecodeCle(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 8194)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1, 1);
	self->contentPalette[0] = self->c64Palette[content[8004] & 15];
	self->contentPalette[1] = self->c64Palette[content[8002] >> 4];
	self->contentPalette[2] = self->c64Palette[content[8002] & 15];
	self->contentPalette[3] = self->c64Palette[content[8003] & 15];
	RECOIL_DecodeC64FourColor(self, content, 2, 0);
	return true;
}

static bool RECOIL_DecodeIle(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 4098)
		return false;
	RECOIL_SetSize(self, 320, 48, RECOILResolution_C641X1, 2);
	for (int i = 0; i < 4; i++)
		self->contentPalette[i] = self->c64Palette[content[4094 + i] & (i < 3 ? 15 : 7)];
	RECOIL_DecodeC64FourColor(self, content, 2050, 0);
	RECOIL_DecodeC64FourColor(self, content, 2, 1);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeCfli(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 8170)
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 1);
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 296; x++)
			self->pixels[y * 296 + x] = self->c64Palette[content[5 + ((y & 7) << 10) + (y & ~7) * 5 + (x >> 3)] >> ((~x & 1) << 2) & 15];
	}
	return true;
}

static bool RECOIL_IsGodot(uint8_t const *content, int contentLength)
{
	return content[0] == 'G' && content[1] == 'O' && content[2] == 'D' && content[contentLength - 1] == 173;
}

static bool RECOIL_DecodeGodot(RECOIL *self, int width, int height, uint8_t const *content, int contentOffset, int contentLength, bool compressed)
{
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_C641X1, 1))
		return false;
	UflStream rle;
	UflStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = 173;
	for (int row = 0; row < height; row += 8) {
		for (int column = 0; column < width; column += 8) {
			for (int y = 0; y < 8; y++) {
				int pixelsOffset = (row + y) * width + column;
				for (int x = 0; x < 4; x++) {
					int b = compressed ? RleStream_ReadRle(&rle.base) : Stream_ReadByte(&rle.base.base.base);
					if (b < 0)
						return false;
					static const uint8_t BY_BRIGHTNESS[16] = { 0, 6, 9, 11, 2, 4, 8, 12, 14, 10, 5, 15, 3, 7, 13, 1 };
					self->pixels[pixelsOffset++] = self->c64Palette[BY_BRIGHTNESS[b >> 4]];
					self->pixels[pixelsOffset++] = self->c64Palette[BY_BRIGHTNESS[b & 15]];
				}
			}
		}
	}
	return true;
}

static bool RECOIL_Decode4bt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 5)
		return false;
	if (contentLength == 32002 && content[0] == 0)
		return RECOIL_DecodeGodot(self, 320, 200, content, 2, contentLength, false);
	return content[3] == '0' && RECOIL_IsGodot(content, contentLength) && RECOIL_DecodeGodot(self, 320, 200, content, 4, contentLength - 1, true);
}

static bool RECOIL_DecodeGodotClp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength >= 9 && content[3] == '1' && RECOIL_IsGodot(content, contentLength) && RECOIL_DecodeGodot(self, content[6] << 3, content[7] << 3, content, 8, contentLength - 1, true);
}

static void RECOIL_DecodeC64HiresFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, bool afli, int stride, int pixelsOffset)
{
	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < self->width; x++) {
			int offset = (y & ~7) * stride + (x & ~7) + (y & 7);
			int c = content[bitmapOffset + offset] >> (~x & 7) & 1;
			int v;
			if (videoMatrixOffset >= 0) {
				offset >>= 3;
				if (afli)
					offset += (y & 7) << 10;
				v = content[videoMatrixOffset + offset];
			}
			else
				v = -videoMatrixOffset;
			c = c == 0 ? v & 15 : v >> 4;
			self->pixels[pixelsOffset + y * self->width + x] = self->c64Palette[c];
		}
	}
}

static bool RECOIL_DecodeC64Hires(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset)
{
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1, 1);
	RECOIL_DecodeC64HiresFrame(self, content, bitmapOffset, videoMatrixOffset, false, 40, 0);
	return true;
}

static bool RECOIL_DecodeRpo(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 8002 && RECOIL_DecodeC64Hires(self, content, 2, -1);
}

static bool RECOIL_DecodeGr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 10)
		return false;
	int columns = content[0];
	int height = content[1] << 3;
	if (contentLength != 2 + columns * height || !RECOIL_SetSize(self, columns << 3, height, RECOILResolution_C641X1, 1))
		return false;
	RECOIL_DecodeC64HiresFrame(self, content, 2, -1, false, columns, 0);
	return true;
}

static bool RECOIL_DecodeC64Hir(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 8002:
	case 8194:
		return RECOIL_DecodeC64Hires(self, content, 2, -16);
	default:
		return false;
	}
}

static bool RECOIL_DecodeIph(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 9002:
	case 9003:
	case 9009:
		return RECOIL_DecodeC64Hires(self, content, 2, 8002);
	default:
		return false;
	}
}

static bool RECOIL_DecodeHed(RECOIL *self, uint8_t const *content)
{
	return RECOIL_DecodeC64Hires(self, content, 2, 8194);
}

static bool RECOIL_DecodeJj(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[9024];
	C64KoalaStream rle;
	C64KoalaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_Unpack(&rle.base, unpacked, 0, 1, 9024) && RECOIL_DecodeC64Hires(self, unpacked, 1024, 0);
}

static bool RECOIL_DecodeDd(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 9026:
	case 9217:
	case 9218:
	case 9346:
		return RECOIL_DecodeC64Hires(self, content, 1026, 2);
	default:
		return RECOIL_DecodeJj(self, content, contentLength);
	}
}

static int RECOIL_GetC64Multicolor(const RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, bool bottomBfli, int x, int y, int strideColumns)
{
	x += self->leftSkip;
	if (x < 0)
		return background;
	int charOffset = (y >> 3) * strideColumns + (x >> 3);
	if (bottomBfli)
		charOffset = (charOffset - 21) & 1023;
	switch (content[bitmapOffset + (charOffset << 3) + (y & 7)] >> (~x & 6) & 3) {
	case 1:
		return content[videoMatrixOffset + charOffset] >> 4;
	case 2:
		return content[videoMatrixOffset + charOffset];
	case 3:
		return colorOffset < 0 ? content[-colorOffset] : content[colorOffset + charOffset];
	default:
		return background;
	}
}

static void RECOIL_DecodeC64MulticolorLine(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, bool bottomBfli, int y, int pixelsOffset, int width, int strideColumns)
{
	for (int x = 0; x < width; x++)
		self->pixels[pixelsOffset + x] = self->c64Palette[RECOIL_GetC64Multicolor(self, content, bitmapOffset, videoMatrixOffset, colorOffset, background, bottomBfli, x, y, strideColumns) & 15];
}

static void RECOIL_DecodeC64MulticolorFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset, int pixelsOffset)
{
	int background = backgroundOffset < 0 ? 0 : content[backgroundOffset];
	for (int y = 0; y < 200; y++)
		RECOIL_DecodeC64MulticolorLine(self, content, bitmapOffset, videoMatrixOffset, colorOffset, background, false, y, pixelsOffset + y * 320, 320, 40);
}

static bool RECOIL_DecodeC64Multicolor(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset)
{
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C642X1, 1);
	RECOIL_DecodeC64MulticolorFrame(self, content, bitmapOffset, videoMatrixOffset, colorOffset, backgroundOffset, 0);
	return true;
}

static bool RECOIL_DecodeIpt(RECOIL *self, uint8_t const *content)
{
	return RECOIL_DecodeC64Multicolor(self, content, 2, 8002, 9002, 10002);
}

static bool RECOIL_DecodeOcp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 10018 && RECOIL_DecodeC64Multicolor(self, content, 2, 8002, 9018, 9003);
}

static bool RECOIL_DecodeBpl(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 10242 && RECOIL_DecodeC64Multicolor(self, content, 2, 8194, 9218, 8066);
}

static void RECOIL_DecodeC64MulticolorFliFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, bool bottomBfli, int pixelsOffset)
{
	for (int y = 0; y < 200; y++)
		RECOIL_DecodeC64MulticolorLine(self, content, bitmapOffset, videoMatrixOffset + ((y & 7) << 10), colorOffset, background, bottomBfli, y, pixelsOffset + y * 296, 296, 40);
}

static void RECOIL_DecodeC64MulticolorFliBarsFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset, int pixelsOffset)
{
	for (int y = 0; y < 200; y++)
		RECOIL_DecodeC64MulticolorLine(self, content, bitmapOffset, videoMatrixOffset + ((y & 7) << 10), colorOffset, content[backgroundOffset + y], false, y, pixelsOffset + y * 296, 296, 40);
}

static bool RECOIL_DecodeC64MulticolorFli(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background)
{
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C642X1, 1);
	RECOIL_DecodeC64MulticolorFliFrame(self, content, bitmapOffset + 24, videoMatrixOffset + 3, colorOffset + 3, background, false, 0);
	return true;
}

static bool RECOIL_DecodeC64MulticolorFliBars(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int backgroundOffset)
{
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C642X1, 1);
	RECOIL_DecodeC64MulticolorFliBarsFrame(self, content, bitmapOffset + 24, videoMatrixOffset + 3, colorOffset + 3, backgroundOffset, 0);
	return true;
}

static bool RECOIL_DecodeHfc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 16386)
		return false;
	RECOIL_SetSize(self, 296, 112, RECOILResolution_C641X1, 1);
	RECOIL_DecodeC64HiresFrame(self, content, 26, 8197, true, 40, 0);
	return true;
}

static bool RECOIL_DecodeAfl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 16385)
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 1);
	RECOIL_DecodeC64HiresFrame(self, content, 8218, 5, true, 40, 0);
	return true;
}

static bool RECOIL_DecodePmg(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 9332 && RECOIL_DecodeC64Multicolor(self, content, 116, 8308, -8119, 8116);
}

static bool RECOIL_DecodeKoa(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 10001:
		return RECOIL_DecodeC64Multicolor(self, content, 0, 8000, 9000, 10000);
	case 10003:
	case 10006:
		return RECOIL_DecodeIpt(self, content);
	default:
		return RECOIL_DecodeGg(self, content, contentLength);
	}
}

static bool RECOIL_DecodeZom(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 6)
		return false;
	uint8_t unpacked[10001];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength - 1;
	rle.base.escape = content[contentLength - 1];
	return RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 10000) && RECOIL_DecodeKoa(self, unpacked, 10001);
}

static bool RECOIL_DecodeKoaPacked(RECOIL *self, RleStream *rle)
{
	uint8_t unpacked[10001];
	return RleStream_Unpack(rle, unpacked, 0, 1, 10001) && RECOIL_DecodeKoa(self, unpacked, 10001);
}

static bool RECOIL_DecodeGg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 2)
		return false;
	C64KoalaStream rle;
	C64KoalaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	return RECOIL_DecodeKoaPacked(self, &rle.base);
}

static bool RECOIL_DecodeDol(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 10241:
	case 10242:
	case 10050:
		return RECOIL_DecodeC64Multicolor(self, content, 2050, 1026, 2, 2026);
	default:
		return false;
	}
}

static bool RECOIL_DecodeAmi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 2)
		return false;
	DrpStream rle;
	DrpStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = 194;
	return RECOIL_DecodeKoaPacked(self, &rle.base);
}

static bool RECOIL_DecodeBdp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 13)
		return false;
	if (content[2] == 2 && content[3] == 4 && content[4] == 16 && content[5] == 54 && content[6] == 48 && content[7] == 48) {
		UflStream rle;
		UflStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 10;
		rle.base.base.base.contentLength = contentLength;
		rle.escape = content[8];
		return RECOIL_DecodeKoaPacked(self, &rle.base);
	}
	if (RECOIL_IsStringAt(content, 2, "BDP 5.00")) {
		Bdp5Stream rle;
		Bdp5Stream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 12;
		rle.base.base.base.contentLength = contentLength;
		return RECOIL_DecodeKoaPacked(self, &rle.base);
	}
	else {
		Bdp4Stream rle;
		Bdp4Stream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 2;
		rle.base.base.base.contentLength = contentLength;
		return RECOIL_DecodeKoaPacked(self, &rle.base);
	}
}

static bool RECOIL_DecodeMwi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 7)
		return false;
	int width = content[3] << 1;
	int height = content[4];
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_C642X1, 1))
		return false;
	int charactersPerRow = (width + 7) >> 3;
	int left = (content[1] & 3) << 1;
	if (left != 0)
		charactersPerRow++;
	int rows = (height + 7) >> 3;
	int top = content[2] & 7;
	if (top != 0)
		rows++;
	if (contentLength != 5 + rows * charactersPerRow * 10)
		return false;
	for (int y = 0; y < height; y++) {
		int screenY = top + y;
		for (int x = 0; x < width; x++) {
			int screenX = left + x;
			int offset = 5 + ((screenY >> 3) * charactersPerRow + (screenX >> 3)) * 10;
			int c;
			switch (content[offset + 2 + (screenY & 7)] >> (~screenX & 6) & 3) {
			case 1:
				c = content[offset] >> 4;
				break;
			case 2:
				c = content[offset];
				break;
			case 3:
				c = content[offset + 1];
				break;
			default:
				c = 0;
				break;
			}
			self->pixels[y * width + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeC64Shp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8)
		return false;
	int columns = 40;
	int height = 200;
	UflStream rle;
	UflStream_Construct(&rle);
	switch (content[2]) {
	case 0:
		rle.escape = content[3];
		rle.base.base.base.contentOffset = 5;
		break;
	case 128:
		rle.escape = content[3];
		rle.base.base.base.contentOffset = 4;
		break;
	case 167:
		if (content[3] != 25)
			return false;
		columns = 39;
		rle.escape = content[4];
		rle.base.base.base.contentOffset = 5;
		break;
	case 168:
		height = content[3] << 3;
		if (height == 0 || height > 200)
			return false;
		rle.escape = content[4];
		rle.base.base.base.contentOffset = 5;
		break;
	case 232:
		if (content[3] != 25)
			return false;
		rle.escape = content[5];
		rle.base.base.base.contentOffset = 6;
		break;
	default:
		return false;
	}
	rle.base.base.base.content = content;
	rle.base.base.base.contentLength = contentLength;
	int bitmapLength = height * columns;
	uint8_t unpacked[10001];
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, bitmapLength))
		return false;
	rle.escape = 0;
	if (!RleStream_Unpack(&rle.base, unpacked, bitmapLength, 1, (bitmapLength >> 3) * 9))
		return false;
	switch (content[2]) {
	case 0:
		rle.escape = 255;
		break;
	case 232:
		if (Stream_ReadByte(&rle.base.base.base) != 255)
			return false;
		rle.escape = 216;
		break;
	default:
		if (rle.base.base.base.contentOffset != contentLength)
			return false;
		RECOIL_SetSize(self, columns << 3, height, RECOILResolution_C641X1, 1);
		RECOIL_DecodeC64HiresFrame(self, unpacked, 0, bitmapLength, false, columns, 0);
		return true;
	}
	unpacked[10000] = content[4];
	return RleStream_Unpack(&rle.base, unpacked, 9000, 1, 10000) && rle.base.base.base.contentOffset == contentLength && RECOIL_DecodeKoa(self, unpacked, 10001);
}

static bool RECOIL_DecodeC64HiresInterlace(RECOIL *self, uint8_t const *content, int bitmap1Offset, int videoMatrix1Offset, int bitmap2Offset, int videoMatrix2Offset)
{
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeC64HiresFrame(self, content, bitmap1Offset, videoMatrix1Offset, false, 40, 0);
	RECOIL_DecodeC64HiresFrame(self, content, bitmap2Offset, videoMatrix2Offset, false, 40, 64000);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeIhe(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 16194 && RECOIL_DecodeC64HiresInterlace(self, content, 2, -12, 8194, -12);
}

static bool RECOIL_DecodeHlf(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 24578 && RECOIL_DecodeC64HiresInterlace(self, content, 2, 10242, 16386, 9218);
}

static bool RECOIL_DecodeHle(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 32770 && RECOIL_DecodeC64HiresInterlace(self, content, 2, 8194, 24578, 16386);
}

static bool RECOIL_DecodeVhi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 17389)
		return RECOIL_DecodeC64HiresInterlace(self, content, 2, 16386, 8194, 16386);
	uint8_t unpacked[17384];
	VhiStream rle;
	VhiStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_Unpack(&rle.base, unpacked, 0, 1, 17384) && RECOIL_DecodeC64HiresInterlace(self, unpacked, 0, 16384, 8192, 16384);
}

static bool RECOIL_DecodeMciLike(RECOIL *self, uint8_t const *content, int bitmap1Offset, int videoMatrix1Offset, int bitmap2Offset, int videoMatrix2Offset, int colorOffset, int backgroundOffset, int shift)
{
	RECOIL_SetSize(self, 320, 200, shift == 0 ? RECOILResolution_C642X1 : RECOILResolution_C641X1, 2);
	RECOIL_DecodeC64MulticolorFrame(self, content, bitmap1Offset, videoMatrix1Offset, colorOffset, backgroundOffset, 0);
	self->leftSkip = -shift;
	RECOIL_DecodeC64MulticolorFrame(self, content, bitmap2Offset, videoMatrix2Offset, colorOffset, backgroundOffset, 64000);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeFp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 19266 && RECOIL_DecodeMciLike(self, content, 3074, 1026, 11266, 2050, 2, 11074, 1);
}

static bool RECOIL_DecodeMciUnpacked(RECOIL *self, uint8_t const *content)
{
	return RECOIL_DecodeMciLike(self, content, 1026, 2, 9218, 17410, 18434, 1002, 1);
}

static bool RECOIL_DecodeMci(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 19434)
		return RECOIL_DecodeMciUnpacked(self, content);
	if (contentLength < 142)
		return false;
	uint8_t unpacked[19434];
	MciStream rle;
	MciStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentLength - 1;
	return RleStream_UnpackBackwards(&rle.base, unpacked, 2, 19433) && RECOIL_DecodeMciUnpacked(self, unpacked);
}

static bool RECOIL_DecodeDrz(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[10051];
	uint8_t const *source = DrpStream_UnpackFile(content, contentLength, "DRAZPAINT 1.4", unpacked, 10051);
	return source != NULL && RECOIL_DecodeC64Multicolor(self, source, 2050, 1026, 2, 10050);
}

static bool RECOIL_DecodeDrl(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[18242];
	uint8_t const *source = DrpStream_UnpackFile(content, contentLength, "DRAZLACE! 1.0", unpacked, 18242);
	if (source == NULL)
		return false;
	int shift = source[10052];
	return shift <= 1 && RECOIL_DecodeMciLike(self, source, 2050, 1026, 10242, 1026, 2, 10050, shift);
}

static void RECOIL_DecodeMleFrame(RECOIL *self, uint8_t const *content, int contentOffset, int pixelsOffset)
{
	for (int y = 0; y < 56; y++) {
		for (int x = 0; x < 320; x++) {
			int c = 0;
			int i = x + self->leftSkip;
			if (i >= 0) {
				int ch = (y >> 3) * 40 + (i >> 3);
				if (ch < 256) {
					static const uint8_t COLORS[4] = { 0, 9, 8, 5 };
					c = COLORS[content[contentOffset + (ch << 3) + (y & 7)] >> (~i & 6) & 3];
				}
			}
			self->pixels[pixelsOffset + y * self->width + x] = self->c64Palette[c];
		}
	}
}

static bool RECOIL_DecodeMle(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 4098)
		return false;
	RECOIL_SetSize(self, 320, 56, RECOILResolution_C641X1, 2);
	RECOIL_DecodeMleFrame(self, content, 2050, 0);
	self->leftSkip = -1;
	RECOIL_DecodeMleFrame(self, content, 2, 17920);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeHcb(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 12148)
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C642X1, 1);
	for (int y = 0; y < 200; y++)
		RECOIL_DecodeC64MulticolorLine(self, content, 4122, 2053 + ((y & 4) << 8), 2053 + ((y & 4) << 8), content[12098 + (y >> 2)], false, y, y * 296, 296, 40);
	return true;
}

static bool RECOIL_DecodeFed(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 17665 && RECOIL_DecodeC64MulticolorFliBars(self, content, 9474, 1282, 258, 8);
}

static bool RECOIL_DecodeHimUnpacked(RECOIL *self, uint8_t const *content)
{
	RECOIL_SetSize(self, 296, 192, RECOILResolution_C641X1, 1);
	RECOIL_DecodeC64HiresFrame(self, content, 346, 8237, true, 40, 0);
	return true;
}

static bool RECOIL_DecodeHim(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 18 || content[0] != 0 || content[1] != 64)
		return false;
	if (content[3] == 255)
		return contentLength == 16385 && RECOIL_DecodeHimUnpacked(self, content);
	if (content[2] + (content[3] << 8) != 16381 + contentLength || content[4] != 242 || content[5] != 127)
		return false;
	uint8_t unpacked[16372];
	HimStream rle;
	HimStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentLength - 1;
	return RleStream_UnpackBackwards(&rle.base, unpacked, 322, 16371) && RECOIL_DecodeHimUnpacked(self, unpacked);
}

static bool RECOIL_DecodeEci(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 32770)
		return RECOIL_DecodeEcp(self, content, contentLength);
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeC64HiresFrame(self, content, 26, 8197, true, 40, 0);
	RECOIL_DecodeC64HiresFrame(self, content, 16410, 24581, true, 40, 59200);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeEcp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 6)
		return false;
	uint8_t unpacked[32770];
	DrpStream rle;
	DrpStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = content[2];
	return RleStream_Unpack(&rle.base, unpacked, 2, 1, 32770) && RECOIL_DecodeEci(self, unpacked, 32770);
}

static bool RECOIL_DecodeFli(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 17218:
	case 17409:
		return RECOIL_DecodeC64MulticolorFli(self, content, 9218, 1026, 2, 0);
	default:
		return false;
	}
}

static bool RECOIL_DecodeFbi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 19)
		return false;
	uint8_t unpacked[17216];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = content[2];
	return RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 17215) && RECOIL_DecodeC64MulticolorFli(self, unpacked, 9216, 1024, 0, 0);
}

static bool RECOIL_DecodeBml(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 17474:
	case 17665:
	case 17666:
		return RECOIL_DecodeC64MulticolorFliBars(self, content, 9474, 1282, 258, 2);
	default:
		if (contentLength < 5)
			return false;
		uint8_t unpacked[17472];
		UifStream rle;
		UifStream_Construct(&rle);
		rle.base.base.base.base.content = content;
		rle.base.base.base.base.contentOffset = contentLength;
		rle.base.escape = content[2];
		return RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 17471) && RECOIL_DecodeC64MulticolorFliBars(self, unpacked, 9472, 1280, 256, 0);
	}
}

static bool RECOIL_DecodeEmc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 17412)
		return false;
	RECOIL_SetSize(self, 296, 192, RECOILResolution_C642X1, 1);
	for (int y = 0; y < 192; y++)
		RECOIL_DecodeC64MulticolorLine(self, content, 8218, 5 + (((y + 4) & 7) << 10), 16389, content[17411], false, y + 4, y * 296, 296, 40);
	return true;
}

static bool RECOIL_DecodeFlm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 17410)
		return RECOIL_DecodeC64MulticolorFli(self, content, 9218, 1026, 2, content[17281]);
	if (contentLength < 6)
		return false;
	uint8_t unpacked[17280];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = ((const RleStreamVtbl *) rle.base.base.base.vtbl)->readValue(&rle.base.base);
	if (!RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 17279))
		return false;
	for (int i = 0; i < 1000; i++) {
		if (unpacked[i] != 0)
			return RECOIL_DecodeC64MulticolorFli(self, unpacked, 9216, 1024, 0, unpacked[17279]);
	}
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 1);
	RECOIL_DecodeC64HiresFrame(self, unpacked, 9240, 1027, true, 40, 0);
	return true;
}

static bool RECOIL_DecodeFfli(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 26115 || content[2] != 'f')
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C642X1, 2);
	RECOIL_DecodeC64MulticolorFliBarsFrame(self, content, 9499, 1286, 262, 3, 0);
	RECOIL_DecodeC64MulticolorFliBarsFrame(self, content, 9499, 17670, 262, 25859, 59200);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeIfli(RECOIL *self, uint8_t const *content, int bitmap1Offset, int bitmap2Offset, int videoMatrix1Offset, int videoMatrix2Offset, int colorOffset, int background)
{
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeC64MulticolorFliFrame(self, content, bitmap1Offset + 24, videoMatrix1Offset + 3, colorOffset + 3, background, false, 0);
	self->leftSkip = -1;
	RECOIL_DecodeC64MulticolorFliFrame(self, content, bitmap2Offset + 24, videoMatrix2Offset + 3, colorOffset + 3, background, false, 59200);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodePpUnpacked(RECOIL *self, uint8_t const *content)
{
	return RECOIL_DecodeIfli(self, content, 9218, 25602, 1026, 17410, 2, content[17281]);
}

static bool RECOIL_DecodePp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8)
		return false;
	if (content[2] == 16 && content[3] == 16 && content[4] == 16) {
		uint8_t unpacked[33602];
		CmpStream rle;
		CmpStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 6;
		rle.base.base.base.contentLength = contentLength;
		rle.escape = content[5];
		return RleStream_Unpack(&rle.base, unpacked, 2, 1, 33602) && RleStream_ReadRle(&rle.base) < 0 && RECOIL_DecodePpUnpacked(self, unpacked);
	}
	return contentLength == 33602 && RECOIL_DecodePpUnpacked(self, content);
}

static bool RECOIL_DecodeFunUnpacked(RECOIL *self, uint8_t const *content)
{
	return RECOIL_DecodeIfli(self, content, 8210, 25594, 18, 17402, 16402, 0);
}

static bool RECOIL_DecodeC64Fun(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 18 || !RECOIL_IsStringAt(content, 2, "FUNPAINT (MT) "))
		return false;
	if (content[16] != 0) {
		uint8_t unpacked[33694];
		DrpStream rle;
		DrpStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 18;
		rle.base.base.base.contentLength = contentLength;
		rle.escape = content[17];
		return RleStream_Unpack(&rle.base, unpacked, 18, 1, 33694) && RleStream_ReadRle(&rle.base) < 0 && RECOIL_DecodeFunUnpacked(self, unpacked);
	}
	return contentLength == 33694 && RECOIL_DecodeFunUnpacked(self, content);
}

static void RECOIL_DecodeGunFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int pixelsOffset)
{
	for (int y = 0; y < 200; y++) {
		int background = content[y < 177 ? 16209 + y : y < 197 ? 18233 + y : 18429];
		RECOIL_DecodeC64MulticolorLine(self, content, bitmapOffset + 24, videoMatrixOffset + 3 + ((y & 7) << 10), 16389, background, false, y, pixelsOffset + y * 296, 296, 40);
	}
}

static bool RECOIL_DecodeGun(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 33602 && contentLength != 33603)
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeGunFrame(self, content, 8194, 2, 0);
	self->leftSkip = -1;
	RECOIL_DecodeGunFrame(self, content, 25602, 17410, 59200);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeBfli(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 33795 || content[2] != 'b')
		return false;
	RECOIL_SetSize(self, 296, 400, RECOILResolution_C642X1, 1);
	RECOIL_DecodeC64MulticolorFliFrame(self, content, 9243, 1030, 6, 0, false, 0);
	RECOIL_DecodeC64MulticolorFliFrame(self, content, 25603, 17411, 3, 0, true, 59200);
	return true;
}

static bool RECOIL_DecodeLp3(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 4098:
	case 4174:
		break;
	default:
		return false;
	}
	if (content[0] != 0 || content[1] != 24)
		return false;
	RECOIL_SetSize(self, 320, 400, RECOILResolution_C642X1, 1);
	uint8_t colors[4];
	if (contentLength == 4174) {
		colors[0] = (uint8_t) (content[2045] & 15);
		colors[1] = (uint8_t) (content[2047] & 15);
		colors[2] = (uint8_t) (content[2048] & 15);
		colors[3] = (uint8_t) (content[2046] & 7);
	}
	else {
		colors[0] = 0;
		colors[1] = 10;
		colors[2] = 2;
		colors[3] = 1;
	}
	for (int y = 0; y < 400; y++) {
		for (int x = 0; x < 320; x++) {
			int c = content[2 + (y >> 3) * 40 + (x >> 3)];
			c = content[2050 + (c << 3) + (y & 7)] >> (~x & 6) & 3;
			self->pixels[y * 320 + x] = self->c64Palette[colors[c]];
		}
	}
	return true;
}

static bool RECOIL_DecodeMilPacked(RECOIL *self, uint8_t const *content, int contentLength, bool vertical)
{
	uint8_t unpacked[10000];
	XeKoalaStream rle;
	XeKoalaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 22;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 10000))
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C642X1, 1);
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 320; x++) {
			int column = x >> 3;
			int charOffset = vertical ? column * 25 + (y >> 3 & 1) * 13 + (y >> 4) : (y & ~7) * 5 + column;
			int c;
			switch (unpacked[2000 + (vertical ? column * 200 + (y & 1) * 100 + (y >> 1) : y * 40 + column)] >> (~x & 6) & 3) {
			case 1:
				c = unpacked[charOffset] >> 4;
				break;
			case 2:
				c = unpacked[charOffset];
				break;
			case 3:
				c = unpacked[1000 + charOffset];
				break;
			default:
				c = content[8];
				break;
			}
			self->pixels[y * 320 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeMil(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 26)
		return false;
	switch (content[7]) {
	case 0:
		return contentLength == 10022 && RECOIL_DecodeC64Multicolor(self, content, 2022, 22, 1022, 8);
	case 1:
		return RECOIL_DecodeMilPacked(self, content, contentLength, true);
	case 2:
		return RECOIL_DecodeMilPacked(self, content, contentLength, false);
	default:
		return false;
	}
}

static bool RECOIL_DecodeVic(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 9002:
	case 9003:
	case 9009:
		return RECOIL_DecodeIph(self, content, contentLength);
	case 10018:
		return RECOIL_DecodeOcp(self, content, contentLength);
	case 10241:
		return RECOIL_DecodeDol(self, content, contentLength);
	case 10242:
		return RECOIL_DecodeBpl(self, content, contentLength);
	case 17218:
	case 17409:
		return RECOIL_DecodeFli(self, content, contentLength);
	case 17410:
		return RECOIL_DecodeFlm(self, content, contentLength);
	case 17474:
	case 17665:
	case 17666:
		return RECOIL_DecodeBml(self, content, contentLength);
	case 18242:
		return RECOIL_DecodeDrl(self, content, contentLength);
	case 33602:
	case 33603:
		return RECOIL_DecodeGun(self, content, contentLength);
	case 33694:
		return RECOIL_DecodeC64Fun(self, content, contentLength);
	default:
		return false;
	}
}

static bool RECOIL_DecodeA(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 8130 || content[0] != 66 || content[1] != 0)
		return false;
	RECOIL_SetSize(self, 416, 182, RECOILResolution_C642X1, 1);
	for (int y = 0; y < 182; y++) {
		for (int x = 0; x < 416; x++) {
			int c = 11;
			int row = y % 23;
			if (row < 21) {
				int column = x % 26;
				if (column < 24) {
					int spriteNo = x / 26 + (y / 23 << 4);
					if (spriteNo < 127) {
						int spriteOffset = 2 + (spriteNo << 6);
						switch (content[spriteOffset + row * 3 + (column >> 3)] >> (~column & 6) & 3) {
						case 1:
							c = 0;
							break;
						case 2:
							c = content[spriteOffset + 63] & 15;
							break;
						case 3:
							c = 1;
							break;
						default:
							break;
						}
					}
				}
			}
			self->pixels[y * 416 + x] = self->c64Palette[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeSpd(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 67)
		return false;
	int headerLength;
	int spriteCount;
	if (content[0] == 'S' && content[1] == 'P' && content[2] == 'D' && content[3] == 1) {
		headerLength = 6;
		spriteCount = content[4] + 1;
		if (contentLength < 9 + (spriteCount << 6))
			return false;
	}
	else {
		if ((contentLength & 63) != 3 || content[0] > 15 || content[1] > 15 || content[2] > 15)
			return false;
		headerLength = 0;
		spriteCount = contentLength >> 6;
	}
	RECOILResolution resolution = RECOILResolution_C642X1;
	for (int spriteNo = 0; spriteNo < spriteCount; spriteNo++) {
		if (content[headerLength + 66 + (spriteNo << 6)] < 128) {
			resolution = RECOILResolution_C641X1;
			break;
		}
	}
	int width;
	int height;
	if (spriteCount <= 16) {
		width = spriteCount * 26 - 2;
		height = 21;
	}
	else {
		width = 414;
		height = ((spriteCount + 15) >> 4) * 23 - 2;
	}
	if (!RECOIL_SetSize(self, width, height, resolution, 1))
		return false;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int c = 0;
			int row = y % 23;
			if (row < 21) {
				int column = x % 26;
				if (column < 24) {
					int spriteNo = x / 26 + (y / 23 << 4);
					if (spriteNo < spriteCount) {
						int spriteOffset = 3 + (spriteNo << 6);
						int b = content[headerLength + spriteOffset + row * 3 + (column >> 3)];
						if (content[headerLength + spriteOffset + 63] < 128) {
							if ((b >> (~column & 7) & 1) != 0)
								c = spriteOffset + 63;
						}
						else {
							switch (b >> (~column & 6) & 3) {
							case 1:
								c = 1;
								break;
							case 2:
								c = spriteOffset + 63;
								break;
							case 3:
								c = 2;
								break;
							default:
								break;
							}
						}
					}
				}
			}
			self->pixels[y * width + x] = self->c64Palette[content[headerLength + c] & 15];
		}
	}
	return true;
}

static int RECOIL_GetAtari8Gr0Pixel(uint8_t const *font, int fontOffset, int ch, int x, int y)
{
	return (font[fontOffset + ((ch & 127) << 3) + (y & 7)] >> (~x & 7) ^ ch >> 7) & 1;
}

static bool RECOIL_DecodePetScreenCustom(RECOIL *self, uint8_t const *content, int screenOffset, int fontOffset, uint8_t const *colors, int colorsOffset, int background, int columns, int rows)
{
	int width = columns << 3;
	int height = rows << 3;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_C641X1, 1))
		return false;
	uint8_t const *font = FuResource_c64_fnt;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int offset = (y >> 3) * columns + (x >> 3);
			int ch = content[screenOffset + offset];
			int c;
			if ((fontOffset == 0 ? RECOIL_GetAtari8Gr0Pixel(font, 0, ch, x, y) : content[fontOffset + (ch << 3) + (y & 7)] >> (~x & 7) & 1) == 0)
				c = background;
			else
				c = colors[colorsOffset + offset];
			self->pixels[y * width + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodePetScreen(RECOIL *self, uint8_t const *content, int screenOffset, int colorsOffset, int background, int columns, int rows)
{
	return RECOIL_DecodePetScreenCustom(self, content, screenOffset, 0, content, colorsOffset, background, columns, rows);
}

static bool RECOIL_DecodePet(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 2026:
		return RECOIL_DecodePetScreen(self, content, 2, 1026, content[1003], 40, 25);
	case 4105:
		return content[0] == 208 && content[1] == 197 && content[2] == 212 && content[3] == '2' && RECOIL_DecodePetScreenCustom(self, content, 55, 2057, content, 1055, content[2056], 40, 25);
	default:
		return false;
	}
}

static bool RECOIL_DecodePdr(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 2029 && RECOIL_DecodePetScreen(self, content, 5, 1029, content[3], 40, 25);
}

static bool RECOIL_DecodePbot(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 70:
		return RECOIL_DecodePetScreen(self, content, 35, 0, 0, 5, 7);
	case 384:
		return RECOIL_DecodePetScreen(self, content, 192, 0, 0, 12, 16);
	default:
		return false;
	}
}

static bool RECOIL_DecodeScrCol(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength != 1002)
		return false;
	uint8_t colors[1003];
	return RECOIL_ReadCompanionFile(self, filename, "COL", "col", colors, 1003) == 1002 && RECOIL_DecodePetScreenCustom(self, content, 2, 0, colors, 2, 0, 40, 25);
}

static bool RECOIL_DecodeCgx(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 40 || !RECOIL_IsStringAt(content, 0, "RIFF") || RECOIL_Get32LittleEndian(content, 4) + 8 != contentLength || !RECOIL_IsStringAt(content, 8, "CGFX"))
		return false;
	int contentOffset = 12;
	int matrixRows = 0;
	int matrixColumns = 0;
	int frameRows = 0;
	int frameColumns = 0;
	while (contentOffset + 8 <= contentLength) {
		int chunkLength = RECOIL_Get32LittleEndian(content, contentOffset + 4);
		int nextChunkOffset = contentOffset + 8 + chunkLength;
		if (nextChunkOffset < 0 || nextChunkOffset > contentLength)
			return false;
		if (RECOIL_IsStringAt(content, contentOffset, "FRMT") && chunkLength == 12) {
			matrixRows = content[contentOffset + 8];
			matrixColumns = content[contentOffset + 9];
			frameRows = content[contentOffset + 16];
			frameColumns = content[contentOffset + 17];
			if (content[contentOffset + 12] != matrixRows * matrixColumns || content[contentOffset + 18] != 4 || content[contentOffset + 19] != 0)
				return false;
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "DATA")) {
			int frameChars = frameRows * frameColumns;
			int frameLength = frameChars * 10 + 2;
			int frames = matrixRows * matrixColumns;
			int width = matrixColumns * frameColumns << 3;
			int height = matrixRows * frameRows << 3;
			if (chunkLength != frames * frameLength || !RECOIL_SetSize(self, width, height, RECOILResolution_C642X1, 1))
				return false;
			for (int matrixRow = 0; matrixRow < matrixRows; matrixRow++) {
				for (int matrixColumn = 0; matrixColumn < matrixColumns; matrixColumn++) {
					int frameOffset = contentOffset + 8 + (matrixRow * matrixColumns + matrixColumn) * frameLength;
					int background = content[frameOffset + frameLength - 1];
					int pixelsOffset = (matrixRow * frameRows * width + matrixColumn * frameColumns) << 3;
					for (int y = 0; y < frameRows << 3; y++)
						RECOIL_DecodeC64MulticolorLine(self, content, frameOffset, frameOffset + (frameChars << 3), frameOffset + frameChars * 9, background, false, y, pixelsOffset + y * width, frameColumns << 3, frameColumns);
				}
			}
			return true;
		}
		else if (!RECOIL_IsStringAt(content, contentOffset, "META"))
			return false;
		contentOffset = nextChunkOffset;
	}
	return false;
}

static bool RECOIL_DecodeFpr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 18370)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C642X1, 1);
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 320; x++) {
			int offset = (y >> 3) * 40 + (x >> 3);
			int c = x < 24 ? 255 : content[2178 + offset + ((y & 7) << 10)];
			switch (content[10370 + (offset << 3) + (y & 7)] >> (~x & 6) & 3) {
			case 0:
				c = 0;
				break;
			case 1:
				c >>= 4;
				break;
			case 3:
				c = x < 24 ? content[898 + y] >> 4 : content[1154 + offset];
				break;
			default:
				break;
			}
			if (x < 24) {
				switch (content[2 + (((((y + 1) & 2) != 0 ? 5 : 0) + y / 42) << 6) + (y >> 1) % 21 * 3 + (x >> 3)] >> (~x & 6) & 3) {
				case 1:
					c = content[642 + y];
					break;
				case 2:
					c = content[1098];
					break;
				case 3:
					c = content[1099];
					break;
				default:
					break;
				}
			}
			self->pixels[y * 320 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeCtm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 30 || content[0] != 'C' || content[1] != 'T' || content[2] != 'M' || content[3] != 5)
		return false;
	int colorMethod = content[8];
	if (colorMethod > 2)
		return false;
	int flags = content[9];
	bool tiles = (flags & 1) != 0;
	if (colorMethod == 1 && !tiles)
		return false;
	bool charex = (flags & 2) != 0;
	bool multi = (flags & 4) != 0;
	int charCount = content[10] + (content[11] << 8) + 1;
	int tileCount = tiles ? content[12] + (content[13] << 8) + 1 : 0;
	int tileWidth = tiles ? content[14] : 1;
	int tileHeight = tiles ? content[15] : 1;
	if (tileWidth == 0 || tileHeight == 0)
		return false;
	int mapWidth = content[16] | content[17] << 8;
	int mapHeight = content[18] | content[19] << 8;
	int tilesOffset = 20 + charCount * 9;
	int tileColorsOffset = charex ? tilesOffset : tilesOffset + tileCount * (tileWidth * tileHeight << 1);
	int mapOffset = colorMethod == 1 ? tileColorsOffset + tileCount : tileColorsOffset;
	if (contentLength != mapOffset + (mapWidth * mapHeight << 1))
		return false;
	int width = mapWidth * tileWidth << 3;
	int height = mapHeight * tileHeight << 3;
	if (!RECOIL_SetSize(self, width, height, multi ? RECOILResolution_C642X1 : RECOILResolution_C641X1, 1))
		return false;
	for (int y = 0; y < height; y++) {
		int mapRowOffset = mapOffset + ((y >> 3) / tileHeight * mapWidth << 1);
		for (int x = 0; x < width; x++) {
			int mapTileOffset = mapRowOffset + ((x >> 3) / tileWidth << 1);
			int tile = content[mapTileOffset] | content[mapTileOffset + 1] << 8;
			int ch;
			if (tiles) {
				if (tile >= tileCount)
					return false;
				ch = (tile * tileHeight + (y >> 3) % tileHeight) * tileWidth + (x >> 3) % tileWidth;
				if (!charex) {
					int tileOffset = tilesOffset + (ch << 1);
					ch = content[tileOffset] | content[tileOffset + 1] << 8;
				}
			}
			else
				ch = tile;
			if (ch >= charCount)
				return false;
			int foregroundOffset;
			switch (colorMethod) {
			case 1:
				foregroundOffset = tileColorsOffset + tile;
				break;
			case 2:
				foregroundOffset = 20 + (charCount << 3) + ch;
				break;
			default:
				foregroundOffset = 7;
				break;
			}
			int c = content[20 + (ch << 3) + (y & 7)];
			if (multi) {
				c = c >> (~x & 6) & 3;
				if (c == 3)
					c = content[foregroundOffset] & 7;
				else
					c = content[4 + c];
			}
			else {
				c = c >> (~x & 7) & 1;
				c = content[c == 0 ? 4 : foregroundOffset];
			}
			self->pixels[y * width + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static void RECOIL_DecodeEshFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int spriteOffset, int pixelsOffset)
{
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 192; x++) {
			int bit = ~x & 7;
			int column = x >> 3;
			int c;
			if ((content[spriteOffset + (((y / 21 << 3) + column / 3) << 6) + y % 21 * 3 + column % 3] >> bit & 1) != 0)
				c = content[20443 + column / 3];
			else {
				int offset = (y & ~7) * 3 + column;
				c = content[19843 + offset] >> ((content[bitmapOffset + (offset << 3) + (y & 7)] >> bit & 1) << 2);
			}
			self->pixels[pixelsOffset + y * 192 + x] = self->c64Palette[c & 15];
		}
	}
}

static bool RECOIL_DecodeEshUnpacked(RECOIL *self, uint8_t const *content)
{
	RECOIL_SetSize(self, 192, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeEshFrame(self, content, 3, 9603, 0);
	RECOIL_DecodeEshFrame(self, content, 4803, 14723, 38400);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeEsh(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 5)
		return false;
	if (content[2] == 0)
		return contentLength == 20454 && RECOIL_DecodeEshUnpacked(self, content);
	uint8_t unpacked[20452];
	PgcStream rle;
	PgcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_Unpack(&rle.base, unpacked, 3, 1, 20452) && RECOIL_DecodeEshUnpacked(self, unpacked);
}

static bool RECOIL_DecodeShx(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 15362) {
		RECOIL_SetSize(self, 144, 168, RECOILResolution_C641X1, 1);
		for (int y = 0; y < 168; y++) {
			for (int x = 0; x < 144; x++) {
				int bit = ~x & 7;
				int column = x >> 3;
				int spriteInLine = column / 3;
				int spriteNo = ((y - 1) & 7) * 15 + spriteInLine;
				if (spriteNo < 105)
					spriteNo += ((spriteInLine + 1) >> 1) * 3;
				int c;
				if ((content[8194 + (spriteNo << 6) + y % 21 * 3 + column % 3] >> bit & 1) != 0)
					c = content[1003];
				else {
					int offset = (y & ~7) * 5 + column;
					c = content[13 + ((y & 7) << 10) + offset] >> ((content[8282 + (offset << 3) + (y & 7)] >> bit & 1) << 2);
				}
				self->pixels[y * 144 + x] = self->c64Palette[c & 15];
			}
		}
		return true;
	}
	if (contentLength < 6)
		return false;
	uint8_t unpacked[9168];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = ((const RleStreamVtbl *) rle.base.base.base.vtbl)->readValue(&rle.base.base);
	if (!RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 9167))
		return false;
	RECOIL_SetSize(self, 144, 168, RECOILResolution_C641X1, 1);
	for (int y = 0; y < 168; y++) {
		for (int x = 0; x < 144; x++) {
			int bit = ~x & 7;
			int offset = y * 18 + (x >> 3);
			int c;
			if ((unpacked[offset] >> bit & 1) != 0)
				c = unpacked[3025];
			else
				c = unpacked[6144 + offset] >> ((unpacked[3072 + offset] >> bit & 1) << 2);
			self->pixels[y * 144 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static int RECOIL_GetShsPixel(uint8_t const *content, int x, int y)
{
	int bit = ~x & 7;
	int column = x >> 3;
	if (y >= 17 && y < 185 && column >= 2 && column < 14) {
		int spriteColumn = column - 2;
		int spriteInLine = spriteColumn / 3;
		int spriteY = y - 17;
		int spriteOffset = (((spriteInLine << 3) + spriteY / 21) << 6) + spriteY % 21 * 3 + spriteColumn % 3;
		if ((content[10242 + spriteOffset] >> bit & 1) != 0)
			return content[8006 + spriteInLine] & 15;
		if ((content[8194 + spriteOffset] >> bit & 1) != 0)
			return content[8002 + spriteInLine] & 15;
	}
	int offset = (y >> 3) * 40 + column;
	return content[13314 + offset] >> ((content[2 + (offset << 3) + (y & 7)] >> bit & 1) << 2);
}

static bool RECOIL_DecodeShs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 14338)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1, 1);
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 320; x++)
			self->pixels[y * 320 + x] = self->c64Palette[RECOIL_GetShsPixel(content, x, y) & 15];
	}
	return true;
}

static int RECOIL_GetShSpriteOffset(int x, int y, int rowShift)
{
	return (((y / 21 << rowShift) + x / 24) << 6) + y % 21 * 3 + (x >> 3) % 3;
}

static void RECOIL_DecodeSh1Frame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int screenStride, int foreSpriteOffset, int backSpriteOffset, int foreColorOffset, int backColorOffset, int rowShift, int pixelsOffset)
{
	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < 96; x++) {
			int bit = ~x & 7;
			int spriteOffset = rowShift == 0 ? (x >> 3) * 168 + y : RECOIL_GetShSpriteOffset(x, y, rowShift);
			int c;
			if ((content[foreSpriteOffset + spriteOffset] >> bit & 1) != 0)
				c = content[foreColorOffset + x / 24] >> (foreColorOffset == backColorOffset ? 4 : 0);
			else if ((content[backSpriteOffset + spriteOffset] >> bit & 1) != 0)
				c = content[backColorOffset + x / 24];
			else {
				int offset = (y >> 3) * screenStride + (x >> 3);
				c = content[videoMatrixOffset + offset] >> ((content[bitmapOffset + (offset << 3) + (y & 7)] >> bit & 1) << 2);
			}
			self->pixels[pixelsOffset + y * 96 + x] = self->c64Palette[c & 15];
		}
	}
}

static bool RECOIL_DecodeSh1Unpacked(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int screenStride, int foreSpriteOffset, int backSpriteOffset, int foreColorOffset, int backColorOffset, int rowShift)
{
	RECOIL_SetSize(self, 96, 168, RECOILResolution_C641X1, 1);
	RECOIL_DecodeSh1Frame(self, content, bitmapOffset, videoMatrixOffset, screenStride, foreSpriteOffset, backSpriteOffset, foreColorOffset, backColorOffset, rowShift, 0);
	return true;
}

static bool RECOIL_UnpackSh(uint8_t const *content, int contentLength, uint8_t *unpacked, int unpackedLength)
{
	if (contentLength < 3)
		return false;
	DrpStream rle;
	DrpStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 1;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = content[0];
	return RleStream_Unpack(&rle.base, unpacked, 0, 1, unpackedLength);
}

static bool RECOIL_DecodeSh1(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 14770)
		return RECOIL_DecodeSh1Unpacked(self, content, 6690, 448, 40, 4530, 2482, 430, 426, 2);
	uint8_t unpacked[6304];
	return RECOIL_UnpackSh(content, contentLength, unpacked, 6304) && RECOIL_DecodeSh1Unpacked(self, unpacked, 0, 6048, 12, 4032, 2016, 6300, 6300, 0);
}

static bool RECOIL_DecodeShiUnpacked(RECOIL *self, uint8_t const *content)
{
	RECOIL_SetSize(self, 96, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeSh1Frame(self, content, 3, 15043, 12, 4803, 5059, 15343, 15347, 3, 0);
	RECOIL_DecodeSh1Frame(self, content, 2403, 15043, 12, 9923, 10179, 15343, 15347, 3, 19200);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeShi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 15355 && content[2] == 0)
		return RECOIL_DecodeShiUnpacked(self, content);
	uint8_t unpacked[15355];
	PgcStream rle;
	PgcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_Unpack(&rle.base, unpacked, 3, 1, 15355) && RECOIL_DecodeShiUnpacked(self, unpacked);
}

static bool RECOIL_DecodeSuperHires2(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int screenStride, int spritesOffset, int spritesY, int spriteColorsOffset)
{
	RECOIL_SetSize(self, 192, 168, RECOILResolution_C641X1, 1);
	for (int y = 0; y < 168; y++) {
		for (int x = 0; x < 192; x++) {
			int bit = ~x & 7;
			int c;
			if (y >= spritesY && (content[spritesOffset + (spritesOffset == 4032 ? (x >> 3) * 168 + y : RECOIL_GetShSpriteOffset(x, y - spritesY, 3))] >> bit & 1) != 0)
				c = content[spriteColorsOffset + x / 24];
			else {
				int offset = (y >> 3) * screenStride + (x >> 3);
				c = content[videoMatrixOffset + offset] >> ((content[bitmapOffset + (offset << 3) + (y & 7)] >> bit & 1) << 2);
			}
			self->pixels[y * 192 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeSh2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 14770)
		return RECOIL_DecodeSuperHires2(self, content, 6642, 442, 40, 2482, 0, 426);
	uint8_t unpacked[8576];
	return RECOIL_UnpackSh(content, contentLength, unpacked, 8576) && RECOIL_DecodeSuperHires2(self, unpacked, 0, 8064, 24, 4032, 0, 8568);
}

static int RECOIL_GetShe1Pixel(uint8_t const *content, int x, int y)
{
	int bit = ~x & 7;
	if (y < 84) {
		int spriteOffset = RECOIL_GetShSpriteOffset(x, y, 3);
		if ((content[1446 + spriteOffset] >> bit & 1) != 0)
			return content[3239];
		if ((content[1190 + spriteOffset] >> bit & 1) != 0)
			return content[3238];
	}
	int offset = (y >> 3) * 12 + (x >> 3);
	return content[1058 + offset] >> ((content[2 + (offset << 3) + (y & 7)] >> bit & 1) << 2);
}

static bool RECOIL_DecodeShe(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 3250:
		RECOIL_SetSize(self, 96, 88, RECOILResolution_C641X1, 1);
		for (int y = 0; y < 88; y++) {
			for (int x = 0; x < 96; x++)
				self->pixels[y * 96 + x] = self->c64Palette[RECOIL_GetShe1Pixel(content, x, y) & 15];
		}
		return true;
	case 8642:
		return RECOIL_DecodeSuperHires2(self, content, 2, 8130, 24, 4034, 1, 8634);
	default:
		return false;
	}
}

static int RECOIL_GetIshPixel(uint8_t const *content, int contentOffset, int x, int y)
{
	int bit = ~x & 7;
	int column = x >> 3;
	if (column < 12) {
		int spriteInLine = column / 3;
		int spriteOffset = contentOffset + ((spriteInLine * 10 + y / 21) << 6) + y % 21 * 3 + column % 3;
		if ((content[10752 + spriteOffset] >> bit & 1) != 0)
			return content[contentOffset + 15364 + spriteInLine];
		if ((content[8192 + spriteOffset] >> bit & 1) != 0)
			return content[contentOffset + 15360 + spriteInLine];
	}
	int offset = (y & ~7) * 5 + column;
	return content[contentOffset + 13312 + column] >> ((content[contentOffset + (offset << 3) + (y & 7)] >> bit & 1) << 2);
}

static void RECOIL_DecodeIshFrame(RECOIL *self, uint8_t const *content, int contentOffset, int pixelsOffset)
{
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 320; x++)
			self->pixels[pixelsOffset + y * 320 + x] = self->c64Palette[RECOIL_GetIshPixel(content, contentOffset, x, y) & 15];
	}
}

static bool RECOIL_DecodeIsh(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 9194:
		return RECOIL_DecodeHed(self, content);
	case 30738:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1, 2);
		RECOIL_DecodeIshFrame(self, content, 2, 0);
		RECOIL_DecodeIshFrame(self, content, 15370, 64000);
		return RECOIL_ApplyBlend(self);
	default:
		return false;
	}
}

static int RECOIL_GetShfPixel(uint8_t const *content, int x, int y)
{
	int column = x >> 3;
	int bit = ~x & 7;
	if (column < 12) {
		static const uint8_t SPRITES[64] = { 128, 132, 133, 137, 138, 142, 143, 147, 148, 152, 153, 157, 158, 162, 163, 167,
			168, 172, 173, 177, 178, 182, 183, 187, 188, 192, 193, 197, 198, 202, 203, 207,
			208, 212, 213, 217, 218, 222, 223, 227, 228, 232, 233, 234, 235, 236, 237, 238,
			239, 240, 241, 242, 243, 244, 245, 246, 247, 30, 46, 62, 78, 94, 110, 126 };
		int spriteIndex = ((y & 7) << 3) + column / 3;
		int spriteOffset = y % 21 * 3 + column % 3;
		if ((content[2 + (SPRITES[spriteIndex] << 6) + spriteOffset] >> bit & 1) != 0)
			return content[1002];
		if ((content[2 + (SPRITES[spriteIndex + 4] << 6) + spriteOffset] >> bit & 1) != 0)
			return content[1003];
	}
	y++;
	int offset = (y & ~7) * 5 + column;
	return content[16 + ((y & 7) << 10) + offset] >> ((content[8306 + (offset << 3) + (y & 7)] >> bit & 1) << 2);
}

static void RECOIL_DecodeShfFrame(RECOIL *self, uint8_t const *content, int foreColor, int backColor, int pixelsOffset)
{
	for (int y = 0; y < 167; y++) {
		for (int x = 0; x < 96; x++) {
			int offset = y * 12 + (x >> 3);
			int bit = ~x & 7;
			int c;
			if ((content[offset] >> bit & 1) != 0)
				c = foreColor;
			else if ((content[2048 + offset] >> bit & 1) != 0)
				c = backColor;
			else
				c = content[6144 + offset] >> ((content[4096 + offset] >> bit & 1) << 2);
			self->pixels[pixelsOffset + y * 96 + x] = self->c64Palette[c & 15];
		}
	}
}

static bool RECOIL_DecodeShf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 15874) {
		RECOIL_SetSize(self, 208, 167, RECOILResolution_C641X1, 1);
		for (int y = 0; y < 167; y++) {
			for (int x = 0; x < 208; x++)
				self->pixels[y * 208 + x] = self->c64Palette[RECOIL_GetShfPixel(content, x, y) & 15];
		}
		return true;
	}
	if (contentLength < 6)
		return false;
	uint8_t unpacked[8170];
	UflStream rle;
	UflStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = content[2];
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 8170))
		return false;
	RECOIL_SetSize(self, 96, 167, RECOILResolution_C641X1, 1);
	RECOIL_DecodeShfFrame(self, unpacked, unpacked[8168], unpacked[8168], 0);
	return true;
}

static bool RECOIL_DecodeC64Sif(RECOIL *self, uint8_t const *content, int contentLength)
{
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentLength = contentLength;
	if (!UifStream_StartSifFrame(&rle, 0))
		return false;
	int frame2Offset = rle.base.base.base.base.contentOffset;
	uint8_t unpacked[8176];
	if (!RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 8175) || !UifStream_StartSifFrame(&rle, frame2Offset) || contentLength != rle.base.base.base.base.contentOffset + 4)
		return false;
	RECOIL_SetSize(self, 96, 167, RECOILResolution_C641X1, 2);
	RECOIL_DecodeShfFrame(self, unpacked, content[contentLength - 4], content[contentLength - 3], 0);
	if (!RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 8175))
		return false;
	RECOIL_DecodeShfFrame(self, unpacked, content[contentLength - 2], content[contentLength - 1], 16032);
	return RECOIL_ApplyBlend(self);
}

static void RECOIL_DecodeUflFrame(RECOIL *self, uint8_t const *content, int bitmapOffset, int videoMatrixOffset, int spritesOffset, int spriteColorsOffset, int pixelsOffset)
{
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 288; x++) {
			int column = x >> 3;
			int offset = 3 + (y & ~7) * 5 + column;
			int c = content[videoMatrixOffset + ((y & 6) << 9) + offset];
			if ((content[bitmapOffset + (offset << 3) + (y & 7)] >> (~x & 7) & 1) != 0)
				c >>= 4;
			else if ((content[spritesOffset + ((y / 40 * 12 + (y & 2) * 3 + column / 6) << 6) + ((y + 1) >> 1) % 21 * 3 + (column >> 1) % 3] >> (~x >> 1 & 7) & 1) != 0)
				c = content[spriteColorsOffset == 4084 ? 4084 + column / 6 : spriteColorsOffset];
			self->pixels[pixelsOffset + y * 288 + x] = self->c64Palette[c & 15];
		}
	}
}

static bool RECOIL_DecodeUflUnpacked(RECOIL *self, uint8_t const *content)
{
	RECOIL_SetSize(self, 288, 200, RECOILResolution_C641X1, 1);
	RECOIL_DecodeUflFrame(self, content, 8194, 4098, 2, content[4081] == 1 ? 4084 : 4082, 0);
	return true;
}

static bool RECOIL_DecodeUfl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength == 16194)
		return RECOIL_DecodeUflUnpacked(self, content);
	if (contentLength < 6)
		return false;
	uint8_t unpacked[16194];
	UflStream rle;
	UflStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = content[2];
	return RleStream_Unpack(&rle.base, unpacked, 2, 1, 16194) && RECOIL_DecodeUflUnpacked(self, unpacked);
}

static bool RECOIL_DecodeUif(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 6)
		return false;
	uint8_t unpacked[32576];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = content[2];
	if (!RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 32575))
		return false;
	RECOIL_SetSize(self, 288, 200, RECOILResolution_C641X1, 2);
	RECOIL_DecodeUflFrame(self, unpacked, 8192, 0, 4096, 4080, 0);
	RECOIL_DecodeUflFrame(self, unpacked, 24576, 16384, 20480, 4080, 57600);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeXfl(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[16192];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = content[2];
	if (!RleStream_UnpackBackwards(&rle.base.base, unpacked, 0, 16191))
		return false;
	uint8_t spriteColors[16];
	memcpy(spriteColors + 1, unpacked + 8174, 10);
	RECOIL_SetSize(self, 192, 167, RECOILResolution_C641X1, 1);
	for (int y = 0; y < 167; y++) {
		if (y >= 3 && (y & 1) != 0) {
			int offset = (y - 3) >> 1;
			offset = (offset / 28 << 10) + offset % 28;
			spriteColors[unpacked[988 + offset] & 15] = unpacked[960 + offset];
		}
		for (int x = 0; x < 192; x++) {
			int column = x >> 3;
			int offset = ((1 + y) & ~7) * 5 + 16 + column;
			int c;
			if ((unpacked[8192 + (offset << 3) + ((1 + y) & 7)] >> (~x & 7) & 1) != 0)
				c = unpacked[(((y - 1) & 7) << 10) + offset] >> 4;
			else {
				int spriteInLine = column / 3;
				static const uint8_t SPRITES[64] = { 228, 229, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 246, 247, 248,
					14, 30, 46, 62, 78, 94, 110, 126, 128, 129, 133, 134, 138, 139, 143, 144,
					148, 149, 153, 154, 158, 159, 163, 164, 168, 169, 173, 174, 178, 179, 183, 184,
					188, 189, 193, 194, 198, 199, 203, 204, 208, 209, 213, 214, 218, 219, 223, 224 };
				switch (unpacked[(SPRITES[((y & 7) << 3) + spriteInLine] << 6) + (y >> 1) % 21 * 3 + column % 3] >> (~x & 6) & 3) {
				case 1:
					c = spriteColors[1];
					break;
				case 2:
					c = spriteColors[3 + spriteInLine];
					break;
				case 3:
					c = spriteColors[2];
					break;
				default:
					c = unpacked[(((y - 1) & 7) << 10) + offset];
					break;
				}
			}
			self->pixels[y * 192 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static int RECOIL_GetNufVideoMatrixOffset(int y)
{
	if (y < 128)
		return 8194 + ((~y >> 1 & 7) << 10);
	else
		return 2 + ((((y >> 1) + (y >= 168 ? 1 : 0)) & 3) << 10);
}

static int RECOIL_GetMufTableOffset(int spriteInLine)
{
	return ((spriteInLine & 6) << 9) + ((spriteInLine & 1) << 7);
}

static bool RECOIL_DecodeMufFrame(RECOIL *self, uint8_t const *content, int pixelsOffset)
{
	for (int y = 0; y < 200; y++) {
		int videoMatrixOffset = RECOIL_GetNufVideoMatrixOffset(y) - 256;
		for (int x = 0; x < 296; x++) {
			int column = x >> 3;
			int offset = (y & ~7) * 5 + 3 + column;
			int c = content[videoMatrixOffset + offset];
			if ((content[16130 - ((y & 128) << 7) + (offset << 3) + (y & 7)] >> (~x & 7) & 1) != 0)
				c >>= 4;
			else if (column < 36) {
				int spriteInLine = column / 6;
				offset = 124 - ((y & 128) << 1) + content[videoMatrixOffset + 1017 + spriteInLine];
				if (offset < 0 || offset >= 340)
					return false;
				int b = content[2 + (offset << 6) + ((((y + 47) >> 1) * 3 + (column >> 1) % 3 + (y < 123 ? 0 : y < 165 ? 1 : 2)) & 63)];
				offset = (y + 1) >> 1;
				if ((content[4610 + offset] >> spriteInLine & 2) != 0) {
					switch (b >> (~x >> 1 & 6) & 3) {
					case 1:
						c = content[7923];
						break;
					case 2:
						c = content[770 + RECOIL_GetMufTableOffset(spriteInLine) + offset];
						break;
					case 3:
						c = content[7922];
						break;
					default:
						break;
					}
				}
				else if ((b >> (~x >> 1 & 7) & 1) != 0)
					c = content[770 + RECOIL_GetMufTableOffset(spriteInLine) + offset];
			}
			self->pixels[pixelsOffset + y * 296 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeMuf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 21826)
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 1);
	return RECOIL_DecodeMufFrame(self, content, 0);
}

static bool RECOIL_DecodeMup(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 6)
		return false;
	uint8_t unpacked[21762];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = content[2];
	return RleStream_UnpackBackwards(&rle.base.base, unpacked, 2, 21761) && RECOIL_DecodeMuf(self, unpacked, 21826);
}

static bool RECOIL_DecodeMui(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 44034)
		return false;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1, 2);
	if (!RECOIL_DecodeMufFrame(self, content, 0))
		return false;
	uint8_t second[21762];
	memcpy(second + 2, content + 32770, 11264);
	memcpy(second + 11266, content + 22018, 10496);
	return RECOIL_DecodeMufFrame(self, second, 59200) && RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeNuf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 23042)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1, 1);
	uint8_t spriteColors[10];
	spriteColors[0] = content[8185];
	for (int i = 0; i < 6; i++)
		spriteColors[1 + i] = content[1026 + RECOIL_GetMufTableOffset(i)];
	spriteColors[7] = content[8179];
	spriteColors[8] = content[8184];
	spriteColors[9] = content[8178];
	for (int y = 0; y < 200; y++) {
		if (y > 0) {
			for (int i = 0; i < 6; i++) {
				int b = content[1026 + RECOIL_GetMufTableOffset(i) + ((y + 1) >> 1)];
				switch (b >> 4) {
				case 0:
					if ((y & 1) != 0)
						spriteColors[1 + i] = (uint8_t) b;
					break;
				case 5:
					if ((y & 1) == (i == 0 ? 1 : 0))
						spriteColors[7] = (uint8_t) b;
					break;
				case 6:
					if ((y & 1) == (i == 0 ? 1 : 0))
						spriteColors[9] = (uint8_t) b;
					break;
				case 7:
					if ((y & 1) == (i == 0 ? 1 : 0))
						spriteColors[0] = (uint8_t) b;
					break;
				case 14:
					if ((y & 1) == (i == 0 ? 1 : 0))
						spriteColors[8] = (uint8_t) b;
					break;
				default:
					break;
				}
			}
		}
		int videoMatrixOffset = RECOIL_GetNufVideoMatrixOffset(y);
		for (int x = 0; x < 320; x++) {
			int column = x >> 3;
			int offset = (y & ~7) * 5 + column;
			int c = column >= 3 || (y & 6) == 0 ? content[videoMatrixOffset + offset] : 255;
			if ((content[(y < 128 ? 16386 : 2) + (offset << 3) + (y & 7)] >> (~x & 7) & 1) != 0)
				c >>= 4;
			else if (column < 39) {
				int spriteInLine = (3 + column) / 6;
				offset = 128 - ((y & 128) << 1) + content[videoMatrixOffset + 1016 + spriteInLine];
				if (offset < 0 || offset >= 360)
					return false;
				int spriteX = column < 3 ? x : ((x - 24) >> 1) % 24;
				int b = content[2 + (offset << 6) + ((((y + 47) >> 1) * 3 + (spriteX >> 3) + (y < 123 ? 0 : y < 165 ? 1 : 2)) & 63)];
				if ((b >> (~spriteX & 7) & 1) != 0)
					c = spriteColors[spriteInLine];
				else if (column < 3) {
					offset = 128 - ((y & 128) << 1) + content[videoMatrixOffset + 1023];
					if (offset < 0 || offset >= 360)
						return false;
					b = content[2 + (offset << 6) + ((((y + 47) >> 1) * 3 + column + (y < 123 ? 0 : y < 165 ? 1 : 2)) & 63)] >> (~x & 6) & 3;
					if (b != 0)
						c = spriteColors[6 + b];
				}
			}
			self->pixels[y * 320 + x] = self->c64Palette[c & 15];
		}
	}
	return true;
}

static bool RECOIL_DecodeNup(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 7 || content[2] != 253)
		return false;
	uint8_t unpacked[23042];
	UifStream rle;
	UifStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	rle.base.escape = content[3];
	return RleStream_UnpackBackwards(&rle.base.base, unpacked, 2, 23041) && RECOIL_DecodeNuf(self, unpacked, 23042);
}

static bool RECOIL_DecodeDoo(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 640, 400, RECOILResolution_ST1X1, 1);
	return RECOIL_DecodeBlackAndWhite(self, content, 0, contentLength, false, 16777215);
}

static bool RECOIL_DecodeDa4(RECOIL *self, uint8_t const *content, int contentLength)
{
	RECOIL_SetSize(self, 640, 800, RECOILResolution_ST1X1, 1);
	return RECOIL_DecodeBlackAndWhite(self, content, 0, contentLength, false, 16777215);
}

static bool RECOIL_DecodeStCmp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 5)
		return false;
	switch (content[1]) {
	case 0:
		RECOIL_SetSize(self, 640, 400, RECOILResolution_ST1X1, 1);
		break;
	case 200:
		RECOIL_SetSize(self, 640, 800, RECOILResolution_ST1X1, 1);
		break;
	default:
		return false;
	}
	CmpStream rle;
	CmpStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = content[0];
	return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 16777215);
}

static bool RECOIL_DecodeBld(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 5)
		return false;
	int width = content[0] << 8 | content[1];
	int height = (content[2] << 8) + content[3] + 1;
	if (content[0] < 128)
		return RECOIL_SetSize(self, width + 1, height, RECOILResolution_ST1X1, 1) && RECOIL_DecodeBlackAndWhite(self, content, 4, contentLength, false, 16777215);
	if (!RECOIL_SetSize(self, 65537 - width, height, RECOILResolution_ST1X1, 1))
		return false;
	BldStream rle;
	BldStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 4;
	rle.base.base.base.contentLength = contentLength;
	return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 16777215);
}

static bool RECOIL_DecodeCrg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 43 || !RECOIL_IsStringAt(content, 0, "CALAMUSCRG") || content[10] != 3 || content[11] != 232 || content[12] != 0 || content[13] != 2)
		return false;
	int width = RECOIL_Get32BigEndian(content, 20);
	int height = RECOIL_Get32BigEndian(content, 24);
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_ST1X1, 1))
		return false;
	CciStream rle;
	CciStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 42;
	rle.base.base.base.contentLength = contentLength;
	return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 16777215);
}

static bool RECOIL_DecodePac(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8 || content[0] != 'p' || content[1] != 'M' || content[2] != '8')
		return false;
	int unpackedStride;
	switch (content[3]) {
	case '5':
		unpackedStride = 1;
		break;
	case '6':
		unpackedStride = 80;
		break;
	default:
		return false;
	}
	PacStream rle;
	PacStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 7;
	rle.base.base.base.contentLength = contentLength;
	uint8_t unpacked[32000];
	return RleStream_UnpackColumns(&rle.base, unpacked, 0, unpackedStride, 32000) && RECOIL_DecodeDoo(self, unpacked, 32000);
}

static void RECOIL_FillPscLine(uint8_t *unpacked, int unpackedOffset, int unpackedStride, int value)
{
	for (int i = 0; i < unpackedStride; i++)
		unpacked[unpackedOffset + i] = (uint8_t) value;
}

static int RECOIL_CopyPscLines(uint8_t *unpacked, int unpackedOffset, int unpackedStride, int unpackedLength, int count)
{
	if (unpackedOffset < unpackedStride || unpackedOffset + count * unpackedStride > unpackedLength)
		return -1;
	do {
		memcpy(unpacked + unpackedOffset, unpacked + (unpackedOffset - unpackedStride), unpackedStride);
		unpackedOffset += unpackedStride;
	}
	while (--count > 0);
	return unpackedOffset;
}

static bool RECOIL_DecodePsc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 18 || !RECOIL_IsStringAt(content, 0, "tm89") || content[8] != 2 || content[9] != 1)
		return false;
	int width = (content[10] << 8) + content[11] + 1;
	int height = (content[12] << 8) + content[13] + 1;
	if (width > 640 || height > 400)
		return false;
	RECOIL_SetSize(self, width, height, RECOILResolution_ST1X1, 1);
	int unpackedStride = (width + 7) >> 3;
	int unpackedLength = unpackedStride * height;
	if (content[14] == 99 && contentLength == 16 + unpackedLength && content[15 + unpackedLength] == 255)
		return RECOIL_DecodeBlackAndWhite(self, content, 15, contentLength - 1, false, 16777215);
	uint8_t unpacked[32000];
	int contentOffset = 14;
	for (int unpackedOffset = 0; unpackedOffset < unpackedLength;) {
		if (contentOffset + 1 >= contentLength)
			return false;
		switch (content[contentOffset++]) {
		case 0:
			RECOIL_FillPscLine(unpacked, unpackedOffset, unpackedStride, 0);
			unpackedOffset += unpackedStride;
			break;
		case 10:
			unpackedOffset = RECOIL_CopyPscLines(unpacked, unpackedOffset, unpackedStride, unpackedLength, 1 + content[contentOffset++]);
			if (unpackedOffset < 0)
				return false;
			break;
		case 12:
			unpackedOffset = RECOIL_CopyPscLines(unpacked, unpackedOffset, unpackedStride, unpackedLength, 257 + content[contentOffset++]);
			if (unpackedOffset < 0)
				return false;
			break;
		case 100:
			RECOIL_FillPscLine(unpacked, unpackedOffset, unpackedStride, content[contentOffset++]);
			unpackedOffset += unpackedStride;
			break;
		case 102:
			if (contentOffset + 2 >= contentLength)
				return false;
			for (int i = 0; i < unpackedStride; i++)
				unpacked[unpackedOffset + i] = content[contentOffset + (i & 1)];
			contentOffset += 2;
			unpackedOffset += unpackedStride;
			break;
		case 110:
			if (contentOffset + unpackedStride >= contentLength)
				return false;
			memcpy(unpacked + unpackedOffset, content + contentOffset, unpackedStride);
			contentOffset += unpackedStride;
			unpackedOffset += unpackedStride;
			break;
		case 200:
			RECOIL_FillPscLine(unpacked, unpackedOffset, unpackedStride, 255);
			unpackedOffset += unpackedStride;
			break;
		default:
			return false;
		}
	}
	if (contentOffset >= contentLength || content[contentOffset] != 255)
		return false;
	return RECOIL_DecodeBlackAndWhite(self, unpacked, 0, unpackedLength, false, 16777215);
}

static bool RECOIL_DecodeCp3(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 4)
		return false;
	int countLength = (1 + (content[0] << 8) + content[1]) << 2;
	if (contentLength <= countLength)
		return false;
	int valueOffset = countLength;
	uint8_t unpacked[32000];
	int unpackedOffset = 0;
	int count;
	for (int countOffset = 4; countOffset < countLength; countOffset += 4) {
		count = (content[countOffset] << 8 | content[countOffset + 1]) << 3;
		if (valueOffset + count + 8 > contentLength || unpackedOffset + count > 32000)
			return false;
		memcpy(unpacked + unpackedOffset, content + valueOffset, count);
		valueOffset += count;
		unpackedOffset += count;
		count = (content[countOffset + 2] << 8 | content[countOffset + 3]) << 3;
		if (unpackedOffset + count > 32000)
			return false;
		for (int offset = 0; offset < count; offset += 8)
			memcpy(unpacked + (unpackedOffset + offset), content + valueOffset, 8);
		valueOffset += 8;
		unpackedOffset += count;
	}
	count = 32000 - unpackedOffset;
	if (valueOffset + count != contentLength)
		return false;
	memcpy(unpacked + unpackedOffset, content + valueOffset, count);
	return RECOIL_DecodeDoo(self, unpacked, 32000);
}

static bool RECOIL_DecodeStFnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 2050:
		RECOIL_SetSize(self, 256, 64, RECOILResolution_ST1X1, 1);
		break;
	case 4096:
	case 4098:
		RECOIL_SetSize(self, 256, 128, RECOILResolution_ST1X1, 1);
		break;
	default:
		return false;
	}
	if ((contentLength & 2) != 0) {
		if (content[contentLength - 2] != 0 || content[contentLength - 2] > 1)
			return false;
		contentLength -= 2;
	}
	RECOIL_DecodeBlackAndWhiteFont(self, content, 0, contentLength, 16);
	return true;
}

static bool RECOIL_DecodeGdosFnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 88 || content[62] != 85 || content[63] != 85)
		return false;
	GdosFntStream stream;
	if (content[3] == 0) {
		if (content[2] == 0)
			return false;
		stream.bigEndian = false;
	}
	else if (content[2] == 0)
		stream.bigEndian = true;
	else
		return false;
	stream.base.content = content;
	stream.base.contentLength = contentLength;
	stream.base.contentOffset = 36;
	int firstCharacter = GdosFntStream_ReadWord(&stream);
	int lastCharacter = GdosFntStream_ReadWord(&stream);
	if (firstCharacter > lastCharacter)
		return false;
	stream.base.contentOffset = 72;
	int characterOffset = GdosFntStream_ReadInt(&stream);
	if (characterOffset <= 0 || characterOffset >= contentLength)
		return false;
	int bitmapOffset = GdosFntStream_ReadInt(&stream);
	if (bitmapOffset < 0 || bitmapOffset >= contentLength)
		return false;
	int bytesPerLine = GdosFntStream_ReadWord(&stream);
	if (bytesPerLine == 0)
		return false;
	int height = GdosFntStream_ReadWord(&stream);
	if (height == 0 || bitmapOffset + height * bytesPerLine > contentLength)
		return false;
	int characterEndOffset = characterOffset + ((lastCharacter - firstCharacter + 2) << 1);
	if (characterEndOffset > bitmapOffset)
		return false;
	int width = FuInt_Min(height << 4, 3840);
	stream.base.contentOffset = characterOffset;
	stream.base.contentLength = characterEndOffset;
	stream.bitmapWidth = bytesPerLine << 3;
	stream.width = width;
	stream.nextX = stream.rightX = 0;
	int row;
	for (row = 0; stream.nextX >= 0; row += height) {
		if (!GdosFntStream_FitRow(&stream))
			return false;
	}
	if (!RECOIL_SetSize(self, width, row, RECOILResolution_ST1X1, 1))
		return false;
	stream.base.contentOffset = characterOffset;
	stream.nextX = stream.rightX = 0;
	for (row = 0; stream.nextX >= 0; row += height) {
		GdosFntStream_FitRow(&stream);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int fontX = stream.leftX + x;
				int c;
				if (fontX < stream.rightX) {
					int offset = bitmapOffset + y * bytesPerLine + (fontX >> 3);
					c = (content[offset] >> (~fontX & 7) & 1) == 0 ? 16777215 : 0;
				}
				else
					c = 16777215;
				self->pixels[(row + y) * width + x] = c;
			}
		}
	}
	return true;
}

static bool RECOIL_IsStePalette(uint8_t const *content, int contentOffset, int colors)
{
	while (--colors >= 0) {
		if ((content[contentOffset] & 8) != 0 || (content[contentOffset + 1] & 136) != 0)
			return true;
		contentOffset += 2;
	}
	return false;
}

static int RECOIL_GetStColor(const RECOIL *self, uint8_t const *content, int contentOffset)
{
	int r = content[contentOffset];
	int gb = content[contentOffset + 1];
	int rgb;
	switch (self->resolution) {
	case RECOILResolution_ST1X1:
	case RECOILResolution_ST1X2:
		rgb = (r & 7) << 16 | (gb & 112) << 4 | (gb & 7);
		return rgb << 5 | rgb << 2 | (rgb >> 1 & 197379);
	case RECOILResolution_TT1X1:
	case RECOILResolution_TT2X1:
		rgb = (r & 15) << 16 | (gb & 240) << 4 | (gb & 15);
		return rgb << 4 | rgb;
	default:
		rgb = (r & 7) << 17 | (r & 8) << 13 | (gb & 112) << 5 | (gb & 135) << 1 | (gb & 8) >> 3;
		return rgb << 4 | rgb;
	}
}

static void RECOIL_SetStPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors, int c)
{
	for (; c < colors; c++)
		self->contentPalette[c] = RECOIL_GetStColor(self, content, contentOffset + (c << 1));
}

static int RECOIL_GetSteInterlacedColor(int rgb)
{
	rgb = (rgb & 1792) << 10 | (rgb & 2160) << 6 | (rgb & 16519) << 2 | (rgb & 8192) >> 5 | (rgb & 8) >> 2 | (rgb & 4096) >> 12;
	return rgb << 3 | (rgb >> 2 & 460551);
}

static int RECOIL_GetStVdiColor(uint8_t const *content, int contentOffset)
{
	int rgb = 0;
	for (int i = 0; i < 6; i += 2) {
		int c = content[contentOffset + i] << 8 | content[contentOffset + i + 1];
		c = c < 1000 ? c * 255 / 1000 : 255;
		rgb = rgb << 8 | c;
	}
	return rgb;
}

static void RECOIL_SetStVdiColor(RECOIL *self, int i, int rgb, int bitplanes)
{
	switch (i) {
	case 1:
		i = (1 << bitplanes) - 1;
		break;
	case 2:
		i = 1;
		break;
	case 3:
		i = 2;
		break;
	case 5:
		i = 6;
		break;
	case 6:
		i = 3;
		break;
	case 7:
		i = 5;
		break;
	case 8:
		i = 7;
		break;
	case 9:
		i = 8;
		break;
	case 10:
		i = 9;
		break;
	case 11:
		i = 10;
		break;
	case 13:
		i = 14;
		break;
	case 14:
		i = 11;
		break;
	case 15:
		i = 13;
		break;
	case 255:
		i = 15;
		break;
	default:
		break;
	}
	self->contentPalette[i] = rgb;
}

static void RECOIL_SetStVdiPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors, int bitplanes)
{
	for (int i = 0; i < colors; i++)
		RECOIL_SetStVdiColor(self, i, RECOIL_GetStVdiColor(content, contentOffset + i * 6), bitplanes);
}

static int RECOIL_GetStLowPixel(uint8_t const *content, int contentOffset, int x)
{
	return RECOIL_GetBitplaneWordsPixel(content, contentOffset, x, 4);
}

static bool RECOIL_DecodeStLowWithStride(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, int bitmapStride, uint8_t const *palette, int paletteOffset, int width, int height, int frames)
{
	RECOIL_SetSize(self, width, height, RECOIL_IsStePalette(palette, paletteOffset, 16) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, frames);
	RECOIL_SetStPalette(self, palette, paletteOffset, 16, 0);
	RECOIL_DecodeBitplanes(self, bitmap, bitmapOffset, bitmapStride, 4, 0, width, height);
	return true;
}

static bool RECOIL_DecodeStLow(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int width, int height, int frames)
{
	return RECOIL_DecodeStLowWithStride(self, bitmap, bitmapOffset, (width + 15) >> 4 << 3, palette, paletteOffset, width, height, frames);
}

static void RECOIL_DecodeStMedium(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int width, int height, int frames)
{
	RECOIL_SetSize(self, width, height << 1, RECOIL_IsStePalette(palette, paletteOffset, 4) ? RECOILResolution_STE1X2 : RECOILResolution_ST1X2, frames);
	RECOIL_SetStPalette(self, palette, paletteOffset, 4, 0);
	RECOIL_DecodeScaledBitplanes(self, bitmap, bitmapOffset, width, height * frames, 2, false, NULL);
}

static bool RECOIL_DecodeSrt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 32038 || !RECOIL_IsStringAt(content, 32000, "JHSy") || content[32004] != 0 || content[32005] != 1)
		return false;
	RECOIL_DecodeStMedium(self, content, 0, content, 32006, 640, 200, 1);
	return true;
}

static bool RECOIL_DecodeSt(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int mode, int doubleHeight)
{
	switch (mode) {
	case 0:
		return RECOIL_DecodeStLow(self, bitmap, bitmapOffset, palette, paletteOffset, 320, 200 << doubleHeight, 1);
	case 1:
		RECOIL_DecodeStMedium(self, bitmap, bitmapOffset, palette, paletteOffset, 640, 200 << doubleHeight, 1);
		return true;
	case 2:
		RECOIL_SetSize(self, 640, 400 << doubleHeight, RECOILResolution_ST1X1, 1);
		return RECOIL_DecodeBlackAndWhite(self, bitmap, bitmapOffset, bitmapOffset + (32000 << doubleHeight), false, 16777215);
	default:
		return false;
	}
}

static bool RECOIL_DecodeStPi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 32034 || content[0] != 0)
		return false;
	switch (contentLength) {
	case 32034:
	case 32066:
	case 32128:
		return RECOIL_DecodeSt(self, content, 34, content, 2, content[1], 0);
	case 38434:
		return content[1] == 4 && RECOIL_DecodeStLow(self, content, 34, content, 2, 320, 240, 1);
	case 44834:
		return content[1] == 0 && RECOIL_DecodeStLow(self, content, 34, content, 2, 320, 280, 1);
	case 64034:
		return RECOIL_DecodeSt(self, content, 34, content, 2, content[1], 1);
	case 116514:
		return content[1] == 0 && RECOIL_DecodeStLow(self, content, 34, content, 2, 416, 560, 1);
	case 153606:
		if (content[1] != 6)
			return false;
		RECOIL_SetSize(self, 1280, 960, RECOILResolution_TT1X1, 1);
		return RECOIL_DecodeBlackAndWhite(self, content, 6, contentLength, false, 16777215);
	case 153634:
		if (content[1] != 4)
			return false;
		RECOIL_SetSize(self, 640, 480, RECOILResolution_TT1X1, 1);
		RECOIL_SetStPalette(self, content, 2, 16, 0);
		RECOIL_DecodeBitplanes(self, content, 34, 320, 4, 0, 640, 480);
		return true;
	case 154114:
		if (content[1] != 7)
			return false;
		RECOIL_SetSize(self, 640, 480, RECOILResolution_TT2X1, 1);
		RECOIL_SetStPalette(self, content, 2, 256, 0);
		RECOIL_DecodeScaledBitplanes(self, content, 514, 320, 480, 8, false, NULL);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodePc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 68 || content[0] != 128 || content[1] > 2)
		return false;
	int bitplanes = 4 >> content[1];
	PackBitsStream rle;
	PackBitsStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 34;
	rle.base.base.base.contentLength = contentLength;
	uint8_t unpacked[32000];
	return PackBitsStream_UnpackBitplaneLines(&rle, unpacked, 320 << content[1], 200, bitplanes, true, false) && RECOIL_DecodeSt(self, unpacked, 0, content, 2, content[1], 0);
}

static bool RECOIL_DecodeEza(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 44 || content[0] != 'E' || content[1] != 'Z' || content[2] != 0 || content[3] != 200)
		return false;
	PackBitsStream rle;
	PackBitsStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 44;
	rle.base.base.base.contentLength = contentLength;
	uint8_t unpacked[32000];
	return PackBitsStream_UnpackBitplaneLines(&rle, unpacked, 320, 200, 4, true, false) && RECOIL_DecodeStLow(self, unpacked, 0, content, 4, 320, 200, 1);
}

static bool RECOIL_DecodeNeo(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 32128:
		if (content[0] != 0 || content[1] != 0 || content[2] != 0)
			return false;
		if (content[3] == 0) {
			uint8_t rst[6801];
			if (RECOIL_ReadCompanionFile(self, filename, "RST", "rst", rst, 6801) == 6800) {
				RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
				RECOIL_SetStPalette(self, content, 4, 16, 0);
				RastPalette palette;
				RastPalette_Construct(&palette);
				palette.base.base.base.content = rst;
				palette.base.base.base.contentOffset = 0;
				palette.base.base.base.contentLength = 6800;
				palette.colors = 16;
				RECOIL_DecodeScaledBitplanes(self, content, 128, 320, 200, 4, false, &palette.base);
				return true;
			}
		}
		return RECOIL_DecodeSt(self, content, 128, content, 4, content[3], 0);
	case 128128:
		return content[0] == 186 && content[1] == 190 && content[2] == 0 && content[3] == 0 && RECOIL_DecodeStLow(self, content, 128, content, 4, 640, 400, 1);
	default:
		return false;
	}
}

static bool RECOIL_DecodeArtDirector(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 32512 && content[32287] < 8 && RECOIL_DecodeStLow(self, content, 0, content, 32000 + (content[32287] << 5), 320, 200, 1);
}

static bool RECOIL_DecodeSsb(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 32768 && RECOIL_DecodeStLow(self, content, 0, content, 32000, 320, 200, 1);
}

static bool RECOIL_DecodeGfaArtist(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 32032:
		return RECOIL_DecodeStLow(self, content, 32, content, 0, 320, 200, 1);
	case 34360:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
		GfaArtistPalette palette;
		GfaArtistPalette_Construct(&palette);
		palette.base.base.base.content = content;
		RECOIL_DecodeScaledBitplanes(self, content, 4, 320, 200, 4, false, &palette.base);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeBil(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 32032:
		return RECOIL_DecodeStLow(self, content, 32, content, 0, 320, 200, 1);
	case 32034:
		return content[0] == 0 && content[1] == 0 && RECOIL_DecodeStLow(self, content, 34, content, 2, 320, 200, 1);
	default:
		return false;
	}
}

static bool RECOIL_DecodePaletteMaster(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 36864 || content[35968] != 255 || content[35969] != 255)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
	ArtPalette palette;
	ArtPalette_Construct(&palette);
	palette.base.base.base.content = content;
	palette.base.base.base.contentOffset = 32800;
	RECOIL_DecodeScaledBitplanes(self, content, 0, 320, 200, 4, false, &palette.base);
	return true;
}

static bool RECOIL_DecodeCel(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 128 || content[0] != 255 || content[1] != 255 || content[2] != 0 || content[3] != 0)
		return false;
	int width = content[58] << 8 | content[59];
	int height = content[60] << 8 | content[61];
	return contentLength == 128 + ((width + 15) >> 4 << 3) * height && RECOIL_DecodeStLow(self, content, 128, content, 4, width, height, 1);
}

static bool RECOIL_DecodeMur(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength != 32000)
		return false;
	uint8_t pal[97];
	if (RECOIL_ReadCompanionFile(self, filename, "PAL", "pal", pal, 97) != 96)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_STE1X1, 1);
	RECOIL_SetStVdiPalette(self, pal, 0, 16, 4);
	RECOIL_DecodeBitplanes(self, content, 0, 160, 4, 0, 320, 200);
	return true;
}

static bool RECOIL_DecodeKid(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 63054 && content[0] == 'K' && content[1] == 'D' && RECOIL_DecodeStLowWithStride(self, content, 34, 230, content, 2, 448, 274, 1);
}

static bool RECOIL_DecodeStPpp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 32079 && RECOIL_IsStringAt(content, 0, "PABLO PACKED PICTURE: Groupe CDND \r\n32036\r\n") && content[44] == 0 && content[45] == 125 && content[46] == 36 && RECOIL_DecodeSt(self, content, 79, content, 47, content[43], 0);
}

static bool RECOIL_DecodeStRgb(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 96102)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_STE1X1, 1);
	self->frames = 3;
	for (int i = 0; i < 64000; i++) {
		int rgb = RECOIL_GetStLowPixel(content, 34, i) << 16 | RECOIL_GetStLowPixel(content, 32068, i) << 8 | RECOIL_GetStLowPixel(content, 64102, i);
		self->pixels[i] = rgb * 17;
	}
	return true;
}

static bool RECOIL_DecodeSd(RECOIL *self, uint8_t const *content, int contentLength, int mode)
{
	return contentLength == 32128 && RECOIL_DecodeSt(self, content, 128, content, 4, mode, 0);
}

static bool RECOIL_DecodeObj(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8)
		return false;
	if (content[4] == 0 && content[5] == 1) {
		return RECOIL_SetSize(self, (content[0] << 8) + content[1] + 1, (content[2] << 8) + content[3] + 1, RECOILResolution_ST1X1, 1) && RECOIL_DecodeBlackAndWhite(self, content, 6, contentLength, true, 16777215);
	}
	Stream s;
	s.content = content;
	s.contentOffset = 0;
	s.contentLength = contentLength;
	for (int i = 0; i < 16; i++) {
		int rgb = Stream_ParseDaliInt(&s);
		if (rgb < 0 || rgb > 1911)
			return false;
		rgb = (rgb & 1792) << 8 | (rgb & 112) << 4 | (rgb & 7);
		self->contentPalette[i] = rgb << 5 | rgb << 2 | (rgb >> 1 & 197379);
	}
	int contentOffset = s.contentOffset;
	if (contentOffset + 6 >= contentLength || content[contentOffset + 2] != 0 || content[contentOffset + 4] != 0 || content[contentOffset + 5] != 4)
		return false;
	int width = (content[contentOffset] << 8) + content[contentOffset + 1] + 1;
	int height = content[contentOffset + 3] + 1;
	int stride = (width + 15) >> 4 << 3;
	if (contentOffset + 6 + height * stride != contentLength || !RECOIL_SetSize(self, width, height, RECOILResolution_ST1X1, 1))
		return false;
	RECOIL_DecodeBitplanes(self, content, contentOffset + 6, stride, 4, 0, width, height);
	return true;
}

static bool RECOIL_DecodeIc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 68 || !RECOIL_IsStringAt(content, 0, "IMDC") || content[4] != 0 || content[64] != 200 || content[65] != 2)
		return false;
	uint8_t unpacked[32000];
	IcStream rle;
	IcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 67;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_UnpackColumns(&rle.base, unpacked, 0, 160, 32000) && RECOIL_DecodeSt(self, unpacked, 0, content, 6, content[5], 0);
}

static bool RECOIL_DecodeGraphicsProcessor(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 493 || content[0] != 0)
		return false;
	int mode = content[1];
	switch (mode) {
	case 0:
	case 1:
	case 2:
		return contentLength == 32331 && RECOIL_DecodeSt(self, content, 331, content, 2, mode, 0);
	case 10:
	case 11:
	case 12:
		break;
	default:
		return false;
	}
	mode -= 10;
	int bitplanes = 4 >> mode;
	uint8_t unpacked[32000];
	int contentOffset = 333;
	int count = 0;
	for (int unpackedOffset = 0; unpackedOffset < 32000; unpackedOffset += bitplanes) {
		if (count == 0) {
			if (contentOffset + bitplanes >= contentLength)
				return false;
			count = content[contentOffset];
			if (count == 0)
				return false;
			contentOffset += 1 + bitplanes;
		}
		memcpy(unpacked + unpackedOffset, content + (contentOffset - bitplanes), bitplanes);
		count--;
	}
	return RECOIL_DecodeSt(self, unpacked, 0, content, 2, mode, 0);
}

static bool RECOIL_DecodeDaliCompressed(RECOIL *self, uint8_t const *content, int contentLength, int mode)
{
	DaliStream stream;
	stream.base.content = content;
	stream.base.contentOffset = 32;
	stream.base.contentLength = contentLength;
	int countLength = Stream_ParseDaliInt(&stream.base);
	return countLength > 0 && Stream_ParseDaliInt(&stream.base) > 0 && DaliStream_Decode(&stream, countLength, self, 0, mode);
}

static bool RECOIL_DecodeRgh(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 14 || !RECOIL_IsStringAt(content, 0, "(c)F.MARCHAL"))
		return false;
	DaliStream stream;
	stream.base.content = content;
	stream.base.contentOffset = 12;
	stream.base.contentLength = contentLength;
	int countLength = Stream_ParseDaliInt(&stream.base);
	int paletteOffset = stream.base.contentOffset;
	stream.base.contentOffset = paletteOffset + 32;
	return DaliStream_Decode(&stream, countLength, self, paletteOffset, 0);
}

static bool RECOIL_DecodeSc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 128 || !RECOIL_IsStringAt(content, 54, "ANvisionA"))
		return false;
	int flags = content[63];
	int doubleHeight;
	switch (flags & 15) {
	case 0:
		doubleHeight = 1;
		break;
	case 1:
	case 2:
		doubleHeight = 0;
		break;
	default:
		return false;
	}
	int bitmapLength = 32000 << doubleHeight;
	int mode = flags >> 4 & 3;
	if (flags >= 128) {
		uint8_t unpacked[64000];
		ScStream rle;
		ScStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 128;
		rle.base.base.base.contentLength = contentLength;
		int bytesPer16Pixels = 8 >> mode;
		for (int bitplane = 0; bitplane < bytesPer16Pixels; bitplane += 2) {
			if (!RleStream_UnpackWords(&rle.base, unpacked, bitplane, bytesPer16Pixels, bitmapLength))
				return false;
		}
		return RECOIL_DecodeSt(self, unpacked, 0, content, 4, mode, doubleHeight);
	}
	return contentLength >= 128 + bitmapLength && RECOIL_DecodeSt(self, content, 128, content, 4, mode, doubleHeight);
}

static bool RECOIL_DecodeGfb(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 20 || !RECOIL_IsStringAt(content, 0, "GF25"))
		return false;
	int bitplanes;
	switch (RECOIL_Get32BigEndian(content, 4)) {
	case 2:
		bitplanes = 1;
		break;
	case 4:
		bitplanes = 2;
		break;
	case 16:
		bitplanes = 4;
		break;
	case 256:
		bitplanes = 8;
		break;
	default:
		return false;
	}
	int width = RECOIL_Get32BigEndian(content, 8);
	if (width <= 0)
		return false;
	int height = RECOIL_Get32BigEndian(content, 12);
	if (height <= 0)
		return false;
	int bitmapLength = RECOIL_Get32BigEndian(content, 16);
	if (bitmapLength <= 0)
		return false;
	if (1556 + bitmapLength != contentLength || bitmapLength != ((width + 15) >> 4 << 1) * bitplanes * height || !RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, false))
		return false;
	RECOIL_SetStVdiPalette(self, content, 20 + bitmapLength, 1 << bitplanes, bitplanes);
	RECOIL_DecodeScaledBitplanes(self, content, 20, width, height, bitplanes, false, NULL);
	return true;
}

static bool RECOIL_DecodeCa(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 8 || content[0] != 'C' || content[1] != 'A')
		return false;
	int contentOffset;
	switch (content[3]) {
	case 0:
		contentOffset = 36;
		break;
	case 1:
		contentOffset = 12;
		break;
	case 2:
		contentOffset = 4;
		break;
	default:
		return false;
	}
	switch (content[2]) {
	case 0:
		return contentOffset + 32000 == contentLength && RECOIL_DecodeSt(self, content, contentOffset, content, 4, content[3], 0);
	case 1:
		{
			uint8_t unpacked[32000];
			CaStream rle;
			CaStream_Construct(&rle);
			rle.base.base.base.content = content;
			rle.base.base.base.contentOffset = contentOffset;
			rle.base.base.base.contentLength = contentLength;
			return CaStream_UnpackCa(&rle, unpacked, 0) && RECOIL_DecodeSt(self, unpacked, 0, content, 4, content[3], 0);
		}
	default:
		return false;
	}
}

static bool RECOIL_DecodeTny(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 42)
		return false;
	int mode = content[0];
	int contentOffset;
	if (mode > 2) {
		if (mode > 5)
			return false;
		mode -= 3;
		contentOffset = 4;
	}
	else
		contentOffset = 0;
	int controlLength = content[contentOffset + 33] << 8 | content[contentOffset + 34];
	int valueLength = (content[contentOffset + 35] << 8 | content[contentOffset + 36]) << 1;
	if (contentOffset + 37 + controlLength + valueLength > contentLength)
		return false;
	TnyStream rle;
	TnyStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentOffset + 37;
	rle.valueOffset = rle.base.base.base.base.contentLength = contentOffset + 37 + controlLength;
	rle.valueLength = contentOffset + 37 + controlLength + valueLength;
	uint8_t unpacked[32000];
	for (int bitplane = 0; bitplane < 8; bitplane += 2) {
		for (int x = bitplane; x < 160; x += 8) {
			for (int unpackedOffset = x; unpackedOffset < 32000; unpackedOffset += 160) {
				int b = RleStream_ReadRle(&rle.base.base);
				if (b < 0)
					return false;
				unpacked[unpackedOffset] = (uint8_t) (b >> 8);
				unpacked[unpackedOffset + 1] = (uint8_t) b;
			}
		}
	}
	return RECOIL_DecodeSt(self, unpacked, 0, content, contentOffset + 1, mode, 0);
}

static bool RECOIL_UnpackGrx(uint8_t const *packed, int packedOffset, int packedLength, uint8_t *unpacked, int unpackedOffset, int unpackedLength)
{
	int bits = 0;
	int bitsCount = 0;
	int offsets[1024];
	int codes = 258;
	int codeBits = 9;
	while (unpackedOffset < unpackedLength) {
		while (bitsCount < codeBits) {
			if (packedOffset >= packedLength)
				return false;
			bits |= packed[packedOffset++] << bitsCount;
			bitsCount += 8;
		}
		int code = bits & ((1 << codeBits) - 1);
		bits >>= codeBits;
		bitsCount -= codeBits;
		switch (code) {
		case 256:
			if (codeBits == 10)
				return false;
			codeBits = 10;
			break;
		case 257:
			codes = 258;
			codeBits = 9;
			break;
		default:
			if (codes >= 1024)
				return false;
			offsets[codes] = unpackedOffset;
			if (code < 256) {
				unpacked[unpackedOffset++] = (uint8_t) code;
			}
			else if (code >= codes)
				return false;
			else {
				int sourceOffset = offsets[code];
				int endOffset = offsets[code + 1];
				if (unpackedOffset + endOffset - sourceOffset >= unpackedLength)
					return false;
				do
					unpacked[unpackedOffset++] = unpacked[sourceOffset++];
				while (sourceOffset <= endOffset);
			}
			codes++;
			break;
		}
	}
	return true;
}

static bool RECOIL_DecodeGrx(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1588 || !RECOIL_IsStringAt(content, 0, "GRXP") || content[4] != 1 || content[5] != 1 || content[28] != 0)
		return false;
	int width = content[30] << 8 | content[31];
	int height = content[32] << 8 | content[33];
	int bitplanes;
	switch (content[34] << 8 | content[35]) {
	case 2:
		bitplanes = 1;
		break;
	case 4:
		bitplanes = 2;
		break;
	case 16:
		bitplanes = 4;
		break;
	case 256:
		bitplanes = 8;
		break;
	default:
		return false;
	}
	int contentStride = ((width + 15) >> 4) * bitplanes << 1;
	int bitmapLength = RECOIL_Get32BigEndian(content, 1574);
	if (bitmapLength != contentStride * height || !RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, true))
		return false;
	RECOIL_SetStVdiPalette(self, content, 36, 1 << bitplanes, bitplanes);
	switch (content[29]) {
	case 0:
		if (contentLength != 1586 + bitmapLength)
			return false;
		RECOIL_DecodeBitplanes(self, content, 1586, contentStride, bitplanes, 0, width, height);
		return true;
	case 1:
		;
		int packed1Length = RECOIL_Get32BigEndian(content, 1578);
		if (packed1Length <= 0)
			return false;
		int packed2Offset = 1586 + packed1Length;
		if (contentLength != packed2Offset + RECOIL_Get32BigEndian(content, 1582))
			return false;
		uint8_t *unpacked = (uint8_t *) malloc(bitmapLength * sizeof(uint8_t));
		if (!RECOIL_UnpackGrx(content, 1586, packed2Offset, unpacked, 0, bitmapLength >> 1) || !RECOIL_UnpackGrx(content, packed2Offset, contentLength, unpacked, bitmapLength >> 1, bitmapLength)) {
			free(unpacked);
			return false;
		}
		RECOIL_DecodeBitplanes(self, unpacked, 0, contentStride, bitplanes, 0, width, height);
		free(unpacked);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeCptFul(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, HblPalette *palette)
{
	if (contentLength < contentOffset + 40 || content[contentOffset + 32] != 0)
		return false;
	int mode = content[contentOffset + 33];
	if (mode > 2)
		return false;
	int bitplanes = 4 >> mode;
	uint8_t unpacked[32000];
	uint8_t isFilled[16000] = { 0 };
	contentOffset += 34;
	for (;;) {
		int nextContentOffset = contentOffset + 4 + bitplanes * 2;
		if (nextContentOffset > contentLength)
			return false;
		int repeatCount = content[contentOffset] << 8 | content[contentOffset + 1];
		if (repeatCount == 65535) {
			contentOffset = nextContentOffset;
			break;
		}
		int offset = (content[contentOffset + 2] << 8 | content[contentOffset + 3]) * bitplanes;
		do {
			if (offset >= 16000)
				return false;
			memcpy(unpacked + (offset << 1), content + (contentOffset + 4), bitplanes << 1);
			isFilled[offset] = 1;
			offset += bitplanes;
		}
		while (--repeatCount >= 0);
		contentOffset = nextContentOffset;
	}
	for (int offset = 0; offset < 16000; offset += bitplanes) {
		if (isFilled[offset] == 0) {
			int nextContentOffset = contentOffset + bitplanes * 2;
			if (nextContentOffset > contentLength)
				return false;
			memcpy(unpacked + (offset << 1), content + contentOffset, bitplanes << 1);
			contentOffset = nextContentOffset;
		}
	}
	if (palette == NULL)
		return RECOIL_DecodeSt(self, unpacked, 0, content, 0, mode, 0);
	if (mode == 0)
		RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
	else
		RECOIL_SetSize(self, 640, 400, RECOILResolution_ST1X2, 1);
	RECOIL_DecodeScaledBitplanes(self, unpacked, 0, 320 << mode, 200, bitplanes, false, &palette->base);
	return true;
}

static bool RECOIL_DecodeCpt(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength < 40)
		return false;
	if (content[33] <= 1) {
		uint8_t hbl[3249];
		int hblLength = RECOIL_ReadCompanionFile(self, filename, "HBL", "hbl", hbl, 3249);
		if (hblLength >= 896 && hblLength <= 3248) {
			HblPalette palette;
			HblPalette_Construct(&palette);
			palette.base.base.base.content = hbl;
			palette.base.base.base.contentLength = hblLength;
			if (HblPalette_Init(&palette))
				return RECOIL_DecodeCptFul(self, content, 0, contentLength, &palette);
		}
	}
	return RECOIL_DecodeCptFul(self, content, 0, contentLength, NULL);
}

static bool RECOIL_DecodeFul(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1544)
		return false;
	HblPalette palette;
	HblPalette_Construct(&palette);
	palette.base.base.base.content = content;
	palette.base.base.base.contentLength = contentLength;
	return HblPalette_Init(&palette) && palette.base.base.base.contentOffset + 641 < contentLength && content[palette.base.base.base.contentOffset + 641] <= 1 && RECOIL_DecodeCptFul(self, content, palette.base.base.base.contentOffset + 608, contentLength, &palette);
}

static void RECOIL_SetDefaultStPalette(RECOIL *self, int bitplanes)
{
	self->contentPalette[0] = 16777215;
	if (bitplanes >= 2) {
		self->contentPalette[1] = 16711680;
		self->contentPalette[2] = 65280;
		if (bitplanes == 4) {
			self->contentPalette[3] = 16776960;
			self->contentPalette[4] = 255;
			self->contentPalette[5] = 16711935;
			self->contentPalette[6] = 65535;
			self->contentPalette[7] = 11184810;
			self->contentPalette[8] = 5592405;
			self->contentPalette[9] = 11141120;
			self->contentPalette[10] = 43520;
			self->contentPalette[11] = 11184640;
			self->contentPalette[12] = 170;
			self->contentPalette[13] = 11141290;
			self->contentPalette[14] = 43690;
		}
	}
	self->contentPalette[(1 << bitplanes) - 1] = 0;
}

static bool RECOIL_IsXimg(uint8_t const *content)
{
	return RECOIL_IsStringAt(content, 16, "XIMG") && content[20] == 0 && content[21] == 0;
}

static bool RECOIL_DecodeSttt(RECOIL *self, ImgStream *rle, int width, int bytesPerBitplane)
{
	int bitplanes = rle->base.base.base.content[5];
	RECOIL_SetStPalette(self, rle->base.base.base.content, 22, 16, 0);
	memset(self->contentPalette + 16, 0, 240 * sizeof(int));
	uint8_t *unpacked = (uint8_t *) malloc(bytesPerBitplane * sizeof(uint8_t));
	int doubleWidth = self->resolution == RECOILResolution_TT2X1 ? 1 : 0;
	for (int bitplane = 0; bitplane < bitplanes; bitplane++) {
		for (int y = 0; y < self->height;) {
			int lineRepeatCount = ImgStream_GetLineRepeatCount(rle);
			if (self->resolution == RECOILResolution_ST1X2 || self->resolution == RECOILResolution_STE1X2)
				lineRepeatCount <<= 1;
			if (lineRepeatCount > self->height - y)
				lineRepeatCount = self->height - y;
			if (!ImgStream_UnpackLine(rle, unpacked, bytesPerBitplane, y)) {
				free(unpacked);
				return false;
			}
			while (--lineRepeatCount >= 0) {
				for (int x = 0; x < width; x++) {
					int c = unpacked[x >> 3] >> (~x & 7) & 1;
					int pixelsOffset = (y * width + x) << doubleWidth;
					if (bitplane != 0)
						c = c << bitplane | self->pixels[pixelsOffset];
					if (bitplane == bitplanes - 1) {
						c = self->contentPalette[c];
						if (doubleWidth != 0)
							self->pixels[pixelsOffset + 1] = c;
					}
					self->pixels[pixelsOffset] = c;
				}
				y++;
			}
		}
	}
	free(unpacked);
	return true;
}

static bool RECOIL_DecodeStImg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 17 || content[0] != 0 || content[1] > 3 || content[4] != 0)
		return false;
	int headerLength = (content[2] << 8 | content[3]) << 1;
	if (headerLength < 16 || headerLength >= contentLength)
		return false;
	int bitplanes = content[5];
	int width = content[12] << 8 | content[13];
	int height = content[14] << 8 | content[15];
	if (headerLength == 18 && content[16] == 0 && content[17] == 3) {
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		int contentOffset = 18;
		int pixelsLength = width * height;
		int count = 0;
		for (int i = 0; i < pixelsLength; i++) {
			if (count == 0) {
				if (contentOffset + 1 >= contentLength)
					return false;
				if (content[contentOffset++] != 128)
					return false;
				count = content[contentOffset++];
				if (count == 0)
					return false;
			}
			if (contentOffset + 2 >= contentLength)
				return false;
			self->pixels[i] = content[contentOffset + 2] << 16 | content[contentOffset + 1] << 8 | content[contentOffset];
			contentOffset += 3;
			count--;
		}
		return true;
	}
	int xRatio = content[8] << 8 | content[9];
	int yRatio = content[10] << 8 | content[11];
	if (bitplanes <= 2 && width <= 640 && height <= 200 && yRatio * 2 > xRatio * 3)
		RECOIL_SetSize(self, width, height << 1, RECOILResolution_ST1X2, 1);
	else if (bitplanes <= 8 && width <= 320 && height <= 480 && xRatio * 2 > yRatio * 3)
		RECOIL_SetSize(self, width << 1, height, RECOILResolution_TT2X1, 1);
	else if (!RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, true))
		return false;
	ImgStream rle;
	ImgStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = headerLength;
	rle.base.base.base.contentLength = contentLength;
	int bytesPerBitplane = (width + 7) >> 3;
	bool chunky = false;
	if (headerLength == 28 && RECOIL_IsStringAt(content, 16, "TIMG") && content[20] == 0 && content[21] == 3 && content[22] == 0 && content[24] == 0 && content[26] == 0) {
		switch (bitplanes << 24 | content[23] << 16 | content[25] << 8 | content[27]) {
		case 251987205:
		case 268764677:
		case 403179528:
			break;
		default:
			return false;
		}
	}
	else {
		switch (bitplanes) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			if (headerLength == 22 + (6 << bitplanes) && RECOIL_IsXimg(content)) {
				for (int i = 0; i < 1 << bitplanes; i++)
					self->contentPalette[i] = RECOIL_GetStVdiColor(content, 22 + i * 6);
			}
			else if (headerLength == 54 && RECOIL_IsStringAt(content, 16, "STTT") && content[20] == 0 && content[21] == 16)
				return RECOIL_DecodeSttt(self, &rle, width, bytesPerBitplane);
			else if (bitplanes == 8) {
				if (headerLength == 22 && RECOIL_IsXimg(content))
					RECOIL_SetGrayscalePalette(self, 255);
				else {
					int rgb = 16777215;
					for (int c = 0; c < 256; c++) {
						self->contentPalette[c] = rgb;
						for (int mask = 8421504;; mask >>= 1) {
							rgb ^= mask;
							if ((rgb & mask) == 0)
								break;
						}
					}
				}
			}
			else if (bitplanes > 2 && bitplanes != 4)
				return false;
			else if (headerLength == 50 && content[16] == 0 && content[17] == 128)
				RECOIL_SetStPalette(self, content, 18, 16, 0);
			else
				RECOIL_SetDefaultStPalette(self, bitplanes);
			break;
		case 16:
		case 24:
		case 32:
			chunky = true;
			break;
		default:
			return false;
		}
	}
	if (chunky && bitplanes == 24)
		bytesPerBitplane = (bytesPerBitplane + 1) & ~1;
	int bytesPerLine = bitplanes * bytesPerBitplane;
	uint8_t *unpacked = (uint8_t *) malloc(bytesPerLine * sizeof(uint8_t));
	for (int y = 0; y < height;) {
		int lineRepeatCount = FuInt_Min(ImgStream_GetLineRepeatCount(&rle), height - y);
		if (!ImgStream_UnpackLine(&rle, unpacked, bytesPerLine, y)) {
			free(unpacked);
			return false;
		}
		for (int x = 0; x < width; x++) {
			int c;
			if (chunky) {
				switch (bitplanes) {
				case 16:
					c = RECOIL_GetFalconTrueColor(unpacked, x << 1);
					break;
				case 24:
					c = RECOIL_GetR8G8B8Color(unpacked, x * 3);
					break;
				case 32:
					c = RECOIL_GetR8G8B8Color(unpacked, (x << 2) + 1);
					break;
				default:
					abort();
				}
			}
			else {
				c = RECOIL_GetBitplanePixel(unpacked, x >> 3, x, bitplanes, bytesPerBitplane);
				switch (bitplanes) {
				case 15:
					c = RECOIL_GetB5G5R5Color(c);
					break;
				case 16:
					c = (c & 31) << 19 | (c & 2016) << 5 | (c >> 8 & 248);
					c |= (c >> 5 & 458759) | (c >> 6 & 768);
					break;
				case 24:
					c = (c & 255) << 16 | (c & 65280) | c >> 16;
					break;
				default:
					c = self->contentPalette[c];
					break;
				}
			}
			for (int i = 0; i < lineRepeatCount; i++)
				RECOIL_SetScaledPixel(self, x, y + i, c);
		}
		y += lineRepeatCount;
	}
	free(unpacked);
	return true;
}

static bool RECOIL_DecodeStLowBlend(RECOIL *self, uint8_t const *bitmap, int bitmapOffset, uint8_t const *palette, int paletteOffset, int width, int height)
{
	RECOIL_DecodeStLow(self, bitmap, bitmapOffset, palette, paletteOffset, width, height, 2);
	RECOIL_DecodeBitplanes(self, bitmap, bitmapOffset + (width >> 1) * height, width >> 1, 4, width * height, width, height);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeDuo(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 113600 && RECOIL_DecodeStLowBlend(self, content, 32, content, 0, 416, 273);
}

static bool RECOIL_DecodeDu2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 113576 && contentLength != 113600)
		return false;
	RECOIL_DecodeStMedium(self, content, 8, content, 0, 832, 273, 2);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeP3c(RECOIL *self, uint8_t const *content, int contentLength)
{
	CaStream rle;
	CaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	int compressedLength = Stream_ParseDaliInt(&rle.base.base.base);
	if (compressedLength < 0)
		return false;
	int paletteOffset = rle.base.base.base.contentOffset;
	rle.base.base.base.contentLength = paletteOffset + 32 + compressedLength;
	if (rle.base.base.base.contentLength >= contentLength)
		return false;
	rle.base.base.base.contentOffset = paletteOffset + 32;
	uint8_t unpacked[64000];
	if (!CaStream_UnpackCa(&rle, unpacked, 0))
		return false;
	rle.base.base.base.contentLength = contentLength;
	compressedLength = Stream_ParseDaliInt(&rle.base.base.base);
	if (compressedLength < 0 || rle.base.base.base.contentOffset + compressedLength != contentLength)
		return false;
	rle.base.base.base.contentLength = contentLength;
	return CaStream_UnpackCa(&rle, unpacked, 32000) && RECOIL_DecodeStLowBlend(self, unpacked, 0, content, paletteOffset, 320, 200);
}

static bool RECOIL_UnpackLz4(const RECOIL *self, uint8_t const *content, int contentLength, uint8_t *unpacked, int unpackedLength)
{
	if (contentLength < 11 || content[0] != 4 || content[1] != 34 || content[2] != 77 || content[3] != 24 || (content[4] & 195) != 64)
		return false;
	Lz4Stream stream;
	stream.base.content = content;
	stream.base.contentOffset = 7;
	if ((content[4] & 8) != 0)
		stream.base.contentOffset += 8;
	stream.unpacked = unpacked;
	stream.unpackedOffset = 0;
	stream.unpackedLength = unpackedLength;
	for (;;) {
		if (stream.base.contentOffset + 4 > contentLength)
			return false;
		int blockSize = RECOIL_Get32LittleEndian(content, stream.base.contentOffset);
		stream.base.contentOffset += 4;
		stream.base.contentLength = contentLength;
		if (blockSize == 0)
			break;
		if (blockSize >> 31 != 0) {
			if (!Lz4Stream_Copy(&stream, blockSize & 2147483647))
				return false;
			continue;
		}
		stream.base.contentLength = stream.base.contentOffset + blockSize;
		if (stream.base.contentLength > contentLength)
			return false;
		for (;;) {
			int token = Stream_ReadByte(&stream.base);
			if (token < 0)
				return false;
			int count = Lz4Stream_ReadCount(&stream, token >> 4);
			if (count < 0 || !Lz4Stream_Copy(&stream, count))
				return false;
			if (stream.base.contentOffset == stream.base.contentLength)
				break;
			if (stream.base.contentOffset > stream.base.contentLength - 2)
				return false;
			int distance = Stream_ReadByte(&stream.base);
			distance += Stream_ReadByte(&stream.base) << 8;
			if (distance == 0)
				return false;
			count = Lz4Stream_ReadCount(&stream, token & 15);
			if (count < 0)
				return false;
			count += 4;
			int nextOffset = stream.unpackedOffset + count;
			if (nextOffset > unpackedLength || !RECOIL_CopyPrevious(unpacked, stream.unpackedOffset, distance, count))
				return false;
			stream.unpackedOffset = nextOffset;
		}
		if ((content[4] & 16) != 0)
			stream.base.contentOffset += 4;
	}
	if ((content[4] & 4) != 0)
		stream.base.contentOffset += 4;
	return stream.base.contentOffset == contentLength && stream.unpackedOffset == unpackedLength;
}

static bool RECOIL_DecodePl4(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[64070];
	if (!RECOIL_UnpackLz4(self, content, contentLength, unpacked, 64070) || unpacked[0] != 0 || unpacked[1] != 0 || unpacked[32036] != 0 || unpacked[32037] != 0)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOIL_IsStePalette(unpacked, 2, 16) || RECOIL_IsStePalette(unpacked, 32038, 16) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, 2);
	RECOIL_SetStPalette(self, unpacked, 2, 16, 0);
	RECOIL_DecodeBitplanes(self, unpacked, 34, 160, 4, 0, 320, 200);
	RECOIL_SetStPalette(self, unpacked, 32038, 16, 0);
	RECOIL_DecodeBitplanes(self, unpacked, 32070, 160, 4, 64000, 320, 200);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeSpuVariable(RECOIL *self, uint8_t const *content, int height, int bitmapOffset, int paletteOffset, bool enhanced)
{
	if (!RECOIL_SetSize(self, 320, height, enhanced || RECOIL_IsStePalette(content, paletteOffset, height * 48) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, 1))
		return false;
	if (enhanced)
		self->frames = 2;
	int pixelsOffset = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < 320; x++) {
			int c = RECOIL_GetStLowPixel(content, bitmapOffset, pixelsOffset);
			int x1 = c * 10 + 1 - (c & 1) * 6;
			if (x >= x1 + 160)
				c += 32;
			else if (x >= x1)
				c += 16;
			int colorOffset = paletteOffset + y * 96 + (c << 1);
			self->pixels[pixelsOffset++] = enhanced ? RECOIL_GetSteInterlacedColor(content[colorOffset] << 8 | content[colorOffset + 1]) : RECOIL_GetStColor(self, content, colorOffset);
		}
	}
	return true;
}

static bool RECOIL_DecodeSpuScreen(RECOIL *self, uint8_t const *content, bool enhanced)
{
	return RECOIL_DecodeSpuVariable(self, content, 199, 160, 32000, enhanced);
}

static bool RECOIL_DecodeSpu(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 51104 && RECOIL_DecodeSpuScreen(self, content, RECOIL_IsStringAt(content, 0, "5BIT"));
}

static bool RECOIL_UnpackSpc(RleStream *rle, uint8_t *unpacked)
{
	for (int bitplane = 0; bitplane < 8; bitplane += 2) {
		if (!RleStream_UnpackWords(rle, unpacked, 160 + bitplane, 8, 32000))
			return false;
	}
	return true;
}

static bool RECOIL_DecodeStSpc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 12 || content[0] != 'S' || content[1] != 'P')
		return false;
	uint8_t unpacked[51104];
	SpcStream rle;
	SpcStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 12;
	rle.base.base.base.contentLength = contentLength;
	if (!RECOIL_UnpackSpc(&rle.base, unpacked))
		return false;
	int contentOffset = 12 + RECOIL_Get32BigEndian(content, 4);
	if (contentOffset < 12)
		return false;
	for (int unpackedOffset = 32000; unpackedOffset < 51104;) {
		if (contentOffset >= contentLength - 1)
			return false;
		int got = (content[contentOffset] & 127) << 8 | content[contentOffset + 1];
		contentOffset += 2;
		for (int i = 0; i < 16; i++) {
			if ((got >> i & 1) == 0) {
				unpacked[unpackedOffset] = 0;
				unpacked[unpackedOffset + 1] = 0;
			}
			else {
				if (contentOffset >= contentLength - 1)
					return false;
				unpacked[unpackedOffset] = content[contentOffset];
				unpacked[unpackedOffset + 1] = content[contentOffset + 1];
				contentOffset += 2;
			}
			unpackedOffset += 2;
		}
	}
	return RECOIL_DecodeSpuScreen(self, unpacked, false);
}

static bool RECOIL_DecodeSps(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 13 || content[0] != 'S' || content[1] != 'P' || content[2] != 0 || content[3] != 0)
		return false;
	uint8_t unpacked[51104];
	SpsStream rle;
	SpsStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 12;
	rle.base.base.base.contentLength = contentLength;
	if ((content[contentLength - 1] & 1) == 0) {
		for (int bitplane = 0; bitplane < 8; bitplane += 2) {
			for (int x = 0; x < 40; x++) {
				if (!RleStream_Unpack(&rle.base, unpacked, 160 + ((x & ~1) << 2) + bitplane + (x & 1), 160, 32000))
					return false;
			}
		}
	}
	else if (!RECOIL_UnpackSpc(&rle.base, unpacked))
		return false;
	BitStream bitStream;
	BitStream_Construct(&bitStream);
	bitStream.base.content = content;
	bitStream.base.contentOffset = 12 + RECOIL_Get32BigEndian(content, 4);
	if (bitStream.base.contentOffset < 12)
		return false;
	bitStream.base.contentLength = contentLength;
	for (int unpackedOffset = 32000; unpackedOffset < 51104;) {
		int got = BitStream_ReadBits(&bitStream, 14);
		if (got < 0)
			return false;
		got <<= 1;
		for (int i = 15; i >= 0; i--) {
			int rgb;
			if ((got >> i & 1) == 0)
				rgb = 0;
			else {
				rgb = BitStream_ReadBits(&bitStream, 9);
				if (rgb < 0)
					return false;
			}
			unpacked[unpackedOffset] = (uint8_t) (rgb >> 6);
			unpacked[unpackedOffset + 1] = (uint8_t) ((rgb & 63) + (rgb & 56));
			unpackedOffset += 2;
		}
	}
	return RECOIL_DecodeSpuScreen(self, unpacked, false);
}

static bool RECOIL_DecodeSpxV2(RECOIL *self, uint8_t const *content, int contentLength, SpxStream *stream)
{
	if (content[5] != 1)
		return false;
	int unpackedLength = RECOIL_Get32BigEndian(content, stream->base.contentStart);
	if (unpackedLength <= 0 || unpackedLength > 134217728)
		return false;
	int bitmapLength = RECOIL_Get32BigEndian(content, stream->base.contentStart - 8);
	int paletteOffset = RECOIL_Get32BigEndian(content, stream->base.contentStart - 4);
	int packedLength = RECOIL_Get32BigEndian(content, stream->base.contentStart + 4);
	stream->base.contentStart += 8;
	int packedEnd = stream->base.contentStart + packedLength;
	if (bitmapLength != 8 + packedLength || packedEnd > contentLength || packedEnd < 0)
		return false;
	stream->base.contentOffset = packedEnd;
	uint8_t *unpacked = (uint8_t *) malloc(unpackedLength * sizeof(uint8_t));
	if (!SpxStream_UnpackV2(stream, unpacked, unpackedLength)) {
		free(unpacked);
		return false;
	}
	if (paletteOffset == 98336 && unpackedLength == 155552) {
		bool returnValue = RECOIL_DecodeSpuVariable(self, unpacked, 597, 160, 98240, false);
		free(unpacked);
		return returnValue;
	}
	int height = (unpackedLength - paletteOffset) / 96;
	bool returnValue = paletteOffset >= 320 + height * 160 && RECOIL_DecodeSpuVariable(self, unpacked, height, 320, paletteOffset, false);
	free(unpacked);
	return returnValue;
}

static bool RECOIL_DecodeSpx(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 12 || content[0] != 'S' || content[1] != 'P' || content[2] != 'X')
		return false;
	int contentOffset = 10;
	for (int zerosToSkip = 2;;) {
		if (contentOffset + 16 >= contentLength)
			return false;
		if (content[contentOffset++] == 0) {
			if (--zerosToSkip == 0)
				break;
		}
	}
	int bitmapLength = RECOIL_Get32BigEndian(content, contentOffset);
	int paletteOffset = contentOffset + 8 + bitmapLength;
	if (paletteOffset > contentLength)
		return false;
	SpxStream stream;
	stream.base.content = content;
	stream.base.contentStart = contentOffset + 8;
	stream.base.contentOffset = paletteOffset;
	switch (content[4]) {
	case 0:
		break;
	case 1:
		switch (content[3]) {
		case 1:
			bitmapLength = Ice21Stream_GetUnpackedLength(&stream.base);
			break;
		case 2:
			return RECOIL_DecodeSpxV2(self, content, contentLength, &stream);
		default:
			return false;
		}
		break;
	default:
		return false;
	}
	bitmapLength -= 160;
	if (bitmapLength <= 0 || bitmapLength % 160 != 0)
		return false;
	int height = bitmapLength / 160;
	uint8_t *unpacked = (uint8_t *) malloc((height << 8) * sizeof(uint8_t));
	int paletteLength = RECOIL_Get32BigEndian(content, stream.base.contentStart - 4);
	if (content[4] == 0)
		memcpy(unpacked, content + (stream.base.contentStart + 160), bitmapLength);
	else if (content[3] == 1) {
		if (!Ice21Stream_Unpack(&stream.base, unpacked, 0, bitmapLength)) {
			free(unpacked);
			return false;
		}
	}
	if (content[5] == 0) {
		if (paletteLength != height * 96) {
			free(unpacked);
			return false;
		}
		memcpy(unpacked + bitmapLength, content + paletteOffset, paletteLength);
	}
	else {
		stream.base.contentStart = paletteOffset;
		stream.base.contentOffset = paletteOffset + paletteLength;
		if (stream.base.contentOffset > contentLength || Ice21Stream_GetUnpackedLength(&stream.base) != height * 96 || !Ice21Stream_Unpack(&stream.base, unpacked, bitmapLength, height << 8)) {
			free(unpacked);
			return false;
		}
	}
	bool returnValue = RECOIL_DecodeSpuVariable(self, unpacked, height, 0, height * 160, false);
	free(unpacked);
	return returnValue;
}

static int RECOIL_GetStLowSeparateBitplanes(uint8_t const *content, int contentOffset, int bitplaneLength, int x)
{
	return RECOIL_GetBitplanePixel(content, contentOffset + (x >> 3), x, 4, bitplaneLength);
}

static bool RECOIL_DecodePci(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 115648)
		return false;
	RECOIL_SetSize(self, 352, 278, RECOIL_IsStePalette(content, 97856, 8896) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, 2);
	int bitmapOffset = 0;
	for (int y = 0; y < 556; y++) {
		if (y == 278)
			bitmapOffset = 48928;
		RECOIL_SetStPalette(self, content, 97856 + (y << 5), 16, 0);
		for (int x = 0; x < 352; x++)
			self->pixels[y * 352 + x] = self->contentPalette[RECOIL_GetStLowSeparateBitplanes(content, bitmapOffset, 12232, x)];
		bitmapOffset += 44;
	}
	return RECOIL_ApplyBlend(self);
}

static void RECOIL_DecodePcsScreen(RECOIL *self, uint8_t const *unpacked, int pixelsOffset)
{
	for (int y = 0; y < 199; y++) {
		for (int x = 0; x < 320; x++) {
			int c = RECOIL_GetStLowSeparateBitplanes(unpacked, 40 + y * 40, 8000, x) << 1;
			if (x >= c * 2) {
				if (c < 28) {
					if (x >= c * 2 + 76) {
						if (x >= 176 + c * 5 - (c & 2) * 3)
							c += 32;
						c += 32;
					}
				}
				else if (x >= c * 2 + 92)
					c += 32;
				c += 32;
			}
			self->pixels[pixelsOffset++] = RECOIL_GetStColor(self, unpacked, 32000 + y * 96 + c);
		}
	}
}

static bool RECOIL_DecodePcs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 18 || content[0] != 1 || content[1] != 64 || content[2] != 0 || content[3] != 200)
		return false;
	PcsStream rle;
	PcsStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = 6;
	rle.base.base.base.base.contentLength = contentLength;
	uint8_t unpacked1[51136];
	if (!PcsStream_UnpackPcs(&rle, unpacked1))
		return false;
	if (content[4] == 0) {
		RECOIL_SetSize(self, 320, 199, RECOIL_IsStePalette(unpacked1, 32000, 9616) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, 1);
		RECOIL_DecodePcsScreen(self, unpacked1, 0);
		return true;
	}
	uint8_t unpacked2[51136];
	if (!PcsStream_UnpackPcs(&rle, unpacked2))
		return false;
	if ((content[4] & 1) == 0) {
		for (int i = 0; i < 32000; i++)
			unpacked2[i] ^= unpacked1[i];
	}
	if ((content[4] & 2) == 0) {
		for (int i = 32000; i < 51136; i++)
			unpacked2[i] ^= unpacked1[i];
	}
	RECOIL_SetSize(self, 320, 199, RECOIL_IsStePalette(unpacked1, 32000, 9616) || RECOIL_IsStePalette(unpacked2, 32000, 9616) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, 2);
	RECOIL_DecodePcsScreen(self, unpacked1, 0);
	RECOIL_DecodePcsScreen(self, unpacked2, 63680);
	return RECOIL_ApplyBlend(self);
}

static uint8_t const *RECOIL_UnpackPbx(const RECOIL *self, uint8_t const *content, int contentLength, uint8_t *unpacked, int bitmapOffset, int bytesPer16Pixels, int unpackedLength)
{
	if (content[4] != 128 || content[5] != 1)
		return contentLength == unpackedLength ? content : NULL;
	PackBitsStream rle;
	PackBitsStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 128;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 128, 1, bitmapOffset))
		return NULL;
	for (int bitplane = 0; bitplane < bytesPer16Pixels; bitplane += 2) {
		for (int x = bitplane; x < 160; x += bytesPer16Pixels) {
			if (!RleStream_UnpackWords(&rle.base, unpacked, bitmapOffset + x, 160, unpackedLength))
				return NULL;
		}
	}
	return unpacked;
}

static bool RECOIL_DecodePbx01(RECOIL *self, uint8_t const *content, int contentLength, int bitplanes, int lineHeight)
{
	uint8_t unpacked[32512];
	uint8_t const *source = RECOIL_UnpackPbx(self, content, contentLength, unpacked, 512, bitplanes << 1, 32512);
	if (source == NULL || source[161] != 0)
		return false;
	int paletteOffset = 128;
	for (int y = 0; y < 200; y++) {
		if (paletteOffset < 512 && y == source[paletteOffset + 33]) {
			RECOIL_SetStPalette(self, source, paletteOffset, 16, 0);
			do
				paletteOffset += 48;
			while (paletteOffset < 512 && source[paletteOffset + 34] == 0 && source[paletteOffset + 35] == 0);
		}
		RECOIL_DecodeBitplanes(self, source, 512 + y * 160, 0, bitplanes, y * lineHeight * self->width, self->width, lineHeight);
	}
	return true;
}

static void RECOIL_DecodePbx8(RECOIL *self, uint8_t const *content, int paletteOffset, int bitmapOffset, int pixelsOffset)
{
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 320; x++) {
			int c = RECOIL_GetStLowPixel(content, bitmapOffset + y * 160, x);
			if (x >= (c > 7 ? 88 : 76) + c * 10 - (c & 1) * 6)
				c += 16;
			self->pixels[pixelsOffset + x] = RECOIL_GetStColor(self, content, paletteOffset + (y << 6) + (c << 1));
		}
		pixelsOffset += 320;
	}
}

static bool RECOIL_DecodePbx(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 128 || content[0] != 0 || content[1] != 0 || content[2] != 0)
		return false;
	switch (content[3]) {
	case 0:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
		return RECOIL_DecodePbx01(self, content, contentLength, 4, 1);
	case 1:
		RECOIL_SetSize(self, 640, 400, RECOILResolution_ST1X2, 1);
		return RECOIL_DecodePbx01(self, content, contentLength, 2, 2);
	case 128:
		{
			uint8_t unpacked[44928];
			uint8_t const *source = RECOIL_UnpackPbx(self, content, contentLength, unpacked, 12928, 8, 44928);
			if (source == NULL)
				return false;
			RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
			RECOIL_DecodePbx8(self, source, 128, 12928, 0);
			return true;
		}
	case 129:
		{
			uint8_t unpacked[57728];
			uint8_t const *source = RECOIL_UnpackPbx(self, content, contentLength, unpacked, 25728, 8, 57728);
			if (source == NULL)
				return false;
			RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 2);
			RECOIL_DecodePbx8(self, source, 128, 25728, 0);
			RECOIL_DecodePbx8(self, source, 12928, 25728, 64000);
			return RECOIL_ApplyBlend(self);
		}
	default:
		return false;
	}
}

static void RECOIL_DecodeMppScreen(RECOIL *self, uint8_t const *content, int paletteOffset, int paletteLength, int pixelsOffset)
{
	int mode = content[3];
	int bitmapOffset = paletteOffset + paletteLength;
	int palette[16] = { 0 };
	MppPaletteStream paletteStream;
	MppPaletteStream_Construct(&paletteStream);
	paletteStream.base.base.content = content;
	paletteStream.base.base.contentOffset = paletteOffset;
	paletteStream.base.base.contentLength = bitmapOffset;
	for (int y = 0; y < self->height; y++) {
		for (int c = mode == 3 ? 6 : 1; c < 16; c++)
			palette[c] = MppPaletteStream_Read(&paletteStream);
		static const uint8_t FIRST_CHANGE_X[4] = { 33, 9, 4, 69 };
		int changeX = FIRST_CHANGE_X[mode];
		int changeColor = 0;
		for (int x = 0; x < self->width; x++) {
			if (x == changeX) {
				static const uint8_t RIGHT_BORDER_COLOR[4] = { 32, 16, 32, 127 };
				palette[changeColor & 15] = changeColor == RIGHT_BORDER_COLOR[mode] ? 0 : MppPaletteStream_Read(&paletteStream);
				switch (mode) {
				case 0:
				case 3:
					switch (changeColor) {
					case 15:
						changeX += mode == 0 ? 88 : 112;
						break;
					case 31:
						changeX += 12;
						break;
					case 37:
						changeX += 100;
						break;
					default:
						changeX += 4;
						break;
					}
					break;
				case 1:
					changeX += (changeColor & 1) == 0 ? 4 : 16;
					break;
				case 2:
					changeX += 8;
					break;
				default:
					abort();
				}
				changeColor++;
			}
			self->pixels[pixelsOffset + x] = palette[RECOIL_GetStLowPixel(content, bitmapOffset, x)];
		}
		bitmapOffset += self->width >> 1;
		pixelsOffset += self->width;
	}
}

static bool RECOIL_DecodeMpp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 12 || content[0] != 'M' || content[1] != 'P' || content[2] != 'P')
		return false;
	int mode = content[3];
	if (mode > 3)
		return false;
	int width = mode < 3 ? 320 : 416;
	int height = mode < 3 ? 199 : 273;
	int frames = 1 + (content[4] >> 2 & 1);
	static const uint8_t MODE_COLORS_PER_LINE[4] = { 52, 46, 54, 48 };
	int paletteLength = MODE_COLORS_PER_LINE[mode] * height;
	switch (content[4] & 3) {
	case 0:
		RECOIL_SetSize(self, width, height, RECOILResolution_ST1X1, frames);
		paletteLength *= 9;
		break;
	case 1:
		RECOIL_SetSize(self, width, height, RECOILResolution_STE1X1, frames);
		paletteLength *= 12;
		break;
	case 3:
		RECOIL_SetSize(self, width, height, RECOILResolution_STE1X1, frames);
		self->frames = 2;
		paletteLength *= 15;
		break;
	default:
		return false;
	}
	paletteLength = (paletteLength + 15) >> 4 << 1;
	int paletteOffset = 12 + RECOIL_Get32BigEndian(content, 8);
	if (paletteOffset < 12)
		return false;
	int pixelsLength = width * height;
	if (contentLength != paletteOffset + (paletteLength + (pixelsLength >> 1)) * frames)
		return false;
	RECOIL_DecodeMppScreen(self, content, paletteOffset, paletteLength, 0);
	if (frames == 1)
		return true;
	RECOIL_DecodeMppScreen(self, content, paletteOffset + paletteLength + (pixelsLength >> 1), paletteLength, pixelsLength);
	return RECOIL_ApplyBlend(self);
}

static bool RECOIL_DecodeHrm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 92000)
		return false;
	RECOIL_SetSize(self, 640, 400, RECOILResolution_STE1X2, 1);
	self->frames = 2;
	for (int y = 0; y < 400; y++) {
		for (int x = 0; x < 640; x++) {
			int offset = y * 160 + (x >> 2 & ~3) + (x >> 3 & 1);
			int bit = ~x & 7;
			int c = (content[offset] >> bit & 1) | (content[offset + 2] >> bit & 1) << 1;
			static const uint8_t COLOR_OFFSETS[4] = { 80, 72, 40, 32 };
			c += ((x + COLOR_OFFSETS[c]) / 80 << 2) - 1;
			int rgb = RECOIL_GetStColor(self, content, 64000 + y * 70 + (c << 1));
			int pixelsOffset = y * 640 + x;
			if ((y & 1) == 0)
				self->pixels[pixelsOffset] = rgb;
			else {
				int rgb1 = self->pixels[pixelsOffset - 640];
				self->pixels[pixelsOffset] = self->pixels[pixelsOffset - 640] = (rgb1 & rgb) + ((rgb1 ^ rgb) >> 1 & 8355711);
			}
		}
	}
	return true;
}

static bool RECOIL_DecodeStIcn(RECOIL *self, uint8_t const *content, int contentLength)
{
	IcnParser parser;
	parser.base.content = content;
	parser.base.contentOffset = 0;
	parser.base.contentLength = contentLength;
	int width = IcnParser_ParseDefine(&parser, "ICON_W");
	if (width <= 0 || width >= 256)
		return false;
	int height = IcnParser_ParseDefine(&parser, "ICON_H");
	if (height <= 0 || height >= 256)
		return false;
	int size = IcnParser_ParseDefine(&parser, "ICONSIZE");
	if (size != ((width + 15) >> 4) * height)
		return false;
	if (!IcnParser_ExpectAfterWhitespace(&parser, "int") || !IcnParser_ExpectAfterWhitespace(&parser, "image[ICONSIZE]") || !IcnParser_ExpectAfterWhitespace(&parser, "=") || !IcnParser_ExpectAfterWhitespace(&parser, "{"))
		return false;
	uint8_t bitmap[8192];
	for (int i = 0;;) {
		int value = IcnParser_ParseHex(&parser);
		if (value < 0)
			return false;
		bitmap[i * 2] = (uint8_t) (value >> 8);
		bitmap[i * 2 + 1] = (uint8_t) value;
		if (++i >= size)
			break;
		if (parser.base.contentOffset >= contentLength)
			return false;
		if (content[parser.base.contentOffset++] != ',')
			return false;
	}
	if (!IcnParser_ExpectAfterWhitespace(&parser, "};"))
		return false;
	RECOIL_SetSize(self, width, height, RECOILResolution_ST1X1, 1);
	return RECOIL_DecodeBlackAndWhite(self, bitmap, 0, size << 1, true, 16777215);
}

static bool RECOIL_DecodeIm(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 16384:
		RECOIL_SetSize(self, 128, 128, RECOILResolution_ST1X1, 1);
		break;
	case 65536:
		RECOIL_SetSize(self, 256, 256, RECOILResolution_ST1X1, 1);
		break;
	default:
		return false;
	}
	RECOIL_SetGrayscalePalette(self, 0);
	RECOIL_DecodeBytes(self, content, 0);
	return true;
}

static bool RECOIL_DecodeCol(RECOIL *self, uint8_t const *content, int contentLength)
{
	int width;
	switch (contentLength) {
	case 65536:
		width = 128;
		break;
	case 262144:
		width = 256;
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, width, width, RECOILResolution_ST1X1, 1);
	int pixelsLength = contentLength >> 2;
	for (int i = 0; i < pixelsLength; i++)
		self->pixels[i] = content[pixelsLength + i] << 16 | content[pixelsLength * 2 + i] << 8 | content[pixelsLength * 3 + i];
	return true;
}

static bool RECOIL_DecodeCe(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 192022 || !RECOIL_IsStringAt(content, 0, "EYES") || content[4] != 0)
		return false;
	switch (content[5]) {
	case 0:
		if (contentLength != 192022)
			return false;
		RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
		for (int y = 0; y < 200; y++) {
			for (int x = 0; x < 320; x++) {
				int offset = 22 + x * 200 + y;
				int rgb = content[offset] << 16 | content[64000 + offset] << 8 | content[128000 + offset];
				if ((rgb & 12632256) != 0)
					return false;
				self->pixels[y * 320 + x] = rgb << 2 | (rgb >> 4 & 197379);
			}
		}
		return true;
	case 1:
		if (contentLength != 256022)
			return false;
		RECOIL_SetSize(self, 640, 400, RECOILResolution_ST1X2, 1);
		for (int y = 0; y < 200; y++) {
			for (int x = 0; x < 640; x++) {
				int offset = (11 + x * 200 + y) << 1;
				int c = content[offset] << 8 | content[offset + 1];
				if (c >= 32768)
					return false;
				offset = y * 1280 + x;
				self->pixels[offset + 640] = self->pixels[offset] = RECOIL_GetR5G5B5Color(c);
			}
		}
		return true;
	case 2:
		if (contentLength != 256022)
			return false;
		RECOIL_SetSize(self, 640, 400, RECOILResolution_ST1X1, 1);
		for (int y = 0; y < 400; y++) {
			for (int x = 0; x < 640; x++) {
				int b = content[22 + x * 400 + (y & 1) * 200 + (y >> 1)];
				if (b > 191)
					return false;
				self->pixels[y * 640 + x] = b * 4 / 3 * 65793;
			}
		}
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeIbi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if ((contentLength != 704 && contentLength != 1600) || content[0] != 'I' || content[1] != 'C' || content[2] != 'B' || (content[3] != 'I' && content[3] != '3') || content[8] != 0 || content[9] != 32 || content[10] != 0 || content[11] != 32)
		return false;
	RECOIL_SetSize(self, 32, 32, RECOILResolution_FALCON1X1, 1);
	RECOIL_SetDefaultStPalette(self, 4);
	RECOIL_DecodeBitplanes(self, content, 64, 16, 4, 0, 32, 32);
	return true;
}

static bool RECOIL_DecodeBw(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 11 || !RECOIL_IsStringAt(content, 0, "B&W256"))
		return false;
	int width = content[6] << 8 | content[7];
	int height = content[8] << 8 | content[9];
	if (contentLength != 10 + width * height || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
		return false;
	RECOIL_SetGrayscalePalette(self, 0);
	RECOIL_DecodeBytes(self, content, 10);
	return true;
}

static bool RECOIL_DecodeFalconHir(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 11 || content[0] != 15 || content[1] != 15 || content[2] != 0 || content[3] != 1 || content[8] != 0 || content[9] != 1)
		return false;
	int width = content[4] << 8 | content[5];
	int height = content[6] << 8 | content[7];
	int pixelsLength = width * height;
	if (contentLength != 10 + pixelsLength || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
		return false;
	for (int i = 0; i < pixelsLength; i++) {
		int b = content[10 + i];
		if (b >= 128)
			return false;
		self->pixels[i] = b * 131586;
	}
	return true;
}

static bool RECOIL_DecodeRw(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 64000:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_FALCON1X1, 1);
		break;
	case 128000:
		RECOIL_SetSize(self, 640, 200, RECOILResolution_FALCON1X1, 1);
		break;
	case 256000:
		RECOIL_SetSize(self, 640, 400, RECOILResolution_FALCON1X1, 1);
		break;
	default:
		return false;
	}
	RECOIL_SetGrayscalePalette(self, 255);
	RECOIL_DecodeBytes(self, content, 0);
	return true;
}

static void RECOIL_DecodeR8G8G8X8Colors(RECOIL *self, uint8_t const *content, int contentOffset, int count)
{
	for (int i = 0; i < count; i++)
		self->pixels[i] = RECOIL_GetR8G8B8Color(content, contentOffset + (i << 2));
}

static bool RECOIL_DecodeIim(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 17 || !RECOIL_IsStringAt(content, 0, "IS_IMAGE") || content[8] != 0)
		return false;
	int width = content[12] << 8 | content[13];
	int height = content[14] << 8 | content[15];
	int pixelsLength = width * height;
	switch (content[9]) {
	case 0:
		return RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1) && RECOIL_DecodeBlackAndWhite(self, content, 16, contentLength, false, 16777215);
	case 1:
		if (contentLength != 16 + pixelsLength || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		RECOIL_SetGrayscalePalette(self, 255);
		RECOIL_DecodeBytes(self, content, 16);
		return true;
	case 4:
		if (contentLength != 16 + pixelsLength * 3 || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		RECOIL_DecodeR8G8B8Colors(content, 16, pixelsLength, self->pixels, 0);
		return true;
	case 5:
		if (contentLength != 16 + (pixelsLength << 2) || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		RECOIL_DecodeR8G8G8X8Colors(self, content, 17, pixelsLength);
		return true;
	default:
		return false;
	}
}

static void RECOIL_SetFalconPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors)
{
	for (int i = 0; i < colors; i++) {
		int offset = contentOffset + (i << 2);
		self->contentPalette[i] = content[offset] << 16 | content[offset + 1] << 8 | content[offset + 3];
	}
}

static void RECOIL_DecodeFalconPalette(RECOIL *self, uint8_t const *content, int bitplanesOffset, int paletteOffset, int width, int height)
{
	RECOIL_SetFalconPalette(self, content, paletteOffset, 256);
	RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1);
	RECOIL_DecodeBitplanes(self, content, bitplanesOffset, width, 8, 0, width, height);
}

static bool RECOIL_DecodeFuckpaint(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 65024:
		RECOIL_DecodeFalconPalette(self, content, 1024, 0, 320, 200);
		return true;
	case 77824:
		RECOIL_DecodeFalconPalette(self, content, 1024, 0, 320, 240);
		return true;
	case 308224:
		RECOIL_DecodeFalconPalette(self, content, 1024, 0, 640, 480);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeDg1(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 65032 || content[0] != 'D' || content[1] != 'G' || content[2] != 'U' || content[3] != 1 || content[4] != 1 || content[5] != 64 || content[6] != 0 || content[7] != 200)
		return false;
	RECOIL_DecodeFalconPalette(self, content, 1032, 8, 320, 200);
	return true;
}

static bool RECOIL_DecodeDc1(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1042 || content[0] != 'D' || content[1] != 'G' || content[2] != 'C' || content[4] != 1 || content[5] != 64 || content[6] != 0 || content[7] != 200)
		return false;
	int compression = content[3];
	if (compression == 0) {
		if (contentLength != 65034)
			return false;
		RECOIL_DecodeFalconPalette(self, content, 1034, 10, 320, 200);
		return true;
	}
	if (compression > 3)
		return false;
	uint8_t unpacked[64000];
	int contentOffset = 1038;
	int valueBytes = 1 << (compression - 1);
	int repeatCount = 0;
	for (int bitplane = 0; bitplane < 16; bitplane += 2) {
		for (int unpackedOffset = bitplane; unpackedOffset < 64000; unpackedOffset += 16) {
			for (int x = 0; x < 2; x++) {
				if (repeatCount == 0) {
					int nextContentOffset = contentOffset + compression * 2;
					if (nextContentOffset > contentLength) {
						unpacked[unpackedOffset + x] = 0;
						continue;
					}
					switch (compression) {
					case 1:
						repeatCount = content[contentOffset] + 1;
						break;
					case 2:
						repeatCount = ((content[contentOffset] << 8) + content[contentOffset + 1] + 1) << 1;
						break;
					case 3:
						repeatCount = ((content[contentOffset] << 8) + content[contentOffset + 1] + 1) << 2;
						break;
					default:
						abort();
					}
					contentOffset = nextContentOffset;
				}
				unpacked[unpackedOffset + x] = content[contentOffset - (--repeatCount & (valueBytes - 1)) - 1];
			}
		}
	}
	RECOIL_SetFalconPalette(self, content, 10, 256);
	RECOIL_SetSize(self, 320, 200, RECOILResolution_FALCON1X1, 1);
	RECOIL_DecodeBitplanes(self, unpacked, 0, 320, 8, 0, 320, 200);
	return true;
}

static bool RECOIL_DecodeDel(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[96000];
	return CaStream_UnpackDel(content, contentLength, unpacked, 2) && RECOIL_DecodeFuckpaint(self, unpacked, 77824);
}

static bool RECOIL_DecodeDph(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t *unpacked = (uint8_t *) malloc(320000 * sizeof(uint8_t));
	if (!CaStream_UnpackDel(content, contentLength, unpacked, 10)) {
		free(unpacked);
		return false;
	}
	RECOIL_SetFalconPalette(self, unpacked, 0, 256);
	RECOIL_SetSize(self, 640, 480, RECOILResolution_FALCON1X1, 1);
	RECOIL_DecodeBitplanes(self, unpacked, 1024, 320, 8, 0, 320, 240);
	RECOIL_DecodeBitplanes(self, unpacked, 77824, 320, 8, 320, 320, 240);
	RECOIL_DecodeBitplanes(self, unpacked, 154624, 320, 8, 153600, 320, 240);
	RECOIL_DecodeBitplanes(self, unpacked, 231424, 320, 8, 153920, 320, 240);
	free(unpacked);
	return true;
}

static bool RECOIL_DecodeFalconTrueColor(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height, RECOILResolution resolution)
{
	if (!RECOIL_SetScaledSize(self, width, height, resolution))
		return false;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			RECOIL_SetScaledPixel(self, x, y, RECOIL_GetFalconTrueColor(content, contentOffset));
			contentOffset += 2;
		}
	}
	return true;
}

static bool RECOIL_DecodeFalconTrueColorVariable(RECOIL *self, uint8_t const *content, int contentLength, int widthOffset, int dataOffset)
{
	int width = content[widthOffset] << 8 | content[widthOffset + 1];
	int height = content[widthOffset + 2] << 8 | content[widthOffset + 3];
	return dataOffset + width * height * 2 == contentLength && RECOIL_DecodeFalconTrueColor(self, content, dataOffset, width, height, RECOILResolution_FALCON1X1);
}

static bool RECOIL_DecodeFtc(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 184320 && RECOIL_DecodeFalconTrueColor(self, content, 0, 384, 240, RECOILResolution_FALCON1X1);
}

static bool RECOIL_DecodeXga(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 153600:
		return RECOIL_DecodeFalconTrueColor(self, content, 0, 320, 240, RECOILResolution_FALCON1X1);
	case 368640:
		return RECOIL_DecodeFalconTrueColor(self, content, 0, 384, 480, RECOILResolution_FALCON2X1);
	default:
		return false;
	}
}

static bool RECOIL_DecodeGod(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength > 6 && RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 2, 6);
}

static bool RECOIL_DecodeTrp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength >= 9 && (RECOIL_IsStringAt(content, 0, "TRUP") || RECOIL_IsStringAt(content, 0, "tru?")) && RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 4, 8);
}

static bool RECOIL_DecodeTru(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength >= 256 && RECOIL_IsStringAt(content, 0, "Indy") && RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 4, 256);
}

static bool RECOIL_DecodeTg1(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength >= 20 && RECOIL_IsStringAt(content, 0, "COKE format.") && content[16] == 0 && content[17] == 18 && RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 12, 18);
}

static bool RECOIL_DecodeTcp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength >= 218 && RECOIL_IsStringAt(content, 0, "TRUECOLR") && content[12] == 0 && content[13] == 18 && content[14] == 0 && content[15] == 1 && content[16] == 0 && content[17] == 1 && RECOIL_IsStringAt(content, 18, "PICT") && RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 28, 216);
}

static bool RECOIL_DecodeTre(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 13 || !RECOIL_IsStringAt(content, 0, "tre1"))
		return false;
	int width = content[4] << 8 | content[5];
	int height = content[6] << 8 | content[7];
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
		return false;
	Tre1Stream rle;
	Tre1Stream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 12;
	rle.base.base.base.contentLength = contentLength;
	int pixelsLength = width * height;
	for (int i = 0; i < pixelsLength; i++) {
		int rgb = RleStream_ReadRle(&rle.base);
		if (rgb < 0)
			return false;
		self->pixels[i] = rgb;
	}
	return true;
}

static bool RECOIL_IsRag(uint8_t const *content, int contentLength)
{
	return contentLength >= 55 && RECOIL_IsStringAt(content, 0, "RAG-D!") && content[6] == 0 && content[7] == 0 && content[16] == 0;
}

static bool RECOIL_DecodeRag(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (!RECOIL_IsRag(content, contentLength))
		return false;
	int width = content[12] << 8 | content[13];
	if ((width & 15) != 0)
		return false;
	int height = (content[14] << 8) + content[15] + 1;
	int bitplanes = content[17];
	int paletteLength = RECOIL_Get32BigEndian(content, 18);
	switch (bitplanes) {
	case 1:
	case 2:
	case 4:
	case 8:
		switch (paletteLength) {
		case 32:
			if (bitplanes > 4)
				return false;
			break;
		case 1024:
			break;
		default:
			return false;
		}
		int bytesPerLine = (width >> 3) * bitplanes;
		if (30 + paletteLength + height * bytesPerLine > contentLength || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		if (paletteLength == 32)
			RECOIL_SetStPalette(self, content, 30, 16, 0);
		else
			RECOIL_SetFalconPalette(self, content, 30, 256);
		RECOIL_DecodeBitplanes(self, content, 30 + paletteLength, bytesPerLine, bitplanes, 0, width, height);
		return true;
	case 16:
		return paletteLength == 1024 && contentLength >= 1054 + width * height * 2 && RECOIL_DecodeFalconTrueColor(self, content, 1054, width, height, RECOILResolution_FALCON1X1);
	default:
		return false;
	}
}

static bool RECOIL_DecodeRagc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (!RECOIL_IsRag(content, contentLength) || content[17] != 8 || RECOIL_Get32BigEndian(content, 18) != 1024)
		return false;
	int width = content[12] << 8 | content[13];
	int height = (content[14] << 8) + content[15] + 1;
	if (1054 + width * height > contentLength || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
		return false;
	RECOIL_SetFalconPalette(self, content, 30, 256);
	RECOIL_DecodeBytes(self, content, 1054);
	return true;
}

static bool RECOIL_DecodeFalconFun(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 14 || content[0] != 0 || content[1] != 10 || content[2] != 207 || content[3] != 226 || content[8] != 0)
		return false;
	int width = content[4] << 8 | content[5];
	if ((width & 15) != 0)
		return false;
	int height = content[6] << 8 | content[7];
	int bitplanes = content[9];
	switch (bitplanes) {
	case 1:
	case 2:
	case 4:
	case 8:
		;
		int bytesPerLine = (width >> 3) * bitplanes;
		int paletteOffset = 25 + height * bytesPerLine;
		int colors = 1 << bitplanes;
		if (contentLength != paletteOffset + colors * 6 || !RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, false))
			return false;
		if (bitplanes == 1)
			RECOIL_SetDefaultStPalette(self, 1);
		else
			RECOIL_SetStVdiPalette(self, content, paletteOffset, colors, bitplanes);
		RECOIL_DecodeScaledBitplanes(self, content, 13, width, height, bitplanes, false, NULL);
		return true;
	case 16:
		return contentLength >= 13 + width * height * 2 && RECOIL_DecodeFalconTrueColor(self, content, 13, width, height, RECOILResolution_FALCON1X1);
	default:
		return false;
	}
}

static bool RECOIL_DecodeEsm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 812 || content[0] != 'T' || content[1] != 'M' || content[2] != 'S' || content[3] != 0 || content[4] != 3 || content[5] != 44 || content[10] != 0)
		return false;
	int width = content[6] << 8 | content[7];
	int height = content[8] << 8 | content[9];
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
		return false;
	int pixelsLength = width * height;
	switch (content[11]) {
	case 1:
		return RECOIL_DecodeBlackAndWhite(self, content, 812, contentLength, false, 16777215);
	case 8:
		if (contentLength != 812 + pixelsLength)
			return false;
		for (int i = 0; i < 256; i++)
			self->contentPalette[i] = content[36 + i] << 16 | content[292 + i] << 8 | content[548 + i];
		for (int i = 0; i < pixelsLength; i++)
			self->pixels[i] = self->contentPalette[content[812 + i]];
		return true;
	case 24:
		if (contentLength != 812 + pixelsLength * 3)
			return false;
		RECOIL_DecodeR8G8B8Colors(content, 812, pixelsLength, self->pixels, 0);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeFalconPix(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 15 || !RECOIL_IsStringAt(content, 0, "PIXT") || content[4] != 0)
		return false;
	int contentOffset;
	switch (content[5]) {
	case 1:
		contentOffset = 14;
		break;
	case 2:
		contentOffset = 16;
		break;
	default:
		return false;
	}
	int width = content[8] << 8 | content[9];
	if ((width & 15) != 0)
		return false;
	int bitplanes = content[7];
	int height = content[10] << 8 | content[11];
	int pixelsLength;
	switch (bitplanes) {
	case 1:
		return content[6] == 1 && RECOIL_SetSizeStOrFalcon(self, width, height, 1, false) && RECOIL_DecodeBlackAndWhite(self, content, contentOffset, contentLength, true, 16777215);
	case 2:
	case 4:
		;
		int bitmapOffset = contentOffset + (3 << bitplanes);
		if (content[6] != 1 || contentLength != bitmapOffset + (width >> 3) * bitplanes * height || !RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, false))
			return false;
		RECOIL_DecodeR8G8B8Colors(content, contentOffset, 1 << bitplanes, self->contentPalette, 0);
		RECOIL_DecodeScaledBitplanes(self, content, bitmapOffset, width, height, bitplanes, false, NULL);
		return true;
	case 8:
		if (content[6] != 0 || contentLength != contentOffset + 768 + width * height || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		RECOIL_DecodeR8G8B8Colors(content, contentOffset, 256, self->contentPalette, 0);
		RECOIL_DecodeBytes(self, content, contentOffset + 768);
		return true;
	case 16:
		return content[6] == 1 && contentLength == contentOffset + width * height * 2 && RECOIL_DecodeFalconTrueColor(self, content, contentOffset, width, height, RECOILResolution_FALCON1X1);
	case 24:
		pixelsLength = width * height;
		if (content[6] != 1 || contentLength != contentOffset + pixelsLength * 3 || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		RECOIL_DecodeR8G8B8Colors(content, contentOffset, pixelsLength, self->pixels, 0);
		return true;
	case 32:
		pixelsLength = width * height;
		if (contentLength != contentOffset + (pixelsLength << 2) || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		RECOIL_DecodeR8G8G8X8Colors(self, content, contentOffset + 1, pixelsLength);
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodePntUnpacked(RECOIL *self, uint8_t const *content, uint8_t const *bitmap, int bitmapOffset, int width, int height)
{
	int bitplanes = content[13];
	switch (bitplanes) {
	case 1:
	case 2:
	case 4:
	case 8:
		if (!RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, false))
			return false;
		memset(self->contentPalette, 0, sizeof(self->contentPalette));
		RECOIL_SetStVdiPalette(self, content, 128, content[6] << 8 | content[7], bitplanes);
		RECOIL_DecodeScaledBitplanes(self, bitmap, bitmapOffset, width, height, bitplanes, false, NULL);
		return true;
	case 16:
		return RECOIL_DecodeFalconTrueColor(self, bitmap, bitmapOffset, width, height, RECOILResolution_FALCON1X1);
	case 24:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		for (int y = 0; y < height; y++) {
			RECOIL_DecodeR8G8B8Colors(bitmap, bitmapOffset, width, self->pixels, y * width);
			bitmapOffset += ((width + 15) & ~15) * 3;
		}
		return true;
	default:
		return false;
	}
}

static bool RECOIL_DecodeFalconPnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 128 || content[0] != 'P' || content[1] != 'N' || content[2] != 'T' || content[3] != 0 || content[4] != 1 || content[5] != 0 || content[12] != 0 || content[14] != 0)
		return false;
	int colors = content[6] << 8 | content[7];
	if (colors > 256)
		return false;
	int bitmapOffset = 128 + colors * 6;
	int bitmapLength = RECOIL_Get32BigEndian(content, 16);
	if (bitmapLength <= 0 || contentLength < bitmapOffset + bitmapLength)
		return false;
	int width = content[8] << 8 | content[9];
	int height = content[10] << 8 | content[11];
	if (width <= 0 || height > 134217728 / width)
		return false;
	int bitplanes = content[13];
	int unpackedLength = ((width + 15) >> 4 << 1) * height * bitplanes;
	switch (content[15]) {
	case 0:
		return bitmapLength == unpackedLength && RECOIL_DecodePntUnpacked(self, content, content, bitmapOffset, width, height);
	case 1:
		;
		uint8_t *unpacked = (uint8_t *) malloc(unpackedLength * sizeof(uint8_t));
		PackBitsStream rle;
		PackBitsStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = bitmapOffset;
		rle.base.base.base.contentLength = contentLength;
		bool returnValue = PackBitsStream_UnpackBitplaneLines(&rle, unpacked, width, height, bitplanes, true, false) && RECOIL_DecodePntUnpacked(self, content, unpacked, 0, width, height);
		free(unpacked);
		return returnValue;
	default:
		return false;
	}
}

static bool RECOIL_DecodeUimg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 15 || !RECOIL_IsStringAt(content, 0, "UIMG") || content[6] != 0)
		return false;
	int palette = content[7];
	if (palette > 3)
		return false;
	int depth = content[8];
	int chunk = content[9];
	int width = content[10] << 8 | content[11];
	int height = content[12] << 8 | content[13];
	static const uint8_t PALETTE_UNIT[4] = { 0, 2, 2, 4 };
	int bitmapOffset = 14 + (PALETTE_UNIT[palette] << depth);
	int pixelsLength = width * height;
	switch (chunk) {
	case 255:
	case 0:
		if (palette == 0 || depth > 8 || (width & 15) != 0 || contentLength != bitmapOffset + (pixelsLength >> 3) * depth)
			return false;
		break;
	case 1:
		if (palette == 0 || depth > 8 || contentLength != bitmapOffset + pixelsLength)
			return false;
		break;
	case 2:
	case 3:
	case 4:
		if (palette != 0 || depth != chunk << 3 || contentLength != 14 + pixelsLength * chunk)
			return false;
		break;
	default:
		return false;
	}
	switch (palette) {
	case 0:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		break;
	case 1:
		if (!RECOIL_SetSize(self, width, height, depth > 4 ? RECOILResolution_FALCON1X1 : RECOIL_IsStePalette(content, 14, 1 << depth) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1, 1))
			return false;
		memset(self->contentPalette, 0, sizeof(self->contentPalette));
		RECOIL_SetStPalette(self, content, 14, 1 << depth, 0);
		break;
	case 2:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_TT1X1, 1))
			return false;
		memset(self->contentPalette, 0, sizeof(self->contentPalette));
		RECOIL_SetStPalette(self, content, 14, 1 << depth, 0);
		break;
	case 3:
		if (!RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1, 1))
			return false;
		memset(self->contentPalette, 0, sizeof(self->contentPalette));
		RECOIL_SetFalconPalette(self, content, 14, 1 << depth);
		break;
	default:
		return false;
	}
	switch (chunk) {
	case 0:
		RECOIL_DecodeBitplanes(self, content, bitmapOffset, (width >> 3) * depth, depth, 0, width, height);
		return true;
	case 1:
		RECOIL_DecodeBytes(self, content, bitmapOffset);
		return true;
	case 2:
		for (int i = 0; i < pixelsLength; i++)
			self->pixels[i] = RECOIL_GetFalconTrueColor(content, 14 + (i << 1));
		return true;
	case 3:
		RECOIL_DecodeR8G8B8Colors(content, 14, pixelsLength, self->pixels, 0);
		return true;
	case 4:
		RECOIL_DecodeR8G8G8X8Colors(self, content, 15, pixelsLength);
		return true;
	case 255:
		switch (depth) {
		case 1:
			RECOIL_DecodeBitplanes(self, content, bitmapOffset, width >> 3, 1, 0, width, height);
			return true;
		case 2:
			RECOIL_DecodeMsx6(self, content, bitmapOffset);
			return true;
		case 4:
			RECOIL_DecodeNibbles(self, content, bitmapOffset, width >> 1);
			return true;
		default:
			return false;
		}
	default:
		abort();
	}
}

static void RECOIL_SetOcsColor(RECOIL *self, int c, int r, int gb)
{
	int rgb = (r & 15) << 16 | (gb & 240) << 4 | (gb & 15);
	self->contentPalette[c] = rgb * 17;
}

static void RECOIL_SetOcsPalette(RECOIL *self, uint8_t const *content, int contentOffset, int colors)
{
	for (int c = 0; c < colors; c++) {
		int r = content[contentOffset++];
		int gb = content[contentOffset++];
		RECOIL_SetOcsColor(self, c, r, gb);
	}
}

static bool RECOIL_DecodeInfo(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 98 || content[0] != 227 || content[1] != 16 || content[2] != 0 || content[3] != 1)
		return false;
	static const int OS1_PALETTE[4] = { 5614335, 16777215, 0, 16746496 };
	static const int OS2_PALETTE[8] = { 9803157, 0, 16777215, 3893154, 8092539, 11513775, 11178108, 16755095 };
	int const *palette;
	switch (RECOIL_Get32BigEndian(content, 44)) {
	case 0:
		palette = OS1_PALETTE;
		break;
	case 1:
		palette = OS2_PALETTE;
		break;
	default:
		return false;
	}
	int contentOffset = RECOIL_Get32BigEndian(content, 66) == 0 ? 78 : 134;
	int width = content[contentOffset + 4] << 8 | content[contentOffset + 5];
	int height = content[contentOffset + 6] << 8 | content[contentOffset + 7];
	int bitplanes = content[contentOffset + 8] << 8 | content[contentOffset + 9];
	switch (bitplanes) {
	case 2:
		break;
	case 3:
		if (palette == OS1_PALETTE)
			return false;
		break;
	default:
		return false;
	}
	int bytesPerLine = (width + 15) >> 4 << 1;
	int bitplaneLength = height * bytesPerLine;
	contentOffset += 20;
	return contentLength >= contentOffset + bitplanes * bitplaneLength && RECOIL_DecodeAmigaPlanar(self, content, contentOffset, width, height, RECOILResolution_AMIGA1X2, bitplanes, palette);
}

static bool RECOIL_DecodeAbkSprite(RECOIL *self, uint8_t const *content, int contentLength)
{
	int sprites = content[4] << 8 | content[5];
	int contentOffset = 6;
	int width = 0;
	int height = 0;
	for (int sprite = 0; sprite < sprites; sprite++) {
		if (contentOffset + 10 >= contentLength || content[contentOffset + 4] != 0)
			return false;
		int spriteWidth = (content[contentOffset] << 8 | content[contentOffset + 1]) << 4;
		int spriteHeight = content[contentOffset + 2] << 8 | content[contentOffset + 3];
		int bitplanes = content[contentOffset + 5];
		if (bitplanes == 0 || bitplanes > 5)
			return false;
		width += spriteWidth;
		if (height < spriteHeight)
			height = spriteHeight;
		if (width <= 0 || height > 134217728 / width)
			return false;
		contentOffset += 10 + (spriteWidth >> 3) * spriteHeight * bitplanes;
	}
	if (contentOffset + 64 != contentLength || !RECOIL_SetSize(self, width, height, RECOILResolution_AMIGA1X1, 1))
		return false;
	RECOIL_SetOcsPalette(self, content, contentOffset, 32);
	contentOffset = 6;
	int left = 0;
	for (int sprite = 0; sprite < sprites; sprite++) {
		int spriteWidth = (content[contentOffset] << 8 | content[contentOffset + 1]) << 4;
		int spriteHeight = content[contentOffset + 2] << 8 | content[contentOffset + 3];
		int bitplanes = content[contentOffset + 5];
		int bytesPerLine = spriteWidth >> 3;
		int bitplaneLength = height * bytesPerLine;
		for (int y = 0; y < spriteHeight; y++) {
			for (int x = 0; x < spriteWidth; x++)
				self->pixels[y * width + left + x] = self->contentPalette[RECOIL_GetBitplanePixel(content, contentOffset + 10 + y * bytesPerLine + (x >> 3), x, bitplanes, bitplaneLength)];
		}
		for (int y = spriteHeight; y < height; y++)
			memset(self->pixels + (y * width + left), 0, spriteWidth * sizeof(int));
		contentOffset += 10 + bitplanes * bitplaneLength;
		left += spriteWidth;
	}
	return true;
}

static bool RECOIL_DecodeAbk(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 82 || content[0] != 'A' || content[1] != 'm')
		return false;
	switch (content[2]) {
	case 'S':
		return content[3] == 'p' && RECOIL_DecodeAbkSprite(self, content, contentLength);
	case 'I':
		return content[3] == 'c' && RECOIL_DecodeAbkSprite(self, content, contentLength);
	case 'B':
		break;
	default:
		return false;
	}
	if (content[3] != 'k' || contentLength < 135 || !RECOIL_IsStringAt(content, 12, "Pac.Pic") || content[110] != 6 || content[111] != 7 || content[112] != 25 || content[113] != 99 || content[124] != 0)
		return false;
	int width = content[118] << 8 | content[119];
	if ((width & 1) != 0)
		return false;
	int lumps = content[120] << 8 | content[121];
	int lumpLines = content[122] << 8 | content[123];
	int height = lumps * lumpLines;
	int bitplanes = content[125];
	if (bitplanes == 0 || bitplanes > 5 || !RECOIL_SetSize(self, width << 3, height, RECOILResolution_AMIGA1X1, 1))
		return false;
	int rleOffset = 110 + RECOIL_Get32BigEndian(content, 126);
	if (rleOffset < 0 || rleOffset >= contentLength)
		return false;
	int pointsOffset = 110 + RECOIL_Get32BigEndian(content, 130);
	if (pointsOffset < 0)
		return false;
	uint8_t *unpacked = (uint8_t *) malloc(bitplanes * width * height * sizeof(uint8_t));
	int picOffset = 135;
	int pic = content[134];
	int rleBits = content[rleOffset++] << 8 | 128;
	int pointsBits = 0;
	for (int bitplane = 0; bitplane < bitplanes; bitplane++) {
		for (int lump = 0; lump < lumps; lump++) {
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < lumpLines; y++) {
					rleBits <<= 1;
					if ((rleBits & 255) == 0) {
						pointsBits <<= 1;
						if ((pointsBits & 255) == 0) {
							if (pointsOffset >= contentLength) {
								free(unpacked);
								return false;
							}
							pointsBits = content[pointsOffset++] << 1 | 1;
						}
						if ((pointsBits >> 8 & 1) != 0) {
							if (rleOffset >= contentLength) {
								free(unpacked);
								return false;
							}
							rleBits = content[rleOffset++] << 1 | 1;
						}
						else
							rleBits >>= 8;
					}
					if ((rleBits >> 8 & 1) != 0) {
						if (picOffset >= contentLength) {
							free(unpacked);
							return false;
						}
						pic = content[picOffset++];
					}
					unpacked[((bitplane * lumps + lump) * lumpLines + y) * width + x] = (uint8_t) pic;
				}
			}
		}
	}
	RECOIL_SetOcsPalette(self, content, 46, 32);
	bool returnValue = RECOIL_DecodeAmigaPlanar(self, unpacked, 0, width << 3, height, RECOILResolution_AMIGA1X1, bitplanes, self->contentPalette);
	free(unpacked);
	return returnValue;
}

static RECOILResolution RECOIL_GetAmigaAspectRatio(int xRatio, int yRatio, RECOILResolution resolution)
{
	if (xRatio <= 0 || yRatio <= 0)
		return resolution;
	if (xRatio > yRatio * 6)
		return RECOILResolution_AMIGA8X1;
	if (xRatio > yRatio * 3)
		return RECOILResolution_AMIGA4X1;
	if (xRatio * 2 > yRatio * 3)
		return RECOILResolution_AMIGA2X1;
	if (yRatio > xRatio * 3)
		return RECOILResolution_AMIGA1X4;
	if (yRatio * 2 > xRatio * 3)
		return resolution == RECOILResolution_AMIGA1X1 ? RECOILResolution_AMIGA1X2 : RECOILResolution_ST1X2;
	return resolution;
}

static RECOILResolution RECOIL_GetCamgAspectRatio(int camg, RECOILResolution resolution)
{
	int log;
	switch (camg & ~61439) {
	case 0:
	case 69632:
	case 135168:
	case 462848:
	case 790528:
	case 856064:
		camg &= 32812;
		log = 0;
		break;
	case 266240:
		return RECOILResolution_AMIGA1X1;
	case 331776:
	case 528384:
	case 724992:
	case 921600:
		camg &= 32812;
		log = -1;
		break;
	case 200704:
	case 397312:
		camg &= 32805;
		log = -1;
		break;
	case 593920:
	case 659456:
		camg &= 33285;
		log = 0;
		break;
	default:
		return resolution;
	}
	switch (camg & 33312) {
	case 0:
		break;
	case 32768:
		log++;
		break;
	case 32800:
		log += 2;
		break;
	case 512:
		log--;
		break;
	default:
		return resolution;
	}
	switch (camg & 13) {
	case 0:
		break;
	case 4:
		log--;
		break;
	case 5:
		log -= 2;
		break;
	case 8:
		log++;
		break;
	default:
		return resolution;
	}
	switch (log) {
	case 0:
		return RECOILResolution_AMIGA1X1;
	case -1:
		return RECOILResolution_AMIGA2X1;
	case -2:
		return RECOILResolution_AMIGA4X1;
	case -3:
		return RECOILResolution_AMIGA8X1;
	case 1:
		return RECOILResolution_AMIGA1X2;
	case 2:
		return RECOILResolution_AMIGA1X4;
	default:
		return resolution;
	}
}

static bool RECOIL_DecodeDeep(RECOIL *self, uint8_t const *content, int contentLength)
{
	int width = 0;
	int height = 0;
	int compression = 0;
	RECOILResolution resolution = RECOILResolution_AMIGA1X1;
	DeepStream rle;
	DeepStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	int tvdcOffset = -1;
	for (int contentOffset = 12; contentOffset < contentLength - 7;) {
		int chunkLength = RECOIL_Get32BigEndian(content, contentOffset + 4);
		int chunkEndOffset = contentOffset + 8 + chunkLength;
		if (chunkEndOffset > contentLength || chunkEndOffset < contentOffset + 8)
			break;
		if (RECOIL_IsStringAt(content, contentOffset, "DGBL")) {
			if (chunkLength < 8 || content[contentOffset + 12] != 0) {
				DeepStream_Destruct(&rle);
				return false;
			}
			width = content[contentOffset + 8] << 8 | content[contentOffset + 9];
			height = content[contentOffset + 10] << 8 | content[contentOffset + 11];
			compression = content[contentOffset + 13];
			resolution = RECOIL_GetAmigaAspectRatio(content[contentOffset + 14], content[contentOffset + 15], resolution);
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "DPEL")) {
			if (!DeepStream_SetDpel(&rle, contentOffset, chunkLength)) {
				DeepStream_Destruct(&rle);
				return false;
			}
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "DLOC")) {
			if (chunkLength < 4) {
				DeepStream_Destruct(&rle);
				return false;
			}
			width = content[contentOffset + 8] << 8 | content[contentOffset + 9];
			height = content[contentOffset + 10] << 8 | content[contentOffset + 11];
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "TVDC")) {
			if (chunkLength != 32) {
				DeepStream_Destruct(&rle);
				return false;
			}
			tvdcOffset = contentOffset + 8;
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "DBOD")) {
			if (chunkEndOffset + 8 < contentLength && RECOIL_IsStringAt(content, chunkEndOffset, "DBOD")) {
				DeepStream_Destruct(&rle);
				return false;
			}
			if (rle.components <= 0 || !RECOIL_SetScaledSize(self, width, height, resolution)) {
				DeepStream_Destruct(&rle);
				return false;
			}
			rle.base.base.base.base.contentOffset = contentOffset + 8;
			rle.base.base.base.base.contentLength = chunkEndOffset;
			for (int y = 0; y < height; y++) {
				if (compression == 5) {
					if (tvdcOffset < 0 || !DeepStream_ReadDeltaLine(&rle, width, tvdcOffset)) {
						DeepStream_Destruct(&rle);
						return false;
					}
				}
				for (int x = 0; x < width; x++) {
					int rgb;
					switch (compression) {
					case 0:
						rgb = ((const RleStreamVtbl *) rle.base.base.base.vtbl)->readValue(&rle.base.base);
						break;
					case 1:
						rgb = RleStream_ReadRle(&rle.base.base);
						break;
					case 5:
						rgb = rle.line[x];
						break;
					default:
						DeepStream_Destruct(&rle);
						return false;
					}
					if (rgb < 0) {
						DeepStream_Destruct(&rle);
						return false;
					}
					RECOIL_SetScaledPixel(self, x, y, rgb);
				}
			}
			DeepStream_Destruct(&rle);
			return true;
		}
		contentOffset = (chunkEndOffset + 1) & ~1;
	}
	DeepStream_Destruct(&rle);
	return false;
}

static bool RECOIL_DecodeRgbn(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int width, int height, bool rgb8)
{
	int rgb = 0;
	int count = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (count == 0) {
				if (rgb8) {
					if (contentOffset > contentLength - 4)
						return false;
					rgb = RECOIL_GetR8G8B8Color(content, contentOffset);
					count = content[contentOffset + 3] & 127;
					contentOffset += 4;
				}
				else {
					if (contentOffset > contentLength - 2)
						return false;
					rgb = content[contentOffset];
					count = content[contentOffset + 1];
					rgb = (((rgb & 240) << 4 | (rgb & 15)) << 8 | count >> 4) * 17;
					count &= 7;
					contentOffset += 2;
				}
				if (count == 0) {
					if (contentOffset >= contentLength)
						return false;
					count = content[contentOffset++];
					if (count == 0) {
						if (contentOffset > contentLength - 2)
							return false;
						count = content[contentOffset] << 8 | content[contentOffset + 1];
						contentOffset += 2;
					}
				}
			}
			RECOIL_SetScaledPixel(self, x, y, rgb);
			count--;
		}
	}
	return true;
}

static bool RECOIL_DecodeRast(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, uint8_t const *unpacked, int width, int height, int bitplanes)
{
	if (!RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes, false))
		return false;
	RastPalette rast;
	RastPalette_Construct(&rast);
	rast.base.base.base.content = content;
	rast.base.base.base.contentOffset = contentOffset + 8;
	rast.base.base.base.contentLength = contentLength;
	rast.colors = 1 << bitplanes;
	RECOIL_DecodeScaledBitplanes(self, unpacked, 0, width, height, bitplanes, false, &rast.base);
	return true;
}

static void RECOIL_DecodeHam(RECOIL *self, uint8_t const *unpacked, int width, int height, int bitplanes, MultiPalette *multiPalette)
{
	int bytesPerLine = ((width + 15) >> 4 << 1) * bitplanes;
	int holdBits = bitplanes > 6 ? 6 : 4;
	for (int y = 0; y < height; y++) {
		if (multiPalette != NULL)
			((const MultiPaletteVtbl *) multiPalette->base.vtbl)->setLinePalette(multiPalette, self, y);
		int rgb = self->contentPalette[0];
		for (int x = 0; x < width; x++) {
			int c = RECOIL_GetBitplaneWordsPixel(unpacked, y * bytesPerLine, x, bitplanes);
			switch (c >> holdBits) {
			case 0:
				rgb = self->contentPalette[c];
				break;
			case 1:
				c = c << (8 - holdBits) & 255;
				c |= c >> holdBits;
				rgb = (rgb & 16776960) | c;
				break;
			case 2:
				c = c << (8 - holdBits) & 255;
				c |= c >> holdBits;
				rgb = (rgb & 65535) | c << 16;
				break;
			case 3:
				c = c << (8 - holdBits) & 255;
				c |= c >> holdBits;
				rgb = (rgb & 16711935) | c << 8;
				break;
			default:
				abort();
			}
			RECOIL_SetScaledPixel(self, x, y, rgb);
		}
	}
}

static int RECOIL_GetHameNibble(const RECOIL *self, uint8_t const *content, int contentOffset, int x)
{
	int c = RECOIL_GetStLowPixel(content, contentOffset, x);
	int rgb = self->contentPalette[c];
	return (rgb >> 20 & 8) | (rgb >> 13 & 4) | (rgb >> 6 & 2) | (rgb >> 4 & 1);
}

static int RECOIL_GetHameByte(const RECOIL *self, uint8_t const *content, int contentOffset, int x)
{
	return RECOIL_GetHameNibble(self, content, contentOffset, x << 1) << 4 | RECOIL_GetHameNibble(self, content, contentOffset, (x << 1) + 1);
}

static bool RECOIL_IsHame(const RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 7; i++) {
		static const uint8_t MAGIC[7] = { 162, 245, 132, 220, 109, 176, 127 };
		if (RECOIL_GetHameByte(self, content, contentOffset, i) != MAGIC[i])
			return false;
	}
	switch (RECOIL_GetHameByte(self, content, contentOffset, 7)) {
	case 20:
	case 24:
		return true;
	default:
		return false;
	}
}

static void RECOIL_DecodeHame(RECOIL *self, uint8_t const *content, int width)
{
	int palette[512] = { 0 };
	int paletteLength[2] = { 0 };
	bool hame = false;
	for (int y = 0; y < self->height; y++) {
		int lineOffset = y * width;
		int paletteOffset = self->resolution == RECOILResolution_AMIGA_HAME2X1 && (y & 1) != 0 ? 256 : 0;
		if (RECOIL_IsHame(self, content, lineOffset)) {
			paletteOffset += paletteLength[paletteOffset >> 8];
			for (int c = 0; c < 64; c++) {
				int offset = 8 + c * 3;
				palette[paletteOffset + c] = RECOIL_GetHameByte(self, content, lineOffset, offset) << 16 | RECOIL_GetHameByte(self, content, lineOffset, offset + 1) << 8 | RECOIL_GetHameByte(self, content, lineOffset, offset + 2);
			}
			paletteLength[paletteOffset >> 8] = (paletteLength[paletteOffset >> 8] + 64) & 255;
			hame = RECOIL_GetHameByte(self, content, lineOffset, 7) == 24;
			memset(self->pixels + y * self->width, 0, self->width * sizeof(int));
		}
		else {
			int paletteBank = 0;
			int rgb = 0;
			for (int x = 0; x < width; x++) {
				int c = RECOIL_GetHameByte(self, content, lineOffset, x);
				if (hame) {
					switch (c >> 6) {
					case 0:
						if (c < 60)
							rgb = palette[paletteOffset + paletteBank + c];
						else
							paletteBank = (c - 60) << 6;
						break;
					case 1:
						rgb = (c & 63) << 2 | (rgb & 16776960);
						break;
					case 2:
						rgb = (c & 63) << 18 | (rgb & 65535);
						break;
					default:
						rgb = (c & 63) << 10 | (rgb & 16711935);
						break;
					}
				}
				else
					rgb = palette[paletteOffset + c];
				RECOIL_SetScaledPixel(self, x, y, rgb);
			}
		}
	}
}

static int RECOIL_GetDctvValue(const RECOIL *self, uint8_t const *content, int contentOffset, int x, int bitplanes)
{
	int c = RECOIL_GetBitplaneWordsPixel(content, contentOffset, x, bitplanes);
	int rgb = self->contentPalette[c];
	return (rgb << 2 & 64) | (rgb >> 19 & 16) | (rgb >> 5 & 4) | (rgb >> 15 & 1);
}

static bool RECOIL_IsDctv(const RECOIL *self, uint8_t const *content, int contentOffset, int bitplanes)
{
	if (RECOIL_GetDctvValue(self, content, contentOffset, 0, bitplanes) >> 6 != 0)
		return false;
	int r = 125;
	for (int x = 1; x < 256; x++) {
		if (RECOIL_GetDctvValue(self, content, contentOffset, x, bitplanes) >> 6 == (r & 1))
			return false;
		if ((r & 1) != 0)
			r ^= 390;
		r >>= 1;
	}
	return true;
}

static int RECOIL_ClampByte(int x)
{
	return x <= 0 ? 0 : x >= 255 ? 255 : x;
}

static bool RECOIL_DecodeDctv(RECOIL *self, uint8_t const *content, int width, int height, RECOILResolution resolution, int bitplanes)
{
	if (!RECOIL_IsDctv(self, content, 0, bitplanes))
		return false;
	int interlace;
	int bytesPerLine = ((width + 15) >> 4 << 1) * bitplanes;
	if (resolution == RECOILResolution_AMIGA1X2) {
		interlace = 0;
		height--;
		resolution = RECOILResolution_AMIGA_DCTV1X2;
	}
	else {
		if (!RECOIL_IsDctv(self, content, bytesPerLine, bitplanes))
			return false;
		interlace = 1;
		height -= 2;
		resolution = RECOILResolution_AMIGA_DCTV1X1;
	}
	RECOIL_SetScaledSize(self, width, height, resolution);
	int contentOffset = bytesPerLine << interlace;
	int chroma[2048];
	for (int y = 0; y < height; y++) {
		int odd = y >> interlace & 1;
		int rgb = 0;
		int o = 0;
		int p = 0;
		for (int x = 0; x < width; x++) {
			if ((x & 1) == odd) {
				int n = x + 1 < width ? RECOIL_GetDctvValue(self, content, contentOffset, x, bitplanes) << 1 | RECOIL_GetDctvValue(self, content, contentOffset, x + 1, bitplanes) : 0;
				int i = (o + n) >> 1;
				i = i <= 64 ? 0 : i >= 224 ? 255 : (i - 64) * 8 / 5;
				int u = n + p - (o << 1);
				if (u < 0)
					u += 3;
				u >>= 2;
				if (((x + 1) & 2) == 0)
					u = -u;
				int chromaOffset = (x & ~1) | (y & interlace);
				int v = y > interlace ? chroma[chromaOffset] : 0;
				chroma[chromaOffset] = u;
				if (odd == 0) {
					u = v;
					v = chroma[chromaOffset];
				}
				p = o;
				o = n;
				int r = i + v * 4655 / 2560;
				int b = i + u * 8286 / 2560;
				int g = i - (v * 2372 + u * 1616) / 2560;
				rgb = RECOIL_ClampByte(r) << 16 | RECOIL_ClampByte(g) << 8 | RECOIL_ClampByte(b);
			}
			RECOIL_SetScaledPixel(self, x, y, rgb);
		}
		contentOffset += bytesPerLine;
	}
	return true;
}

static bool RECOIL_DecodeIffUnpacked(RECOIL *self, uint8_t const *unpacked, int width, int height, RECOILResolution resolution, int bitplanes, int colors, int camg, MultiPalette *multiPalette)
{
	if (!RECOIL_SetScaledSize(self, width, height, resolution))
		return false;
	if (bitplanes <= 8) {
		if (colors == 0) {
			colors = 1 << bitplanes;
			for (int c = 0; c < colors; c++)
				self->contentPalette[c] = c * 255 / colors * 65793;
		}
		if ((camg & 2048) != 0 || (bitplanes == 6 && colors == 16)) {
			RECOIL_DecodeHam(self, unpacked, width, height, bitplanes, multiPalette);
		}
		else if (width >= 400 && (resolution == RECOILResolution_AMIGA1X2 || resolution == RECOILResolution_AMIGA1X1) && bitplanes == 4 && multiPalette == NULL && RECOIL_IsHame(self, unpacked, 0)) {
			if (resolution == RECOILResolution_AMIGA1X2)
				RECOIL_SetSize(self, width >> 1, height, RECOILResolution_AMIGA_HAME1X1, 1);
			else
				RECOIL_SetSize(self, width, height, RECOILResolution_AMIGA_HAME2X1, 1);
			RECOIL_DecodeHame(self, unpacked, width >> 1);
		}
		else if (width >= 256 && width <= 2048 && height >= 3 && (resolution == RECOILResolution_AMIGA1X2 || resolution == RECOILResolution_AMIGA1X1) && multiPalette == NULL && RECOIL_DecodeDctv(self, unpacked, width, height, resolution, bitplanes)) {
		}
		else {
			RECOIL_DecodeScaledBitplanes(self, unpacked, 0, width, height, bitplanes, bitplanes == 6 && ((camg & 128) != 0 || colors == 32), multiPalette);
		}
	}
	else {
		int bytesPerBitplane = (width + 15) >> 4 << 1;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int offset = (y * bytesPerBitplane + (x >> 3 & ~1)) * bitplanes + (x >> 3 & 1);
				int c = RECOIL_GetBitplanePixel(unpacked, offset, x, 24, 2);
				RECOIL_SetScaledPixel(self, x, y, (c & 255) << 16 | (c & 65280) | c >> 16);
			}
		}
	}
	return true;
}

static bool RECOIL_DecodeIff(RECOIL *self, uint8_t const *content, int contentLength, RECOILResolution resolution)
{
	if (contentLength < 56 || !RECOIL_IsStringAt(content, 0, "FORM"))
		return false;
	if (RECOIL_IsStringAt(content, 8, "DEEP") || RECOIL_IsStringAt(content, 8, "TVPP"))
		return RECOIL_DecodeDeep(self, content, contentLength);
	int contentOffset = 8;
	if (RECOIL_IsStringAt(content, 8, "DPSTDPAH") && RECOIL_Get32BigEndian(content, 16) == 24 && RECOIL_IsStringAt(content, 44, "FORM"))
		contentOffset = 52;
	else if (RECOIL_IsStringAt(content, 8, "ANIMFORM"))
		contentOffset = 20;
	IffType type;
	if (RECOIL_IsStringAt(content, contentOffset, "ILBM"))
		type = IffType_ILBM;
	else if (RECOIL_IsStringAt(content, contentOffset, "PBM "))
		type = IffType_PBM;
	else if (RECOIL_IsStringAt(content, contentOffset, "ACBM"))
		type = IffType_ACBM;
	else if (RECOIL_IsStringAt(content, contentOffset, "RGB8"))
		type = IffType_RGB8;
	else if (RECOIL_IsStringAt(content, contentOffset, "RGBN"))
		type = IffType_RGBN;
	else
		return false;
	contentOffset += 4;
	int width = 0;
	int height = 0;
	int bitplanes = 0;
	bool hasMask = false;
	int compression = 0;
	bool ocsPalette = false;
	int colors = 0;
	int camg = 0;
	CtblPalette ctbl;
	CtblPalette_Construct(&ctbl);
	ShamLacePalette sham;
	ShamLacePalette_Construct(&sham);
	PchgPalette pchg;
	PchgPalette_Construct(&pchg);
	MultiPalette *multiPalette = NULL;
	while (contentOffset < contentLength - 7) {
		int chunkLength = RECOIL_Get32BigEndian(content, contentOffset + 4);
		int chunkEndOffset = contentOffset + 8 + chunkLength;
		if (chunkEndOffset > contentLength || chunkEndOffset < contentOffset + 8) {
			chunkEndOffset = contentLength;
			chunkLength = contentLength - contentOffset - 8;
		}
		if (RECOIL_IsStringAt(content, contentOffset, "BMHD") && chunkLength >= 16) {
			width = content[contentOffset + 8] << 8 | content[contentOffset + 9];
			height = content[contentOffset + 10] << 8 | content[contentOffset + 11];
			bitplanes = content[contentOffset + 16];
			hasMask = content[contentOffset + 17] == 1;
			compression = content[contentOffset + 18];
			switch (type) {
			case IffType_PBM:
				if (bitplanes != 8 || compression > 1) {
					PchgPalette_Destruct(&pchg);
					return false;
				}
				break;
			case IffType_RGB8:
				if (bitplanes != 25 || compression != 4) {
					PchgPalette_Destruct(&pchg);
					return false;
				}
				break;
			case IffType_RGBN:
				if (bitplanes != 13 || compression != 4) {
					PchgPalette_Destruct(&pchg);
					return false;
				}
				break;
			default:
				if (bitplanes == 0 || (bitplanes > 8 && bitplanes != 24 && bitplanes != 32) || compression > 2) {
					PchgPalette_Destruct(&pchg);
					return false;
				}
				break;
			}
			int pixelsCount = width * height;
			if (pixelsCount <= 0 || pixelsCount > 134217728) {
				PchgPalette_Destruct(&pchg);
				return false;
			}
			ocsPalette = content[contentOffset + 19] != 128;
			resolution = RECOIL_GetAmigaAspectRatio(content[contentOffset + 22], content[contentOffset + 23], resolution);
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "CMAP")) {
			colors = chunkLength / 3;
			if (colors > 256) {
				PchgPalette_Destruct(&pchg);
				return false;
			}
			if (colors > 32)
				ocsPalette = false;
			for (int c = 0; c < colors; c++) {
				self->contentPalette[c] = RECOIL_GetR8G8B8Color(content, contentOffset + 8 + c * 3);
				if ((self->contentPalette[c] & 986895) != 0)
					ocsPalette = false;
			}
			if (ocsPalette) {
				for (int c = 0; c < colors; c++)
					self->contentPalette[c] |= self->contentPalette[c] >> 4;
			}
			memset(self->contentPalette + colors, 0, (256 - colors) * sizeof(int));
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "CAMG") && chunkLength >= 4) {
			camg = RECOIL_Get32BigEndian(content, contentOffset + 8);
			resolution = RECOIL_GetCamgAspectRatio(camg, resolution);
		}
		else if ((RECOIL_IsStringAt(content, contentOffset, "CTBL") || RECOIL_IsStringAt(content, contentOffset, "BEAM")) && height > 0) {
			ctbl.colors = (chunkLength >> 1) / height;
			if (ctbl.colors <= 32) {
				ctbl.base.base.base.content = content;
				ctbl.base.base.base.contentOffset = contentOffset + 8;
				multiPalette = &ctbl.base;
			}
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "SHAM") && chunkLength >= 2 && content[contentOffset + 8] == 0 && content[contentOffset + 9] == 0) {
			if (chunkLength == 2 + (height << 5)) {
				ctbl.base.base.base.content = content;
				ctbl.base.base.base.contentOffset = contentOffset + 10;
				ctbl.colors = 16;
				multiPalette = &ctbl.base;
			}
			else if (chunkLength == 2 + (height >> 1 << 5)) {
				sham.base.base.base.content = content;
				sham.base.base.base.contentOffset = contentOffset + 10;
				multiPalette = &sham.base;
			}
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "PCHG")) {
			pchg.base.base.base.content = content;
			pchg.base.base.base.contentOffset = contentOffset + 8;
			pchg.base.base.base.contentLength = chunkEndOffset;
			if (!PchgPalette_Init(&pchg)) {
				PchgPalette_Destruct(&pchg);
				return false;
			}
			multiPalette = &pchg.base;
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "BODY")) {
			if (width == 0) {
				PchgPalette_Destruct(&pchg);
				return false;
			}
			if (compression == 4) {
				bool returnValue = RECOIL_SetScaledSize(self, width, height, resolution) && RECOIL_DecodeRgbn(self, content, contentOffset + 8, chunkEndOffset, width, height, type == IffType_RGB8);
				PchgPalette_Destruct(&pchg);
				return returnValue;
			}
			int bytesPerLine = ((width + 15) >> 4 << 1) * bitplanes;
			uint8_t *unpacked = NULL;
			if (compression == 2) {
				free(unpacked);
				unpacked = (uint8_t *) malloc(bytesPerLine * height * sizeof(uint8_t));
				VdatStream rle;
				VdatStream_Construct(&rle);
				rle.base.base.base.base.base.content = content;
				rle.base.base.base.base.base.contentOffset = contentOffset + 8;
				for (int bitplane = 0; bitplane < bitplanes; bitplane++) {
					if (rle.base.base.base.base.base.contentOffset + 14 > chunkEndOffset || !RECOIL_IsStringAt(content, rle.base.base.base.base.base.contentOffset, "VDAT")) {
						free(unpacked);
						PchgPalette_Destruct(&pchg);
						return false;
					}
					int nextContentOffset = rle.base.base.base.base.base.contentOffset + 8 + RECOIL_Get32BigEndian(content, rle.base.base.base.base.base.contentOffset + 4);
					if (nextContentOffset > chunkEndOffset) {
						free(unpacked);
						PchgPalette_Destruct(&pchg);
						return false;
					}
					rle.base.valueOffset = rle.base.base.base.base.base.contentLength = rle.base.base.base.base.base.contentOffset + 8 + (content[rle.base.base.base.base.base.contentOffset + 8] << 8) + content[rle.base.base.base.base.base.contentOffset + 9];
					rle.base.valueLength = nextContentOffset;
					rle.base.base.base.base.base.contentOffset += 10;
					for (int x = bitplane << 1; x < bytesPerLine; x += bitplanes << 1) {
						int unpackedOffset = x;
						for (int y = 0; y < height; y++) {
							int b = RleStream_ReadRle(&rle.base.base.base);
							if (b < 0) {
								free(unpacked);
								PchgPalette_Destruct(&pchg);
								return false;
							}
							unpacked[unpackedOffset] = (uint8_t) (b >> 8);
							unpacked[unpackedOffset + 1] = (uint8_t) b;
							unpackedOffset += bytesPerLine;
						}
					}
					rle.base.base.base.base.base.contentOffset = nextContentOffset;
				}
				resolution = resolution == RECOILResolution_AMIGA1X2 ? RECOILResolution_ST1X2 : RECOILResolution_ST1X1;
			}
			else {
				PackBitsStream rle;
				PackBitsStream_Construct(&rle);
				rle.base.base.base.content = content;
				rle.base.base.base.contentOffset = contentOffset + 8;
				rle.base.base.base.contentLength = chunkEndOffset;
				if (type == IffType_PBM) {
					if (colors == 0 || !RECOIL_SetScaledSize(self, width, height, resolution)) {
						free(unpacked);
						PchgPalette_Destruct(&pchg);
						return false;
					}
					for (int y = 0; y < height; y++) {
						for (int x = 0; x < width; x++) {
							int b = compression == 0 ? Stream_ReadByte(&rle.base.base.base) : RleStream_ReadRle(&rle.base);
							if (b < 0) {
								free(unpacked);
								PchgPalette_Destruct(&pchg);
								return false;
							}
							RECOIL_SetScaledPixel(self, x, y, self->contentPalette[b]);
						}
						if ((width & 1) != 0 && (compression == 0 ? Stream_ReadByte(&rle.base.base.base) : RleStream_ReadRle(&rle.base)) < 0) {
							free(unpacked);
							PchgPalette_Destruct(&pchg);
							return false;
						}
					}
					free(unpacked);
					PchgPalette_Destruct(&pchg);
					return true;
				}
				free(unpacked);
				unpacked = (uint8_t *) malloc(bytesPerLine * height * sizeof(uint8_t));
				if (!PackBitsStream_UnpackBitplaneLines(&rle, unpacked, width, height, bitplanes, compression == 1, hasMask)) {
					free(unpacked);
					PchgPalette_Destruct(&pchg);
					return false;
				}
			}
			if (bitplanes <= 8 && chunkEndOffset < contentLength - 8) {
				int nextChunkOffset = (chunkEndOffset + 1) & ~1;
				if (RECOIL_IsStringAt(content, nextChunkOffset, "RAST")) {
					bool returnValue = RECOIL_DecodeRast(self, content, nextChunkOffset, contentLength, unpacked, width, height, bitplanes);
					free(unpacked);
					PchgPalette_Destruct(&pchg);
					return returnValue;
				}
				if (RECOIL_IsStringAt(content, chunkEndOffset, "RAST")) {
					bool returnValue = RECOIL_DecodeRast(self, content, chunkEndOffset, contentLength, unpacked, width, height, bitplanes);
					free(unpacked);
					PchgPalette_Destruct(&pchg);
					return returnValue;
				}
			}
			bool returnValue = RECOIL_DecodeIffUnpacked(self, unpacked, width, height, resolution, bitplanes, colors, camg, multiPalette);
			free(unpacked);
			PchgPalette_Destruct(&pchg);
			return returnValue;
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "ABIT")) {
			if (width == 0 || chunkLength != ((width + 15) >> 4 << 1) * height * bitplanes) {
				PchgPalette_Destruct(&pchg);
				return false;
			}
			contentOffset += 8;
			uint8_t *unpacked = (uint8_t *) malloc(chunkLength * sizeof(uint8_t));
			for (int bitplane = 0; bitplane < bitplanes; bitplane++) {
				for (int unpackedOffset = bitplane << 1; unpackedOffset < chunkLength; unpackedOffset += bitplanes << 1) {
					unpacked[unpackedOffset] = content[contentOffset++];
					unpacked[unpackedOffset + 1] = content[contentOffset++];
				}
			}
			bool returnValue = RECOIL_DecodeIffUnpacked(self, unpacked, width, height, resolution, bitplanes, colors, camg, multiPalette);
			free(unpacked);
			PchgPalette_Destruct(&pchg);
			return returnValue;
		}
		contentOffset = (chunkEndOffset + 1) & ~1;
	}
	PchgPalette_Destruct(&pchg);
	return false;
}

static int RECOIL_ParseAtari8ExecutableHeader(uint8_t const *content, int contentOffset)
{
	if (content[contentOffset] != 255 || content[contentOffset + 1] != 255)
		return -1;
	int startAddress = content[contentOffset + 2] | content[contentOffset + 3] << 8;
	int endAddress = content[contentOffset + 4] | content[contentOffset + 5] << 8;
	return endAddress - startAddress + 1;
}

static int RECOIL_GetAtari8ExecutableOffset(uint8_t const *content, int contentLength)
{
	if (contentLength >= 7) {
		int blockLength = RECOIL_ParseAtari8ExecutableHeader(content, 0);
		if (blockLength > 0 && 6 + blockLength == contentLength)
			return 6;
	}
	return 0;
}

static bool RECOIL_SetAtari8RawSize(RECOIL *self, uint8_t const *content, int contentLength, RECOILResolution resolution)
{
	int contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	int height = (contentLength - contentOffset) / 40;
	if (height == 0 || height > 240)
		return false;
	RECOIL_SetSize(self, 320, height, resolution, 1);
	return true;
}

static void RECOIL_SetGtiaColor(RECOIL *self, int reg, int value)
{
	value &= 254;
	switch (reg) {
	case 0:
	case 1:
	case 2:
	case 3:
		self->gtiaColors[reg] = (uint8_t) value;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		self->gtiaColors[8 + reg] = self->gtiaColors[reg] = (uint8_t) value;
		break;
	case 8:
		self->gtiaColors[11] = self->gtiaColors[10] = self->gtiaColors[9] = self->gtiaColors[8] = (uint8_t) value;
		break;
	default:
		abort();
	}
}

static void RECOIL_SetPM123PF0123Bak(RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 8; i++)
		RECOIL_SetGtiaColor(self, 1 + i, content[contentOffset + i]);
}

static void RECOIL_SetGtiaColors(RECOIL *self, uint8_t const *content, int contentOffset)
{
	self->gtiaColors[0] = (uint8_t) (content[contentOffset] & 254);
	RECOIL_SetPM123PF0123Bak(self, content, contentOffset + 1);
}

static void RECOIL_SetPF21(RECOIL *self, uint8_t const *content, int contentOffset)
{
	self->gtiaColors[6] = (uint8_t) (content[contentOffset] & 254);
	self->gtiaColors[5] = (uint8_t) (content[contentOffset + 1] & 254);
}

static void RECOIL_SetXeOsDefaultColors(RECOIL *self)
{
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 40;
	self->gtiaColors[5] = 202;
	self->gtiaColors[6] = 148;
	self->gtiaColors[7] = 70;
}

static void RECOIL_SetGr15DefaultColors(RECOIL *self)
{
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 4;
	self->gtiaColors[5] = 8;
	self->gtiaColors[6] = 12;
}

static void RECOIL_SetBakPF012(RECOIL *self, uint8_t const *content, int contentOffset, int contentStride)
{
	for (int i = 0; i < 4; i++)
		self->gtiaColors[i == 0 ? 8 : 3 + i] = (uint8_t) (content[contentOffset + i * contentStride] & 254);
}

static void RECOIL_SetBakPF0123(RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 5; i++)
		self->gtiaColors[i == 0 ? 8 : 3 + i] = (uint8_t) (content[contentOffset + i] & 254);
}

static void RECOIL_SetPF012Bak(RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 4; i++)
		self->gtiaColors[i == 3 ? 8 : 4 + i] = (uint8_t) (content[contentOffset + i] & 254);
}

static void RECOIL_SetPF0123Bak(RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 5; i++)
		self->gtiaColors[4 + i] = (uint8_t) (content[contentOffset + i] & 254);
}

static void RECOIL_SetPF0123Even(RECOIL *self, uint8_t const *content, int contentOffset)
{
	for (int i = 0; i < 4; i++)
		self->gtiaColors[4 + i] = (uint8_t) (content[contentOffset + i * 2] & 254);
}

static void RECOIL_DecodeAtari8Gr8(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int height)
{
	uint8_t colors[2];
	colors[0] = self->gtiaColors[6];
	colors[1] = (uint8_t) ((self->gtiaColors[6] & 240) | (self->gtiaColors[5] & 14));
	frameOffset -= self->leftSkip;
	for (int y = 0; y < height; y++) {
		int x;
		for (x = self->leftSkip; x < self->width; x++) {
			int c = content[contentOffset + (x >> 3)] >> (~x & 7) & 1;
			frame[frameOffset + x] = colors[c];
		}
		for (; x < self->width + self->leftSkip; x++)
			frame[frameOffset + x] = self->gtiaColors[8];
		contentOffset += (self->width + 7) >> 3;
		frameOffset += self->width;
	}
}

static void RECOIL_DecodeAtari8Gr15(const RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, uint8_t *frame, int frameOffset, int frameStride, int height)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < self->width; x++) {
			int c = content[contentOffset + (x >> 3)] >> (~x & 6) & 3;
			frame[frameOffset + x] = self->gtiaColors[c == 0 ? 8 : c + 3];
		}
		contentOffset += contentStride;
		frameOffset += frameStride;
	}
}

static void RECOIL_DecodeAtari8Gr7(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int height)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < self->width; x++) {
			int c = content[contentOffset + (x >> 3)] >> (~x & 6) & 3;
			frame[frameOffset + x + self->width] = frame[frameOffset + x] = self->gtiaColors[c == 0 ? 8 : c + 3];
		}
		contentOffset += self->width >> 3;
		frameOffset += self->width << 1;
	}
}

static void RECOIL_DecodeAtari8Gr3(const RECOIL *self, uint8_t const *content, uint8_t *frame)
{
	for (int y = 0; y < self->height; y++) {
		for (int x = 0; x < self->width; x++) {
			int c = content[(y >> 3) * (self->width >> 5) + (x >> 5)] >> (~(x >> 2) & 6) & 3;
			frame[y * self->width + x] = self->gtiaColors[c == 0 ? 8 : c + 3];
		}
	}
}

static void RECOIL_DecodeAtari8Gr9(const RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, uint8_t *frame, int frameOffset, int frameStride, int width, int height)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int i = x + self->leftSkip;
			int c = i < 0 || i >= width ? 0 : content[contentOffset + (i >> 3)] >> (~i & 4) & 15;
			frame[frameOffset + x] = (uint8_t) (self->gtiaColors[8] | c);
		}
		contentOffset += contentStride;
		frameOffset += frameStride;
	}
}

static void RECOIL_DecodeAtari8Gr11(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int frameStride, int height)
{
	frameOffset -= self->leftSkip;
	for (int y = 0; y < height; y++) {
		int x;
		for (x = self->leftSkip; x < self->width; x++) {
			int c = content[contentOffset + (x >> 3)] << (x & 4) & 240;
			c = c == 0 ? self->gtiaColors[8] & 240 : self->gtiaColors[8] | c;
			frame[frameOffset + x] = (uint8_t) c;
		}
		for (; x < self->width + self->leftSkip; x++)
			frame[frameOffset + x] = (uint8_t) (self->gtiaColors[8] & 240);
		contentOffset += self->width >> 3;
		frameOffset += frameStride;
	}
}

static void RECOIL_DecodeAtari8Gr10(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset, int frameStride, int height)
{
	frameOffset += 2 - self->leftSkip;
	for (int y = 0; y < height; y++) {
		int x;
		for (x = self->leftSkip - 2; x < 0; x++)
			frame[frameOffset + x] = self->gtiaColors[0];
		for (; x < self->width + self->leftSkip - 2; x++) {
			int c = content[contentOffset + (x >> 3)] >> (~x & 4) & 15;
			frame[frameOffset + x] = self->gtiaColors[c];
		}
		contentOffset += self->width >> 3;
		frameOffset += frameStride;
	}
}

static void RECOIL_DecodeAtari8Gr11PalBlend(const RECOIL *self, uint8_t const *content, int contentOffset, int contentStride, uint8_t *frame, int y)
{
	for (; y < self->height; y += 2) {
		int frameOffset = y * self->width - self->leftSkip;
		for (int x = self->leftSkip; x < self->width; x++) {
			int c = content[contentOffset + (x >> 3)] << (x & 4) & 240;
			int i = ((y == 0 ? 0 : frame[frameOffset - self->width + x] & 15) + (y == self->height - 1 ? 0 : frame[frameOffset + self->width + x] & 15)) >> 1;
			frame[frameOffset + x] = (uint8_t) (c | i);
			if (y < self->height - 1)
				frame[frameOffset + self->width + x] = (uint8_t) (c | (frame[frameOffset + self->width + x] & 15));
		}
		memset(frame + (frameOffset + self->width), 0, self->leftSkip * sizeof(uint8_t));
		contentOffset += contentStride;
	}
}

static int RECOIL_ToAtari8Char(int ascii)
{
	switch (ascii & 96) {
	case 0:
		return ascii + 64;
	case 32:
	case 64:
		return ascii - 32;
	default:
		return ascii;
	}
}

static void RECOIL_DecodeAtari8Gr0Line(const RECOIL *self, uint8_t const *characters, int charactersOffset, uint8_t const *font, int fontOffset, uint8_t *frame, int frameOffset, int lines)
{
	uint8_t colors[2];
	colors[0] = self->gtiaColors[6];
	colors[1] = (uint8_t) ((self->gtiaColors[6] & 240) | (self->gtiaColors[5] & 14));
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < self->width; x++) {
			int ch = charactersOffset + (x >> 3);
			if (characters != NULL)
				ch = characters[ch];
			int b = RECOIL_GetAtari8Gr0Pixel(font, fontOffset, ch, x, y);
			if (lines == 10) {
				switch (((ch & 96) + y) >> 1) {
				case 4:
				case 20:
				case 36:
				case 48:
					b = ch >> 7;
					break;
				default:
					break;
				}
			}
			frame[frameOffset + x] = colors[b];
		}
		frameOffset += self->width;
	}
}

static void RECOIL_DecodeAtari8Gr0(RECOIL *self, uint8_t const *characters, int charactersOffset, int charactersStride, uint8_t const *font, int fontOffset, uint8_t *frame)
{
	self->gtiaColors[6] = 0;
	self->gtiaColors[5] = 14;
	for (int y = 0; y < self->height; y += 8)
		RECOIL_DecodeAtari8Gr0Line(self, characters, charactersOffset + (y >> 3) * charactersStride, font, fontOffset, frame, y * self->width, 8);
}

static void RECOIL_DecodeAtari8Gr1Line(const RECOIL *self, uint8_t const *content, int charactersOffset, uint8_t const *font, int fontOffset, uint8_t *frame, int frameOffset, int doubleLine)
{
	for (int y = 0; y < 8 << doubleLine; y++) {
		for (int x = 0; x < self->width; x++) {
			int ch = content[charactersOffset + (x >> 4)];
			int b = font[fontOffset + ((ch & 63) << 3) + (y >> doubleLine)] >> (~(x >> 1) & 7) & 1;
			frame[frameOffset + x] = self->gtiaColors[b == 0 ? 8 : 4 + (ch >> 6)];
		}
		frameOffset += self->width;
	}
}

static void RECOIL_DecodeAtari8Gr12Line(const RECOIL *self, uint8_t const *characters, int charactersOffset, uint8_t const *font, int fontOffset, uint8_t *frame, int frameOffset, int doubleLine)
{
	for (int y = 0; y < 8 << doubleLine; y++) {
		for (int x = 0; x < self->width; x++) {
			int ch = x >> 3;
			if (characters != NULL)
				ch = characters[charactersOffset + ch];
			int c = font[fontOffset + ((ch & 127) << 3) + (y >> doubleLine)] >> (~x & 6) & 3;
			int gr12Registers = ch >= 128 ? 30024 : 25928;
			frame[frameOffset + x] = self->gtiaColors[gr12Registers >> (c << 2) & 15];
		}
		frameOffset += self->width;
	}
}

static void RECOIL_DecodeAtari8Player(const RECOIL *self, uint8_t const *content, int contentOffset, int color, uint8_t *frame, int frameOffset, int height, bool multi)
{
	color &= 254;
	for (int y = 0; y < height; y++) {
		int b = content[contentOffset + y];
		for (int x = 0; x < 8; x++) {
			int c = b >> (7 - x) & 1;
			if (c != 0)
				frame[frameOffset + x * 2 + 1] = frame[frameOffset + x * 2] = (uint8_t) (multi ? frame[frameOffset + x * 2] | color : color);
		}
		frameOffset += self->width;
	}
}

static bool RECOIL_ApplyAtari8Palette(RECOIL *self, uint8_t const *frame)
{
	int pixelsLength = self->width * self->height;
	for (int i = 0; i < pixelsLength; i++)
		self->pixels[i] = self->atari8Palette[frame[i]];
	return true;
}

static bool RECOIL_ApplyAtari8PaletteBlend(RECOIL *self, uint8_t const *frame1, uint8_t const *frame2)
{
	int pixelsLength = self->width * self->height;
	self->frames = 2;
	for (int i = 0; i < pixelsLength; i++) {
		int rgb1 = self->atari8Palette[frame1[i]];
		int rgb2 = self->atari8Palette[frame2[i]];
		self->pixels[i] = (rgb1 & rgb2) + ((rgb1 ^ rgb2) >> 1 & 8355711);
	}
	return true;
}

static bool RECOIL_ApplyAtari8PaletteBlend3(RECOIL *self, uint8_t const *frame1, uint8_t const *frame2, uint8_t const *frame3)
{
	int pixelsLength = self->width * self->height;
	self->frames = 3;
	for (int i = 0; i < pixelsLength; i++) {
		int rgb1 = self->atari8Palette[frame1[i]];
		int rgb2 = self->atari8Palette[frame2[i]];
		int rgb3 = self->atari8Palette[frame3[i]];
		self->pixels[i] = ((rgb1 >> 16) + (rgb2 >> 16) + (rgb3 >> 16)) / 3 << 16 | ((rgb1 >> 8 & 255) + (rgb2 >> 8 & 255) + (rgb3 >> 8 & 255)) / 3 << 8 | ((rgb1 & 255) + (rgb2 & 255) + (rgb3 & 255)) / 3;
	}
	return true;
}

static bool RECOIL_DecodeGr8(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE1X1))
		return false;
	int contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	if (contentLength == 7682) {
		self->gtiaColors[6] = (uint8_t) (content[7680] & 14);
		self->gtiaColors[5] = (uint8_t) (content[7681] & 14);
	}
	else {
		self->gtiaColors[6] = 0;
		self->gtiaColors[5] = 14;
	}
	uint8_t frame[76800];
	RECOIL_DecodeAtari8Gr8(self, content, contentOffset, frame, 0, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeDrg(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 6400 && RECOIL_DecodeGr8(self, content, contentLength);
}

static bool RECOIL_DecodeGr8Raw(RECOIL *self, uint8_t const *content, int contentLength, int width, int height)
{
	RECOIL_SetSize(self, width, height, RECOILResolution_XE1X1, 1);
	self->contentPalette[0] = self->atari8Palette[0];
	self->contentPalette[1] = self->atari8Palette[14];
	return RECOIL_DecodeMono(self, content, 0, contentLength, false);
}

static bool RECOIL_DecodePsf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 572 || contentLength > 640)
		return false;
	RECOIL_SetSize(self, 88, 52, RECOILResolution_XE1X1, 1);
	self->contentPalette[0] = self->atari8Palette[14];
	self->contentPalette[1] = self->atari8Palette[0];
	RECOIL_DecodeBitplanes(self, content, 0, 11, 1, 0, 88, 52);
	return true;
}

static bool RECOIL_DecodeMonoArt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 4)
		return false;
	int columns = content[0] + 1;
	int height = content[1] + 1;
	if (columns > 30 || height > 64 || contentLength != 3 + columns * height)
		return false;
	RECOIL_SetSize(self, columns << 3, height, RECOILResolution_XE1X1, 1);
	self->contentPalette[0] = self->atari8Palette[14];
	self->contentPalette[1] = self->atari8Palette[0];
	RECOIL_DecodeBitplanes(self, content, 2, columns, 1, 0, columns << 3, height);
	return true;
}

static bool RECOIL_DecodeGhg(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 4)
		return false;
	int width = content[0] | content[1] << 8;
	int height = content[2];
	if (width == 0 || width > 320 || height == 0 || height > 200 || contentLength != 3 + ((width + 7) >> 3) * height)
		return false;
	RECOIL_SetSize(self, width, height, RECOILResolution_XE1X1, 1);
	uint8_t frame[64000];
	self->gtiaColors[6] = 12;
	self->gtiaColors[5] = 2;
	RECOIL_DecodeAtari8Gr8(self, content, 3, frame, 0, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeCpr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 2)
		return false;
	XeKoalaStream rle;
	XeKoalaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 1;
	rle.base.base.base.contentLength = contentLength;
	if (!XeKoalaStream_UnpackRaw(&rle, content[0], 7680))
		return false;
	self->gtiaColors[6] = 12;
	self->gtiaColors[5] = 0;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1, 1);
	uint8_t frame[61440];
	RECOIL_DecodeAtari8Gr8(self, rle.unpacked, 0, frame, 0, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeSg3(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 240)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE8X8, 1);
	uint8_t frame[61440];
	RECOIL_SetXeOsDefaultColors(self);
	RECOIL_DecodeAtari8Gr3(self, content, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGr3(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 244)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE8X8, 1);
	uint8_t frame[61440];
	RECOIL_SetBakPF012(self, content, 240, 1);
	RECOIL_DecodeAtari8Gr3(self, content, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeDit(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3845)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X2, 1);
	uint8_t frame[61440];
	RECOIL_SetPF0123Bak(self, content, 3840);
	RECOIL_DecodeAtari8Gr7(self, content, 0, frame, 0, 96);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeVisualizer(RECOIL *self, uint8_t const *content)
{
	RECOIL_SetSize(self, 320, 158, RECOILResolution_XE2X2, 1);
	uint8_t frame[50560];
	RECOIL_SetPF0123Bak(self, content, 0);
	RECOIL_DecodeAtari8Gr7(self, content, 5, frame, 0, 79);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGr7(RECOIL *self, uint8_t const *content, int contentOffset, int contentSize)
{
	if (contentSize > 4804 || contentSize % 40 != 4)
		return false;
	int height = contentSize / 40;
	RECOIL_SetSize(self, 320, height * 2, RECOILResolution_XE2X2, 1);
	uint8_t frame[76800];
	RECOIL_SetBakPF012(self, content, contentOffset + contentSize - 4, 1);
	RECOIL_DecodeAtari8Gr7(self, content, contentOffset, frame, 0, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeRys(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3840)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X2, 1);
	uint8_t frame[61440];
	RECOIL_SetXeOsDefaultColors(self);
	RECOIL_DecodeAtari8Gr7(self, content, 0, frame, 0, 96);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeBkg(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 3856 && RECOIL_DecodeGr7(self, content, 0, 3844);
}

static bool RECOIL_DecodeAtari8Artist(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3206 || content[0] != 7)
		return false;
	RECOIL_SetSize(self, 320, 160, RECOILResolution_XE2X2, 1);
	uint8_t frame[51200];
	RECOIL_SetPF0123Bak(self, content, 1);
	RECOIL_DecodeAtari8Gr7(self, content, 6, frame, 0, 80);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGr9(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE4X1))
		return false;
	self->gtiaColors[8] = 0;
	int contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	uint8_t frame[76800];
	RECOIL_DecodeAtari8Gr9(self, content, contentOffset, 40, frame, 0, 320, 320, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeRap(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 7681)
		return false;
	self->gtiaColors[8] = (uint8_t) (content[7680] & 254);
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1, 1);
	uint8_t frame[61440];
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame, 0, 320, 320, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeTxe(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3840)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2, 1);
	uint8_t frame[61440];
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame, 0, 640, 320, 96);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGr9x4(RECOIL *self, uint8_t const *content, int contentOffset, int width, int height)
{
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_XE4X4, 1))
		return false;
	uint8_t *frame = (uint8_t *) malloc(width * height * sizeof(uint8_t));
	self->gtiaColors[8] = 0;
	for (int y = 0; y < 4; y++)
		RECOIL_DecodeAtari8Gr9(self, content, contentOffset, width >> 3, frame, y * width, width << 2, width, height >> 2);
	RECOIL_ApplyAtari8Palette(self, frame);
	free(frame);
	return true;
}

static bool RECOIL_DecodeZm4(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 2048 && RECOIL_DecodeGr9x4(self, content, 0, 256, 256);
}

static bool RECOIL_DecodeGr9p(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 2400 && RECOIL_DecodeGr9x4(self, content, 0, 320, 240);
}

static bool RECOIL_DecodeFge(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 1286 && RECOIL_DecodeGr9x4(self, content, 6, 256, 160);
}

static bool RECOIL_Decode16x16x16(RECOIL *self, uint8_t const *content, int contentOffset, int colbak)
{
	RECOIL_SetSize(self, 64, 64, RECOILResolution_XE4X4, 1);
	for (int y = 0; y < 64; y++) {
		for (int x = 0; x < 64; x++) {
			int c = content[contentOffset + ((y & ~3) << 2) + (x >> 2)];
			if (c > 15)
				return false;
			self->pixels[(y << 6) + x] = self->atari8Palette[colbak | c];
		}
	}
	return true;
}

static bool RECOIL_DecodeTx0(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 257 && RECOIL_Decode16x16x16(self, content, 0, content[256] & 254);
}

static bool RECOIL_DecodeTxs(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 262 && content[0] == 255 && content[1] == 255 && content[2] == 0 && content[3] == 6 && content[4] == 255 && content[5] == 6 && RECOIL_Decode16x16x16(self, content, 6, 0);
}

static bool RECOIL_DecodeA4r(RECOIL *self, uint8_t const *content, int contentLength)
{
	A4rStream s;
	A4rStream_Construct(&s);
	s.base.content = content;
	s.base.contentOffset = 0;
	s.base.contentLength = contentLength;
	if (!A4rStream_UnpackA4r(&s))
		return false;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_XE4X1, 1);
	uint8_t frame[81920];
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, s.unpacked, 512, 40, frame, 0, 320, 320, 256);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeG11(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE4X1))
		return false;
	self->gtiaColors[8] = 6;
	int contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	uint8_t frame[76800];
	RECOIL_DecodeAtari8Gr11(self, content, contentOffset, frame, 0, 320, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeG10(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE4X1))
		return false;
	int contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	if ((contentLength - contentOffset) % 40 != 9)
		return false;
	self->leftSkip = 2;
	RECOIL_SetGtiaColors(self, content, contentLength - 9);
	uint8_t frame[76800];
	RECOIL_DecodeAtari8Gr10(self, content, contentOffset, frame, 0, 320, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeG09(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 7680:
		return RECOIL_DecodeGr9(self, content, contentLength);
	case 15360:
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 640, 192, RECOILResolution_XE4X1, 1);
	self->gtiaColors[8] = 0;
	uint8_t frame[122880];
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame, 0, 640, 320, 192);
	RECOIL_DecodeAtari8Gr9(self, content, 7680, 40, frame, 320, 640, 320, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeSkp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 7680)
		return false;
	self->gtiaColors[8] = 38;
	self->gtiaColors[4] = 40;
	self->gtiaColors[5] = 0;
	self->gtiaColors[6] = 12;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame, 0, 320, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeKss(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 6404)
		return false;
	RECOIL_SetSize(self, 320, 160, RECOILResolution_XE2X1, 1);
	uint8_t frame[51200];
	RECOIL_SetBakPF012(self, content, 6400, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame, 0, 320, 160);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeMic(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength == 15872) {
		contentLength = 7680;
		RECOIL_SetPF012Bak(self, content, 7680);
	}
	else {
		switch (contentLength % 40) {
		case 0:
		case 3:
			RECOIL_SetGr15DefaultColors(self);
			break;
		case 4:
			RECOIL_SetBakPF012(self, content, contentLength - 4, 1);
			break;
		case 5:
			RECOIL_SetPF012Bak(self, content, contentLength - 5);
			break;
		default:
			return false;
		}
	}
	int height = contentLength / 40;
	if (height == 0 || height > 240)
		return false;
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1, 1);
	uint8_t frame[76800];
	if (filename != NULL) {
		if (contentLength % 40 == 0) {
			uint8_t asm_[131072];
			int asmLength = RECOIL_ReadCompanionFile(self, filename, "RP.INI", "rp.ini", asm_, 131072);
			if (asmLength > 0) {
				RastaStream s;
				RastaStream_Construct(&s);
				s.base.content = asm_;
				s.base.contentLength = asmLength;
				if (!RastaStream_ReadIni(&s))
					return false;
				s.base.contentLength = RECOIL_ReadCompanionFile(self, filename, "PMG", "pmg", asm_, 131072);
				if (!RastaStream_ReadPmg(&s))
					return false;
				s.base.contentLength = RECOIL_ReadCompanionFile(self, filename, "RP", "rp", asm_, 131072);
				return RastaStream_ReadRp(&s, content, height, frame) && RECOIL_ApplyAtari8Palette(self, frame);
			}
		}
		if (height == 240) {
			uint8_t col[1281];
			switch (RECOIL_ReadCompanionFile(self, filename, "COL", "col", col, 1281)) {
			case 1024:
			case 1280:
				for (int y = 0; y < 240; y++) {
					RECOIL_SetBakPF012(self, col, y, 256);
					RECOIL_DecodeAtari8Gr15(self, content, y * 40, 40, frame, y * 320, 320, 1);
				}
				return RECOIL_ApplyAtari8Palette(self, frame);
			default:
				break;
			}
		}
	}
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame, 0, 320, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodePi8(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 7680:
		return RECOIL_DecodeMic(self, NULL, content, contentLength);
	case 7685:
		return RECOIL_DecodeGr8(self, content, contentLength);
	default:
		return false;
	}
}

static bool RECOIL_DecodeHpm(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[7684];
	HpmStream rle;
	HpmStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 7680))
		return false;
	switch (Stream_ReadByte(&rle.base.base.base)) {
	case 52:
	case 53:
		unpacked[7680] = 0;
		unpacked[7681] = 52;
		unpacked[7682] = (uint8_t) (contentLength == 3494 ? 56 : 200);
		unpacked[7683] = (uint8_t) (contentLength == 3494 ? 60 : 124);
		break;
	case 81:
		unpacked[7680] = 164;
		unpacked[7681] = 81;
		unpacked[7682] = 185;
		unpacked[7683] = 124;
		break;
	case 228:
		unpacked[7680] = 0;
		unpacked[7681] = 228;
		unpacked[7682] = 200;
		unpacked[7683] = 190;
		break;
	case 4:
		unpacked[7680] = 6;
		unpacked[7681] = 4;
		unpacked[7682] = 0;
		unpacked[7683] = 10;
		break;
	case 48:
		unpacked[7680] = 14;
		unpacked[7681] = 48;
		unpacked[7682] = 199;
		unpacked[7683] = 123;
		break;
	case 116:
		unpacked[7680] = 0;
		unpacked[7681] = 116;
		unpacked[7682] = 88;
		unpacked[7683] = 126;
		break;
	default:
		unpacked[7680] = 0;
		unpacked[7681] = 4;
		unpacked[7682] = 8;
		unpacked[7683] = 12;
		break;
	}
	return RECOIL_DecodeMic(self, NULL, unpacked, 7684);
}

static bool RECOIL_DecodeCpi(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[7936];
	CpiStream rle;
	CpiStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 7936))
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 12;
	self->gtiaColors[5] = 8;
	self->gtiaColors[6] = 4;
	RECOIL_DecodeAtari8Gr15(self, unpacked, 0, 40, frame, 0, 320, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeWnd(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3072)
		return false;
	int width = content[0] + 1;
	int contentStride = (width + 3) >> 2;
	int height = content[1];
	if (contentStride > 40 || height == 0 || height > 192 || contentStride * height > 3070)
		return false;
	RECOIL_SetSize(self, width << 1, height, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 70;
	self->gtiaColors[5] = 136;
	self->gtiaColors[6] = 14;
	RECOIL_DecodeAtari8Gr15(self, content, 2, contentStride, frame, 0, width << 1, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAtari8Koala(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength)
{
	if (contentOffset + 22 >= contentLength)
		return false;
	int rows = content[contentOffset + 12];
	if (rows > 192)
		return false;
	XeKoalaStream rle;
	XeKoalaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset;
	rle.base.base.base.contentLength = contentLength;
	if (!XeKoalaStream_UnpackWrapped(&rle, rows * 40))
		return false;
	RECOIL_SetPF0123Bak(self, content, contentOffset + 13);
	uint8_t frame[61440];
	switch (content[contentOffset + 20] << 16 | content[contentOffset + 8] << 8 | rows) {
	case 536:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1, 1);
		uint8_t const *font = FuResource_atari8_fnt;
		for (int row = 0; row < 24; row++)
			RECOIL_DecodeAtari8Gr0Line(self, rle.unpacked, row * 40, font, 0, frame, row * 2560, 8);
		break;
	case 3776:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
		RECOIL_DecodeAtari8Gr15(self, rle.unpacked, 0, 40, frame, 0, 320, 192);
		break;
	case 69568:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1, 1);
		RECOIL_DecodeAtari8Gr9(self, rle.unpacked, 0, 40, frame, 0, 320, 320, 192);
		break;
	default:
		return false;
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAtari8Pix(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength >= 30 && content[0] == 27 && content[1] == 77 && 4 + (content[2] | content[3] << 8) == contentLength && RECOIL_DecodeAtari8Koala(self, content, 4, contentLength);
}

static void RECOIL_DecodeAt800Players(const RECOIL *self, uint8_t const *content, uint8_t *frame)
{
	for (int i = 0; i < 4; i++)
		RECOIL_DecodeAtari8Player(self, content, 4 + i * 240, content[i], frame, i * 10 * 2, 240, false);
}

static void RECOIL_DecodeAt800Missiles(const RECOIL *self, uint8_t const *content, int contentOffset, uint8_t *frame, int frameOffset)
{
	for (int y = 0; y < 240; y++) {
		for (int i = 0; i < 4; i++) {
			int b = content[contentOffset + y] >> (i << 1);
			int offset = frameOffset + i * 4 * 2;
			frame[offset + 1] = frame[offset] = (uint8_t) ((b & 2) == 0 ? 0 : content[i]);
			frame[offset + 3] = frame[offset + 2] = (uint8_t) ((b & 1) == 0 ? 0 : content[i]);
		}
		frameOffset += self->width;
	}
}

static bool RECOIL_DecodePla(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 241)
		return false;
	RECOIL_SetSize(self, 16, 240, RECOILResolution_XE2X1, 1);
	uint8_t frame[3840] = { 0 };
	RECOIL_DecodeAtari8Player(self, content, 1, content[0], frame, 0, 240, false);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeMis(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 61 && contentLength != 241)
		return false;
	RECOIL_SetSize(self, 4, 240, RECOILResolution_XE2X1, 1);
	uint8_t frame[960];
	for (int y = 0; y < 240; y++) {
		int b = content[1 + (y >> 2)] >> ((~y & 3) << 1);
		frame[y * 4 + 1] = frame[y * 4] = (uint8_t) ((b & 2) == 0 ? 0 : content[0]);
		frame[y * 4 + 3] = frame[y * 4 + 2] = (uint8_t) ((b & 1) == 0 ? 0 : content[0]);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_Decode4pl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 964)
		return false;
	RECOIL_SetSize(self, 80, 240, RECOILResolution_XE2X1, 1);
	uint8_t frame[19200] = { 0 };
	RECOIL_DecodeAt800Players(self, content, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_Decode4mi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 244)
		return false;
	RECOIL_SetSize(self, 32, 240, RECOILResolution_XE2X1, 1);
	uint8_t frame[7680] = { 0 };
	RECOIL_DecodeAt800Missiles(self, content, 4, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_Decode4pm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1204)
		return false;
	RECOIL_SetSize(self, 112, 240, RECOILResolution_XE2X1, 1);
	uint8_t frame[26880] = { 0 };
	RECOIL_DecodeAt800Players(self, content, frame);
	RECOIL_DecodeAt800Missiles(self, content, 964, frame, 80);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAtari8Spr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 3 || contentLength > 42)
		return false;
	int height = content[0];
	if (2 + height != contentLength)
		return false;
	RECOIL_SetSize(self, 16, height, RECOILResolution_XE2X1, 1);
	uint8_t frame[640] = { 0 };
	RECOIL_DecodeAtari8Player(self, content, 2, content[1], frame, 0, height, false);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeMsl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 3 || contentLength > 36)
		return false;
	int height = content[0];
	if (2 + height != contentLength)
		return false;
	RECOIL_SetSize(self, 4, height, RECOILResolution_XE2X1, 1);
	uint8_t frame[136];
	for (int y = 0; y < height; y++) {
		int b = content[2 + y];
		if (b > 3)
			return false;
		frame[y * 4 + 1] = frame[y * 4] = (uint8_t) ((b & 2) == 0 ? 0 : content[1]);
		frame[y * 4 + 3] = frame[y * 4 + 2] = (uint8_t) ((b & 1) == 0 ? 0 : content[1]);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeMpl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 13)
		return false;
	int height = content[0];
	if (height == 0 || height > 40)
		return false;
	int bitmapOffset = contentLength - (height << 2);
	if (bitmapOffset != 9 && bitmapOffset != 14)
		return false;
	int minX = 255;
	int maxX = 0;
	for (int i = 1; i < 5; i++) {
		int x = content[i];
		if (minX > x)
			minX = x;
		if (maxX < x)
			maxX = x;
	}
	if (maxX + 8 > 56)
		return false;
	RECOIL_SetSize(self, (maxX + 8 - minX) << 1, height, RECOILResolution_XE2X1, 1);
	uint8_t frame[4480] = { 0 };
	for (int i = 3; i >= 0; i--)
		RECOIL_DecodeAtari8Player(self, content, bitmapOffset + i * height, content[5 + i], frame, (content[1 + i] - minX) << 1, height, false);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeLdm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 281)
		return false;
	for (int i = 0; i < 21; i++)
		if (content[i] != "Ludek Maker data file"[i] + 128)
			return false;
	int shapes = content[24] - content[23];
	if (shapes <= 0 || shapes > 100 || contentLength < 281 + shapes * 120)
		return false;
	int rows = (shapes + 7) >> 3;
	if (rows == 1)
		RECOIL_SetSize(self, shapes * 40, 30, RECOILResolution_XE2X1, 1);
	else
		RECOIL_SetSize(self, 320, rows * 32 - 2, RECOILResolution_XE2X1, 1);
	uint8_t frame[132480] = { 0 };
	for (int shape = 0; shape < shapes; shape++) {
		int contentOffset = 281 + shape * 120;
		int frameOffset = (shape >> 3) * 32 * 320 + (shape & 7) * 40;
		RECOIL_DecodeAtari8Player(self, content, contentOffset, content[21], frame, frameOffset, 30, true);
		RECOIL_DecodeAtari8Player(self, content, contentOffset + 30, content[22], frame, frameOffset, 30, true);
		RECOIL_DecodeAtari8Player(self, content, contentOffset + 60, content[21], frame, frameOffset + 16, 30, true);
		RECOIL_DecodeAtari8Player(self, content, contentOffset + 90, content[22], frame, frameOffset + 16, 30, true);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodePmd(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 12 || content[0] != 240 || content[1] != 237 || content[2] != 228)
		return false;
	int sprites = content[7];
	int shapes = content[8] * content[9];
	int totalShapes = sprites * shapes;
	int height = content[10];
	if (sprites == 0 || sprites > 4 || shapes == 0 || shapes > 160 || height == 0 || height > 48 || 11 + totalShapes * height != contentLength)
		return false;
	if (true)
		totalShapes >>= 1;
	int rows = (totalShapes + 15) >> 4;
	if (rows == 1)
		RECOIL_SetSize(self, totalShapes * 20, height, RECOILResolution_XE2X1, 1);
	else {
		int totalHeight = rows * (height + 2) - 2;
		if (totalHeight > 560)
			return false;
		RECOIL_SetSize(self, 320, totalHeight, RECOILResolution_XE2X1, 1);
	}
	uint8_t frame[179200] = { 0 };
	for (int shape = 0; shape < totalShapes; shape++) {
		int frameOffset = (shape >> 4) * (height + 2) * 320 + (shape & 15) * 20;
		if (true) {
			int spritePair = shape / shapes;
			int contentOffset = 11 + (spritePair * shapes + shape) * height;
			RECOIL_DecodeAtari8Player(self, content, contentOffset, content[3 + spritePair * 2], frame, frameOffset, height, true);
			RECOIL_DecodeAtari8Player(self, content, contentOffset + shapes * height, content[4 + spritePair * 2], frame, frameOffset, height, true);
		}
		else
			RECOIL_DecodeAtari8Player(self, content, 11 + shape * height, content[3 + shape / shapes], frame, frameOffset, height, false);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeApl(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1677 || content[0] != 154 || content[1] != 248 || content[2] != 57 || content[3] != 33)
		return false;
	int frames = content[4];
	int height = content[5];
	int gap = content[6];
	if (frames == 0 || frames > 16 || height == 0 || height > 48 || gap > 8)
		return false;
	int frameWidth = (8 + gap + 2) << 1;
	RECOIL_SetSize(self, frames * frameWidth, height, RECOILResolution_XE2X1, 1);
	uint8_t frame[27648] = { 0 };
	for (int f = 0; f < frames; f++) {
		RECOIL_DecodeAtari8Player(self, content, 42 + f * 48, content[7 + f], frame, f * frameWidth, height, true);
		RECOIL_DecodeAtari8Player(self, content, 858 + f * 48, content[24 + f], frame, f * frameWidth + gap * 2, height, true);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_GetSprEdPixel(uint8_t const *content, int bitmapOffset, int bitmapStride, int x)
{
	if (x < 0 || x >= 10)
		return false;
	int grafp = content[bitmapOffset] << 2;
	if ((content[10] & 1) != 0)
		grafp |= content[bitmapOffset + 4 * bitmapStride] & 3;
	return (grafp >> (9 - x) & 1) != 0;
}

static int RECOIL_GetSprEdPair(uint8_t const *content, int bitmapOffset, int bitmapStride, int colorOffset, int colorStride, int x, int gap01)
{
	bool p1 = RECOIL_GetSprEdPixel(content, bitmapOffset + bitmapStride, bitmapStride, x - gap01);
	if (RECOIL_GetSprEdPixel(content, bitmapOffset, bitmapStride, x)) {
		int c = content[colorOffset];
		if (p1)
			c |= content[colorOffset + colorStride];
		return c;
	}
	if (p1)
		return content[colorOffset + colorStride];
	return -1;
}

static bool RECOIL_DecodeSprEd(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 23 || !RECOIL_IsStringAt(content, 0, "Spr!"))
		return false;
	int doubleLine = content[9];
	int mergeMode = content[10];
	int gap01;
	int gap23 = content[12];
	int gap02 = content[13];
	bool dli = (content[14] & 1) != 0;
	int frames = content[16];
	int height;
	if (frames == 0) {
		gap01 = content[11];
		frames = content[17];
		height = content[18];
	}
	else {
		height = content[17];
		gap01 = content[18];
	}
	int unitWidth = 8 + ((mergeMode & 1) << 1);
	int players = (mergeMode & 4) != 0 ? 4 : 2;
	int dliOffset = 19 + players * frames * (1 + (height << (mergeMode & 1)));
	int bitmapStride = frames * height;
	if (doubleLine > 1 || gap01 > unitWidth || gap23 > unitWidth || gap02 > unitWidth << 1 || contentLength < (dli ? dliOffset + 5 * bitmapStride : dliOffset))
		return false;
	int frameWidth = unitWidth + gap01;
	if (players == 4) {
		int width23 = gap02 + unitWidth + gap23;
		if (frameWidth < width23)
			frameWidth = width23;
	}
	frameWidth += 2;
	int width = frames * frameWidth - 2;
	if (!RECOIL_SetSize(self, width << 1, height << doubleLine, doubleLine == 0 ? RECOILResolution_XE2X1 : RECOILResolution_XE2X2, 1))
		return false;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int frame = x / frameWidth;
			int h = x % frameWidth;
			int colorOffset = 19 + frame;
			int colorStride = frames;
			if (dli) {
				colorOffset = dliOffset + bitmapStride + frame * height + y;
				colorStride = bitmapStride;
			}
			int bitmapOffset = 19 + players * frames + frame * height + y;
			int c = RECOIL_GetSprEdPair(content, bitmapOffset, bitmapStride, colorOffset, colorStride, h, gap01);
			if (c < 0 && players == 4)
				c = RECOIL_GetSprEdPair(content, bitmapOffset + 2 * bitmapStride, bitmapStride, colorOffset + 2 * colorStride, colorStride, h - gap02, gap23);
			if (c < 0)
				c = content[dli ? colorOffset - bitmapStride : 6];
			c = self->atari8Palette[c & 254];
			int pixelsOffset = ((y * width << doubleLine) + x) << 1;
			self->pixels[pixelsOffset + 1] = self->pixels[pixelsOffset] = c;
			if (doubleLine != 0)
				self->pixels[pixelsOffset + (width << 1) + 1] = self->pixels[pixelsOffset + (width << 1)] = c;
		}
	}
	return true;
}

static bool RECOIL_DecodeAtari8Hr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 16384)
		return false;
	RECOIL_SetSize(self, 256, 239, RECOILResolution_XE1X1, 1);
	self->gtiaColors[6] = 0;
	self->gtiaColors[5] = 14;
	uint8_t frame1[61184];
	RECOIL_DecodeAtari8Gr8(self, content, 0, frame1, 0, 239);
	uint8_t frame2[61184];
	RECOIL_DecodeAtari8Gr8(self, content, 8192, frame2, 0, 239);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeMcppVariable(RECOIL *self, uint8_t const *content, int bitmapOffset, int colorsOffset, int width, int height)
{
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_XE2X2, 1))
		return false;
	uint8_t *frame = (uint8_t *) malloc(width * height * sizeof(uint8_t));
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset, width >> 3, frame, 0, width << 1, height >> 1);
	RECOIL_SetPF012Bak(self, content, colorsOffset + 4);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + (width * height >> 4), width >> 3, frame, width, width << 1, height >> 1);
	RECOIL_ApplyAtari8Palette(self, frame);
	free(frame);
	return true;
}

static bool RECOIL_DecodeMcpp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 8008 && RECOIL_DecodeMcppVariable(self, content, 0, 8000, 320, 200);
}

static bool RECOIL_DecodeIld(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 8195)
		return false;
	RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1, 1);
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 6;
	self->gtiaColors[5] = 2;
	self->gtiaColors[6] = 10;
	uint8_t frame1[32768];
	RECOIL_DecodeAtari8Gr15(self, content, 0, 32, frame1, 0, 256, 128);
	uint8_t frame2[32768];
	RECOIL_DecodeAtari8Gr15(self, content, 4096, 32, frame2, 0, 256, 128);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeInp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 16004)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1, 1);
	RECOIL_SetBakPF012(self, content, 16000, 1);
	uint8_t frame1[64000];
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame1, 0, 320, 200);
	uint8_t frame2[64000];
	RECOIL_DecodeAtari8Gr15(self, content, 8000, 40, frame2, 0, 320, 200);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeIge(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 6160 || content[0] != 255 || content[1] != 255 || content[2] != 246 || content[3] != 163 || content[4] != 255 || content[5] != 187 || content[6] != 255 || content[7] != 95)
		return false;
	RECOIL_SetSize(self, 256, 96, RECOILResolution_XE2X1, 1);
	uint8_t frame1[24576];
	RECOIL_SetBakPF012(self, content, 8, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 16, 32, frame1, 0, 256, 96);
	uint8_t frame2[24576];
	RECOIL_SetBakPF012(self, content, 12, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 3088, 32, frame2, 0, 256, 96);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeInt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 18 || !RECOIL_IsStringAt(content, 0, "INT95a") || content[8] != 15 || content[9] != 43)
		return false;
	int contentStride = content[6];
	int height = content[7];
	if (contentStride == 0 || contentStride > 320 || height == 0 || height > 239 || 18 + contentStride * height * 2 != contentLength)
		return false;
	int width = contentStride << 3;
	RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1, 1);
	uint8_t frame1[76480];
	RECOIL_SetBakPF012(self, content, 10, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 18, contentStride, frame1, 0, width, height);
	uint8_t frame2[76480];
	RECOIL_SetBakPF012(self, content, 14, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 18 + contentStride * height, contentStride, frame2, 0, width, height);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeIst(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 17184)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1, 1);
	uint8_t frame1[64000];
	uint8_t frame2[64000];
	for (int y = 0; y < 200; y++) {
		RECOIL_SetBakPF012(self, content, 16384 + y, 200);
		RECOIL_DecodeAtari8Gr15(self, content, 16 + y * 40, 0, frame1, y * 320, 320, 1);
		RECOIL_DecodeAtari8Gr15(self, content, 8208 + y * 40, 0, frame2, y * 320, 320, 1);
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeGr15Blend(RECOIL *self, uint8_t const *content, int bitmapOffset, int colorsOffset, int height)
{
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1, 1);
	uint8_t frame1[64000];
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset, 80, frame1, 0, 640, height >> 1);
	RECOIL_SetPF012Bak(self, content, colorsOffset + 4);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + 40, 80, frame1, 320, 640, height >> 1);
	uint8_t frame2[64000];
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + height * 40, 80, frame2, 0, 640, height >> 1);
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + height * 40 + 40, 80, frame2, 320, 640, height >> 1);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeMcp(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 16008 && RECOIL_DecodeGr15Blend(self, content, 0, 16000, 200);
}

static bool RECOIL_DecodeAtari8Raw(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 15372 && RECOIL_IsStringAt(content, 0, "XLPB") && RECOIL_DecodeGr15Blend(self, content, 4, 15364, 192);
}

static bool RECOIL_DecodeXlp(RECOIL *self, uint8_t const *content, int contentLength)
{
	XlpStream rle;
	XlpStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentLength = contentLength;
	uint8_t unpacked[16000];
	int height;
	int colorsOffset;
	if (contentLength >= 10 && RECOIL_IsStringAt(content, 0, "XLPC")) {
		memset(unpacked, 0, sizeof(unpacked));
		rle.base.base.base.contentOffset = 8;
		RleStream_UnpackColumns(&rle.base, unpacked, 0, 40, 15360);
		height = 192;
		colorsOffset = 4;
	}
	else {
		rle.base.base.base.contentOffset = 4;
		if (RleStream_UnpackColumns(&rle.base, unpacked, 0, 40, 16000))
			height = 200;
		else {
			rle.base.base.base.contentOffset = 4;
			if (RleStream_UnpackColumns(&rle.base, unpacked, 0, 40, 15360))
				height = 192;
			else
				return false;
		}
		colorsOffset = 0;
	}
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1, 1);
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	uint8_t frame1[64000];
	RECOIL_DecodeAtari8Gr15(self, unpacked, 0, 40, frame1, 0, 320, height);
	uint8_t frame2[64000];
	RECOIL_DecodeAtari8Gr15(self, unpacked, height * 40, 40, frame2, 0, 320, height);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeAtari8Max(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1732 || !RECOIL_IsStringAt(content, 0, "XLPM"))
		return false;
	XlpStream rle;
	XlpStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 1732;
	rle.base.base.base.contentLength = contentLength;
	uint8_t unpacked[15360];
	if (!RleStream_UnpackColumns(&rle.base, unpacked, 0, 40, 15360))
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame1[61440];
	uint8_t frame2[61440];
	for (int y = 0; y < 192; y++) {
		RECOIL_SetBakPF012(self, content, 772 + y, 192);
		RECOIL_DecodeAtari8Gr15(self, unpacked, y * 40, 40, frame1, y * 320, 320, 1);
		RECOIL_SetBakPF012(self, content, 4 + y, 192);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 7680 + y * 40, 40, frame2, y * 320, 320, 1);
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeHr2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 16006)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE1X1, 1);
	uint8_t frame1[64000];
	RECOIL_SetPF21(self, content, 16000);
	RECOIL_DecodeAtari8Gr8(self, content, 0, frame1, 0, 200);
	uint8_t frame2[64000];
	RECOIL_SetBakPF012(self, content, 16002, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 8000, 40, frame2, 0, 320, 200);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeLum(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (contentLength != 4766)
		return false;
	RECOIL_SetSize(self, 320, 238, RECOILResolution_XE4X2, 1);
	uint8_t frame[76160];
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 6, 40, frame, 320, 640, 320, 119);
	uint8_t col[4767];
	if (RECOIL_ReadCompanionFile(self, filename, "COL", "col", col, 4767) == 4766) {
		RECOIL_DecodeAtari8Gr11PalBlend(self, col, 6, 40, frame, 0);
	}
	else {
		RECOIL_DecodeAtari8Gr9(self, content, 6, 40, frame, 0, 640, 320, 119);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeApc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 7680 && contentLength != 7720)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2, 1);
	uint8_t frame[61440];
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 40, 80, frame, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 0, 80, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_Decode256(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 7680 && contentLength != 7684)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2, 1);
	uint8_t frame[61440];
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 3840, 40, frame, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 0, 40, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeMga(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 7856)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2, 1);
	uint8_t frame[61440];
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 0, 80, frame, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 40, 80, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAp3(RECOIL *self, uint8_t const *content, int contentLength)
{
	int gr11Offset;
	switch (contentLength) {
	case 15360:
	case 15362:
		gr11Offset = 7680;
		break;
	case 15872:
		gr11Offset = 8192;
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1, 1);
	self->gtiaColors[8] = 0;
	uint8_t frame1[61440];
	RECOIL_DecodeAtari8Gr9(self, content, 0, 80, frame1, 0, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, gr11Offset + 40, 80, frame1, 1);
	uint8_t frame2[61440];
	RECOIL_DecodeAtari8Gr9(self, content, 40, 80, frame2, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, gr11Offset, 80, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeBgp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 19163 || !RECOIL_IsStringAt(content, 0, "BUGBITER_APAC239I_PICTURE_V1.0") || content[30] != 255 || content[31] != 80 || content[32] != 239)
		return false;
	int textLength = content[37] + (content[38] << 8);
	if (contentLength != 19163 + textLength || content[39 + textLength] != 88 || content[40 + textLength] != 37 || content[9601 + textLength] != 88 || content[9602 + textLength] != 37)
		return false;
	RECOIL_SetSize(self, 320, 239, RECOILResolution_XE4X1, 1);
	self->gtiaColors[8] = 0;
	uint8_t frame1[76480];
	RECOIL_DecodeAtari8Gr9(self, content, 41 + textLength, 80, frame1, 0, 640, 320, 120);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9643 + textLength, 80, frame1, 1);
	uint8_t frame2[76480];
	RECOIL_DecodeAtari8Gr9(self, content, 81 + textLength, 80, frame2, 320, 640, 320, 119);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9603 + textLength, 80, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeHip(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 80)
		return false;
	static const uint8_t GR10_COLORS[9] = { 0, 0, 2, 4, 6, 8, 10, 12, 14 };
	uint8_t frame1[76800];
	uint8_t frame2[76800];
	int frameLength = RECOIL_ParseAtari8ExecutableHeader(content, 0);
	if (frameLength > 0 && frameLength % 40 == 0 && 12 + frameLength * 2 == contentLength && RECOIL_ParseAtari8ExecutableHeader(content, 6 + frameLength) == frameLength) {
		int height = frameLength / 40;
		if (height > 240)
			return false;
		RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		RECOIL_SetGtiaColors(self, GR10_COLORS, 0);
		RECOIL_DecodeAtari8Gr10(self, content, 6, frame1, 0, 320, height);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, content, 12 + frameLength, 40, frame2, 0, 320, 320, height);
	}
	else {
		int height = contentLength / 80;
		if (height > 240)
			return false;
		RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame1, 0, 320, 320, height);
		if (contentLength % 80 == 9)
			RECOIL_SetGtiaColors(self, content, contentLength - 9);
		else
			RECOIL_SetGtiaColors(self, GR10_COLORS, 0);
		RECOIL_DecodeAtari8Gr10(self, content, height * 40, frame2, 0, 320, height);
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeG9s(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[7680];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 7680) && RECOIL_DecodeGr9(self, unpacked, 7680);
}

static bool RECOIL_DecodeIns(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[16004];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 16004) && RECOIL_DecodeInp(self, unpacked, 16004);
}

static bool RECOIL_DecodePls(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[7680];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 7680) && RECOIL_DecodeApc(self, unpacked, 7680);
}

static bool RECOIL_DecodeAps(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[7720];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 7720) && RECOIL_DecodeApc(self, unpacked, 7720);
}

static bool RECOIL_DecodeIls(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[15360];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 15360) && RECOIL_DecodeAp3(self, unpacked, 15360);
}

static bool RECOIL_DecodeApp(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[15872];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 15872) && RECOIL_DecodeAp3(self, unpacked, 15872);
}

static bool RECOIL_DecodeHps(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t unpacked[16009];
	SfdnStream s;
	SfdnStream_Construct(&s);
	s.base.base.content = content;
	s.base.base.contentLength = contentLength;
	return SfdnStream_Unpack(&s, unpacked, 16009) && RECOIL_DecodeHip(self, unpacked, 16009);
}

static bool RECOIL_DecodeTip(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 129 || content[0] != 'T' || content[1] != 'I' || content[2] != 'P' || content[3] != 1 || content[4] != 0)
		return false;
	int width = content[5];
	int height = content[6];
	if (width > 160 || (width & 3) != 0 || height > 119)
		return false;
	int contentStride = width >> 2;
	int frameLength = content[7] | content[8] << 8;
	if (frameLength != contentStride * height || contentLength != 9 + 3 * frameLength)
		return false;
	RECOIL_SetSize(self, width << 1, height << 1, RECOILResolution_XE2X2, 1);
	self->leftSkip = 1;
	static const uint8_t COLORS[9] = { 0, 2, 4, 6, 8, 10, 12, 14, 0 };
	RECOIL_SetGtiaColors(self, COLORS, 0);
	uint8_t frame1[76160];
	RECOIL_DecodeAtari8Gr9(self, content, 9, contentStride, frame1, width << 1, width << 2, width << 1, height);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9 + 2 * frameLength, contentStride, frame1, 0);
	uint8_t frame2[76160];
	RECOIL_DecodeAtari8Gr10(self, content, 9 + frameLength, frame2, width << 1, width << 2, height);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9 + 2 * frameLength, contentStride, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeCin(RECOIL *self, uint8_t const *content, int contentLength)
{
	int height;
	switch (contentLength) {
	case 15360:
		RECOIL_SetGr15DefaultColors(self);
		height = 192;
		break;
	case 16004:
		RECOIL_SetBakPF012(self, content, 16000, 1);
		height = 200;
		break;
	case 16384:
		height = 192;
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1, 1);
	uint8_t frame1[64000];
	uint8_t frame2[64000];
	for (int y = 0; y < height; y++) {
		if (contentLength == 16384)
			RECOIL_SetBakPF012(self, content, 15360 + y, 256);
		RECOIL_DecodeAtari8Gr15(self, content, y * 40, 40, (y & 1) == 0 ? frame1 : frame2, y * 320, 320, 1);
	}
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 40 * height + 40, 80, frame1, 1);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 40 * height, 80, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeCci(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 24 || !RECOIL_IsStringAt(content, 0, "CIN 1.2 "))
		return false;
	CciStream rle;
	CciStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 8;
	rle.base.base.base.contentLength = contentLength;
	uint8_t unpacked[16384];
	if (!CciStream_UnpackGr15(&rle, unpacked, 0) || !CciStream_UnpackGr15(&rle, unpacked, 40))
		return false;
	rle.base.base.base.contentOffset += 4;
	rle.base.repeatCount = 0;
	if (!RleStream_UnpackColumns(&rle.base, unpacked, 7680, 40, 15360))
		return false;
	rle.base.base.base.contentOffset += 4;
	rle.base.repeatCount = 0;
	return RleStream_Unpack(&rle.base, unpacked, 15360, 1, 16384) && RECOIL_DecodeCin(self, unpacked, 16384);
}

static bool RECOIL_DecodeAgs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 17 || content[0] != 'A' || content[1] != 'G' || content[2] != 'S')
		return false;
	int width = content[4];
	int height = content[5] | content[6] << 8;
	if (contentLength != 16 + (width * height << 1))
		return false;
	switch (content[3]) {
	case 11:
		return RECOIL_DecodeMcppVariable(self, content, 16, 7, width << 3, height << 1);
	case 19:
		return RECOIL_DecodeGr9x4(self, content, 16, width << 3, height << 2);
	default:
		return false;
	}
}

static bool RECOIL_UnpackRip(const RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, uint8_t *unpacked, int unpackedLength)
{
	if (contentOffset + 304 > contentLength || !RECOIL_IsStringAt(content, contentOffset, "PCK"))
		return false;
	FanoTree lengthTree;
	FanoTree_Create(&lengthTree, content, contentOffset + 16, 64);
	FanoTree distanceTree;
	FanoTree_Create(&distanceTree, content, contentOffset + 16 + 32, 256);
	FanoTree literalTree;
	FanoTree_Create(&literalTree, content, contentOffset + 16 + 32 + 128, 256);
	BitStream bitStream;
	BitStream_Construct(&bitStream);
	bitStream.base.content = content;
	bitStream.base.contentOffset = contentOffset + 16 + 288;
	bitStream.base.contentLength = contentLength;
	for (int unpackedOffset = 0; unpackedOffset < unpackedLength;) {
		switch (bitStream.vtbl->readBit(&bitStream)) {
		case 0:
			;
			int literal = FanoTree_ReadCode(&literalTree, &bitStream);
			if (literal < 0)
				return false;
			unpacked[unpackedOffset++] = (uint8_t) literal;
			break;
		case 1:
			;
			int distance = FanoTree_ReadCode(&distanceTree, &bitStream);
			if (distance < 0)
				return false;
			distance += 2;
			int count = FanoTree_ReadCode(&lengthTree, &bitStream);
			if (count < 0)
				return false;
			count = FuInt_Min(count + 2, unpackedLength - unpackedOffset);
			if (!RECOIL_CopyPrevious(unpacked, unpackedOffset, distance, count))
				return false;
			unpackedOffset += count;
			if (unpackedOffset >= unpackedLength)
				return true;
			break;
		default:
			return false;
		}
	}
	return true;
}

static bool RECOIL_DecodeRip(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 34 || content[0] != 'R' || content[1] != 'I' || content[2] != 'P' || content[18] != 'T' || content[19] != ':')
		return false;
	int headerLength = content[11] | content[12] << 8;
	int contentStride = content[13];
	int height = content[15];
	int textLength = content[17];
	if (headerLength >= contentLength || contentStride == 0 || contentStride > 80 || (contentStride & 1) != 0 || height == 0 || height > 239 || 33 + textLength >= contentLength || content[20 + textLength] != 9 || !RECOIL_IsStringAt(content, 21 + textLength, "CM:"))
		return false;
	if (content[7] < 16)
		contentStride >>= 1;
	int unpackedLength = contentStride * height;
	if (content[7] == 48)
		unpackedLength += (height + 1) >> 1 << 3;
	uint8_t unpacked[20080] = { 0 };
	switch (content[9]) {
	case 0:
		if (headerLength + unpackedLength > contentLength)
			return false;
		memcpy(unpacked, content + headerLength, unpackedLength);
		break;
	case 1:
		RECOIL_UnpackRip(self, content, headerLength, contentLength, unpacked, unpackedLength);
		break;
	default:
		return false;
	}
	RECOIL_SetGtiaColors(self, content, 24 + textLength);
	contentStride = content[13] >> 1;
	int width = contentStride << 3;
	uint8_t frame1[76480];
	uint8_t frame2[76480];
	switch (content[7]) {
	case 14:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, contentStride, frame1, 0, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 15:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE1X1, 1);
		RECOIL_DecodeAtari8Gr8(self, unpacked, 0, frame1, 0, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 79:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE4X1, 1);
		RECOIL_DecodeAtari8Gr9(self, unpacked, 0, contentStride, frame1, 0, width, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 143:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE4X1, 1);
		self->leftSkip = 2;
		RECOIL_DecodeAtari8Gr10(self, unpacked, 0, frame1, 0, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 207:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE4X1, 1);
		RECOIL_DecodeAtari8Gr11(self, content, 0, frame1, 0, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 30:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, contentStride, frame1, 0, width, height);
		RECOIL_DecodeAtari8Gr15(self, unpacked, height * contentStride, contentStride, frame2, 0, width, height);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	case 16:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1, 1);
		RECOIL_SetBakPF012(self, content, 28 + textLength, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, contentStride << 1, frame1, 0, width << 1, height >> 1);
		RECOIL_SetBakPF012(self, content, 24 + textLength, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, contentStride, contentStride << 1, frame1, width, width << 1, height >> 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, height * contentStride, contentStride << 1, frame2, 0, width << 1, height >> 1);
		RECOIL_SetBakPF012(self, content, 28 + textLength, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, (height + 1) * contentStride, contentStride << 1, frame2, width, width << 1, height >> 1);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	case 32:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		RECOIL_DecodeAtari8Gr10(self, unpacked, 0, frame1, 0, width, height);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, unpacked, height * contentStride, contentStride, frame2, 0, width, width, height);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	case 48:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		self->gtiaColors[0] = 0;
		int colorsOffset = height * contentStride << 1;
		for (int y = 0; y < height; y += 2) {
			RECOIL_SetPM123PF0123Bak(self, unpacked, colorsOffset + (y << 2));
			RECOIL_DecodeAtari8Gr10(self, unpacked, y * contentStride, frame1, y * width, width, y + 1 < height ? 2 : 1);
		}
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, unpacked, height * contentStride, contentStride, frame2, 0, width, width, height);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	default:
		return false;
	}
}

static bool RECOIL_DecodeVzi(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 16000)
		return false;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1, 1);
	self->gtiaColors[8] = 0;
	self->leftSkip = -1;
	uint8_t frame1[64000];
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame1, 0, 320, 320, 200);
	self->leftSkip = 1;
	uint8_t frame2[64000];
	RECOIL_DecodeAtari8Gr9(self, content, 8000, 40, frame2, 0, 320, 320, 200);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeRmUnpacked(RECOIL *self, uint8_t const *content, int colorsOffset, int dliOffset, uint8_t const *bitmap, int mode, RECOILResolution resolution)
{
	bool dliPresent[192] = { false };
	for (int i = 0; i < 128; i++) {
		int y = content[dliOffset + i];
		switch (y) {
		case 0:
			break;
		case 1:
		case 2:
		case 4:
		case 5:
			return false;
		default:
			if (mode == 0) {
				if (y >= 101)
					return false;
				if (y == 3)
					y = 0;
				else
					y -= 5;
			}
			else {
				if (y == 100 || y == 101 || y >= 198)
					return false;
				if (y == 3)
					y = 1;
				else if (y < 100)
					y -= 4;
				else
					y -= 6;
			}
			dliPresent[y] = true;
			break;
		}
	}
	RECOIL_SetSize(self, 320, 192, resolution, 1);
	if (mode == 2)
		self->leftSkip = 2;
	if (mode == 1)
		self->gtiaColors[8] = (uint8_t) (content[colorsOffset + 8] & 240);
	else
		RECOIL_SetGtiaColors(self, content, colorsOffset);
	int height = mode == 0 ? 96 : 192;
	uint8_t frame[61440];
	for (int y = 0; y < height; y++) {
		switch (mode) {
		case 0:
			RECOIL_DecodeAtari8Gr7(self, bitmap, y * 40, frame, y * 640, 1);
			break;
		case 1:
			RECOIL_DecodeAtari8Gr9(self, bitmap, y * 40, 40, frame, y * 320, 320, 320, 1);
			break;
		case 2:
			RECOIL_DecodeAtari8Gr10(self, bitmap, y * 40, frame, y * 320, 320, 1);
			break;
		case 3:
			RECOIL_DecodeAtari8Gr11(self, bitmap, y * 40, frame, y * 320, 320, 1);
			break;
		case 4:
			RECOIL_DecodeAtari8Gr15(self, bitmap, y * 40, 40, frame, y * 320, 320, 1);
			break;
		default:
			abort();
		}
		if (dliPresent[y]) {
			int vcount = mode == 0 ? 16 + y : 16 + ((y - 1) >> 1);
			int reg = content[dliOffset + 128 + vcount];
			if (reg < 9)
				RECOIL_SetGtiaColor(self, reg, content[dliOffset + 256 + vcount]);
			else if (reg != 128)
				return false;
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeRm(RECOIL *self, uint8_t const *content, int contentLength, int mode, RECOILResolution resolution)
{
	XeKoalaStream rle;
	XeKoalaStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength - 464;
	if (XeKoalaStream_UnpackWrapped(&rle, mode == 0 ? 3840 : 7680)) {
		return RECOIL_DecodeRmUnpacked(self, content, contentLength - 464, contentLength - 384, rle.unpacked, mode, resolution);
	}
	else if (contentLength == 8192) {
		return RECOIL_DecodeRmUnpacked(self, content, 7680, 7808, content, mode, resolution);
	}
	return false;
}

static bool RECOIL_DecodeAgp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 7690)
		return false;
	RECOIL_SetGtiaColors(self, content, 1);
	uint8_t frame[61440];
	switch (content[0]) {
	case 8:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1, 1);
		RECOIL_DecodeAtari8Gr8(self, content, 10, frame, 0, 192);
		break;
	case 9:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1, 1);
		RECOIL_DecodeAtari8Gr9(self, content, 10, 40, frame, 0, 320, 320, 192);
		break;
	case 10:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1, 1);
		self->leftSkip = 2;
		RECOIL_DecodeAtari8Gr10(self, content, 10, frame, 0, 320, 192);
		break;
	case 11:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1, 1);
		RECOIL_DecodeAtari8Gr11(self, content, 10, frame, 0, 320, 192);
		break;
	case 15:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
		RECOIL_DecodeAtari8Gr15(self, content, 10, 40, frame, 0, 320, 192);
		break;
	default:
		return false;
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeShc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 17920)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1, 1);
	uint8_t frame1[61440];
	uint8_t frame2[61440];
	int col1 = 15360;
	int col2 = 16640;
	for (int y = 0; y < 192; y++) {
		for (int x = 0; x < 320; x++) {
			int i = 320 * y + x;
			int bit = ~x & 7;
			switch (x) {
			case 94:
			case 166:
			case 214:
			case 262:
			case 306:
				col1++;
				break;
			case 46:
			case 142:
			case 190:
			case 238:
			case 286:
				col2++;
				break;
			default:
				break;
			}
			frame1[i] = (uint8_t) (content[col1] & ((content[i >> 3] >> bit & 1) != 0 ? 240 : 254));
			frame2[i] = (uint8_t) (content[col2] & ((content[7680 + (i >> 3)] >> bit & 1) != 0 ? 240 : 254));
		}
		col1++;
		col2++;
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeMgp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 3845)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X2, 1);
	uint8_t frame[61440];
	RECOIL_SetPF0123Bak(self, content, 0);
	int rainbow = content[5];
	uint8_t bitmap[3840];
	memcpy(bitmap, content + 6, 3839);
	bitmap[3839] = 0;
	for (int y = 0; y < 96; y++) {
		if (rainbow < 4) {
			self->gtiaColors[rainbow == 0 ? 8 : 3 + rainbow] = (uint8_t) ((16 + y) & 254);
		}
		RECOIL_DecodeAtari8Gr7(self, bitmap, y * 40, frame, y * 640, 1);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGad(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 4325)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X2, 1);
	uint8_t frame[61440];
	RECOIL_SetPF0123Bak(self, content, 0);
	for (int y = 0; y < 96; y++) {
		RECOIL_DecodeAtari8Gr7(self, content, 5 + y * 40, frame, y * 640, 1);
		if (content[3845 + y] < 128) {
			for (int i = 0; i < 4; i++)
				self->gtiaColors[i == 3 ? 8 : 4 + i] = (uint8_t) (content[3941 + i * 96 + y] & 254);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeFwa(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 7960 || content[0] != 254 || content[1] != 254 || content[6] != 112 || content[7] != 112 || content[8] != 112 || content[11] != 80 || content[115] != 96 || content[205] != 65 || 7960 + content[7958] + (content[7959] << 8) != contentLength)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	RECOIL_SetBakPF012(self, content, 2, 1);
	int dlOffset = 9;
	int dliOffset = 7960;
	for (int y = 0; y < 192; y++) {
		RECOIL_DecodeAtari8Gr15(self, content, 262 + 40 * y + (y >= 102 ? 16 : 0), 40, frame, y * 320, 320, 1);
		int dlInstr = content[dlOffset];
		if (dlOffset == 9 || dlOffset == 113) {
			if ((dlInstr & 127) != 78 || content[dlOffset + 1] != 0)
				return false;
			dlOffset += 3;
		}
		else {
			if ((dlInstr & 127) != 14)
				return false;
			dlOffset++;
		}
		if (dlInstr >= 128) {
			if (dliOffset + 14 > contentLength || content[dliOffset] != 72 || content[dliOffset + 1] != 138 || content[dliOffset + 2] != 72 || content[dliOffset + 3] != 169 || content[dliOffset + 5] != 141 || content[dliOffset + 6] != 10 || content[dliOffset + 7] != 212)
				return false;
			int a = content[dliOffset + 4];
			dliOffset += 8;
			while (content[dliOffset] != 32) {
				switch (content[dliOffset]) {
				case 169:
					a = content[dliOffset + 1];
					dliOffset += 2;
					break;
				case 141:
					if (content[dliOffset + 2] != 208)
						return false;
					int lo = content[dliOffset + 1];
					switch (lo) {
					case 22:
					case 23:
					case 24:
					case 26:
						self->gtiaColors[lo - 18] = (uint8_t) (a & 254);
						break;
					default:
						return false;
					}
					dliOffset += 3;
					break;
				default:
					return false;
				}
				if (dliOffset + 3 > contentLength)
					return false;
			}
			if (content[dliOffset + 1] != 202 || content[dliOffset + 2] != 6)
				return false;
			dliOffset += 3;
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAtari8Font(RECOIL *self, uint8_t const *characters, uint8_t const *font, int fontOffset)
{
	RECOIL_SetSize(self, 256, 32, RECOILResolution_XE1X1, 1);
	uint8_t frame[8192];
	RECOIL_DecodeAtari8Gr0(self, characters, 0, 32, font, fontOffset, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAtari8Fnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	int contentOffset;
	switch (contentLength) {
	case 1024:
	case 1025:
	case 1026:
		contentOffset = 0;
		break;
	case 1030:
		if (RECOIL_ParseAtari8ExecutableHeader(content, 0) != 1024)
			return false;
		contentOffset = 6;
		break;
	default:
		return false;
	}
	return RECOIL_DecodeAtari8Font(self, NULL, content, contentOffset);
}

static bool RECOIL_DecodeF80(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 512)
		return false;
	RECOIL_SetSize(self, 128, 32, RECOILResolution_XE1X1, 1);
	uint8_t frame[4096];
	RECOIL_DecodeAtari8Gr0(self, NULL, 0, 16, content, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeSxs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1030 || RECOIL_ParseAtari8ExecutableHeader(content, 0) != 1024)
		return false;
	uint8_t characters[128];
	for (int i = 0; i < 128; i++)
		characters[i] = (uint8_t) ((i & 65) | (i >> 4 & 2) | (i & 30) << 1);
	return RECOIL_DecodeAtari8Font(self, characters, content, 6);
}

static bool RECOIL_DecodeFn2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 2048)
		return false;
	RECOIL_SetSize(self, 256, 64, RECOILResolution_XE1X1, 1);
	self->gtiaColors[6] = 0;
	self->gtiaColors[5] = 14;
	uint8_t frame[16384];
	for (int y = 0; y < 64; y += 8)
		RECOIL_DecodeAtari8Gr0Line(self, NULL, y >> 4 << 5, content, (y & 8) << 7, frame, y << 8, 8);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeOdf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1280)
		return false;
	RECOIL_SetSize(self, 256, 40, RECOILResolution_XE1X1, 1);
	uint8_t frame[10240];
	for (int y = 0; y < 40; y++) {
		for (int x = 0; x < 256; x++)
			frame[(y << 8) + x] = (uint8_t) ((content[y / 10 * 320 + (x >> 3) * 10 + y % 10] >> (~x & 7) & 1) == 0 ? 0 : 14);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeNlq(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 379 || !RECOIL_IsStringAt(content, 0, "DAISY-DOT NLQ FONT") || content[18] != 155)
		return false;
	RECOIL_SetSize(self, 320, 96, RECOILResolution_XE1X1, 1);
	uint8_t frame[30720] = { 0 };
	int contentOffset = 19;
	for (int i = 0; i < 91; i++) {
		if (contentOffset >= contentLength)
			return false;
		int width = content[contentOffset];
		if (width == 0 || width > 19)
			return false;
		int nextContentOffset = contentOffset + (width + 1) * 2;
		if (nextContentOffset > contentLength || content[nextContentOffset - 1] != 155)
			return false;
		int c = i < 64 ? i : i < 90 ? i + 1 : 92;
		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < width; x++) {
				int b = content[contentOffset + 1 + (y & 1) * width + x] >> (7 - (y >> 1)) & 1;
				frame[((c & 240) | y) * 320 + (c & 15) * 20 + x] = (uint8_t) (b == 0 ? 0 : 14);
			}
		}
		contentOffset = nextContentOffset;
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGr1(RECOIL *self, uint8_t const *content, int contentLength, int doubleHeight)
{
	int charsLength = 480 >> doubleHeight;
	switch (contentLength - charsLength) {
	case 0:
		RECOIL_SetXeOsDefaultColors(self);
		break;
	case 5:
		RECOIL_SetBakPF0123(self, content, charsLength);
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 320, 192, doubleHeight == 0 ? RECOILResolution_XE2X1 : RECOILResolution_XE2X2, 1);
	uint8_t frame[61440];
	uint8_t const *font = FuResource_atari8_fnt;
	for (int offset = 0; offset < charsLength; offset += 20)
		RECOIL_DecodeAtari8Gr1Line(self, content, offset, font, 0, frame, offset << (7 + doubleHeight), doubleHeight);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAcs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 1028)
		return false;
	RECOIL_SetBakPF012(self, content, 0, 1);
	RECOIL_SetSize(self, 128, 64, RECOILResolution_XE2X1, 1);
	uint8_t frame[8192];
	for (int y = 0; y < 8; y++)
		RECOIL_DecodeAtari8Gr12Line(self, NULL, 0, content, 4 + (y << 7), frame, y << 10, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeJgp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 2054 || RECOIL_ParseAtari8ExecutableHeader(content, 0) != 2048)
		return false;
	RECOIL_SetGr15DefaultColors(self);
	RECOIL_SetSize(self, 256, 64, RECOILResolution_XE2X1, 1);
	uint8_t frame[16384];
	for (int y = 0; y < 8; y++)
		RECOIL_DecodeAtari8Gr12Line(self, NULL, 0, content, 6 + ((y & 6) << 7) + ((y & 1) << 10), frame, y << 11, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeLeo(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 2580)
		return false;
	RECOIL_SetSize(self, 256, 64, RECOILResolution_XE2X1, 1);
	uint8_t frame[16384];
	uint8_t characters[32];
	RECOIL_SetPF0123Bak(self, content, 2560);
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 32; x++)
			characters[x] = content[2048 + ((x & 1) << 7) + ((y & 1) << 6) + ((y & 6) << 3) + (x >> 1)];
		RECOIL_DecodeAtari8Gr12Line(self, characters, 0, content, (y & 1) << 10, frame, y << 11, 0);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAtari8Sif(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 2048)
		return false;
	RECOIL_SetSize(self, 256, 32, RECOILResolution_XE2X1, 1);
	self->gtiaColors[4] = 76;
	self->gtiaColors[5] = 204;
	self->gtiaColors[6] = 140;
	self->gtiaColors[8] = 0;
	uint8_t frame1[8192];
	uint8_t frame2[8192];
	for (int y = 0; y < 4; y++) {
		RECOIL_DecodeAtari8Gr12Line(self, NULL, 0, content, y << 8, frame1, y << 11, 0);
		RECOIL_DecodeAtari8Gr12Line(self, NULL, 0, content, 1024 + (y << 8), frame2, y << 11, 0);
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeDlm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 256)
		return false;
	uint8_t characters[176];
	for (int y = 0; y < 16; y++)
		for (int x = 0; x < 11; x++)
			characters[y * 11 + x] = (uint8_t) RECOIL_ToAtari8Char(content[y * 16 + 5 + x]);
	RECOIL_SetSize(self, 88, 128, RECOILResolution_XE1X1, 1);
	uint8_t frame[11264];
	RECOIL_DecodeAtari8Gr0(self, characters, 0, 11, FuResource_atari8_fnt, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static void RECOIL_DecodeAtari8Gr0Screen(RECOIL *self, uint8_t const *content, uint8_t const *font)
{
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1, 1);
	uint8_t frame[61440];
	RECOIL_DecodeAtari8Gr0(self, content, 0, 40, font, 0, frame);
	RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGr0(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 960 && contentLength != 1024)
		return false;
	RECOIL_DecodeAtari8Gr0Screen(self, content, FuResource_atari8_fnt);
	return true;
}

static bool RECOIL_DecodeSge(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 960)
		return false;
	uint8_t font[1024];
	memcpy(font, FuResource_atari8_fnt, 1024);
	for (int i = 0; i < 4; i++) {
		font[1004 + i] = font[728 + i] = 15;
		font[1000 + i] = font[732 + i] = 240;
	}
	RECOIL_DecodeAtari8Gr0Screen(self, content, font);
	return true;
}

static bool RECOIL_DecodeAn2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 3)
		return false;
	int columns = content[0] + 1;
	int rows = content[1] + 1;
	if (columns > 40 || rows > 24 || contentLength != 2 + columns * rows)
		return false;
	RECOIL_SetSize(self, columns << 3, rows << 3, RECOILResolution_XE1X1, 1);
	uint8_t frame[61440];
	RECOIL_DecodeAtari8Gr0(self, content, 2, columns, FuResource_atari8_fnt, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAn4(RECOIL *self, uint8_t const *content, int contentLength, int doubleHeight)
{
	if (contentLength < 8)
		return false;
	int columns;
	int rows;
	int charactersOffset;
	if (contentLength << doubleHeight == 960) {
		columns = 40;
		rows = 24 >> doubleHeight;
		RECOIL_SetXeOsDefaultColors(self);
		charactersOffset = 0;
	}
	else {
		columns = content[0] + 1;
		rows = content[1] + 1;
		if (columns > 40 || rows << doubleHeight > 24 || contentLength != 7 + columns * rows)
			return false;
		RECOIL_SetBakPF0123(self, content, 2);
		charactersOffset = 7;
	}
	if (doubleHeight == 0)
		RECOIL_SetSize(self, columns << 3, rows << 3, RECOILResolution_XE2X1, 1);
	else
		RECOIL_SetSize(self, columns << 3, rows << 4, RECOILResolution_XE2X2, 1);
	uint8_t frame[61440];
	uint8_t const *font = FuResource_atari8_fnt;
	for (int y = 0; y < rows; y++)
		RECOIL_DecodeAtari8Gr12Line(self, content, charactersOffset + y * columns, font, 0, frame, y * columns << (6 + doubleHeight), doubleHeight);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeTl4(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 11)
		return false;
	int columns = content[0];
	int rows = content[1];
	if (columns == 0 || columns > 4 || rows == 0 || rows > 5 || contentLength != 2 + columns * rows * 9)
		return false;
	RECOIL_SetSize(self, columns << 3, rows << 3, RECOILResolution_XE2X1, 1);
	uint8_t frame[1280];
	for (int y = 0; y < rows << 3; y++) {
		for (int x = 0; x < columns << 3; x++) {
			int offset = 2 + ((y >> 3) * columns + (x >> 3)) * 9;
			int c;
			switch (content[offset + (y & 7)] >> (~x & 6) & 3) {
			case 1:
				c = 40;
				break;
			case 2:
				c = 202;
				break;
			case 3:
				c = content[offset + 8] == 0 ? 148 : 70;
				break;
			default:
				c = 0;
				break;
			}
			frame[(y * columns << 3) + x] = (uint8_t) c;
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAsciiArtEditor(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength <= 0 || content[contentLength - 1] != 155)
		return false;
	uint8_t characters[1536];
	int columns = 1;
	int x = 0;
	int y = 0;
	for (int contentOffset = 0; contentOffset < contentLength; contentOffset++) {
		int ch = content[contentOffset];
		if (y >= 24)
			return false;
		if (ch == 155) {
			if (columns < x)
				columns = x;
			while (x < 64)
				characters[y * 64 + x++] = 0;
			x = 0;
			y++;
		}
		else {
			if (x >= 64)
				return false;
			characters[y * 64 + x++] = (uint8_t) RECOIL_ToAtari8Char(ch);
		}
	}
	RECOIL_SetSize(self, columns << 3, y << 3, RECOILResolution_XE1X1, 1);
	uint8_t frame[98304];
	RECOIL_DecodeAtari8Gr0(self, characters, 0, 64, FuResource_atari8_fnt, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeAll(RECOIL *self, uint8_t const *content, int contentLength)
{
	if ((contentLength & 1023) != 989)
		return false;
	RECOIL_SetPF0123Bak(self, content, contentLength - 5);
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	for (int y = 0; y < 24; y++) {
		int fontOffset = 24 + (content[y] << 10);
		if (fontOffset >= contentLength - 965)
			return false;
		RECOIL_DecodeAtari8Gr12Line(self, content, contentLength - 965 + y * 40, content, fontOffset, frame, y * 2560, 0);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeKpr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 11 || RECOIL_GetAtari8ExecutableOffset(content, contentLength) != 6)
		return false;
	int frames = content[8];
	int cols = content[9];
	int rows = content[10];
	int tiles = frames * cols * rows;
	if (contentLength < 11 + tiles || !RECOIL_SetSize(self, frames * cols << 3, rows << 3, RECOILResolution_XE2X1, 1))
		return false;
	int pixelsOffset = 0;
	for (int y = 0; y < rows << 3; y++) {
		for (int f = 0; f < frames; f++) {
			for (int x = 0; x < cols << 3; x++) {
				int c = content[11 + (f * rows + (y >> 3)) * cols + (x >> 3)];
				c = 11 + tiles + (c << 3) + (y & 7);
				if (c >= contentLength)
					return false;
				c = content[c] >> (~x & 6) & 3;
				self->pixels[pixelsOffset++] = self->atari8Palette[c << 2];
			}
		}
	}
	return true;
}

static bool RECOIL_DecodeEnvisionCommon(RECOIL *self, uint8_t const *content, int mode, int columns, int rows, int charactersOffset, int const *fontId2Offset)
{
	int charWidth;
	int charHeight;
	RECOILResolution resolution;
	switch (mode) {
	case 2:
		charWidth = 8;
		charHeight = 8;
		resolution = RECOILResolution_XE1X1;
		break;
	case 3:
		charWidth = 8;
		charHeight = 10;
		resolution = RECOILResolution_XE1X1;
		break;
	case 4:
		charWidth = 8;
		charHeight = 8;
		resolution = RECOILResolution_XE2X1;
		break;
	case 5:
		charWidth = 8;
		charHeight = 16;
		resolution = RECOILResolution_XE2X2;
		break;
	case 6:
		charWidth = 16;
		charHeight = 8;
		resolution = RECOILResolution_XE2X1;
		break;
	case 7:
		charWidth = 16;
		charHeight = 16;
		resolution = RECOILResolution_XE2X2;
		break;
	default:
		return false;
	}
	if (!RECOIL_SetSize(self, columns * charWidth, rows * charHeight, resolution, 1))
		return false;
	uint8_t *frame = (uint8_t *) malloc(self->width * self->height * sizeof(uint8_t));
	for (int row = 0; row < rows; row++) {
		int fontOffset;
		if (fontId2Offset != NULL) {
			fontOffset = fontId2Offset[content[8 + columns * rows + 256 + row]];
			if (fontOffset == 0) {
				free(frame);
				return false;
			}
		}
		else {
			fontOffset = 10 + columns * rows;
		}
		int frameOffset = row * charHeight * self->width;
		switch (mode >> 1) {
		case 1:
			RECOIL_DecodeAtari8Gr0Line(self, content, charactersOffset, content, fontOffset, frame, frameOffset, charHeight);
			break;
		case 2:
			RECOIL_DecodeAtari8Gr12Line(self, content, charactersOffset, content, fontOffset, frame, frameOffset, mode & 1);
			break;
		case 3:
			RECOIL_DecodeAtari8Gr1Line(self, content, charactersOffset, content, fontOffset, frame, frameOffset, mode & 1);
			break;
		default:
			abort();
		}
		charactersOffset += columns;
	}
	RECOIL_ApplyAtari8Palette(self, frame);
	free(frame);
	return true;
}

static bool RECOIL_DecodeEnvision(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1505)
		return false;
	int columns = content[1] + 1;
	int rows = content[2] + 1;
	if (rows > 204)
		return false;
	int fontOffset = 8 + columns * rows + 463;
	if (contentLength < fontOffset || contentLength != fontOffset + content[fontOffset - 1] * 1033)
		return false;
	int fontId2Offset[256] = { 0 };
	for (; fontOffset < contentLength; fontOffset += 1033)
		fontId2Offset[content[fontOffset]] = fontOffset + 1 + 8;
	RECOIL_SetPF0123Bak(self, content, 3);
	return RECOIL_DecodeEnvisionCommon(self, content, content[0] & 127, columns, rows, 8, fontId2Offset);
}

static bool RECOIL_DecodeEnvisionPC(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1035 || content[2] >= 128)
		return false;
	int columns = content[1] | content[2] << 8;
	int rows = content[3] | content[4] << 8;
	int contentOffset = 10 + columns * rows + 1024;
	while (contentOffset < contentLength) {
		switch (content[contentOffset++]) {
		case 0:
			break;
		case 1:
			if (contentOffset + 6 >= contentLength || content[contentOffset + 1] >= 5 || content[contentOffset + 3] >= 5 || content[contentOffset + 5] >= 5)
				return false;
			contentOffset += (content[contentOffset] + (content[contentOffset + 1] << 8)) * (content[contentOffset + 2] + (content[contentOffset + 3] << 8)) * (content[contentOffset + 4] + (content[contentOffset + 5] << 8) + 1);
			break;
		case 2:
			contentOffset += columns * rows;
			break;
		case 3:
			contentOffset += 1027;
			break;
		default:
			return false;
		}
	}
	if (contentOffset > contentLength)
		return false;
	RECOIL_SetBakPF0123(self, content, 5);
	return RECOIL_DecodeEnvisionCommon(self, content, content[0], columns, rows, 10, NULL);
}

static bool RECOIL_DecodeMcs(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 10185)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	for (int y = 0; y < 192; y++) {
		int fontOffset = 9 + (y / 24 << 10);
		for (int x = 0; x < 320; x++) {
			int ch = content[8201 + (y >> 3) * 40 + (x >> 3)];
			int c;
			switch (content[fontOffset + ((ch & 127) << 3) + (y & 7)] >> (~x & 6) & 3) {
			case 0:
				c = x / 80;
				int pmgBit = (x >> 3) % 10;
				int pmgOffset;
				if (pmgBit < 8) {
					pmgBit = 7 - pmgBit;
					pmgOffset = 9305 + (c << 7);
				}
				else {
					pmgBit = c << 1 | (pmgBit ^ 9);
					pmgOffset = 9177;
				}
				if ((content[pmgOffset + (y >> 1)] >> pmgBit & 1) == 0)
					c = 8;
				break;
			case 1:
				c = 4;
				break;
			case 2:
				c = 5;
				break;
			default:
				c = 6 + (ch >> 7);
				break;
			}
			frame[y * 320 + x] = (uint8_t) (content[c] & 254);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static int RECOIL_Gr12GtiaNibbleToGr8(int nibble, int ch, bool gtia10)
{
	switch (nibble) {
	case 0:
	case 1:
	case 4:
	case 5:
		return 0;
	case 2:
	case 6:
		return 1;
	case 3:
	case 7:
		return (ch & 128) == 0 ? 2 : 3;
	case 8:
		return gtia10 ? 8 : 4;
	case 9:
		return 4;
	case 10:
		return 5;
	case 11:
		return (ch & 128) == 0 ? 6 : 7;
	case 12:
		return gtia10 || (ch & 128) == 0 ? 8 : 12;
	case 13:
		return (ch & 128) == 0 ? 8 : 12;
	case 14:
		return (ch & 128) == 0 ? 9 : 13;
	case 15:
		return (ch & 128) == 0 ? 10 : 15;
	default:
		return 0;
	}
}

static int RECOIL_Gr12GtiaByteToGr8(int b, int ch, bool gtia10)
{
	return RECOIL_Gr12GtiaNibbleToGr8(b >> 4, ch, gtia10) << 4 | RECOIL_Gr12GtiaNibbleToGr8(b & 15, ch, gtia10);
}

static void RECOIL_DecodeIceFrame(const RECOIL *self, uint8_t const *content, int charactersOffset, int fontOffset, uint8_t *frame, IceFrameMode mode)
{
	int doubleLine;
	switch (mode) {
	case IceFrameMode_GR13_GTIA9:
	case IceFrameMode_GR13_GTIA10:
	case IceFrameMode_GR13_GTIA11:
		doubleLine = 1;
		break;
	default:
		doubleLine = 0;
		break;
	}
	int frameOffset = 0;
	uint8_t bitmap[40];
	for (int y = 0; y < self->height; y++) {
		for (int col = 0; col < self->width >> 3; col++) {
			int ch;
			switch (charactersOffset) {
			case -1:
				;
				static const uint8_t ROW2CHAR1[16] = { 64, 0, 32, 96, 192, 128, 160, 224, 64, 0, 32, 96, 192, 128, 160, 224 };
				ch = ROW2CHAR1[y >> (3 + doubleLine)] + col;
				break;
			case -2:
				;
				static const uint8_t ROW2CHAR2[16] = { 64, 0, 32, 96, 192, 128, 160, 224, 192, 128, 160, 224, 64, 0, 32, 96 };
				ch = ROW2CHAR2[y >> (3 + doubleLine)] + col;
				break;
			default:
				ch = (y / 24 << 8) + content[charactersOffset + (y >> 3) * 40 + col];
				break;
			}
			int b = content[fontOffset + ((ch & ~128) << 3) + (y >> doubleLine & 7)];
			switch (mode) {
			case IceFrameMode_GR0:
			case IceFrameMode_GR0_GTIA9:
			case IceFrameMode_GR0_GTIA10:
			case IceFrameMode_GR0_GTIA11:
				if (charactersOffset < 0 && (ch & 128) != 0)
					b ^= 255;
				bitmap[col] = (uint8_t) b;
				break;
			case IceFrameMode_GR12:
				for (int x = col == 0 ? self->leftSkip : 0; x < 8; x++) {
					int c = b >> (~x & 6) & 3;
					int gr12Registers = (ch & 128) == 0 ? 25928 : 30024;
					frame[frameOffset + (col << 3) + x - self->leftSkip] = self->gtiaColors[gr12Registers >> (c << 2) & 15];
				}
				break;
			case IceFrameMode_GR12_GTIA9:
			case IceFrameMode_GR12_GTIA11:
			case IceFrameMode_GR13_GTIA9:
			case IceFrameMode_GR13_GTIA11:
				bitmap[col] = (uint8_t) RECOIL_Gr12GtiaByteToGr8(b, ch, false);
				break;
			case IceFrameMode_GR12_GTIA10:
			case IceFrameMode_GR13_GTIA10:
				bitmap[col] = (uint8_t) RECOIL_Gr12GtiaByteToGr8(b, ch, true);
				break;
			}
		}
		switch (mode) {
		case IceFrameMode_GR0:
			RECOIL_DecodeAtari8Gr8(self, bitmap, 0, frame, frameOffset, 1);
			break;
		case IceFrameMode_GR12:
			for (int x = self->width; x < self->width + self->leftSkip; x++)
				frame[frameOffset + x] = self->gtiaColors[8];
			break;
		case IceFrameMode_GR0_GTIA9:
		case IceFrameMode_GR12_GTIA9:
		case IceFrameMode_GR13_GTIA9:
			RECOIL_DecodeAtari8Gr9(self, bitmap, 0, 0, frame, frameOffset, 0, self->width, 1);
			break;
		case IceFrameMode_GR0_GTIA10:
		case IceFrameMode_GR12_GTIA10:
		case IceFrameMode_GR13_GTIA10:
			RECOIL_DecodeAtari8Gr10(self, bitmap, 0, frame, frameOffset, 0, 1);
			break;
		case IceFrameMode_GR0_GTIA11:
		case IceFrameMode_GR12_GTIA11:
		case IceFrameMode_GR13_GTIA11:
			RECOIL_DecodeAtari8Gr11(self, bitmap, 0, frame, frameOffset, 0, 1);
			break;
		}
		frameOffset += self->width;
	}
}

static bool RECOIL_VerifyIce(RECOIL *self, uint8_t const *content, int contentLength, bool font, int fontLength, int imageLength, RECOILResolution resolution)
{
	if (font) {
		if (contentLength != fontLength)
			return false;
		RECOIL_SetSize(self, 256, 128, resolution, 1);
	}
	else {
		if (contentLength != imageLength || content[0] != 1)
			return false;
		RECOIL_SetSize(self, 320, 192, resolution, 1);
	}
	return true;
}

static void RECOIL_DecodeIce20Frame(const RECOIL *self, uint8_t const *content, bool second, int fontOffset, uint8_t *frame, int mode)
{
	uint8_t bitmap[32];
	for (int y = 0; y < 288; y++) {
		int row = y >> 5;
		int c = (second ? row / 3 : row % 3) + 1;
		for (int col = 0; col < 32; col++) {
			int ch = ((y & 24) << 1) + (col >> 1);
			int b = content[fontOffset + (ch << 3) + (y & 7)];
			b = (col & 1) == 0 ? b >> 4 : b & 15;
			b = ((b & 8) << 3 | (b & 4) << 2 | (b & 2) << 1 | (b & 1)) * c;
			if (mode == 10) {
				if ((b & 112) == 64)
					b = 128 + (b & 15);
				if ((b & 7) == 4)
					b = (b & 240) + 8;
			}
			bitmap[col] = (uint8_t) b;
		}
		switch (mode) {
		case 9:
			RECOIL_DecodeAtari8Gr9(self, bitmap, 0, 0, frame, y << 8, 0, 256, 1);
			break;
		case 10:
			RECOIL_DecodeAtari8Gr10(self, bitmap, 0, frame, y << 8, 0, 1);
			break;
		case 11:
			RECOIL_DecodeAtari8Gr11(self, bitmap, 0, frame, y << 8, 0, 1);
			break;
		default:
			abort();
		}
	}
}

static bool RECOIL_DecodeAtari8Ice(RECOIL *self, uint8_t const *content, int contentLength, bool font, int mode)
{
	uint8_t frame1[73728];
	uint8_t frame2[73728];
	switch (mode) {
	case 0:
		if (contentLength != 2053)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1, 1);
		self->gtiaColors[5] = (uint8_t) (content[1] & 254);
		self->gtiaColors[6] = (uint8_t) (content[3] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 5, frame1, IceFrameMode_GR0);
		self->gtiaColors[5] = (uint8_t) (content[2] & 254);
		self->gtiaColors[6] = (uint8_t) (content[4] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1029, frame2, IceFrameMode_GR0);
		break;
	case 1:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2054, 18310, RECOILResolution_XE2X1))
			return false;
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16390, 6, frame1, IceFrameMode_GR12);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 17350, 1030, frame2, IceFrameMode_GR12);
		break;
	case 2:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2058, 18314, RECOILResolution_XE2X1))
			return false;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_SetPF0123Even(self, content, 2);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16394, 10, frame1, IceFrameMode_GR12);
		RECOIL_SetPF0123Even(self, content, 3);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 17354, 1034, frame2, IceFrameMode_GR12);
		break;
	case 3:
		if (font) {
			if (contentLength != 2055)
				return false;
			RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1, 1);
		}
		else {
			if (contentLength != 17351 || content[0] != 3)
				return false;
			RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1, 1);
		}
		RECOIL_SetPF21(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16391, 7, frame1, IceFrameMode_GR0);
		RECOIL_SetBakPF0123(self, content, 2);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16391, 1031, frame2, IceFrameMode_GR12);
		break;
	case 4:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1, 1);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR0_GTIA10);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 5:
		if (contentLength != 2065 && contentLength != 2066)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1, 1);
		self->leftSkip = 2;
		self->gtiaColors[0] = (uint8_t) (content[1] & 254);
		for (int i = 0; i < 8; i++)
			RECOIL_SetGtiaColor(self, i + 1, content[2 + i * 2]);
		if (contentLength == 2065) {
			RECOIL_DecodeIceFrame(self, content, -1, 17, frame1, IceFrameMode_GR0_GTIA10);
			for (int i = 0; i < 7; i++)
				RECOIL_SetGtiaColor(self, i + 1, content[3 + i * 2]);
			RECOIL_DecodeIceFrame(self, content, -2, 1041, frame2, IceFrameMode_GR0_GTIA10);
		}
		else {
			RECOIL_DecodeIceFrame(self, content, -1, 18, frame1, IceFrameMode_GR0_GTIA10);
			for (int i = 0; i < 8; i++)
				RECOIL_SetGtiaColor(self, i + 1, content[3 + i * 2]);
			RECOIL_DecodeIceFrame(self, content, -2, 1042, frame2, IceFrameMode_GR0_GTIA10);
		}
		break;
	case 6:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0_GTIA9);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA9);
		break;
	case 7:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0_GTIA11);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA11);
		break;
	case 8:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR0_GTIA9);
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 9:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR0_GTIA11);
		self->gtiaColors[0] = 0;
		RECOIL_SetPM123PF0123Bak(self, content, 2);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 10:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0_GTIA9);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA11);
		break;
	case 11:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1, 1);
		self->gtiaColors[6] = 0;
		self->gtiaColors[5] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA11);
		break;
	case 12:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1, 1);
		RECOIL_SetPF21(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA9);
		break;
	case 13:
		if (contentLength != 2059)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1, 1);
		RECOIL_SetPF21(self, content, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 11, frame1, IceFrameMode_GR0);
		self->leftSkip = 2;
		self->gtiaColors[0] = (uint8_t) (content[1] & 254);
		RECOIL_SetPM123PF0123Bak(self, content, 3);
		RECOIL_DecodeIceFrame(self, content, -2, 1035, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 14:
		if (contentLength != 2054)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1, 1);
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1030, frame2, IceFrameMode_GR12_GTIA11);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeIceFrame(self, content, -1, 6, frame1, IceFrameMode_GR12);
		break;
	case 15:
		if (contentLength != 2054)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1, 1);
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 6, frame1, IceFrameMode_GR12);
		RECOIL_DecodeIceFrame(self, content, -2, 1030, frame2, IceFrameMode_GR12_GTIA9);
		break;
	case 16:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1, 1);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR12_GTIA10);
		self->leftSkip = 0;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR12);
		break;
	case 17:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2054, 17350, RECOILResolution_XE2X1))
			return false;
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16390, 1030, frame2, IceFrameMode_GR0_GTIA11);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16390, 6, frame1, IceFrameMode_GR12);
		break;
	case 18:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2054, 17350, RECOILResolution_XE2X1))
			return false;
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16390, 6, frame1, IceFrameMode_GR12);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16390, 1030, frame2, IceFrameMode_GR0_GTIA9);
		break;
	case 19:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2058, 17354, RECOILResolution_XE2X1))
			return false;
		RECOIL_SetPF0123Bak(self, content, 5);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16394, 10, frame1, IceFrameMode_GR12);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16394, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 22:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE4X2, 1);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR13_GTIA10);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR13_GTIA10);
		break;
	case 23:
		if (contentLength != 2065)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE4X2, 1);
		self->leftSkip = 2;
		self->gtiaColors[0] = (uint8_t) (content[1] & 254);
		for (int i = 0; i < 8; i++)
			RECOIL_SetGtiaColor(self, i + 1, content[2 + i * 2]);
		RECOIL_DecodeIceFrame(self, content, -1, 17, frame1, IceFrameMode_GR13_GTIA10);
		for (int i = 0; i < 7; i++)
			RECOIL_SetGtiaColor(self, i + 1, content[3 + i * 2]);
		RECOIL_DecodeIceFrame(self, content, -2, 1041, frame2, IceFrameMode_GR13_GTIA10);
		break;
	case 24:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE4X2, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR13_GTIA9);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR13_GTIA9);
		break;
	case 25:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE4X2, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR13_GTIA11);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR13_GTIA11);
		break;
	case 26:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE2X2, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR13_GTIA9);
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR13_GTIA10);
		break;
	case 27:
		if (contentLength != 2058)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE2X2, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR13_GTIA11);
		self->gtiaColors[0] = 0;
		RECOIL_SetPM123PF0123Bak(self, content, 2);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR13_GTIA10);
		break;
	case 28:
		if (contentLength != 2051)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_XE4X2, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR13_GTIA9);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR13_GTIA11);
		break;
	case 31:
		if (contentLength != 1032)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE4X1, 1);
		self->leftSkip = 2;
		static const uint8_t ICE20_GTIA11_COLORS[7] = { 0, 1, 2, 3, 5, 7, 8 };
		for (int i = 0; i < 7; i++)
			RECOIL_SetGtiaColor(self, ICE20_GTIA11_COLORS[i], content[1 + i]);
		RECOIL_DecodeIce20Frame(self, content, false, 8, frame1, 10);
		RECOIL_DecodeIce20Frame(self, content, true, 520, frame2, 10);
		break;
	case 32:
		if (contentLength != 1038)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE4X1, 1);
		self->leftSkip = 2;
		self->gtiaColors[0] = (uint8_t) (content[1] & 254);
		for (int i = 1; i < 7; i++)
			RECOIL_SetGtiaColor(self, ICE20_GTIA11_COLORS[i], content[i * 2]);
		RECOIL_DecodeIce20Frame(self, content, false, 14, frame1, 10);
		for (int i = 1; i < 7; i++)
			RECOIL_SetGtiaColor(self, ICE20_GTIA11_COLORS[i], content[1 + i * 2]);
		RECOIL_DecodeIce20Frame(self, content, true, 526, frame2, 10);
		break;
	case 33:
		if (contentLength != 1027)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE4X1, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIce20Frame(self, content, false, 3, frame1, 9);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIce20Frame(self, content, true, 515, frame2, 9);
		break;
	case 34:
		if (contentLength != 1027)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE4X1, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIce20Frame(self, content, false, 3, frame1, 11);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIce20Frame(self, content, true, 515, frame2, 11);
		break;
	case 35:
		if (contentLength != 1032)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIce20Frame(self, content, false, 8, frame1, 9);
		for (int i = 0; i < 7; i++)
			RECOIL_SetGtiaColor(self, ICE20_GTIA11_COLORS[i], content[1 + i]);
		RECOIL_DecodeIce20Frame(self, content, true, 520, frame2, 10);
		break;
	case 36:
		if (contentLength != 1032)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE2X1, 1);
		self->leftSkip = 1;
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIce20Frame(self, content, false, 8, frame1, 11);
		self->gtiaColors[0] = 0;
		for (int i = 1; i < 7; i++)
			RECOIL_SetGtiaColor(self, ICE20_GTIA11_COLORS[i], content[1 + i]);
		RECOIL_DecodeIce20Frame(self, content, true, 520, frame2, 10);
		break;
	case 37:
		if (contentLength != 1027)
			return false;
		RECOIL_SetSize(self, 256, 288, RECOILResolution_XE4X1, 1);
		self->gtiaColors[8] = (uint8_t) (content[1] & 254);
		RECOIL_DecodeIce20Frame(self, content, false, 3, frame1, 9);
		self->gtiaColors[8] = (uint8_t) (content[2] & 254);
		RECOIL_DecodeIce20Frame(self, content, true, 515, frame2, 11);
		break;
	default:
		return false;
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static bool RECOIL_DecodeIp2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 17358 || content[0] != 1)
		return false;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	self->gtiaColors[8] = (uint8_t) (content[1] & 254);
	self->gtiaColors[4] = (uint8_t) (content[5] & 254);
	self->gtiaColors[5] = (uint8_t) (content[7] & 254);
	self->gtiaColors[6] = (uint8_t) (content[9] & 254);
	self->gtiaColors[7] = (uint8_t) (content[11] & 254);
	uint8_t frame1[61440];
	RECOIL_DecodeIceFrame(self, content, 16398, 14, frame1, IceFrameMode_GR12);
	self->leftSkip = 2;
	for (int i = 0; i < 4; i++) {
		self->gtiaColors[i] = (uint8_t) (content[1 + i] & 254);
		RECOIL_SetGtiaColor(self, 4 + i, content[6 + i * 2]);
	}
	RECOIL_SetGtiaColor(self, 8, content[13]);
	uint8_t frame2[61440];
	RECOIL_DecodeIceFrame(self, content, 16398, 1038, frame2, IceFrameMode_GR0_GTIA10);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static void RECOIL_DecodeAtari8RgbScreen(RECOIL *self, uint8_t const *screens, int screensOffset, int color, uint8_t *frame)
{
	if (self->resolution == RECOILResolution_XE4X1) {
		self->gtiaColors[8] = (uint8_t) color;
		RECOIL_DecodeAtari8Gr9(self, screens, screensOffset, 40, frame, 0, self->width, self->width, self->height);
	}
	else {
		self->gtiaColors[8] = 0;
		self->gtiaColors[4] = (uint8_t) (color | 4);
		self->gtiaColors[5] = (uint8_t) (color | 10);
		self->gtiaColors[6] = (uint8_t) (color | 14);
		RECOIL_DecodeAtari8Gr15(self, screens, screensOffset, 40, frame, 0, self->width, self->height);
	}
}

static bool RECOIL_DecodeAtari8Rgb(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 9 || !RECOIL_IsStringAt(content, 0, "RGB1"))
		return false;
	int titleLength = content[4];
	if (contentLength < 9 + titleLength)
		return false;
	int width = content[6 + titleLength];
	int height = content[7 + titleLength];
	if (width == 0 || (width & 1) != 0 || width > 80 || height == 0 || height > 192 || content[8 + titleLength] != 1)
		return false;
	switch (content[5 + titleLength]) {
	case 9:
		RECOIL_SetSize(self, width << 2, height, RECOILResolution_XE4X1, 1);
		break;
	case 15:
		RECOIL_SetSize(self, width << 2, height, RECOILResolution_XE2X1, 1);
		break;
	default:
		return false;
	}
	int leftRgbs[192];
	uint8_t screens[23040];
	RgbStream rle;
	RgbStream_Construct(&rle);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 9 + titleLength;
	rle.base.base.base.contentLength = contentLength;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			int rgb = RleStream_ReadRle(&rle.base);
			if (rgb < 0)
				return false;
			if ((x & 1) == 0)
				leftRgbs[y] = rgb;
			else {
				int leftRgb = leftRgbs[y];
				int screenOffset = y * 40 + (x >> 1);
				screens[screenOffset] = (uint8_t) ((leftRgb >> 4 & 240) | rgb >> 8);
				screens[7680 + screenOffset] = (uint8_t) ((leftRgb & 240) | (rgb >> 4 & 15));
				screens[15360 + screenOffset] = (uint8_t) ((leftRgb << 4 & 240) | (rgb & 15));
			}
		}
	}
	uint8_t frame1[61440];
	RECOIL_DecodeAtari8RgbScreen(self, screens, 0, 48, frame1);
	uint8_t frame2[61440];
	RECOIL_DecodeAtari8RgbScreen(self, screens, 7680, 192, frame2);
	uint8_t frame3[61440];
	RECOIL_DecodeAtari8RgbScreen(self, screens, 15360, 112, frame3);
	return RECOIL_ApplyAtari8PaletteBlend3(self, frame1, frame2, frame3);
}

static bool RECOIL_DrawBlazingPaddlesVector(const RECOIL *self, uint8_t const *content, int contentLength, uint8_t *frame, int frameOffset, int index, int startAddress)
{
	if (index * 2 + 1 >= contentLength)
		return false;
	int contentOffset = content[index * 2] + (content[index * 2 + 1] << 8) - startAddress;
	if (contentOffset < 0)
		return false;
	while (contentOffset < contentLength) {
		int control = content[contentOffset++];
		if (control == 8)
			return true;
		for (; control >= 0; control -= 16) {
			if ((control & 4) == 0)
				frame[frameOffset + 1] = frame[frameOffset] = 14;
			switch (control & 3) {
			case 0:
				frameOffset += 2;
				break;
			case 1:
				frameOffset -= 2;
				break;
			case 2:
				frameOffset -= self->width;
				break;
			case 3:
				frameOffset += self->width;
				break;
			default:
				abort();
			}
		}
	}
	return false;
}

static bool RECOIL_DecodeBlazingPaddlesVectors(RECOIL *self, uint8_t const *content, int contentLength, int startAddress)
{
	int x = 0;
	int y = 0;
	int i;
	int lineI = 0;
	int lineTop = 0;
	int lineBottom = 0;
	int xs[256];
	int ys[256];
	int width = 0;
	BlazingPaddlesBoundingBox box;
	for (i = 0; i < 256; i++) {
		if (!BlazingPaddlesBoundingBox_Calculate(&box, content, contentLength, i, startAddress))
			break;
		int shapeWidth = box.right - box.left + 2;
		if (x + shapeWidth > 160) {
			y -= lineTop;
			while (lineI < i)
				ys[lineI++] = y;
			if (width < x)
				width = x;
			x = 0;
			y += lineBottom + 2;
			lineTop = box.top;
			lineBottom = box.bottom;
		}
		xs[i] = x - box.left;
		x += shapeWidth;
		if (lineTop > box.top)
			lineTop = box.top;
		if (lineBottom < box.bottom)
			lineBottom = box.bottom;
	}
	y -= lineTop;
	while (lineI < i)
		ys[lineI++] = y;
	if (width < x)
		width = x;
	y += lineBottom + 1;
	if (i == 0 || width > 160 || y > 240)
		return false;
	RECOIL_SetSize(self, width << 1, y, RECOILResolution_XE2X1, 1);
	uint8_t frame[76800] = { 0 };
	for (int j = 0; j < i; j++) {
		if (!RECOIL_DrawBlazingPaddlesVector(self, content, contentLength, frame, (ys[j] * width + xs[j]) << 1, j, startAddress))
			break;
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeChr(RECOIL *self, uint8_t const *content, int contentLength)
{
	return contentLength == 3072 && RECOIL_DecodeBlazingPaddlesVectors(self, content, contentLength, 28672);
}

static bool RECOIL_DecodeShp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (RECOIL_DecodeC64Shp(self, content, contentLength))
		return true;
	switch (contentLength) {
	case 1024:
		return RECOIL_DecodeBlazingPaddlesVectors(self, content, contentLength, 31744);
	case 4384:
		return RECOIL_DecodeGr7(self, content, 528, 3844);
	case 10018:
		return RECOIL_DecodeOcp(self, content, contentLength);
	default:
		return false;
	}
}

static void RECOIL_DrawSpcChar(uint8_t *pixels, int x1, int y1, int ch)
{
	if (ch < 32 || ch > 95)
		return;
	uint8_t const *font = FuResource_atari8_fnt;
	int fontOffset = (ch - 32) << 3;
	for (int y = 0; y < 8 && y1 + y < 192; y++) {
		for (int x = 0; x < 4 && x1 + x < 160; x++)
			pixels[(y1 + y) * 160 + x1 + x] = (uint8_t) (font[fontOffset + y] >> (6 - x * 2) & 3);
	}
}

static void RECOIL_DrawSpcLine(uint8_t *pixels, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx >= dy) {
		int e = dx;
		if (x2 < x1) {
			int ty = y1;
			x1 = x2;
			x2 += dx;
			y1 = y2;
			y2 = ty;
		}
		for (; x1 <= x2; x1++) {
			if (x1 < 160 && y1 < 192)
				pixels[160 * y1 + x1] = (uint8_t) color;
			e -= dy * 2;
			if (e < 0) {
				e += dx * 2;
				y1 += y1 < y2 ? 1 : -1;
			}
		}
	}
	else {
		int e = dy;
		if (y2 < y1) {
			int tx = x1;
			x1 = x2;
			x2 = tx;
			y1 = y2;
			y2 += dy;
		}
		for (; y1 <= y2; y1++) {
			if (x1 < 160 && y1 < 192)
				pixels[160 * y1 + x1] = (uint8_t) color;
			e -= dx * 2;
			if (e < 0) {
				e += dy * 2;
				x1 += x1 < x2 ? 1 : -1;
			}
		}
	}
}

static void RECOIL_PlotSpcPattern(uint8_t *pixels, int x, int y, int pattern)
{
	pixels[y * 160 + x] = (uint8_t) (pattern >> (((~y & 1) << 3) + ((~x & 3) << 1)) & 3);
}

static void RECOIL_DrawSpcBrush(uint8_t *pixels, int x1, int y1, int brush, int pattern)
{
	static const uint8_t BRUSHES[128] = { 0, 0, 0, 0, 0, 0, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 48, 48, 48, 48, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 16, 56, 56, 56, 56, 16, 0, 0, 0, 0, 0, 0,
		0, 0, 16, 56, 56, 124, 124, 124, 124, 56, 56, 16, 0, 0, 0, 0,
		0, 24, 24, 60, 60, 126, 126, 126, 126, 60, 60, 24, 24, 0, 0, 0,
		16, 56, 124, 124, 124, 254, 254, 254, 254, 124, 124, 124, 56, 16, 0, 0,
		0, 0, 16, 40, 40, 80, 60, 120, 20, 40, 40, 16, 0, 0, 0, 0,
		16, 40, 84, 40, 84, 186, 124, 124, 186, 84, 40, 84, 40, 16, 0, 0 };
	for (int y = 0; y < 16 && y1 + y < 192; y++) {
		int brushShape = BRUSHES[brush * 16 + y];
		for (int x = 0; x < 8 && x1 + x < 160; x++) {
			if ((brushShape >> (7 - x) & 1) != 0)
				RECOIL_PlotSpcPattern(pixels, x, y, pattern);
		}
	}
}

static bool RECOIL_FillSpc(uint8_t *pixels, int x, int y, int pattern)
{
	if (x >= 160 || y >= 192)
		return false;
	while (y >= 0 && pixels[y * 160 + x] == 0)
		y--;
	while (++y < 192 && pixels[y * 160 + x] == 0) {
		do
			x--;
		while (x >= 0 && pixels[y * 160 + x] == 0);
		int x1 = x;
		while (x < 159) {
			if (pixels[y * 160 + ++x] != 0)
				break;
			RECOIL_PlotSpcPattern(pixels, x, y, pattern);
		}
		x = x1 + ((x - x1 + 1) >> 1);
	}
	return true;
}

static bool RECOIL_DecodeAtari8Spc(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 3 || contentLength != content[0] + (content[1] << 8) + 3 || content[contentLength - 1] != 0)
		return false;
	uint8_t pixels[30720] = { 0 };
	int lineColors[96] = { 0 };
	int textX = 0;
	int textY = 0;
	int lineX = 0;
	int lineY = 0;
	int brush = 0;
	int pattern = 8840;
	int lineColor = 3;
	int x;
	int y;
	for (int contentOffset = 2; content[contentOffset] != 0;) {
		switch (content[contentOffset]) {
		case 16:
			if (contentOffset + 3 >= contentLength)
				return false;
			textX = content[contentOffset + 1];
			textY = content[contentOffset + 2];
			contentOffset += 3;
			break;
		case 32:
		case 33:
		case 34:
		case 35:
			if (contentOffset + 1 >= contentLength)
				return false;
			lineColor = content[contentOffset] & 3;
			contentOffset++;
			break;
		case 48:
		case 80:
			if (contentOffset + 2 >= contentLength)
				return false;
			RECOIL_DrawSpcChar(pixels, textX, textY, content[contentOffset + 1]);
			textX += 4;
			contentOffset += 2;
			break;
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 69:
		case 70:
		case 71:
			if (contentOffset + 1 >= contentLength)
				return false;
			brush = content[contentOffset] & 7;
			contentOffset++;
			break;
		case 96:
			if (contentOffset + 2 >= contentLength)
				return false;
			pattern = content[contentOffset + 1];
			static const int PATTERNS[71] = { 0, 21845, 43690, 65535, 4420, 8840, 13260, 26265, 30685, 48110, 5457, 10914, 16371, 16388, 27302, 32759,
				32776, 38233, 49147, 49164, 54621, 60078, 21896, 8908, 13124, 17561, 17629, 30617, 35054, 34918, 39406, 52343,
				52411, 56763, 7089, 5465, 5469, 38237, 16392, 16396, 32780, 27308, 10926, 27298, 32763, 16379, 49143, 21892,
				8900, 13128, 17553, 17617, 30609, 35042, 34914, 39393, 52339, 52403, 56755, 21900, 8904, 13132, 17565, 17625,
				30621, 35046, 34926, 39397, 52347, 52407, 56759 };
			if (pattern >= 71)
				return false;
			pattern = PATTERNS[pattern];
			contentOffset += 2;
			break;
		case 112:
			if (contentOffset + 7 >= contentLength)
				return false;
			for (y = content[contentOffset + 1]; y <= content[contentOffset + 2]; y++) {
				if (y >= 96)
					return false;
				lineColors[y] = contentOffset + 3;
			}
			contentOffset += 7;
			break;
		case 128:
			if (contentOffset + 3 >= contentLength)
				return false;
			lineX = content[contentOffset + 1];
			lineY = content[contentOffset + 2];
			contentOffset += 3;
			break;
		case 160:
			if (contentOffset + 3 >= contentLength)
				return false;
			x = content[contentOffset + 1];
			y = content[contentOffset + 2];
			RECOIL_DrawSpcLine(pixels, lineX, lineY, x, y, lineColor);
			lineX = x;
			lineY = y;
			contentOffset += 3;
			break;
		case 192:
			if (contentOffset + 3 >= contentLength)
				return false;
			RECOIL_DrawSpcBrush(pixels, content[contentOffset + 1], content[contentOffset + 2], brush, pattern);
			contentOffset += 3;
			break;
		case 224:
			if (contentOffset + 3 >= contentLength)
				return false;
			if (!RECOIL_FillSpc(pixels, content[contentOffset + 1], content[contentOffset + 2], pattern))
				return false;
			contentOffset += 3;
			break;
		default:
			return false;
		}
	}
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[61440];
	for (y = 0; y < 192; y++) {
		static const uint8_t DEFAULT_COLORS[4] = { 0, 21, 149, 54 };
		int colorsOffset = lineColors[y >> 1];
		uint8_t const *colors = colorsOffset == 0 ? DEFAULT_COLORS : content;
		for (x = 0; x < 160; x++) {
			int offset = y * 320 + x * 2;
			frame[offset + 1] = frame[offset] = (uint8_t) (colors[colorsOffset + pixels[y * 160 + x]] & 254);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeHcm(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 8208 || !RECOIL_IsStringAt(content, 0, "HCMA8") || content[5] != 1)
		return false;
	HcmRenderer gtia;
	HcmRenderer_Construct(&gtia);
	int leftSprite;
	switch (content[6]) {
	case 0:
		leftSprite = 2;
		gtia.base.prior = 0;
		break;
	case 2:
		leftSprite = 1;
		gtia.base.prior = 36;
		break;
	default:
		return false;
	}
	gtia.base.playerHpos[3] = gtia.base.playerHpos[3 - leftSprite] = 104;
	gtia.base.missileHpos[leftSprite] = gtia.base.missileHpos[0] = 136;
	gtia.base.missileHpos[3] = gtia.base.missileHpos[3 - leftSprite] = 144;
	for (int i = 0; i < 4; i++)
		gtia.base.missileSize[i] = gtia.base.playerSize[i] = 4;
	gtia.base.colors[8] = (uint8_t) (content[7] & 254);
	gtia.base.colors[3 - leftSprite] = gtia.base.colors[0] = (uint8_t) (content[8] & 254);
	gtia.base.colors[3] = gtia.base.colors[leftSprite] = (uint8_t) (content[9] & 254);
	gtia.base.colors[4] = (uint8_t) (content[10] & 254);
	gtia.base.colors[5] = (uint8_t) (content[11] & 254);
	gtia.base.colors[6] = (uint8_t) (content[12] & 254);
	gtia.base.content = content;
	gtia.base.playfieldColumns = 32;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_XE2X1, 1);
	uint8_t frame[49152];
	for (int y = 0; y < 192; y++) {
		gtia.base.playerHpos[leftSprite] = gtia.base.playerHpos[0] = 72;
		GtiaRenderer_ProcessSpriteDma(&gtia.base, content, 816 + y);
		GtiaRenderer_StartLine(&gtia.base, 64);
		GtiaRenderer_DrawSpan(&gtia.base, y, 64, 128, AnticMode_FOUR_COLOR, frame, 256, 0);
		gtia.base.playerHpos[leftSprite] = gtia.base.playerHpos[0] = 152;
		gtia.base.playerGraphics[0] = content[48 + y];
		gtia.base.playerGraphics[leftSprite] = content[304 + y];
		GtiaRenderer_DrawSpan(&gtia.base, y, 128, 192, AnticMode_FOUR_COLOR, frame, 256, 0);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeGed(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 11302 || content[0] != 255 || content[1] != 255 || content[2] != 48 || content[3] != 83 || content[4] != 79 || content[5] != 127)
		return false;
	int cycle = content[3300];
	if (cycle > 7)
		return false;
	GedRenderer gtia;
	GedRenderer_Construct(&gtia);
	GtiaRenderer_SetSpriteSizes(gtia.base.missileSize, content[3291]);
	gtia.base.colors[7] = (uint8_t) (content[3293] & 254);
	gtia.base.colors[8] = (uint8_t) (content[3294] & 254);
	int prior = content[3292];
	gtia.base.prior = prior;
	for (int i = 0; i < 4; i++) {
		GtiaRenderer_SetPlayerSize(&gtia.base, i, content[3290] >> ((3 - i) << 1));
		gtia.base.playerHpos[i] = (uint8_t) (48 + content[3295 + i]);
		gtia.base.missileHpos[i] = (uint8_t) ((prior & 16) == 0 ? gtia.base.playerHpos[i] + (gtia.base.playerSize[i] << 3) : i == 0 ? 48 + content[3299] : gtia.base.missileHpos[i - 1] + (gtia.base.missileSize[i - 1] << 1));
		gtia.base.colors[i] = (uint8_t) (content[3286 + i] & 254);
	}
	gtia.base.content = content;
	gtia.base.playfieldColumns = 40;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1, 1);
	uint8_t frame[64000];
	for (int y = 0; y < 200; y++) {
		GtiaRenderer_ProcessSpriteDma(&gtia.base, content, 2034 + y);
		GtiaRenderer_Poke(&gtia.base, content[206 + y] & 31, content[6 + y]);
		gtia.base.colors[4] = (uint8_t) (content[406 + y] & 254);
		gtia.base.colors[5] = (uint8_t) (content[606 + y] & 254);
		gtia.base.colors[6] = (uint8_t) (content[806 + y] & 254);
		GtiaRenderer_StartLine(&gtia.base, 48);
		int hpos = GtiaRenderer_DrawSpan(&gtia.base, y, 48, 63 + (cycle << 3), AnticMode_FOUR_COLOR, frame, 320, 0);
		gtia.base.colors[4] = (uint8_t) (content[1006 + y] & 254);
		hpos = GtiaRenderer_DrawSpan(&gtia.base, y, hpos, cycle < 4 ? hpos + 32 : 107 + (cycle << 2), AnticMode_FOUR_COLOR, frame, 320, 0);
		gtia.base.colors[5] = (uint8_t) (content[1206 + y] & 254);
		hpos = GtiaRenderer_DrawSpan(&gtia.base, y, hpos, 123 + (cycle << 2), AnticMode_FOUR_COLOR, frame, 320, 0);
		gtia.base.colors[6] = (uint8_t) (content[1406 + y] & 254);
		hpos = GtiaRenderer_DrawSpan(&gtia.base, y, hpos, hpos + 24, AnticMode_FOUR_COLOR, frame, 320, 0);
		gtia.base.colors[4] = (uint8_t) (content[1606 + y] & 254);
		hpos = GtiaRenderer_DrawSpan(&gtia.base, y, hpos, hpos + 24, AnticMode_FOUR_COLOR, frame, 320, 0);
		gtia.base.colors[5] = (uint8_t) (content[1806 + y] & 254);
		GtiaRenderer_DrawSpan(&gtia.base, y, hpos, 208, AnticMode_FOUR_COLOR, frame, 320, 0);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodePgr(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 1776 || 6 + RECOIL_ParseAtari8ExecutableHeader(content, 0) != contentLength || content[2] != 6 || content[3] != 130 || !RECOIL_IsStringAt(content, 8, "PowerGFX"))
		return false;
	PgrRenderer gtia;
	PgrRenderer_Construct(&gtia);
	for (int i = 0; i < 14; i++) {
		GtiaRenderer_Poke(&gtia.base, i, content[504 + i]);
		GtiaRenderer_Poke(&gtia.base, 14 + i, content[760 + i]);
	}
	gtia.base.content = content;
	int dmaCtl = content[774];
	switch (dmaCtl & 243) {
	case 49:
		gtia.base.playfieldColumns = 32;
		break;
	case 50:
		gtia.base.playfieldColumns = 40;
		break;
	default:
		return false;
	}
	int dlOffset = 16;
	int rasterOffset = content[6] + (content[7] << 8) - 33280;
	if (rasterOffset < 1536)
		return false;
	gtia.screenOffset = -1;
	int a = 0;
	uint8_t frame[80640];
	RECOILResolution resolution = RECOILResolution_XE4X1;
	for (int y = 0; y < 240; y++) {
		int hpos = -11;
		int dlOp = content[dlOffset++];
		switch (dlOp) {
		case 0:
		case 14:
		case 15:
			break;
		case 65:
			dlOffset--;
			break;
		case 78:
		case 79:
			hpos += 4;
			gtia.screenOffset = content[dlOffset] + (content[dlOffset + 1] << 8) - 33280;
			dlOffset += 2;
			break;
		default:
			return false;
		}
		AnticMode anticMode;
		switch (dlOp & 15) {
		case 14:
			anticMode = AnticMode_FOUR_COLOR;
			if (resolution == RECOILResolution_XE4X1 && gtia.base.prior < 64)
				resolution = RECOILResolution_XE2X1;
			break;
		case 15:
			anticMode = AnticMode_HI_RES;
			if (gtia.base.prior < 64)
				resolution = RECOILResolution_XE1X1;
			break;
		default:
			anticMode = AnticMode_BLANK;
			break;
		}
		if (anticMode != AnticMode_BLANK && (gtia.screenOffset < 1536 || gtia.screenOffset + 40 > contentLength))
			return false;
		GtiaRenderer_StartLine(&gtia.base, 44);
		if ((dmaCtl & 12) != 0) {
			hpos += 2;
			if ((dmaCtl & 4) != 0)
				gtia.base.missileGraphics = content[264 + y];
			if ((dmaCtl & 8) != 0) {
				hpos += 8;
				GtiaRenderer_ProcessPlayerDma(&gtia.base, content, 520 + y);
			}
		}
		for (int cpuCycles = 1;;) {
			if (rasterOffset >= contentLength)
				return false;
			int rasterOp = content[rasterOffset++];
			if ((rasterOp & 32) != 0) {
				if (rasterOffset >= contentLength)
					return false;
				cpuCycles += 2;
				a = content[rasterOffset++];
			}
			int addr = rasterOp & 31;
			if (addr <= 27) {
				int untilHpos = GtiaRenderer_AdvanceCpuCycles(&gtia.base, hpos, cpuCycles, anticMode != AnticMode_BLANK);
				GtiaRenderer_DrawSpan(&gtia.base, y, hpos >= 44 ? hpos : 44, untilHpos < 212 ? untilHpos : 212, anticMode, frame, 336, 0);
				hpos = untilHpos;
				GtiaRenderer_Poke(&gtia.base, addr, a);
				if (rasterOp >= 128)
					break;
				cpuCycles = 4;
			}
			else {
				int nops = (rasterOp >> 6 & 3) | (rasterOp & 3) << 2;
				if (nops == 0)
					break;
				cpuCycles += nops << 1;
			}
		}
		GtiaRenderer_DrawSpan(&gtia.base, y, hpos >= 44 ? hpos : 44, 212, anticMode, frame, 336, 0);
		if (anticMode != AnticMode_BLANK)
			gtia.screenOffset += gtia.base.playfieldColumns;
	}
	RECOIL_SetSize(self, 336, 240, resolution, 1);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_HasG2fRaster(uint8_t const *content, int contentOffset, int count, int hitClr)
{
	do {
		switch (content[contentOffset]) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 65:
		case 66:
		case 67:
		case 97:
		case 98:
		case 99:
			break;
		case 129:
		case 130:
		case 131:
			if (content[contentOffset + 1] != hitClr)
				return true;
			break;
		default:
			return true;
		}
		contentOffset += 2;
	}
	while (--count > 0);
	return false;
}

static bool RECOIL_DecodeMch(RECOIL *self, uint8_t const *content, int contentLength)
{
	int columns;
	switch (contentLength) {
	case 9840:
	case 28673:
		columns = 32;
		break;
	case 12000:
	case 30833:
		columns = 40;
		break;
	case 14160:
	case 32993:
		columns = 48;
		break;
	default:
		return false;
	}
	int bitmapLength = columns * 270;
	bool sprites = contentLength > bitmapLength + 1200;
	AnticMode anticMode;
	switch (content[0] & 3) {
	case 0:
		if (sprites && RECOIL_HasG2fRaster(content, bitmapLength + 6080, 6960, 30))
			return false;
		anticMode = AnticMode_FIVE_COLOR;
		break;
	case 1:
		anticMode = AnticMode_FIVE_COLOR;
		break;
	case 2:
		if (sprites && RECOIL_HasG2fRaster(content, bitmapLength + 6080, 6960, 30))
			return false;
		anticMode = AnticMode_FOUR_COLOR;
		break;
	default:
		return false;
	}
	RECOILResolution resolution;
	int gtiaMode = 0;
	switch (content[0] & 60) {
	case 0:
		anticMode = AnticMode_HI_RES;
		resolution = RECOILResolution_XE1X1;
		break;
	case 4:
		resolution = RECOILResolution_XE2X1;
		break;
	case 8:
		anticMode = AnticMode_HI_RES;
		resolution = RECOILResolution_XE4X1;
		gtiaMode = 64;
		break;
	case 24:
		anticMode = AnticMode_HI_RES;
		resolution = RECOILResolution_XE4X1;
		gtiaMode = 128;
		break;
	case 40:
		anticMode = AnticMode_HI_RES;
		resolution = RECOILResolution_XE4X1;
		gtiaMode = 192;
		break;
	default:
		return false;
	}
	RECOIL_SetSize(self, 336, 240, resolution, 1);
	uint8_t frame[80640];
	MchRenderer gtia;
	MchRenderer_Construct(&gtia);
	memset(gtia.base.playerHpos, 0, sizeof(gtia.base.playerHpos));
	memset(gtia.base.missileHpos, 0, sizeof(gtia.base.missileHpos));
	memset(gtia.base.colors, 0, sizeof(gtia.base.colors));
	gtia.base.prior = gtiaMode;
	gtia.base.content = content;
	gtia.base.playfieldColumns = columns;
	gtia.dliPlus = false;
	for (int i = 0; i < bitmapLength; i += 9) {
		if ((content[i] & 64) != 0) {
			gtia.dliPlus = true;
			break;
		}
	}
	for (int y = 0; y < 240; y++) {
		int colorsOffset = bitmapLength + y;
		GtiaRenderer_SetG2fColors(&gtia.base, colorsOffset, 240, sprites ? 9 : 5, gtiaMode);
		if (sprites) {
			for (int i = 0; i < 4; i++) {
				gtia.base.playerHpos[i] = content[colorsOffset + (9 + i) * 240];
				gtia.base.missileHpos[i] = content[colorsOffset + (13 + i) * 240];
			}
			GtiaRenderer_SetSpriteSizes(gtia.base.playerSize, content[colorsOffset + 4080]);
			GtiaRenderer_SetSpriteSizes(gtia.base.missileSize, content[colorsOffset + 4320]);
			gtia.base.prior = gtiaMode | content[colorsOffset + 4560];
			GtiaRenderer_ProcessSpriteDma(&gtia.base, content, colorsOffset + 4800);
		}
		GtiaRenderer_StartLine(&gtia.base, 44);
		GtiaRenderer_DrawSpan(&gtia.base, y, 44, 212, anticMode, frame, 336, 0);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_G2fHasRaster(uint8_t const *content, int contentOffset)
{
	return RECOIL_HasG2fRaster(content, contentOffset, 2880, content[0] < 128 ? 22 : 30);
}

static bool RECOIL_DecodeG2fUnpacked(RECOIL *self, uint8_t const *content, int contentLength, uint8_t *frame, int yOffset)
{
	if (contentLength < 155711)
		return false;
	int columns = content[0] & 127;
	switch (columns) {
	case 32:
	case 40:
	case 48:
		break;
	default:
		return false;
	}
	int fontsOffset = 3 + 30 * columns;
	int fontNumberOffset = fontsOffset + (((content[2] & 127) + 1) << 10);
	if (contentLength < fontNumberOffset + 153724)
		return false;
	bool charMode;
	int vbxeOffset = fontNumberOffset + 155231;
	int inverse2Offset = -1;
	switch (content[fontNumberOffset + 147679] & 127) {
	case 1:
		if (RECOIL_G2fHasRaster(content, fontNumberOffset + 147934))
			return false;
		charMode = true;
		break;
	case 2:
		charMode = true;
		break;
	case 3:
		if (RECOIL_G2fHasRaster(content, fontNumberOffset + 147934))
			return false;
		charMode = false;
		break;
	case 66:
		charMode = true;
		inverse2Offset = vbxeOffset + 138244;
		if (contentLength < inverse2Offset + 30 * columns)
			return false;
		break;
	default:
		return false;
	}
	if (contentLength < vbxeOffset + 138243)
		vbxeOffset = -1;
	else {
		switch (content[vbxeOffset]) {
		case 0:
			vbxeOffset = -1;
			break;
		case 1:
			if (content[vbxeOffset + 1] != 8 || content[vbxeOffset + 2] == 0)
				return false;
			self->resolution = RECOILResolution_VBXE2X1;
			break;
		default:
			return false;
		}
	}
	G2fRenderer gtia;
	G2fRenderer_Construct(&gtia);
	gtia.base.content = content;
	gtia.base.playfieldColumns = columns;
	gtia.inverse2Offset = inverse2Offset;
	gtia.vbxeOffset = vbxeOffset;
	for (int y = 0; y < 240; y++) {
		int row = y >> 3;
		gtia.fontOffset = fontsOffset + ((content[fontNumberOffset + row] & 127) << 10);
		if (gtia.fontOffset >= fontNumberOffset)
			return false;
		int spriteOffset = fontNumberOffset + 2334 + (y << 1);
		int prior = content[spriteOffset + 1] >> 4 & 7;
		static const uint8_t PRIORS[5] = { 4, 2, 1, 8, 0 };
		if (prior >= 5)
			return false;
		prior = PRIORS[prior] | (content[spriteOffset + 1025] & 48);
		AnticMode anticMode;
		switch (content[fontNumberOffset + 153694 + row]) {
		case 1:
			self->resolution = self->resolution == RECOILResolution_VBXE2X1 || self->resolution == RECOILResolution_VBXE1X1 ? RECOILResolution_VBXE1X1 : RECOILResolution_XE1X1;
			anticMode = AnticMode_HI_RES;
			break;
		case 2:
			if (self->resolution == RECOILResolution_XE4X1)
				self->resolution = RECOILResolution_XE2X1;
			anticMode = charMode ? AnticMode_FIVE_COLOR : AnticMode_FOUR_COLOR;
			break;
		case 4:
			;
			static const uint8_t GTIA_MODES[8] = { 64, 64, 64, 64, 64, 128, 192, 64 };
			prior |= GTIA_MODES[content[1] & 7];
			anticMode = AnticMode_HI_RES;
			break;
		case 255:
			anticMode = AnticMode_BLANK;
			break;
		default:
			return false;
		}
		int colorsOffset = fontNumberOffset + 30 + y;
		GtiaRenderer_SetG2fColors(&gtia.base, colorsOffset, 256, 9, prior);
		int missileGraphics = 0;
		for (int i = 0; i < 4; i++) {
			if (!G2fRenderer_SetSprite(gtia.base.playerHpos, gtia.base.playerSize, i, content, spriteOffset) || !G2fRenderer_SetSprite(gtia.base.missileHpos, gtia.base.missileSize, i, content, spriteOffset + 512))
				return false;
			gtia.base.playerGraphics[i] = content[colorsOffset + 6400 + (i << 9)];
			missileGraphics |= content[colorsOffset + 6656 + (i << 9)] >> 6 << (i << 1);
		}
		gtia.base.missileGraphics = missileGraphics;
		gtia.base.prior = prior;
		GtiaRenderer_StartLine(&gtia.base, 44);
		GtiaRenderer_DrawSpan(&gtia.base, y, 44, 212, anticMode, frame, 336, yOffset);
	}
	return true;
}

static bool RECOIL_DecodeG2fFrame(RECOIL *self, uint8_t const *content, int contentLength, uint8_t *frame, int yOffset)
{
	if (contentLength < 11)
		return false;
	if (RECOIL_IsStringAt(content, 0, "G2FZLIB")) {
		uint8_t *unpacked = (uint8_t *) malloc(327078 * sizeof(uint8_t));
		InflateStream stream;
		stream.base.content = content;
		stream.base.contentOffset = 7;
		stream.base.contentLength = contentLength;
		contentLength = InflateStream_Uncompress(&stream, unpacked, 327078);
		bool returnValue = RECOIL_DecodeG2fUnpacked(self, unpacked, contentLength, frame, yOffset);
		free(unpacked);
		return returnValue;
	}
	return RECOIL_DecodeG2fUnpacked(self, content, contentLength, frame, yOffset);
}

static bool RECOIL_DecodeG2f(RECOIL *self, uint8_t const *content, int contentLength)
{
	uint8_t frame[80640];
	self->resolution = RECOILResolution_XE4X1;
	if (!RECOIL_DecodeG2fFrame(self, content, contentLength, frame, 0))
		return false;
	RECOIL_SetSize(self, 336, 240, self->resolution, 1);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static bool RECOIL_DecodeVsc(RECOIL *self, const char *vscFilename, uint8_t const *content, int contentLength)
{
	Stream s;
	s.content = content;
	s.contentOffset = 0;
	s.contentLength = contentLength;
	int height = 0;
	for (;;) {
		int c = Stream_ReadByte(&s);
		if (c < 0)
			break;
		switch (c) {
		case '\r':
			if (Stream_ReadByte(&s) != '\n')
				return false;
			height += 240;
			break;
		case '/':
		case ':':
		case '\\':
			return false;
		default:
			if (c < ' ' || c > '~')
				return false;
			break;
		}
	}
	uint8_t *frame = (uint8_t *) malloc(336 * height * sizeof(uint8_t));
	uint8_t *g2f = (uint8_t *) malloc(327078 * sizeof(uint8_t));
	s.contentOffset = 0;
	self->resolution = RECOILResolution_XE4X1;
	for (height = 0;; height += 240) {
		int filenameOffset = s.contentOffset;
		if (!Stream_SkipUntilByte(&s, '\n'))
			break;
		char *filename = FuString_Substring((const char *) content + filenameOffset, s.contentOffset - 2 - filenameOffset);
		contentLength = RECOIL_ReadSiblingFile(self, vscFilename, filename, g2f, 327078);
		if (!RECOIL_DecodeG2fFrame(self, g2f, contentLength, frame, height)) {
			free(filename);
			free(g2f);
			free(frame);
			return false;
		}
		free(filename);
	}
	bool returnValue = RECOIL_SetSize(self, 336, height, self->resolution, 1) && RECOIL_ApplyAtari8Palette(self, frame);
	free(g2f);
	free(frame);
	return returnValue;
}

static bool RECOIL_DecodeDap(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength != 77568)
		return false;
	RECOIL_SetSize(self, 320, 240, RECOILResolution_VBXE1X1, 1);
	for (int i = 0; i < 256; i++)
		self->contentPalette[i] = content[76800 + i] << 16 | content[77056 + i] << 8 | content[77312 + i];
	RECOIL_DecodeBytes(self, content, 0);
	return true;
}

static bool RECOIL_DecodeTandyPnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 236 || content[0] != 19 || content[1] != 'P' || content[2] != 'N' || content[3] != 'T')
		return false;
	RECOIL_SetSize(self, 312, 176, RECOILResolution_TANDY1X1, 1);
	static const int PALETTE[16] = { 0, 153, 39168, 3381657, 10027008, 13382604, 13395456, 10066329, 10053171, 6697983, 3394560, 6737100, 16764108, 16751103, 16776960, 16777215 };
	if (contentLength == 27478) {
		memcpy(self->contentPalette, PALETTE, 16 * sizeof(int));
		RECOIL_DecodeNibbles(self, content, 22, 156);
		return true;
	}
	int contentOffset = 22;
	int repeatCount = 1;
	int repeatValue = 0;
	for (int pixelsOffset = 0; pixelsOffset < 54912; pixelsOffset += 2) {
		if (--repeatCount == 0) {
			if (contentOffset + 1 >= contentLength)
				return false;
			repeatCount = content[contentOffset + 1];
			if (repeatCount == 0)
				return false;
			repeatValue = content[contentOffset];
			contentOffset += 2;
		}
		self->pixels[pixelsOffset] = PALETTE[repeatValue >> 4];
		self->pixels[pixelsOffset + 1] = PALETTE[repeatValue & 15];
	}
	return contentOffset == contentLength;
}

static bool RECOIL_DecodeHs2(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength % 105 != 0)
		return false;
	return RECOIL_SetSize(self, 840, contentLength / 105, RECOILResolution_PC1X1, 1) && RECOIL_DecodeBlackAndWhite(self, content, 0, contentLength, false, 0);
}

static bool RECOIL_DecodeImage72Fnt(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 4 || content[0] != 0 || content[1] != 8)
		return false;
	int fontHeight = content[2];
	if (contentLength != 3 + (fontHeight << 8))
		return false;
	RECOIL_SetSize(self, 256, fontHeight << 3, RECOILResolution_PC1X1, 1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, 3, contentLength, fontHeight);
	return true;
}

static bool RECOIL_DecodeMsp(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 32)
		return false;
	int width = content[4] | content[5] << 8;
	int height = content[6] | content[7] << 8;
	if (RECOIL_IsStringAt(content, 0, "DanM"))
		return RECOIL_SetSize(self, width, height, RECOILResolution_PC1X1, 1) && RECOIL_DecodeBlackAndWhite(self, content, 32, contentLength, false, 0);
	if (RECOIL_IsStringAt(content, 0, "LinS") && RECOIL_SetSize(self, width, height, RECOILResolution_PC1X1, 1)) {
		MspStream rle;
		MspStream_Construct(&rle);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 32 + (height << 1);
		rle.base.base.base.contentLength = contentLength;
		return RECOIL_DecodeRleBlackAndWhite(self, &rle.base, 0);
	}
	return false;
}

static bool RECOIL_DecodeAwbmPalette(RECOIL *self, uint8_t const *content, int contentLength, int paletteOffset, int colors)
{
	if (contentLength < paletteOffset + 4 + colors * 3 || !RECOIL_IsStringAt(content, paletteOffset, "RGB "))
		return false;
	for (int i = 0; i < colors; i++) {
		int rgb = RECOIL_GetR8G8B8Color(content, paletteOffset + 4 + i * 3);
		self->contentPalette[i] = (rgb & 4144959) << 2 | (rgb >> 4 & 197379);
	}
	return true;
}

static bool RECOIL_DecodeAwbm(RECOIL *self, uint8_t const *content, int contentLength)
{
	int width = content[4] | content[5] << 8;
	int height = content[6] | content[7] << 8;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_PC1X1, 1))
		return false;
	if (RECOIL_DecodeAwbmPalette(self, content, contentLength, 8 + width * height, 256)) {
		RECOIL_DecodeBytes(self, content, 8);
		return true;
	}
	int planeStride = (width + 7) >> 3;
	if (!RECOIL_DecodeAwbmPalette(self, content, contentLength, 8 + (height * planeStride << 2), 16))
		return false;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
			self->pixels[y * width + x] = self->contentPalette[RECOIL_GetBitplanePixel(content, 8 + (y * planeStride << 2) + (x >> 3), x, 4, planeStride)];
	}
	return true;
}

static bool RECOIL_DecodeEpa(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 17)
		return false;
	if (RECOIL_IsStringAt(content, 0, "AWBM"))
		return RECOIL_DecodeAwbm(self, content, contentLength);
	int columns = content[0];
	int rows = content[1];
	if (columns > 80 || rows > 25 || contentLength != 2 + columns * rows * 15 + 70)
		return false;
	int width = columns * 8;
	int height = rows * 14;
	RECOIL_SetSize(self, width, height, RECOILResolution_PC1X1, 1);
	int bitmapOffset = 2 + columns * rows;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int ch = y / 14 * columns + (x >> 3);
			int attribute = content[2 + ch];
			int b = content[bitmapOffset + ch * 14 + y % 14] >> (~x & 7) & 1;
			self->pixels[y * width + x] = RECOIL_CGA_PALETTE[b == 0 ? attribute >> 4 : attribute & 15];
		}
	}
	return true;
}

static void RECOIL_DecodeBkMono(RECOIL *self, uint8_t const *content, int height)
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < 512; x++) {
			int c = content[(y >> 1 << 6) + (x >> 3)] >> (x & 7) & 1;
			if (c != 0)
				c = 16777215;
			self->pixels[(y << 9) + x] = c;
		}
	}
}

static void RECOIL_DecodeBkColorFrame(RECOIL *self, uint8_t const *content, int paletteOffset, int frame)
{
	paletteOffset <<= 2;
	for (int i = 0; i < 65536; i++) {
		static const int PALETTE[64] = { 0, 255, 65280, 16711680, 0, 16776960, 16711935, 16711680, 0, 65535, 255, 16711935, 0, 65280, 65535, 16776960,
			0, 16711935, 65535, 16777215, 0, 16777215, 16777215, 16777215, 0, 12582912, 8388608, 16711680, 0, 65280, 65535, 16776960,
			0, 12583104, 8388863, 16711935, 0, 16776960, 8388863, 12582912, 0, 16776960, 12583104, 16711680, 0, 65535, 16776960, 16711680,
			0, 16711680, 65280, 65535, 0, 65535, 16776960, 16777215, 0, 16776960, 65280, 16777215, 0, 65535, 65280, 16777215 };
		self->pixels[(frame << 16) + i] = PALETTE[paletteOffset + (content[(frame << 14) + (i >> 2)] >> ((i & 3) << 1) & 3)];
	}
}

static bool RECOIL_DecodeBkColor(RECOIL *self, uint8_t const *content, int palette)
{
	RECOIL_SetSize(self, 256, 256, RECOILResolution_BK1X1, 1);
	RECOIL_DecodeBkColorFrame(self, content, palette, 0);
	return true;
}

static bool RECOIL_DecodeBks(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 16384:
		if (!RECOIL_SetSize(self, 512, 512, RECOILResolution_BK1X2, 1))
			return false;
		RECOIL_DecodeBkMono(self, content, 512);
		return true;
	case 16385:
		;
		int palette = content[16384];
		if (palette > 15)
			return false;
		return RECOIL_DecodeBkColor(self, content, palette);
	case 32768:
		if (!RECOIL_SetSize(self, 512, 512, RECOILResolution_BK1X2, 2))
			return false;
		RECOIL_DecodeBkMono(self, content, 1024);
		return RECOIL_ApplyBlend(self);
	case 32770:
		;
		int palette1 = content[32768];
		int palette2 = content[32769];
		if (palette1 > 15 || palette2 > 15)
			return false;
		RECOIL_SetSize(self, 256, 256, RECOILResolution_BK1X1, 2);
		RECOIL_DecodeBkColorFrame(self, content, palette1, 0);
		RECOIL_DecodeBkColorFrame(self, content, palette2, 1);
		return RECOIL_ApplyBlend(self);
	default:
		return false;
	}
}

static bool RECOIL_DecodeVectorSpr(RECOIL *self, uint8_t const *content, int contentLength)
{
	VectorSprStream rle;
	VectorSprStream_Construct(&rle);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentLength;
	uint8_t unpacked[32768];
	if (!RleStream_Unpack(&rle.base.base, unpacked, 0, 1, 32768))
		return false;
	for (int i = 0; i < 16; i++) {
		int c = content[i];
		self->contentPalette[i] = (c & 7) * 73 >> 1 << 16 | (c >> 3 & 7) * 72 >> 1 << 8 | (c >> 6) * 85;
	}
	RECOIL_SetSize(self, 256, 256, RECOILResolution_VECTOR1X1, 1);
	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 256; x++)
			self->pixels[(y << 8) + x] = self->contentPalette[RECOIL_GetBitplanePixel(unpacked, (31 - (x >> 3)) << 8 | y, x, 4, 8192)];
	}
	return true;
}

static bool RECOIL_DecodePi9(RECOIL *self, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 7684:
	case 7808:
	case 7936:
		return RECOIL_DecodeGr9(self, content, 7680);
	case 7720:
		return RECOIL_DecodeApc(self, content, contentLength);
	default:
		return RECOIL_DecodeFuckpaint(self, content, contentLength);
	}
}

static bool RECOIL_IsPaint256(const char *filename)
{
	ptrdiff_t i = (ptrdiff_t) strlen(filename) - 10;
	if (i < 0)
		return false;
	if (i > 0 && filename[i - 1] != '/' && filename[i - 1] != '\\')
		return false;
	return (filename[i] | 32) == 'p' && (filename[i + 1] | 32) == 'a' && (filename[i + 2] | 32) == 'i' && (filename[i + 3] | 32) == 'n' && (filename[i + 4] | 32) == 't' && filename[i + 5] != '/' && filename[i + 5] != '\\';
}

static bool RECOIL_DecodePic(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	if (RECOIL_DecodePsion3Pic(self, content, contentLength) || RECOIL_DecodeX68KPic(self, content, contentLength) || RECOIL_DecodeAtari8Koala(self, content, 0, contentLength))
		return true;
	switch (contentLength) {
	case 3325:
		return RECOIL_DecodeVisualizer(self, content);
	case 4325:
		return RECOIL_DecodeGad(self, content, contentLength);
	case 7680:
		return RECOIL_IsPaint256(filename) ? RECOIL_Decode256(self, content, contentLength) : RECOIL_DecodeGr8(self, content, contentLength);
	case 7681:
	case 7682:
	case 7683:
	case 7684:
	case 7685:
		return RECOIL_DecodeMic(self, NULL, content, contentLength);
	case 16384:
		return RECOIL_DecodeBkColor(self, content, 0);
	case 32000:
		return RECOIL_DecodeDoo(self, content, contentLength);
	case 32768:
		return RECOIL_DecodeAppleIIShr(self, content, contentLength);
	default:
		return RECOIL_DecodeStPi(self, content, contentLength) || RECOIL_DecodeSc8(self, NULL, content, contentLength);
	}
}

static bool RECOIL_DecodeScr(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	switch (contentLength) {
	case 960:
		return RECOIL_DecodeGr0(self, content, contentLength);
	case 1002:
		return RECOIL_DecodeScrCol(self, filename, content, contentLength);
	case 6144:
		RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
		RECOIL_DecodeZx(self, content, 0, -1, -3, 0);
		return true;
	case 6912:
	case 6913:
		RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
		RECOIL_DecodeZx(self, content, 0, 6144, 3, 0);
		return true;
	case 6976:
		RECOIL_SetUlaPlus(self, content, 6912);
		RECOIL_DecodeZx(self, content, 0, 6144, 3, 0);
		return true;
	case 12288:
		RECOIL_SetZx(self, RECOILResolution_TIMEX1X1, 1);
		RECOIL_DecodeZx(self, content, 0, 6144, -1, 0);
		return true;
	case 12289:
		RECOIL_SetSize(self, 512, 384, RECOILResolution_TIMEX1X2, 1);
		RECOIL_DecodeTimexHires(self, content, 0, 0);
		return true;
	case 12352:
		RECOIL_SetUlaPlus(self, content, 12288);
		RECOIL_DecodeZx(self, content, 0, 6144, -1, 0);
		return true;
	case 16000:
		RECOIL_SetSize(self, 640, 400, RECOILResolution_MC05151X2, 1);
		self->contentPalette[0] = 0;
		self->contentPalette[1] = 16777215;
		RECOIL_DecodeScaledBitplanes(self, content, 0, 640, 200, 1, false, NULL);
		return true;
	case 32768:
		return RECOIL_DecodeAppleIIShr(self, content, contentLength);
	default:
		return RECOIL_DecodeAmstradScr(self, filename, content, contentLength);
	}
}

static bool RECOIL_DecodeFlfFont(RECOIL *self, uint8_t const *content, int contentOffset, int contentLength, int columns, int rows, RECOILResolution resolution, int const *palette, int colors, int xMask, int cMask)
{
	if (contentLength != contentOffset + columns * rows * 12)
		return false;
	int width = columns << 3;
	int height = rows << 3;
	RECOIL_SetSize(self, width, height, resolution, 1);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int offset = contentOffset + ((y >> 3) * columns + (x >> 3)) * 12;
			int c = content[offset + (y & 7)] >> (x & xMask) & cMask;
			c = content[offset + 8 + c];
			if (c >= colors)
				return false;
			self->pixels[y * width + x] = palette[c];
		}
	}
	return true;
}

static bool RECOIL_DecodeFlfBytes(RECOIL *self, uint8_t const *content, int contentLength)
{
	int colorsOffset = 14 + 320 * self->height;
	if (contentLength < colorsOffset + 6)
		return false;
	int colors = content[colorsOffset - 1];
	if (colors == 0)
		colors = 256;
	switch (contentLength - colorsOffset - colors * 3) {
	case 0:
	case 256:
		break;
	default:
		return false;
	}
	RECOIL_DecodeR8G8B8Colors(content, colorsOffset, colors, self->contentPalette, 0);
	RECOIL_DecodeBytes(self, content, 13);
	return true;
}

static bool RECOIL_DecodeFlf(RECOIL *self, uint8_t const *content, int contentLength)
{
	if (contentLength < 20 || !RECOIL_IsStringAt(content, 0, "FLUFF64"))
		return false;
	memset(self->contentPalette, 0, sizeof(self->contentPalette));
	switch (content[11]) {
	case 1:
		return RECOIL_DecodeFlfFont(self, content, 15, contentLength, 40, 25, RECOILResolution_C642X1, self->c64Palette, 16, 6, 3);
	case 4:
	case 5:
		return RECOIL_DecodeFlfFont(self, content, 18, contentLength, 40, 25, RECOILResolution_C642X1, self->c64Palette, 16, 6, 3);
	case 6:
		return RECOIL_DecodeFlfFont(self, content, 18, contentLength, 40, 25, RECOILResolution_C641X1, self->c64Palette, 16, 7, 1);
	case 7:
		;
		int columns = content[15];
		int rows = content[16];
		int length = columns * rows;
		return contentLength >= 45 + (length << 1) && RECOIL_DecodePetScreen(self, content, 29 + length, 29, content[13], columns, rows);
	case 9:
		if (content[12] != 6)
			return false;
		return RECOIL_DecodeFlfFont(self, content, 20, contentLength, content[18], content[19], RECOILResolution_VIC202X1, RECOIL_VIC20_PALETTE, 8, 6, 3);
	case 11:
		if (contentLength != 64269)
			return false;
		int c;
		switch (content[12]) {
		case 2:
			c = 1;
			break;
		case 3:
			c = 9;
			break;
		case 4:
			c = 0;
			break;
		case 5:
			c = 8;
			break;
		default:
			return false;
		}
		self->contentPalette[1] = RECOIL_CGA_PALETTE[c + 2];
		self->contentPalette[2] = RECOIL_CGA_PALETTE[c + 4];
		self->contentPalette[3] = RECOIL_CGA_PALETTE[c + 6];
		RECOIL_SetSize(self, 320, 200, RECOILResolution_PC1X1, 1);
		RECOIL_DecodeBytes(self, content, 13);
		return true;
	case 12:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_AMIGA1X1, 1);
		return RECOIL_DecodeFlfBytes(self, content, contentLength);
	case 13:
		RECOIL_SetSize(self, 320, 256, RECOILResolution_AMIGA1X1, 1);
		return RECOIL_DecodeFlfBytes(self, content, contentLength);
	case 22:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_ST1X1, 1);
		return RECOIL_DecodeFlfBytes(self, content, contentLength);
	case 24:
		if (content[12] != 11 || contentLength != 32269)
			return false;
		RECOIL_SetAmstradFirmwarePalette(self, content, 32205, 16);
		RECOIL_SetSize(self, 320, 200, RECOILResolution_AMSTRAD2X1, 1);
		RECOIL_DecodeBytes(self, content, 13);
		return true;
	case 25:
		if (content[12] != 11 || contentLength < 282)
			return false;
		int width = RECOIL_Get32LittleEndian(content, 13);
		int height = RECOIL_Get32LittleEndian(content, 17);
		if (RECOIL_Get32LittleEndian(content, 21) != 0 || !RECOIL_SetSize(self, width << 1, height, RECOILResolution_AMSTRAD2X1, 1) || contentLength != 281 + width * height)
			return false;
		RECOIL_SetAmstradFirmwarePalette(self, content, contentLength - 64, 16);
		RECOIL_DecodeBytes(self, content, 25);
		return true;
	case 26:
		if (content[12] != 12)
			return false;
		switch (content[13]) {
		case 4:
			if (contentLength != 82190)
				return false;
			self->contentPalette[1] = 16777215;
			RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC1X1, 1);
			RECOIL_DecodeBytes(self, content, 13);
			return true;
		case 5:
			if (contentLength != 41230)
				return false;
			memcpy(self->contentPalette, RECOIL_BBC_PALETTE2_BIT, 4 * sizeof(int));
			RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC2X1, 1);
			RECOIL_DecodeBytes(self, content, 13);
			return true;
		default:
			return false;
		}
	case 27:
		RECOIL_SetSize(self, 320, 200, RECOILResolution_PC1X1, 1);
		return RECOIL_DecodeFlfBytes(self, content, contentLength);
	case 28:
		if (content[12] != 14 || contentLength < 49165)
			return false;
		RECOIL_SetZx(self, RECOILResolution_SPECTRUM1X1, 1);
		RECOIL_DecodeBytes(self, content, 13);
		return true;
	default:
		return false;
	}
}

bool RECOIL_IsOurFile(const char *filename)
{
	switch (RECOIL_GetPackedExt(filename)) {
	case 540423474:
	case 538976307:
	case 825242163:
	case 544498228:
	case 543780148:
	case 543977524:
	case 544043060:
	case 543372342:
	case 538976353:
	case 544355425:
	case 540292705:
	case 543648119:
	case 544432481:
	case 543715433:
	case 543519336:
	case 543908449:
	case 544432993:
	case 543975009:
	case 544237409:
	case 544434017:
	case 543976545:
	case 543780193:
	case 540175969:
	case 540307041:
	case 540372577:
	case 540176481:
	case 540242017:
	case 544632929:
	case 543778660:
	case 544237412:
	case 543388517:
	case 543386729:
	case 544045680:
	case 543256673:
	case 543387745:
	case 544042096:
	case 543977569:
	case 544239713:
	case 544436321:
	case 544502369:
	case 544633441:
	case 544371809:
	case 544679522:
	case 544702306:
	case 540041826:
	case 540107362:
	case 540172898:
	case 540303970:
	case 540369506:
	case 543646306:
	case 544236642:
	case 543975010:
	case 1768711778:
	case 540632930:
	case 543975778:
	case 1937076834:
	case 538996841:
	case 1952672112:
	case 540618855:
	case 544237410:
	case 543648610:
	case 544435042:
	case 540109922:
	case 540175458:
	case 540240994:
	case 543452258:
	case 543976802:
	case 543648870:
	case 538996834:
	case 540110946:
	case 540176482:
	case 540307554:
	case 540438626:
	case 540569698:
	case 540094563:
	case 540160099:
	case 540291171:
	case 540422243:
	case 540553315:
	case 540422499:
	case 540291683:
	case 540160867:
	case 543977570:
	case 544567906:
	case 538997602:
	case 538993255:
	case 538994544:
	case 543388514:
	case 878931298:
	case 544240482:
	case 540107107:
	case 540172643:
	case 540238179:
	case 543777635:
	case 544564323:
	case 540108131:
	case 540173667:
	case 540239203:
	case 543974755:
	case 1768711779:
	case 544761699:
	case 539256931:
	case 540305507:
	case 540436579:
	case 540567651:
	case 543516771:
	case 544368739:
	case 544434275:
	case 544761955:
	case 544106851:
	case 543517795:
	case 544238691:
	case 540372323:
	case 544238947:
	case 543977315:
	case 540242019:
	case 543780963:
	case 544370787:
	case 544501859:
	case 543650403:
	case 544044131:
	case 544503139:
	case 543651683:
	case 540303716:
	case 544235876:
	case 540107620:
	case 538993764:
	case 544236644:
	case 544499048:
	case 543715442:
	case 543974756:
	case 540108644:
	case 1919379556:
	case 544368740:
	case 544106852:
	case 544500068:
	case 544042084:
	case 543977316:
	case 543450466:
	case 543451510:
	case 544173924:
	case 543715428:
	case 543650404:
	case 543978084:
	case 544238692:
	case 544895588:
	case 544240228:
	case 540112228:
	case 544175460:
	case 540177764:
	case 543449701:
	case 543777637:
	case 544236389:
	case 543386981:
	case 543256677:
	case 543716197:
	case 544043877:
	case 543259237:
	case 540031078:
	case 543777382:
	case 544236390:
	case 544501862:
	case 540173414:
	case 543450470:
	case 543975014:
	case 1768711782:
	case 543516518:
	case 543583334:
	case 543779942:
	case 544042086:
	case 540175974:
	case 544501350:
	case 538996838:
	case 540176486:
	case 544370790:
	case 543388774:
	case 543978854:
	case 544109926:
	case 543258470:
	case 538976359:
	case 540029287:
	case 540094823:
	case 543568487:
	case 543308135:
	case 544422247:
	case 543450739:
	case 543450471:
	case 543319655:
	case 538994535:
	case 543647847:
	case 543648103:
	case 540372071:
	case 540371059:
	case 540437607:
	case 540436595:
	case 540503143:
	case 540502131:
	case 540568679:
	case 540567667:
	case 543255655:
	case 543321191:
	case 543254643:
	case 543320179:
	case 543386727:
	case 544435303:
	case 543453031:
	case 538997351:
	case 538997603:
	case 540045927:
	case 543388513:
	case 540111463:
	case 540176999:
	case 540242535:
	case 540504679:
	case 540570215:
	case 540635751:
	case 1882813031:
	case 543322727:
	case 544174695:
	case 543584871:
	case 544240231:
	case 544764519:
	case 538997607:
	case 1936157033:
	case 543896115:
	case 544109927:
	case 544039528:
	case 544434022:
	case 544108397:
	case 543449959:
	case 543318888:
	case 544039784:
	case 543450472:
	case 543385192:
	case 543450728:
	case 543319912:
	case 544368488:
	case 544041320:
	case 544237928:
	case 544369000:
	case 543517800:
	case 543583336:
	case 543517032:
	case 544369768:
	case 543387752:
	case 543780968:
	case 544043112:
	case 544436328:
	case 538997352:
	case 540177000:
	case 543777640:
	case 543650408:
	case 544043624:
	case 544436840:
	case 540177256:
	case 540238441:
	case 543777385:
	case 540107625:
	case 540173161:
	case 540238697:
	case 543515497:
	case 544105321:
	case 543581801:
	case 1835164513:
	case 1835099490:
	case 544498532:
	case 1987339108:
	case 1885693284:
	case 538997348:
	case 544039272:
	case 913138024:
	case 946692456:
	case 544039532:
	case 1835166825:
	case 538996845:
	case 945973106:
	case 1851942770:
	case 1835100275:
	case 543975017:
	case 543516521:
	case 543516777:
	case 544041321:
	case 543452265:
	case 543517801:
	case 544435305:
	case 538996073:
	case 543649129:
	case 1735223668:
	case 1735223672:
	case 544107881:
	case 1868983913:
	case 543649385:
	case 544239209:
	case 544435817:
	case 544501353:
	case 540176489:
	case 543387753:
	case 544501865:
	case 543519340:
	case 540177001:
	case 543650409:
	case 543716201:
	case 544043881:
	case 544502633:
	case 544237418:
	case 538995306:
	case 544761451:
	case 543451499:
	case 543255659:
	case 543256427:
	case 544043122:
	case 544370795:
	case 544437099:
	case 540308587:
	case 544830571:
	case 543515500:
	case 544040044:
	case 544171372:
	case 540242028:
	case 543912044:
	case 543912045:
	case 543912040:
	case 544044396:
	case 543383917:
	case 1735683696:
	case 543646061:
	case 543779693:
	case 544235885:
	case 544760173:
	case 543646317:
	case 538993517:
	case 543712109:
	case 543777645:
	case 544236397:
	case 1886413677:
	case 544433005:
	case 538994541:
	case 540108653:
	case 540174189:
	case 540305261:
	case 540567405:
	case 543254381:
	case 544237421:
	case 543385965:
	case 543582573:
	case 543648109:
	case 543975789:
	case 544434541:
	case 540109933:
	case 543517805:
	case 544500845:
	case 543977581:
	case 544239725:
	case 543978349:
	case 544240493:
	case 543585645:
	case 543782253:
	case 544241005:
	case 544372077:
	case 543782765:
	case 1852405613:
	case 540113005:
	case 544171374:
	case 540241006:
	case 544304238:
	case 543585646:
	case 544241006:
	case 543783022:
	case 543842927:
	case 544236399:
	case 543780973:
	case 1667854445:
	case 543581295:
	case 538976368:
	case 540094832:
	case 543372144:
	case 540095600:
	case 543765616:
	case 540292720:
	case 544828518:
	case 540238192:
	case 543383920:
	case 1953456752:
	case 544760432:
	case 540107632:
	case 540173168:
	case 540238704:
	case 543777648:
	case 544433008:
	case 544498544:
	case 544367728:
	case 544499056:
	case 540108656:
	case 540174192:
	case 540239728:
	case 543385456:
	case 543582064:
	case 544368496:
	case 538995056:
	case 540109168:
	case 540174704:
	case 540240240:
	case 540371312:
	case 540436848:
	case 543716723:
	case 540305776:
	case 540502384:
	case 540567920:
	case 540633456:
	case 543385968:
	case 811821424:
	case 544762224:
	case 540306544:
	case 543255664:
	case 544435312:
	case 543452528:
	case 543649136:
	case 544501360:
	case 538996848:
	case 543715440:
	case 544239728:
	case 543388528:
	case 543585136:
	case 538981489:
	case 543646066:
	case 1667719538:
	case 544235890:
	case 544694642:
	case 543319922:
	case 543713138:
	case 544237938:
	case 543517810:
	case 540044658:
	case 540110194:
	case 540175730:
	case 540241266:
	case 540306802:
	case 538996850:
	case 544174194:
	case 543713639:
	case 543717234:
	case 543979378:
	case 544438642:
	case 544366963:
	case 540044387:
	case 540109923:
	case 540175459:
	case 540043120:
	case 540042099:
	case 540107635:
	case 540173171:
	case 540238707:
	case 540304243:
	case 540369779:
	case 540370279:
	case 540435315:
	case 540500851:
	case 540501351:
	case 540566387:
	case 540566887:
	case 540570227:
	case 543253363:
	case 543318899:
	case 543384435:
	case 540042355:
	case 540107891:
	case 540173427:
	case 544630131:
	case 544436851:
	case 543910521:
	case 544367475:
	case 540239731:
	case 543516531:
	case 544761715:
	case 540108915:
	case 540174451:
	case 540239987:
	case 808464947:
	case 543385715:
	case 543516787:
	case 543582323:
	case 543778931:
	case 544237683:
	case 544368755:
	case 544761971:
	case 543582579:
	case 544238451:
	case 543387763:
	case 543453299:
	case 544370803:
	case 544436339:
	case 544567411:
	case 544764019:
	case 540373619:
	case 540439155:
	case 540504691:
	case 543781491:
	case 544502387:
	case 540111731:
	case 540177267:
	case 540242803:
	case 540308339:
	case 879977331:
	case 543322995:
	case 544764787:
	case 543978611:
	case 544240755:
	case 543651955:
	case 544438387:
	case 544236404:
	case 540108660:
	case 544041332:
	case 544237940:
	case 540306548:
	case 540110452:
	case 540175988:
	case 540241524:
	case 540307060:
	case 540372596:
	case 540438132:
	case 544829044:
	case 543780980:
	case 543519348:
	case 544240244:
	case 544567924:
	case 540047476:
	case 543520884:
	case 544438388:
	case 543975029:
	case 543582581:
	case 544039542:
	case 538996066:
	case 543778934:
	case 543385974:
	case 543388534:
	case 543783542:
	case 544106871:
	case 543452791:
	case 543975032:
	case 543254392:
	case 544238712:
	case 544041338:
	case 540306810:
	case 544042874:
	case 540110970:
	case 538997626:
	case 544241786:
	case 544438394:
		return true;
	default:
		return false;
	}
}

bool RECOIL_Decode(RECOIL *self, const char *filename, uint8_t const *content, int contentLength)
{
	switch (RECOIL_GetPackedExt(filename)) {
	case 540423474:
		return RECOIL_DecodeIff(self, content, contentLength, RECOILResolution_AMIGA1X1) || RECOIL_Decode256(self, content, contentLength);
	case 538976307:
		return RECOIL_Decode3(self, content, contentLength);
	case 825242163:
		return RECOIL_Decode3201(self, content, contentLength);
	case 544498228:
		return RECOIL_Decode4bt(self, content, contentLength);
	case 543780148:
		return RECOIL_Decode4mi(self, content, contentLength);
	case 543977524:
		return RECOIL_Decode4pl(self, content, contentLength);
	case 544043060:
		return RECOIL_Decode4pm(self, content, contentLength);
	case 543372342:
		return RECOIL_Decode64c(self, content, contentLength);
	case 538976353:
		return RECOIL_DecodeA(self, content, contentLength);
	case 544355425:
		return RECOIL_DecodeA4r(self, content, contentLength);
	case 540292705:
	case 543648119:
		return contentLength == 10242 && RECOIL_DecodeC64Multicolor(self, content, 2, 8194, 9218, 10241);
	case 544432481:
	case 543715433:
	case 543519336:
		return RECOIL_DecodeIph(self, content, contentLength);
	case 543908449:
		return RECOIL_DecodeAbk(self, content, contentLength);
	case 544432993:
		return RECOIL_DecodeAcs(self, content, contentLength);
	case 543975009:
		return RECOIL_DecodeAfl(self, content, contentLength);
	case 544237409:
		return RECOIL_DecodeAgp(self, content, contentLength);
	case 544434017:
		return RECOIL_DecodeAgs(self, content, contentLength);
	case 543976545:
		return RECOIL_DecodeAll(self, content, contentLength);
	case 543780193:
		return RECOIL_DecodeAmi(self, content, contentLength);
	case 540175969:
		return RECOIL_DecodeAn2(self, content, contentLength);
	case 540307041:
		return RECOIL_DecodeAn4(self, content, contentLength, 0);
	case 540372577:
		return RECOIL_DecodeAn4(self, content, contentLength, 1);
	case 540176481:
		return RECOIL_Decode256(self, content, contentLength);
	case 540242017:
	case 544632929:
	case 543778660:
	case 544237412:
	case 543388517:
	case 543386729:
	case 544045680:
		return RECOIL_DecodeAp3(self, content, contentLength);
	case 543256673:
	case 543387745:
	case 544042096:
		return RECOIL_DecodeApc(self, content, contentLength);
	case 543977569:
		return RECOIL_DecodeApl(self, content, contentLength);
	case 544239713:
		return RECOIL_DecodeApp(self, content, contentLength);
	case 544436321:
		return RECOIL_DecodeAps(self, content, contentLength);
	case 544502369:
		return RECOIL_DecodeIph(self, content, contentLength) || RECOIL_DecodeArtDirector(self, content, contentLength) || RECOIL_DecodeGfaArtist(self, content, contentLength) || RECOIL_DecodeDoo(self, content, contentLength) || RECOIL_DecodePaletteMaster(self, content, contentLength) || RECOIL_DecodeAtari8Artist(self, content, contentLength) || RECOIL_DecodeMonoArt(self, content, contentLength) || RECOIL_DecodeAsciiArtEditor(self, content, contentLength);
	case 544633441:
		return RECOIL_DecodeArtMaster88(self, content, contentLength);
	case 544371809:
		return RECOIL_DecodeAtr(self, content, contentLength);
	case 544679522:
	case 544702306:
		return RECOIL_DecodeBw(self, content, contentLength);
	case 540041826:
		return RECOIL_DecodeBb0(self, content, contentLength, RECOIL_BBC_PALETTE1_BIT);
	case 540107362:
		return RECOIL_DecodeBb1(self, content, contentLength, RECOIL_BBC_PALETTE2_BIT);
	case 540172898:
		return RECOIL_DecodeBb2(self, content, contentLength, RECOIL_BBC_PALETTE);
	case 540303970:
		return RECOIL_DecodeBb4(self, content, contentLength, RECOIL_BBC_PALETTE1_BIT);
	case 540369506:
		return RECOIL_DecodeBb5(self, content, contentLength, RECOIL_BBC_PALETTE2_BIT);
	case 543646306:
		return RECOIL_DecodeBbg(self, content, contentLength);
	case 544236642:
		return RECOIL_DecodeBdp(self, content, contentLength);
	case 543975010:
	case 1768711778:
		return RECOIL_DecodeBfli(self, content, contentLength);
	case 540632930:
	case 540618855:
		return RECOIL_DecodeG09(self, content, contentLength);
	case 544237410:
		return RECOIL_DecodeBgp(self, content, contentLength);
	case 543975778:
		return RECOIL_DecodeBil(self, content, contentLength);
	case 543648610:
		return RECOIL_DecodeBkg(self, content, contentLength);
	case 544435042:
		return RECOIL_DecodeBks(self, content, contentLength);
	case 1937076834:
	case 538996841:
	case 1952672112:
		return RECOIL_DecodeBrus(self, content, contentLength);
	case 540109922:
	case 540175458:
	case 540240994:
		return RECOIL_DecodeIff(self, content, contentLength, RECOILResolution_ST1X1);
	case 543452258:
		return RECOIL_DecodeBld(self, content, contentLength);
	case 543976802:
	case 543648870:
		return RECOIL_DecodeBml(self, content, contentLength);
	case 538996834:
		return RECOIL_DecodeBp(self, content, contentLength);
	case 540110946:
	case 540176482:
	case 540307554:
	case 540438626:
	case 540569698:
	case 540094563:
	case 540160099:
	case 540291171:
	case 540422243:
	case 540553315:
	case 540422499:
	case 540291683:
	case 540160867:
		return RECOIL_DecodeUimg(self, content, contentLength);
	case 543977570:
		return RECOIL_DecodeBpl(self, content, contentLength);
	case 544567906:
		return RECOIL_DecodeBru(self, content, contentLength);
	case 538997602:
	case 538993255:
	case 538994544:
		return RECOIL_DecodePrintfox(self, content, contentLength);
	case 543388514:
	case 878931298:
		return RECOIL_DecodeBsc(self, content, contentLength);
	case 544240482:
		return RECOIL_DecodeBsp(self, content, contentLength);
	case 540107107:
	case 540172643:
	case 540238179:
		return RECOIL_DecodeCa(self, content, contentLength);
	case 543777635:
		return RECOIL_DecodeCci(self, content, contentLength);
	case 544564323:
		return contentLength == 10277 && RECOIL_DecodeC64Multicolor(self, content, 275, 8275, 9275, 10275);
	case 540108131:
	case 540173667:
	case 540239203:
		return RECOIL_DecodeCe(self, content, contentLength);
	case 543974755:
		return RECOIL_DecodeCel(self, content, contentLength);
	case 1768711779:
		return RECOIL_DecodeCfli(self, content, contentLength);
	case 544761699:
		return RECOIL_DecodeCgx(self, content, contentLength);
	case 539256931:
		return RECOIL_DecodeChrd(self, content, contentLength);
	case 540305507:
	case 540436579:
	case 540567651:
		return RECOIL_DecodeCh8(self, content, contentLength);
	case 543516771:
		return contentLength == 20482 && RECOIL_DecodeC64Multicolor(self, content, 2, 16898, 18434, 20479);
	case 544368739:
		return RECOIL_DecodeChr(self, content, contentLength);
	case 544434275:
		return RECOIL_DecodeChs(self, content, contentLength);
	case 544761955:
		return RECOIL_DecodeChx(self, content, contentLength);
	case 544106851:
		return RECOIL_DecodeCin(self, content, contentLength);
	case 543517795:
		return RECOIL_DecodeCle(self, content, contentLength);
	case 544238691:
		return RECOIL_DecodeGodotClp(self, content, contentLength) || RECOIL_DecodeCocoClp(self, content, contentLength);
	case 540372323:
		return RECOIL_DecodeCm5(self, filename, content, contentLength);
	case 544238947:
		return RECOIL_DecodeDdGraph(self, filename, content, contentLength) || RECOIL_DecodeStCmp(self, content, contentLength);
	case 543977315:
		return RECOIL_DecodeCol(self, content, contentLength);
	case 540242019:
		return RECOIL_DecodeCp3(self, content, contentLength);
	case 543780963:
		return RECOIL_DecodeCpi(self, content, contentLength);
	case 544370787:
		return RECOIL_DecodeCpr(self, content, contentLength);
	case 544501859:
		return RECOIL_DecodeCpt(self, filename, content, contentLength);
	case 543650403:
		return RECOIL_DecodeCrg(self, content, contentLength);
	case 544044131:
		return RECOIL_DecodeCtm(self, content, contentLength);
	case 544503139:
		return RECOIL_DecodeGr8Raw(self, content, contentLength, 96, 99);
	case 543651683:
		return contentLength == 10007 && RECOIL_DecodeIpt(self, content);
	case 540303716:
		return RECOIL_DecodeDa4(self, content, contentLength);
	case 544235876:
		return RECOIL_DecodeDap(self, content, contentLength);
	case 540107620:
		return RECOIL_DecodeDc1(self, content, contentLength);
	case 538993764:
	case 544236644:
	case 544499048:
	case 543715442:
		return RECOIL_DecodeDd(self, content, contentLength);
	case 543974756:
		return RECOIL_DecodeDel(self, content, contentLength);
	case 540108644:
		return RECOIL_DecodeDg1(self, content, contentLength);
	case 1919379556:
		return RECOIL_DecodeAppleIIDhr(self, content, contentLength);
	case 544368740:
		return RECOIL_DecodeIff(self, content, contentLength, RECOILResolution_AMIGA1X1) || RECOIL_DecodeAppleIIDhr(self, content, contentLength);
	case 544106852:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, false, 3);
	case 544500068:
		return RECOIL_DecodeDit(self, content, contentLength);
	case 544042084:
		return RECOIL_DecodeDlm(self, content, contentLength);
	case 543977316:
	case 543450466:
	case 543451510:
		return RECOIL_DecodeDol(self, content, contentLength);
	case 544173924:
		return RECOIL_DecodeDoo(self, content, contentLength);
	case 543715428:
		return RECOIL_DecodeDph(self, content, contentLength);
	case 543650404:
		return RECOIL_DecodeDrg(self, content, contentLength);
	case 543978084:
	case 544238692:
		return RECOIL_DecodeDrl(self, content, contentLength);
	case 544895588:
	case 544240228:
		return RECOIL_DecodeDrz(self, content, contentLength);
	case 540112228:
	case 544175460:
		return RECOIL_DecodeDuo(self, content, contentLength);
	case 540177764:
		return RECOIL_DecodeDu2(self, content, contentLength);
	case 543449701:
		return RECOIL_DecodeEbd(self, content, contentLength);
	case 543777637:
		return RECOIL_DecodeEci(self, content, contentLength);
	case 544236389:
		return RECOIL_DecodeEcp(self, content, contentLength);
	case 543386981:
		return RECOIL_DecodeEmc(self, content, contentLength);
	case 543256677:
		return RECOIL_DecodeEpa(self, content, contentLength);
	case 543716197:
		return RECOIL_DecodeEsh(self, content, contentLength);
	case 544043877:
		return RECOIL_DecodeEsm(self, content, contentLength);
	case 543259237:
		return RECOIL_DecodeEza(self, content, contentLength);
	case 540031078:
		return RECOIL_DecodeF80(self, content, contentLength);
	case 543777382:
		return RECOIL_DecodeFbi(self, content, contentLength);
	case 544236390:
	case 544501862:
		return contentLength == 10004 && RECOIL_DecodeIpt(self, content);
	case 540173414:
		return RECOIL_DecodeFli(self, content, contentLength);
	case 543450470:
		return RECOIL_DecodeFed(self, content, contentLength);
	case 543975014:
	case 1768711782:
		return RECOIL_DecodeFfli(self, content, contentLength);
	case 543516518:
		return RECOIL_DecodeFge(self, content, contentLength);
	case 543583334:
		return RECOIL_DecodeFlf(self, content, contentLength);
	case 543779942:
		return RECOIL_DecodeFli(self, content, contentLength) || RECOIL_DecodeBml(self, content, contentLength);
	case 544042086:
		return RECOIL_DecodeFlm(self, content, contentLength);
	case 540175974:
		return RECOIL_DecodeFn2(self, content, contentLength);
	case 544501350:
		return RECOIL_DecodePct(self, content, contentLength) || RECOIL_DecodeGdosFnt(self, content, contentLength) || RECOIL_DecodeAtari8Fnt(self, content, contentLength) || RECOIL_DecodeStFnt(self, content, contentLength) || RECOIL_DecodeAmstradFnt(self, content, contentLength) || RECOIL_DecodeImage72Fnt(self, content, contentLength);
	case 538996838:
		return RECOIL_DecodeFp(self, content, contentLength);
	case 540176486:
		return RECOIL_DecodeC64Fun(self, content, contentLength);
	case 544370790:
		return RECOIL_DecodeFpr(self, content, contentLength);
	case 543388774:
		return RECOIL_DecodeFtc(self, content, contentLength);
	case 543978854:
		return RECOIL_DecodeFul(self, content, contentLength);
	case 544109926:
		return RECOIL_DecodeC64Fun(self, content, contentLength) || RECOIL_DecodeFalconFun(self, content, contentLength);
	case 543258470:
		return RECOIL_DecodeFwa(self, content, contentLength);
	case 538976359:
		return RECOIL_DecodeG(self, content, contentLength);
	case 540029287:
		return RECOIL_DecodeG10(self, content, contentLength);
	case 540094823:
		return RECOIL_DecodeG11(self, content, contentLength);
	case 543568487:
		return RECOIL_DecodeG2f(self, content, contentLength);
	case 543308135:
		return RECOIL_DecodeG9b(self, content, contentLength);
	case 544422247:
	case 543450739:
		return RECOIL_DecodeG9s(self, content, contentLength);
	case 543450471:
		return RECOIL_DecodeGed(self, content, contentLength);
	case 543319655:
		return RECOIL_DecodeGfb(self, content, contentLength);
	case 538994535:
		return RECOIL_DecodeGg(self, content, contentLength);
	case 543647847:
		return RECOIL_DecodeGhg(self, content, contentLength);
	case 543648103:
		return RECOIL_DecodeIph(self, content, contentLength) || RECOIL_DecodeKoa(self, content, contentLength);
	case 540372071:
	case 540371059:
		return RECOIL_DecodeGl5(self, filename, content, contentLength);
	case 540437607:
	case 540436595:
		return RECOIL_DecodeGl6(self, filename, content, contentLength);
	case 540503143:
	case 540502131:
		return RECOIL_DecodeGl7(self, filename, content, contentLength);
	case 540568679:
	case 540567667:
		return RECOIL_DecodeGl8(self, content, contentLength);
	case 543255655:
	case 543321191:
	case 543254643:
	case 543320179:
		return RECOIL_DecodeGlYjk(self, filename, content, contentLength);
	case 543386727:
	case 544435303:
		return RECOIL_DecodeGlYjk(self, NULL, content, contentLength);
	case 543453031:
		return RECOIL_DecodeGod(self, content, contentLength);
	case 538997351:
	case 538997603:
		return RECOIL_DecodeGr(self, content, contentLength);
	case 540045927:
	case 543388513:
		return RECOIL_DecodeGr0(self, content, contentLength);
	case 540111463:
		return RECOIL_DecodeGr1(self, content, contentLength, 0);
	case 540176999:
		return RECOIL_DecodeGr1(self, content, contentLength, 1);
	case 540242535:
		return RECOIL_DecodeGr3(self, content, contentLength);
	case 540504679:
		return RECOIL_DecodeGr7(self, content, 0, contentLength);
	case 540570215:
		return RECOIL_DecodeGr8(self, content, contentLength);
	case 540635751:
		return RECOIL_DecodeGr9(self, content, contentLength);
	case 1882813031:
		return RECOIL_DecodeGr9p(self, content, contentLength);
	case 543322727:
	case 544174695:
		return RECOIL_DecodeGrb(self, content, contentLength);
	case 543584871:
		return RECOIL_DecodeCocoMax(self, content, contentLength) || RECOIL_DecodeProfiGrf(self, content, contentLength);
	case 544240231:
		return RECOIL_DecodeSc2(self, content, contentLength);
	case 544764519:
		return RECOIL_DecodeGrx(self, content, contentLength);
	case 538997607:
	case 1936157033:
	case 543896115:
		return RECOIL_DecodeApfShr(self, content, contentLength);
	case 544109927:
		return RECOIL_DecodeGun(self, content, contentLength);
	case 544039528:
	case 544434022:
	case 544108397:
	case 543449959:
		return RECOIL_DecodeC64Hir(self, content, contentLength);
	case 543318888:
		return RECOIL_DecodeHcb(self, content, contentLength);
	case 544039784:
		return RECOIL_DecodeHcm(self, content, contentLength);
	case 543450472:
		return contentLength == 9218 && RECOIL_DecodeHed(self, content);
	case 543385192:
	case 543450728:
		return RECOIL_DecodeHfc(self, content, contentLength);
	case 543319912:
		return RECOIL_DecodeHgb(self, content, contentLength);
	case 544368488:
		return RECOIL_DecodeHgr(self, content, contentLength);
	case 544041320:
		return RECOIL_DecodeHim(self, content, contentLength);
	case 544237928:
		return RECOIL_DecodeHip(self, content, contentLength);
	case 544369000:
		return RECOIL_DecodeFalconHir(self, content, contentLength) || RECOIL_DecodeC64Hir(self, content, contentLength) || RECOIL_DecodeHrs(self, content, contentLength);
	case 543517800:
		return RECOIL_DecodeHle(self, content, contentLength);
	case 543583336:
	case 543517032:
		return RECOIL_DecodeHlf(self, content, contentLength);
	case 544369768:
		return RECOIL_DecodeHlr(self, content, contentLength);
	case 543387752:
		return RECOIL_DecodeIph(self, content, contentLength);
	case 543780968:
		return RECOIL_DecodeC64Hir(self, content, contentLength) || RECOIL_DecodeIph(self, content, contentLength);
	case 544043112:
		return RECOIL_DecodeHpm(self, content, contentLength);
	case 544436328:
		return RECOIL_DecodeHps(self, content, contentLength);
	case 538997352:
		return RECOIL_DecodeTrsHr(self, content, contentLength) || RECOIL_DecodeAtari8Hr(self, content, contentLength);
	case 540177000:
	case 543777640:
		return RECOIL_DecodeHr2(self, content, contentLength);
	case 543650408:
		return RECOIL_DecodeHrg(self, content, contentLength);
	case 544043624:
		return RECOIL_DecodeHrm(self, content, contentLength);
	case 544436840:
		return RECOIL_DecodeHrs(self, content, contentLength);
	case 540177256:
		return RECOIL_DecodeHs2(self, content, contentLength);
	case 540238441:
	case 543777385:
		return RECOIL_DecodeIbi(self, content, contentLength);
	case 540107625:
	case 540173161:
	case 540238697:
		return RECOIL_DecodeIc(self, content, contentLength);
	case 543515497:
		return contentLength > 1024 && RECOIL_DecodeAtari8Ice(self, content, contentLength, true, content[0]);
	case 544105321:
		return RECOIL_DecodeStIcn(self, content, contentLength) || RECOIL_DecodePsion3Pic(self, content, contentLength) || RECOIL_DecodeAtari8Ice(self, content, contentLength, false, 17);
	case 543581801:
	case 1835164513:
	case 1835099490:
	case 544498532:
	case 1987339108:
	case 1885693284:
	case 538997348:
	case 544039272:
	case 913138024:
	case 946692456:
	case 544039532:
	case 1835166825:
	case 538996845:
	case 945973106:
	case 1851942770:
	case 1835100275:
		return RECOIL_DecodeIff(self, content, contentLength, RECOILResolution_AMIGA1X1);
	case 543975017:
		return RECOIL_DecodeGun(self, content, contentLength) || RECOIL_DecodeZxIfl(self, content, contentLength);
	case 543516521:
		return RECOIL_DecodeIge(self, content, contentLength);
	case 543516777:
		return RECOIL_DecodeIhe(self, content, contentLength);
	case 544041321:
		return RECOIL_DecodeIim(self, content, contentLength);
	case 543452265:
		return RECOIL_DecodeIld(self, content, contentLength);
	case 543517801:
		return RECOIL_DecodeIle(self, content, contentLength);
	case 544435305:
		return RECOIL_DecodeIls(self, content, contentLength);
	case 538996073:
		return RECOIL_DecodeIm(self, content, contentLength);
	case 543649129:
		return RECOIL_DecodeStImg(self, content, contentLength) || RECOIL_DecodeZxImg(self, content, contentLength) || RECOIL_DecodeArtMaster88(self, content, contentLength) || RECOIL_DecodeDaVinci(self, content, contentLength);
	case 1735223668:
	case 1735223672:
		return RECOIL_DecodeStImg(self, content, contentLength);
	case 544107881:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, false, 18);
	case 1868983913:
		return RECOIL_DecodeInfo(self, content, contentLength);
	case 543649385:
	case 544239209:
		return RECOIL_DecodeInp(self, content, contentLength);
	case 544435817:
		return RECOIL_DecodeIns(self, content, contentLength);
	case 544501353:
		return RECOIL_DecodeInt(self, content, contentLength) || RECOIL_DecodeInp(self, content, contentLength);
	case 540176489:
		return RECOIL_DecodeIp2(self, content, contentLength);
	case 543387753:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, false, 19);
	case 544501865:
	case 543519340:
		return contentLength == 10003 && RECOIL_DecodeIpt(self, content);
	case 540177001:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, false, 2);
	case 543650409:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, false, 1);
	case 543716201:
		return RECOIL_DecodeIsh(self, content, contentLength);
	case 544043881:
		return contentLength == 10218 && RECOIL_DecodeC64Multicolor(self, content, 1026, 9218, 2, 9217);
	case 544502633:
		return RECOIL_DecodeIst(self, content, contentLength);
	case 544237418:
		return RECOIL_DecodeJgp(self, content, contentLength);
	case 538995306:
		return RECOIL_DecodeJj(self, content, contentLength);
	case 544761451:
		return RECOIL_DecodeGr8Raw(self, content, contentLength, 56, 60);
	case 543451499:
		return RECOIL_DecodeKid(self, content, contentLength);
	case 543255659:
	case 543256427:
	case 544043122:
		return RECOIL_DecodeKoa(self, content, contentLength);
	case 544370795:
		return RECOIL_DecodeKpr(self, content, contentLength);
	case 544437099:
		return RECOIL_DecodeKss(self, content, contentLength);
	case 540308587:
	case 544830571:
		return RECOIL_DecodeKty(self, content, contentLength);
	case 543515500:
		return RECOIL_DecodeLce(self, content, contentLength);
	case 544040044:
		return RECOIL_DecodeLdm(self, content, contentLength);
	case 544171372:
		return RECOIL_DecodeLeo(self, content, contentLength);
	case 540242028:
		return RECOIL_DecodeLp3(self, content, contentLength);
	case 543912044:
		return RECOIL_DecodeDaliCompressed(self, content, contentLength, 0);
	case 543912045:
		return RECOIL_DecodeDaliCompressed(self, content, contentLength, 1);
	case 543912040:
		return RECOIL_DecodeDaliCompressed(self, content, contentLength, 2);
	case 544044396:
		return RECOIL_DecodeLum(self, filename, content, contentLength);
	case 543383917:
	case 1735683696:
		return RECOIL_DecodeMac(self, content, contentLength);
	case 543646061:
	case 543779693:
		return RECOIL_DecodeMag(self, content, contentLength);
	case 544235885:
		return RECOIL_DecodeEnvision(self, content, contentLength) || RECOIL_DecodeEnvisionPC(self, content, contentLength);
	case 544760173:
		return RECOIL_DecodeMag(self, content, contentLength) || RECOIL_DecodeAtari8Max(self, content, contentLength) || RECOIL_DecodeCocoMax(self, content, contentLength);
	case 543646317:
		return RECOIL_DecodeGr8Raw(self, content, contentLength, 512, 256);
	case 538993517:
		return RECOIL_DecodeMcMlt(self, content, contentLength, -1);
	case 543712109:
		return RECOIL_DecodeMch(self, content, contentLength);
	case 543777645:
		return RECOIL_DecodeMci(self, content, contentLength);
	case 544236397:
		return RECOIL_DecodeMcp(self, content, contentLength);
	case 1886413677:
		return RECOIL_DecodeMcpp(self, content, contentLength);
	case 544433005:
		return RECOIL_DecodeMcs(self, content, contentLength);
	case 538994541:
		return RECOIL_DecodeVic20Mg(self, content, contentLength);
	case 540108653:
	case 540174189:
	case 540305261:
	case 540567405:
		return RECOIL_DecodeMg(self, content, contentLength);
	case 543254381:
		return RECOIL_DecodeMga(self, content, contentLength);
	case 544237421:
		return RECOIL_DecodeMgp(self, content, contentLength);
	case 543385965:
		return RECOIL_DecodeMic(self, filename, content, contentLength);
	case 543582573:
		return RECOIL_DecodeMif(self, content, contentLength);
	case 543648109:
		return RECOIL_DecodeMig(self, content, contentLength);
	case 543975789:
		return RECOIL_DecodeMil(self, content, contentLength);
	case 544434541:
		return RECOIL_DecodeMis(self, content, contentLength);
	case 540109933:
		return RECOIL_DecodeMl1(self, content, contentLength);
	case 543517805:
		return RECOIL_DecodeMle(self, content, contentLength);
	case 544500845:
		return RECOIL_DecodeMcMlt(self, content, contentLength, 0);
	case 543977581:
		return RECOIL_DecodeMpl(self, content, contentLength);
	case 544239725:
		return RECOIL_DecodeMpp(self, content, contentLength);
	case 543978349:
		return RECOIL_DecodeMsl(self, content, contentLength);
	case 544240493:
		return RECOIL_DecodeMsp(self, content, contentLength);
	case 543585645:
		return RECOIL_DecodeMuf(self, content, contentLength);
	case 543782253:
		return RECOIL_DecodeMui(self, content, contentLength);
	case 544241005:
		return RECOIL_DecodeMup(self, content, contentLength);
	case 544372077:
		return RECOIL_DecodeMur(self, filename, content, contentLength);
	case 543782765:
	case 1852405613:
		return RECOIL_DecodeMwi(self, content, contentLength);
	case 540113005:
		return RECOIL_DecodeMx1(self, content, contentLength);
	case 544171374:
		return RECOIL_DecodeNeo(self, filename, content, contentLength) || RECOIL_DecodeIff(self, content, contentLength, RECOILResolution_STE1X1);
	case 540241006:
		return RECOIL_DecodeNl3(self, content, contentLength);
	case 544304238:
		return RECOIL_DecodeNlq(self, content, contentLength);
	case 543585646:
		return RECOIL_DecodeNuf(self, content, contentLength);
	case 544241006:
		return RECOIL_DecodeNup(self, content, contentLength);
	case 543783022:
		return RECOIL_DecodeNxi(self, content, contentLength);
	case 543842927:
		return RECOIL_DecodeObj(self, content, contentLength);
	case 544236399:
	case 543780973:
	case 1667854445:
		return RECOIL_DecodeOcp(self, content, contentLength);
	case 543581295:
		return RECOIL_DecodeOdf(self, content, contentLength);
	case 538976368:
		return RECOIL_DecodeP(self, content, contentLength);
	case 540094832:
		return RECOIL_DecodeP11(self, content, contentLength);
	case 543372144:
		return RECOIL_DecodeP3c(self, content, contentLength);
	case 540095600:
		return RECOIL_DecodeCocoMax(self, content, contentLength);
	case 543765616:
		return RECOIL_DecodeP4i(self, content, contentLength);
	case 540292720:
	case 544828518:
		return contentLength == 10050 && RECOIL_DecodeC64Multicolor(self, content, 2050, 1026, 2, 2049);
	case 540238192:
		return RECOIL_DecodeStPpp(self, content, contentLength);
	case 543383920:
		return RECOIL_DecodePac(self, content, contentLength);
	case 1953456752:
		return RECOIL_DecodePbot(self, content, contentLength);
	case 544760432:
		return RECOIL_DecodePbx(self, content, contentLength);
	case 540107632:
	case 540173168:
	case 540238704:
		return RECOIL_DecodePc(self, content, contentLength);
	case 543777648:
		return RECOIL_DecodePci(self, content, contentLength);
	case 544433008:
		return RECOIL_DecodePcs(self, content, contentLength);
	case 544498544:
		return RECOIL_DecodePct(self, content, contentLength);
	case 544367728:
		return RECOIL_DecodePdr(self, content, contentLength);
	case 544499056:
		return RECOIL_DecodePet(self, content, contentLength);
	case 540108656:
	case 540174192:
		return RECOIL_DecodeSc(self, content, contentLength) || RECOIL_DecodeGraphicsProcessor(self, content, contentLength);
	case 540239728:
		return RECOIL_DecodeGraphicsProcessor(self, content, contentLength);
	case 543385456:
		return RECOIL_DecodePgc(self, content, contentLength);
	case 543582064:
		return RECOIL_DecodePgf(self, content, contentLength);
	case 544368496:
		return RECOIL_DecodePgr(self, content, contentLength);
	case 538995056:
		return RECOIL_DecodePi(self, content, contentLength) || RECOIL_DecodeBpl(self, content, contentLength);
	case 540109168:
	case 540174704:
	case 540240240:
	case 540371312:
	case 540436848:
	case 543716723:
		return RECOIL_DecodeStPi(self, content, contentLength);
	case 540305776:
		return RECOIL_DecodeFuckpaint(self, content, contentLength) || RECOIL_DecodeStPi(self, content, contentLength);
	case 540502384:
		return RECOIL_DecodeFuckpaint(self, content, contentLength);
	case 540567920:
		return RECOIL_DecodePi8(self, content, contentLength);
	case 540633456:
		return RECOIL_DecodePi9(self, content, contentLength);
	case 543385968:
		return RECOIL_DecodePic(self, filename, content, contentLength);
	case 811821424:
		return RECOIL_DecodePic0(self, filename, content, contentLength);
	case 544762224:
		return RECOIL_DecodeFalconPix(self, content, contentLength) || RECOIL_DecodeCocoMax(self, content, contentLength) || RECOIL_DecodeAtari8Pix(self, content, contentLength);
	case 540306544:
		return RECOIL_DecodePl4(self, content, contentLength);
	case 543255664:
		return RECOIL_DecodePla(self, content, contentLength);
	case 544435312:
		return RECOIL_DecodePls(self, content, contentLength);
	case 543452528:
		return RECOIL_DecodePmd(self, content, contentLength);
	case 543649136:
		return RECOIL_DecodePmg(self, content, contentLength);
	case 544501360:
		return RECOIL_DecodeFalconPnt(self, content, contentLength) || RECOIL_DecodeTandyPnt(self, content, contentLength) || RECOIL_DecodeApfShr(self, content, contentLength) || RECOIL_DecodeMac(self, content, contentLength) || RECOIL_DecodeAppleIIShr(self, content, contentLength) || RECOIL_DecodePaintworks(self, content, contentLength);
	case 538996848:
		return RECOIL_DecodePp(self, content, contentLength);
	case 543715440:
		return RECOIL_DecodePph(self, filename, content, contentLength);
	case 544239728:
		return RECOIL_DecodeStPpp(self, content, contentLength) || RECOIL_DecodePp(self, content, contentLength);
	case 543388528:
		return RECOIL_DecodePsc(self, content, contentLength);
	case 543585136:
		return RECOIL_DecodePsf(self, content, contentLength);
	case 538981489:
		return RECOIL_DecodeQ4(self, content, contentLength);
	case 543646066:
		return RECOIL_DecodeRag(self, content, contentLength);
	case 1667719538:
		return RECOIL_DecodeRagc(self, content, contentLength);
	case 544235890:
		return RECOIL_DecodeRap(self, content, contentLength);
	case 544694642:
		return RECOIL_DecodeZx81Raw(self, content, contentLength) || RECOIL_DecodeAtari8Raw(self, content, contentLength) || RECOIL_DecodeRw(self, content, contentLength);
	case 543319922:
		return RECOIL_DecodeStRgb(self, content, contentLength) || RECOIL_DecodeAtari8Rgb(self, content, contentLength) || RECOIL_DecodeZxRgb(self, content, contentLength);
	case 543713138:
		return RECOIL_DecodeRgh(self, content, contentLength);
	case 544237938:
		return RECOIL_DecodeRip(self, content, contentLength);
	case 543517810:
		return RECOIL_DecodeRle(self, content, contentLength);
	case 540044658:
		return RECOIL_DecodeRm(self, content, contentLength, 0, RECOILResolution_XE2X2);
	case 540110194:
		return RECOIL_DecodeRm(self, content, contentLength, 1, RECOILResolution_XE4X1);
	case 540175730:
		return RECOIL_DecodeRm(self, content, contentLength, 2, RECOILResolution_XE4X1);
	case 540241266:
		return RECOIL_DecodeRm(self, content, contentLength, 3, RECOILResolution_XE4X1);
	case 540306802:
		return RECOIL_DecodeRm(self, content, contentLength, 4, RECOILResolution_XE2X1);
	case 538996850:
		return contentLength == 10242 && RECOIL_DecodeC64Multicolor(self, content, 1026, 2, 9218, -1);
	case 544174194:
	case 543713639:
		return RECOIL_DecodeRpo(self, content, contentLength);
	case 543717234:
	case 543979378:
		return RECOIL_DecodeRw(self, content, contentLength);
	case 544438642:
		return RECOIL_DecodeRys(self, content, contentLength);
	case 544366963:
		return contentLength == 10219 && RECOIL_DecodeC64Multicolor(self, content, 1026, 2, 9218, 1010);
	case 540044387:
	case 540109923:
	case 540175459:
	case 540043120:
	case 540042099:
	case 540107635:
		return RECOIL_DecodeSc(self, content, contentLength);
	case 540173171:
		return RECOIL_DecodeSc(self, content, contentLength) || RECOIL_DecodeSc2(self, content, contentLength);
	case 540238707:
		return RECOIL_DecodeSc3(self, content, contentLength);
	case 540304243:
		return RECOIL_DecodeSc4(self, content, contentLength);
	case 540369779:
	case 540370279:
		return RECOIL_DecodeSc5(self, filename, content, contentLength);
	case 540435315:
		return RECOIL_DecodeSc6(self, filename, content, contentLength);
	case 540500851:
	case 540501351:
		return RECOIL_DecodeSc7(self, filename, content, contentLength);
	case 540566387:
	case 540566887:
	case 540570227:
		return RECOIL_DecodeSc8(self, filename, content, contentLength);
	case 543253363:
	case 543318899:
		return RECOIL_DecodeSca(self, filename, content, contentLength);
	case 543384435:
	case 544436851:
	case 543910521:
		return RECOIL_DecodeScc(self, filename, content, contentLength);
	case 544367475:
		return RECOIL_DecodeScr(self, filename, content, contentLength);
	case 540042355:
		return RECOIL_DecodeSd(self, content, contentLength, 0);
	case 540107891:
		return RECOIL_DecodeSd(self, content, contentLength, 1);
	case 540173427:
		return RECOIL_DecodeSd(self, content, contentLength, 2);
	case 544630131:
		return RECOIL_DecodeSev(self, content, contentLength);
	case 540239731:
		return RECOIL_DecodeSg3(self, content, contentLength);
	case 543516531:
		return RECOIL_DecodeSge(self, content, contentLength);
	case 544761715:
		return RECOIL_DecodeSgx(self, content, contentLength);
	case 540108915:
		return RECOIL_DecodeSh1(self, content, contentLength);
	case 540174451:
		return RECOIL_DecodeSh2(self, content, contentLength);
	case 540239987:
	case 808464947:
		return RECOIL_DecodeApfShr(self, content, contentLength) || RECOIL_Decode3201(self, content, contentLength) || RECOIL_DecodeSh3(self, content, contentLength) || RECOIL_DecodeAppleIIShr(self, content, contentLength);
	case 543385715:
		return RECOIL_DecodeShc(self, content, contentLength) || RECOIL_DecodeGlYjk(self, NULL, content, contentLength);
	case 543516787:
		return RECOIL_DecodeShe(self, content, contentLength);
	case 543582323:
		return RECOIL_DecodeShf(self, content, contentLength);
	case 543778931:
		return RECOIL_DecodeShi(self, content, contentLength);
	case 544237683:
		return RECOIL_DecodeShp(self, content, contentLength);
	case 544368755:
		return RECOIL_DecodeApfShr(self, content, contentLength) || RECOIL_DecodeAppleIIShr(self, content, contentLength) || RECOIL_DecodeSh3(self, content, contentLength) || RECOIL_DecodeTrsShr(self, content, contentLength);
	case 544434291:
		return RECOIL_DecodeShs(self, content, contentLength);
	case 544761971:
		return RECOIL_DecodeShx(self, content, contentLength);
	case 543582579:
		return RECOIL_DecodeAtari8Sif(self, content, contentLength) || RECOIL_DecodeC64Sif(self, content, contentLength);
	case 544238451:
		return RECOIL_DecodeSkp(self, content, contentLength);
	case 543387763:
		return RECOIL_DecodeStSpc(self, content, contentLength) || RECOIL_DecodeAtari8Spc(self, content, contentLength);
	case 543453299:
		return RECOIL_DecodeSpd(self, content, contentLength);
	case 544370803:
		return RECOIL_DecodeSprEd(self, content, contentLength) || RECOIL_DecodeAppleSpr(self, content, contentLength) || RECOIL_DecodeAtari8Spr(self, content, contentLength) || RECOIL_DecodeVectorSpr(self, content, contentLength);
	case 544436339:
		return RECOIL_DecodeSps(self, content, contentLength);
	case 544567411:
		return RECOIL_DecodeSpu(self, content, contentLength);
	case 544764019:
		return RECOIL_DecodeSpx(self, content, contentLength);
	case 540373619:
		return RECOIL_DecodeSr5(self, filename, content, contentLength);
	case 540439155:
		return RECOIL_DecodeSr6(self, filename, content, contentLength);
	case 540504691:
		return RECOIL_DecodeSr7(self, filename, content, contentLength);
	case 543781491:
		return RECOIL_DecodeSri(self, filename, content, contentLength);
	case 544502387:
		return RECOIL_DecodeSrt(self, content, contentLength);
	case 540111731:
		return RECOIL_DecodeSs1(self, content, contentLength);
	case 540177267:
		return RECOIL_DecodeSs2(self, content, contentLength);
	case 540242803:
		return RECOIL_DecodeSs3(self, content, contentLength);
	case 540308339:
	case 879977331:
		return RECOIL_DecodeSs4(self, content, contentLength);
	case 543322995:
		return RECOIL_DecodeSsb(self, content, contentLength);
	case 544764787:
		return RECOIL_DecodeSsx(self, content, contentLength);
	case 543978611:
		return RECOIL_DecodeStl(self, content, contentLength);
	case 544240755:
		return RECOIL_DecodeGl6(self, NULL, content, contentLength);
	case 543651955:
		return RECOIL_DecodeSxg(self, content, contentLength);
	case 544438387:
		return RECOIL_DecodeSxs(self, content, contentLength);
	case 544236404:
		return RECOIL_DecodeTcp(self, content, contentLength);
	case 540108660:
		return RECOIL_DecodeTg1(self, content, contentLength);
	case 544041332:
		return RECOIL_DecodeTim(self, content, contentLength);
	case 544237940:
		return RECOIL_DecodeTip(self, content, contentLength);
	case 540306548:
		return RECOIL_DecodeTl4(self, content, contentLength);
	case 540110452:
	case 540175988:
	case 540241524:
	case 540307060:
	case 540372596:
	case 540438132:
	case 544829044:
		return RECOIL_DecodeTny(self, content, contentLength);
	case 543780980:
		return RECOIL_DecodeFalconPnt(self, content, contentLength);
	case 543519348:
		return RECOIL_DecodeTre(self, content, contentLength);
	case 544240244:
		return RECOIL_DecodeTrp(self, content, contentLength);
	case 544567924:
		return RECOIL_DecodeTru(self, content, contentLength);
	case 540047476:
		return RECOIL_DecodeTx0(self, content, contentLength);
	case 543520884:
		return RECOIL_DecodeTxe(self, content, contentLength);
	case 544438388:
		return RECOIL_DecodeTxs(self, content, contentLength);
	case 543975029:
		return RECOIL_DecodeUfl(self, content, contentLength);
	case 543582581:
		return RECOIL_DecodeUif(self, content, contentLength);
	case 544039542:
	case 538996066:
		return RECOIL_DecodeVbm(self, content, contentLength);
	case 543778934:
		return RECOIL_DecodeVhi(self, content, contentLength);
	case 543385974:
		return RECOIL_DecodeVic(self, content, contentLength);
	case 543388534:
		return RECOIL_DecodeVsc(self, filename, content, contentLength);
	case 543783542:
		return RECOIL_DecodeVzi(self, content, contentLength);
	case 544106871:
		return RECOIL_DecodeWin(self, filename, content, contentLength);
	case 543452791:
		return RECOIL_DecodeWnd(self, content, contentLength);
	case 543975032:
		return RECOIL_DecodeXfl(self, content, contentLength);
	case 543254392:
		return RECOIL_DecodeXga(self, content, contentLength);
	case 544238712:
		return RECOIL_DecodeXlp(self, content, contentLength);
	case 544041338:
		return RECOIL_DecodeZim(self, content, contentLength);
	case 540306810:
		return RECOIL_DecodeZm4(self, content, contentLength);
	case 544042874:
		return RECOIL_DecodeZom(self, content, contentLength);
	case 540110970:
		return RECOIL_DecodeZp1(self, content, contentLength);
	case 538997626:
		return RECOIL_DecodeZs(self, content, contentLength);
	case 544241786:
		return RECOIL_DecodeZxp(self, content, contentLength);
	case 544438394:
		return RECOIL_DecodeZxs(self, content, contentLength);
	default:
		return false;
	}
}

int RECOIL_GetWidth(const RECOIL *self)
{
	return self->width;
}

int RECOIL_GetHeight(const RECOIL *self)
{
	return self->height;
}

int const *RECOIL_GetPixels(const RECOIL *self)
{
	return self->pixels;
}

const char *RECOIL_GetPlatform(const RECOIL *self)
{
	switch (self->resolution) {
	case RECOILResolution_AMIGA1X1:
	case RECOILResolution_AMIGA2X1:
	case RECOILResolution_AMIGA4X1:
	case RECOILResolution_AMIGA8X1:
	case RECOILResolution_AMIGA1X2:
	case RECOILResolution_AMIGA1X4:
		return "Amiga";
	case RECOILResolution_AMIGA_DCTV1X1:
	case RECOILResolution_AMIGA_DCTV1X2:
		return "Amiga DCTV";
	case RECOILResolution_AMIGA_HAME1X1:
	case RECOILResolution_AMIGA_HAME2X1:
		return "Amiga HAM-E";
	case RECOILResolution_AMSTRAD1X1:
	case RECOILResolution_AMSTRAD2X1:
	case RECOILResolution_AMSTRAD1X2:
		return "Amstrad CPC";
	case RECOILResolution_APPLE_I_I1X1:
		return "Apple II";
	case RECOILResolution_APPLE_I_IE1X2:
		return "Apple IIe";
	case RECOILResolution_APPLE_I_I_G_S1X1:
	case RECOILResolution_APPLE_I_I_G_S1X2:
		return "Apple IIGS";
	case RECOILResolution_MACINTOSH1X1:
		return "Apple Macintosh";
	case RECOILResolution_XE1X1:
	case RECOILResolution_XE2X1:
	case RECOILResolution_XE4X1:
	case RECOILResolution_XE2X2:
	case RECOILResolution_XE4X2:
	case RECOILResolution_XE4X4:
	case RECOILResolution_XE8X8:
		return "Atari 8-bit";
	case RECOILResolution_VBXE1X1:
	case RECOILResolution_VBXE2X1:
		return "Atari 8-bit VBXE";
	case RECOILResolution_PORTFOLIO1X1:
		return "Atari Portfolio";
	case RECOILResolution_ST1X1:
	case RECOILResolution_ST1X2:
		return "Atari ST";
	case RECOILResolution_STE1X1:
	case RECOILResolution_STE1X2:
		return "Atari STE";
	case RECOILResolution_TT1X1:
	case RECOILResolution_TT2X1:
		return "Atari TT";
	case RECOILResolution_FALCON1X1:
	case RECOILResolution_FALCON2X1:
		return "Atari Falcon";
	case RECOILResolution_BBC1X1:
	case RECOILResolution_BBC2X1:
	case RECOILResolution_BBC1X2:
		return "BBC Micro";
	case RECOILResolution_VIC201X1:
	case RECOILResolution_VIC202X1:
		return "Commodore VIC-20";
	case RECOILResolution_C161X1:
	case RECOILResolution_C162X1:
		return "Commodore 16/116/Plus4";
	case RECOILResolution_C641X1:
	case RECOILResolution_C642X1:
		return "Commodore 64";
	case RECOILResolution_C1281X1:
		return "Commodore 128";
	case RECOILResolution_BK1X1:
	case RECOILResolution_BK1X2:
		return "Electronika BK";
	case RECOILResolution_MC05151X2:
		return "Electronika MC 0515";
	case RECOILResolution_FM_TOWNS1X1:
		return "FM Towns";
	case RECOILResolution_HP481X1:
		return "HP 48";
	case RECOILResolution_MSX11X1:
	case RECOILResolution_MSX14X4:
		return "MSX";
	case RECOILResolution_MSX21X1:
	case RECOILResolution_MSX21X2:
	case RECOILResolution_MSX21X1I:
	case RECOILResolution_MSX22X1I:
		return "MSX2";
	case RECOILResolution_MSX2_PLUS1X1:
	case RECOILResolution_MSX2_PLUS2X1I:
		return "MSX2+";
	case RECOILResolution_MSX_V99901X1:
		return "MSX V9990 VDP";
	case RECOILResolution_ORIC1X1:
		return "Oric";
	case RECOILResolution_PC1X1:
		return "PC";
	case RECOILResolution_PC801X2:
		return "NEC PC-80";
	case RECOILResolution_PC881X2:
		return "NEC PC-88";
	case RECOILResolution_PC88_VA1X1:
		return "NEC PC-88 VA";
	case RECOILResolution_PC981X1:
		return "NEC PC-98";
	case RECOILResolution_PLAY_STATION1X1:
		return "PlayStation";
	case RECOILResolution_PSION31X1:
		return "Psion Series 3";
	case RECOILResolution_SAM_COUPE1X1:
	case RECOILResolution_SAM_COUPE1X2:
	case RECOILResolution_SAM_COUPE2X1I:
		return "SAM Coupe";
	case RECOILResolution_X68_K1X1:
		return "Sharp X68000";
	case RECOILResolution_TANDY1X1:
		return "Tandy 1000";
	case RECOILResolution_VECTOR1X1:
		return "Vector-06C";
	case RECOILResolution_ZX811X1:
		return "ZX81";
	case RECOILResolution_SPECTRUM1X1:
	case RECOILResolution_SPECTRUM4X4:
		return "ZX Spectrum";
	case RECOILResolution_SPECTRUM_PROFI1X2:
		return "ZX Spectrum Profi";
	case RECOILResolution_SPECTRUM_ULA_PLUS1X1:
		return "ZX Spectrum ULAplus";
	case RECOILResolution_ZX_EVOLUTION1X1:
		return "ZX Evolution";
	case RECOILResolution_SPECTRUM_NEXT1X1:
		return "ZX Spectrum Next";
	case RECOILResolution_TIMEX1X1:
	case RECOILResolution_TIMEX1X2:
		return "Timex 2048";
	case RECOILResolution_TRS1X1:
	case RECOILResolution_TRS1X2:
		return "TRS-80";
	case RECOILResolution_COCO1X1:
	case RECOILResolution_COCO2X2:
		return "TRS-80 Color Computer";
	default:
		return "Unknown";
	}
}

int RECOIL_GetOriginalWidth(const RECOIL *self)
{
	switch (self->resolution) {
	case RECOILResolution_AMIGA2X1:
	case RECOILResolution_AMIGA_HAME2X1:
	case RECOILResolution_AMSTRAD2X1:
	case RECOILResolution_XE2X1:
	case RECOILResolution_XE2X2:
	case RECOILResolution_VBXE2X1:
	case RECOILResolution_TT2X1:
	case RECOILResolution_FALCON2X1:
	case RECOILResolution_BBC2X1:
	case RECOILResolution_VIC202X1:
	case RECOILResolution_C162X1:
	case RECOILResolution_C642X1:
	case RECOILResolution_COCO2X2:
	case RECOILResolution_MSX22X1I:
	case RECOILResolution_MSX2_PLUS2X1I:
	case RECOILResolution_SAM_COUPE2X1I:
		return self->width >> 1;
	case RECOILResolution_AMIGA4X1:
	case RECOILResolution_MSX14X4:
	case RECOILResolution_SPECTRUM4X4:
	case RECOILResolution_XE4X1:
	case RECOILResolution_XE4X2:
	case RECOILResolution_XE4X4:
		return self->width >> 2;
	case RECOILResolution_AMIGA8X1:
	case RECOILResolution_XE8X8:
		return self->width >> 3;
	default:
		return self->width;
	}
}

int RECOIL_GetOriginalHeight(const RECOIL *self)
{
	switch (self->resolution) {
	case RECOILResolution_AMIGA1X2:
	case RECOILResolution_AMSTRAD1X2:
	case RECOILResolution_APPLE_I_IE1X2:
	case RECOILResolution_APPLE_I_I_G_S1X2:
	case RECOILResolution_XE2X2:
	case RECOILResolution_XE4X2:
	case RECOILResolution_ST1X2:
	case RECOILResolution_STE1X2:
	case RECOILResolution_BBC1X2:
	case RECOILResolution_BK1X2:
	case RECOILResolution_MC05151X2:
	case RECOILResolution_MSX21X2:
	case RECOILResolution_PC801X2:
	case RECOILResolution_PC881X2:
	case RECOILResolution_SAM_COUPE1X2:
	case RECOILResolution_SPECTRUM_PROFI1X2:
	case RECOILResolution_TIMEX1X2:
	case RECOILResolution_TRS1X2:
	case RECOILResolution_COCO2X2:
		return self->height >> 1;
	case RECOILResolution_AMIGA1X4:
	case RECOILResolution_MSX14X4:
	case RECOILResolution_SPECTRUM4X4:
	case RECOILResolution_XE4X4:
		return self->height >> 2;
	case RECOILResolution_XE8X8:
		return self->height >> 3;
	default:
		return self->height;
	}
}

int RECOIL_GetXPixelsPerMeter(const RECOIL *self)
{
	switch (self->resolution) {
	case RECOILResolution_APPLE_I_I1X1:
		return 1530;
	case RECOILResolution_XE1X1:
	case RECOILResolution_XE2X1:
	case RECOILResolution_XE4X1:
	case RECOILResolution_XE2X2:
	case RECOILResolution_XE4X2:
	case RECOILResolution_XE4X4:
	case RECOILResolution_XE8X8:
	case RECOILResolution_VBXE1X1:
	case RECOILResolution_VBXE2X1:
		return self->ntsc ? 1530 : 1261;
	case RECOILResolution_PORTFOLIO1X1:
		return 2123;
	case RECOILResolution_BBC1X1:
	case RECOILResolution_BBC2X1:
		return self->ntsc ? 1710 : 1423;
	case RECOILResolution_BBC1X2:
		return self->ntsc ? 3421 : 2846;
	case RECOILResolution_VIC201X1:
	case RECOILResolution_VIC202X1:
		return self->ntsc ? 1749 : 1574;
	case RECOILResolution_C161X1:
	case RECOILResolution_C162X1:
		return self->ntsc ? 1530 : 1261;
	case RECOILResolution_C641X1:
	case RECOILResolution_C642X1:
		return self->ntsc ? 1749 : 1402;
	case RECOILResolution_MSX11X1:
	case RECOILResolution_MSX14X4:
	case RECOILResolution_MSX21X1:
	case RECOILResolution_MSX2_PLUS1X1:
		return 1148;
	case RECOILResolution_MSX21X2:
	case RECOILResolution_MSX21X1I:
	case RECOILResolution_MSX22X1I:
	case RECOILResolution_MSX2_PLUS2X1I:
		return 2296;
	case RECOILResolution_ORIC1X1:
		return 1067;
	case RECOILResolution_VECTOR1X1:
		return 1067;
	case RECOILResolution_ZX811X1:
		return 1156;
	case RECOILResolution_SPECTRUM1X1:
	case RECOILResolution_SPECTRUM4X4:
	case RECOILResolution_SPECTRUM_ULA_PLUS1X1:
	case RECOILResolution_ZX_EVOLUTION1X1:
	case RECOILResolution_SPECTRUM_NEXT1X1:
	case RECOILResolution_TIMEX1X1:
		return 1245;
	case RECOILResolution_TIMEX1X2:
		return 2490;
	default:
		return 0;
	}
}

int RECOIL_GetYPixelsPerMeter(const RECOIL *self)
{
	switch (self->resolution) {
	case RECOILResolution_APPLE_I_I1X1:
		return 1312;
	case RECOILResolution_XE1X1:
	case RECOILResolution_XE2X1:
	case RECOILResolution_XE4X1:
	case RECOILResolution_XE2X2:
	case RECOILResolution_XE4X2:
	case RECOILResolution_XE4X4:
	case RECOILResolution_XE8X8:
	case RECOILResolution_VBXE1X1:
	case RECOILResolution_VBXE2X1:
		return self->ntsc ? 1312 : 1312;
	case RECOILResolution_PORTFOLIO1X1:
		return 2123;
	case RECOILResolution_BBC1X1:
	case RECOILResolution_BBC2X1:
		return self->ntsc ? 1312 : 1312;
	case RECOILResolution_BBC1X2:
		return self->ntsc ? 2624 : 2624;
	case RECOILResolution_VIC201X1:
	case RECOILResolution_VIC202X1:
	case RECOILResolution_C161X1:
	case RECOILResolution_C162X1:
		return self->ntsc ? 1312 : 1312;
	case RECOILResolution_C641X1:
	case RECOILResolution_C642X1:
		return self->ntsc ? 1312 : 1312;
	case RECOILResolution_MSX11X1:
	case RECOILResolution_MSX14X4:
	case RECOILResolution_MSX21X1:
	case RECOILResolution_MSX2_PLUS1X1:
		return 1312;
	case RECOILResolution_MSX21X2:
	case RECOILResolution_MSX21X1I:
	case RECOILResolution_MSX22X1I:
	case RECOILResolution_MSX2_PLUS2X1I:
		return 2624;
	case RECOILResolution_ORIC1X1:
		return 1312;
	case RECOILResolution_VECTOR1X1:
		return 1312;
	case RECOILResolution_ZX811X1:
		return 1312;
	case RECOILResolution_SPECTRUM1X1:
	case RECOILResolution_SPECTRUM4X4:
	case RECOILResolution_SPECTRUM_ULA_PLUS1X1:
	case RECOILResolution_ZX_EVOLUTION1X1:
	case RECOILResolution_SPECTRUM_NEXT1X1:
	case RECOILResolution_TIMEX1X1:
		return 1312;
	case RECOILResolution_TIMEX1X2:
		return 2624;
	default:
		return 0;
	}
}

float RECOIL_GetXPixelsPerInch(const RECOIL *self)
{
	return (float) (RECOIL_GetXPixelsPerMeter(self) * 0.0254);
}

float RECOIL_GetYPixelsPerInch(const RECOIL *self)
{
	return (float) (RECOIL_GetYPixelsPerMeter(self) * 0.0254);
}

int RECOIL_GetFrames(const RECOIL *self)
{
	return self->frames;
}

static void RECOIL_CalculatePalette(RECOIL *self)
{
	if (self->colorInUse == NULL) {
		free(self->colorInUse);
		self->colorInUse = (uint8_t *) malloc(2097152 * sizeof(uint8_t));
	}
	memset(self->colorInUse, 0, 2097152 * sizeof(uint8_t));
	self->colors = 0;
	memset(self->palette, 0, sizeof(self->palette));
	int pixelsCount = self->width * self->height;
	for (int pixelsOffset = 0; pixelsOffset < pixelsCount; pixelsOffset++) {
		int rgb = self->pixels[pixelsOffset];
		int i = rgb >> 3;
		int mask = 1 << (rgb & 7);
		if ((self->colorInUse[i] & mask) == 0) {
			self->colorInUse[i] |= mask;
			if (self->colors < 256)
				self->palette[self->colors] = rgb;
			self->colors++;
		}
	}
}

int RECOIL_GetColors(RECOIL *self)
{
	if (self->colors == -1)
		RECOIL_CalculatePalette(self);
	return self->colors;
}

static int RECOIL_FindInSortedPalette(const RECOIL *self, int rgb)
{
	int left = 0;
	int right = self->colors;
	while (left < right) {
		int index = (left + right) >> 1;
		int paletteRgb = self->palette[index];
		if (rgb == paletteRgb)
			return index;
		if (rgb < paletteRgb)
			right = index;
		else
			left = index + 1;
	}
	return 0;
}

int const *RECOIL_ToPalette(RECOIL *self)
{
	if (self->colors == -1)
		RECOIL_CalculatePalette(self);
	if (self->colors > 256)
		return NULL;
	qsort(self->palette, self->colors, sizeof(int), FuCompare_int);
	int pixelsLength = self->width * self->height;
	if (self->indexesLength < pixelsLength) {
		self->indexesLength = pixelsLength;
		free(self->indexes);
		self->indexes = (uint8_t *) malloc(pixelsLength * sizeof(uint8_t));
	}
	for (int i = 0; i < pixelsLength; i++)
		self->indexes[i] = (uint8_t) RECOIL_FindInSortedPalette(self, self->pixels[i]);
	return self->palette;
}

uint8_t const *RECOIL_GetIndexes(const RECOIL *self)
{
	return self->indexes;
}
