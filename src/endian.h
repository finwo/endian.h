// Based heavily on https://stackoverflow.com/a/58418801
#ifndef __FINWO_ENDIAN_H__
#define __FINWO_ENDIAN_H__

#if defined(OS_MACOSX) || defined(__APPLE__)
  #include <libkern/OSByteOrder.h>

  #define htobe16(x) OSSwapHostToBigInt16(x)
  #define htole16(x) OSSwapHostToLittleInt16(x)
  #define be16toh(x) OSSwapBigToHostInt16(x)
  #define le16toh(x) OSSwapLittleToHostInt16(x)

  #define htobe32(x) OSSwapHostToBigInt32(x)
  #define htole32(x) OSSwapHostToLittleInt32(x)
  #define be32toh(x) OSSwapBigToHostInt32(x)
  #define le32toh(x) OSSwapLittleToHostInt32(x)

  #define htobe64(x) OSSwapHostToBigInt64(x)
  #define htole64(x) OSSwapHostToLittleInt64(x)
  #define be64toh(x) OSSwapBigToHostInt64(x)
  #define le64toh(x) OSSwapLittleToHostInt64(x)
#elif defined(OS_SOLARIS)
  #include <sys/isa_defs.h>
  #ifdef _LITTLE_ENDIAN
    #define LITTLE_ENDIAN
  #else
    #define BIG_ENDIAN
  #endif
#elif defined(OS_FREEBSD) || defined(OS_OPENBSD) || defined(OS_NETBSD) || defined(OS_DRAGONFLYBSD)
  #include <sys/types.h>
  #include <sys/endian.h>
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)

  #define SwapTwoBytes(data) \
  ( (((data) >> 8) & 0x00FF) | \
    (((data) << 8) & 0xFF00) )

  #define SwapFourBytes(data)   \
  ( (((data) >> 24) & 0x000000FF) | \
    (((data) >>  8) & 0x0000FF00) | \
    (((data) <<  8) & 0x00FF0000) | \
    (((data) << 24) & 0xFF000000) )

  #define SwapEightBytes(data)   \
  ( (((data) >> 56) & 0x00000000000000FF) | \
    (((data) >> 40) & 0x000000000000FF00) | \
    (((data) >> 24) & 0x0000000000FF0000) | \
    (((data) >>  8) & 0x00000000FF000000) | \
    (((data) <<  8) & 0x000000FF00000000) | \
    (((data) << 24) & 0x0000FF0000000000) | \
    (((data) << 40) & 0x00FF000000000000) | \
    (((data) << 56) & 0xFF00000000000000) )

  #if BYTE_ORDER == LITTLE_ENDIAN

    #define htobe16(x) SwapTwoBytes(x)
    #define htole16(x) (x)
    #define be16toh(x) SwapTwoBytes(x)
    #define le16toh(x) (x)

    #define htobe32(x) SwapFourBytes(x)
    #define htole32(x) (x)
    #define be32toh(x) SwapFourBytes(x)
    #define le32toh(x) (x)

    #define htobe64(x) SwapEightBytes(x)
    #define htole64(x) (x)
    #define be64toh(x) SwapEightBytes(x)
    #define le64toh(x) (x)

  #elif BYTE_ORDER == BIG_ENDIAN

    /* that would be xbox 360 */
    #define htobe16(x) (x)
    #define htole16(x) __builtin_bswap16(x)
    #define be16toh(x) (x)
    #define le16toh(x) __builtin_bswap16(x)

    #define htobe32(x) (x)
    #define htole32(x) __builtin_bswap32(x)
    #define be32toh(x) (x)
    #define le32toh(x) __builtin_bswap32(x)

    #define htobe64(x) (x)
    #define htole64(x) __builtin_bswap64(x)
    #define be64toh(x) (x)
    #define le64toh(x) __builtin_bswap64(x)

  #else
    #error byte order not supported
  #endif

  #define __BYTE_ORDER    BYTE_ORDER
  #define __BIG_ENDIAN    BIG_ENDIAN
  #define __LITTLE_ENDIAN LITTLE_ENDIAN
  #define __PDP_ENDIAN    PDP_ENDIAN

#else
  #include <endian.h>
#endif

#endif // __FINWO_ENDIAN_H__
