#include <stdint.h>

#include "src/endian.h"

int main() {
  uint32_t orgu32 = 42;

  uint32_t beu32 = htobe32(orgu32);
  uint32_t newu32 = be32toh(beu32);

  return newu32;
}
