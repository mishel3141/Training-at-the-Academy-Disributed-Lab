
#include <stdio.h>
#include "ec.h"
#include "dsa.h"

int main() {
    EcEd ecc;
    EcEdInit(&ecc, 256, NULL, NULL, NULL, NULL);

    // Відновлений приватний ключ (u64[14])
    u64 d[14] = {
        0x6EAB52C0, 0x4181AA24, 0x0E518D8E, 0x5C6D92CF,
        0xBA25A03D, 0x3C813DAF, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000
    };

    // Хеш повідомлення (u64[14])
    u64 h[14] = {
        0xF778A16B, 0xB239412F, 0x01619416, 0x64F4F3DE,
        0x310CA991, 0xAFDF65B5, 0x070AF8FB, 0x5433A582,
        0x00000000, 0x00000000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000
    };

    EcSignature sig;

    // Виконуємо підпис
    EcDsaSign((Ec*)&ecc, d, h, &sig);

    // Підпис (r та s) буде виведено через DEBUG в dsa.c
    return 0;
}
