
#ifndef GF_H
#define GF_H

#include <stdint.h>
#include "ec.h"

typedef uint64_t u64;

// BigInt арифметика
void BigIntInit(Ec* ec, u64* a);
void BigIntCopy(Ec* ec, u64* r, const u64* a);
void BigIntAdd(Ec* ec, u64* r, const u64* a, const u64* b);
void BigIntSub(Ec* ec, u64* r, const u64* a, const u64* b);
void BigIntMul(Ec* ec, u64* r, const u64* a, const u64* b);
void BigIntMod(Ec* ec, u64* r, const u64* a, const u64* mod);
void BigIntInv(Ec* ec, u64* r, const u64* a);
int BigIntCmp(Ec* ec, const u64* a, const u64* b);
void BigIntFree(Ec* ec, u64* a);

#endif
