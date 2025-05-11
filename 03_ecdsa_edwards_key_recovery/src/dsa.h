
#ifndef DSA_H
#define DSA_H

#include "ec.h"

// Підпис
typedef struct {
    u64 r[14];
    u64 s[14];
} EcSignature;

// Функція підпису
void EcDsaSign(Ec* ec, const u64* d, const u64* hash, EcSignature* sig);

#endif
