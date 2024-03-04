endian.h
========

Basic handling of endianness between host and known orientations

API
---

These macros are defined in [src/endian.h](src/endian.h):

```C
htobe16(x)
htole16(x)
be16toh(x)
le16toh(x)

htobe32(x)
htole32(x)
be32toh(x)
le32toh(x)

htobe64(x)
htole64(x)
be64toh(x)
le64toh(x)
```

And as a C11 extension, the following macros are defined as well in
[src/endian-c11.h](src/endian-c11.h) to not have to think about the type being
passed to the maco:

```C
htobe(x)
htole(x)
betoh(x)
letoh(x)
```
