#include "kleinSbox.h"

#ifndef KLEIN64_H_
#define KLEIN64_H_

//rounds of Klein-64;
#define ROUNDS_64 4

#define klein64_encrypt(plain, key, cipher) klein64_encrypt_rounds((plain), (key), ROUNDS_64, (cipher))
#define klein64_decrypt(cipher, key, plain) klein64_decrypt_rounds((cipher), (key), ROUNDS_64, (plain))

void klein64_encrypt_rounds(const uint8_t *plain, const uint8_t *key, const uint8_t rounds, uint8_t *cipher);

void klein64_decrypt_rounds(const uint8_t *cipher, const uint8_t *key, const uint8_t rounds, uint8_t *plain);
#endif /* KLEIN64_H_ */