//
// Created by baptc on 07/06/2022.
//
#include "klein64.h"
#include <string.h>
#define _CRT_RAND_S
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifndef PROJECT_KLEINATTACK_H
#define PROJECT_KLEINATTACK_H



typedef unsigned char uint8_t;

uint8_t* generatePlaintext();
uint8_t* add_diff(uint8_t* text);
void InvMixcolumn(uint8_t* state);
void Mixcolumn(uint8_t* state);

void RotateNibble(uint8_t* state);
void InvRotateNibble(uint8_t* state);

void Sbox(uint8_t* state);
void InvSbox(uint8_t* state);

uint8_t* decrypteToCheck(uint8_t* cipher, uint8_t* key);
uint8_t* decrypteWithGuessToCheck(uint8_t* cipher, uint8_t* key);

int checkConformingPair(uint8_t* state1,uint8_t* state2);
int checkPartConformingPair(uint8_t* state1,uint8_t* state2,int* mask);
uint8_t** getConformingPair(uint8_t* key, unsigned int n,int* mask,int number);

// exploiting neutral bits

uint8_t * generationPtFromConfText(uint8_t* ConfText);
uint8_t** getSetConformingPair(uint8_t* key,uint8_t* confText, int n);
uint8_t* generationPt(const int* mask);
uint8_t* keyGeneration(unsigned int n);
uint8_t* keyGenerationHighNibble(int n);
uint8_t** keyRecoveryPart(const uint8_t** conformingtexts,int part);
uint8_t* keyBruteFroce(uint8_t* keysLowerNibble, uint8_t* message, uint8_t* cipher);
uint8_t * add_text(uint8_t* text1,uint8_t* text2);
int equals(uint8_t* text1,uint8_t* text2);




// display

void displayAddText(uint8_t* text1,uint8_t* text2);
void display(uint8_t* state);
void displayRoundKey(uint8_t* key);

#endif //PROJECT_KLEINATTACK_H
