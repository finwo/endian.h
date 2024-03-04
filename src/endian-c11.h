#ifndef __FINWO_ENDIAN_EXTRA_H__
#define __FINWO_ENDIAN_EXTRA_H__

#include <stdint.h>

#include "endian.h"

#define htobe(v) _Generic(v, uint16_t: htobe16, int16_t: htobe16, uint32_t: htobe32, int32_t: htobe32, int64_t: htobe64, uint64_t: htobe64)(v)
#define htole(v) _Generic(v, uint16_t: htole16, int16_t: htole16, uint32_t: htole32, int32_t: htole32, int64_t: htole64, uint64_t: htole64)(v)

#define betoh(v) _Generic(v, uint16_t: be16toh, int16_t: be16toh, uint32_t: be32toh, int32_t: be32toh, int64_t: be64toh, uint64_t: be64toh)(v)
#define letoh(v) _Generic(v, uint16_t: le16toh, int16_t: le16toh, uint32_t: le32toh, int32_t: le32toh, int64_t: le64toh, uint64_t: le64toh)(v)

#endif // __FINWO_ENDIAN_EXTRA_H__
