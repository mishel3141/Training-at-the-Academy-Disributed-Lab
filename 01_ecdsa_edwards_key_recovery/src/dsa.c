
#include "ec.h"
#include "gf.h"
#include "dsa.h"

// ECDSA Sign
void EcDsaSign(Ec* ec, const u64* d, const u64* hash, EcSignature* sig) {
    BigInt k, kinv, r, s, z;
    BigIntInit(ec, k);
    BigIntInit(ec, kinv);
    BigIntInit(ec, r);
    BigIntInit(ec, s);
    BigIntInit(ec, z);

    // k = hash % n (vulnerable version!)
    BigIntCopy(ec, k, hash);
    if (BigIntCmp(ec, k, ec->n) >= 0)
        BigIntSub(ec, k, k, ec->n);

    // R = k * G
    EcPoint R;
    EcPointInit(ec, &R);
    EcMul(ec, &R, &ec->G, k);

    BigIntCopy(ec, r, R.x);
    BigIntCopy(ec, sig->r, r);

    // kinv = k^(-1) mod n
    BigIntInv(ec, kinv, k);

    // z = hash
    BigIntCopy(ec, z, hash);

    // s = kinv * (z + r*d) mod n
    BigIntMul(ec, s, r, d);
    BigIntAdd(ec, s, s, z);
    BigIntMul(ec, s, s, kinv);
    BigIntMod(ec, s, s, ec->n);

    BigIntCopy(ec, sig->s, s);

    // DEBUG ВИВІД ПІДПИСУ
    printf("DEBUG r = ");
    for (int i = 13; i >= 0; i--) printf("%08x", sig->r[i]);
    printf("\n");

    printf("DEBUG s = ");
    for (int i = 13; i >= 0; i--) printf("%08x", sig->s[i]);
    printf("\n");

    BigIntFree(ec, k);
    BigIntFree(ec, kinv);
    BigIntFree(ec, r);
    BigIntFree(ec, s);
    BigIntFree(ec, z);
}
