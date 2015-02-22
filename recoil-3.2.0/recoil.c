/* Generated automatically with "cito". Do not edit. */
#include <stdlib.h>
#include <string.h>
#include "recoil.h"
typedef struct A4rStream A4rStream;
typedef struct AmstradStream AmstradStream;
typedef struct BbgStream BbgStream;
typedef struct BitStream BitStream;
typedef struct BlazingPaddlesBoundingBox BlazingPaddlesBoundingBox;
typedef struct C64KoalaStream C64KoalaStream;
typedef struct CaStream CaStream;
typedef struct CciStream CciStream;
typedef struct DrpStream DrpStream;
typedef struct FanoTree FanoTree;
typedef struct GoDotStream GoDotStream;
typedef struct HimStream HimStream;
typedef struct HpmStream HpmStream;

typedef enum {
	IceFrameMode_GR0,
	IceFrameMode_GR0_GTIA9,
	IceFrameMode_GR0_GTIA10,
	IceFrameMode_GR0_GTIA11,
	IceFrameMode_GR12,
	IceFrameMode_GR12_GTIA9,
	IceFrameMode_GR12_GTIA10,
	IceFrameMode_GR12_GTIA11
}
IceFrameMode;
typedef struct IcnParser IcnParser;

typedef enum {
	IffType_ILBM,
	IffType_PBM,
	IffType_ACBM
}
IffType;
typedef struct ImgStream ImgStream;
typedef struct Lz4Stream Lz4Stream;
typedef struct MppPaletteStream MppPaletteStream;
typedef struct MspStream MspStream;
typedef struct PInterpreter PInterpreter;
typedef struct PacStream PacStream;
typedef struct PackBitsStream PackBitsStream;
typedef struct PcsStream PcsStream;
typedef struct PgcStream PgcStream;

/**
 * Platform and pixel ratio.
 */
typedef enum {
	RECOILResolution_AMIGA1X1,
	RECOILResolution_AMSTRAD1X1,
	RECOILResolution_AMSTRAD1X2,
	RECOILResolution_APPLE_I_I1X1,
	RECOILResolution_APPLE_I_I1X2,
	RECOILResolution_MACINTOSH1X1,
	RECOILResolution_XE1X1,
	RECOILResolution_XE2X1,
	RECOILResolution_XE4X1,
	RECOILResolution_XE2X2,
	RECOILResolution_XE4X2,
	RECOILResolution_PORTFOLIO1X1,
	RECOILResolution_ST1X1,
	RECOILResolution_ST1X2,
	RECOILResolution_STE1X1,
	RECOILResolution_STE1X2,
	RECOILResolution_FALCON1X1,
	RECOILResolution_BBC1X1,
	RECOILResolution_BBC2X1,
	RECOILResolution_BBC1X2,
	RECOILResolution_C161X1,
	RECOILResolution_C162X1,
	RECOILResolution_C641X1,
	RECOILResolution_C642X1,
	RECOILResolution_MSX1X1,
	RECOILResolution_PC1X1,
	RECOILResolution_SAM_COUPE1X1,
	RECOILResolution_SPECTRUM1X1,
	RECOILResolution_ZX811X1
}
RECOILResolution;
typedef struct RgbStream RgbStream;
typedef struct RleStream RleStream;
typedef struct SpcStream SpcStream;
typedef struct SpsStream SpsStream;
typedef struct Sr8Stream Sr8Stream;
typedef struct Stream Stream;
typedef struct TnyPcsStream TnyPcsStream;
typedef struct TnyStream TnyStream;
typedef struct VdatStream VdatStream;
typedef struct XeKoalaStream XeKoalaStream;
typedef struct XlpStream XlpStream;
typedef struct ZxpStream ZxpStream;

struct Stream {
	int contentLength;
	int contentOffset;
	unsigned char const *content;
};
static int Stream_ReadByte(Stream *self);

struct A4rStream {
	Stream base;
	int innerFlags;
	int outerFlags;
	int unpackedOffset;
	unsigned char unpacked[11248];
};
static void A4rStream_Construct(A4rStream *self);
static cibool A4rStream_CopyBlock(A4rStream *self, int distance, int length);
static int A4rStream_ReadFlag(A4rStream *self);
static cibool A4rStream_StoreByte(A4rStream *self, int value);
static cibool A4rStream_UnpackA4r(A4rStream *self);

struct BitStream {
	Stream base;
	int bits;
};
static void BitStream_Construct(BitStream *self);
static int BitStream_ReadBit(BitStream *self);
static int BitStream_ReadBits(BitStream *self, int count);

typedef struct {
	cibool (*readCommand)(RleStream *self);
	int (*readValue)(RleStream *self);
}
RleStreamVtbl;
struct RleStream {
	BitStream base;
	const RleStreamVtbl *vtbl;
	/**
	 * Block length.
	 */
	int repeatCount;
	/**
	 * Value for an RLE block, -1 for a block of literals.
	 */
	int repeatValue;
};
static void RleStream_Construct(RleStream *self, const RleStreamVtbl *vtbl);
static int RleStream_ReadRle(RleStream *self);
static int RleStream_ReadValue(RleStream *self);
static cibool RleStream_Unpack(RleStream *self, unsigned char *unpacked, int unpackedOffset, int unpackedStride, int unpackedCount);
static cibool RleStream_UnpackC64(RleStream *self, unsigned char *unpacked, int unpackedLength);

struct AmstradStream {
	RleStream base;
	int blockLength;
};
static void AmstradStream_Construct(AmstradStream *self, const RleStreamVtbl *vtbl);
static cibool AmstradStream_ReadCommand(AmstradStream *self);
static const RleStreamVtbl CiVtbl_AmstradStream = {
	(cibool (*)(RleStream *self)) AmstradStream_ReadCommand,
	RleStream_ReadValue
};

struct BbgStream {
	RleStream base;
	int countBits;
	int valueBits;
};
static void BbgStream_Construct(BbgStream *self, const RleStreamVtbl *vtbl);
static int BbgStream_ReadBitsReverse(BbgStream *self, int count);
static cibool BbgStream_ReadCommand(BbgStream *self);
static const RleStreamVtbl CiVtbl_BbgStream = {
	(cibool (*)(RleStream *self)) BbgStream_ReadCommand,
	RleStream_ReadValue
};

struct BlazingPaddlesBoundingBox {
	int bottom;
	int left;
	int right;
	int top;
};
static cibool BlazingPaddlesBoundingBox_Calculate(BlazingPaddlesBoundingBox *self, unsigned char const *content, int contentLength, int index, int startAddress);

struct C64KoalaStream {
	RleStream base;
};
static void C64KoalaStream_Construct(C64KoalaStream *self, const RleStreamVtbl *vtbl);
static cibool C64KoalaStream_ReadCommand(C64KoalaStream *self);
static const RleStreamVtbl CiVtbl_C64KoalaStream = {
	(cibool (*)(RleStream *self)) C64KoalaStream_ReadCommand,
	RleStream_ReadValue
};

struct CaStream {
	RleStream base;
	int defaultValue;
	int escapeByte;
};
static void CaStream_Construct(CaStream *self, const RleStreamVtbl *vtbl);
static cibool CaStream_ReadCommand(CaStream *self);
static cibool CaStream_UnpackCa(unsigned char const *content, int contentOffset, int contentLength, unsigned char *unpacked, int unpackedOffset);
static cibool CaStream_UnpackDel(unsigned char const *content, int contentLength, unsigned char *unpacked, int blocks);
static const RleStreamVtbl CiVtbl_CaStream = {
	(cibool (*)(RleStream *self)) CaStream_ReadCommand,
	RleStream_ReadValue
};

struct CciStream {
	RleStream base;
};
static void CciStream_Construct(CciStream *self, const RleStreamVtbl *vtbl);
static cibool CciStream_ReadCommand(CciStream *self);
static cibool CciStream_UnpackGr15(CciStream *self, unsigned char *unpacked, int unpackedOffset);
static const RleStreamVtbl CiVtbl_CciStream = {
	(cibool (*)(RleStream *self)) CciStream_ReadCommand,
	RleStream_ReadValue
};

struct DrpStream {
	RleStream base;
	int escape;
};
static void DrpStream_Construct(DrpStream *self, const RleStreamVtbl *vtbl);
static cibool DrpStream_ReadCommand(DrpStream *self);
static unsigned char const *DrpStream_UnpackFile(unsigned char const *content, int contentLength, const char *signature, unsigned char *unpacked, int unpackedLength);
static const RleStreamVtbl CiVtbl_DrpStream = {
	(cibool (*)(RleStream *self)) DrpStream_ReadCommand,
	RleStream_ReadValue
};

struct FanoTree {
	/**
	 * Count[n] == number of codes of bit length n.
	 */
	int count[16];
	/**
	 * Values sorted by code length.
	 */
	unsigned char values[256];
};
static void FanoTree_Create(FanoTree *self, unsigned char const *content, int contentOffset, int codeCount);
static int FanoTree_ReadCode(FanoTree const *self, BitStream *bitStream);

struct GoDotStream {
	RleStream base;
};
static void GoDotStream_Construct(GoDotStream *self, const RleStreamVtbl *vtbl);
static cibool GoDotStream_ReadCommand(GoDotStream *self);
static const RleStreamVtbl CiVtbl_GoDotStream = {
	(cibool (*)(RleStream *self)) GoDotStream_ReadCommand,
	RleStream_ReadValue
};

struct HimStream {
	RleStream base;
};
static void HimStream_Construct(HimStream *self, const RleStreamVtbl *vtbl);
static cibool HimStream_ReadCommand(HimStream *self);
static int HimStream_ReadValue(HimStream *self);
static const RleStreamVtbl CiVtbl_HimStream = {
	(cibool (*)(RleStream *self)) HimStream_ReadCommand,
	(int (*)(RleStream *self)) HimStream_ReadValue
};

struct HpmStream {
	RleStream base;
};
static void HpmStream_Construct(HpmStream *self, const RleStreamVtbl *vtbl);
static cibool HpmStream_ReadCommand(HpmStream *self);
static const RleStreamVtbl CiVtbl_HpmStream = {
	(cibool (*)(RleStream *self)) HpmStream_ReadCommand,
	RleStream_ReadValue
};

struct IcnParser {
	Stream base;
};
static cibool IcnParser_Expect(IcnParser *self, const char *s);
static int IcnParser_ParseDefine(IcnParser *self, const char *s);
static int IcnParser_ParseHex(IcnParser *self);
static cibool IcnParser_SkipWhitespace(IcnParser *self);

struct ImgStream {
	RleStream base;
	int patternRepeatCount;
};
static void ImgStream_Construct(ImgStream *self, const RleStreamVtbl *vtbl);
static int ImgStream_GetLineRepeatCount(ImgStream *self);
static cibool ImgStream_ReadCommand(ImgStream *self);
static const RleStreamVtbl CiVtbl_ImgStream = {
	(cibool (*)(RleStream *self)) ImgStream_ReadCommand,
	RleStream_ReadValue
};

struct Lz4Stream {
	Stream base;
	int unpackedLength;
	int unpackedOffset;
	unsigned char *unpacked;
};
static cibool Lz4Stream_Copy(Lz4Stream *self, int count);
static int Lz4Stream_ReadCount(Lz4Stream *self, int count);

struct MppPaletteStream {
	BitStream base;
};
static void MppPaletteStream_Construct(MppPaletteStream *self);
static int MppPaletteStream_Read(MppPaletteStream *self);

struct MspStream {
	RleStream base;
};
static void MspStream_Construct(MspStream *self, const RleStreamVtbl *vtbl);
static cibool MspStream_ReadCommand(MspStream *self);
static const RleStreamVtbl CiVtbl_MspStream = {
	(cibool (*)(RleStream *self)) MspStream_ReadCommand,
	RleStream_ReadValue
};

struct PInterpreter {
	Stream base;
	int bottomCode;
	int bottomOffset;
	int screenOffset;
	unsigned char screen[768];
};
static cibool PInterpreter_DPeek(PInterpreter *self, int expectedX, int expectedAddress);
static cibool PInterpreter_DoFor(PInterpreter *self);
static cibool PInterpreter_DoIf(PInterpreter *self);
static cibool PInterpreter_Let(PInterpreter *self);
static cibool PInterpreter_Next(PInterpreter *self);
static cibool PInterpreter_Poke(PInterpreter *self);
static cibool PInterpreter_Print(PInterpreter *self);
static int PInterpreter_PrintString(PInterpreter *self, int offset);
static int PInterpreter_ReadNumber(PInterpreter *self);
static cibool PInterpreter_Run(PInterpreter *self);

struct PacStream {
	RleStream base;
};
static void PacStream_Construct(PacStream *self, const RleStreamVtbl *vtbl);
static cibool PacStream_ReadCommand(PacStream *self);
static const RleStreamVtbl CiVtbl_PacStream = {
	(cibool (*)(RleStream *self)) PacStream_ReadCommand,
	RleStream_ReadValue
};

struct PackBitsStream {
	RleStream base;
};
static void PackBitsStream_Construct(PackBitsStream *self, const RleStreamVtbl *vtbl);
static cibool PackBitsStream_ReadCommand(PackBitsStream *self);
static const RleStreamVtbl CiVtbl_PackBitsStream = {
	(cibool (*)(RleStream *self)) PackBitsStream_ReadCommand,
	RleStream_ReadValue
};

struct TnyPcsStream {
	RleStream base;
};
static void TnyPcsStream_Construct(TnyPcsStream *self, const RleStreamVtbl *vtbl);
static cibool TnyPcsStream_ReadCommand(TnyPcsStream *self);
static const RleStreamVtbl CiVtbl_TnyPcsStream = {
	(cibool (*)(RleStream *self)) TnyPcsStream_ReadCommand,
	RleStream_ReadValue
};

struct PcsStream {
	TnyPcsStream base;
	cibool palette;
};
static void PcsStream_Construct(PcsStream *self, const RleStreamVtbl *vtbl);
static int PcsStream_ReadValue(PcsStream *self);
static cibool PcsStream_UnpackPcs(PcsStream *self, unsigned char *unpacked);
static const RleStreamVtbl CiVtbl_PcsStream = {
	(cibool (*)(RleStream *self)) TnyPcsStream_ReadCommand,
	(int (*)(RleStream *self)) PcsStream_ReadValue
};

struct PgcStream {
	RleStream base;
};
static void PgcStream_Construct(PgcStream *self, const RleStreamVtbl *vtbl);
static cibool PgcStream_ReadCommand(PgcStream *self);
static const RleStreamVtbl CiVtbl_PgcStream = {
	(cibool (*)(RleStream *self)) PgcStream_ReadCommand,
	RleStream_ReadValue
};

struct RECOIL {
	int colors;
	/**
	 * Number of frames (normally 1; 2 or 3 for flickering pictures).
	 */
	int frames;
	/**
	 * Decoded image height.
	 */
	int height;
	int leftSkip;
	/**
	 * Platform and pixel ratio.
	 */
	RECOILResolution resolution;
	/**
	 * Decoded image width.
	 */
	int width;
	unsigned char gtiaColors[16];
	int atari8Palette[256];
	/**
	 * RGB palette decoded from the image file.
	 */
	int contentPalette[256];
	int palette[256];
	/**
	 * Decoded image pixels as 0xRRGGBB.
	 */
	int pixels[1572864];
};
static void RECOIL_Construct(RECOIL *self);
static cibool RECOIL_ApplyAtari8Palette(RECOIL *self, unsigned char const *frame);
static cibool RECOIL_ApplyAtari8PaletteBlend(RECOIL *self, unsigned char const *frame1, unsigned char const *frame2);
static cibool RECOIL_ApplyAtari8PaletteBlend3(RECOIL *self, unsigned char const *frame1, unsigned char const *frame2, unsigned char const *frame3);
static cibool RECOIL_ApplyBlend(RECOIL *self);
static void RECOIL_CalculatePalette(RECOIL *self, int *palette, int paletteOffset, int paletteLength);
static cibool RECOIL_Decode256(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_Decode3(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_Decode4bt(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_Decode4mi(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_Decode4pl(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_Decode4pm(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_Decode64c(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeA4r(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAcs(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAfl(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAgp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAll(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAmi(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAmstradFnt(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAmstradMode2(RECOIL *self, unsigned char const *content, int contentOffset, int width, int height);
static cibool RECOIL_DecodeAmstradScr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAp3(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeApc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeApl(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeApp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeArtDirector(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAsciiArtEditor(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeAt800Missiles(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset);
static void RECOIL_DecodeAt800Players(RECOIL const *self, unsigned char const *content, unsigned char *frame);
static cibool RECOIL_DecodeAtari8Artist(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAtari8Fnt(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAtari8Font(RECOIL *self, unsigned char const *characters, unsigned char const *font, int fontOffset);
static void RECOIL_DecodeAtari8Gr0(RECOIL const *self, unsigned char const *characters, int charactersStride, unsigned char const *font, int fontOffset, unsigned char *frame);
static void RECOIL_DecodeAtari8Gr10(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int frameStride, int height);
static void RECOIL_DecodeAtari8Gr11(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int frameStride, int height);
static void RECOIL_DecodeAtari8Gr11PalBlend(RECOIL const *self, unsigned char const *content, int contentOffset, int contentStride, unsigned char *frame, int y);
static void RECOIL_DecodeAtari8Gr12Line(RECOIL const *self, unsigned char const *characters, int charactersOffset, unsigned char const *font, int fontOffset, unsigned char *frame, int frameOffset);
static void RECOIL_DecodeAtari8Gr15(RECOIL const *self, unsigned char const *content, int contentOffset, int contentStride, unsigned char *frame, int frameOffset, int frameStride, int height);
static void RECOIL_DecodeAtari8Gr7(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int height);
static void RECOIL_DecodeAtari8Gr8(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int height);
static void RECOIL_DecodeAtari8Gr9(RECOIL const *self, unsigned char const *content, int contentOffset, int contentStride, unsigned char *frame, int frameOffset, int frameStride, int width, int height);
static cibool RECOIL_DecodeAtari8Ice(RECOIL *self, unsigned char const *content, int contentLength, cibool font, int mode);
static void RECOIL_DecodeAtari8Player(RECOIL const *self, unsigned char const *content, int contentOffset, int color, unsigned char *frame, int frameOffset, int height);
static cibool RECOIL_DecodeAtari8Rgb(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeAtari8RgbScreen(RECOIL *self, unsigned char const *screens, int screensOffset, int color, unsigned char *frame);
static cibool RECOIL_DecodeAtari8Spc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAtr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAwbm(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeAwbmPalette(RECOIL *self, unsigned char const *content, int contentLength, int paletteOffset, int colors);
static cibool RECOIL_DecodeBb0(RECOIL *self, unsigned char const *content, int contentLength, int const *palette);
static cibool RECOIL_DecodeBb1(RECOIL *self, unsigned char const *content, int contentLength, int const *palette);
static cibool RECOIL_DecodeBb2(RECOIL *self, unsigned char const *content, int contentLength, int const *palette);
static cibool RECOIL_DecodeBb4(RECOIL *self, unsigned char const *content, int contentLength, int const *palette);
static cibool RECOIL_DecodeBb5(RECOIL *self, unsigned char const *content, int contentLength, int const *palette);
static cibool RECOIL_DecodeBbg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeBfli(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeBgp(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeBitplanes(RECOIL *self, unsigned char const *content, int contentOffset, int bitplanes, int pixelsOffset, int pixelsCount);
static cibool RECOIL_DecodeBkg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeBlackAndWhite(RECOIL *self, unsigned char const *content, int contentOffset, int width, int height, int backgroundColor, RECOILResolution resolution);
static void RECOIL_DecodeBlackAndWhiteFont(RECOIL *self, unsigned char const *content, int contentOffset, int contentLength);
static cibool RECOIL_DecodeBlazingPaddlesVectors(RECOIL *self, unsigned char const *content, int contentLength, int startAddress);
static cibool RECOIL_DecodeBml(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeBru(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeC64HiresFrame(RECOIL *self, unsigned char const *content, int bitmapOffset, int videoMatrixOffset, int pixelsOffset);
static cibool RECOIL_DecodeC64Multicolor(RECOIL *self, int width, unsigned char const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background);
static void RECOIL_DecodeC64MulticolorFrame(RECOIL *self, unsigned char const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, int pixelsOffset);
static cibool RECOIL_DecodeCa(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeCci(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeCh8(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeChr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeCin(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeCpr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeCpt(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDd(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDel(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDgc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDgu(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDhr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDlm(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDol(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDoo(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDph(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDrg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDrl(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDrz(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDu2(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeDuo(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeEci(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeEcp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeEpa(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeFalconPalette320(RECOIL *self, unsigned char const *content, int bitplanesOffset, int paletteOffset, int height);
static cibool RECOIL_DecodeFalconTrueColor(RECOIL *self, unsigned char const *content, int contentLength, int contentOffset, int width, int height);
static cibool RECOIL_DecodeFalconTrueColorVariable(RECOIL *self, unsigned char const *content, int contentLength, int widthOffset, int dataOffset);
static cibool RECOIL_DecodeFfli(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeFli(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeFtc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeFun(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeFunUnpacked(RECOIL *self, unsigned char const *content);
static cibool RECOIL_DecodeFwa(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeG09(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeG10(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeG11(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGfb(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGhg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGod(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGr15Blend(RECOIL *self, unsigned char const *content, int bitmapOffset, int colorsOffset, int height);
static cibool RECOIL_DecodeGr7(RECOIL *self, unsigned char const *content, int contentOffset, int contentSize);
static cibool RECOIL_DecodeGr8(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGr9(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeGun(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeHam(RECOIL *self, unsigned char const *unpacked, int bitplanes);
static cibool RECOIL_DecodeHed(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHfc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHgb(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHgr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHim(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHimUnpacked(RECOIL *self, unsigned char const *content);
static cibool RECOIL_DecodeHip(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHir(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHlf(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHlr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHpm(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeHr2(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeIceFrame(RECOIL const *self, unsigned char const *content, int charactersOffset, int fontOffset, unsigned char *frame, IceFrameMode mode);
static cibool RECOIL_DecodeIff(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeIffUnpacked(RECOIL *self, unsigned char *unpacked, int bitplanes, int colors, int camg);
static cibool RECOIL_DecodeIge(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeIhe(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeInfo(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeInp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeInt(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeIp2(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeIph(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeIst(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeJgp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeJj(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeKoa(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeLeo(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeLp3(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeLum(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMac(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMax(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMbg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMch(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMci(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMcp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMcpp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMcs(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMgp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMic(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMis(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeMle(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeMleFrame(RECOIL *self, unsigned char const *content, int contentOffset, int pixelsOffset);
static cibool RECOIL_DecodeMpp(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeMppScreen(RECOIL *self, unsigned char const *content, int paletteOffset, int paletteLength, int pixelsOffset);
static cibool RECOIL_DecodeMsp(RECOIL *self, unsigned char const *content, int contentLength);
static int RECOIL_DecodeMsxYjk(unsigned char const *content, int i);
static cibool RECOIL_DecodeNeo(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeNlq(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeOcp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeP(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeP4i(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePac(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePcs(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodePcsScreen(RECOIL *self, unsigned char const *unpacked, int pixelsOffset);
static cibool RECOIL_DecodePgc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePgf(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePi4(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePic(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePl4(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePla(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePmd(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodePmg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeRaw(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeRip(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeRm(RECOIL *self, unsigned char const *content, int contentLength, int mode, RECOILResolution resolution);
static cibool RECOIL_DecodeRys(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSc2(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSc8(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSca(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeScc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeScr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeScs4(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSge(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeShc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeShp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeShr(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSif(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSps(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSpu(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSr8(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSt(RECOIL *self, unsigned char const *bitmap, int bitmapOffset, unsigned char const *palette, int paletteOffset, int mode);
static cibool RECOIL_DecodeStIcn(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeStImg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeStLow(RECOIL *self, unsigned char const *bitmap, int bitmapOffset, unsigned char const *palette, int paletteOffset, int width, int height);
static void RECOIL_DecodeStMedium(RECOIL *self, unsigned char const *bitmap, int bitmapOffset, unsigned char const *palette, int paletteOffset, int width, int height, int blend);
static cibool RECOIL_DecodeStPi(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeStSpc(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeSxs(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeTip(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeTny(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeTrp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeTru(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeValidSc8(RECOIL *self, unsigned char const *content);
static cibool RECOIL_DecodeVic(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeVzi(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeWnd(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeXlp(RECOIL *self, unsigned char const *content, int contentLength);
static void RECOIL_DecodeZx(RECOIL *self, unsigned char const *content, int bitmapOffset, int attributesOffset, int attributesMode, int pixelsOffset);
static cibool RECOIL_DecodeZxIfl(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeZxImg(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeZxRgb(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DecodeZxRgb3(RECOIL *self, unsigned char const *content, int contentLength, unsigned char const *frameComponents);
static cibool RECOIL_DecodeZxp(RECOIL *self, unsigned char const *content, int contentLength);
static cibool RECOIL_DrawBlazingPaddlesVector(RECOIL const *self, unsigned char const *content, int contentLength, unsigned char *frame, int frameOffset, int index, int startAddress);
static void RECOIL_DrawSpcBrush(unsigned char *pixels, int x1, int y1, int brush, int pattern);
static void RECOIL_DrawSpcChar(unsigned char *pixels, int x1, int y1, int ch);
static void RECOIL_DrawSpcLine(unsigned char *pixels, int x1, int y1, int x2, int y2, int color);
static cibool RECOIL_ExpectMsx2(unsigned char const *content, int contentLength);
static cibool RECOIL_ExpectMsxHeader(unsigned char const *content, int expected);
static cibool RECOIL_FillSpc(unsigned char *pixels, int x, int y, int pattern);
static int RECOIL_FindColor(int const *palette, int paletteEnd, int rgb);
static int RECOIL_Get32BigEndian(unsigned char const *content, int contentOffset);
static int RECOIL_Get32LittleEndian(unsigned char const *content, int contentOffset);
static int RECOIL_GetAmstradHeader(unsigned char const *content, int contentLength);
static int RECOIL_GetAtari8ExecutableOffset(unsigned char const *content, int contentLength);
static int RECOIL_GetMsxHeader(unsigned char const *content);
static int RECOIL_GetPackedExt(const char *filename);
static int RECOIL_GetStColor(RECOIL const *self, unsigned char const *content, int contentOffset);
static int RECOIL_GetStColor1000(unsigned char const *content, int contentOffset);
static unsigned char RECOIL_Gr12GtiaByteToGr8(int b, int ch, cibool gtia10);
static int RECOIL_Gr12GtiaNibbleToGr8(int nibble, int ch, cibool gtia10);
static cibool RECOIL_IsStePalette(unsigned char const *content, int contentOffset, int colors);
static cibool RECOIL_IsStringAt(unsigned char const *content, int contentOffset, const char *s);
static int RECOIL_ParseAtari8ExecutableHeader(unsigned char const *content, int contentOffset);
static void RECOIL_PlotSpcPattern(unsigned char *pixels, int x, int y, int pattern);
static cibool RECOIL_SetAtari8RawSize(RECOIL *self, unsigned char const *content, int contentLength, RECOILResolution resolution);
static void RECOIL_SetBakPF012(RECOIL *self, unsigned char const *content, int contentOffset, int contentStride);
static void RECOIL_SetBakPF0123(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetC16Palette(RECOIL *self);
static void RECOIL_SetFalconPalette(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetGr15DefaultColors(RECOIL *self);
static void RECOIL_SetGtiaColor(RECOIL *self, int reg, int value);
static void RECOIL_SetGtiaColors(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetPF0123Bak(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetPF0123Even(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetPF012Bak(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetPF21(RECOIL *self, unsigned char const *content, int contentOffset);
static void RECOIL_SetPM123PF0123Bak(RECOIL *self, unsigned char const *content, int contentOffset);
static cibool RECOIL_SetSize(RECOIL *self, int width, int height, RECOILResolution resolution);
static cibool RECOIL_SetSizeStOrFalcon(RECOIL *self, int width, int height, int bitplanes);
static void RECOIL_SetStPalette(RECOIL *self, unsigned char const *content, int contentOffset, int colors);
static int RECOIL_ToAtari8Char(int ascii);
static cibool RECOIL_UnpackLz4(RECOIL const *self, unsigned char const *content, int contentLength, unsigned char *unpacked, int unpackedLength);
static cibool RECOIL_UnpackRip(RECOIL const *self, unsigned char const *content, int contentOffset, int contentLength, unsigned char *unpacked, int unpackedLength);
static cibool RECOIL_UnpackSpc(RleStream *rle, unsigned char *unpacked);
static cibool RECOIL_VerifyIce(RECOIL *self, unsigned char const *content, int contentLength, cibool font, int fontLength, int imageLength, RECOILResolution resolution);
static const int RECOIL_BbcPalette[16] = { 0, 16711680, 65280, 16776960, 255, 16711935, 65535, 16777215, 0, 16711680, 65280, 16776960, 255, 16711935, 65535, 16777215 };
static const int RECOIL_BbcPalette2Bit[4] = { 0, 16711680, 16776960, 16777215 };
static const int RECOIL_BbcPalette1Bit[2] = { 0, 16777215 };
static const int RECOIL_C64Palette[16] = { 0, 16777215, 6829867, 7382194, 7290246, 5803331, 3483769, 12109679, 7294757, 4405504, 10119001, 4473924, 7105644, 10146436, 7102133, 9803157 };
static const unsigned char CiBinaryResource_altirrapal_pal[768] = { 0, 0, 0, 17, 17, 17, 34, 34, 34, 51, 51, 51, 68, 68, 68, 85,
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
static const unsigned char CiBinaryResource_atari8_fnt[1024] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 24, 24, 24, 0, 24, 0,
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
static const unsigned char CiBinaryResource_c16_pal[768] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
	47, 47, 47, 61, 61, 61, 66, 66, 66, 86, 85, 90, 132, 126, 133, 178,
	172, 179, 202, 202, 202, 249, 249, 249, 47, 47, 47, 61, 61, 61, 66, 66,
	66, 86, 85, 90, 132, 126, 133, 178, 172, 179, 202, 202, 202, 249, 249, 249,
	104, 16, 16, 117, 30, 32, 123, 40, 32, 144, 60, 59, 187, 103, 104, 233,
	146, 146, 255, 172, 172, 255, 246, 242, 104, 16, 16, 117, 30, 32, 123, 40,
	32, 144, 60, 59, 187, 103, 104, 233, 146, 146, 255, 172, 172, 255, 246, 242,
	0, 66, 66, 0, 80, 79, 2, 86, 89, 23, 109, 114, 69, 150, 150, 108,
	195, 193, 133, 216, 224, 209, 255, 255, 0, 66, 66, 0, 80, 79, 2, 86,
	89, 23, 109, 114, 69, 150, 150, 108, 195, 193, 133, 216, 224, 209, 255, 255,
	88, 0, 109, 106, 16, 120, 111, 26, 130, 135, 45, 153, 175, 88, 195, 217,
	134, 240, 243, 156, 255, 255, 233, 255, 88, 0, 109, 106, 16, 120, 111, 26,
	130, 135, 45, 153, 175, 88, 195, 217, 134, 240, 243, 156, 255, 255, 233, 255,
	0, 78, 0, 4, 92, 0, 10, 101, 9, 31, 123, 21, 74, 167, 62, 121,
	209, 118, 146, 234, 138, 219, 255, 211, 0, 78, 0, 4, 92, 0, 10, 101,
	9, 31, 123, 21, 74, 167, 62, 121, 209, 118, 146, 234, 138, 219, 255, 211,
	25, 28, 148, 42, 42, 163, 48, 52, 167, 70, 73, 193, 115, 115, 236, 157,
	161, 255, 183, 186, 255, 240, 255, 255, 25, 28, 148, 42, 42, 163, 48, 52,
	167, 70, 73, 193, 115, 115, 236, 157, 161, 255, 183, 186, 255, 240, 255, 255,
	56, 56, 0, 76, 71, 0, 80, 81, 0, 102, 99, 0, 146, 141, 17, 189,
	190, 64, 214, 211, 91, 255, 255, 163, 56, 56, 0, 76, 71, 0, 80, 81,
	0, 102, 99, 0, 146, 141, 17, 189, 190, 64, 214, 211, 91, 255, 255, 163,
	86, 32, 0, 105, 47, 0, 110, 54, 0, 132, 76, 13, 175, 120, 50, 220,
	162, 97, 243, 190, 121, 255, 255, 193, 86, 32, 0, 105, 47, 0, 110, 54,
	0, 132, 76, 13, 175, 120, 50, 220, 162, 97, 243, 190, 121, 255, 255, 193,
	75, 40, 0, 89, 56, 0, 101, 64, 0, 115, 85, 0, 161, 128, 32, 209,
	169, 76, 230, 197, 101, 255, 255, 178, 75, 40, 0, 89, 56, 0, 101, 64,
	0, 115, 85, 0, 161, 128, 32, 209, 169, 76, 230, 197, 101, 255, 255, 178,
	22, 72, 0, 38, 86, 0, 44, 92, 0, 64, 114, 0, 108, 158, 18, 147,
	200, 61, 176, 224, 87, 252, 255, 162, 22, 72, 0, 38, 86, 0, 44, 92,
	0, 64, 114, 0, 108, 158, 18, 147, 200, 61, 176, 224, 87, 252, 255, 162,
	105, 7, 47, 117, 21, 65, 125, 30, 69, 145, 51, 94, 186, 95, 137, 233,
	138, 177, 255, 164, 207, 255, 238, 255, 105, 7, 47, 117, 21, 65, 125, 30,
	69, 145, 51, 94, 186, 95, 137, 233, 138, 177, 255, 164, 207, 255, 238, 255,
	0, 70, 38, 0, 88, 61, 1, 97, 69, 25, 116, 92, 70, 159, 131, 111,
	205, 171, 137, 229, 200, 209, 255, 255, 0, 70, 38, 0, 88, 61, 1, 97,
	69, 25, 116, 92, 70, 159, 131, 111, 205, 171, 137, 229, 200, 209, 255, 255,
	6, 42, 128, 21, 61, 143, 28, 69, 153, 50, 89, 174, 97, 133, 221, 138,
	180, 255, 164, 202, 255, 235, 255, 255, 6, 42, 128, 21, 61, 143, 28, 69,
	153, 50, 89, 174, 97, 133, 221, 138, 180, 255, 164, 202, 255, 235, 255, 255,
	42, 20, 155, 57, 34, 174, 66, 45, 173, 89, 63, 195, 132, 108, 239, 178,
	154, 255, 200, 184, 255, 255, 248, 255, 42, 20, 155, 57, 34, 174, 66, 45,
	173, 89, 63, 195, 132, 108, 239, 178, 154, 255, 200, 184, 255, 255, 248, 255,
	11, 73, 0, 25, 89, 0, 29, 98, 0, 50, 118, 0, 93, 163, 41, 136,
	203, 89, 162, 229, 122, 237, 255, 188, 11, 73, 0, 25, 89, 0, 29, 98,
	0, 50, 118, 0, 93, 163, 41, 136, 203, 89, 162, 229, 122, 237, 255, 188 };
static const unsigned char CiBinaryResource_zx81_fnt[512] = { 0, 0, 0, 0, 0, 0, 0, 0, 240, 240, 240, 240, 0, 0, 0, 0,
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

struct RgbStream {
	RleStream base;
};
static void RgbStream_Construct(RgbStream *self, const RleStreamVtbl *vtbl);
static cibool RgbStream_ReadCommand(RgbStream *self);
static int RgbStream_ReadValue(RgbStream *self);
static const RleStreamVtbl CiVtbl_RgbStream = {
	(cibool (*)(RleStream *self)) RgbStream_ReadCommand,
	(int (*)(RleStream *self)) RgbStream_ReadValue
};

struct SpcStream {
	RleStream base;
};
static void SpcStream_Construct(SpcStream *self, const RleStreamVtbl *vtbl);
static cibool SpcStream_ReadCommand(SpcStream *self);
static const RleStreamVtbl CiVtbl_SpcStream = {
	(cibool (*)(RleStream *self)) SpcStream_ReadCommand,
	RleStream_ReadValue
};

struct SpsStream {
	RleStream base;
};
static void SpsStream_Construct(SpsStream *self, const RleStreamVtbl *vtbl);
static cibool SpsStream_ReadCommand(SpsStream *self);
static const RleStreamVtbl CiVtbl_SpsStream = {
	(cibool (*)(RleStream *self)) SpsStream_ReadCommand,
	RleStream_ReadValue
};

struct Sr8Stream {
	RleStream base;
};
static void Sr8Stream_Construct(Sr8Stream *self, const RleStreamVtbl *vtbl);
static cibool Sr8Stream_ReadCommand(Sr8Stream *self);
static const RleStreamVtbl CiVtbl_Sr8Stream = {
	(cibool (*)(RleStream *self)) Sr8Stream_ReadCommand,
	RleStream_ReadValue
};

struct TnyStream {
	TnyPcsStream base;
	int valueLength;
	int valueOffset;
};
static void TnyStream_Construct(TnyStream *self, const RleStreamVtbl *vtbl);
static int TnyStream_ReadValue(TnyStream *self);
static const RleStreamVtbl CiVtbl_TnyStream = {
	(cibool (*)(RleStream *self)) TnyPcsStream_ReadCommand,
	(int (*)(RleStream *self)) TnyStream_ReadValue
};

struct VdatStream {
	TnyStream base;
};
static void VdatStream_Construct(VdatStream *self, const RleStreamVtbl *vtbl);
static cibool VdatStream_ReadCommand(VdatStream *self);
static const RleStreamVtbl CiVtbl_VdatStream = {
	(cibool (*)(RleStream *self)) VdatStream_ReadCommand,
	(int (*)(RleStream *self)) TnyStream_ReadValue
};

struct XeKoalaStream {
	RleStream base;
};
static void XeKoalaStream_Construct(XeKoalaStream *self, const RleStreamVtbl *vtbl);
static cibool XeKoalaStream_ReadCommand(XeKoalaStream *self);
static cibool XeKoalaStream_UnpackRaw(int type, unsigned char const *content, int contentOffset, int contentLength, unsigned char *unpacked, int unpackedLength);
static cibool XeKoalaStream_UnpackWrapped(unsigned char const *content, int contentLength, unsigned char *unpacked, int unpackedLength);
static const RleStreamVtbl CiVtbl_XeKoalaStream = {
	(cibool (*)(RleStream *self)) XeKoalaStream_ReadCommand,
	RleStream_ReadValue
};

struct XlpStream {
	RleStream base;
};
static void XlpStream_Construct(XlpStream *self, const RleStreamVtbl *vtbl);
static cibool XlpStream_ReadCommand(XlpStream *self);
static const RleStreamVtbl CiVtbl_XlpStream = {
	(cibool (*)(RleStream *self)) XlpStream_ReadCommand,
	RleStream_ReadValue
};

struct ZxpStream {
	Stream base;
};
static cibool ZxpStream_IsEof(ZxpStream const *self);
static int ZxpStream_ReadChar(ZxpStream *self);
static int ZxpStream_ReadHexDigit(ZxpStream *self);

static void A4rStream_Construct(A4rStream *self)
{
	self->outerFlags = self->innerFlags = 0;
}

static cibool A4rStream_CopyBlock(A4rStream *self, int distance, int length)
{
	if (distance > self->unpackedOffset)
		return FALSE;
	do {
		if (!A4rStream_StoreByte(self, self->unpacked[self->unpackedOffset - distance]))
			return FALSE;
	}
	while (--length > 0);
	return TRUE;
}

static int A4rStream_ReadFlag(A4rStream *self)
{
	if ((self->innerFlags & 127) == 0) {
		if ((self->outerFlags & 127) == 0) {
			if (self->base.contentOffset >= self->base.contentLength)
				return -1;
			self->outerFlags = (self->base.content[self->base.contentOffset++] << 1) | 1;
		}
		else
			self->outerFlags <<= 1;
		if ((self->outerFlags & 256) == 0)
			self->innerFlags = 1;
		else {
			if (self->base.contentOffset >= self->base.contentLength)
				return -1;
			self->innerFlags = (self->base.content[self->base.contentOffset++] << 1) | 1;
		}
	}
	else
		self->innerFlags <<= 1;
	return (self->innerFlags >> 8) & 1;
}

static cibool A4rStream_StoreByte(A4rStream *self, int value)
{
	if (self->unpackedOffset < 0 || self->unpackedOffset >= 11248)
		return FALSE;
	self->unpacked[self->unpackedOffset++] = value;
	return TRUE;
}

static cibool A4rStream_UnpackA4r(A4rStream *self)
{
	memset(self->unpacked, 0, sizeof(self->unpacked));
	self->unpackedOffset = -1;
	for (;;) {
		int b;
		switch (A4rStream_ReadFlag(self)) {
		case -1:
			return FALSE;
		case 0:
			b = Stream_ReadByte(&self->base);
			if (b < 0)
				return FALSE;
			if (!A4rStream_StoreByte(self, b))
				return FALSE;
			break;
		case 1:
			b = Stream_ReadByte(&self->base);
			switch (b) {
			case -1:
				return FALSE;
			case 0:
				if (self->base.contentOffset + 2 >= self->base.contentLength)
					return FALSE;
				b = Stream_ReadByte(&self->base);
				self->unpackedOffset = b + (Stream_ReadByte(&self->base) << 8) + 128 - 19984;
				if (!A4rStream_StoreByte(self, Stream_ReadByte(&self->base)))
					return FALSE;
				break;
			case 1:
				b = Stream_ReadByte(&self->base);
				switch (b) {
				case -1:
					return FALSE;
				case 0:
					return TRUE;
				default:
					if (!A4rStream_CopyBlock(self, 1, b + 2))
						return FALSE;
					break;
				}
				break;
			default:
				if (!A4rStream_CopyBlock(self, 128 - (b >> 1), 2 + (b & 1)))
					return FALSE;
				break;
			}
			break;
		}
	}
}

static void AmstradStream_Construct(AmstradStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_AmstradStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool AmstradStream_ReadCommand(AmstradStream *self)
{
	int b;
	while (self->blockLength <= 0) {
		int lo;
		int hi;
		if (Stream_ReadByte(&self->base.base.base) != 77 || Stream_ReadByte(&self->base.base.base) != 74 || Stream_ReadByte(&self->base.base.base) != 72)
			return FALSE;
		lo = Stream_ReadByte(&self->base.base.base);
		if (lo < 0)
			return FALSE;
		hi = Stream_ReadByte(&self->base.base.base);
		if (hi < 0)
			return FALSE;
		self->blockLength = (hi << 8) | lo;
	}
	b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
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
	return TRUE;
}

static void BbgStream_Construct(BbgStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_BbgStream;
	RleStream_Construct(&self->base, vtbl);
}

static int BbgStream_ReadBitsReverse(BbgStream *self, int count)
{
	int result = 0;
	{
		int i;
		for (i = 0; i < count; i++) {
			switch (BitStream_ReadBit(&self->base.base)) {
			case -1:
				return -1;
			case 1:
				result |= 1 << i;
				break;
			case 0:
				break;
			}
		}
	}
	return result;
}

static cibool BbgStream_ReadCommand(BbgStream *self)
{
	switch (BitStream_ReadBit(&self->base.base)) {
	case -1:
		return FALSE;
	case 0:
		self->base.repeatCount = 1;
		break;
	case 1:
		self->base.repeatCount = BbgStream_ReadBitsReverse(self, self->countBits);
		if (self->base.repeatCount <= 0)
			return FALSE;
		break;
	}
	self->base.repeatValue = BbgStream_ReadBitsReverse(self, self->valueBits);
	return TRUE;
}

static void BitStream_Construct(BitStream *self)
{
	self->bits = 0;
}

static int BitStream_ReadBit(BitStream *self)
{
	if ((self->bits & 127) == 0) {
		if (self->base.contentOffset >= self->base.contentLength)
			return -1;
		self->bits = (self->base.content[self->base.contentOffset++] << 1) | 1;
	}
	else
		self->bits <<= 1;
	return (self->bits >> 8) & 1;
}

static int BitStream_ReadBits(BitStream *self, int count)
{
	int result = 0;
	while (--count >= 0) {
		int bit = BitStream_ReadBit(self);
		if (bit < 0)
			return -1;
		result = (result << 1) | bit;
	}
	return result;
}

static cibool BlazingPaddlesBoundingBox_Calculate(BlazingPaddlesBoundingBox *self, unsigned char const *content, int contentLength, int index, int startAddress)
{
	int contentOffset;
	int x;
	int y;
	if (index * 2 + 1 >= contentLength)
		return FALSE;
	contentOffset = content[index * 2] + (content[index * 2 + 1] << 8) - startAddress;
	if (contentOffset < 0)
		return FALSE;
	self->left = self->top = self->right = self->bottom = 0;
	x = 0;
	y = 0;
	while (contentOffset < contentLength) {
		int control = content[contentOffset++];
		int len;
		if (control == 8)
			return TRUE;
		len = (control >> 4) + 1;
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
		}
	}
	return FALSE;
}

static void C64KoalaStream_Construct(C64KoalaStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_C64KoalaStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool C64KoalaStream_ReadCommand(C64KoalaStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b == 254) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatValue = b;
		self->base.repeatCount = 1;
	}
	return TRUE;
}

static void CaStream_Construct(CaStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_CaStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool CaStream_ReadCommand(CaStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	int c;
	if (b < 0)
		return FALSE;
	if (b != self->escapeByte) {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return TRUE;
	}
	c = Stream_ReadByte(&self->base.base.base);
	if (c < 0)
		return FALSE;
	if (c == self->escapeByte) {
		self->base.repeatCount = 1;
		self->base.repeatValue = c;
		return TRUE;
	}
	b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	switch (c) {
	case 0:
		self->base.repeatCount = b + 1;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		break;
	case 1:
		c = Stream_ReadByte(&self->base.base.base);
		if (c < 0)
			return FALSE;
		self->base.repeatCount = (b << 8) + c + 1;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		break;
	case 2:
		if (b == 0)
			self->base.repeatCount = 32000;
		else {
			c = Stream_ReadByte(&self->base.base.base);
			if (c < 0)
				return FALSE;
			self->base.repeatCount = (b << 8) + c + 1;
		}
		self->base.repeatValue = self->defaultValue;
		break;
	default:
		self->base.repeatCount = c + 1;
		self->base.repeatValue = b;
		break;
	}
	return TRUE;
}

static cibool CaStream_UnpackCa(unsigned char const *content, int contentOffset, int contentLength, unsigned char *unpacked, int unpackedOffset)
{
	CaStream rle;
	int unpackedStep;
	unsigned char isFilled[32000];
	if (contentOffset + 4 > contentLength)
		return FALSE;
	CaStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset + 4;
	rle.base.base.base.contentLength = contentLength;
	rle.escapeByte = content[contentOffset];
	rle.defaultValue = content[contentOffset + 1];
	unpackedStep = (content[contentOffset + 2] << 8) | content[contentOffset + 3];
	if (unpackedStep >= 32000)
		return FALSE;
	if (unpackedStep == 0) {
		rle.base.repeatCount = 32000;
		rle.base.repeatValue = rle.defaultValue;
		unpackedStep = 1;
	}
	memset(isFilled, 0, sizeof(isFilled));
	{
		int offset;
		for (offset = 0;;) {
			int b = RleStream_ReadRle(&rle.base);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset + offset] = b;
			isFilled[offset] = 1;
			offset += unpackedStep;
			if (offset >= 32000) {
				for (offset = 1; isFilled[offset] != 0; offset++)
					if (offset >= unpackedStep)
						return TRUE;
			}
		}
	}
}

static cibool CaStream_UnpackDel(unsigned char const *content, int contentLength, unsigned char *unpacked, int blocks)
{
	int contentOffset = blocks << 2;
	int unpackedOffset;
	if (contentOffset >= contentLength)
		return FALSE;
	unpackedOffset = 0;
	{
		int block;
		for (block = 0; block < blocks; block++) {
			int nextContentOffset = contentOffset + RECOIL_Get32BigEndian(content, block << 2);
			if (!CaStream_UnpackCa(content, contentOffset, nextContentOffset, unpacked, unpackedOffset))
				return FALSE;
			contentOffset = nextContentOffset;
			unpackedOffset += 32000;
		}
	}
	if (blocks == 2) {
		if (!CaStream_UnpackCa(content, contentOffset, contentLength, unpacked, unpackedOffset))
			return FALSE;
	}
	return TRUE;
}

static void CciStream_Construct(CciStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_CciStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool CciStream_ReadCommand(CciStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		self->base.repeatCount = b + 1;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = b - 127;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	return TRUE;
}

static cibool CciStream_UnpackGr15(CciStream *self, unsigned char *unpacked, int unpackedOffset)
{
	self->base.base.base.contentOffset += 4;
	self->base.repeatCount = 0;
	{
		int offset;
		for (offset = 0;;) {
			int b = RleStream_ReadRle(&self->base);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset + offset] = b;
			offset += 80;
			if (offset >= 7680) {
				offset -= 7679;
				if (offset >= 40)
					return TRUE;
			}
		}
	}
}

static void DrpStream_Construct(DrpStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_DrpStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool DrpStream_ReadCommand(DrpStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b == self->escape) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
	}
	return TRUE;
}

static unsigned char const *DrpStream_UnpackFile(unsigned char const *content, int contentLength, const char *signature, unsigned char *unpacked, int unpackedLength)
{
	if (contentLength > 16 && RECOIL_IsStringAt(content, 2, signature)) {
		DrpStream rle;
		DrpStream_Construct(&rle, NULL);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 16;
		rle.base.base.base.contentLength = contentLength;
		rle.escape = content[15];
		if (!RleStream_UnpackC64(&rle.base, unpacked, unpackedLength))
			return NULL;
		return unpacked;
	}
	if (contentLength != unpackedLength)
		return NULL;
	return content;
}

static void FanoTree_Create(FanoTree *self, unsigned char const *content, int contentOffset, int codeCount)
{
	int positions[16];
	int position;
	memset(self->count, 0, sizeof(self->count));
	{
		int code;
		for (code = 0; code < codeCount; code++) {
			int bits = content[contentOffset + (code >> 1)];
			bits = (code & 1) == 0 ? bits >> 4 : bits & 15;
			self->count[bits]++;
		}
	}
	position = 0;
	{
		int bits;
		for (bits = 0; bits < 16; bits++) {
			positions[bits] = position;
			position += self->count[bits];
		}
	}
	{
		int code;
		for (code = 0; code < codeCount; code++) {
			int bits = content[contentOffset + (code >> 1)];
			bits = (code & 1) == 0 ? bits >> 4 : bits & 15;
			self->values[positions[bits]++] = code;
		}
	}
}

static int FanoTree_ReadCode(FanoTree const *self, BitStream *bitStream)
{
	int code = 0;
	int valuesOffset = self->count[0];
	{
		int bits;
		for (bits = 1; bits < 16; bits++) {
			int bit = BitStream_ReadBit(bitStream);
			int count;
			if (bit < 0)
				return -1;
			code = (code << 1) | bit;
			count = self->count[bits];
			if (code < count)
				return self->values[valuesOffset + code];
			code -= count;
			valuesOffset += count;
		}
	}
	return -1;
}

static void GoDotStream_Construct(GoDotStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_GoDotStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool GoDotStream_ReadCommand(GoDotStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b == 173) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
	}
	return TRUE;
}

static void HimStream_Construct(HimStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_HimStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool HimStream_ReadCommand(HimStream *self)
{
	int b = self->base.vtbl->readValue(&self->base);
	switch (b) {
	case -1:
		return FALSE;
	case 0:
		self->base.repeatCount = self->base.vtbl->readValue(&self->base);
		if (self->base.repeatCount <= 0)
			return FALSE;
		self->base.repeatValue = self->base.vtbl->readValue(&self->base);
		return TRUE;
	default:
		self->base.repeatCount = b - 1;
		self->base.repeatValue = -1;
		return TRUE;
	}
}

static int HimStream_ReadValue(HimStream *self)
{
	if (self->base.base.base.contentOffset < 18)
		return -1;
	return self->base.base.base.content[self->base.base.base.contentOffset--];
}

static void HpmStream_Construct(HpmStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_HpmStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool HpmStream_ReadCommand(HpmStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b == 0) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = b;
		self->base.repeatValue = -1;
	}
	return TRUE;
}

static cibool IcnParser_Expect(IcnParser *self, const char *s)
{
	int length;
	if (!IcnParser_SkipWhitespace(self))
		return FALSE;
	length = (int) strlen(s);
	{
		int i;
		for (i = 0; i < length; i++)
			if (self->base.content[self->base.contentOffset++] != s[i])
				return FALSE;
	}
	return TRUE;
}

static int IcnParser_ParseDefine(IcnParser *self, const char *s)
{
	if (!IcnParser_Expect(self, "#define") || !IcnParser_Expect(self, s))
		return -1;
	return IcnParser_ParseHex(self);
}

static int IcnParser_ParseHex(IcnParser *self)
{
	int r;
	if (!IcnParser_Expect(self, "0x"))
		return -1;
	r = 0;
	for (; self->base.contentOffset < self->base.contentLength; self->base.contentOffset++) {
		int c = self->base.content[self->base.contentOffset];
		if (c >= 48 && c <= 57)
			c -= 48;
		else if (c >= 65 && c <= 70)
			c -= 55;
		else if (c >= 97 && c <= 102)
			c -= 87;
		else
			return r;
		if (r >> 12 != 0)
			return -1;
		r = (r << 4) | c;
	}
	return r;
}

static cibool IcnParser_SkipWhitespace(IcnParser *self)
{
	cibool got = FALSE;
	while (self->base.contentOffset < self->base.contentLength) {
		switch (self->base.content[self->base.contentOffset]) {
		case 32:
		case 9:
		case 13:
		case 10:
			self->base.contentOffset++;
			got = TRUE;
			break;
		case 47:
			if (self->base.contentOffset + 3 >= self->base.contentLength || self->base.content[self->base.contentOffset + 1] != 42)
				return FALSE;
			self->base.contentOffset += 3;
			do {
				if (++self->base.contentOffset > self->base.contentLength)
					return FALSE;
			}
			while (self->base.content[self->base.contentOffset - 2] != 42 || self->base.content[self->base.contentOffset - 1] != 47);
			got = TRUE;
			break;
		default:
			return got;
		}
	}
	return TRUE;
}

static void ImgStream_Construct(ImgStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_ImgStream;
	RleStream_Construct(&self->base, vtbl);
	self->patternRepeatCount = 0;
}

static int ImgStream_GetLineRepeatCount(ImgStream *self)
{
	if (self->base.repeatCount == 0 && self->base.base.base.contentOffset + 4 < self->base.base.base.contentLength && self->base.base.base.content[self->base.base.base.contentOffset] == 0 && self->base.base.base.content[self->base.base.base.contentOffset + 1] == 0 && self->base.base.base.content[self->base.base.base.contentOffset + 2] == 255) {
		self->base.base.base.contentOffset += 4;
		return self->base.base.base.content[self->base.base.base.contentOffset - 1] + 1;
	}
	return 1;
}

static cibool ImgStream_ReadCommand(ImgStream *self)
{
	int b;
	if (self->patternRepeatCount > 1) {
		self->patternRepeatCount--;
		self->base.repeatCount = (self->base.base.base.content[6] << 8) | self->base.base.base.content[7];
		self->base.base.base.contentOffset -= self->base.repeatCount;
		return TRUE;
	}
	b = Stream_ReadByte(&self->base.base.base);
	switch (b) {
	case -1:
		return FALSE;
	case 0:
		b = Stream_ReadByte(&self->base.base.base);
		if (b <= 0)
			return FALSE;
		self->patternRepeatCount = b;
		self->base.repeatCount = (self->base.base.base.content[6] << 8) | self->base.base.base.content[7];
		self->base.repeatValue = -1;
		return TRUE;
	case 128:
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount < 0)
			return FALSE;
		self->base.repeatValue = -1;
		return TRUE;
	default:
		self->base.repeatCount = b & 127;
		self->base.repeatValue = b >= 128 ? 255 : 0;
		return TRUE;
	}
}

static cibool Lz4Stream_Copy(Lz4Stream *self, int count)
{
	if (self->base.contentOffset + count > self->base.contentLength || self->unpackedOffset + count > self->unpackedLength)
		return FALSE;
	memcpy(self->unpacked + self->unpackedOffset, self->base.content + self->base.contentOffset, count);
	self->base.contentOffset += count;
	self->unpackedOffset += count;
	return TRUE;
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
		rgb = ((rgb & 448) << 10) | ((rgb & 56) << 5) | (rgb & 7);
		return (rgb << 5) | (rgb << 2) | ((rgb >> 1) & 197379);
	case 1:
		rgb = BitStream_ReadBits(&self->base, 12);
		rgb = ((rgb & 1792) << 9) | ((rgb & 2160) << 5) | ((rgb & 135) << 1) | ((rgb & 8) >> 3);
		return (rgb << 4) | rgb;
	case 3:
		rgb = BitStream_ReadBits(&self->base, 15);
		rgb = ((rgb & 1792) << 10) | ((rgb & 2048) << 6) | ((rgb & 16519) << 2) | ((rgb & 112) << 6) | ((rgb & 8192) >> 5) | ((rgb & 8) >> 2) | ((rgb & 4096) >> 12);
		return (rgb << 3) | ((rgb >> 2) & 460551);
	default:
		return 0;
	}
}

static void MspStream_Construct(MspStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_MspStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool MspStream_ReadCommand(MspStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b == 0) {
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = b;
		self->base.repeatValue = -1;
	}
	return TRUE;
}

static cibool PInterpreter_DPeek(PInterpreter *self, int expectedX, int expectedAddress)
{
	return Stream_ReadByte(&self->base) == 20 && PInterpreter_ReadNumber(self) == expectedX && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 211 && PInterpreter_ReadNumber(self) == expectedAddress && Stream_ReadByte(&self->base) == 21 && PInterpreter_ReadNumber(self) == 256 && Stream_ReadByte(&self->base) == 23 && Stream_ReadByte(&self->base) == 211 && PInterpreter_ReadNumber(self) == expectedAddress + 1;
}

static cibool PInterpreter_DoFor(PInterpreter *self)
{
	self->bottomCode |= 4;
	return Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 20 && PInterpreter_ReadNumber(self) == 0 && Stream_ReadByte(&self->base) == 223 && PInterpreter_ReadNumber(self) == 63;
}

static cibool PInterpreter_DoIf(PInterpreter *self)
{
	return Stream_ReadByte(&self->base) == 198 && Stream_ReadByte(&self->base) == 38 && Stream_ReadByte(&self->base) == 13 && Stream_ReadByte(&self->base) == 221 && PInterpreter_ReadNumber(self) == 64 && Stream_ReadByte(&self->base) == 222 && Stream_ReadByte(&self->base) == 227;
}

static cibool PInterpreter_Let(PInterpreter *self)
{
	switch (Stream_ReadByte(&self->base)) {
	case 38:
		if (Stream_ReadByte(&self->base) != 13 || Stream_ReadByte(&self->base) != 20 || Stream_ReadByte(&self->base) != 11)
			return FALSE;
		self->bottomOffset = self->base.contentOffset;
		for (;;) {
			switch (Stream_ReadByte(&self->base)) {
			case -1:
				return FALSE;
			case 11:
				return TRUE;
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
		return FALSE;
	}
}

static cibool PInterpreter_Next(PInterpreter *self)
{
	if (Stream_ReadByte(&self->base) == 43 && self->bottomOffset > 0 && self->bottomCode == 15) {
		self->screenOffset = 704;
		return PInterpreter_PrintString(self, self->bottomOffset) >= 0;
	}
	return FALSE;
}

static cibool PInterpreter_Poke(PInterpreter *self)
{
	self->bottomCode |= 8;
	return Stream_ReadByte(&self->base) == 41 && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 16 && Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 18 && PInterpreter_ReadNumber(self) == 31 && Stream_ReadByte(&self->base) == 17 && Stream_ReadByte(&self->base) == 26 && Stream_ReadByte(&self->base) == 211 && Stream_ReadByte(&self->base) == 16 && Stream_ReadByte(&self->base) == 56 && Stream_ReadByte(&self->base) == 21 && Stream_ReadByte(&self->base) == 43 && Stream_ReadByte(&self->base) == 17;
}

static cibool PInterpreter_Print(PInterpreter *self)
{
	for (;;) {
		switch (Stream_ReadByte(&self->base)) {
			int row;
			int column;
		case 11:
			self->base.contentOffset = PInterpreter_PrintString(self, self->base.contentOffset);
			if (self->base.contentOffset < 0)
				return FALSE;
			break;
		case 193:
			row = PInterpreter_ReadNumber(self);
			if (row < 0 || row > 21 || Stream_ReadByte(&self->base) != 26)
				return FALSE;
			column = PInterpreter_ReadNumber(self);
			if (column < 0 || column > 31)
				return FALSE;
			self->screenOffset = (row << 5) | column;
			break;
		case 0:
		case 25:
			break;
		case 118:
			self->base.contentOffset--;
			if (self->base.content[self->base.contentOffset - 1] != 25) {
				self->screenOffset = (self->screenOffset & ~31) + 32;
			}
			return TRUE;
		default:
			return FALSE;
		}
	}
}

static int PInterpreter_PrintString(PInterpreter *self, int offset)
{
	for (;;) {
		int c;
		if (offset >= self->base.contentLength)
			return -1;
		c = self->base.content[offset++];
		if (c == 11)
			break;
		if (self->screenOffset >= 768)
			return -1;
		if (c == 192)
			c = 11;
		else if ((c & 127) >= 64)
			return -1;
		self->screen[self->screenOffset++] = c;
	}
	return offset;
}

static int PInterpreter_ReadNumber(PInterpreter *self)
{
	for (;;) {
		switch (Stream_ReadByte(&self->base)) {
			int exp;
			int m0;
			int m1;
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
			if (self->base.contentOffset + 5 > self->base.contentLength)
				return -1;
			exp = Stream_ReadByte(&self->base);
			m0 = Stream_ReadByte(&self->base);
			m1 = Stream_ReadByte(&self->base);
			self->base.contentOffset += 2;
			if (exp > 144 || m0 >= 128)
				return -1;
			if (exp <= 128)
				return 0;
			return (((m0 | 128) << 8) | m1) >> (144 - exp);
		default:
			return -1;
		}
	}
}

static cibool PInterpreter_Run(PInterpreter *self)
{
	self->base.contentOffset = 116;
	memset(self->screen, 0, sizeof(self->screen));
	self->screenOffset = 0;
	self->bottomOffset = -1;
	self->bottomCode = 0;
	for (;;) {
		if (self->base.contentOffset + 8 > self->base.contentLength)
			return FALSE;
		if (Stream_ReadByte(&self->base) == 118)
			return TRUE;
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
			return TRUE;
		case 245:
			if (!PInterpreter_Print(self))
				return FALSE;
			break;
		case 241:
			if (!PInterpreter_Let(self))
				return FALSE;
			break;
		case 250:
			if (!PInterpreter_DoIf(self))
				return FALSE;
			break;
		case 235:
			if (!PInterpreter_DoFor(self))
				return FALSE;
			break;
		case 244:
			if (!PInterpreter_Poke(self))
				return FALSE;
			break;
		case 243:
			if (!PInterpreter_Next(self))
				return FALSE;
			break;
		default:
			return FALSE;
		}
		if (Stream_ReadByte(&self->base) != 118)
			return FALSE;
	}
}

static void PacStream_Construct(PacStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_PacStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool PacStream_ReadCommand(PacStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b == self->base.base.base.content[4]) {
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return FALSE;
		self->base.repeatCount = b + 1;
		self->base.repeatValue = self->base.base.base.content[5];
	}
	else if (b == self->base.base.base.content[6]) {
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatValue < 0)
			return FALSE;
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return FALSE;
		self->base.repeatCount = b + 1;
	}
	else {
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
	}
	return TRUE;
}

static void PackBitsStream_Construct(PackBitsStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_PackBitsStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool PackBitsStream_ReadCommand(PackBitsStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		self->base.repeatCount = b + 1;
		self->base.repeatValue = -1;
	}
	else if (b > 128) {
		self->base.repeatCount = 257 - b;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else
		self->base.repeatCount = 0;
	return TRUE;
}

static void PcsStream_Construct(PcsStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_PcsStream;
	TnyPcsStream_Construct(&self->base, vtbl);
}

static int PcsStream_ReadValue(PcsStream *self)
{
	int value;
	if (!self->palette)
		return Stream_ReadByte(&self->base.base.base.base);
	if (self->base.base.base.base.contentOffset + 1 >= self->base.base.base.base.contentLength)
		return -1;
	value = (self->base.base.base.base.content[self->base.base.base.base.contentOffset] << 8) | self->base.base.base.base.content[self->base.base.base.base.contentOffset + 1];
	self->base.base.base.base.contentOffset += 2;
	return value;
}

static cibool PcsStream_UnpackPcs(PcsStream *self, unsigned char *unpacked)
{
	self->base.base.base.base.contentOffset += 2;
	self->palette = FALSE;
	{
		int unpackedOffset;
		for (unpackedOffset = 0; unpackedOffset < 32000; unpackedOffset++) {
			int b = RleStream_ReadRle(&self->base.base);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset] = b;
		}
	}
	if (self->base.base.repeatCount != 0)
		return FALSE;
	self->base.base.base.base.contentOffset += 2;
	self->palette = TRUE;
	{
		int unpackedOffset;
		for (unpackedOffset = 32000; unpackedOffset < 51232; unpackedOffset += 2) {
			int b = RleStream_ReadRle(&self->base.base);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset] = b >> 8;
			unpacked[unpackedOffset + 1] = (unsigned char) b;
		}
	}
	return TRUE;
}

static void PgcStream_Construct(PgcStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_PgcStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool PgcStream_ReadCommand(PgcStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		self->base.repeatCount = b;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = b - 128;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	return TRUE;
}

static void RECOIL_Construct(RECOIL *self)
{
	RECOIL_SetAtari8Palette(self, NULL);
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
	free(self);
}

static cibool RECOIL_ApplyAtari8Palette(RECOIL *self, unsigned char const *frame)
{
	int pixelsLength = self->width * self->height;
	{
		int i;
		for (i = 0; i < pixelsLength; i++)
			self->pixels[i] = self->atari8Palette[frame[i]];
	}
	return TRUE;
}

static cibool RECOIL_ApplyAtari8PaletteBlend(RECOIL *self, unsigned char const *frame1, unsigned char const *frame2)
{
	int pixelsLength = self->width * self->height;
	self->frames = 2;
	{
		int i;
		for (i = 0; i < pixelsLength; i++) {
			int rgb1 = self->atari8Palette[frame1[i]];
			int rgb2 = self->atari8Palette[frame2[i]];
			self->pixels[i] = (rgb1 & rgb2) + (((rgb1 ^ rgb2) >> 1) & 8355711);
		}
	}
	return TRUE;
}

static cibool RECOIL_ApplyAtari8PaletteBlend3(RECOIL *self, unsigned char const *frame1, unsigned char const *frame2, unsigned char const *frame3)
{
	int pixelsLength = self->width * self->height;
	self->frames = 3;
	{
		int i;
		for (i = 0; i < pixelsLength; i++) {
			int rgb1 = self->atari8Palette[frame1[i]];
			int rgb2 = self->atari8Palette[frame2[i]];
			int rgb3 = self->atari8Palette[frame3[i]];
			self->pixels[i] = (((rgb1 >> 16) + (rgb2 >> 16) + (rgb3 >> 16)) / 3 << 16) | ((((rgb1 >> 8) & 255) + ((rgb2 >> 8) & 255) + ((rgb3 >> 8) & 255)) / 3 << 8) | ((rgb1 & 255) + (rgb2 & 255) + (rgb3 & 255)) / 3;
		}
	}
	return TRUE;
}

static cibool RECOIL_ApplyBlend(RECOIL *self)
{
	int pixelsLength = self->width * self->height;
	self->frames = 2;
	{
		int i;
		for (i = 0; i < pixelsLength; i++) {
			int rgb1 = self->pixels[i];
			int rgb2 = self->pixels[pixelsLength + i];
			self->pixels[i] = (rgb1 & rgb2) + (((rgb1 ^ rgb2) >> 1) & 8355711);
		}
	}
	return TRUE;
}

static void RECOIL_CalculatePalette(RECOIL *self, int *palette, int paletteOffset, int paletteLength)
{
	int pixelsCount = self->width * self->height;
	{
		int pixelsOffset;
		for (pixelsOffset = 0; pixelsOffset < pixelsCount; pixelsOffset++) {
			int rgb = self->pixels[pixelsOffset];
			int index = RECOIL_FindColor(palette, paletteOffset, rgb);
			if (index >= paletteOffset || palette[index] != rgb) {
				if (paletteOffset == paletteLength) {
					self->colors = 0;
					return;
				}
				{
					int j;
					for (j = paletteOffset; --j >= index;)
						palette[j + 1] = palette[j];
				}
				palette[index] = rgb;
				paletteOffset++;
			}
		}
	}
	self->colors = paletteOffset;
}

cibool RECOIL_Decode(RECOIL *self, const char *filename, unsigned char const *content, int contentLength)
{
	switch (RECOIL_GetPackedExt(filename)) {
	case 540423474:
		return RECOIL_Decode256(self, content, contentLength);
	case 538976307:
		return RECOIL_Decode3(self, content, contentLength);
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
	case 544355425:
		return RECOIL_DecodeA4r(self, content, contentLength);
	case 540292705:
	case 543648119:
		return contentLength == 10242 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8194, 9218, content[10241]);
	case 544432481:
	case 543715433:
		return RECOIL_DecodeIph(self, content, contentLength);
	case 544432993:
		return RECOIL_DecodeAcs(self, content, contentLength);
	case 543975009:
		return RECOIL_DecodeAfl(self, content, contentLength);
	case 544237409:
		return RECOIL_DecodeAgp(self, content, contentLength);
	case 543976545:
		return RECOIL_DecodeAll(self, content, contentLength);
	case 543780193:
		return RECOIL_DecodeAmi(self, content, contentLength);
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
	case 543387745:
		return RECOIL_DecodeApc(self, content, contentLength);
	case 543977569:
		return RECOIL_DecodeApl(self, content, contentLength);
	case 544239713:
		return RECOIL_DecodeApp(self, content, contentLength);
	case 544502369:
		return RECOIL_DecodeIph(self, content, contentLength) || RECOIL_DecodeArtDirector(self, content, contentLength) || RECOIL_DecodeAtari8Artist(self, content, contentLength) || RECOIL_DecodeAsciiArtEditor(self, content, contentLength);
	case 544371809:
		return RECOIL_DecodeAtr(self, content, contentLength);
	case 540041826:
		return RECOIL_DecodeBb0(self, content, contentLength, RECOIL_BbcPalette1Bit);
	case 540107362:
		return RECOIL_DecodeBb1(self, content, contentLength, RECOIL_BbcPalette2Bit);
	case 540172898:
		return RECOIL_DecodeBb2(self, content, contentLength, RECOIL_BbcPalette);
	case 540303970:
		return RECOIL_DecodeBb4(self, content, contentLength, RECOIL_BbcPalette1Bit);
	case 540369506:
		return RECOIL_DecodeBb5(self, content, contentLength, RECOIL_BbcPalette2Bit);
	case 543646306:
		return RECOIL_DecodeBbg(self, content, contentLength);
	case 1768711778:
		return RECOIL_DecodeBfli(self, content, contentLength);
	case 540632930:
	case 540618855:
		return RECOIL_DecodeG09(self, content, contentLength);
	case 544237410:
		return RECOIL_DecodeBgp(self, content, contentLength);
	case 543648610:
		return RECOIL_DecodeBkg(self, content, contentLength);
	case 543976802:
		return RECOIL_DecodeBml(self, content, contentLength);
	case 544567906:
		return RECOIL_DecodeBru(self, content, contentLength);
	case 540107107:
	case 540172643:
	case 540238179:
		return RECOIL_DecodeCa(self, content, contentLength);
	case 543777635:
		return RECOIL_DecodeCci(self, content, contentLength);
	case 544564323:
		return contentLength == 10277 && RECOIL_DecodeC64Multicolor(self, 320, content, 275, 8275, 9275, content[10275]);
	case 540305507:
	case 540436579:
	case 540567651:
		return RECOIL_DecodeCh8(self, content, contentLength);
	case 543516771:
		return contentLength == 20482 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 16898, 18434, 0);
	case 544368739:
		return RECOIL_DecodeChr(self, content, contentLength);
	case 544106851:
		return RECOIL_DecodeCin(self, content, contentLength);
	case 544370787:
		return RECOIL_DecodeCpr(self, content, contentLength);
	case 544501859:
		return RECOIL_DecodeCpt(self, content, contentLength);
	case 543651683:
		return contentLength == 10007 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8002, 9002, content[10003]);
	case 540107620:
	case 543385444:
		return RECOIL_DecodeDgc(self, content, contentLength);
	case 538993764:
		return RECOIL_DecodeDd(self, content, contentLength);
	case 543974756:
		return RECOIL_DecodeDel(self, content, contentLength);
	case 540108644:
	case 544565092:
		return RECOIL_DecodeDgu(self, content, contentLength);
	case 544368740:
		return RECOIL_DecodeDhr(self, content, contentLength);
	case 544106852:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, FALSE, 3);
	case 544042084:
		return RECOIL_DecodeDlm(self, content, contentLength);
	case 543977316:
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
	case 543777637:
		return RECOIL_DecodeEci(self, content, contentLength);
	case 544236389:
		return RECOIL_DecodeEcp(self, content, contentLength);
	case 543256677:
		return RECOIL_DecodeEpa(self, content, contentLength);
	case 540173414:
		return RECOIL_DecodeFli(self, content, contentLength);
	case 1768711782:
		return RECOIL_DecodeFfli(self, content, contentLength);
	case 543779942:
		return RECOIL_DecodeFli(self, content, contentLength) || RECOIL_DecodeBml(self, content, contentLength);
	case 544501350:
		return RECOIL_DecodeAtari8Fnt(self, content, contentLength) || RECOIL_DecodeAmstradFnt(self, content, contentLength);
	case 544501862:
		return contentLength == 10004 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8002, 9002, content[10004]);
	case 543388774:
		return RECOIL_DecodeFtc(self, content, contentLength);
	case 544109926:
	case 540176486:
		return RECOIL_DecodeFun(self, content, contentLength);
	case 543258470:
		return RECOIL_DecodeFwa(self, content, contentLength);
	case 538994535:
		return RECOIL_DecodeGg(self, content, contentLength);
	case 543647847:
		return RECOIL_DecodeGhg(self, content, contentLength);
	case 543453031:
		return RECOIL_DecodeGod(self, content, contentLength);
	case 540029287:
		return RECOIL_DecodeG10(self, content, contentLength);
	case 540094823:
		return RECOIL_DecodeG11(self, content, contentLength);
	case 543319655:
		return RECOIL_DecodeGfb(self, content, contentLength);
	case 540504679:
		return RECOIL_DecodeGr7(self, content, 0, contentLength);
	case 540570215:
		return RECOIL_DecodeGr8(self, content, contentLength);
	case 540635751:
		return RECOIL_DecodeGr9(self, content, contentLength);
	case 544109927:
		return RECOIL_DecodeGun(self, content, contentLength);
	case 543450472:
		return RECOIL_DecodeHed(self, content, contentLength);
	case 543385192:
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
	case 544039528:
	case 543713639:
	case 544434022:
	case 544108397:
	case 543449959:
		return RECOIL_DecodeHir(self, content, contentLength);
	case 543583336:
		return RECOIL_DecodeHlf(self, content, contentLength);
	case 544369768:
		return RECOIL_DecodeHlr(self, content, contentLength);
	case 543387752:
		return RECOIL_DecodeIph(self, content, contentLength);
	case 544043112:
		return RECOIL_DecodeHpm(self, content, contentLength);
	case 538997352:
		return RECOIL_DecodeHr(self, content, contentLength);
	case 540177000:
	case 543777640:
		return RECOIL_DecodeHr2(self, content, contentLength);
	case 543515497:
		return contentLength > 2048 && RECOIL_DecodeAtari8Ice(self, content, contentLength, TRUE, content[0]);
	case 544105321:
		return RECOIL_DecodeStIcn(self, content, contentLength) || RECOIL_DecodeAtari8Ice(self, content, contentLength, FALSE, 17);
	case 543581801:
	case 1835164513:
	case 540109922:
	case 540175458:
	case 540240994:
	case 913138024:
	case 946692456:
	case 544039532:
		return RECOIL_DecodeIff(self, content, contentLength);
	case 543975017:
		return RECOIL_DecodeGun(self, content, contentLength) || RECOIL_DecodeZxIfl(self, content, contentLength);
	case 543516521:
		return RECOIL_DecodeIge(self, content, contentLength);
	case 543516777:
		return RECOIL_DecodeIhe(self, content, contentLength);
	case 543649129:
		return RECOIL_DecodeStImg(self, content, contentLength) || RECOIL_DecodeZxImg(self, content, contentLength);
	case 1735223672:
		return RECOIL_DecodeStImg(self, content, contentLength);
	case 544107881:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, FALSE, 18);
	case 1868983913:
		return RECOIL_DecodeInfo(self, content, contentLength);
	case 543649385:
	case 544239209:
		return RECOIL_DecodeInp(self, content, contentLength);
	case 544501353:
		return RECOIL_DecodeInt(self, content, contentLength) || RECOIL_DecodeInp(self, content, contentLength);
	case 540176489:
		return RECOIL_DecodeIp2(self, content, contentLength);
	case 543387753:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, FALSE, 19);
	case 544501865:
		return contentLength == 10003 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8002, 9002, content[10002]);
	case 540177001:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, FALSE, 2);
	case 543650409:
		return RECOIL_DecodeAtari8Ice(self, content, contentLength, FALSE, 1);
	case 544043881:
		return contentLength == 10218 && RECOIL_DecodeC64Multicolor(self, 320, content, 1026, 9218, 2, content[9217]);
	case 544502633:
		return RECOIL_DecodeIst(self, content, contentLength);
	case 544237418:
		return RECOIL_DecodeJgp(self, content, contentLength);
	case 538995306:
		return RECOIL_DecodeJj(self, content, contentLength);
	case 543256427:
	case 543648103:
	case 544043122:
		return RECOIL_DecodeKoa(self, content, contentLength);
	case 544171372:
		return RECOIL_DecodeLeo(self, content, contentLength);
	case 540242028:
		return RECOIL_DecodeLp3(self, content, contentLength);
	case 544044396:
		return RECOIL_DecodeLum(self, content, contentLength);
	case 543383917:
		return RECOIL_DecodeMac(self, content, contentLength);
	case 544760173:
		return RECOIL_DecodeMax(self, content, contentLength);
	case 543646317:
		return RECOIL_DecodeMbg(self, content, contentLength);
	case 538993517:
		return RECOIL_DecodeMc(self, content, contentLength);
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
	case 540108653:
	case 540174189:
	case 540305261:
	case 540567405:
		return RECOIL_DecodeMg(self, content, contentLength);
	case 544237421:
		return RECOIL_DecodeMgp(self, content, contentLength);
	case 543385965:
		return RECOIL_DecodeMic(self, content, contentLength);
	case 543975789:
		return contentLength == 10022 && RECOIL_DecodeC64Multicolor(self, 320, content, 2022, 22, 1022, 0);
	case 544434541:
		return RECOIL_DecodeMis(self, content, contentLength);
	case 543517805:
		return RECOIL_DecodeMle(self, content, contentLength);
	case 544239725:
		return RECOIL_DecodeMpp(self, content, contentLength);
	case 544240493:
		return RECOIL_DecodeMsp(self, content, contentLength);
	case 544171374:
		return RECOIL_DecodeNeo(self, content, contentLength);
	case 544304238:
		return RECOIL_DecodeNlq(self, content, contentLength);
	case 544236399:
		return RECOIL_DecodeOcp(self, content, contentLength);
	case 538976368:
		return RECOIL_DecodeP(self, content, contentLength);
	case 543765616:
		return RECOIL_DecodeP4i(self, content, contentLength);
	case 540292720:
		return contentLength == 10050 && RECOIL_DecodeC64Multicolor(self, 320, content, 2050, 1026, 2, content[2049]);
	case 543383920:
		return RECOIL_DecodePac(self, content, contentLength);
	case 540107632:
	case 540173168:
	case 540238704:
		return RECOIL_DecodePc(self, content, contentLength);
	case 544433008:
		return RECOIL_DecodePcs(self, content, contentLength);
	case 543385456:
		return RECOIL_DecodePgc(self, content, contentLength);
	case 543582064:
		return RECOIL_DecodePgf(self, content, contentLength);
	case 538995056:
		return contentLength == 10242 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8194, 9218, content[8066]);
	case 540109168:
	case 540174704:
	case 540240240:
		return RECOIL_DecodeStPi(self, content, contentLength);
	case 540305776:
	case 540633456:
		return RECOIL_DecodePi4(self, content, contentLength);
	case 543385968:
		return RECOIL_DecodePic(self, content, contentLength);
	case 540306544:
		return RECOIL_DecodePl4(self, content, contentLength);
	case 543255664:
		return RECOIL_DecodePla(self, content, contentLength);
	case 544042096:
		return RECOIL_DecodeApc(self, content, contentLength);
	case 543452528:
		return RECOIL_DecodePmd(self, content, contentLength);
	case 543649136:
		return RECOIL_DecodePmg(self, content, contentLength);
	case 544694642:
		return RECOIL_DecodeRaw(self, content, contentLength);
	case 543319922:
		return RECOIL_DecodeAtari8Rgb(self, content, contentLength) || RECOIL_DecodeZxRgb(self, content, contentLength);
	case 544237938:
		return RECOIL_DecodeRip(self, content, contentLength);
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
		return contentLength == 10242 && RECOIL_DecodeC64Multicolor(self, 320, content, 1026, 2, 9218, 0);
	case 544438642:
		return RECOIL_DecodeRys(self, content, contentLength);
	case 544366963:
		return contentLength == 10018 && RECOIL_DecodeC64Multicolor(self, 320, content, 1026, 2, 9218, content[1010]);
	case 540173171:
	case 544240231:
		return RECOIL_DecodeSc2(self, content, contentLength);
	case 540566387:
		return RECOIL_DecodeSc8(self, content, contentLength);
	case 543253363:
		return RECOIL_DecodeSca(self, content, contentLength);
	case 543384435:
	case 544436851:
		return RECOIL_DecodeScc(self, content, contentLength);
	case 544367475:
		return RECOIL_DecodeScr(self, content, contentLength);
	case 879977331:
		return RECOIL_DecodeScs4(self, content, contentLength);
	case 543516531:
		return RECOIL_DecodeSge(self, content, contentLength);
	case 543385715:
		return RECOIL_DecodeShc(self, content, contentLength);
	case 544237683:
		return RECOIL_DecodeShp(self, content, contentLength);
	case 544368755:
		return RECOIL_DecodeShr(self, content, contentLength);
	case 543582579:
		return RECOIL_DecodeSif(self, content, contentLength);
	case 543387763:
		return RECOIL_DecodeStSpc(self, content, contentLength) || RECOIL_DecodeAtari8Spc(self, content, contentLength);
	case 544436339:
		return RECOIL_DecodeSps(self, content, contentLength);
	case 544567411:
		return RECOIL_DecodeSpu(self, content, contentLength);
	case 540570227:
		return RECOIL_DecodeSr8(self, content, contentLength);
	case 544438387:
		return RECOIL_DecodeSxs(self, content, contentLength);
	case 544237940:
		return RECOIL_DecodeTip(self, content, contentLength);
	case 540110452:
	case 540175988:
	case 540241524:
	case 544829044:
		return RECOIL_DecodeTny(self, content, contentLength);
	case 544240244:
		return RECOIL_DecodeTrp(self, content, contentLength);
	case 544567924:
		return RECOIL_DecodeTru(self, content, contentLength);
	case 543385974:
		return RECOIL_DecodeVic(self, content, contentLength);
	case 543783542:
		return RECOIL_DecodeVzi(self, content, contentLength);
	case 543452791:
		return RECOIL_DecodeWnd(self, content, contentLength);
	case 544238712:
		return RECOIL_DecodeXlp(self, content, contentLength);
	case 544241786:
		return RECOIL_DecodeZxp(self, content, contentLength);
	default:
		return FALSE;
	}
}

static cibool RECOIL_Decode256(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if (contentLength != 7680 && contentLength != 7684)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 3840, 40, frame, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 0, 40, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_Decode3(RECOIL *self, unsigned char const *content, int contentLength)
{
	static const unsigned char frameComponents[3] = { 0, 16, 8 };
	return RECOIL_DecodeZxRgb3(self, content, contentLength, frameComponents);
}

static cibool RECOIL_Decode4bt(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[32000];
	GoDotStream rle;
	if (contentLength < 5 || !RECOIL_IsStringAt(content, 0, "GOD0") || content[contentLength - 1] != 173)
		return FALSE;
	GoDotStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 4;
	rle.base.base.base.contentLength = contentLength - 1;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 32000))
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	{
		int y;
		for (y = 0; y < 200; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					static const unsigned char byBrightness[16] = { 0, 6, 9, 11, 2, 4, 8, 12, 14, 10, 5, 15, 3, 7, 13, 1 };
					int c = unpacked[(y & ~7) * 160 + (((x & ~7) + (y & 7)) << 2) + ((x >> 1) & 3)];
					self->pixels[y * 320 + x] = RECOIL_C64Palette[byBrightness[(x & 1) == 0 ? c >> 4 : c & 15]];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_Decode4mi(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[7680];
	if (contentLength != 244)
		return FALSE;
	RECOIL_SetSize(self, 32, 240, RECOILResolution_XE2X1);
	memset(frame, 0, sizeof(frame));
	RECOIL_DecodeAt800Missiles(self, content, 4, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_Decode4pl(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[19200];
	if (contentLength != 964)
		return FALSE;
	RECOIL_SetSize(self, 80, 240, RECOILResolution_XE2X1);
	memset(frame, 0, sizeof(frame));
	RECOIL_DecodeAt800Players(self, content, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_Decode4pm(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[26880];
	if (contentLength != 1204)
		return FALSE;
	RECOIL_SetSize(self, 112, 240, RECOILResolution_XE2X1);
	memset(frame, 0, sizeof(frame));
	RECOIL_DecodeAt800Players(self, content, frame);
	RECOIL_DecodeAt800Missiles(self, content, 964, frame, 80);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_Decode64c(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength < 10 || contentLength > 2050 || content[0] != 0)
		return FALSE;
	RECOIL_SetSize(self, 256, (contentLength + 253) >> 8 << 3, RECOILResolution_C641X1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, 2, contentLength);
	return TRUE;
}

static cibool RECOIL_DecodeA4r(RECOIL *self, unsigned char const *content, int contentLength)
{
	A4rStream a4r;
	unsigned char frame[81920];
	A4rStream_Construct(&a4r);
	a4r.base.content = content;
	a4r.base.contentOffset = 0;
	a4r.base.contentLength = contentLength;
	if (!A4rStream_UnpackA4r(&a4r))
		return FALSE;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_XE4X1);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, a4r.unpacked, 512, 40, frame, 0, 320, 320, 256);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeAcs(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char characters[16];
	unsigned char frame[8192];
	if (contentLength != 1028)
		return FALSE;
	{
		int i;
		for (i = 0; i < 16; i++)
			characters[i] = i;
	}
	RECOIL_SetBakPF012(self, content, 0, 1);
	RECOIL_SetSize(self, 128, 64, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 8; y++)
			RECOIL_DecodeAtari8Gr12Line(self, characters, 0, content, 4 + (y << 7), frame, y << 10);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeAfl(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 16385)
		return FALSE;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 8218, 5, 0);
	return TRUE;
}

static cibool RECOIL_DecodeAgp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if (contentLength != 7690)
		return FALSE;
	RECOIL_SetGtiaColors(self, content, 1);
	switch (content[0]) {
	case 8:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1);
		RECOIL_DecodeAtari8Gr8(self, content, 10, frame, 0, 192);
		break;
	case 9:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1);
		RECOIL_DecodeAtari8Gr9(self, content, 10, 40, frame, 0, 320, 320, 192);
		break;
	case 10:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1);
		self->leftSkip = 2;
		RECOIL_DecodeAtari8Gr10(self, content, 10, frame, 0, 320, 192);
		break;
	case 11:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1);
		RECOIL_DecodeAtari8Gr11(self, content, 10, frame, 0, 320, 192);
		break;
	case 15:
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
		RECOIL_DecodeAtari8Gr15(self, content, 10, 40, frame, 0, 320, 192);
		break;
	default:
		return FALSE;
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeAll(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if ((contentLength & 1023) != 989)
		return FALSE;
	RECOIL_SetPF0123Bak(self, content, contentLength - 5);
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 24; y++) {
			int fontOffset = 24 + (content[y] << 10);
			if (fontOffset >= contentLength - 965)
				return FALSE;
			RECOIL_DecodeAtari8Gr12Line(self, content, contentLength - 965 + y * 40, content, fontOffset, frame, y * 2560);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeAmi(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[10259];
	DrpStream rle;
	if (contentLength < 2)
		return FALSE;
	DrpStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = 194;
	return RleStream_UnpackC64(&rle.base, unpacked, 10259) && RECOIL_DecodeKoa(self, unpacked, 10003);
}

static cibool RECOIL_DecodeAmstradFnt(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	if (contentLength < contentOffset + 768)
		return FALSE;
	RECOIL_SetSize(self, 256, 24, RECOILResolution_AMSTRAD1X1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, contentOffset, contentLength);
	return TRUE;
}

static cibool RECOIL_DecodeAmstradMode2(RECOIL *self, unsigned char const *content, int contentOffset, int width, int height)
{
	RECOIL_SetSize(self, width, height << 1, RECOILResolution_AMSTRAD1X2);
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < width; x++) {
					int offset = (y * width << 1) + x;
					int c = (content[contentOffset + ((y & 7) << 11) + (((y >> 3) * width + x) >> 3)] >> (~x & 7)) & 1;
					if (c != 0)
						c = 16777215;
					self->pixels[offset + width] = self->pixels[offset] = c;
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeAmstradScr(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	AmstradStream rle;
	unsigned char unpacked[16384];
	if (contentLength == contentOffset + 16384)
		return RECOIL_DecodeAmstradMode2(self, content, contentOffset, 640, 200);
	AmstradStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset;
	rle.base.base.base.contentLength = contentLength;
	rle.blockLength = 0;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 16384))
		return FALSE;
	return RECOIL_DecodeAmstradMode2(self, unpacked, 0, 640, 200);
}

static cibool RECOIL_DecodeAp3(RECOIL *self, unsigned char const *content, int contentLength)
{
	int gr11Offset;
	unsigned char frame1[61440];
	unsigned char frame2[61440];
	switch (contentLength) {
	case 15360:
	case 15362:
		gr11Offset = 7680;
		break;
	case 15872:
		gr11Offset = 8192;
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X1);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 0, 80, frame1, 0, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, gr11Offset + 40, 80, frame1, 1);
	RECOIL_DecodeAtari8Gr9(self, content, 40, 80, frame2, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, gr11Offset, 80, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeApc(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if (contentLength != 7680 && contentLength != 7720)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 40, 80, frame, 320, 640, 320, 96);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 0, 80, frame, 0);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeApl(RECOIL *self, unsigned char const *content, int contentLength)
{
	int frames;
	int height;
	int gap;
	int frameWidth;
	unsigned char frame[27648];
	if (contentLength != 1677 || content[0] != 154 || content[1] != 248 || content[2] != 57 || content[3] != 33)
		return FALSE;
	frames = content[4];
	height = content[5];
	gap = content[6];
	if (frames == 0 || frames > 16 || height == 0 || height > 48 || gap > 8)
		return FALSE;
	frameWidth = (8 + gap + 2) << 1;
	RECOIL_SetSize(self, frames * frameWidth, height, RECOILResolution_XE2X1);
	memset(frame, 0, sizeof(frame));
	{
		int f;
		for (f = 0; f < frames; f++) {
			RECOIL_DecodeAtari8Player(self, content, 42 + f * 48, content[7 + f], frame, f * frameWidth, height);
			RECOIL_DecodeAtari8Player(self, content, 858 + f * 48, content[24 + f], frame, f * frameWidth + gap * 2, height);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeApp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[15872];
	int unpackedOffset;
	BitStream bitStream;
	int current;
	int hi;
	if (contentLength < 7958 || !RECOIL_IsStringAt(content, 0, "S101") || content[4] != 0 || content[5] != 62)
		return FALSE;
	unpackedOffset = 0;
	BitStream_Construct(&bitStream);
	bitStream.base.content = content;
	bitStream.base.contentOffset = 22;
	bitStream.base.contentLength = contentLength;
	current = BitStream_ReadBits(&bitStream, 4);
	hi = -1;
	for (;;) {
		int code;
		int bit;
		if (hi < 0)
			hi = current;
		else {
			unpacked[unpackedOffset++] = (hi << 4) | current;
			if (unpackedOffset >= 15872)
				break;
			hi = -1;
		}
		for (code = 0;; code += 2) {
			bit = BitStream_ReadBit(&bitStream);
			if (bit == 0)
				break;
			if (bit < 0 || code >= 14)
				return FALSE;
		}
		bit = BitStream_ReadBit(&bitStream);
		if (bit < 0)
			return FALSE;
		code += bit;
		current = (current - content[6 + code]) & 15;
	}
	return RECOIL_DecodeAp3(self, unpacked, 15872);
}

static cibool RECOIL_DecodeArtDirector(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 32512)
		return FALSE;
	return RECOIL_DecodeStLow(self, content, 0, content, 32000, 320, 200);
}

static cibool RECOIL_DecodeAsciiArtEditor(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char characters[1536];
	int columns;
	int x;
	int y;
	unsigned char frame[98304];
	if (contentLength <= 0 || content[contentLength - 1] != 155)
		return FALSE;
	columns = 1;
	x = 0;
	y = 0;
	{
		int contentOffset;
		for (contentOffset = 0; contentOffset < contentLength; contentOffset++) {
			int ch = content[contentOffset];
			if (y >= 24)
				return FALSE;
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
					return FALSE;
				characters[y * 64 + x++] = RECOIL_ToAtari8Char(ch);
			}
		}
	}
	RECOIL_SetSize(self, columns << 3, y << 3, RECOILResolution_XE1X1);
	RECOIL_DecodeAtari8Gr0(self, characters, 64, CiBinaryResource_atari8_fnt, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static void RECOIL_DecodeAt800Missiles(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset)
{
	{
		int y;
		for (y = 0; y < 240; y++) {
			{
				int i;
				for (i = 0; i < 4; i++) {
					int b = content[contentOffset + y] >> (i << 1);
					int offset = frameOffset + i * 4 * 2;
					frame[offset + 1] = frame[offset] = (b & 2) == 0 ? 0 : content[i];
					frame[offset + 3] = frame[offset + 2] = (b & 1) == 0 ? 0 : content[i];
				}
			}
			frameOffset += self->width;
		}
	}
}

static void RECOIL_DecodeAt800Players(RECOIL const *self, unsigned char const *content, unsigned char *frame)
{
	{
		int i;
		for (i = 0; i < 4; i++)
			RECOIL_DecodeAtari8Player(self, content, 4 + i * 240, content[i], frame, i * 10 * 2, 240);
	}
}

static cibool RECOIL_DecodeAtari8Artist(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[51200];
	if (contentLength != 3206 || content[0] != 7)
		return FALSE;
	RECOIL_SetSize(self, 320, 160, RECOILResolution_XE2X2);
	RECOIL_SetPF0123Bak(self, content, 1);
	RECOIL_DecodeAtari8Gr7(self, content, 6, frame, 0, 80);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeAtari8Fnt(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	unsigned char characters[128];
	switch (contentLength) {
	case 1024:
	case 1025:
	case 1026:
		contentOffset = 0;
		break;
	case 1030:
		if (RECOIL_ParseAtari8ExecutableHeader(content, 0) != 1024)
			return FALSE;
		contentOffset = 6;
		break;
	default:
		return FALSE;
	}
	{
		int i;
		for (i = 0; i < 128; i++)
			characters[i] = i;
	}
	return RECOIL_DecodeAtari8Font(self, characters, content, contentOffset);
}

static cibool RECOIL_DecodeAtari8Font(RECOIL *self, unsigned char const *characters, unsigned char const *font, int fontOffset)
{
	unsigned char frame[8192];
	RECOIL_SetSize(self, 256, 32, RECOILResolution_XE1X1);
	RECOIL_DecodeAtari8Gr0(self, characters, 32, font, fontOffset, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static void RECOIL_DecodeAtari8Gr0(RECOIL const *self, unsigned char const *characters, int charactersStride, unsigned char const *font, int fontOffset, unsigned char *frame)
{
	{
		int y;
		for (y = 0; y < self->height; y++) {
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int ch = characters[(y >> 3) * charactersStride + (x >> 3)];
					int b = font[fontOffset + ((ch & 127) << 3) + (y & 7)];
					if (ch >= 128)
						b ^= 255;
					frame[y * self->width + x] = ((b >> (~x & 7)) & 1) == 0 ? 0 : 14;
				}
			}
		}
	}
}

static void RECOIL_DecodeAtari8Gr10(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int frameStride, int height)
{
	frameOffset += 2 - self->leftSkip;
	{
		int y;
		for (y = 0; y < height; y++) {
			int x;
			for (x = self->leftSkip - 2; x < 0; x++)
				frame[frameOffset + x] = self->gtiaColors[0];
			for (; x < self->width + self->leftSkip - 2; x++) {
				int c = (content[contentOffset + (x >> 3)] >> (~x & 4)) & 15;
				frame[frameOffset + x] = self->gtiaColors[c];
			}
			contentOffset += self->width >> 3;
			frameOffset += frameStride;
		}
	}
}

static void RECOIL_DecodeAtari8Gr11(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int frameStride, int height)
{
	frameOffset -= self->leftSkip;
	{
		int y;
		for (y = 0; y < height; y++) {
			int x;
			for (x = self->leftSkip; x < self->width; x++) {
				int c = (content[contentOffset + (x >> 3)] << (x & 4)) & 240;
				c = c == 0 ? self->gtiaColors[8] & 240 : self->gtiaColors[8] | c;
				frame[frameOffset + x] = c;
			}
			for (; x < self->width + self->leftSkip; x++)
				frame[frameOffset + x] = self->gtiaColors[8] & 240;
			contentOffset += self->width >> 3;
			frameOffset += frameStride;
		}
	}
}

static void RECOIL_DecodeAtari8Gr11PalBlend(RECOIL const *self, unsigned char const *content, int contentOffset, int contentStride, unsigned char *frame, int y)
{
	for (; y < self->height; y += 2) {
		int frameOffset = y * self->width - self->leftSkip;
		int x;
		for (x = self->leftSkip; x < self->width; x++) {
			int c = (content[contentOffset + (x >> 3)] << (x & 4)) & 240;
			int i = ((y == 0 ? 0 : frame[frameOffset - self->width + x] & 15) + (y == self->height - 1 ? 0 : frame[frameOffset + self->width + x] & 15)) >> 1;
			frame[frameOffset + x] = c | i;
			if (y < self->height - 1)
				frame[frameOffset + self->width + x] = c | (frame[frameOffset + self->width + x] & 15);
		}
		for (; x < self->width + self->leftSkip; x++)
			frame[frameOffset + x] = 0;
		contentOffset += contentStride;
	}
}

static void RECOIL_DecodeAtari8Gr12Line(RECOIL const *self, unsigned char const *characters, int charactersOffset, unsigned char const *font, int fontOffset, unsigned char *frame, int frameOffset)
{
	{
		int y;
		for (y = 0; y < 8; y++) {
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int ch = characters[charactersOffset + (x >> 3)];
					int c = (font[fontOffset + ((ch & 127) << 3) + y] >> (~x & 6)) & 3;
					int gr12Registers = ch >= 128 ? 30024 : 25928;
					frame[frameOffset + x] = self->gtiaColors[(gr12Registers >> (c << 2)) & 15];
				}
			}
			frameOffset += self->width;
		}
	}
}

static void RECOIL_DecodeAtari8Gr15(RECOIL const *self, unsigned char const *content, int contentOffset, int contentStride, unsigned char *frame, int frameOffset, int frameStride, int height)
{
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int c = (content[contentOffset + (x >> 3)] >> (~x & 6)) & 3;
					frame[frameOffset + x] = self->gtiaColors[c == 0 ? 8 : c + 3];
				}
			}
			contentOffset += contentStride;
			frameOffset += frameStride;
		}
	}
}

static void RECOIL_DecodeAtari8Gr7(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int height)
{
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int c = (content[contentOffset + (x >> 3)] >> (~x & 6)) & 3;
					frame[frameOffset + x + self->width] = frame[frameOffset + x] = self->gtiaColors[c == 0 ? 8 : c + 3];
				}
			}
			contentOffset += self->width >> 3;
			frameOffset += self->width << 1;
		}
	}
}

static void RECOIL_DecodeAtari8Gr8(RECOIL const *self, unsigned char const *content, int contentOffset, unsigned char *frame, int frameOffset, int height)
{
	unsigned char colors[2];
	colors[0] = self->gtiaColors[6];
	colors[1] = (self->gtiaColors[6] & 240) | (self->gtiaColors[5] & 14);
	frameOffset -= self->leftSkip;
	{
		int y;
		for (y = 0; y < height; y++) {
			int x;
			for (x = self->leftSkip; x < self->width; x++) {
				int c = (content[contentOffset + (x >> 3)] >> (~x & 7)) & 1;
				frame[frameOffset + x] = colors[c];
			}
			for (; x < self->width + self->leftSkip; x++)
				frame[frameOffset + x] = self->gtiaColors[8];
			contentOffset += self->width >> 3;
			frameOffset += self->width;
		}
	}
}

static void RECOIL_DecodeAtari8Gr9(RECOIL const *self, unsigned char const *content, int contentOffset, int contentStride, unsigned char *frame, int frameOffset, int frameStride, int width, int height)
{
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < width; x++) {
					int i = x + self->leftSkip;
					int c = i < 0 || i >= width ? 0 : (content[contentOffset + (i >> 3)] >> (~i & 4)) & 15;
					frame[frameOffset + x] = self->gtiaColors[8] | c;
				}
			}
			contentOffset += contentStride;
			frameOffset += frameStride;
		}
	}
}

static cibool RECOIL_DecodeAtari8Ice(RECOIL *self, unsigned char const *content, int contentLength, cibool font, int mode)
{
	unsigned char frame1[61440];
	unsigned char frame2[61440];
	switch (mode) {
	case 0:
		if (contentLength != 2053)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1);
		self->gtiaColors[5] = content[1] & 254;
		self->gtiaColors[6] = content[3] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 5, frame1, IceFrameMode_GR0);
		self->gtiaColors[5] = content[2] & 254;
		self->gtiaColors[6] = content[4] & 254;
		RECOIL_DecodeIceFrame(self, content, -2, 1029, frame2, IceFrameMode_GR0);
		break;
	case 1:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2054, 18310, RECOILResolution_XE2X1))
			return FALSE;
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16390, 6, frame1, IceFrameMode_GR12);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 17350, 1030, frame2, IceFrameMode_GR12);
		break;
	case 2:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2058, 18314, RECOILResolution_XE2X1))
			return FALSE;
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_SetPF0123Even(self, content, 2);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16394, 10, frame1, IceFrameMode_GR12);
		RECOIL_SetPF0123Even(self, content, 3);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 17354, 1034, frame2, IceFrameMode_GR12);
		break;
	case 3:
		if (font) {
			if (contentLength != 2055)
				return FALSE;
			RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1);
		}
		else {
			if (contentLength != 17351 || content[0] != 3)
				return FALSE;
			RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1);
		}
		RECOIL_SetPF21(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16391, 7, frame1, IceFrameMode_GR0);
		RECOIL_SetBakPF0123(self, content, 2);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16391, 1031, frame2, IceFrameMode_GR12);
		break;
	case 4:
		if (contentLength != 2058)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR0_GTIA10);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 5:
		if (contentLength != 2065 && contentLength != 2066)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1);
		self->leftSkip = 2;
		self->gtiaColors[0] = content[1] & 254;
		{
			int i;
			for (i = 0; i < 8; i++)
				RECOIL_SetGtiaColor(self, i + 1, content[2 + i * 2]);
		}
		if (contentLength == 2065) {
			RECOIL_DecodeIceFrame(self, content, -1, 17, frame1, IceFrameMode_GR0_GTIA10);
			{
				int i;
				for (i = 0; i < 7; i++)
					RECOIL_SetGtiaColor(self, i + 1, content[3 + i * 2]);
			}
			RECOIL_DecodeIceFrame(self, content, -2, 1041, frame2, IceFrameMode_GR0_GTIA10);
		}
		else {
			RECOIL_DecodeIceFrame(self, content, -1, 18, frame1, IceFrameMode_GR0_GTIA10);
			{
				int i;
				for (i = 0; i < 8; i++)
					RECOIL_SetGtiaColor(self, i + 1, content[3 + i * 2]);
			}
			RECOIL_DecodeIceFrame(self, content, -2, 1042, frame2, IceFrameMode_GR0_GTIA10);
		}
		break;
	case 6:
		if (contentLength != 2051)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0_GTIA9);
		self->gtiaColors[8] = content[2] & 254;
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA9);
		break;
	case 7:
		if (contentLength != 2051)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0_GTIA11);
		self->gtiaColors[8] = content[2] & 254;
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA11);
		break;
	case 8:
		if (contentLength != 2058)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1);
		self->leftSkip = 1;
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR0_GTIA9);
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 9:
		if (contentLength != 2058)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1);
		self->leftSkip = 1;
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR0_GTIA11);
		self->gtiaColors[0] = 0;
		RECOIL_SetPM123PF0123Bak(self, content, 2);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 10:
		if (contentLength != 2051)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE4X1);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0_GTIA9);
		self->gtiaColors[8] = content[2] & 254;
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA11);
		break;
	case 11:
		if (contentLength != 2051)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1);
		self->gtiaColors[6] = 0;
		self->gtiaColors[5] = content[2] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA11);
		break;
	case 12:
		if (contentLength != 2051)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1);
		RECOIL_SetPF21(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 3, frame1, IceFrameMode_GR0);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -2, 1027, frame2, IceFrameMode_GR0_GTIA9);
		break;
	case 13:
		if (contentLength != 2059)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE1X1);
		RECOIL_SetPF21(self, content, 1);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 11, frame1, IceFrameMode_GR0);
		self->leftSkip = 2;
		self->gtiaColors[0] = content[1] & 254;
		RECOIL_SetPM123PF0123Bak(self, content, 3);
		RECOIL_DecodeIceFrame(self, content, -2, 1035, frame2, IceFrameMode_GR0_GTIA10);
		break;
	case 14:
		if (contentLength != 2054)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1);
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1030, frame2, IceFrameMode_GR12_GTIA11);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeIceFrame(self, content, -1, 6, frame1, IceFrameMode_GR12);
		break;
	case 15:
		if (contentLength != 2054)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1);
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -1, 6, frame1, IceFrameMode_GR12);
		RECOIL_DecodeIceFrame(self, content, -2, 1030, frame2, IceFrameMode_GR12_GTIA9);
		break;
	case 16:
		if (contentLength != 2058)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, RECOILResolution_XE2X1);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, -2, 1034, frame2, IceFrameMode_GR12_GTIA10);
		self->leftSkip = 0;
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, -1, 10, frame1, IceFrameMode_GR12);
		break;
	case 17:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2054, 17350, RECOILResolution_XE2X1))
			return FALSE;
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16390, 1030, frame2, IceFrameMode_GR0_GTIA11);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16390, 6, frame1, IceFrameMode_GR12);
		break;
	case 18:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2054, 17350, RECOILResolution_XE2X1))
			return FALSE;
		RECOIL_SetBakPF0123(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16390, 6, frame1, IceFrameMode_GR12);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16390, 1030, frame2, IceFrameMode_GR0_GTIA9);
		break;
	case 19:
		if (!RECOIL_VerifyIce(self, content, contentLength, font, 2058, 17354, RECOILResolution_XE2X1))
			return FALSE;
		RECOIL_SetPF0123Bak(self, content, 5);
		self->gtiaColors[8] = content[1] & 254;
		RECOIL_DecodeIceFrame(self, content, font ? -1 : 16394, 10, frame1, IceFrameMode_GR12);
		self->leftSkip = 2;
		RECOIL_SetGtiaColors(self, content, 1);
		RECOIL_DecodeIceFrame(self, content, font ? -2 : 16394, 1034, frame2, IceFrameMode_GR0_GTIA10);
		break;
	default:
		return FALSE;
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static void RECOIL_DecodeAtari8Player(RECOIL const *self, unsigned char const *content, int contentOffset, int color, unsigned char *frame, int frameOffset, int height)
{
	color &= 254;
	{
		int y;
		for (y = 0; y < height; y++) {
			int b = content[contentOffset + y];
			{
				int x;
				for (x = 0; x < 8; x++) {
					int c = (b >> (7 - x)) & 1;
					if (c != 0)
						frame[frameOffset + x * 2 + 1] = frame[frameOffset + x * 2] |= color;
				}
			}
			frameOffset += self->width;
		}
	}
}

static cibool RECOIL_DecodeAtari8Rgb(RECOIL *self, unsigned char const *content, int contentLength)
{
	int titleLength;
	int width;
	int height;
	int leftRgbs[192];
	unsigned char screens[23040];
	RgbStream rle;
	unsigned char frame1[61440];
	unsigned char frame2[61440];
	unsigned char frame3[61440];
	if (contentLength < 9 || !RECOIL_IsStringAt(content, 0, "RGB1"))
		return FALSE;
	titleLength = content[4];
	width = content[6 + titleLength];
	height = content[7 + titleLength];
	if (width == 0 || (width & 1) != 0 || width > 80 || height == 0 || height > 192 || content[8 + titleLength] != 1)
		return FALSE;
	switch (content[5 + titleLength]) {
	case 9:
		RECOIL_SetSize(self, width << 2, height, RECOILResolution_XE4X1);
		break;
	case 15:
		RECOIL_SetSize(self, width << 2, height, RECOILResolution_XE2X1);
		break;
	default:
		return FALSE;
	}
	RgbStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 9 + titleLength;
	rle.base.base.base.contentLength = contentLength;
	{
		int x;
		for (x = 0; x < width; x++) {
			{
				int y;
				for (y = 0; y < height; y++) {
					int rgb = RleStream_ReadRle(&rle.base);
					if (rgb < 0)
						return FALSE;
					if ((x & 1) == 0)
						leftRgbs[y] = rgb;
					else {
						int leftRgb = leftRgbs[y];
						int screenOffset = y * 40 + (x >> 1);
						screens[screenOffset] = ((leftRgb >> 4) & 240) | (rgb >> 8);
						screens[7680 + screenOffset] = (leftRgb & 240) | ((rgb >> 4) & 15);
						screens[15360 + screenOffset] = ((leftRgb << 4) & 240) | (rgb & 15);
					}
				}
			}
		}
	}
	RECOIL_DecodeAtari8RgbScreen(self, screens, 0, 48, frame1);
	RECOIL_DecodeAtari8RgbScreen(self, screens, 7680, 192, frame2);
	RECOIL_DecodeAtari8RgbScreen(self, screens, 15360, 112, frame3);
	return RECOIL_ApplyAtari8PaletteBlend3(self, frame1, frame2, frame3);
}

static void RECOIL_DecodeAtari8RgbScreen(RECOIL *self, unsigned char const *screens, int screensOffset, int color, unsigned char *frame)
{
	if (self->resolution == RECOILResolution_XE4X1) {
		self->gtiaColors[8] = color;
		RECOIL_DecodeAtari8Gr9(self, screens, screensOffset, 40, frame, 0, self->width, self->width, self->height);
	}
	else {
		self->gtiaColors[8] = 0;
		self->gtiaColors[4] = color | 4;
		self->gtiaColors[5] = color | 10;
		self->gtiaColors[6] = color | 14;
		RECOIL_DecodeAtari8Gr15(self, screens, screensOffset, 40, frame, 0, self->width, self->height);
	}
}

static cibool RECOIL_DecodeAtari8Spc(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char pixels[30720];
	int lineColors[96];
	int textX;
	int textY;
	int lineX;
	int lineY;
	int brush;
	int pattern;
	int lineColor;
	int x;
	int y;
	unsigned char frame[61440];
	if (contentLength < 3 || contentLength != content[0] + (content[1] << 8) + 3 || content[contentLength - 1] != 0)
		return FALSE;
	memset(pixels, 0, sizeof(pixels));
	memset(lineColors, 0, sizeof(lineColors));
	textX = 0;
	textY = 0;
	lineX = 0;
	lineY = 0;
	brush = 0;
	pattern = 8840;
	lineColor = 3;
	{
		int contentOffset;
		for (contentOffset = 2; content[contentOffset] != 0;) {
			switch (content[contentOffset]) {
				static const int patterns[71] = { 0, 21845, 43690, 65535, 4420, 8840, 13260, 26265, 30685, 48110, 5457, 10914, 16371, 16388, 27302, 32759,
					32776, 38233, 49147, 49164, 54621, 60078, 21896, 8908, 13124, 17561, 17629, 30617, 35054, 34918, 39406, 52343,
					52411, 56763, 7089, 5465, 5469, 38237, 16392, 16396, 32780, 27308, 10926, 27298, 32763, 16379, 49143, 21892,
					8900, 13128, 17553, 17617, 30609, 35042, 34914, 39393, 52339, 52403, 56755, 21900, 8904, 13132, 17565, 17625,
					30621, 35046, 34926, 39397, 52347, 52407, 56759 };
			case 16:
				if (contentOffset + 3 >= contentLength)
					return FALSE;
				textX = content[contentOffset + 1];
				textY = content[contentOffset + 2];
				contentOffset += 3;
				break;
			case 32:
			case 33:
			case 34:
			case 35:
				if (contentOffset + 1 >= contentLength)
					return FALSE;
				lineColor = content[contentOffset] & 3;
				contentOffset++;
				break;
			case 48:
			case 80:
				if (contentOffset + 2 >= contentLength)
					return FALSE;
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
					return FALSE;
				brush = content[contentOffset] & 7;
				contentOffset++;
				break;
			case 96:
				if (contentOffset + 2 >= contentLength)
					return FALSE;
				pattern = content[contentOffset + 1];
				if (pattern >= 71)
					return FALSE;
				pattern = patterns[pattern];
				contentOffset += 2;
				break;
			case 112:
				if (contentOffset + 7 >= contentLength)
					return FALSE;
				for (y = content[contentOffset + 1]; y <= content[contentOffset + 2]; y++) {
					if (y >= 96)
						return FALSE;
					lineColors[y] = contentOffset + 3;
				}
				contentOffset += 7;
				break;
			case 128:
				if (contentOffset + 3 >= contentLength)
					return FALSE;
				lineX = content[contentOffset + 1];
				lineY = content[contentOffset + 2];
				contentOffset += 3;
				break;
			case 160:
				if (contentOffset + 3 >= contentLength)
					return FALSE;
				x = content[contentOffset + 1];
				y = content[contentOffset + 2];
				RECOIL_DrawSpcLine(pixels, lineX, lineY, x, y, lineColor);
				lineX = x;
				lineY = y;
				contentOffset += 3;
				break;
			case 192:
				if (contentOffset + 3 >= contentLength)
					return FALSE;
				RECOIL_DrawSpcBrush(pixels, content[contentOffset + 1], content[contentOffset + 2], brush, pattern);
				contentOffset += 3;
				break;
			case 224:
				if (contentOffset + 3 >= contentLength)
					return FALSE;
				if (!RECOIL_FillSpc(pixels, content[contentOffset + 1], content[contentOffset + 2], pattern))
					return FALSE;
				contentOffset += 3;
				break;
			default:
				return FALSE;
			}
		}
	}
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
	for (y = 0; y < 192; y++) {
		static const unsigned char defaultColors[4] = { 0, 21, 149, 54 };
		int colorsOffset = lineColors[y >> 1];
		unsigned char const *colors = colorsOffset == 0 ? defaultColors : content;
		for (x = 0; x < 160; x++) {
			int offset = y * 320 + x * 2;
			frame[offset + 1] = frame[offset] = colors[colorsOffset + pixels[y * 160 + x]] & 254;
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeAtr(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 768)
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, content, -3, 0, 3, 0);
	return TRUE;
}

static cibool RECOIL_DecodeAwbm(RECOIL *self, unsigned char const *content, int contentLength)
{
	int width = content[4] | (content[5] << 8);
	int height = content[6] | (content[7] << 8);
	int planeStride = (width + 7) >> 3;
	cibool colors256;
	if (RECOIL_DecodeAwbmPalette(self, content, contentLength, 8 + width * height, 256))
		colors256 = TRUE;
	else if ((width & 3) == 0 && RECOIL_DecodeAwbmPalette(self, content, contentLength, 8 + (height * planeStride << 2), 16))
		colors256 = FALSE;
	else
		return FALSE;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_PC1X1))
		return FALSE;
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < width; x++) {
					int c;
					if (colors256)
						c = content[8 + y * width + x];
					else {
						int offset = 8 + (y * planeStride << 2) + (x >> 3);
						c = 0;
						{
							int bit;
							for (bit = 0; bit < 4; bit++) {
								c |= ((content[offset] >> (~x & 7)) & 1) << bit;
								offset += planeStride;
							}
						}
					}
					self->pixels[y * width + x] = self->contentPalette[c];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeAwbmPalette(RECOIL *self, unsigned char const *content, int contentLength, int paletteOffset, int colors)
{
	if (!RECOIL_IsStringAt(content, paletteOffset, "RGB ") || contentLength < paletteOffset + 4 + colors * 3)
		return FALSE;
	{
		int i;
		for (i = 0; i < colors; i++) {
			int r = content[paletteOffset + 4 + i * 3];
			int g = content[paletteOffset + 5 + i * 3];
			int b = content[paletteOffset + 6 + i * 3];
			int rgb = (r << 16) | (g << 8) | b;
			self->contentPalette[i] = ((rgb & 4144959) << 2) | ((rgb >> 4) & 197379);
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeBb0(RECOIL *self, unsigned char const *content, int contentLength, int const *palette)
{
	if (contentLength != 20480)
		return FALSE;
	RECOIL_SetSize(self, 640, 512, RECOILResolution_BBC1X2);
	{
		int y;
		for (y = 0; y < 256; y++) {
			{
				int x;
				for (x = 0; x < 640; x++) {
					int c = (content[(y & ~7) * 80 + (x & ~7) + (y & 7)] >> (~x & 7)) & 1;
					int pixelsOffset = y * 1280 + x;
					self->pixels[pixelsOffset + 640] = self->pixels[pixelsOffset] = palette[c];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeBb1(RECOIL *self, unsigned char const *content, int contentLength, int const *palette)
{
	if (contentLength != 20480)
		return FALSE;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC1X1);
	{
		int y;
		for (y = 0; y < 256; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					int c = content[(y & ~7) * 80 + ((x & ~3) << 1) + (y & 7)] >> (~x & 3);
					self->pixels[y * 320 + x] = palette[((c >> 3) & 2) + (c & 1)];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeBb2(RECOIL *self, unsigned char const *content, int contentLength, int const *palette)
{
	if (contentLength != 20480)
		return FALSE;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC2X1);
	{
		int y;
		for (y = 0; y < 256; y++) {
			{
				int x;
				for (x = 0; x < 160; x++) {
					int c = content[(y & ~7) * 80 + ((x & ~1) << 2) + (y & 7)] >> (~x & 1);
					int pixelsOffset = (y * 160 + x) << 1;
					self->pixels[pixelsOffset + 1] = self->pixels[pixelsOffset] = palette[((c >> 3) & 8) + ((c >> 2) & 4) + ((c >> 1) & 2) + (c & 1)];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeBb4(RECOIL *self, unsigned char const *content, int contentLength, int const *palette)
{
	if (contentLength != 10240)
		return FALSE;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC1X1);
	{
		int y;
		for (y = 0; y < 256; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					int c = (content[(y & ~7) * 40 + (x & ~7) + (y & 7)] >> (~x & 7)) & 1;
					self->pixels[y * 320 + x] = palette[c];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeBb5(RECOIL *self, unsigned char const *content, int contentLength, int const *palette)
{
	if (contentLength != 10240)
		return FALSE;
	RECOIL_SetSize(self, 320, 256, RECOILResolution_BBC2X1);
	{
		int y;
		for (y = 0; y < 256; y++) {
			{
				int x;
				for (x = 0; x < 160; x++) {
					int c = content[(y & ~7) * 40 + ((x & ~3) << 1) + (y & 7)] >> (~x & 3);
					int pixelsOffset = (y * 160 + x) << 1;
					self->pixels[pixelsOffset + 1] = self->pixels[pixelsOffset] = palette[((c >> 3) & 2) + (c & 1)];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeBbg(RECOIL *self, unsigned char const *content, int contentLength)
{
	BbgStream rle;
	int mode;
	int unpackedLength;
	int unpackedStep;
	unsigned char unpacked[20480];
	BbgStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	rle.valueBits = BbgStream_ReadBitsReverse(&rle, 8);
	if (rle.valueBits < 1 || rle.valueBits > 8)
		return FALSE;
	mode = BbgStream_ReadBitsReverse(&rle, 8);
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
		return FALSE;
	}
	{
		int i;
		for (i = 15; i >= 0; i--) {
			int c = BbgStream_ReadBitsReverse(&rle, 4);
			if (c < 0)
				return FALSE;
			self->contentPalette[i] = RECOIL_BbcPalette[c];
		}
	}
	unpackedStep = BbgStream_ReadBitsReverse(&rle, 8);
	if (unpackedStep <= 0)
		return FALSE;
	rle.countBits = BbgStream_ReadBitsReverse(&rle, 8);
	if (rle.countBits < 1 || rle.countBits > 8)
		return FALSE;
	{
		int unpackedOffset;
		for (unpackedOffset = unpackedStep - 1;;) {
			int b = RleStream_ReadRle(&rle.base);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset] = b;
			unpackedOffset += unpackedStep;
			if (unpackedOffset >= unpackedLength) {
				unpackedOffset = unpackedOffset % unpackedStep - 1;
				if (unpackedOffset < 0)
					break;
			}
		}
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
		return FALSE;
	}
}

static cibool RECOIL_DecodeBfli(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 33795 || content[2] != 98)
		return FALSE;
	RECOIL_SetSize(self, 296, 400, RECOILResolution_C642X1);
	RECOIL_DecodeC64MulticolorFrame(self, content, 9243, 1030, 6, 0, 0);
	RECOIL_DecodeC64MulticolorFrame(self, content, 25603, 17411, 3, 0, 59200);
	return TRUE;
}

static cibool RECOIL_DecodeBgp(RECOIL *self, unsigned char const *content, int contentLength)
{
	int textLength;
	unsigned char frame1[76480];
	unsigned char frame2[76480];
	if (contentLength < 19163 || !RECOIL_IsStringAt(content, 0, "BUGBITER_APAC239I_PICTURE_V1.0") || content[30] != 255 || content[31] != 80 || content[32] != 239)
		return FALSE;
	textLength = content[37] + (content[38] << 8);
	if (contentLength != 19163 + textLength || content[39 + textLength] != 88 || content[40 + textLength] != 37 || content[9601 + textLength] != 88 || content[9602 + textLength] != 37)
		return FALSE;
	RECOIL_SetSize(self, 320, 239, RECOILResolution_XE4X1);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 41 + textLength, 80, frame1, 0, 640, 320, 120);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9643 + textLength, 80, frame1, 1);
	RECOIL_DecodeAtari8Gr9(self, content, 81 + textLength, 80, frame2, 320, 640, 320, 119);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9603 + textLength, 80, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static void RECOIL_DecodeBitplanes(RECOIL *self, unsigned char const *content, int contentOffset, int bitplanes, int pixelsOffset, int pixelsCount)
{
	{
		int i;
		for (i = 0; i < pixelsCount; i++) {
			int offset = contentOffset + ((i >> 3) & ~1) * bitplanes + ((i >> 3) & 1);
			int bit = ~i & 7;
			int c = 0;
			{
				int bitplane;
				for (bitplane = bitplanes; --bitplane >= 0;)
					c = (c << 1) | ((content[offset + (bitplane << 1)] >> bit) & 1);
			}
			self->pixels[pixelsOffset + i] = self->contentPalette[c];
		}
	}
}

static cibool RECOIL_DecodeBkg(RECOIL *self, unsigned char const *content, int contentLength)
{
	return contentLength == 3856 && RECOIL_DecodeGr7(self, content, 0, 3844);
}

static cibool RECOIL_DecodeBlackAndWhite(RECOIL *self, unsigned char const *content, int contentOffset, int width, int height, int backgroundColor, RECOILResolution resolution)
{
	if (!RECOIL_SetSize(self, width, height, resolution))
		return FALSE;
	self->contentPalette[0] = backgroundColor;
	self->contentPalette[1] = backgroundColor ^ 16777215;
	RECOIL_DecodeBitplanes(self, content, contentOffset, 1, 0, width * height);
	return TRUE;
}

static void RECOIL_DecodeBlackAndWhiteFont(RECOIL *self, unsigned char const *content, int contentOffset, int contentLength)
{
	{
		int y;
		for (y = 0; y < self->height; y++) {
			{
				int x;
				for (x = 0; x < 256; x++) {
					int offset = contentOffset + ((y & ~7) << 5) + (x & ~7) + (y & 7);
					int c;
					if (offset < contentLength) {
						c = (content[offset] >> (~x & 7)) & 1;
						if (c != 0)
							c = 16777215;
					}
					else
						c = 0;
					self->pixels[(y << 8) + x] = c;
				}
			}
		}
	}
}

static cibool RECOIL_DecodeBlazingPaddlesVectors(RECOIL *self, unsigned char const *content, int contentLength, int startAddress)
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
	unsigned char frame[76800];
	for (i = 0; i < 256; i++) {
		int shapeWidth;
		if (!BlazingPaddlesBoundingBox_Calculate(&box, content, contentLength, i, startAddress))
			break;
		shapeWidth = box.right - box.left + 2;
		if (x + shapeWidth > 160) {
			y -= lineTop;
			while (lineI < i)
				ys[lineI++] = y;
			if (width < x)
				width = (x + 3) & ~3;
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
		width = (x + 3) & ~3;
	y += lineBottom + 1;
	if (i == 0 || y > 240)
		return FALSE;
	RECOIL_SetSize(self, width * 2, y, RECOILResolution_XE2X1);
	memset(frame, 0, sizeof(frame));
	for (i = 0; i < 256; i++) {
		if (!RECOIL_DrawBlazingPaddlesVector(self, content, contentLength, frame, (ys[i] * width + xs[i]) * 2, i, startAddress))
			break;
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeBml(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 17474:
	case 17665:
	case 17666:
		break;
	default:
		return FALSE;
	}
	RECOIL_DecodeC64Multicolor(self, 296, content, 9498, 1285, 261, -2);
	return TRUE;
}

static cibool RECOIL_DecodeBru(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 64)
		return FALSE;
	RECOIL_SetSize(self, 8, 8, RECOILResolution_ST1X1);
	{
		int i;
		for (i = 0; i < 64; i++) {
			switch (content[i]) {
			case 0:
				self->pixels[i] = 0;
				break;
			case 1:
				self->pixels[i] = 16777215;
				break;
			default:
				return FALSE;
			}
		}
	}
	return TRUE;
}

static void RECOIL_DecodeC64HiresFrame(RECOIL *self, unsigned char const *content, int bitmapOffset, int videoMatrixOffset, int pixelsOffset)
{
	cibool afli = self->width == 296;
	{
		int y;
		for (y = 0; y < self->height; y++) {
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int offset = (y & ~7) * 40 + (x & ~7) + (y & 7);
					int c = (content[bitmapOffset + offset] >> (~x & 7)) & 1;
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
					self->pixels[pixelsOffset + y * self->width + x] = RECOIL_C64Palette[c];
				}
			}
		}
	}
}

static cibool RECOIL_DecodeC64Multicolor(RECOIL *self, int width, unsigned char const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background)
{
	RECOIL_SetSize(self, width, 200, RECOILResolution_C642X1);
	RECOIL_DecodeC64MulticolorFrame(self, content, bitmapOffset, videoMatrixOffset, colorOffset, background, 0);
	return TRUE;
}

static void RECOIL_DecodeC64MulticolorFrame(RECOIL *self, unsigned char const *content, int bitmapOffset, int videoMatrixOffset, int colorOffset, int background, int pixelsOffset)
{
	cibool fli = self->width == 296;
	cibool bottomBfli = pixelsOffset != 0 && self->height == 400;
	{
		int y;
		for (y = 0; y < 200; y++) {
			int lineBackground;
			if (background >= 0)
				lineBackground = background;
			else if (background == -16209 && y >= 177)
				lineBackground = content[y < 197 ? 18233 + y : 18429];
			else
				lineBackground = content[y - background];
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int c = lineBackground;
					int i = x + self->leftSkip;
					if (i >= 0) {
						int offset = (y & ~7) * 40 + (i & ~7) + (y & 7);
						if (bottomBfli)
							offset = (offset - 168) & 8191;
						switch ((content[bitmapOffset + offset] >> (~i & 6)) & 3) {
						case 1:
							offset >>= 3;
							if (fli)
								offset += (y & 7) << 10;
							c = content[videoMatrixOffset + offset] >> 4;
							break;
						case 2:
							offset >>= 3;
							if (fli)
								offset += (y & 7) << 10;
							c = content[videoMatrixOffset + offset];
							break;
						case 3:
							c = colorOffset < 0 ? content[-colorOffset] : content[colorOffset + (offset >> 3)];
							break;
						default:
							break;
						}
					}
					self->pixels[pixelsOffset + y * self->width + x] = RECOIL_C64Palette[c & 15];
				}
			}
		}
	}
}

static cibool RECOIL_DecodeCa(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	if (contentLength < 8 || content[0] != 67 || content[1] != 65)
		return FALSE;
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
		return FALSE;
	}
	switch (content[2]) {
		unsigned char unpacked[32000];
	case 0:
		if (contentOffset + 32000 != contentLength)
			return FALSE;
		return RECOIL_DecodeSt(self, content, contentOffset, content, 4, content[3]);
	case 1:
		if (!CaStream_UnpackCa(content, contentOffset, contentLength, unpacked, 0))
			return FALSE;
		return RECOIL_DecodeSt(self, unpacked, 0, content, 4, content[3]);
	default:
		return FALSE;
	}
}

static cibool RECOIL_DecodeCci(RECOIL *self, unsigned char const *content, int contentLength)
{
	CciStream rle;
	unsigned char unpacked[16384];
	if (contentLength < 24 || !RECOIL_IsStringAt(content, 0, "CIN 1.2 "))
		return FALSE;
	CciStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 8;
	rle.base.base.base.contentLength = contentLength;
	if (!CciStream_UnpackGr15(&rle, unpacked, 0))
		return FALSE;
	if (!CciStream_UnpackGr15(&rle, unpacked, 40))
		return FALSE;
	rle.base.base.base.contentOffset += 4;
	rle.base.repeatCount = 0;
	if (!RleStream_Unpack(&rle.base, unpacked, 7680, 40, 7680))
		return FALSE;
	rle.base.base.base.contentOffset += 4;
	rle.base.repeatCount = 0;
	if (!RleStream_Unpack(&rle.base, unpacked, 15360, 1, 1024))
		return FALSE;
	return RECOIL_DecodeCin(self, unpacked, 16384);
}

static cibool RECOIL_DecodeCh8(RECOIL *self, unsigned char const *content, int contentLength)
{
	int height;
	switch (contentLength) {
	case 768:
		height = 24;
		break;
	case 2048:
		height = 64;
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, 256, height, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeBlackAndWhiteFont(self, content, 0, contentLength);
	return TRUE;
}

static cibool RECOIL_DecodeChr(RECOIL *self, unsigned char const *content, int contentLength)
{
	return contentLength == 3072 && RECOIL_DecodeBlazingPaddlesVectors(self, content, contentLength, 28672);
}

static cibool RECOIL_DecodeCin(RECOIL *self, unsigned char const *content, int contentLength)
{
	int height;
	unsigned char frame1[64000];
	unsigned char frame2[64000];
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
		return FALSE;
	}
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < height; y++) {
			if (contentLength == 16384)
				RECOIL_SetBakPF012(self, content, 15360 + y, 256);
			RECOIL_DecodeAtari8Gr15(self, content, y * 40, 40, (y & 1) == 0 ? frame1 : frame2, y * 320, 320, 1);
		}
	}
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 40 * height + 40, 80, frame1, 1);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 40 * height, 80, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeCpr(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[7680];
	unsigned char frame[61440];
	if (contentLength < 2)
		return FALSE;
	if (!XeKoalaStream_UnpackRaw(content[0], content, 1, contentLength, unpacked, 7680))
		return FALSE;
	self->gtiaColors[6] = 12;
	self->gtiaColors[5] = 0;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1);
	RECOIL_DecodeAtari8Gr8(self, unpacked, 0, frame, 0, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeCpt(RECOIL *self, unsigned char const *content, int contentLength)
{
	int bitplanes;
	unsigned char unpacked[32000];
	unsigned char isFilled[16000];
	int contentOffset;
	if (contentLength < 40 || content[32] != 0 || content[33] > 2)
		return FALSE;
	bitplanes = 4 >> content[33];
	memset(isFilled, 0, sizeof(isFilled));
	contentOffset = 34;
	for (;;) {
		int nextContentOffset = contentOffset + 4 + bitplanes * 2;
		int repeatCount;
		int offset;
		if (nextContentOffset > contentLength)
			return FALSE;
		repeatCount = (content[contentOffset] << 8) | content[contentOffset + 1];
		if (repeatCount == 65535) {
			contentOffset = nextContentOffset;
			break;
		}
		offset = ((content[contentOffset + 2] << 8) | content[contentOffset + 3]) * bitplanes;
		do {
			if (offset >= 16000)
				return FALSE;
			{
				int bitplane;
				for (bitplane = 0; bitplane < bitplanes; bitplane++) {
					unpacked[offset * 2] = content[contentOffset + 4 + bitplane * 2];
					unpacked[offset * 2 + 1] = content[contentOffset + 4 + bitplane * 2 + 1];
					isFilled[offset++] = 1;
				}
			}
		}
		while (--repeatCount >= 0);
		contentOffset = nextContentOffset;
	}
	{
		int offset;
		for (offset = 0; offset < 16000; offset++) {
			if (isFilled[offset] == 0) {
				if (contentOffset + 1 >= contentLength)
					return FALSE;
				unpacked[offset * 2] = content[contentOffset++];
				unpacked[offset * 2 + 1] = content[contentOffset++];
			}
		}
	}
	return RECOIL_DecodeSt(self, unpacked, 0, content, 0, content[33]);
}

static cibool RECOIL_DecodeDd(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 9026:
	case 9218:
	case 9346:
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 1026, 2, 0);
	return TRUE;
}

static cibool RECOIL_DecodeDel(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[96000];
	if (!CaStream_UnpackDel(content, contentLength, unpacked, 2))
		return FALSE;
	return RECOIL_DecodePi4(self, unpacked, 77824);
}

static cibool RECOIL_DecodeDgc(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[64000];
	int contentOffset;
	int valueBytes;
	int repeatCount;
	if (contentLength < 1042 || content[0] != 68 || content[1] != 71 || content[2] != 67 || content[3] > 3 || content[4] != 1 || content[5] != 64 || content[6] != 0 || content[7] != 200)
		return FALSE;
	if (content[3] == 0) {
		if (contentLength != 65034)
			return FALSE;
		RECOIL_DecodeFalconPalette320(self, content, 1034, 10, 200);
		return TRUE;
	}
	contentOffset = 1038;
	valueBytes = 1 << (content[3] - 1);
	repeatCount = 0;
	{
		int bitplane;
		for (bitplane = 0; bitplane < 16; bitplane += 2) {
			{
				int unpackedOffset;
				for (unpackedOffset = bitplane; unpackedOffset < 64000; unpackedOffset += 16) {
					{
						int x;
						for (x = 0; x < 2; x++) {
							if (repeatCount == 0) {
								int nextContentOffset = contentOffset + content[3] * 2;
								if (nextContentOffset > contentLength)
									return FALSE;
								switch (content[3]) {
								case 1:
									repeatCount = content[contentOffset] + 1;
									break;
								case 2:
									repeatCount = ((content[contentOffset] << 8) + content[contentOffset + 1] + 1) << 1;
									break;
								case 3:
									repeatCount = ((content[contentOffset] << 8) + content[contentOffset + 1] + 1) << 2;
									break;
								}
								contentOffset = nextContentOffset;
							}
							repeatCount--;
							unpacked[unpackedOffset + x] = content[contentOffset - valueBytes + (~repeatCount & (valueBytes - 1))];
						}
					}
				}
			}
		}
	}
	RECOIL_SetFalconPalette(self, content, 10);
	RECOIL_SetSize(self, 320, 200, RECOILResolution_FALCON1X1);
	RECOIL_DecodeBitplanes(self, unpacked, 0, 8, 0, 64000);
	return TRUE;
}

static cibool RECOIL_DecodeDgu(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 65032 || content[0] != 68 || content[1] != 71 || content[2] != 85 || content[3] != 1 || content[4] != 1 || content[5] != 64 || content[6] != 0 || content[7] != 200)
		return FALSE;
	RECOIL_DecodeFalconPalette320(self, content, 1032, 8, 200);
	return TRUE;
}

static cibool RECOIL_DecodeDhr(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 16384)
		return FALSE;
	RECOIL_SetSize(self, 560, 384, RECOILResolution_APPLE_I_I1X2);
	{
		int y;
		for (y = 0; y < 192; y++) {
			int lineOffset = ((y & 7) << 10) | ((y & 56) << 4) | (y >> 6) * 40;
			{
				int x;
				for (x = 0; x < 560; x++) {
					int b = x / 7;
					int c = (content[((b & 1) << 13) + lineOffset + (b >> 1)] >> x % 7) & 1;
					int pixelsOffset;
					if (c != 0)
						c = 16777215;
					pixelsOffset = y * 1120 + x;
					self->pixels[pixelsOffset + 560] = self->pixels[pixelsOffset] = c;
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeDlm(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char characters[176];
	unsigned char frame[11264];
	if (contentLength != 256)
		return FALSE;
	{
		int y;
		for (y = 0; y < 16; y++)
			{
				int x;
				for (x = 0; x < 11; x++)
					characters[y * 11 + x] = RECOIL_ToAtari8Char(content[y * 16 + 5 + x]);
			}
	}
	RECOIL_SetSize(self, 88, 128, RECOILResolution_XE1X1);
	RECOIL_DecodeAtari8Gr0(self, characters, 11, CiBinaryResource_atari8_fnt, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeDol(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 10241:
	case 10242:
	case 10050:
		break;
	default:
		return FALSE;
	}
	return RECOIL_DecodeC64Multicolor(self, 320, content, 2050, 1026, 2, content[2026]);
}

static cibool RECOIL_DecodeDoo(RECOIL *self, unsigned char const *content, int contentLength)
{
	return contentLength == 32000 && RECOIL_DecodeBlackAndWhite(self, content, 0, 640, 400, 16777215, RECOILResolution_ST1X1);
}

static cibool RECOIL_DecodeDph(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char *unpacked = (unsigned char *) malloc(320000 * sizeof(unsigned char ));
	if (!CaStream_UnpackDel(content, contentLength, unpacked, 10)) {
		free(unpacked);
		return FALSE;
	}
	RECOIL_SetFalconPalette(self, unpacked, 0);
	RECOIL_SetSize(self, 640, 480, RECOILResolution_FALCON1X1);
	{
		int y;
		for (y = 0; y < 240; y++) {
			RECOIL_DecodeBitplanes(self, unpacked, 1024 + y * 320, 8, y * 640, 320);
			RECOIL_DecodeBitplanes(self, unpacked, 77824 + y * 320, 8, y * 640 + 320, 320);
			RECOIL_DecodeBitplanes(self, unpacked, 154624 + y * 320, 8, (240 + y) * 640, 320);
			RECOIL_DecodeBitplanes(self, unpacked, 231424 + y * 320, 8, (240 + y) * 640 + 320, 320);
		}
	}
	free(unpacked);
	return TRUE;
}

static cibool RECOIL_DecodeDrg(RECOIL *self, unsigned char const *content, int contentLength)
{
	return contentLength == 6400 && RECOIL_DecodeGr8(self, content, contentLength);
}

static cibool RECOIL_DecodeDrl(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[18242];
	int shift;
	content = DrpStream_UnpackFile(content, contentLength, "DRAZLACE! 1.0", unpacked, 18242);
	if (content == NULL)
		return FALSE;
	shift = content[10052];
	if (shift > 1)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, shift == 0 ? RECOILResolution_C642X1 : RECOILResolution_C641X1);
	RECOIL_DecodeC64MulticolorFrame(self, content, 2050, 1026, 2, content[10050], 0);
	self->leftSkip = -shift;
	RECOIL_DecodeC64MulticolorFrame(self, content, 10242, 1026, 2, content[10050], 64000);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeDrz(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[10051];
	content = DrpStream_UnpackFile(content, contentLength, "DRAZPAINT 1.4", unpacked, 10051);
	return content != NULL && RECOIL_DecodeC64Multicolor(self, 320, content, 2050, 1026, 2, content[10050]);
}

static cibool RECOIL_DecodeDu2(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 113576 && contentLength != 113600)
		return FALSE;
	RECOIL_DecodeStMedium(self, content, 8, content, 0, 832, 273, 1);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeDuo(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 113600)
		return FALSE;
	RECOIL_DecodeStLow(self, content, 32, content, 0, 416, 273);
	RECOIL_DecodeBitplanes(self, content, 56816, 4, 113568, 113568);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeEci(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 32770)
		return FALSE;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 26, 8197, 0);
	RECOIL_DecodeC64HiresFrame(self, content, 16410, 24581, 59200);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeEcp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[32770];
	DrpStream rle;
	if (contentLength < 6)
		return FALSE;
	DrpStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	rle.escape = content[2];
	return RleStream_Unpack(&rle.base, unpacked, 2, 1, 32768) && RECOIL_DecodeEci(self, unpacked, 32770);
}

static cibool RECOIL_DecodeEpa(RECOIL *self, unsigned char const *content, int contentLength)
{
	int columns;
	int rows;
	int width;
	int height;
	int bitmapOffset;
	if (contentLength < 17)
		return FALSE;
	if (RECOIL_IsStringAt(content, 0, "AWBM"))
		return RECOIL_DecodeAwbm(self, content, contentLength);
	columns = content[0];
	rows = content[1];
	if (columns > 80 || rows > 25 || contentLength != 2 + columns * rows * 15 + 70)
		return FALSE;
	width = columns * 8;
	height = rows * 14;
	RECOIL_SetSize(self, width, height, RECOILResolution_PC1X1);
	bitmapOffset = 2 + columns * rows;
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < width; x++) {
					int ch = y / 14 * columns + (x >> 3);
					int attribute = content[2 + ch];
					int b = (content[bitmapOffset + ch * 14 + y % 14] >> (~x & 7)) & 1;
					static const int palette[16] = { 0, 170, 43520, 43690, 11141120, 11141290, 11162880, 11184810, 5592405, 5592575, 5635925, 5636095, 16733525, 16733695, 16777045, 16777215 };
					self->pixels[y * width + x] = palette[b == 0 ? attribute >> 4 : attribute & 15];
				}
			}
		}
	}
	return TRUE;
}

static void RECOIL_DecodeFalconPalette320(RECOIL *self, unsigned char const *content, int bitplanesOffset, int paletteOffset, int height)
{
	RECOIL_SetFalconPalette(self, content, paletteOffset);
	RECOIL_SetSize(self, 320, height, RECOILResolution_FALCON1X1);
	RECOIL_DecodeBitplanes(self, content, bitplanesOffset, 8, 0, 320 * height);
}

static cibool RECOIL_DecodeFalconTrueColor(RECOIL *self, unsigned char const *content, int contentLength, int contentOffset, int width, int height)
{
	int pixelsCount = width * height;
	if (contentOffset + pixelsCount * 2 != contentLength || !RECOIL_SetSize(self, width, height, RECOILResolution_FALCON1X1))
		return FALSE;
	{
		int i;
		for (i = 0; i < pixelsCount; i++) {
			int rg = content[contentOffset + i * 2];
			int gb = content[contentOffset + i * 2 + 1];
			int r = (rg & 248) | (rg >> 5);
			int g = ((rg & 7) << 3) | (gb >> 5);
			int b;
			g = (g << 2) | (g >> 4);
			b = gb & 31;
			b = (b << 3) | (b >> 2);
			self->pixels[i] = (r << 16) | (g << 8) | b;
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeFalconTrueColorVariable(RECOIL *self, unsigned char const *content, int contentLength, int widthOffset, int dataOffset)
{
	int width = (content[widthOffset] << 8) | content[widthOffset + 1];
	int height = (content[widthOffset + 2] << 8) | content[widthOffset + 3];
	return RECOIL_DecodeFalconTrueColor(self, content, contentLength, dataOffset, width, height);
}

static cibool RECOIL_DecodeFfli(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 26115 || content[2] != 102)
		return FALSE;
	RECOIL_DecodeC64Multicolor(self, 296, content, 9499, 1286, 262, -3);
	RECOIL_DecodeC64MulticolorFrame(self, content, 9499, 17670, 262, -25859, 59200);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeFli(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 17218:
	case 17409:
	case 17410:
		break;
	default:
		return FALSE;
	}
	RECOIL_DecodeC64Multicolor(self, 296, content, 9242, 1029, 5, 0);
	return TRUE;
}

static cibool RECOIL_DecodeFtc(RECOIL *self, unsigned char const *content, int contentLength)
{
	return RECOIL_DecodeFalconTrueColor(self, content, contentLength, 0, 384, 240);
}

static cibool RECOIL_DecodeFun(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength < 18 || !RECOIL_IsStringAt(content, 2, "FUNPAINT (MT) "))
		return FALSE;
	if (content[16] != 0) {
		unsigned char unpacked[33694];
		DrpStream rle;
		DrpStream_Construct(&rle, NULL);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 18;
		rle.base.base.base.contentLength = contentLength;
		rle.escape = content[17];
		return RleStream_Unpack(&rle.base, unpacked, 18, 1, 33676) && RleStream_ReadRle(&rle.base) < 0 && RECOIL_DecodeFunUnpacked(self, unpacked);
	}
	return contentLength == 33694 && RECOIL_DecodeFunUnpacked(self, content);
}

static cibool RECOIL_DecodeFunUnpacked(RECOIL *self, unsigned char const *content)
{
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64MulticolorFrame(self, content, 8234, 21, 16405, 0, 0);
	self->leftSkip = -1;
	RECOIL_DecodeC64MulticolorFrame(self, content, 25618, 17405, 16405, 0, 59200);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeFwa(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	int dlOffset;
	int dliOffset;
	if (contentLength < 7960 || content[0] != 254 || content[1] != 254 || content[6] != 112 || content[7] != 112 || content[8] != 112 || content[11] != 80 || content[115] != 96 || content[205] != 65 || 7960 + content[7958] + (content[7959] << 8) != contentLength)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
	RECOIL_SetBakPF012(self, content, 2, 1);
	dlOffset = 9;
	dliOffset = 7960;
	{
		int y;
		for (y = 0; y < 192; y++) {
			int dlInstr;
			RECOIL_DecodeAtari8Gr15(self, content, 262 + 40 * y + (y >= 102 ? 16 : 0), 40, frame, y * 320, 320, 1);
			dlInstr = content[dlOffset];
			if (dlOffset == 9 || dlOffset == 113) {
				if ((dlInstr & 127) != 78 || content[dlOffset + 1] != 0)
					return FALSE;
				dlOffset += 3;
			}
			else {
				if ((dlInstr & 127) != 14)
					return FALSE;
				dlOffset++;
			}
			if (dlInstr >= 128) {
				unsigned char a;
				if (dliOffset + 14 > contentLength || content[dliOffset] != 72 || content[dliOffset + 1] != 138 || content[dliOffset + 2] != 72 || content[dliOffset + 3] != 169 || content[dliOffset + 5] != 141 || content[dliOffset + 6] != 10 || content[dliOffset + 7] != 212)
					return FALSE;
				a = content[dliOffset + 4];
				dliOffset += 8;
				while (content[dliOffset] != 32) {
					switch (content[dliOffset]) {
						int lo;
					case 169:
						a = content[dliOffset + 1];
						dliOffset += 2;
						break;
					case 141:
						if (content[dliOffset + 2] != 208)
							return FALSE;
						lo = content[dliOffset + 1];
						switch (lo) {
						case 22:
						case 23:
						case 24:
						case 26:
							self->gtiaColors[lo - 18] = a & 254;
							break;
						default:
							return FALSE;
						}
						dliOffset += 3;
						break;
					default:
						return FALSE;
					}
					if (dliOffset + 3 > contentLength)
						return FALSE;
				}
				if (content[dliOffset + 1] != 202 || content[dliOffset + 2] != 6)
					return FALSE;
				dliOffset += 3;
			}
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeG09(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[122880];
	switch (contentLength) {
	case 7680:
		return RECOIL_DecodeGr9(self, content, contentLength);
	case 15360:
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, 640, 192, RECOILResolution_XE4X1);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame, 0, 640, 320, 192);
	RECOIL_DecodeAtari8Gr9(self, content, 7680, 40, frame, 320, 640, 320, 192);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeG10(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	unsigned char frame[76800];
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE4X1))
		return FALSE;
	contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	if ((contentLength - contentOffset) % 40 != 9)
		return FALSE;
	self->leftSkip = 2;
	RECOIL_SetGtiaColors(self, content, contentLength - 9);
	RECOIL_DecodeAtari8Gr10(self, content, contentOffset, frame, 0, 320, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeG11(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	unsigned char frame[76800];
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE4X1))
		return FALSE;
	self->gtiaColors[8] = 6;
	contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	RECOIL_DecodeAtari8Gr11(self, content, contentOffset, frame, 0, 320, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeGfb(RECOIL *self, unsigned char const *content, int contentLength)
{
	int bitplanes;
	int width;
	int height;
	int bitmapLength;
	if (contentLength < 20 || !RECOIL_IsStringAt(content, 0, "GF25"))
		return FALSE;
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
		return FALSE;
	}
	width = RECOIL_Get32BigEndian(content, 8);
	height = RECOIL_Get32BigEndian(content, 12);
	bitmapLength = RECOIL_Get32BigEndian(content, 16);
	if (1556 + bitmapLength != contentLength || bitmapLength != (width >> 3) * bitplanes * height)
		return FALSE;
	{
		int i;
		for (i = 0; i < 1 << bitplanes; i++) {
			int j;
			int rgb;
			switch (i) {
			case 1:
				j = (1 << bitplanes) - 1;
				break;
			case 2:
				j = 1;
				break;
			case 3:
				j = 2;
				break;
			case 5:
				j = 6;
				break;
			case 6:
				j = 3;
				break;
			case 7:
				j = 5;
				break;
			case 8:
				j = 7;
				break;
			case 9:
				j = 8;
				break;
			case 10:
				j = 9;
				break;
			case 11:
				j = 10;
				break;
			case 13:
				j = 14;
				break;
			case 14:
				j = 11;
				break;
			case 15:
				j = 13;
				break;
			case 255:
				j = 15;
				break;
			default:
				j = i;
				break;
			}
			rgb = RECOIL_GetStColor1000(content, 20 + bitmapLength + i * 6);
			if (rgb < 0)
				return FALSE;
			self->contentPalette[j] = rgb;
		}
	}
	if (!RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes))
		return FALSE;
	RECOIL_DecodeBitplanes(self, content, 20, bitplanes, 0, width * height);
	return TRUE;
}

static cibool RECOIL_DecodeGg(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[10003];
	C64KoalaStream rle;
	if (contentLength < 2)
		return FALSE;
	C64KoalaStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_UnpackC64(&rle.base, unpacked, 10003) && RECOIL_DecodeKoa(self, unpacked, 10003);
}

static cibool RECOIL_DecodeGhg(RECOIL *self, unsigned char const *content, int contentLength)
{
	int width;
	int height;
	unsigned char frame[64000];
	if (contentLength < 4)
		return FALSE;
	width = ((content[0] | (content[1] << 8)) + 7) & ~7;
	height = content[2];
	if (width == 0 || width > 320 || height == 0 || height > 200)
		return FALSE;
	RECOIL_SetSize(self, width, height, RECOILResolution_XE1X1);
	self->gtiaColors[6] = 12;
	self->gtiaColors[5] = 2;
	RECOIL_DecodeAtari8Gr8(self, content, 3, frame, 0, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeGod(RECOIL *self, unsigned char const *content, int contentLength)
{
	return contentLength > 6 && RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 2, 6);
}

static cibool RECOIL_DecodeGr15Blend(RECOIL *self, unsigned char const *content, int bitmapOffset, int colorsOffset, int height)
{
	unsigned char frame1[64000];
	unsigned char frame2[64000];
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1);
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset, 80, frame1, 0, 640, height >> 1);
	RECOIL_SetPF012Bak(self, content, colorsOffset + 4);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + 40, 80, frame1, 320, 640, height >> 1);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + height * 40, 80, frame2, 0, 640, height >> 1);
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	RECOIL_DecodeAtari8Gr15(self, content, bitmapOffset + height * 40 + 40, 80, frame2, 320, 640, height >> 1);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeGr7(RECOIL *self, unsigned char const *content, int contentOffset, int contentSize)
{
	int height;
	unsigned char frame[76800];
	if (contentSize > 4804 || contentSize % 40 != 4)
		return FALSE;
	height = contentSize / 40;
	RECOIL_SetSize(self, 320, height * 2, RECOILResolution_XE2X2);
	RECOIL_SetBakPF012(self, content, contentOffset + contentSize - 4, 1);
	RECOIL_DecodeAtari8Gr7(self, content, contentOffset, frame, 0, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeGr8(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	unsigned char frame[76800];
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE1X1))
		return FALSE;
	self->gtiaColors[6] = 0;
	self->gtiaColors[5] = 14;
	contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	RECOIL_DecodeAtari8Gr8(self, content, contentOffset, frame, 0, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeGr9(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	unsigned char frame[76800];
	if (!RECOIL_SetAtari8RawSize(self, content, contentLength, RECOILResolution_XE4X1))
		return FALSE;
	self->gtiaColors[8] = 0;
	contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	RECOIL_DecodeAtari8Gr9(self, content, contentOffset, 40, frame, 0, 320, 320, self->height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeGun(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 33602 && contentLength != 33603)
		return FALSE;
	RECOIL_SetSize(self, 296, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64MulticolorFrame(self, content, 8218, 5, 16389, -16209, 0);
	self->leftSkip = -1;
	RECOIL_DecodeC64MulticolorFrame(self, content, 25626, 17413, 16389, -16209, 59200);
	return RECOIL_ApplyBlend(self);
}

static void RECOIL_DecodeHam(RECOIL *self, unsigned char const *unpacked, int bitplanes)
{
	int holdBits = bitplanes > 6 ? 6 : 4;
	int i = 0;
	{
		int y;
		for (y = 0; y < self->height; y++) {
			int rgb = self->contentPalette[0];
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int offset = ((i >> 3) & ~1) * bitplanes + ((i >> 3) & 1);
					int bit = ~i & 7;
					int c = 0;
					{
						int bitplane;
						for (bitplane = bitplanes; --bitplane >= 0;)
							c = (c << 1) | ((unpacked[offset + (bitplane << 1)] >> bit) & 1);
					}
					switch (c >> holdBits) {
					case 0:
						rgb = self->contentPalette[c];
						break;
					case 1:
						c = (c << (8 - holdBits)) & 255;
						c |= c >> holdBits;
						rgb = (rgb & 16776960) | c;
						break;
					case 2:
						c = (c << (8 - holdBits)) & 255;
						c |= c >> holdBits;
						rgb = (rgb & 65535) | (c << 16);
						break;
					case 3:
						c = (c << (8 - holdBits)) & 255;
						c |= c >> holdBits;
						rgb = (rgb & 16711935) | (c << 8);
						break;
					}
					self->pixels[i++] = rgb;
				}
			}
		}
	}
}

static cibool RECOIL_DecodeHed(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 9218)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 2, 8194, 0);
	return TRUE;
}

static cibool RECOIL_DecodeHfc(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 16386)
		return FALSE;
	RECOIL_SetSize(self, 296, 112, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 26, 8197, 0);
	return TRUE;
}

static cibool RECOIL_DecodeHgb(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset = RECOIL_GetAmstradHeader(content, contentLength);
	if (contentLength != contentOffset + 16384)
		return FALSE;
	return RECOIL_DecodeAmstradMode2(self, content, contentOffset, 512, 256);
}

static cibool RECOIL_DecodeHgr(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength < 8184)
		return FALSE;
	RECOIL_SetSize(self, 280, 192, RECOILResolution_APPLE_I_I1X1);
	{
		int y;
		for (y = 0; y < 192; y++) {
			int lineOffset = ((y & 7) << 10) | ((y & 56) << 4) | (y >> 6) * 40;
			{
				int x;
				for (x = 0; x < 280; x++) {
					int c = (content[lineOffset + x / 7] >> x % 7) & 1;
					if (c != 0)
						c = 16777215;
					self->pixels[y * 280 + x] = c;
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeHim(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[16372];
	HimStream rle;
	if (contentLength < 18 || content[0] != 0 || content[1] != 64)
		return FALSE;
	if (content[3] == 255)
		return contentLength == 16385 && RECOIL_DecodeHimUnpacked(self, content);
	if (content[2] + (content[3] << 8) != 16381 + contentLength || content[4] != 242 || content[5] != 127)
		return FALSE;
	HimStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentLength - 1;
	{
		int unpackedOffset;
		for (unpackedOffset = 16371; unpackedOffset >= 322; unpackedOffset--) {
			int b = RleStream_ReadRle(&rle.base);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset] = b;
		}
	}
	return RECOIL_DecodeHimUnpacked(self, unpacked);
}

static cibool RECOIL_DecodeHimUnpacked(RECOIL *self, unsigned char const *content)
{
	RECOIL_SetSize(self, 296, 192, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 346, 8237, 0);
	return TRUE;
}

static cibool RECOIL_DecodeHip(RECOIL *self, unsigned char const *content, int contentLength)
{
	static const unsigned char gr10Colors[9] = { 0, 0, 2, 4, 6, 8, 10, 12, 14 };
	unsigned char frame1[76800];
	unsigned char frame2[76800];
	int frameLength;
	if (contentLength < 80)
		return FALSE;
	frameLength = RECOIL_ParseAtari8ExecutableHeader(content, 0);
	if (frameLength > 0 && frameLength % 40 == 0 && 12 + frameLength * 2 == contentLength && RECOIL_ParseAtari8ExecutableHeader(content, 6 + frameLength) == frameLength) {
		int height = frameLength / 40;
		if (height > 240)
			return FALSE;
		RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1);
		self->leftSkip = 1;
		RECOIL_SetGtiaColors(self, gr10Colors, 0);
		RECOIL_DecodeAtari8Gr10(self, content, 6, frame1, 0, 320, height);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, content, 12 + frameLength, 40, frame2, 0, 320, 320, height);
	}
	else {
		int height = contentLength / 80;
		if (height > 240)
			return FALSE;
		RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1);
		self->leftSkip = 1;
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame1, 0, 320, 320, height);
		if (contentLength % 80 == 9)
			RECOIL_SetGtiaColors(self, content, contentLength - 9);
		else
			RECOIL_SetGtiaColors(self, gr10Colors, 0);
		RECOIL_DecodeAtari8Gr10(self, content, height * 40, frame2, 0, 320, height);
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeHir(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 8002:
	case 8194:
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 2, -16, 0);
	return TRUE;
}

static cibool RECOIL_DecodeHlf(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 24578)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 2, 9218, 0);
	RECOIL_DecodeC64HiresFrame(self, content, 16386, 10242, 64000);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeHlr(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 1628 || content[0] != 118 || content[1] != 175 || content[2] != 211 || content[3] != 254 || content[4] != 33 || content[5] != 0 || content[6] != 88)
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, content, -2, 92, 3, 0);
	RECOIL_DecodeZx(self, content, -2, 860, 3, 49152);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeHpm(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[7684];
	HpmStream rle;
	HpmStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 0;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 7680))
		return FALSE;
	switch (Stream_ReadByte(&rle.base.base.base)) {
	case 52:
	case 53:
		unpacked[7680] = 0;
		unpacked[7681] = 52;
		unpacked[7682] = contentLength == 3494 ? 56 : 200;
		unpacked[7683] = contentLength == 3494 ? 60 : 124;
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
	return RECOIL_DecodeMic(self, unpacked, 7684);
}

static cibool RECOIL_DecodeHr(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[61184];
	unsigned char frame2[61184];
	if (contentLength != 16384)
		return FALSE;
	RECOIL_SetSize(self, 256, 239, RECOILResolution_XE1X1);
	self->gtiaColors[6] = 0;
	self->gtiaColors[5] = 14;
	RECOIL_DecodeAtari8Gr8(self, content, 0, frame1, 0, 239);
	RECOIL_DecodeAtari8Gr8(self, content, 8192, frame2, 0, 239);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeHr2(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[64000];
	unsigned char frame2[64000];
	if (contentLength != 16006)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE1X1);
	RECOIL_SetPF21(self, content, 16000);
	RECOIL_DecodeAtari8Gr8(self, content, 0, frame1, 0, 200);
	RECOIL_SetBakPF012(self, content, 16002, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 8000, 40, frame2, 0, 320, 200);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static void RECOIL_DecodeIceFrame(RECOIL const *self, unsigned char const *content, int charactersOffset, int fontOffset, unsigned char *frame, IceFrameMode mode)
{
	int frameOffset = 0;
	unsigned char bitmap[40];
	{
		int y;
		for (y = 0; y < self->height; y++) {
			{
				int col;
				for (col = 0; col < self->width >> 3; col++) {
					int ch;
					int b;
					switch (charactersOffset) {
						static const unsigned char row2char1[16] = { 64, 0, 32, 96, 192, 128, 160, 224, 64, 0, 32, 96, 192, 128, 160, 224 };
						static const unsigned char row2char2[16] = { 64, 0, 32, 96, 192, 128, 160, 224, 192, 128, 160, 224, 64, 0, 32, 96 };
					case -1:
						ch = row2char1[y >> 3] + col;
						break;
					case -2:
						ch = row2char2[y >> 3] + col;
						break;
					default:
						ch = (y / 24 << 8) + content[charactersOffset + (y >> 3) * 40 + col];
						break;
					}
					b = content[fontOffset + ((ch & ~128) << 3) + (y & 7)];
					switch (mode) {
					case IceFrameMode_GR0:
					case IceFrameMode_GR0_GTIA9:
					case IceFrameMode_GR0_GTIA10:
					case IceFrameMode_GR0_GTIA11:
						if (charactersOffset < 0 && (ch & 128) != 0)
							b ^= 255;
						bitmap[col] = b;
						break;
					case IceFrameMode_GR12:
						{
							int x;
							for (x = col == 0 ? self->leftSkip : 0; x < 8; x++) {
								int c = (b >> (~x & 6)) & 3;
								int gr12Registers = (ch & 128) == 0 ? 25928 : 30024;
								frame[frameOffset + (col << 3) + x - self->leftSkip] = self->gtiaColors[(gr12Registers >> (c << 2)) & 15];
							}
						}
						break;
					case IceFrameMode_GR12_GTIA9:
					case IceFrameMode_GR12_GTIA11:
						bitmap[col] = RECOIL_Gr12GtiaByteToGr8(b, ch, FALSE);
						break;
					case IceFrameMode_GR12_GTIA10:
						bitmap[col] = RECOIL_Gr12GtiaByteToGr8(b, ch, TRUE);
						break;
					}
				}
			}
			switch (mode) {
			case IceFrameMode_GR0:
				RECOIL_DecodeAtari8Gr8(self, bitmap, 0, frame, frameOffset, 1);
				break;
			case IceFrameMode_GR12:
				{
					int x;
					for (x = self->width; x < self->width + self->leftSkip; x++)
						frame[frameOffset + x] = self->gtiaColors[8];
				}
				break;
			case IceFrameMode_GR0_GTIA9:
			case IceFrameMode_GR12_GTIA9:
				RECOIL_DecodeAtari8Gr9(self, bitmap, 0, 0, frame, frameOffset, 0, self->width, 1);
				break;
			case IceFrameMode_GR0_GTIA10:
			case IceFrameMode_GR12_GTIA10:
				RECOIL_DecodeAtari8Gr10(self, bitmap, 0, frame, frameOffset, 0, 1);
				break;
			case IceFrameMode_GR0_GTIA11:
			case IceFrameMode_GR12_GTIA11:
				RECOIL_DecodeAtari8Gr11(self, bitmap, 0, frame, frameOffset, 0, 1);
				break;
			}
			frameOffset += self->width;
		}
	}
}

static cibool RECOIL_DecodeIff(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	IffType type;
	int width;
	int height;
	int bitplanes;
	cibool hasMask;
	int compression;
	int colors;
	int camg;
	if (contentLength < 56 || !RECOIL_IsStringAt(content, 0, "FORM"))
		return FALSE;
	contentOffset = 8;
	if (RECOIL_IsStringAt(content, 8, "DPSTDPAH") && RECOIL_Get32BigEndian(content, 16) == 24 && RECOIL_IsStringAt(content, 44, "FORM"))
		contentOffset = 52;
	if (RECOIL_IsStringAt(content, contentOffset, "ILBM"))
		type = IffType_ILBM;
	else if (RECOIL_IsStringAt(content, contentOffset, "PBM "))
		type = IffType_PBM;
	else if (RECOIL_IsStringAt(content, contentOffset, "ACBM"))
		type = IffType_ACBM;
	else
		return FALSE;
	contentOffset += 4;
	width = 0;
	height = 0;
	bitplanes = 0;
	hasMask = FALSE;
	compression = 0;
	colors = 0;
	camg = 0;
	while (contentOffset + 7 < contentLength) {
		int chunkLength = RECOIL_Get32BigEndian(content, contentOffset + 4);
		if (contentOffset + 8 + chunkLength > contentLength)
			break;
		if (RECOIL_IsStringAt(content, contentOffset, "BMHD") && chunkLength >= 11) {
			int pixelsCount;
			width = (content[contentOffset + 8] << 8) | content[contentOffset + 9];
			height = (content[contentOffset + 10] << 8) | content[contentOffset + 11];
			bitplanes = content[contentOffset + 16];
			hasMask = content[contentOffset + 17] == 1;
			compression = content[contentOffset + 18];
			if (type == IffType_PBM) {
				if (bitplanes != 8 || compression > 1)
					return FALSE;
				width = (width + 3) & ~3;
			}
			else {
				if (bitplanes == 0 || (bitplanes > 8 && bitplanes != 24 && bitplanes != 32) || compression > 2)
					return FALSE;
				width = (width + 15) & ~15;
			}
			pixelsCount = width * height;
			if (pixelsCount <= 0 || pixelsCount > 1572864)
				return FALSE;
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "CMAP")) {
			int c;
			colors = chunkLength / 3;
			if (colors > 256)
				return FALSE;
			for (c = 0; c < colors; c++) {
				int offset = contentOffset + 8 + c * 3;
				self->contentPalette[c] = (content[offset] << 16) | (content[offset + 1] << 8) | content[offset + 2];
			}
			for (; c < 256; c++)
				self->contentPalette[c] = 0;
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "CAMG") && chunkLength >= 4)
			camg = RECOIL_Get32BigEndian(content, contentOffset + 8);
		else if (RECOIL_IsStringAt(content, contentOffset, "BODY")) {
			int bytesPerLine;
			unsigned char *unpacked;
			if (width == 0)
				return FALSE;
			bytesPerLine = (width >> 3) * bitplanes;
			if (compression == 2) {
				VdatStream rle;
				unpacked = (unsigned char *) malloc(bytesPerLine * height * sizeof(unsigned char ));
				VdatStream_Construct(&rle, NULL);
				rle.base.base.base.base.base.content = content;
				rle.base.base.base.base.base.contentOffset = contentOffset + 8;
				{
					int bitplane;
					for (bitplane = 0; bitplane < bitplanes; bitplane++) {
						int nextContentOffset;
						if (rle.base.base.base.base.base.contentOffset + 14 > contentLength || !RECOIL_IsStringAt(content, rle.base.base.base.base.base.contentOffset, "VDAT"))
							return FALSE;
						nextContentOffset = rle.base.base.base.base.base.contentOffset + 8 + RECOIL_Get32BigEndian(content, rle.base.base.base.base.base.contentOffset + 4);
						if (nextContentOffset > contentOffset + 8 + chunkLength)
							return FALSE;
						rle.base.valueOffset = rle.base.base.base.base.base.contentLength = rle.base.base.base.base.base.contentOffset + 8 + (content[rle.base.base.base.base.base.contentOffset + 8] << 8) + content[rle.base.base.base.base.base.contentOffset + 9];
						rle.base.valueLength = nextContentOffset;
						rle.base.base.base.base.base.contentOffset += 10;
						{
							int x;
							for (x = bitplane << 1; x < bytesPerLine; x += bitplanes << 1) {
								int unpackedOffset = x;
								{
									int y;
									for (y = 0; y < height; y++) {
										int b = RleStream_ReadRle(&rle.base.base.base);
										if (b < 0)
											return FALSE;
										unpacked[unpackedOffset] = b >> 8;
										unpacked[unpackedOffset + 1] = (unsigned char) b;
										unpackedOffset += bytesPerLine;
									}
								}
							}
						}
						rle.base.base.base.base.base.contentOffset = nextContentOffset;
					}
				}
				RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes);
			}
			else {
				PackBitsStream rle;
				PackBitsStream_Construct(&rle, NULL);
				rle.base.base.base.content = content;
				rle.base.base.base.contentOffset = contentOffset + 8;
				rle.base.base.base.contentLength = contentOffset + 8 + chunkLength;
				if (type == IffType_PBM) {
					if (colors == 0)
						return FALSE;
					RECOIL_SetSize(self, width, height, RECOILResolution_AMIGA1X1);
					{
						int y;
						for (y = 0; y < height; y++) {
							{
								int x;
								for (x = 0; x < width; x++) {
									int b = compression == 0 ? Stream_ReadByte(&rle.base.base.base) : RleStream_ReadRle(&rle.base);
									if (b < 0)
										return FALSE;
									self->pixels[y * width + x] = self->contentPalette[b];
								}
							}
						}
					}
					return TRUE;
				}
				unpacked = (unsigned char *) malloc(bytesPerLine * height * sizeof(unsigned char ));
				{
					int y;
					for (y = 0; y < height; y++) {
						{
							int bitplane;
							for (bitplane = 0; bitplane < bitplanes; bitplane++) {
								{
									int w;
									for (w = bitplane << 1; w < bytesPerLine; w += bitplanes << 1) {
										{
											int x;
											for (x = 0; x < 2; x++) {
												int b = compression == 0 ? Stream_ReadByte(&rle.base.base.base) : RleStream_ReadRle(&rle.base);
												if (b < 0)
													return FALSE;
												unpacked[y * bytesPerLine + w + x] = b;
											}
										}
									}
								}
							}
						}
						if (hasMask) {
							{
								int x;
								for (x = 0; x < width; x += 8) {
									int b = compression == 0 ? Stream_ReadByte(&rle.base.base.base) : RleStream_ReadRle(&rle.base);
									if (b < 0)
										return FALSE;
								}
							}
						}
					}
				}
				RECOIL_SetSize(self, width, height, RECOILResolution_AMIGA1X1);
			}
			return RECOIL_DecodeIffUnpacked(self, unpacked, bitplanes, colors, camg);
		}
		else if (RECOIL_IsStringAt(content, contentOffset, "ABIT")) {
			unsigned char *unpacked;
			if (width == 0 || compression != 0 || chunkLength != (width >> 3) * height * bitplanes)
				return FALSE;
			contentOffset += 8;
			unpacked = (unsigned char *) malloc(chunkLength * sizeof(unsigned char ));
			{
				int bitplane;
				for (bitplane = 0; bitplane < bitplanes; bitplane++) {
					{
						int unpackedOffset;
						for (unpackedOffset = bitplane << 1; unpackedOffset < chunkLength; unpackedOffset += bitplanes << 1) {
							{
								int x;
								for (x = 0; x < 2; x++)
									unpacked[unpackedOffset + x] = content[contentOffset++];
							}
						}
					}
				}
			}
			RECOIL_SetSize(self, width, height, RECOILResolution_AMIGA1X1);
			return RECOIL_DecodeIffUnpacked(self, unpacked, bitplanes, colors, camg);
		}
		contentOffset += 8 + ((chunkLength + 1) & ~1);
	}
	return FALSE;
}

static cibool RECOIL_DecodeIffUnpacked(RECOIL *self, unsigned char *unpacked, int bitplanes, int colors, int camg)
{
	if (bitplanes <= 8) {
		if (colors == 0) {
			colors = 1 << bitplanes;
			{
				int c;
				for (c = 0; c < colors; c++)
					self->contentPalette[c] = c * 255 / colors * 65793;
			}
		}
		else if ((camg & 2176) == 128 && bitplanes == 6 && colors < 64) {
			{
				int c;
				for (c = 0; c < 32; c++)
					self->contentPalette[32 + c] = (self->contentPalette[c] >> 1) & 8355711;
			}
		}
		if ((camg & 2048) != 0) {
			RECOIL_DecodeHam(self, unpacked, bitplanes);
		}
		else {
			RECOIL_DecodeBitplanes(self, unpacked, 0, bitplanes, 0, self->width * self->height);
		}
	}
	else {
		int pixelsCount = self->width * self->height;
		{
			int i;
			for (i = 0; i < pixelsCount; i++) {
				int offset = ((i >> 3) & ~1) * bitplanes + ((i >> 3) & 1);
				int bit = ~i & 7;
				int c = 0;
				{
					int bitplane;
					for (bitplane = 24; --bitplane >= 0;)
						c = (c << 1) | ((unpacked[offset + (bitplane << 1)] >> bit) & 1);
				}
				self->pixels[i] = ((c & 255) << 16) | (c & 65280) | (c >> 16);
			}
		}
	}
	free(unpacked);
	return TRUE;
}

static cibool RECOIL_DecodeIge(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[24576];
	unsigned char frame2[24576];
	if (contentLength != 6160 || content[0] != 255 || content[1] != 255 || content[2] != 246 || content[3] != 163 || content[4] != 255 || content[5] != 187 || content[6] != 255 || content[7] != 95)
		return FALSE;
	RECOIL_SetSize(self, 256, 96, RECOILResolution_XE2X1);
	RECOIL_SetBakPF012(self, content, 8, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 16, 32, frame1, 0, 256, 96);
	RECOIL_SetBakPF012(self, content, 12, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 3088, 32, frame2, 0, 256, 96);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeIhe(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 16194)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 2, -12, 0);
	RECOIL_DecodeC64HiresFrame(self, content, 8194, -12, 64000);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeInfo(RECOIL *self, unsigned char const *content, int contentLength)
{
	static const int os1Palette[4] = { 5614335, 16777215, 0, 16746496 };
	static const int os2Palette[8] = { 9803157, 0, 16777215, 3893154, 8092539, 11513775, 11178108, 16755095 };
	int const *palette;
	int contentOffset;
	int width;
	int height;
	int bitplanes;
	if (contentLength < 98 || content[0] != 227 || content[1] != 16 || content[2] != 0 || content[3] != 1)
		return FALSE;
	switch (RECOIL_Get32BigEndian(content, 44)) {
	case 0:
		palette = os1Palette;
		break;
	case 1:
		palette = os2Palette;
		break;
	default:
		return FALSE;
	}
	contentOffset = RECOIL_Get32BigEndian(content, 66) == 0 ? 78 : 134;
	width = (content[contentOffset + 4] << 8) | content[contentOffset + 5];
	height = (content[contentOffset + 6] << 8) | content[contentOffset + 7];
	bitplanes = (content[contentOffset + 8] << 8) | content[contentOffset + 9];
	switch (bitplanes) {
	case 2:
		break;
	case 3:
		if (palette == os1Palette)
			return FALSE;
		break;
	default:
		return FALSE;
	}
	width = (width + 15) & ~15;
	contentOffset += 20;
	if (contentOffset + height * (width >> 3) > contentLength)
		return FALSE;
	if (!RECOIL_SetSize(self, width, height, RECOILResolution_AMIGA1X1))
		return FALSE;
	{
		int y;
		for (y = 0; y < height; y++) {
			{
				int x;
				for (x = 0; x < width; x++) {
					int bit = ~x & 7;
					int offset = contentOffset + y * (width >> 3) + (x >> 3);
					int c = 0;
					{
						int bitplane;
						for (bitplane = bitplanes; --bitplane >= 0;)
							c = (c << 1) | ((content[offset + bitplane * height * (width >> 3)] >> bit) & 1);
					}
					self->pixels[y * width + x] = palette[c];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeInp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[64000];
	unsigned char frame2[64000];
	if (contentLength < 16004)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1);
	RECOIL_SetBakPF012(self, content, 16000, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame1, 0, 320, 200);
	RECOIL_DecodeAtari8Gr15(self, content, 8000, 40, frame2, 0, 320, 200);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeInt(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentStride;
	int height;
	int width;
	unsigned char frame1[76480];
	unsigned char frame2[76480];
	if (contentLength < 18 || !RECOIL_IsStringAt(content, 0, "INT95a") || content[8] != 15 || content[9] != 43)
		return FALSE;
	contentStride = content[6];
	height = content[7];
	if (contentStride == 0 || contentStride > 320 || height == 0 || height > 239 || 18 + contentStride * height * 2 != contentLength)
		return FALSE;
	width = contentStride << 3;
	RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1);
	RECOIL_SetBakPF012(self, content, 10, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 18, contentStride, frame1, 0, width, height);
	RECOIL_SetBakPF012(self, content, 14, 1);
	RECOIL_DecodeAtari8Gr15(self, content, 18 + contentStride * height, contentStride, frame2, 0, width, height);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeIp2(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[61440];
	unsigned char frame2[61440];
	if (contentLength != 17358 || content[0] != 1)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
	self->gtiaColors[8] = content[1] & 254;
	self->gtiaColors[4] = content[5] & 254;
	self->gtiaColors[5] = content[7] & 254;
	self->gtiaColors[6] = content[9] & 254;
	self->gtiaColors[7] = content[11] & 254;
	RECOIL_DecodeIceFrame(self, content, 16398, 14, frame1, IceFrameMode_GR12);
	self->leftSkip = 2;
	{
		int i;
		for (i = 0; i < 4; i++) {
			self->gtiaColors[i] = content[1 + i] & 254;
			RECOIL_SetGtiaColor(self, 4 + i, content[6 + i * 2]);
		}
	}
	RECOIL_SetGtiaColor(self, 8, content[13]);
	RECOIL_DecodeIceFrame(self, content, 16398, 1038, frame2, IceFrameMode_GR0_GTIA10);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeIph(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 9002:
	case 9003:
	case 9009:
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64HiresFrame(self, content, 2, 8002, 0);
	return TRUE;
}

static cibool RECOIL_DecodeIst(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[64000];
	unsigned char frame2[64000];
	if (contentLength != 17184)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 200; y++) {
			RECOIL_SetBakPF012(self, content, 16384 + y, 200);
			RECOIL_DecodeAtari8Gr15(self, content, 16 + y * 40, 0, frame1, y * 320, 320, 1);
			RECOIL_DecodeAtari8Gr15(self, content, 8208 + y * 40, 0, frame2, y * 320, 320, 1);
		}
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeJgp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char characters[32];
	unsigned char frame[16384];
	if (contentLength != 2054 || RECOIL_ParseAtari8ExecutableHeader(content, 0) != 2048)
		return FALSE;
	{
		int i;
		for (i = 0; i < 32; i++)
			characters[i] = i;
	}
	RECOIL_SetGr15DefaultColors(self);
	RECOIL_SetSize(self, 256, 64, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 8; y++)
			RECOIL_DecodeAtari8Gr12Line(self, characters, 0, content, 6 + ((y & 6) << 7) + ((y & 1) << 10), frame, y << 11);
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeJj(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[9026];
	C64KoalaStream rle;
	if (contentLength < 2)
		return FALSE;
	C64KoalaStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 2;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_UnpackC64(&rle.base, unpacked, 9026) && RECOIL_DecodeDd(self, unpacked, 9026);
}

static cibool RECOIL_DecodeKoa(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 10003:
	case 10006:
		break;
	default:
		return FALSE;
	}
	return RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8002, 9002, content[10002]);
}

static cibool RECOIL_DecodeLeo(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[16384];
	unsigned char characters[32];
	if (contentLength != 2580)
		return FALSE;
	RECOIL_SetSize(self, 256, 64, RECOILResolution_XE2X1);
	RECOIL_SetPF0123Bak(self, content, 2560);
	{
		int y;
		for (y = 0; y < 8; y++) {
			{
				int x;
				for (x = 0; x < 32; x++)
					characters[x] = content[2048 + ((x & 1) << 7) + ((y & 1) << 6) + ((y & 6) << 3) + (x >> 1)];
			}
			RECOIL_DecodeAtari8Gr12Line(self, characters, 0, content, (y & 1) << 10, frame, y << 11);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeLp3(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char colors[4];
	switch (contentLength) {
	case 4098:
	case 4174:
		break;
	default:
		return FALSE;
	}
	if (content[0] != 0 || content[1] != 24)
		return FALSE;
	RECOIL_SetSize(self, 320, 400, RECOILResolution_C642X1);
	if (contentLength == 4174) {
		colors[0] = content[2045] & 15;
		colors[1] = content[2047] & 15;
		colors[2] = content[2048] & 15;
		colors[3] = content[2046] & 7;
	}
	else {
		colors[0] = 0;
		colors[1] = 10;
		colors[2] = 2;
		colors[3] = 1;
	}
	{
		int y;
		for (y = 0; y < 400; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					int c = content[2 + (y >> 3) * 40 + (x >> 3)];
					c = (content[2050 + (c << 3) + (y & 7)] >> (~x & 6)) & 3;
					self->pixels[y * 320 + x] = RECOIL_C64Palette[colors[c]];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeLum(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if (contentLength != 4766)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE4X2);
	self->gtiaColors[8] = 0;
	RECOIL_DecodeAtari8Gr9(self, content, 6, 40, frame, 0, 640, 320, 96);
	RECOIL_DecodeAtari8Gr9(self, content, 6, 40, frame, 320, 640, 320, 96);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMac(RECOIL *self, unsigned char const *content, int contentLength)
{
	PackBitsStream rle;
	unsigned char unpacked[51840];
	if (contentLength < 512 || content[0] != 0 || content[1] != 0 || content[2] != 0 || (content[3] & ~2) != 0)
		return FALSE;
	PackBitsStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 512;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 1, 51840))
		return FALSE;
	return RECOIL_DecodeBlackAndWhite(self, unpacked, 0, 576, 720, 16777215, RECOILResolution_MACINTOSH1X1);
}

static cibool RECOIL_DecodeMax(RECOIL *self, unsigned char const *content, int contentLength)
{
	XlpStream rle;
	unsigned char unpacked[15360];
	unsigned char frame1[61440];
	unsigned char frame2[61440];
	if (contentLength < 1732 || !RECOIL_IsStringAt(content, 0, "XLPM"))
		return FALSE;
	XlpStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 1732;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, 40, 15360))
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 192; y++) {
			RECOIL_SetBakPF012(self, content, 772 + y, 192);
			RECOIL_DecodeAtari8Gr15(self, unpacked, y * 40, 40, frame1, y * 320, 320, 1);
			RECOIL_SetBakPF012(self, content, 4 + y, 192);
			RECOIL_DecodeAtari8Gr15(self, unpacked, 7680 + y * 40, 40, frame2, y * 320, 320, 1);
		}
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeMbg(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[131072];
	if (contentLength != 16384)
		return FALSE;
	RECOIL_SetSize(self, 512, 256, RECOILResolution_XE1X1);
	self->gtiaColors[6] = 0;
	self->gtiaColors[5] = 14;
	RECOIL_DecodeAtari8Gr8(self, content, 0, frame, 0, 256);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMc(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 12288)
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, content, -1, 6144, 0, 0);
	return TRUE;
}

static cibool RECOIL_DecodeMch(RECOIL *self, unsigned char const *content, int contentLength)
{
	int width;
	int charactersStride;
	int charactersOffset;
	unsigned char frame[84480];
	switch (contentLength) {
	case 9840:
		width = 128;
		charactersStride = 32;
		charactersOffset = 0;
		break;
	case 12000:
		width = 160;
		charactersStride = 40;
		charactersOffset = 0;
		break;
	case 14160:
		width = 176;
		charactersStride = 48;
		charactersOffset = 3;
		break;
	default:
		return FALSE;
	}
	RECOIL_SetSize(self, width * 2, 240, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 240; y++) {
			int colorsOffset = contentLength - 1200 + y;
			{
				int x;
				for (x = 0; x < width; x++) {
					int offset = (charactersOffset + (y >> 3) * charactersStride + (x >> 2)) * 9;
					int c = (content[offset + 1 + (y & 7)] >> (~x & 3) * 2) & 3;
					if (c == 3 && content[offset] >= 128)
						c = 4;
					offset = (y * width + x) * 2;
					frame[offset + 1] = frame[offset] = content[colorsOffset + c * 240] & 254;
				}
			}
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMci(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 19434)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_C641X1);
	RECOIL_DecodeC64MulticolorFrame(self, content, 1026, 2, 18434, content[1002], 0);
	self->leftSkip = -1;
	RECOIL_DecodeC64MulticolorFrame(self, content, 9218, 17410, 18434, content[1002], 64000);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeMcp(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 16008)
		return FALSE;
	return RECOIL_DecodeGr15Blend(self, content, 0, 16000, 200);
}

static cibool RECOIL_DecodeMcpp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[64000];
	if (contentLength != 8008)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X2);
	RECOIL_SetPF012Bak(self, content, 8000);
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame, 0, 640, 100);
	RECOIL_SetPF012Bak(self, content, 8004);
	RECOIL_DecodeAtari8Gr15(self, content, 4000, 40, frame, 320, 640, 100);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMcs(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if (contentLength != 10185)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 192; y++) {
			int fontOffset = 9 + (y / 24 << 10);
			{
				int x;
				for (x = 0; x < 320; x++) {
					int ch = content[8201 + (y >> 3) * 40 + (x >> 3)];
					int c;
					switch ((content[fontOffset + ((ch & 127) << 3) + (y & 7)] >> (~x & 6)) & 3) {
						int pmgBit;
						int pmgOffset;
					case 0:
						c = x / 80;
						pmgBit = (x >> 3) % 10;
						if (pmgBit < 8) {
							pmgBit = 7 - pmgBit;
							pmgOffset = 9305 + (c << 7);
						}
						else {
							pmgBit = (c << 1) | (pmgBit ^ 9);
							pmgOffset = 9177;
						}
						if (((content[pmgOffset + (y >> 1)] >> pmgBit) & 1) == 0)
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
					frame[y * 320 + x] = content[c] & 254;
				}
			}
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMg(RECOIL *self, unsigned char const *content, int contentLength)
{
	int attributesMode;
	if (contentLength < 14080 || content[0] != 77 || content[1] != 71 || content[2] != 72 || content[3] != 1)
		return FALSE;
	switch (content[4]) {
	case 1:
		if (contentLength != 19456)
			return FALSE;
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
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
		return FALSE;
	}
	if (contentLength != 12544 + (12288 >> attributesMode))
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, content, 256, 12544, attributesMode, 0);
	RECOIL_DecodeZx(self, content, 6400, 12544 + (6144 >> attributesMode), attributesMode, 49152);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeMgp(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	int rainbow;
	unsigned char bitmap[3840];
	if (contentLength != 3845)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X2);
	RECOIL_SetPF0123Bak(self, content, 0);
	rainbow = content[5];
	memcpy(bitmap + 0, content + 6, 3839);
	bitmap[3839] = 0;
	{
		int y;
		for (y = 0; y < 96; y++) {
			if (rainbow < 4) {
				self->gtiaColors[rainbow == 0 ? 8 : 3 + rainbow] = (16 + y) & 254;
			}
			RECOIL_DecodeAtari8Gr7(self, bitmap, y * 40, frame, y * 640, 1);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMic(RECOIL *self, unsigned char const *content, int contentLength)
{
	int height;
	unsigned char frame[76800];
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
			return FALSE;
		}
	}
	height = contentLength / 40;
	if (height == 0 || height > 240)
		return FALSE;
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1);
	RECOIL_DecodeAtari8Gr15(self, content, 0, 40, frame, 0, 320, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMis(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[960];
	if (contentLength != 61 && contentLength != 241)
		return FALSE;
	RECOIL_SetSize(self, 4, 240, RECOILResolution_XE2X1);
	{
		int y;
		for (y = 0; y < 240; y++) {
			int b = content[1 + (y >> 2)] >> ((~y & 3) << 1);
			frame[y * 4 + 1] = frame[y * 4] = (b & 2) == 0 ? 0 : content[0];
			frame[y * 4 + 3] = frame[y * 4 + 2] = (b & 1) == 0 ? 0 : content[0];
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeMle(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 4098)
		return FALSE;
	RECOIL_SetSize(self, 320, 56, RECOILResolution_C641X1);
	RECOIL_DecodeMleFrame(self, content, 2050, 0);
	self->leftSkip = -1;
	RECOIL_DecodeMleFrame(self, content, 2, 17920);
	return RECOIL_ApplyBlend(self);
}

static void RECOIL_DecodeMleFrame(RECOIL *self, unsigned char const *content, int contentOffset, int pixelsOffset)
{
	{
		int y;
		for (y = 0; y < 56; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					int c = 0;
					int i = x + self->leftSkip;
					if (i >= 0) {
						int ch = (y >> 3) * 40 + (i >> 3);
						if (ch < 256) {
							static const unsigned char colors[4] = { 0, 9, 8, 5 };
							c = colors[(content[contentOffset + (ch << 3) + (y & 7)] >> (~i & 6)) & 3];
						}
					}
					self->pixels[pixelsOffset + y * self->width + x] = RECOIL_C64Palette[c];
				}
			}
		}
	}
}

static cibool RECOIL_DecodeMpp(RECOIL *self, unsigned char const *content, int contentLength)
{
	int mode;
	int width;
	int height;
	static const unsigned char modeColorsPerLine[4] = { 52, 46, 54, 48 };
	int paletteLength;
	int paletteOffset;
	int pixelsLength;
	if (contentLength < 12 || content[0] != 77 || content[1] != 80 || content[2] != 80)
		return FALSE;
	mode = content[3];
	if (mode > 3)
		return FALSE;
	width = mode < 3 ? 320 : 416;
	height = mode < 3 ? 199 : 273;
	paletteLength = modeColorsPerLine[mode] * height;
	switch (content[4] & 3) {
	case 0:
		RECOIL_SetSize(self, width, height, RECOILResolution_ST1X1);
		paletteLength *= 9;
		break;
	case 1:
		RECOIL_SetSize(self, width, height, RECOILResolution_STE1X1);
		paletteLength *= 12;
		break;
	case 3:
		RECOIL_SetSize(self, width, height, RECOILResolution_STE1X1);
		self->frames = 2;
		paletteLength *= 15;
		break;
	default:
		return FALSE;
	}
	paletteLength = (paletteLength + 15) >> 4 << 1;
	paletteOffset = 12 + RECOIL_Get32BigEndian(content, 8);
	pixelsLength = width * height;
	if (contentLength != paletteOffset + ((paletteLength + (pixelsLength >> 1)) << ((content[4] >> 2) & 1)))
		return FALSE;
	RECOIL_DecodeMppScreen(self, content, paletteOffset, paletteLength, 0);
	if ((content[4] & 4) == 0)
		return TRUE;
	RECOIL_DecodeMppScreen(self, content, paletteOffset + paletteLength + (pixelsLength >> 1), paletteLength, pixelsLength);
	return RECOIL_ApplyBlend(self);
}

static void RECOIL_DecodeMppScreen(RECOIL *self, unsigned char const *content, int paletteOffset, int paletteLength, int pixelsOffset)
{
	int mode = content[3];
	int bitmapOffset = paletteOffset + paletteLength;
	int palette[16];
	MppPaletteStream paletteStream;
	memset(palette, 0, sizeof(palette));
	MppPaletteStream_Construct(&paletteStream);
	paletteStream.base.base.content = content;
	paletteStream.base.base.contentOffset = paletteOffset;
	paletteStream.base.base.contentLength = bitmapOffset;
	{
		int y;
		for (y = 0; y < self->height; y++) {
			static const unsigned char firstChangeX[4] = { 33, 9, 4, 69 };
			int changeX;
			int changeColor;
			{
				int c;
				for (c = mode == 3 ? 6 : 1; c < 16; c++)
					palette[c] = MppPaletteStream_Read(&paletteStream);
			}
			changeX = firstChangeX[mode];
			changeColor = 0;
			{
				int x;
				for (x = 0; x < self->width; x++) {
					int offset;
					int bit;
					int c;
					if (x == changeX) {
						static const unsigned char rightBorderColor[4] = { 32, 16, 32, 127 };
						palette[changeColor & 15] = changeColor == rightBorderColor[mode] ? 0 : MppPaletteStream_Read(&paletteStream);
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
						}
						changeColor++;
					}
					offset = bitmapOffset + ((x >> 1) & ~7) + ((x >> 3) & 1);
					bit = ~x & 7;
					c = ((content[offset] >> bit) & 1) | (((content[offset + 2] >> bit) & 1) << 1) | (((content[offset + 4] >> bit) & 1) << 2) | (((content[offset + 6] >> bit) & 1) << 3);
					self->pixels[pixelsOffset + x] = palette[c];
				}
			}
			bitmapOffset += self->width >> 1;
			pixelsOffset += self->width;
		}
	}
}

static cibool RECOIL_DecodeMsp(RECOIL *self, unsigned char const *content, int contentLength)
{
	int width;
	int height;
	int bitmapLength;
	if (contentLength < 32)
		return FALSE;
	width = content[4] | (content[5] << 8);
	height = content[6] | (content[7] << 8);
	width = (width + 7) & ~7;
	bitmapLength = (width >> 3) * height;
	if (RECOIL_IsStringAt(content, 0, "DanM"))
		return contentLength == 32 + bitmapLength && RECOIL_DecodeBlackAndWhite(self, content, 32, width, height, 0, RECOILResolution_PC1X1);
	if (RECOIL_IsStringAt(content, 0, "LinS")) {
		MspStream rle;
		unsigned char *unpacked;
		cibool ok;
		MspStream_Construct(&rle, NULL);
		rle.base.base.base.content = content;
		rle.base.base.base.contentOffset = 32 + (height << 1);
		rle.base.base.base.contentLength = contentLength;
		unpacked = (unsigned char *) malloc(bitmapLength * sizeof(unsigned char ));
		ok = RleStream_Unpack(&rle.base, unpacked, 0, 1, bitmapLength) && RECOIL_DecodeBlackAndWhite(self, unpacked, 0, width, height, 0, RECOILResolution_PC1X1);
		free(unpacked);
		return ok;
	}
	return FALSE;
}

static int RECOIL_DecodeMsxYjk(unsigned char const *content, int i)
{
	int y = content[7 + i] >> 3;
	int k;
	int j;
	int r;
	int g;
	int b;
	int rgb;
	i &= ~3;
	k = (content[i + 7] & 7) | ((content[i + 8] & 7) << 3);
	j = (content[i + 9] & 7) | ((content[i + 10] & 7) << 3);
	k -= (k & 32) << 1;
	j -= (j & 32) << 1;
	r = y + j;
	if (r < 0)
		r = 0;
	else if (r > 31)
		r = 31;
	g = y + k;
	if (g < 0)
		g = 0;
	else if (g > 31)
		g = 31;
	b = (((5 * y - k) >> 1) - j) >> 1;
	if (b < 0)
		b = 0;
	else if (b > 31)
		b = 31;
	rgb = (r << 16) | (g << 8) | b;
	return (rgb << 3) | ((rgb >> 2) & 460551);
}

static cibool RECOIL_DecodeNeo(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 32128 || content[0] != 0 || content[1] != 0 || content[2] != 0)
		return FALSE;
	return RECOIL_DecodeSt(self, content, 128, content, 4, content[3]);
}

static cibool RECOIL_DecodeNlq(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[30720];
	int contentOffset;
	if (contentLength < 379 || !RECOIL_IsStringAt(content, 0, "DAISY-DOT NLQ FONT") || content[18] != 155)
		return FALSE;
	RECOIL_SetSize(self, 320, 96, RECOILResolution_XE1X1);
	memset(frame, 0, sizeof(frame));
	contentOffset = 19;
	{
		int i;
		for (i = 0; i < 91; i++) {
			int width;
			int nextContentOffset;
			int c;
			if (contentOffset >= contentLength)
				return FALSE;
			width = content[contentOffset];
			if (width == 0 || width > 19)
				return FALSE;
			nextContentOffset = contentOffset + (width + 1) * 2;
			if (nextContentOffset > contentLength || content[nextContentOffset - 1] != 155)
				return FALSE;
			c = i < 64 ? i : i < 90 ? i + 1 : 92;
			{
				int y;
				for (y = 0; y < 16; y++) {
					{
						int x;
						for (x = 0; x < width; x++) {
							int b = (content[contentOffset + 1 + (y & 1) * width + x] >> (7 - (y >> 1))) & 1;
							frame[((c & 240) | y) * 320 + (c & 15) * 20 + x] = b == 0 ? 0 : 14;
						}
					}
				}
			}
			contentOffset = nextContentOffset;
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeOcp(RECOIL *self, unsigned char const *content, int contentLength)
{
	return contentLength == 10018 && RECOIL_DecodeC64Multicolor(self, 320, content, 2, 8002, 9018, content[9003]);
}

static cibool RECOIL_DecodeP(RECOIL *self, unsigned char const *content, int contentLength)
{
	PInterpreter interp;
	unsigned char const *font;
	interp.base.content = content;
	interp.base.contentLength = contentLength;
	if (!PInterpreter_Run(&interp))
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_ZX811X1);
	font = CiBinaryResource_zx81_fnt;
	{
		int y;
		for (y = 0; y < 192; y++) {
			{
				int x;
				for (x = 0; x < 256; x++) {
					int c = interp.screen[(y >> 3 << 5) | (x >> 3)];
					int b = (font[((c & 63) << 3) | (y & 7)] >> (~x & 7)) & 1;
					self->pixels[(y << 8) | x] = b == c >> 7 ? 16777215 : 0;
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeP4i(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 10050:
		if (RECOIL_IsStringAt(content, 1020, "MULT")) {
			RECOIL_SetSize(self, 320, 200, RECOILResolution_C162X1);
			RECOIL_SetC16Palette(self);
			{
				int y;
				for (y = 0; y < 200; y++) {
					{
						int x;
						for (x = 0; x < 320; x++) {
							int offset = (y & ~7) * 40 + (x & ~7) + (y & 7);
							int c = (content[2050 + offset] >> (~x & 6)) & 3;
							switch (c) {
							case 0:
								c = content[1025];
								break;
							case 1:
								offset >>= 3;
								c = (content[1026 + offset] & 240) | (content[2 + offset] & 7);
								break;
							case 2:
								offset >>= 3;
								c = ((content[1026 + offset] & 15) << 4) | (content[2 + offset] >> 4);
								break;
							default:
								c = content[1024];
								break;
							}
							self->pixels[y * 320 + x] = self->contentPalette[c];
						}
					}
				}
			}
		}
		else {
			RECOIL_SetSize(self, 320, 200, RECOILResolution_C161X1);
			RECOIL_SetC16Palette(self);
			{
				int y;
				for (y = 0; y < 200; y++) {
					{
						int x;
						for (x = 0; x < 320; x++) {
							int offset = (y & ~7) * 40 + (x & ~7) + (y & 7);
							int c = (content[2050 + offset] >> (~x & 7)) & 1;
							offset >>= 3;
							if (c == 0)
								c = ((content[1026 + offset] & 15) << 4) | (content[2 + offset] >> 4);
							else
								c = (content[1026 + offset] & 240) | (content[2 + offset] & 7);
							self->pixels[y * 320 + x] = self->contentPalette[c];
						}
					}
				}
			}
		}
		break;
	case 2050:
		RECOIL_SetSize(self, 256, 64, RECOILResolution_C162X1);
		RECOIL_SetC16Palette(self);
		{
			int y;
			for (y = 0; y < 64; y++) {
				{
					int x;
					for (x = 0; x < 256; x++) {
						static const unsigned char logoColors[4] = { 0, 19, 21, 23 };
						int c = logoColors[(content[2 + ((x & ~7) << 3) + y] >> (~x & 6)) & 3];
						self->pixels[(y << 8) + x] = self->contentPalette[c];
					}
				}
			}
		}
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

static cibool RECOIL_DecodePac(RECOIL *self, unsigned char const *content, int contentLength)
{
	int unpackedStride;
	PacStream rle;
	unsigned char unpacked[32000];
	if (contentLength < 8 || content[0] != 112 || content[1] != 77 || content[2] != 56)
		return FALSE;
	switch (content[3]) {
	case 53:
		unpackedStride = 1;
		break;
	case 54:
		unpackedStride = 80;
		break;
	default:
		return FALSE;
	}
	PacStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 7;
	rle.base.base.base.contentLength = contentLength;
	if (!RleStream_Unpack(&rle.base, unpacked, 0, unpackedStride, 32000))
		return FALSE;
	return RECOIL_DecodeDoo(self, unpacked, 32000);
}

static cibool RECOIL_DecodePc(RECOIL *self, unsigned char const *content, int contentLength)
{
	int bitplanes;
	PackBitsStream rle;
	unsigned char unpacked[32000];
	if (contentLength < 68 || content[0] != 128 || content[1] > 2)
		return FALSE;
	bitplanes = 4 >> content[1];
	PackBitsStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 34;
	rle.base.base.base.contentLength = contentLength;
	{
		int y;
		for (y = 0; y < 200; y++) {
			{
				int bitplane;
				for (bitplane = 0; bitplane < bitplanes; bitplane++) {
					{
						int x;
						for (x = 0; x < 40 << content[1]; x++) {
							int b = RleStream_ReadRle(&rle.base);
							if (b < 0)
								return FALSE;
							unpacked[y * 160 + (x & ~1) * bitplanes + (bitplane << 1) + (x & 1)] = b;
						}
					}
				}
			}
		}
	}
	return RECOIL_DecodeSt(self, unpacked, 0, content, 2, content[1]);
}

static cibool RECOIL_DecodePcs(RECOIL *self, unsigned char const *content, int contentLength)
{
	PcsStream rle;
	unsigned char unpacked1[51232];
	unsigned char unpacked2[51232];
	if (contentLength < 18 || content[0] != 1 || content[1] != 64 || content[2] != 0 || content[3] != 200)
		return FALSE;
	PcsStream_Construct(&rle, NULL);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = 6;
	rle.base.base.base.base.contentLength = contentLength;
	if (!PcsStream_UnpackPcs(&rle, unpacked1))
		return FALSE;
	RECOIL_SetSize(self, 320, 199, RECOIL_IsStePalette(unpacked1, 32000, 9616) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1);
	RECOIL_DecodePcsScreen(self, unpacked1, 0);
	if (content[4] == 0)
		return TRUE;
	rle.base.base.repeatCount = 0;
	if (!PcsStream_UnpackPcs(&rle, unpacked2))
		return FALSE;
	if ((content[4] & 1) == 0) {
		{
			int i;
			for (i = 0; i < 32000; i++)
				unpacked2[i] ^= unpacked1[i];
		}
	}
	if ((content[4] & 2) == 0) {
		{
			int i;
			for (i = 32000; i < 51232; i++)
				unpacked2[i] ^= unpacked1[i];
		}
	}
	RECOIL_DecodePcsScreen(self, unpacked2, 63680);
	return RECOIL_ApplyBlend(self);
}

static void RECOIL_DecodePcsScreen(RECOIL *self, unsigned char const *unpacked, int pixelsOffset)
{
	{
		int y;
		for (y = 0; y < 199; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					int bitmapOffset = 40 + y * 40 + (x >> 3);
					int bit = ~x & 7;
					int c = (((unpacked[bitmapOffset] >> bit) & 1) << 1) | (((unpacked[8000 + bitmapOffset] >> bit) & 1) << 2) | (((unpacked[16000 + bitmapOffset] >> bit) & 1) << 3) | (((unpacked[24000 + bitmapOffset] >> bit) & 1) << 4);
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
	}
}

static cibool RECOIL_DecodePgc(RECOIL *self, unsigned char const *content, int contentLength)
{
	PgcStream rle;
	unsigned char unpacked[1920];
	if (contentLength < 33 || content[0] != 80 || content[1] != 71 || content[2] != 1)
		return FALSE;
	PgcStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 3;
	rle.base.base.base.contentLength = contentLength;
	{
		int unpackedOffset;
		for (unpackedOffset = 0; unpackedOffset < 1920; unpackedOffset++) {
			int b = RleStream_ReadRle(&rle.base);
			if (b < 0) {
				if (unpackedOffset == 1919)
					b = 0;
				else
					return FALSE;
			}
			unpacked[unpackedOffset] = b;
		}
	}
	return RECOIL_DecodePgf(self, unpacked, 1920);
}

static cibool RECOIL_DecodePgf(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 1920)
		return FALSE;
	return RECOIL_DecodeBlackAndWhite(self, content, 0, 240, 64, 16777215, RECOILResolution_PORTFOLIO1X1);
}

static cibool RECOIL_DecodePi4(RECOIL *self, unsigned char const *content, int contentLength)
{
	int height;
	switch (contentLength) {
	case 65024:
		height = 200;
		break;
	case 77824:
		height = 240;
		break;
	default:
		return FALSE;
	}
	RECOIL_DecodeFalconPalette320(self, content, 1024, 0, height);
	return TRUE;
}

static cibool RECOIL_DecodePic(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[7680];
	if (XeKoalaStream_UnpackWrapped(content, contentLength, unpacked, 7680)) {
		unsigned char frame[61440];
		RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X1);
		RECOIL_SetPF0123Bak(self, content, 13);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, 40, frame, 0, 320, 192);
		return RECOIL_ApplyAtari8Palette(self, frame);
	}
	if (contentLength == 7680)
		return RECOIL_DecodeGr8(self, content, contentLength);
	if (contentLength >= 7681 && contentLength <= 7685)
		return RECOIL_DecodeMic(self, content, contentLength);
	return RECOIL_DecodeDoo(self, content, contentLength) || RECOIL_DecodeSc8(self, content, contentLength);
}

static cibool RECOIL_DecodePl4(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[64070];
	if (!RECOIL_UnpackLz4(self, content, contentLength, unpacked, 64070) || unpacked[0] != 0 || unpacked[1] != 0 || unpacked[32036] != 0 || unpacked[32037] != 0)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOIL_IsStePalette(unpacked, 2, 16) || RECOIL_IsStePalette(unpacked, 32038, 16) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1);
	RECOIL_SetStPalette(self, unpacked, 2, 16);
	RECOIL_DecodeBitplanes(self, unpacked, 34, 4, 0, 64000);
	RECOIL_SetStPalette(self, unpacked, 32038, 16);
	RECOIL_DecodeBitplanes(self, unpacked, 32070, 4, 64000, 64000);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodePla(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[3840];
	if (contentLength != 241)
		return FALSE;
	RECOIL_SetSize(self, 16, 240, RECOILResolution_XE2X1);
	memset(frame, 0, sizeof(frame));
	RECOIL_DecodeAtari8Player(self, content, 1, content[0], frame, 0, 240);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodePmd(RECOIL *self, unsigned char const *content, int contentLength)
{
	int sprites;
	int shapes;
	int totalShapes;
	int height;
	int rows;
	unsigned char frame[179200];
	if (contentLength < 12 || content[0] != 240 || content[1] != 237 || content[2] != 228)
		return FALSE;
	sprites = content[7];
	shapes = content[8] * content[9];
	totalShapes = sprites * shapes;
	height = content[10];
	if (sprites == 0 || sprites > 4 || shapes == 0 || shapes > 160 || height == 0 || height > 48 || 11 + totalShapes * height != contentLength)
		return FALSE;
	if (TRUE)
		totalShapes >>= 1;
	rows = (totalShapes + 15) >> 4;
	if (rows == 1)
		RECOIL_SetSize(self, totalShapes * 20, height, RECOILResolution_XE2X1);
	else {
		int totalHeight = rows * height + (rows - 1) * 2;
		if (totalHeight > 560)
			return FALSE;
		RECOIL_SetSize(self, 320, totalHeight, RECOILResolution_XE2X1);
	}
	memset(frame, 0, sizeof(frame));
	{
		int shape;
		for (shape = 0; shape < totalShapes; shape++) {
			int frameOffset = (shape >> 4) * (height + 2) * 320 + (shape & 15) * 20;
			if (TRUE) {
				int spritePair = shape / shapes;
				int contentOffset = 11 + (spritePair * shapes + shape) * height;
				RECOIL_DecodeAtari8Player(self, content, contentOffset, content[3 + spritePair * 2], frame, frameOffset, height);
				RECOIL_DecodeAtari8Player(self, content, contentOffset + shapes * height, content[4 + spritePair * 2], frame, frameOffset, height);
			}
			else
				RECOIL_DecodeAtari8Player(self, content, 11 + shape * height, content[3 + shape / shapes], frame, frameOffset, height);
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodePmg(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 9332)
		return FALSE;
	return RECOIL_DecodeC64Multicolor(self, 320, content, 116, 8308, -8119, content[8116]);
}

static cibool RECOIL_DecodeRaw(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 15372 || !RECOIL_IsStringAt(content, 0, "XLPB"))
		return FALSE;
	return RECOIL_DecodeGr15Blend(self, content, 4, 15364, 192);
}

static cibool RECOIL_DecodeRip(RECOIL *self, unsigned char const *content, int contentLength)
{
	int headerLength;
	int contentStride;
	int height;
	int textLength;
	int unpackedLength;
	unsigned char unpacked[20076];
	int width;
	unsigned char frame1[76480];
	unsigned char frame2[76480];
	if (contentLength < 34 || content[0] != 82 || content[1] != 73 || content[2] != 80 || content[18] != 84 || content[19] != 58)
		return FALSE;
	headerLength = content[11] | (content[12] << 8);
	contentStride = content[13];
	height = content[15];
	textLength = content[17];
	if (headerLength >= contentLength || contentStride == 0 || contentStride > 80 || (contentStride & 1) != 0 || height == 0 || height > 239 || 33 + textLength >= contentLength || content[20 + textLength] != 9 || !RECOIL_IsStringAt(content, 21 + textLength, "CM:"))
		return FALSE;
	if (content[7] < 16)
		contentStride >>= 1;
	unpackedLength = contentStride * height;
	if (content[7] == 48)
		unpackedLength += (height + 1) >> 1 << 3;
	memset(unpacked, 0, sizeof(unpacked));
	switch (content[9]) {
	case 0:
		if (headerLength + unpackedLength > contentLength)
			return FALSE;
		memcpy(unpacked + 0, content + headerLength, unpackedLength);
		break;
	case 1:
		RECOIL_UnpackRip(self, content, headerLength, contentLength, unpacked, unpackedLength);
		break;
	default:
		return FALSE;
	}
	RECOIL_SetGtiaColors(self, content, 24 + textLength);
	contentStride = content[13] >> 1;
	width = contentStride << 3;
	switch (content[7]) {
		int colorsOffset;
	case 14:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, contentStride, frame1, 0, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 15:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE1X1);
		RECOIL_DecodeAtari8Gr8(self, unpacked, 0, frame1, 0, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 79:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE4X1);
		RECOIL_DecodeAtari8Gr9(self, unpacked, 0, contentStride, frame1, 0, width, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 143:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE4X1);
		self->leftSkip = 2;
		RECOIL_DecodeAtari8Gr10(self, unpacked, 0, frame1, 0, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 207:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE4X1);
		RECOIL_DecodeAtari8Gr11(self, content, 0, frame1, 0, width, height);
		return RECOIL_ApplyAtari8Palette(self, frame1);
	case 30:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, contentStride, frame1, 0, width, height);
		RECOIL_DecodeAtari8Gr15(self, unpacked, height * contentStride, contentStride, frame2, 0, width, height);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	case 16:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1);
		RECOIL_SetBakPF012(self, content, 28 + textLength, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, 0, contentStride << 1, frame1, 0, width << 1, height >> 1);
		RECOIL_SetBakPF012(self, content, 24 + textLength, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, contentStride, contentStride << 1, frame1, width, width << 1, height >> 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, height * contentStride, contentStride << 1, frame2, 0, width << 1, height >> 1);
		RECOIL_SetBakPF012(self, content, 28 + textLength, 1);
		RECOIL_DecodeAtari8Gr15(self, unpacked, (height + 1) * contentStride, contentStride << 1, frame2, width, width << 1, height >> 1);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	case 32:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1);
		self->leftSkip = 1;
		RECOIL_DecodeAtari8Gr10(self, unpacked, 0, frame1, 0, width, height);
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, unpacked, height * contentStride, contentStride, frame2, 0, width, width, height);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	case 48:
		RECOIL_SetSize(self, width, height, RECOILResolution_XE2X1);
		self->leftSkip = 1;
		self->gtiaColors[0] = 0;
		colorsOffset = height * contentStride << 1;
		{
			int y;
			for (y = 0; y < height; y += 2) {
				RECOIL_SetPM123PF0123Bak(self, unpacked, colorsOffset + (y << 2));
				RECOIL_DecodeAtari8Gr10(self, unpacked, y * contentStride, frame1, y * width, width, y + 1 < height ? 2 : 1);
			}
		}
		self->gtiaColors[8] = 0;
		RECOIL_DecodeAtari8Gr9(self, unpacked, height * contentStride, contentStride, frame2, 0, width, width, height);
		return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
	default:
		return FALSE;
	}
}

static cibool RECOIL_DecodeRm(RECOIL *self, unsigned char const *content, int contentLength, int mode, RECOILResolution resolution)
{
	unsigned char unpacked[7680];
	int colorsOffset;
	int dliOffset;
	cibool dliPresent[192];
	int height;
	unsigned char frame[61440];
	if (XeKoalaStream_UnpackWrapped(content, contentLength - 464, unpacked, mode == 0 ? 3840 : 7680)) {
		colorsOffset = contentLength - 464;
		dliOffset = contentLength - 384;
	}
	else if (contentLength == 8192) {
		memcpy(unpacked + 0, content + 0, 7680);
		colorsOffset = 7680;
		dliOffset = 7808;
	}
	else
		return FALSE;
	memset(dliPresent, 0, sizeof(dliPresent));
	{
		int i;
		for (i = 0; i < 128; i++) {
			int y = content[dliOffset + i];
			switch (y) {
			case 0:
				break;
			case 1:
			case 2:
			case 4:
			case 5:
				return FALSE;
			default:
				if (mode == 0) {
					if (y >= 101)
						return FALSE;
					if (y == 3)
						y = 0;
					else
						y -= 5;
				}
				else {
					if (y == 100 || y == 101 || y >= 198)
						return FALSE;
					if (y == 3)
						y = 1;
					else if (y < 100)
						y -= 4;
					else
						y -= 6;
				}
				dliPresent[y] = TRUE;
				break;
			}
		}
	}
	RECOIL_SetSize(self, 320, 192, resolution);
	if (mode == 2)
		self->leftSkip = 2;
	if (mode == 1)
		self->gtiaColors[8] = content[colorsOffset + 8] & 240;
	else
		RECOIL_SetGtiaColors(self, content, colorsOffset);
	height = mode == 0 ? 96 : 192;
	{
		int y;
		for (y = 0; y < height; y++) {
			switch (mode) {
			case 0:
				RECOIL_DecodeAtari8Gr7(self, unpacked, y * 40, frame, y * 640, 1);
				break;
			case 1:
				RECOIL_DecodeAtari8Gr9(self, unpacked, y * 40, 40, frame, y * 320, 320, 320, 1);
				break;
			case 2:
				RECOIL_DecodeAtari8Gr10(self, unpacked, y * 40, frame, y * 320, 320, 1);
				break;
			case 3:
				RECOIL_DecodeAtari8Gr11(self, unpacked, y * 40, frame, y * 320, 320, 1);
				break;
			case 4:
				RECOIL_DecodeAtari8Gr15(self, unpacked, y * 40, 40, frame, y * 320, 320, 1);
				break;
			}
			if (dliPresent[y]) {
				int vcount = mode == 0 ? 16 + y : 16 + ((y - 1) >> 1);
				int reg = content[dliOffset + 128 + vcount];
				if (reg < 9)
					RECOIL_SetGtiaColor(self, reg, content[dliOffset + 256 + vcount]);
				else if (reg != 128)
					return FALSE;
			}
		}
	}
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeRys(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame[61440];
	if (contentLength != 3840)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE2X2);
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 40;
	self->gtiaColors[5] = 202;
	self->gtiaColors[6] = 148;
	RECOIL_DecodeAtari8Gr7(self, content, 0, frame, 0, 96);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeSc2(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 14343 || content[0] != 254 || !RECOIL_ExpectMsxHeader(content, 14336))
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_MSX1X1);
	{
		int y;
		for (y = 0; y < 192; y++) {
			int fontOffset = 7 + ((y & 192) << 5);
			{
				int x;
				for (x = 0; x < 256; x++) {
					int b = fontOffset + (content[6151 + ((y & ~7) << 2) + (x >> 3)] << 3) + (y & 7);
					int c = content[8192 + b];
					static const int palette[16] = { 0, 0, 4110409, 7655549, 5854688, 8419057, 12148305, 6675439, 14378329, 16746877, 13419358, 14602375, 3842625, 12019381, 13421772, 16777215 };
					self->pixels[(y << 8) + x] = palette[((content[b] >> (~x & 7)) & 1) == 0 ? c & 15 : c >> 4];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeSc8(RECOIL *self, unsigned char const *content, int contentLength)
{
	return RECOIL_ExpectMsx2(content, contentLength) && RECOIL_DecodeValidSc8(self, content);
}

static cibool RECOIL_DecodeSca(RECOIL *self, unsigned char const *content, int contentLength)
{
	int palette[16];
	if (contentLength != 64263 || RECOIL_GetMsxHeader(content) < 54272)
		return FALSE;
	{
		int i;
		for (i = 0; i < 16; i++) {
			int rb = content[64135 + (i << 1)];
			int g = content[64136 + (i << 1)];
			int rgb = ((rb & 112) << 12) | (rb & 7) | ((g & 7) << 8);
			palette[i] = (rgb << 5) | (rgb << 2) | ((rgb >> 1) & 197379);
		}
	}
	RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX1X1);
	{
		int i;
		for (i = 0; i < 54272; i++) {
			int c = content[7 + i];
			if ((c & 8) == 0)
				c = RECOIL_DecodeMsxYjk(content, i);
			else
				c = palette[c >> 4];
			self->pixels[i] = c;
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeScc(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (!RECOIL_ExpectMsx2(content, contentLength))
		return FALSE;
	RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX1X1);
	{
		int i;
		for (i = 0; i < 54272; i++)
			self->pixels[i] = RECOIL_DecodeMsxYjk(content, i);
	}
	return TRUE;
}

static cibool RECOIL_DecodeScr(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 6144:
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
		RECOIL_DecodeZx(self, content, 0, -1, -3, 0);
		return TRUE;
	case 6912:
	case 6913:
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
		RECOIL_DecodeZx(self, content, 0, 6144, 3, 0);
		return TRUE;
	case 12288:
		RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
		RECOIL_DecodeZx(self, content, 0, 6144, -1, 0);
		return TRUE;
	default:
		return RECOIL_DecodeAmstradScr(self, content, contentLength);
	}
}

static cibool RECOIL_DecodeScs4(RECOIL *self, unsigned char const *content, int contentLength)
{
	int palette[16];
	if (contentLength != 24617 || content[24616] != 255)
		return FALSE;
	{
		int i;
		for (i = 0; i < 16; i++) {
			int c = content[24576 + i];
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
			palette[i] = rgb;
		}
	}
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SAM_COUPE1X1);
	{
		int y;
		for (y = 0; y < 192; y++) {
			{
				int x;
				for (x = 0; x < 256; x++) {
					int c = content[(y << 7) + (x >> 1)];
					if ((x & 1) == 0)
						c >>= 4;
					self->pixels[(y << 8) + x] = palette[c & 15];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeSge(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char font[1024];
	unsigned char frame[61440];
	if (contentLength != 960)
		return FALSE;
	memcpy(font + 0, CiBinaryResource_atari8_fnt + 0, 1024);
	{
		int i;
		for (i = 0; i < 4; i++) {
			font[1004 + i] = font[728 + i] = 15;
			font[1000 + i] = font[732 + i] = 240;
		}
	}
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1);
	RECOIL_DecodeAtari8Gr0(self, content, 40, font, 0, frame);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeShc(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[61440];
	unsigned char frame2[61440];
	int col1;
	int col2;
	if (contentLength != 17920)
		return FALSE;
	RECOIL_SetSize(self, 320, 192, RECOILResolution_XE1X1);
	col1 = 15360;
	col2 = 16640;
	{
		int y;
		for (y = 0; y < 192; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
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
					frame1[i] = content[col1] & (((content[i >> 3] >> bit) & 1) != 0 ? 240 : 254);
					frame2[i] = content[col2] & (((content[7680 + (i >> 3)] >> bit) & 1) != 0 ? 240 : 254);
				}
			}
			col1++;
			col2++;
		}
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeShp(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 1024:
		return RECOIL_DecodeBlazingPaddlesVectors(self, content, contentLength, 31744);
	case 4384:
		return RECOIL_DecodeGr7(self, content, 528, 3844);
	default:
		return FALSE;
	}
}

static cibool RECOIL_DecodeShr(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 32768)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_APPLE_I_I1X1);
	{
		int c;
		for (c = 0; c < 256; c++) {
			int gb = content[32256 + (c << 1)];
			int r = content[32257 + (c << 1)] & 15;
			int g = gb >> 4;
			int b = gb & 15;
			int rgb = (r << 16) | (g << 8) | b;
			rgb |= rgb << 4;
			self->contentPalette[c] = rgb;
		}
	}
	{
		int y;
		for (y = 0; y < 200; y++) {
			int linePalette = (content[32000 + y] & 15) << 4;
			{
				int x;
				for (x = 0; x < 320; x++) {
					int b = content[y * 160 + (x >> 1)];
					int c = (x & 1) == 0 ? b >> 4 : b & 15;
					self->pixels[y * 320 + x] = self->contentPalette[linePalette + c];
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeSif(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[8192];
	unsigned char frame2[8192];
	unsigned char characters[32];
	if (contentLength != 2048)
		return FALSE;
	RECOIL_SetSize(self, 256, 32, RECOILResolution_XE2X1);
	self->gtiaColors[4] = 76;
	self->gtiaColors[5] = 204;
	self->gtiaColors[6] = 140;
	self->gtiaColors[8] = 0;
	{
		int i;
		for (i = 0; i < 32; i++)
			characters[i] = i;
	}
	{
		int y;
		for (y = 0; y < 4; y++) {
			RECOIL_DecodeAtari8Gr12Line(self, characters, 0, content, y << 8, frame1, y << 11);
			RECOIL_DecodeAtari8Gr12Line(self, characters, 0, content, 1024 + (y << 8), frame2, y << 11);
		}
	}
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeSps(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[51104];
	SpsStream rle;
	BitStream bitStream;
	if (contentLength < 13 || content[0] != 83 || content[1] != 80 || content[2] != 0 || content[3] != 0)
		return FALSE;
	SpsStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 12;
	rle.base.base.base.contentLength = contentLength;
	if ((content[contentLength - 1] & 1) == 0) {
		{
			int bitplane;
			for (bitplane = 0; bitplane < 8; bitplane += 2) {
				{
					int x;
					for (x = 0; x < 40; x++) {
						{
							int unpackedOffset;
							for (unpackedOffset = 160 + ((x & ~1) << 2) + bitplane + (x & 1); unpackedOffset < 32000; unpackedOffset += 160) {
								int b = RleStream_ReadRle(&rle.base);
								if (b < 0)
									return FALSE;
								unpacked[unpackedOffset] = b;
							}
						}
					}
				}
			}
		}
	}
	else {
		if (!RECOIL_UnpackSpc(&rle.base, unpacked))
			return FALSE;
	}
	BitStream_Construct(&bitStream);
	bitStream.base.content = content;
	bitStream.base.contentOffset = 12 + RECOIL_Get32BigEndian(content, 4);
	bitStream.base.contentLength = contentLength;
	{
		int unpackedOffset;
		for (unpackedOffset = 32000; unpackedOffset < 51104;) {
			int got = BitStream_ReadBits(&bitStream, 14);
			if (got < 0)
				return FALSE;
			got <<= 1;
			{
				int i;
				for (i = 15; i >= 0; i--) {
					int rgb;
					if (((got >> i) & 1) == 0)
						rgb = 0;
					else {
						rgb = BitStream_ReadBits(&bitStream, 9);
						if (rgb < 0)
							return FALSE;
					}
					unpacked[unpackedOffset] = rgb >> 6;
					unpacked[unpackedOffset + 1] = (rgb & 63) + (rgb & 56);
					unpackedOffset += 2;
				}
			}
		}
	}
	return RECOIL_DecodeSpu(self, unpacked, 51104);
}

static cibool RECOIL_DecodeSpu(RECOIL *self, unsigned char const *content, int contentLength)
{
	int pixelsOffset;
	if (contentLength != 51104)
		return FALSE;
	RECOIL_SetSize(self, 320, 199, RECOIL_IsStePalette(content, 32000, 9552) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1);
	pixelsOffset = 0;
	{
		int y;
		for (y = 0; y < 199; y++) {
			{
				int x;
				for (x = 0; x < 320; x++) {
					int bitmapOffset = 160 + ((pixelsOffset >> 1) & ~7) + ((x >> 3) & 1);
					int bit = ~x & 7;
					int c = (((content[bitmapOffset] >> bit) & 1) << 1) | (((content[bitmapOffset + 2] >> bit) & 1) << 2) | (((content[bitmapOffset + 4] >> bit) & 1) << 3) | (((content[bitmapOffset + 6] >> bit) & 1) << 4);
					int x1 = c * 5 + 1 - (c & 2) * 3;
					if (x >= x1 + 160)
						c += 64;
					else if (x >= x1)
						c += 32;
					self->pixels[pixelsOffset++] = RECOIL_GetStColor(self, content, 32000 + y * 96 + c);
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeSr8(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[54279];
	Sr8Stream rle;
	if (contentLength < 7)
		return FALSE;
	if (content[0] != 253)
		return RECOIL_DecodeSc8(self, content, contentLength);
	if (RECOIL_GetMsxHeader(content) + 7 != contentLength)
		return FALSE;
	Sr8Stream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 7;
	rle.base.base.base.contentLength = contentLength;
	return RleStream_Unpack(&rle.base, unpacked, 7, 1, 54272) && RECOIL_DecodeValidSc8(self, unpacked);
}

static cibool RECOIL_DecodeSt(RECOIL *self, unsigned char const *bitmap, int bitmapOffset, unsigned char const *palette, int paletteOffset, int mode)
{
	switch (mode) {
	case 0:
		return RECOIL_DecodeStLow(self, bitmap, bitmapOffset, palette, paletteOffset, 320, 200);
	case 1:
		RECOIL_DecodeStMedium(self, bitmap, bitmapOffset, palette, paletteOffset, 640, 200, 0);
		return TRUE;
	case 2:
		return RECOIL_DecodeBlackAndWhite(self, bitmap, bitmapOffset, 640, 400, 16777215, RECOILResolution_ST1X1);
	default:
		return FALSE;
	}
}

static cibool RECOIL_DecodeStIcn(RECOIL *self, unsigned char const *content, int contentLength)
{
	IcnParser parser;
	int width;
	int height;
	int size;
	unsigned char bitmap[8192];
	parser.base.content = content;
	parser.base.contentOffset = 0;
	parser.base.contentLength = contentLength;
	width = IcnParser_ParseDefine(&parser, "ICON_W");
	if (width <= 0 || width >= 256)
		return FALSE;
	height = IcnParser_ParseDefine(&parser, "ICON_H");
	if (height <= 0 || height >= 256)
		return FALSE;
	size = IcnParser_ParseDefine(&parser, "ICONSIZE");
	if (size != ((width + 15) >> 4) * height)
		return FALSE;
	if (!IcnParser_Expect(&parser, "int") || !IcnParser_Expect(&parser, "image[ICONSIZE]") || !IcnParser_Expect(&parser, "=") || !IcnParser_Expect(&parser, "{"))
		return FALSE;
	{
		int i;
		for (i = 0;;) {
			int value = IcnParser_ParseHex(&parser);
			if (value < 0)
				return FALSE;
			bitmap[i * 2] = value >> 8;
			bitmap[i * 2 + 1] = (unsigned char) value;
			if (++i >= size)
				break;
			if (parser.base.contentOffset >= contentLength || content[parser.base.contentOffset++] != 44)
				return FALSE;
		}
	}
	if (!IcnParser_Expect(&parser, "};"))
		return FALSE;
	return RECOIL_DecodeBlackAndWhite(self, bitmap, 0, (width + 15) & ~15, height, 16777215, RECOILResolution_ST1X1);
}

static cibool RECOIL_DecodeStImg(RECOIL *self, unsigned char const *content, int contentLength)
{
	int headerLength;
	int bitplanes;
	int width;
	int height;
	ImgStream rle;
	unsigned char unpacked[2048];
	if (contentLength < 17 || content[0] != 0 || content[1] != 1 || content[4] != 0)
		return FALSE;
	headerLength = ((content[2] << 8) | content[3]) << 1;
	if (headerLength < 16 || headerLength >= contentLength)
		return FALSE;
	bitplanes = content[5];
	width = (((content[12] << 8) | content[13]) + 7) & ~7;
	height = (content[14] << 8) | content[15];
	switch (bitplanes) {
	case 1:
		self->contentPalette[0] = 16777215;
		self->contentPalette[1] = 0;
		break;
	case 2:
	case 4:
	case 8:
		if (headerLength == 22 + (6 << bitplanes) && RECOIL_IsStringAt(content, 16, "XIMG") && content[20] == 0 && content[21] == 0) {
			{
				int i;
				for (i = 0; i < 1 << bitplanes; i++) {
					int rgb = RECOIL_GetStColor1000(content, 22 + i * 6);
					if (rgb < 0)
						return FALSE;
					self->contentPalette[i] = rgb;
				}
			}
		}
		else
			return FALSE;
		break;
	default:
		return FALSE;
	}
	if (!RECOIL_SetSizeStOrFalcon(self, width, height, bitplanes))
		return FALSE;
	ImgStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = headerLength;
	rle.base.base.base.contentLength = contentLength;
	{
		int y;
		for (y = 0; y < height;) {
			int lineRepeatCount = ImgStream_GetLineRepeatCount(&rle);
			{
				int bitplane;
				for (bitplane = 0; bitplane < bitplanes; bitplane++) {
					{
						int x;
						for (x = 0; x < width >> 3; x++) {
							int b = RleStream_ReadRle(&rle.base);
							if (b < 0)
								return FALSE;
							unpacked[(x & ~1) * bitplanes + (bitplane << 1) + (x & 1)] = b;
						}
					}
				}
			}
			do
				RECOIL_DecodeBitplanes(self, unpacked, 0, bitplanes, y * width, width);
			while (++y < height && --lineRepeatCount > 0);
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeStLow(RECOIL *self, unsigned char const *bitmap, int bitmapOffset, unsigned char const *palette, int paletteOffset, int width, int height)
{
	RECOIL_SetSize(self, width, height, RECOIL_IsStePalette(palette, paletteOffset, 16) ? RECOILResolution_STE1X1 : RECOILResolution_ST1X1);
	RECOIL_SetStPalette(self, palette, paletteOffset, 16);
	RECOIL_DecodeBitplanes(self, bitmap, bitmapOffset, 4, 0, width * height);
	return TRUE;
}

static void RECOIL_DecodeStMedium(RECOIL *self, unsigned char const *bitmap, int bitmapOffset, unsigned char const *palette, int paletteOffset, int width, int height, int blend)
{
	RECOIL_SetSize(self, width, height << 1, RECOIL_IsStePalette(palette, paletteOffset, 4) ? RECOILResolution_STE1X2 : RECOILResolution_ST1X2);
	RECOIL_SetStPalette(self, palette, paletteOffset, 4);
	height <<= blend;
	{
		int y;
		for (y = 0; y < height; y++) {
			int lineOffset = y * width;
			{
				int x;
				for (x = 0; x < width; x++) {
					int offset = bitmapOffset + (lineOffset >> 2) + ((x >> 2) & ~3) + ((x >> 3) & 1);
					int bit = ~x & 7;
					int c = ((bitmap[offset] >> bit) & 1) | (((bitmap[offset + 2] >> bit) & 1) << 1);
					int pixelsOffset = (lineOffset << 1) + x;
					self->pixels[pixelsOffset + width] = self->pixels[pixelsOffset] = self->contentPalette[c];
				}
			}
		}
	}
}

static cibool RECOIL_DecodeStPi(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength < 32034 || content[0] != 0)
		return FALSE;
	switch (contentLength) {
	case 32034:
	case 32066:
	case 32128:
		return RECOIL_DecodeSt(self, content, 34, content, 2, content[1]);
	case 44834:
		if (content[1] != 0)
			return FALSE;
		return RECOIL_DecodeStLow(self, content, 34, content, 2, 320, 280);
	case 116514:
		if (content[1] != 0)
			return FALSE;
		return RECOIL_DecodeStLow(self, content, 34, content, 2, 416, 560);
	default:
		return FALSE;
	}
}

static cibool RECOIL_DecodeStSpc(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char unpacked[51104];
	SpcStream rle;
	int contentOffset;
	if (contentLength < 12 || content[0] != 83 || content[1] != 80)
		return FALSE;
	SpcStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = 12;
	rle.base.base.base.contentLength = contentLength;
	if (!RECOIL_UnpackSpc(&rle.base, unpacked))
		return FALSE;
	contentOffset = 12 + RECOIL_Get32BigEndian(content, 4);
	{
		int unpackedOffset;
		for (unpackedOffset = 32000; unpackedOffset < 51104;) {
			int got;
			if (contentOffset + 1 >= contentLength)
				return FALSE;
			got = (content[contentOffset] << 8) | content[contentOffset + 1];
			contentOffset += 2;
			{
				int i;
				for (i = 0; i < 16; i++) {
					if (((got >> i) & 1) == 0) {
						unpacked[unpackedOffset] = 0;
						unpacked[unpackedOffset + 1] = 0;
					}
					else {
						if (contentOffset + 1 >= contentLength)
							return FALSE;
						unpacked[unpackedOffset] = content[contentOffset];
						unpacked[unpackedOffset + 1] = content[contentOffset + 1];
						contentOffset += 2;
					}
					unpackedOffset += 2;
				}
			}
		}
	}
	return RECOIL_DecodeSpu(self, unpacked, 51104);
}

static cibool RECOIL_DecodeSxs(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char characters[128];
	if (contentLength != 1030 || RECOIL_ParseAtari8ExecutableHeader(content, 0) != 1024)
		return FALSE;
	{
		int i;
		for (i = 0; i < 128; i++)
			characters[i] = (i & 65) | ((i >> 4) & 2) | ((i & 30) << 1);
	}
	return RECOIL_DecodeAtari8Font(self, characters, content, 6);
}

static cibool RECOIL_DecodeTip(RECOIL *self, unsigned char const *content, int contentLength)
{
	int width;
	int height;
	int contentStride;
	int frameLength;
	static const unsigned char colors[9] = { 0, 2, 4, 6, 8, 10, 12, 14, 0 };
	unsigned char frame1[76160];
	unsigned char frame2[76160];
	if (contentLength < 129 || content[0] != 84 || content[1] != 73 || content[2] != 80 || content[3] != 1 || content[4] != 0)
		return FALSE;
	width = content[5];
	height = content[6];
	if (width > 160 || (width & 3) != 0 || height > 119)
		return FALSE;
	contentStride = width >> 2;
	frameLength = content[7] | (content[8] << 8);
	if (frameLength != contentStride * height || contentLength != 9 + 3 * frameLength)
		return FALSE;
	RECOIL_SetSize(self, width << 1, height << 1, RECOILResolution_XE2X2);
	self->leftSkip = 1;
	RECOIL_SetGtiaColors(self, colors, 0);
	RECOIL_DecodeAtari8Gr9(self, content, 9, contentStride, frame1, width << 1, width << 2, width << 1, height);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9 + 2 * frameLength, contentStride, frame1, 0);
	RECOIL_DecodeAtari8Gr10(self, content, 9 + frameLength, frame2, width << 1, width << 2, height);
	RECOIL_DecodeAtari8Gr11PalBlend(self, content, 9 + 2 * frameLength, contentStride, frame2, 0);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeTny(RECOIL *self, unsigned char const *content, int contentLength)
{
	int mode;
	int contentOffset;
	int controlLength;
	int valueLength;
	TnyStream rle;
	unsigned char unpacked[32000];
	if (contentLength < 42)
		return FALSE;
	mode = content[0];
	if (mode > 2) {
		if (mode > 5)
			return FALSE;
		mode -= 3;
		contentOffset = 4;
	}
	else
		contentOffset = 0;
	controlLength = (content[contentOffset + 33] << 8) | content[contentOffset + 34];
	valueLength = ((content[contentOffset + 35] << 8) | content[contentOffset + 36]) << 1;
	if (contentOffset + 37 + controlLength + valueLength > contentLength)
		return FALSE;
	TnyStream_Construct(&rle, NULL);
	rle.base.base.base.base.content = content;
	rle.base.base.base.base.contentOffset = contentOffset + 37;
	rle.valueOffset = rle.base.base.base.base.contentLength = contentOffset + 37 + controlLength;
	rle.valueLength = contentOffset + 37 + controlLength + valueLength;
	{
		int bitplane;
		for (bitplane = 0; bitplane < 8; bitplane += 2) {
			{
				int x;
				for (x = bitplane; x < 160; x += 8) {
					{
						int unpackedOffset;
						for (unpackedOffset = x; unpackedOffset < 32000; unpackedOffset += 160) {
							int b = RleStream_ReadRle(&rle.base.base);
							if (b < 0)
								return FALSE;
							unpacked[unpackedOffset] = b >> 8;
							unpacked[unpackedOffset + 1] = (unsigned char) b;
						}
					}
				}
			}
		}
	}
	return RECOIL_DecodeSt(self, unpacked, 0, content, contentOffset + 1, mode);
}

static cibool RECOIL_DecodeTrp(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength < 9 || !RECOIL_IsStringAt(content, 0, "TRUP"))
		return FALSE;
	return RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 4, 8);
}

static cibool RECOIL_DecodeTru(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength < 256 || !RECOIL_IsStringAt(content, 0, "Indy"))
		return FALSE;
	return RECOIL_DecodeFalconTrueColorVariable(self, content, contentLength, 4, 256);
}

static cibool RECOIL_DecodeValidSc8(RECOIL *self, unsigned char const *content)
{
	int palette[256];
	{
		int c;
		for (c = 0; c < 256; c++) {
			palette[c] = ((c & 28) * 72 >> 3 << 16) | ((c >> 5) * 72 >> 1 << 8) | (c & 3) * 85;
		}
	}
	RECOIL_SetSize(self, 256, 212, RECOILResolution_MSX1X1);
	{
		int i;
		for (i = 0; i < 54272; i++)
			self->pixels[i] = palette[content[7 + i]];
	}
	return TRUE;
}

static cibool RECOIL_DecodeVic(RECOIL *self, unsigned char const *content, int contentLength)
{
	switch (contentLength) {
	case 9002:
	case 9003:
	case 9009:
		return RECOIL_DecodeIph(self, content, contentLength);
	case 10018:
		return RECOIL_DecodeOcp(self, content, contentLength);
	case 10241:
	case 10242:
		return RECOIL_DecodeDol(self, content, contentLength);
	case 17218:
	case 17409:
	case 17410:
		return RECOIL_DecodeFli(self, content, contentLength);
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
		return RECOIL_DecodeFun(self, content, contentLength);
	default:
		return FALSE;
	}
}

static cibool RECOIL_DecodeVzi(RECOIL *self, unsigned char const *content, int contentLength)
{
	unsigned char frame1[64000];
	unsigned char frame2[64000];
	if (contentLength != 16000)
		return FALSE;
	RECOIL_SetSize(self, 320, 200, RECOILResolution_XE2X1);
	self->leftSkip = -1;
	RECOIL_DecodeAtari8Gr9(self, content, 0, 40, frame1, 0, 320, 320, 200);
	self->leftSkip = 1;
	RECOIL_DecodeAtari8Gr9(self, content, 8000, 40, frame2, 0, 320, 320, 200);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static cibool RECOIL_DecodeWnd(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentStride;
	int height;
	unsigned char frame[61440];
	if (contentLength != 3072)
		return FALSE;
	contentStride = (content[0] >> 2) + 1;
	height = content[1];
	if (contentStride > 40 || height == 0 || height > 192 || contentStride * height > 3070)
		return FALSE;
	RECOIL_SetSize(self, contentStride << 3, height, RECOILResolution_XE2X1);
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 70;
	self->gtiaColors[5] = 136;
	self->gtiaColors[6] = 14;
	RECOIL_DecodeAtari8Gr15(self, content, 2, contentStride, frame, 0, contentStride << 3, height);
	return RECOIL_ApplyAtari8Palette(self, frame);
}

static cibool RECOIL_DecodeXlp(RECOIL *self, unsigned char const *content, int contentLength)
{
	XlpStream rle;
	unsigned char unpacked[16000];
	int height;
	int colorsOffset;
	unsigned char frame1[64000];
	unsigned char frame2[64000];
	XlpStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentLength = contentLength;
	if (contentLength >= 10 && RECOIL_IsStringAt(content, 0, "XLPC")) {
		memset(unpacked, 0, sizeof(unpacked));
		rle.base.base.base.contentOffset = 8;
		RleStream_Unpack(&rle.base, unpacked, 0, 40, 15360);
		height = 192;
		colorsOffset = 4;
	}
	else {
		rle.base.base.base.contentOffset = 4;
		if (RleStream_Unpack(&rle.base, unpacked, 0, 40, 16000))
			height = 200;
		else {
			rle.base.base.base.contentOffset = 4;
			if (RleStream_Unpack(&rle.base, unpacked, 0, 40, 15360))
				height = 192;
			else
				return FALSE;
		}
		colorsOffset = 0;
	}
	RECOIL_SetSize(self, 320, height, RECOILResolution_XE2X1);
	RECOIL_SetPF012Bak(self, content, colorsOffset);
	RECOIL_DecodeAtari8Gr15(self, unpacked, 0, 40, frame1, 0, 320, height);
	RECOIL_DecodeAtari8Gr15(self, unpacked, height * 40, 40, frame2, 0, 320, height);
	return RECOIL_ApplyAtari8PaletteBlend(self, frame1, frame2);
}

static void RECOIL_DecodeZx(RECOIL *self, unsigned char const *content, int bitmapOffset, int attributesOffset, int attributesMode, int pixelsOffset)
{
	{
		int y;
		for (y = 0; y < 192; y++) {
			{
				int x;
				for (x = 0; x < 256; x++) {
					int col = x >> 3;
					static const int palette[16] = { 0, 205, 13434880, 13435085, 52480, 52685, 13487360, 13487565, 0, 255, 16711680, 16711935, 65280, 65535, 16776960, 16777215 };
					int c;
					switch (bitmapOffset) {
					case -3:
						c = x ^ y;
						break;
					case -2:
						c = content[84 + (y & 7)] >> (~x & 7);
						break;
					case -1:
						c = content[(y << 5) | col] >> (~x & 7);
						break;
					default:
						c = content[bitmapOffset + ((y & 192) << 5) + ((y & 7) << 8) + ((y & 56) << 2) + col] >> (~x & 7);
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
							a = attributesOffset + ((y & 192) << 5) + ((y & 7) << 8) + ((y & 56) << 2);
							break;
						default:
							a = attributesOffset + (y >> attributesMode << 5);
							break;
						}
						a = content[a + col];
						c = c == 0 ? (a >> 3) & 15 : ((a >> 3) & 8) | (a & 7);
						c = palette[c];
					}
					self->pixels[pixelsOffset + (y << 8) + x] = c;
				}
			}
		}
	}
}

static cibool RECOIL_DecodeZxIfl(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 9216)
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, content, 0, 6144, 1, 0);
	return TRUE;
}

static cibool RECOIL_DecodeZxImg(RECOIL *self, unsigned char const *content, int contentLength)
{
	if (contentLength != 13824)
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, content, 0, 6144, 3, 0);
	RECOIL_DecodeZx(self, content, 6912, 13056, 3, 49152);
	return RECOIL_ApplyBlend(self);
}

static cibool RECOIL_DecodeZxRgb(RECOIL *self, unsigned char const *content, int contentLength)
{
	static const unsigned char frameComponents[3] = { 16, 8, 0 };
	return RECOIL_DecodeZxRgb3(self, content, contentLength, frameComponents);
}

static cibool RECOIL_DecodeZxRgb3(RECOIL *self, unsigned char const *content, int contentLength, unsigned char const *frameComponents)
{
	if (contentLength != 18432)
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	self->frames = 3;
	{
		int y;
		for (y = 0; y < 192; y++) {
			{
				int x;
				for (x = 0; x < 256; x++) {
					int offset = ((y & 192) << 5) | ((y & 7) << 8) | ((y & 56) << 2) | (x >> 3);
					int c = 0;
					{
						int frame;
						for (frame = 0; frame < 3; frame++) {
							if (((content[frame * 6144 + offset] >> (~x & 7)) & 1) != 0)
								c |= 255 << frameComponents[frame];
						}
					}
					self->pixels[(y << 8) + x] = c;
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_DecodeZxp(RECOIL *self, unsigned char const *content, int contentLength)
{
	int contentOffset;
	ZxpStream s;
	unsigned char scr[12288];
	if (contentLength < 51670 || !RECOIL_IsStringAt(content, 0, "ZX-Paintbrush "))
		return FALSE;
	contentOffset = 14;
	if (RECOIL_IsStringAt(content, 14, "extended "))
		contentOffset = 23;
	if (!RECOIL_IsStringAt(content, contentOffset, "image"))
		return FALSE;
	s.base.content = content;
	s.base.contentOffset = contentOffset + 5;
	s.base.contentLength = contentLength;
	if (ZxpStream_ReadChar(&s) != 10 || ZxpStream_ReadChar(&s) != 10)
		return FALSE;
	{
		int y;
		for (y = 0; y < 192; y++) {
			int b = 0;
			{
				int x;
				for (x = 0; x < 256; x++) {
					int bit = ~x & 7;
					switch (ZxpStream_ReadChar(&s)) {
					case 42:
					case 48:
						break;
					case 49:
						b |= 1 << bit;
						break;
					default:
						return FALSE;
					}
					if (bit == 0) {
						scr[(y << 5) | (x >> 3)] = b;
						b = 0;
					}
				}
			}
			if (ZxpStream_ReadChar(&s) != 10)
				return FALSE;
		}
	}
	if (ZxpStream_ReadChar(&s) != 10)
		return FALSE;
	{
		int y;
		for (y = 0; y < 192; y++) {
			if (y == 24 && ZxpStream_IsEof(&s)) {
				RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
				RECOIL_DecodeZx(self, scr, -1, 6144, 3, 0);
				return TRUE;
			}
			{
				int x;
				for (x = 0; x < 32; x++) {
					int hi = ZxpStream_ReadHexDigit(&s);
					int lo;
					if (hi < 0)
						return FALSE;
					lo = ZxpStream_ReadHexDigit(&s);
					if (lo < 0)
						return FALSE;
					scr[6144 + (y << 5) + x] = (hi << 4) + lo;
					if (ZxpStream_ReadChar(&s) != (x < 31 ? 32 : 10))
						return FALSE;
				}
			}
		}
	}
	if (!ZxpStream_IsEof(&s))
		return FALSE;
	RECOIL_SetSize(self, 256, 192, RECOILResolution_SPECTRUM1X1);
	RECOIL_DecodeZx(self, scr, -1, 6144, 0, 0);
	return TRUE;
}

static cibool RECOIL_DrawBlazingPaddlesVector(RECOIL const *self, unsigned char const *content, int contentLength, unsigned char *frame, int frameOffset, int index, int startAddress)
{
	int contentOffset;
	if (index * 2 + 1 >= contentLength)
		return FALSE;
	contentOffset = content[index * 2] + (content[index * 2 + 1] << 8) - startAddress;
	if (contentOffset < 0)
		return FALSE;
	while (contentOffset < contentLength) {
		int control = content[contentOffset++];
		if (control == 8)
			return TRUE;
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
			}
		}
	}
	return FALSE;
}

static void RECOIL_DrawSpcBrush(unsigned char *pixels, int x1, int y1, int brush, int pattern)
{
	static const unsigned char brushes[128] = { 0, 0, 0, 0, 0, 0, 16, 16, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 48, 48, 48, 48, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 16, 56, 56, 56, 56, 16, 0, 0, 0, 0, 0, 0,
		0, 0, 16, 56, 56, 124, 124, 124, 124, 56, 56, 16, 0, 0, 0, 0,
		0, 24, 24, 60, 60, 126, 126, 126, 126, 60, 60, 24, 24, 0, 0, 0,
		16, 56, 124, 124, 124, 254, 254, 254, 254, 124, 124, 124, 56, 16, 0, 0,
		0, 0, 16, 40, 40, 80, 60, 120, 20, 40, 40, 16, 0, 0, 0, 0,
		16, 40, 84, 40, 84, 186, 124, 124, 186, 84, 40, 84, 40, 16, 0, 0 };
	{
		int y;
		for (y = 0; y < 16 && y1 + y < 192; y++) {
			int brushShape = brushes[brush * 16 + y];
			{
				int x;
				for (x = 0; x < 8 && x1 + x < 160; x++) {
					if (((brushShape >> (7 - x)) & 1) != 0)
						RECOIL_PlotSpcPattern(pixels, x, y, pattern);
				}
			}
		}
	}
}

static void RECOIL_DrawSpcChar(unsigned char *pixels, int x1, int y1, int ch)
{
	unsigned char const *font;
	int fontOffset;
	if (ch < 32 || ch > 95)
		return;
	font = CiBinaryResource_atari8_fnt;
	fontOffset = (ch - 32) << 3;
	{
		int y;
		for (y = 0; y < 8 && y1 + y < 192; y++) {
			{
				int x;
				for (x = 0; x < 4 && x1 + x < 160; x++)
					pixels[(y1 + y) * 160 + x1 + x] = (font[fontOffset + y] >> (6 - x * 2)) & 3;
			}
		}
	}
}

static void RECOIL_DrawSpcLine(unsigned char *pixels, int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
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
				pixels[160 * y1 + x1] = color;
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
				pixels[160 * y1 + x1] = color;
			e -= dx * 2;
			if (e < 0) {
				e += dy * 2;
				x1 += x1 < x2 ? 1 : -1;
			}
		}
	}
}

static cibool RECOIL_ExpectMsx2(unsigned char const *content, int contentLength)
{
	return contentLength >= 54279 && content[0] == 254 && RECOIL_ExpectMsxHeader(content, 54272);
}

static cibool RECOIL_ExpectMsxHeader(unsigned char const *content, int expected)
{
	int value = RECOIL_GetMsxHeader(content);
	return value == expected || value == expected - 1;
}

static cibool RECOIL_FillSpc(unsigned char *pixels, int x, int y, int pattern)
{
	if (x >= 160 || y >= 192)
		return FALSE;
	while (y >= 0 && pixels[y * 160 + x] == 0)
		y--;
	while (++y < 192 && pixels[y * 160 + x] == 0) {
		int x1;
		do
			x--;
		while (x >= 0 && pixels[y * 160 + x] == 0);
		x1 = x;
		while (x < 159 && pixels[y * 160 + ++x] == 0)
			RECOIL_PlotSpcPattern(pixels, x, y, pattern);
		x = x1 + ((x - x1 + 1) >> 1);
	}
	return TRUE;
}

static int RECOIL_FindColor(int const *palette, int paletteEnd, int rgb)
{
	int paletteBegin = 0;
	while (paletteBegin < paletteEnd) {
		int index = (paletteBegin + paletteEnd) >> 1;
		int paletteRgb = palette[index];
		if (rgb == paletteRgb)
			return index;
		if (rgb < paletteRgb)
			paletteEnd = index;
		else
			paletteBegin = index + 1;
	}
	return paletteBegin;
}

static int RECOIL_Get32BigEndian(unsigned char const *content, int contentOffset)
{
	return (content[contentOffset] << 24) | (content[contentOffset + 1] << 16) | (content[contentOffset + 2] << 8) | content[contentOffset + 3];
}

static int RECOIL_Get32LittleEndian(unsigned char const *content, int contentOffset)
{
	return content[contentOffset] | (content[contentOffset + 1] << 8) | (content[contentOffset + 2] << 16) | (content[contentOffset + 3] << 24);
}

static int RECOIL_GetAmstradHeader(unsigned char const *content, int contentLength)
{
	int sum;
	if (contentLength < 128 || (content[24] | (content[25] << 8)) != contentLength - 128 || content[64] != content[24] || content[65] != content[25] || content[66] != 0)
		return 0;
	sum = 0;
	{
		int i;
		for (i = 0; i < 67; i++)
			sum += content[i];
	}
	if ((content[67] | (content[68] << 8)) != sum)
		return 0;
	return 128;
}

static int RECOIL_GetAtari8ExecutableOffset(unsigned char const *content, int contentLength)
{
	if (contentLength >= 7) {
		int blockLength = RECOIL_ParseAtari8ExecutableHeader(content, 0);
		if (blockLength > 0 && 6 + blockLength == contentLength)
			return 6;
	}
	return 0;
}

int RECOIL_GetColors(RECOIL *self)
{
	if (self->colors == -1) {
		memset(self->palette, 0, sizeof(self->palette));
		RECOIL_CalculatePalette(self, self->palette, 0, 256);
	}
	if (self->colors == 0) {
		int *palette = (int *) malloc(self->width * self->height * sizeof(int ));
		{
			int j;
			for (j = 0; j < 256; j++)
				palette[j] = self->palette[j];
		}
		RECOIL_CalculatePalette(self, palette, 256, -1);
		free(palette);
	}
	return self->colors;
}

int RECOIL_GetFrames(RECOIL const *self)
{
	return self->frames;
}

int RECOIL_GetHeight(RECOIL const *self)
{
	return self->height;
}

static int RECOIL_GetMsxHeader(unsigned char const *content)
{
	if (content[1] != 0 || content[2] != 0 || content[5] != 0 || content[6] != 0)
		return -1;
	return content[3] | (content[4] << 8);
}

int RECOIL_GetOriginalHeight(RECOIL const *self)
{
	switch (self->resolution) {
	case RECOILResolution_AMSTRAD1X2:
	case RECOILResolution_APPLE_I_I1X2:
	case RECOILResolution_XE2X2:
	case RECOILResolution_XE4X2:
	case RECOILResolution_ST1X2:
	case RECOILResolution_STE1X2:
	case RECOILResolution_BBC1X2:
		return self->height >> 1;
	default:
		return self->height;
	}
}

int RECOIL_GetOriginalWidth(RECOIL const *self)
{
	switch (self->resolution) {
	case RECOILResolution_XE2X1:
	case RECOILResolution_XE2X2:
	case RECOILResolution_BBC2X1:
	case RECOILResolution_C162X1:
	case RECOILResolution_C642X1:
		return self->width >> 1;
	case RECOILResolution_XE4X1:
	case RECOILResolution_XE4X2:
		return self->width >> 2;
	default:
		return self->width;
	}
}

static int RECOIL_GetPackedExt(const char *filename)
{
	int ext = 0;
	{
		int i;
		for (i = (int) strlen(filename); --i >= 0;) {
			int c = filename[i];
			if (c == 46)
				return ext | 538976288;
			if (c <= 32 || c > 122 || ext >= 16777216)
				return 0;
			ext = (ext << 8) + c;
		}
	}
	return 0;
}

int const *RECOIL_GetPixels(RECOIL const *self)
{
	return self->pixels;
}

const char *RECOIL_GetPlatform(RECOIL const *self)
{
	switch (self->resolution) {
	case RECOILResolution_AMIGA1X1:
		return "Amiga";
	case RECOILResolution_AMSTRAD1X1:
	case RECOILResolution_AMSTRAD1X2:
		return "Amstrad CPC";
	case RECOILResolution_APPLE_I_I1X1:
	case RECOILResolution_APPLE_I_I1X2:
		return "Apple II";
	case RECOILResolution_MACINTOSH1X1:
		return "Apple Macintosh";
	case RECOILResolution_XE1X1:
	case RECOILResolution_XE2X1:
	case RECOILResolution_XE4X1:
	case RECOILResolution_XE2X2:
	case RECOILResolution_XE4X2:
		return "Atari 8-bit";
	case RECOILResolution_PORTFOLIO1X1:
		return "Atari Portfolio";
	case RECOILResolution_ST1X1:
	case RECOILResolution_ST1X2:
		return "Atari ST";
	case RECOILResolution_STE1X1:
	case RECOILResolution_STE1X2:
		return "Atari STE";
	case RECOILResolution_FALCON1X1:
		return "Atari Falcon";
	case RECOILResolution_BBC1X1:
	case RECOILResolution_BBC2X1:
	case RECOILResolution_BBC1X2:
		return "BBC Micro";
	case RECOILResolution_C161X1:
	case RECOILResolution_C162X1:
		return "Commodore 16";
	case RECOILResolution_C641X1:
	case RECOILResolution_C642X1:
		return "Commodore 64";
	case RECOILResolution_MSX1X1:
		return "MSX";
	case RECOILResolution_PC1X1:
		return "PC";
	case RECOILResolution_SAM_COUPE1X1:
		return "SAM Coupe";
	case RECOILResolution_SPECTRUM1X1:
		return "ZX Spectrum";
	case RECOILResolution_ZX811X1:
		return "ZX81";
	default:
		return "Unknown";
	}
}

static int RECOIL_GetStColor(RECOIL const *self, unsigned char const *content, int contentOffset)
{
	int r = content[contentOffset];
	int gb = content[contentOffset + 1];
	int rgb;
	switch (self->resolution) {
	case RECOILResolution_STE1X1:
	case RECOILResolution_STE1X2:
		rgb = ((r & 7) << 17) | ((r & 8) << 13) | ((gb & 112) << 5) | ((gb & 135) << 1) | ((gb & 8) >> 3);
		return (rgb << 4) | rgb;
	default:
		rgb = ((r & 7) << 16) | ((gb & 112) << 4) | (gb & 7);
		return (rgb << 5) | (rgb << 2) | ((rgb >> 1) & 197379);
	}
}

static int RECOIL_GetStColor1000(unsigned char const *content, int contentOffset)
{
	int rgb = 0;
	{
		int i;
		for (i = 0; i < 3; i++) {
			int c = (content[contentOffset + i * 2] << 8) | content[contentOffset + i * 2 + 1];
			if (c > 1000)
				return -1;
			rgb = (rgb << 8) | c * 255 / 1000;
		}
	}
	return rgb;
}

int RECOIL_GetWidth(RECOIL const *self)
{
	return self->width;
}

static unsigned char RECOIL_Gr12GtiaByteToGr8(int b, int ch, cibool gtia10)
{
	return (RECOIL_Gr12GtiaNibbleToGr8(b >> 4, ch, gtia10) << 4) | RECOIL_Gr12GtiaNibbleToGr8(b & 15, ch, gtia10);
}

static int RECOIL_Gr12GtiaNibbleToGr8(int nibble, int ch, cibool gtia10)
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

cibool RECOIL_IsOurFile(const char *filename)
{
	switch (RECOIL_GetPackedExt(filename)) {
	case 540423474:
	case 538976307:
	case 544498228:
	case 543780148:
	case 543977524:
	case 544043060:
	case 543372342:
	case 544355425:
	case 540292705:
	case 543648119:
	case 544432481:
	case 543715433:
	case 544432993:
	case 543975009:
	case 544237409:
	case 543976545:
	case 543780193:
	case 540176481:
	case 540242017:
	case 544632929:
	case 543778660:
	case 544237412:
	case 543388517:
	case 543386729:
	case 544045680:
	case 543387745:
	case 543977569:
	case 544239713:
	case 544502369:
	case 544371809:
	case 540041826:
	case 540107362:
	case 540172898:
	case 540303970:
	case 540369506:
	case 543646306:
	case 1768711778:
	case 540632930:
	case 540618855:
	case 544237410:
	case 543648610:
	case 543976802:
	case 544567906:
	case 540107107:
	case 540172643:
	case 540238179:
	case 543777635:
	case 544564323:
	case 540305507:
	case 540436579:
	case 540567651:
	case 543516771:
	case 544368739:
	case 544106851:
	case 544370787:
	case 544501859:
	case 543651683:
	case 540107620:
	case 538993764:
	case 543974756:
	case 540108644:
	case 543385444:
	case 544565092:
	case 544368740:
	case 544106852:
	case 544042084:
	case 543977316:
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
	case 543777637:
	case 544236389:
	case 543256677:
	case 540173414:
	case 1768711782:
	case 543779942:
	case 544501350:
	case 544501862:
	case 543388774:
	case 544109926:
	case 540176486:
	case 543258470:
	case 538994535:
	case 543647847:
	case 543453031:
	case 540029287:
	case 540094823:
	case 543319655:
	case 540504679:
	case 540570215:
	case 540635751:
	case 544109927:
	case 543450472:
	case 543385192:
	case 543319912:
	case 544368488:
	case 544041320:
	case 544237928:
	case 544369000:
	case 544039528:
	case 543713639:
	case 544434022:
	case 544108397:
	case 543449959:
	case 543583336:
	case 544369768:
	case 543387752:
	case 544043112:
	case 538997352:
	case 540177000:
	case 543777640:
	case 543515497:
	case 544105321:
	case 543581801:
	case 1835164513:
	case 540109922:
	case 540175458:
	case 540240994:
	case 913138024:
	case 946692456:
	case 544039532:
	case 543975017:
	case 543516521:
	case 543516777:
	case 543649129:
	case 1735223672:
	case 544107881:
	case 1868983913:
	case 543649385:
	case 544239209:
	case 544501353:
	case 540176489:
	case 543387753:
	case 544501865:
	case 540177001:
	case 543650409:
	case 544043881:
	case 544502633:
	case 544237418:
	case 538995306:
	case 543256427:
	case 543648103:
	case 544043122:
	case 544171372:
	case 540242028:
	case 544044396:
	case 543383917:
	case 544760173:
	case 543646317:
	case 538993517:
	case 543712109:
	case 543777645:
	case 544236397:
	case 1886413677:
	case 544433005:
	case 540108653:
	case 540174189:
	case 540305261:
	case 540567405:
	case 544237421:
	case 543385965:
	case 543975789:
	case 544434541:
	case 543517805:
	case 544239725:
	case 544240493:
	case 544171374:
	case 544304238:
	case 544236399:
	case 538976368:
	case 543765616:
	case 540292720:
	case 543383920:
	case 540107632:
	case 540173168:
	case 540238704:
	case 544433008:
	case 543385456:
	case 543582064:
	case 538995056:
	case 540109168:
	case 540174704:
	case 540240240:
	case 540305776:
	case 540633456:
	case 543385968:
	case 540306544:
	case 543255664:
	case 544042096:
	case 543452528:
	case 543649136:
	case 544694642:
	case 543319922:
	case 544237938:
	case 540044658:
	case 540110194:
	case 540175730:
	case 540241266:
	case 540306802:
	case 538996850:
	case 544438642:
	case 544366963:
	case 540173171:
	case 544240231:
	case 540566387:
	case 543253363:
	case 543384435:
	case 544436851:
	case 544367475:
	case 879977331:
	case 543516531:
	case 543385715:
	case 544237683:
	case 544368755:
	case 543582579:
	case 543387763:
	case 544436339:
	case 544567411:
	case 540570227:
	case 544438387:
	case 544237940:
	case 540110452:
	case 540175988:
	case 540241524:
	case 544829044:
	case 544240244:
	case 544567924:
	case 543385974:
	case 543783542:
	case 543452791:
	case 544238712:
	case 544241786:
		return TRUE;
	default:
		return FALSE;
	}
}

static cibool RECOIL_IsStePalette(unsigned char const *content, int contentOffset, int colors)
{
	while (--colors >= 0) {
		if ((content[contentOffset] & 8) != 0 || (content[contentOffset + 1] & 136) != 0)
			return TRUE;
		contentOffset += 2;
	}
	return FALSE;
}

static cibool RECOIL_IsStringAt(unsigned char const *content, int contentOffset, const char *s)
{
	int length = (int) strlen(s);
	{
		int i;
		for (i = 0; i < length; i++)
			if (content[contentOffset + i] != s[i])
				return FALSE;
	}
	return TRUE;
}

static int RECOIL_ParseAtari8ExecutableHeader(unsigned char const *content, int contentOffset)
{
	int startAddress;
	int endAddress;
	if (content[contentOffset] != 255 || content[contentOffset + 1] != 255)
		return -1;
	startAddress = content[contentOffset + 2] | (content[contentOffset + 3] << 8);
	endAddress = content[contentOffset + 4] | (content[contentOffset + 5] << 8);
	return endAddress - startAddress + 1;
}

static void RECOIL_PlotSpcPattern(unsigned char *pixels, int x, int y, int pattern)
{
	pixels[y * 160 + x] = (pattern >> ((~y & 1) * 8 + (~x & 3) * 2)) & 3;
}

void RECOIL_SetAtari8Palette(RECOIL *self, unsigned char const *content)
{
	if (content == NULL)
		content = CiBinaryResource_altirrapal_pal;
	{
		int i;
		for (i = 0; i < 256; i++)
			self->atari8Palette[i] = (content[i * 3] << 16) | (content[i * 3 + 1] << 8) | content[i * 3 + 2];
	}
}

static cibool RECOIL_SetAtari8RawSize(RECOIL *self, unsigned char const *content, int contentLength, RECOILResolution resolution)
{
	int contentOffset = RECOIL_GetAtari8ExecutableOffset(content, contentLength);
	int height = (contentLength - contentOffset) / 40;
	if (height == 0 || height > 240)
		return FALSE;
	RECOIL_SetSize(self, 320, height, resolution);
	return TRUE;
}

static void RECOIL_SetBakPF012(RECOIL *self, unsigned char const *content, int contentOffset, int contentStride)
{
	{
		int i;
		for (i = 0; i < 4; i++)
			self->gtiaColors[i == 0 ? 8 : 3 + i] = content[contentOffset + i * contentStride] & 254;
	}
}

static void RECOIL_SetBakPF0123(RECOIL *self, unsigned char const *content, int contentOffset)
{
	{
		int i;
		for (i = 0; i < 5; i++)
			self->gtiaColors[i == 0 ? 8 : 3 + i] = content[contentOffset + i] & 254;
	}
}

static void RECOIL_SetC16Palette(RECOIL *self)
{
	unsigned char const *pal = CiBinaryResource_c16_pal;
	{
		int i;
		for (i = 0; i < 256; i++)
			self->contentPalette[i] = (pal[i * 3] << 16) | (pal[i * 3 + 1] << 8) | pal[i * 3 + 2];
	}
}

static void RECOIL_SetFalconPalette(RECOIL *self, unsigned char const *content, int contentOffset)
{
	{
		int i;
		for (i = 0; i < 256; i++) {
			int offset = contentOffset + (i << 2);
			self->contentPalette[i] = (content[offset] << 16) | (content[offset + 1] << 8) | content[offset + 3];
		}
	}
}

static void RECOIL_SetGr15DefaultColors(RECOIL *self)
{
	self->gtiaColors[8] = 0;
	self->gtiaColors[4] = 4;
	self->gtiaColors[5] = 8;
	self->gtiaColors[6] = 12;
}

static void RECOIL_SetGtiaColor(RECOIL *self, int reg, int value)
{
	value &= 254;
	switch (reg) {
	case 0:
	case 1:
	case 2:
	case 3:
		self->gtiaColors[reg] = value;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		self->gtiaColors[8 + reg] = self->gtiaColors[reg] = value;
		break;
	case 8:
		self->gtiaColors[11] = self->gtiaColors[10] = self->gtiaColors[9] = self->gtiaColors[8] = value;
		break;
	}
}

static void RECOIL_SetGtiaColors(RECOIL *self, unsigned char const *content, int contentOffset)
{
	self->gtiaColors[0] = content[contentOffset] & 254;
	RECOIL_SetPM123PF0123Bak(self, content, contentOffset + 1);
}

static void RECOIL_SetPF0123Bak(RECOIL *self, unsigned char const *content, int contentOffset)
{
	{
		int i;
		for (i = 0; i < 5; i++)
			self->gtiaColors[4 + i] = content[contentOffset + i] & 254;
	}
}

static void RECOIL_SetPF0123Even(RECOIL *self, unsigned char const *content, int contentOffset)
{
	{
		int i;
		for (i = 0; i < 4; i++)
			self->gtiaColors[4 + i] = content[contentOffset + i * 2] & 254;
	}
}

static void RECOIL_SetPF012Bak(RECOIL *self, unsigned char const *content, int contentOffset)
{
	{
		int i;
		for (i = 0; i < 4; i++)
			self->gtiaColors[i == 3 ? 8 : 4 + i] = content[contentOffset + i] & 254;
	}
}

static void RECOIL_SetPF21(RECOIL *self, unsigned char const *content, int contentOffset)
{
	self->gtiaColors[6] = content[contentOffset] & 254;
	self->gtiaColors[5] = content[contentOffset + 1] & 254;
}

static void RECOIL_SetPM123PF0123Bak(RECOIL *self, unsigned char const *content, int contentOffset)
{
	{
		int i;
		for (i = 0; i < 8; i++)
			RECOIL_SetGtiaColor(self, 1 + i, content[contentOffset + i]);
	}
}

static cibool RECOIL_SetSize(RECOIL *self, int width, int height, RECOILResolution resolution)
{
	if (width <= 0 || width > 2048 || height <= 0 || height > 1024 || width * height > 1572864)
		return FALSE;
	self->width = width;
	self->height = height;
	self->resolution = resolution;
	self->frames = 1;
	self->colors = -1;
	self->leftSkip = 0;
	return TRUE;
}

static cibool RECOIL_SetSizeStOrFalcon(RECOIL *self, int width, int height, int bitplanes)
{
	return RECOIL_SetSize(self, width, height, (bitplanes == 1 && width <= 640 && height <= 400) || (bitplanes <= 4 && width <= 320 && height <= 200) ? RECOILResolution_ST1X1 : RECOILResolution_FALCON1X1);
}

static void RECOIL_SetStPalette(RECOIL *self, unsigned char const *content, int contentOffset, int colors)
{
	{
		int c;
		for (c = 0; c < colors; c++)
			self->contentPalette[c] = RECOIL_GetStColor(self, content, contentOffset + c * 2);
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

int const *RECOIL_ToPalette(RECOIL *self, unsigned char *indexes)
{
	int pixelsCount;
	if (self->colors == -1) {
		memset(self->palette, 0, sizeof(self->palette));
		RECOIL_CalculatePalette(self, self->palette, 0, 256);
	}
	if (self->colors == 0 || self->colors > 256)
		return NULL;
	pixelsCount = self->width * self->height;
	{
		int i;
		for (i = 0; i < pixelsCount; i++)
			indexes[i] = RECOIL_FindColor(self->palette, self->colors, self->pixels[i]);
	}
	return self->palette;
}

static cibool RECOIL_UnpackLz4(RECOIL const *self, unsigned char const *content, int contentLength, unsigned char *unpacked, int unpackedLength)
{
	Lz4Stream stream;
	if (contentLength < 11 || content[0] != 4 || content[1] != 34 || content[2] != 77 || content[3] != 24 || (content[4] & 195) != 64)
		return FALSE;
	stream.base.content = content;
	stream.base.contentOffset = 7;
	if ((content[4] & 8) != 0)
		stream.base.contentOffset += 8;
	stream.unpacked = unpacked;
	stream.unpackedOffset = 0;
	stream.unpackedLength = unpackedLength;
	for (;;) {
		int blockSize;
		if (stream.base.contentOffset + 4 > contentLength)
			return FALSE;
		blockSize = RECOIL_Get32LittleEndian(content, stream.base.contentOffset);
		stream.base.contentOffset += 4;
		stream.base.contentLength = contentLength;
		if (blockSize == 0)
			break;
		if (blockSize >> 31 != 0) {
			if (!Lz4Stream_Copy(&stream, blockSize & 2147483647))
				return FALSE;
			continue;
		}
		stream.base.contentLength = stream.base.contentOffset + blockSize;
		if (stream.base.contentLength > contentLength)
			return FALSE;
		for (;;) {
			int token = Stream_ReadByte(&stream.base);
			int count;
			int offset;
			if (token < 0)
				return FALSE;
			count = Lz4Stream_ReadCount(&stream, token >> 4);
			if (count < 0 || !Lz4Stream_Copy(&stream, count))
				return FALSE;
			if (stream.base.contentOffset == stream.base.contentLength)
				break;
			if (stream.base.contentOffset + 2 > stream.base.contentLength)
				return FALSE;
			offset = Stream_ReadByte(&stream.base);
			offset += Stream_ReadByte(&stream.base) << 8;
			if (offset == 0 || offset > stream.unpackedOffset)
				return FALSE;
			count = Lz4Stream_ReadCount(&stream, token & 15);
			if (count < 0 || stream.unpackedOffset + count > unpackedLength)
				return FALSE;
			count += 4;
			do {
				unpacked[stream.unpackedOffset] = unpacked[stream.unpackedOffset - offset];
				stream.unpackedOffset++;
			}
			while (--count > 0);
		}
		if ((content[4] & 16) != 0)
			stream.base.contentOffset += 4;
	}
	if ((content[4] & 4) != 0)
		stream.base.contentOffset += 4;
	return stream.base.contentOffset == contentLength && stream.unpackedOffset == unpackedLength;
}

static cibool RECOIL_UnpackRip(RECOIL const *self, unsigned char const *content, int contentOffset, int contentLength, unsigned char *unpacked, int unpackedLength)
{
	FanoTree lengthTree;
	FanoTree distanceTree;
	FanoTree literalTree;
	BitStream bitStream;
	if (contentOffset + 304 > contentLength || !RECOIL_IsStringAt(content, contentOffset, "PCK"))
		return FALSE;
	FanoTree_Create(&lengthTree, content, contentOffset + 16, 64);
	FanoTree_Create(&distanceTree, content, contentOffset + 16 + 32, 256);
	FanoTree_Create(&literalTree, content, contentOffset + 16 + 32 + 128, 256);
	BitStream_Construct(&bitStream);
	bitStream.base.content = content;
	bitStream.base.contentOffset = contentOffset + 16 + 288;
	bitStream.base.contentLength = contentLength;
	{
		int unpackedOffset;
		for (unpackedOffset = 0; unpackedOffset < unpackedLength;) {
			switch (BitStream_ReadBit(&bitStream)) {
				int literal;
				int distance;
				int length;
			case -1:
				return FALSE;
			case 0:
				literal = FanoTree_ReadCode(&literalTree, &bitStream);
				if (literal < 0)
					return FALSE;
				unpacked[unpackedOffset++] = literal;
				break;
			case 1:
				distance = FanoTree_ReadCode(&distanceTree, &bitStream);
				if (distance < 0)
					return FALSE;
				distance += 2;
				if (distance > unpackedOffset)
					return FALSE;
				length = FanoTree_ReadCode(&lengthTree, &bitStream);
				if (length < 0)
					return FALSE;
				length += 2;
				do {
					unpacked[unpackedOffset] = unpacked[unpackedOffset - distance];
					if (++unpackedOffset >= unpackedLength)
						return TRUE;
				}
				while (--length > 0);
				break;
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_UnpackSpc(RleStream *rle, unsigned char *unpacked)
{
	{
		int bitplane;
		for (bitplane = 0; bitplane < 8; bitplane += 2) {
			{
				int unpackedOffset;
				for (unpackedOffset = 160 + bitplane; unpackedOffset < 32000; unpackedOffset += 8) {
					{
						int x;
						for (x = 0; x < 2; x++) {
							int b = RleStream_ReadRle(rle);
							if (b < 0)
								return FALSE;
							unpacked[unpackedOffset + x] = b;
						}
					}
				}
			}
		}
	}
	return TRUE;
}

static cibool RECOIL_VerifyIce(RECOIL *self, unsigned char const *content, int contentLength, cibool font, int fontLength, int imageLength, RECOILResolution resolution)
{
	if (font) {
		if (contentLength != fontLength)
			return FALSE;
		RECOIL_SetSize(self, 256, 128, resolution);
	}
	else {
		if (contentLength != imageLength || content[0] != 1)
			return FALSE;
		RECOIL_SetSize(self, 320, 192, resolution);
	}
	return TRUE;
}

static void RgbStream_Construct(RgbStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_RgbStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool RgbStream_ReadCommand(RgbStream *self)
{
	int b = BitStream_ReadBits(&self->base.base, 4);
	cibool rle;
	if (b < 0)
		return FALSE;
	if (b < 8)
		rle = TRUE;
	else {
		b -= 8;
		rle = FALSE;
	}
	if (b == 0) {
		b = BitStream_ReadBits(&self->base.base, 4);
		if (b < 0)
			return FALSE;
		b += 7;
	}
	if (rle) {
		self->base.repeatValue = self->base.vtbl->readValue(&self->base);
		b++;
	}
	else
		self->base.repeatValue = -1;
	self->base.repeatCount = b;
	return TRUE;
}

static int RgbStream_ReadValue(RgbStream *self)
{
	return BitStream_ReadBits(&self->base.base, 12);
}

static void RleStream_Construct(RleStream *self, const RleStreamVtbl *vtbl)
{
	self->vtbl = vtbl;
	BitStream_Construct(&self->base);
	self->repeatCount = 0;
}

static int RleStream_ReadRle(RleStream *self)
{
	while (self->repeatCount == 0) {
		if (!self->vtbl->readCommand(self))
			return -1;
	}
	self->repeatCount--;
	if (self->repeatValue >= 0)
		return self->repeatValue;
	return self->vtbl->readValue(self);
}

static int RleStream_ReadValue(RleStream *self)
{
	return Stream_ReadByte(&self->base.base);
}

static cibool RleStream_Unpack(RleStream *self, unsigned char *unpacked, int unpackedOffset, int unpackedStride, int unpackedCount)
{
	{
		int offset;
		for (offset = 0;;) {
			int b = RleStream_ReadRle(self);
			if (b < 0)
				return FALSE;
			unpacked[unpackedOffset + offset] = b;
			offset += unpackedStride;
			if (offset >= unpackedCount) {
				if (unpackedStride > 1)
					offset -= unpackedCount - 1;
				if (offset >= unpackedStride)
					return TRUE;
			}
		}
	}
}

static cibool RleStream_UnpackC64(RleStream *self, unsigned char *unpacked, int unpackedLength)
{
	unpacked[0] = self->base.base.content[0];
	unpacked[1] = self->base.base.content[1];
	return RleStream_Unpack(self, unpacked, 2, 1, unpackedLength - 2);
}

static void SpcStream_Construct(SpcStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_SpcStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool SpcStream_ReadCommand(SpcStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		self->base.repeatCount = b + 1;
		self->base.repeatValue = -1;
	}
	else {
		self->base.repeatCount = 258 - b;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	return TRUE;
}

static void SpsStream_Construct(SpsStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_SpsStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool SpsStream_ReadCommand(SpsStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		self->base.repeatCount = b + 3;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
	}
	else {
		self->base.repeatCount = b - 127;
		self->base.repeatValue = -1;
	}
	return TRUE;
}

static void Sr8Stream_Construct(Sr8Stream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_Sr8Stream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool Sr8Stream_ReadCommand(Sr8Stream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	switch (b) {
	case -1:
		return FALSE;
	case 0:
		self->base.repeatCount = Stream_ReadByte(&self->base.base.base);
		if (self->base.repeatCount == 0)
			self->base.repeatCount = 256;
		self->base.repeatValue = Stream_ReadByte(&self->base.base.base);
		return TRUE;
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
		return TRUE;
	default:
		self->base.repeatCount = 1;
		self->base.repeatValue = b;
		return TRUE;
	}
}

static int Stream_ReadByte(Stream *self)
{
	if (self->contentOffset >= self->contentLength)
		return -1;
	return self->content[self->contentOffset++];
}

static void TnyPcsStream_Construct(TnyPcsStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_TnyPcsStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool TnyPcsStream_ReadCommand(TnyPcsStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		if (b == 0 || b == 1) {
			if (self->base.base.base.contentOffset + 1 >= self->base.base.base.contentLength)
				return FALSE;
			self->base.repeatCount = (self->base.base.base.content[self->base.base.base.contentOffset] << 8) | self->base.base.base.content[self->base.base.base.contentOffset + 1];
			self->base.base.base.contentOffset += 2;
		}
		else
			self->base.repeatCount = b;
		self->base.repeatValue = b == 1 ? -1 : (&self->base)->vtbl->readValue(&self->base);
	}
	else {
		self->base.repeatCount = 256 - b;
		self->base.repeatValue = -1;
	}
	return TRUE;
}

static void TnyStream_Construct(TnyStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_TnyStream;
	TnyPcsStream_Construct(&self->base, vtbl);
}

static int TnyStream_ReadValue(TnyStream *self)
{
	int value;
	if (self->valueOffset + 1 >= self->valueLength)
		return -1;
	value = (self->base.base.base.base.content[self->valueOffset] << 8) | self->base.base.base.base.content[self->valueOffset + 1];
	self->valueOffset += 2;
	return value;
}

static void VdatStream_Construct(VdatStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_VdatStream;
	TnyStream_Construct(&self->base, vtbl);
}

static cibool VdatStream_ReadCommand(VdatStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base.base.base);
	if (b < 0)
		return FALSE;
	if (b < 128) {
		if (b == 0 || b == 1) {
			self->base.base.base.repeatCount = (&self->base)->base.base.vtbl->readValue(&(&self->base)->base.base);
			if (self->base.base.base.repeatCount < 0)
				return FALSE;
		}
		else
			self->base.base.base.repeatCount = b;
		self->base.base.base.repeatValue = b == 0 ? -1 : (&self->base)->base.base.vtbl->readValue(&(&self->base)->base.base);
	}
	else {
		self->base.base.base.repeatCount = 256 - b;
		self->base.base.base.repeatValue = -1;
	}
	return TRUE;
}

static void XeKoalaStream_Construct(XeKoalaStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_XeKoalaStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool XeKoalaStream_ReadCommand(XeKoalaStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	cibool rle;
	if (b < 0)
		return FALSE;
	if (b < 128)
		rle = TRUE;
	else {
		b -= 128;
		rle = FALSE;
	}
	if (b == 0) {
		int hi = Stream_ReadByte(&self->base.base.base);
		if (hi < 0)
			return FALSE;
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return FALSE;
		b |= hi << 8;
	}
	self->base.repeatCount = b;
	self->base.repeatValue = rle ? Stream_ReadByte(&self->base.base.base) : -1;
	return TRUE;
}

static cibool XeKoalaStream_UnpackRaw(int type, unsigned char const *content, int contentOffset, int contentLength, unsigned char *unpacked, int unpackedLength)
{
	XeKoalaStream rle;
	XeKoalaStream_Construct(&rle, NULL);
	rle.base.base.base.content = content;
	rle.base.base.base.contentOffset = contentOffset;
	rle.base.base.base.contentLength = contentLength;
	switch (type) {
	case 0:
		if (contentLength - contentOffset != unpackedLength)
			return FALSE;
		memcpy(unpacked + 0, content + contentOffset, unpackedLength);
		return TRUE;
	case 1:
		{
			int x;
			for (x = 0; x < 40; x++) {
				{
					int offset;
					for (offset = x; offset < 80; offset += 40) {
						{
							int unpackedOffset;
							for (unpackedOffset = offset; unpackedOffset < unpackedLength; unpackedOffset += 80) {
								int b = RleStream_ReadRle(&rle.base);
								if (b < 0)
									return FALSE;
								unpacked[unpackedOffset] = b;
							}
						}
					}
				}
			}
		}
		return TRUE;
	case 2:
		return RleStream_Unpack(&rle.base, unpacked, 0, 1, unpackedLength);
	default:
		return FALSE;
	}
}

static cibool XeKoalaStream_UnpackWrapped(unsigned char const *content, int contentLength, unsigned char *unpacked, int unpackedLength)
{
	return contentLength >= 26 && content[0] == 255 && content[1] == 128 && content[2] == 201 && content[3] == 199 && content[4] >= 26 && content[4] < contentLength && content[5] == 0 && content[6] == 1 && content[8] == 14 && content[9] == 0 && content[10] == 40 && content[11] == 0 && content[12] == 192 && content[20] == 0 && content[21] == 0 && XeKoalaStream_UnpackRaw(content[7], content, content[4] + 1, contentLength, unpacked, unpackedLength);
}

static void XlpStream_Construct(XlpStream *self, const RleStreamVtbl *vtbl)
{
	if (vtbl == NULL)
		vtbl = &CiVtbl_XlpStream;
	RleStream_Construct(&self->base, vtbl);
}

static cibool XlpStream_ReadCommand(XlpStream *self)
{
	int b = Stream_ReadByte(&self->base.base.base);
	cibool rle;
	if (b < 0)
		return FALSE;
	if (b < 128)
		rle = FALSE;
	else {
		b -= 128;
		rle = TRUE;
	}
	self->base.repeatCount = b;
	if (b >= 64) {
		b = Stream_ReadByte(&self->base.base.base);
		if (b < 0)
			return FALSE;
		self->base.repeatCount = ((self->base.repeatCount - 64) << 8) | b;
	}
	self->base.repeatValue = rle ? Stream_ReadByte(&self->base.base.base) : -1;
	return TRUE;
}

static cibool ZxpStream_IsEof(ZxpStream const *self)
{
	return self->base.contentOffset >= self->base.contentLength;
}

static int ZxpStream_ReadChar(ZxpStream *self)
{
	int c;
	if (self->base.contentOffset >= self->base.contentLength)
		return -1;
	c = self->base.content[self->base.contentOffset++];
	if (c == 13 && self->base.contentOffset < self->base.contentLength && self->base.content[self->base.contentOffset++] == 10)
		return 10;
	return c;
}

static int ZxpStream_ReadHexDigit(ZxpStream *self)
{
	switch (ZxpStream_ReadChar(self)) {
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
	case 65:
	case 97:
		return 10;
	case 66:
	case 98:
		return 11;
	case 67:
	case 99:
		return 12;
	case 68:
	case 100:
		return 13;
	case 69:
	case 101:
		return 14;
	case 70:
	case 102:
		return 15;
	default:
		return -1;
	}
}
