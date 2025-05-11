
#include "gf.h"

// Ініціалізація BigInt
void BigIntInit(Ec* ec, u64* a) {
    for (int i = 0; i < 14; i++) a[i] = 0;
}

// Копіювання BigInt
void BigIntCopy(Ec* ec, u64* r, const u64* a) {
    for (int i = 0; i < 14; i++) r[i] = a[i];
}

// Додавання BigInt
void BigIntAdd(Ec* ec, u64* r, const u64* a, const u64* b) {
    u64 carry = 0;
    for (int i = 0; i < 14; i++) {
        u64 t = a[i] + b[i] + carry;
        carry = (t < a[i]);
        r[i] = t;
    }
}

// Віднімання BigInt
void BigIntSub(Ec* ec, u64* r, const u64* a, const u64* b) {
    u64 borrow = 0;
    for (int i = 0; i < 14; i++) {
        u64 t = a[i] - b[i] - borrow;
        borrow = (a[i] < b[i] + borrow);
        r[i] = t;
    }
}

// Множення BigInt (дуже спрощене, для невеликих k)
void BigIntMul(Ec* ec, u64* r, const u64* a, const u64* b) {
    u64 tmp[28] = {0};
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            __uint128_t t = (__uint128_t)a[i] * (__uint128_t)b[j];
            tmp[i + j] += (u64)t;
            if (t >> 64) tmp[i + j + 1] += (u64)(t >> 64);
        }
    }
    for (int i = 0; i < 14; i++) r[i] = tmp[i];
}

// Модуль BigInt
void BigIntMod(Ec* ec, u64* r, const u64* a, const u64* mod) {
    BigIntCopy(ec, r, a);
    while (BigIntCmp(ec, r, mod) >= 0)
        BigIntSub(ec, r, r, mod);
}

// Інверсія BigInt (extended GCD)
void BigIntInv(Ec* ec, u64* r, const u64* a) {
    u64 t[14] = {0}, newt[14] = {1};
    u64 r0[14], newr[14];
    BigIntCopy(ec, r0, ec->n);
    BigIntCopy(ec, newr, a);

    while (BigIntCmp(ec, newr, (u64[14]){0}) != 0) {
        BigIntSub(ec, r0, r0, newr);
        BigIntSub(ec, t, t, newt);

        if ((int64_t)t[0] < 0) BigIntAdd(ec, t, t, ec->n);
        BigIntCopy(ec, r0, newr);
        BigIntCopy(ec, newr, r0);
        BigIntCopy(ec, t, newt);
    }

    BigIntCopy(ec, r, t);
}

// Порівняння BigInt
int BigIntCmp(Ec* ec, const u64* a, const u64* b) {
    for (int i = 13; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

// Очищення BigInt
void BigIntFree(Ec* ec, u64* a) {
    // No action needed
}
