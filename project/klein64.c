//
// Created by baptc on 07/06/2022.
//
#include "klein64.h"
#include "kleinAttack.h"
void klein64_encrypt_rounds(const uint8_t *plain, const uint8_t *key, const uint8_t rounds, uint8_t *cipher){
    uint8_t state[8];
    uint8_t temp_state[8];
    uint8_t u,v = 0;
    uint8_t round_key[8];
    uint8_t i;

    //initialize the key and the state;
    round_key[0] = key[0];
    round_key[1] = key[1];
    round_key[2] = key[2];
    round_key[3] = key[3];
    round_key[4] = key[4];
    round_key[5] = key[5];
    round_key[6] = key[6];
    round_key[7] = key[7];

    state[0] = plain[0];
    state[1] = plain[1];
    state[2] = plain[2];
    state[3] = plain[3];
    state[4] = plain[4];
    state[5] = plain[5];
    state[6] = plain[6];
    state[7] = plain[7];

    for(i = 1; i <= rounds; i++)
    {
        //add round key;
        state[0] = state[0] ^ round_key[0];
        state[1] = state[1] ^ round_key[1];
        state[2] = state[2] ^ round_key[2];
        state[3] = state[3] ^ round_key[3];
        state[4] = state[4] ^ round_key[4];
        state[5] = state[5] ^ round_key[5];
        state[6] = state[6] ^ round_key[6];
        state[7] = state[7] ^ round_key[7];

        //key schedule;
        temp_state[0] = round_key[0];
        temp_state[1] = round_key[1];
        temp_state[2] = round_key[2];
        temp_state[3] = round_key[3];
        temp_state[4] = round_key[4];

        round_key[0] = round_key[5];
        round_key[1] = round_key[6];
        round_key[2] = round_key[7] ^ i;
        round_key[3] = round_key[4];

        round_key[4] = temp_state[1] ^ round_key[5];
        round_key[5] = sbox8[temp_state[2] ^ round_key[6]];
        round_key[6] = sbox8[temp_state[3] ^ round_key[7]];
        round_key[7] = temp_state[0] ^ temp_state[4];


        //substitute nibbles with the byte-oriented sbox;
        state[0] = sbox8[state[0]];
        state[1] = sbox8[state[1]];
        state[2] = sbox8[state[2]];
        state[3] = sbox8[state[3]];
        state[4] = sbox8[state[4]];
        state[5] = sbox8[state[5]];
        state[6] = sbox8[state[6]];
        state[7] = sbox8[state[7]];

        //the RotateNibbles step, left shift two bytes;
        temp_state[0] = state[2];
        temp_state[1] = state[3];
        temp_state[2] = state[4];
        temp_state[3] = state[5];
        temp_state[4] = state[6];
        temp_state[5] = state[7];
        temp_state[6] = state[0];
        temp_state[7] = state[1];

        //an efficient MixNibbles implementation for AES, Book Page 54;
        u = temp_state[0] ^ temp_state[1] ^ temp_state[2] ^ temp_state[3];
        v = temp_state[0] ^ temp_state[1];
        v = multiply2[v];
        state[0] = temp_state[0] ^ v ^ u;

        v = temp_state[1] ^ temp_state[2];
        v = multiply2[v];
        state[1] = temp_state[1] ^ v ^ u;

        v = temp_state[2] ^ temp_state[3];
        v = multiply2[v];
        state[2] = temp_state[2] ^ v ^ u;

        v = temp_state[3] ^ temp_state[0];
        v = multiply2[v];
        state[3] = temp_state[3] ^ v ^ u;

        u = temp_state[4] ^ temp_state[5] ^ temp_state[6] ^ temp_state[7];
        v = temp_state[4] ^ temp_state[5];
        v = multiply2[v];
        state[4] = temp_state[4] ^ v ^ u;

        v = temp_state[5] ^ temp_state[6];
        v = multiply2[v];
        state[5] = temp_state[5] ^ v ^ u;

        v = temp_state[6] ^ temp_state[7];
        v = multiply2[v];
        state[6] = temp_state[6] ^ v ^ u;

        v = temp_state[7] ^ temp_state[4];
        v = multiply2[v];
        state[7] = temp_state[7] ^ v ^ u;

    }

    //xored by the whitenning key, output the ciphertext;
    cipher[0] = state[0] ^ round_key[0];
    cipher[1] = state[1] ^ round_key[1];
    cipher[2] = state[2] ^ round_key[2];
    cipher[3] = state[3] ^ round_key[3];
    cipher[4] = state[4] ^ round_key[4];
    cipher[5] = state[5] ^ round_key[5];
    cipher[6] = state[6] ^ round_key[6];
    cipher[7] = state[7] ^ round_key[7];

}


void klein64_decrypt_rounds(const uint8_t *cipher, const uint8_t *key, const uint8_t rounds, uint8_t *plain)
{
    uint8_t state[8];
    uint8_t temp_state[8];
    uint8_t u,v = 0;
    uint8_t round_key[8];
    uint8_t i;

    //initialize the state and the key;
    round_key[0] = key[0];
    round_key[1] = key[1];
    round_key[2] = key[2];
    round_key[3] = key[3];
    round_key[4] = key[4];
    round_key[5] = key[5];
    round_key[6] = key[6];
    round_key[7] = key[7];

    //key expansion
    for(i = 1; i <= rounds; i++)
    {
        temp_state[0] = round_key[0];
        temp_state[1] = round_key[1];
        temp_state[2] = round_key[2];
        temp_state[3] = round_key[3];
        temp_state[4] = round_key[4];

        round_key[0] = round_key[5];
        round_key[1] = round_key[6];
        round_key[2] = round_key[7] ^ i;
        round_key[3] = round_key[4];

        round_key[4] = temp_state[1] ^ round_key[5];
        round_key[5] = sbox8[temp_state[2] ^ round_key[6]];
        round_key[6] = sbox8[temp_state[3] ^ round_key[7]];
        round_key[7] = temp_state[0] ^ temp_state[4];

    }
    printf("a\n");
    display(round_key);
    state[0] = cipher[0] ^ round_key[0];
    state[1] = cipher[1] ^ round_key[1];
    state[2] = cipher[2] ^ round_key[2];
    state[3] = cipher[3] ^ round_key[3];
    state[4] = cipher[4] ^ round_key[4];
    state[5] = cipher[5] ^ round_key[5];
    state[6] = cipher[6] ^ round_key[6];
    state[7] = cipher[7] ^ round_key[7];

    //inverse the subsequent rounds;
    for(i = 0; i < rounds; i++)
    {
        //inverse the MixNibbles and the Rotate steps;
        temp_state[0] = state[0];
        temp_state[1] = state[1];
        temp_state[2] = state[2];
        temp_state[3] = state[3];
        temp_state[4] = state[4];
        temp_state[5] = state[5];
        temp_state[6] = state[6];
        temp_state[7] = state[7];

        u = multiply2[multiply2[temp_state[0] ^ temp_state[2]]];
        v = multiply2[multiply2[temp_state[1] ^ temp_state[3]]];

        temp_state[0] = temp_state[0] ^ u;
        temp_state[1] = temp_state[1] ^ v;
        temp_state[2] = temp_state[2] ^ u;
        temp_state[3] = temp_state[3] ^ v;

        u = multiply2[multiply2[temp_state[4] ^ temp_state[6]]];
        v = multiply2[multiply2[temp_state[5] ^ temp_state[7]]];

        temp_state[4] = temp_state[4] ^ u;
        temp_state[5] = temp_state[5] ^ v;
        temp_state[6] = temp_state[6] ^ u;
        temp_state[7] = temp_state[7] ^ v;

        u = temp_state[0] ^ temp_state[1] ^ temp_state[2] ^ temp_state[3];
        v = temp_state[0] ^ temp_state[1];
        v = multiply2[v];
        state[2] = temp_state[0] ^ v ^ u;

        v = temp_state[1] ^ temp_state[2];
        v = multiply2[v];
        state[3] = temp_state[1] ^ v ^ u;

        v = temp_state[2] ^ temp_state[3];
        v = multiply2[v];
        state[4] = temp_state[2] ^ v ^ u;

        v = temp_state[3] ^ temp_state[0];
        v = multiply2[v];
        state[5] = temp_state[3] ^ v ^ u;

        u = temp_state[4] ^ temp_state[5] ^ temp_state[6] ^ temp_state[7];
        v = temp_state[4] ^ temp_state[5];
        v = multiply2[v];
        state[6] = temp_state[4] ^ v ^ u;

        v = temp_state[5] ^ temp_state[6];
        v = multiply2[v];
        state[7] = temp_state[5] ^ v ^ u;

        v = temp_state[6] ^ temp_state[7];
        v = multiply2[v];
        state[0] = temp_state[6] ^ v ^ u;

        v = temp_state[7] ^ temp_state[4];
        v = multiply2[v];
        state[1] = temp_state[7] ^ v ^ u;

        //inverse the SubNibbles step;
        state[0] = sbox8[state[0]];
        state[1] = sbox8[state[1]];
        state[2] = sbox8[state[2]];
        state[3] = sbox8[state[3]];
        state[4] = sbox8[state[4]];
        state[5] = sbox8[state[5]];
        state[6] = sbox8[state[6]];
        state[7] = sbox8[state[7]];

        //reverse the round key;
        temp_state[4] = round_key[4];
        temp_state[5] = round_key[5];
        temp_state[6] = round_key[6];
        temp_state[7] = round_key[7];

        round_key[4] = round_key[3];
        round_key[5] = round_key[0];
        round_key[6] = round_key[1];
        round_key[7] = round_key[2] ^ (rounds - i);

        round_key[0] = temp_state[7] ^ round_key[4];
        round_key[1] = temp_state[4] ^ round_key[5];
        round_key[2] = sbox8[temp_state[5]] ^ round_key[6];
        round_key[3] = sbox8[temp_state[6]] ^ round_key[7];

        //add round key with the intermediate state;
        state[0] = state[0] ^ round_key[0];
        state[1] = state[1] ^ round_key[1];
        state[2] = state[2] ^ round_key[2];
        state[3] = state[3] ^ round_key[3];
        state[4] = state[4] ^ round_key[4];
        state[5] = state[5] ^ round_key[5];
        state[6] = state[6] ^ round_key[6];
        state[7] = state[7] ^ round_key[7];

    }

    //output the plaintext;
    plain[0] = state[0];
    plain[1] = state[1];
    plain[2] = state[2];
    plain[3] = state[3];
    plain[4] = state[4];
    plain[5] = state[5];
    plain[6] = state[6];
    plain[7] = state[7];

}