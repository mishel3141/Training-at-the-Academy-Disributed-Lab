
#ifndef EC_H
#define EC_H

#include <stdint.h>

typedef uint64_t u64;

// Структура кривої
typedef struct {
    int bitlen;
    u64 p[14];
    u64 n[14];
    u64 d;
    struct EcPoint {
        u64 x[14];
        u64 y[14];
    } G;
} EcEd;

// Точка
typedef struct EcPoint EcPoint;

// Підпис
typedef struct {
    u64 r[14];
    u64 s[14];
} EcSignature;

// Функції
void EcPointInit(Ec* ec, EcPoint* P);
void EcPointCopy(Ec* ec, EcPoint* R, const EcPoint* P);
void EcAdd(Ec* ec, EcPoint* R, const EcPoint* P, const EcPoint* Q);
void EcDouble(Ec* ec, EcPoint* R, const EcPoint* P);
void EcMul(Ec* ec, EcPoint* R, const EcPoint* P, const u64* k);

#endif
