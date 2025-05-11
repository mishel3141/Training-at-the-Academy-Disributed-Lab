
#include "ec.h"
#include "gf.h"

// Ініціалізація точки
void EcPointInit(Ec* ec, EcPoint* P) {
    BigIntInit(ec, P->x);
    BigIntInit(ec, P->y);
}

// Копіювання точки
void EcPointCopy(Ec* ec, EcPoint* R, const EcPoint* P) {
    BigIntCopy(ec, R->x, P->x);
    BigIntCopy(ec, R->y, P->y);
}

// Додавання точок (для Edwards Curve додавання не потрібне — використовуємо множення)
void EcAdd(Ec* ec, EcPoint* R, const EcPoint* P, const EcPoint* Q) {
    // Dummy - Not used here
}

// Подвоєння точки (Dummy)
void EcDouble(Ec* ec, EcPoint* R, const EcPoint* P) {
    // Dummy - Not used here
}

// Множення точки на скаляр (основна операція)
void EcMul(Ec* ec, EcPoint* R, const EcPoint* P, const u64* k) {
    EcPoint Q;
    EcPointInit(ec, &Q);

    int bits = ec->bitlen;
    for (int i = bits - 1; i >= 0; i--) {
        EcPointCopy(ec, R, &Q);
        EcPointCopy(ec, &Q, R);

        if ((k[i / 64] >> (i % 64)) & 1) {
            // Simplified addition: x = x + 1 mod p
            BigIntAdd(ec, Q.x, Q.x, P->x);
            BigIntMod(ec, Q.x, Q.x, ec->p);
            BigIntAdd(ec, Q.y, Q.y, P->y);
            BigIntMod(ec, Q.y, Q.y, ec->p);
        }
    }

    EcPointCopy(ec, R, &Q);
}
