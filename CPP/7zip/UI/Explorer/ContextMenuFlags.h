// ContextMenuFlags.h

#ifndef ZIP7_INC_CONTEXT_MENU_FLAGS_H
#define ZIP7_INC_CONTEXT_MENU_FLAGS_H

namespace NContextMenuFlags
{
  const UInt32 kExtract = 1 << 0;
  const UInt32 kExtractHere = 1 << 1;
  const UInt32 kExtractTo = 1 << 2;
  const UInt32 kExtractSmart = 1 << 3;
  const UInt32 kExtractToSingle = 1 << 4;
  const UInt32 kExtractDelete = 1 << 5;
  const UInt32 kExtractHereDelete = 1 << 6;
  const UInt32 kExtractToDelete = 1 << 7;

  const UInt32 kTest = 1 << 9;
  const UInt32 kOpen = 1 << 10;
  const UInt32 kOpenAs = 1 << 11;

  const UInt32 kCompress = 1 << 13;
  const UInt32 kCompressTo7z = 1 << 14;
  const UInt32 kCompressTo7zWithDate = 1 << 15;
  const UInt32 kCompressTo7zSeparate = 1 << 16;
  const UInt32 kCompressEmail = 1 << 17;
  const UInt32 kCompressTo7zEmail = 1 << 18;
  const UInt32 kCompressToZip = 1 << 19;
  const UInt32 kCompressToZipWithDate = 1 << 20;
  const UInt32 kCompressToZipSeparate = 1 << 21;
  const UInt32 kCompressToZipEmail = 1 << 22;

  const UInt32 kCRC_Cascaded = (UInt32)1 << 30;
  const UInt32 kCRC = (UInt32)1 << 31;
}

#endif
