#include <stdio.h>
#include <time.h>
#include <math.h>
#include "klein64.h"
#include "kleinAttack.h"
#include <time.h>


/*
 * First of all, the code run every time until the end without error, if you got one please tell me !
 *
 * The aim of this project is to implement an attack against a version of Klein with fewer rounds.
 *
* The work I provided corresponds to the file kleinAttack.c and kleinAttack.h. Regarding the files
 * klein.c, klein.h and kleinSbox.h are files that were given to me for my project
 *
 * The attack that has been implemented is from a research paper and uses a differential attack.
 * The idea of the attack is based on the observation that if a message has a certain pattern before the Mixcolumn then
 * the probability of having the same difference is greater than expected. Thus, it allows to find
 * lower nibbles separately from higher nibbles. This method allows you to attack between 1 and 6 rounds with a
 * total complexity which is O(2^32) which corresponds to the brute force complexity of the higher nibbles
 *
 * Note: it is also possible to find the key for 1 and 2 rounds with my code. However, for this I
 * don't use the same characterization as for 3 to 6 rounds.
 *
 * To know more about how the attack works, you can refer to the pdf attached with this project
 *
 **********************************************************************************************
 * To choose the number of rounds you have to modify "#define ROUNDS_64" which is in klein64.h
 **********************************************************************************************
 * */
int main(int argc, char **argv){

    unsigned int i,j,k,n;

    int numberConformingPair = 13;
    int mask[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    int mask1[8] = {0, 0, 1, 1, 1, 1, 0, 0};
    int mask2[8] = {1, 1, 0, 0, 0, 0, 1, 1};

    // When you generate a key randomly then it can take time with brute force
    // so it can be useful to consider a key that you choose in order to find quickly the higher nibble
    // with brute force

    int with_random = 1;

    uint8_t* key = malloc(sizeof(uint8_t)*8);
    if(with_random){
        uint8_t* key_temp = generationPt(mask);
        for(i=0;i<8;i++){
            key[i] = key_temp[i];
        }

    }else{
        key[0] = 0x02;
        key[1] = 0x0F;
        key[2] = 0x0F;
        key[3] = 0x0F;
        key[4] = 0xC9;
        key[5] = 0xA3;
        key[6] = 0x7F;
        key[7] = 0xDF;
    }

    // this message and cipher pair is used at the end of the program to filter the keys for brute force
    uint8_t message[8] = {
            0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF,
    };
    uint8_t cipher[8];

    klein64_encrypt(message,key,cipher);

    // the number of iterations "n" is chosen according to the probability of the characteristic

    if(ROUNDS_64<=3){
        n = (unsigned int) pow(2,12);
    }else if(ROUNDS_64==4){
        n = (unsigned int) pow(2,18);
    }else if(ROUNDS_64==5){
        n = (unsigned int) pow(2,24);
    }else if(ROUNDS_64==6){
        n = (unsigned int) pow(2,30);
    }



    printf("########################################\n        Start key recovering  \n########################################\n\n");
    printf("****************************************\n           Print Round Key       \n****************************************\n");

    displayRoundKey(key);


    printf("############ START PART %d ####################\n",1);

    printf("  ** Start finding conforming pairs **\n\n");
    uint8_t** keysPart1;
    uint8_t** keysPart2;
    clock_t t1,t2,t3,t4,t5;
    if(ROUNDS_64<3){

        t1 = clock();
        uint8_t** states = getConformingPair(key,n,mask,numberConformingPair);
        t2 = clock();

        printf("  ** Start guessing **\n\n");
        printf("Potential key : \n");

        keysPart1 =  keyRecoveryPart(states,1);
        t3 = clock();
        printf("############ START PART %d ####################\n",2);
        printf("  ** Start finding conforming pairs **\n\n");


        printf("  ** Start guessing **\n\n");
        printf("Potential key : \n");
        keysPart2 = keyRecoveryPart(states,2);
        t4 = clock();

    }else{
        t1 = clock();
        uint8_t** states = getConformingPair(key,n,mask1,numberConformingPair);

        printf("  ** Start guessing **\n\n");
        printf("Potential key : \n");
        t2 = clock();
        keysPart1 =  keyRecoveryPart(states,1);
        t3 = clock();
        printf("############ START PART %d ####################\n",2);
        printf("  ** Start finding conforming pairs **\n\n");

        states = getConformingPair(key,n,mask2,numberConformingPair);
        t4 = clock();

        printf("  ** Start guessing **\n\n");
        printf("Potential key : \n");

        keysPart2 = keyRecoveryPart(states,2);
        t5 = clock();
    }

    int numberPairFound1 = keysPart1[0];
    int numberPairFound2 = keysPart2[0];
    printf("#####  RESULTS FOR LOWER NIBBLES #############\n",2);
    uint8_t* keysLowerNibble = malloc(sizeof(uint8_t)*8);
    uint8_t* tryKey;
    if(ROUNDS_64<3){
        printf("Time for finding the set of conforming pairs is : %f ms\n",(float) t2-t1);
        printf("Time for recovering candidate keys part 1 is : %f ms\n",(float) t3-t2);
        printf("Time for recovering candidate keys part 2 is : %f ms\n",(float) t4-t3);
    }else{
        printf("Time for finding the first set of conforming pairs is : %f ms \n",(float) t2-t1);
        printf("Time for recovering candidate keys part 1 is : %f ms\n",(float) t3-t2);
        printf("Time for finding the second set of conforming pairs is : %f ms\n",(float) t4-t3);
        printf("Time for recovering candidate keys part 2 is : %f ms\n",(float) t5-t4);
        printf("Time for recovering candidate keys part 2 is : %f ms\n",(float) t5-t4);

    }




    printf("\n****************************************\n    Start brute force higher nibbles       \n****************************************\n");
    int keepGoing = 1;
    for(j=1; (j<=numberPairFound1)&&keepGoing;j++){
        for(k=1;(k<=numberPairFound2)&&keepGoing;k++){
            for(i=0;i<8;i++){
                keysLowerNibble[i] = keysPart1[j][i]^keysPart2[k][i];
            }
            printf("\n****************************************\nWe try with the candidate %d for lower nibble     \n****************************************\n",j+k-1);
            display(keysLowerNibble);
            tryKey = keyBruteFroce(keysLowerNibble,message,cipher);
            if(equals(tryKey,key)){
                keepGoing = 0;
            }else{
                free(tryKey);
            }
        }
    }

    printf("****************************************\n        True Key       \n****************************************\n");
    display(key);
    printf("****************************************\n     Recovered Key        \n****************************************\n");
    display(tryKey);



}