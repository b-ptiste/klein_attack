//
// Created by baptc on 07/06/2022.
//

#include "kleinAttack.h"
#include <math.h>

/*
 * This function provides a text pair with a difference specified by the mask argument, the differences
 * are non-zero and random
 *
 * input :
 * mask (int*): integer list that corresponds to the place where we want non-zero random differences
 *
 * output :
 * pair of texts (uint8_t*) : 8 first uint8_t are first text and 8 others the second text
 */
uint8_t* generationPt(const int* mask){
    unsigned int    number;
    unsigned int i;

    uint8_t* text;
    text = malloc(sizeof(uint8_t)*16);

    for(i=0;i<8;i++){
        rand_s(&number);
        text[i] = (uint8_t) number %256;
    }

    for(i=8;i<16;i++){
        if(mask[i-8]){
            rand_s(&number);
            text[i] = text[i-8]^(uint8_t) (1+number%15);
        }else{
            text[i] = text[i-8];
        }
    }
    return(text);
}


/*
 * This function implements the Mixcolumn
 *
 * input :
 * state (uint8_t*): it is modified after execution
 *
 */

void Mixcolumn(uint8_t* state){
    uint8_t temp_state[8];
    uint8_t u,v = 0;

    temp_state[0] = state[0];
    temp_state[1] = state[1];
    temp_state[2] = state[2];
    temp_state[3] = state[3];
    temp_state[4] = state[4];
    temp_state[5] = state[5];
    temp_state[6] = state[6];
    temp_state[7] = state[7];

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


/*
 * This function implements the InvMixcolumn
 *
 * input :
 * state (uint8_t*): it is modified after execution
 *
 */
void InvMixcolumn(uint8_t* state){

    uint8_t temp_state[8];
    uint8_t u,v = 0;

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

/*
 * This function implements the permutation with the Sbox of
 *
 * input :
 * state (uint8_t*): it is modified after execution
 *
 */
void Sbox(uint8_t* state){
    state[0] = sbox8[state[0]];
    state[1] = sbox8[state[1]];
    state[2] = sbox8[state[2]];
    state[3] = sbox8[state[3]];
    state[4] = sbox8[state[4]];
    state[5] = sbox8[state[5]];
    state[6] = sbox8[state[6]];
    state[7] = sbox8[state[7]];
}

/*
 * This function implements the permutation with the InvSbox
 *
 * input :
 * state (uint8_t*): it is modified after execution
 *
 * */
void InvSbox(uint8_t* state){
    state[0] = sbox8[state[0]];
    state[1] = sbox8[state[1]];
    state[2] = sbox8[state[2]];
    state[3] = sbox8[state[3]];
    state[4] = sbox8[state[4]];
    state[5] = sbox8[state[5]];
    state[6] = sbox8[state[6]];
    state[7] = sbox8[state[7]];
}

/*
 * This function implements the rotation of nibble by two bytes
 *
 * input :
 * state (uint8_t*): it is modified after execution
 *
 * */
void RotateNibble(uint8_t* state){
    uint8_t temp_state[8];

    temp_state[0] = state[0];
    temp_state[1] = state[1];
    temp_state[2] = state[2];
    temp_state[3] = state[3];
    temp_state[4] = state[4];
    temp_state[5] = state[5];
    temp_state[6] = state[6];
    temp_state[7] = state[7];

    state[0] = temp_state[2];
    state[1] = temp_state[3];
    state[2] = temp_state[4];
    state[3] = temp_state[5];
    state[4] = temp_state[6];
    state[5] = temp_state[7];
    state[6] = temp_state[0];
    state[7] = temp_state[1];
}


/*
 * This function implements the rotation of nibble by two bytes in the other direction
 *
 * input :
 * state (uint8_t*): it is modified after execution
 *
 */
void InvRotateNibble(uint8_t* state){
    uint8_t temp_state[8];

    temp_state[0] = state[0];
    temp_state[1] = state[1];
    temp_state[2] = state[2];
    temp_state[3] = state[3];
    temp_state[4] = state[4];
    temp_state[5] = state[5];
    temp_state[6] = state[6];
    temp_state[7] = state[7];

    state[0] = temp_state[6];
    state[1] = temp_state[7];
    state[2] = temp_state[0];
    state[3] = temp_state[1];
    state[4] = temp_state[2];
    state[5] = temp_state[3];
    state[6] = temp_state[4];
    state[7] = temp_state[5];
};

/*
 * This function checks if two texts have the null difference on the higher nibbles
 *
 * input :
 * state1, state2 (uint8_t*) : the text pair we want to test
 *
 * output :
 * 1 if it is a conforming pair
 * 0 otherwise
 *
 */

int checkConformingPair(uint8_t* state1,uint8_t* state2){
    int i;
    for(i=0; i<8; i++){
        uint8_t diff = state1[i]^state2[i];
        if((uint8_t )diff>15){
            return(0);
        }
    }
    return(1);
}


/*
 * This function checks if two texts have the null difference on the higher nibbles but only on the bytes
 * that you choose
 *
 * input :
 * state1, state2 (uint8_t*) : the pair of texts we want to test
 *
 * output :
 * 1 if it is a conforming pair on the bytes we are studying
 * 0 otherwise
 */
int checkPartConformingPair(uint8_t* state1,uint8_t* state2,int* mask){
    int i;
    for(i=0; i<8; i++){
        if(mask[i]){
            uint8_t diff = state1[i]^state2[i];
            if((uint8_t )diff>15){
                return(0);
            }
        }
    }
    return(1);
}


/*
 * This function allows to find at most a quantity of conforming pairs, this can speed up the
 * process.
 *
 * input :
 *
 * key (uint8_t*): The master key
 * n (unsigned int ) : number of iterations we do in the worst case
 * mask (int*) : used in the checkConforming or PaircheckPartConformingPair function
 * ammount (int) : number of conforming pairs we want to obtain
 *
 * output :
 *
 * list with conforming pairs (uint8_t**)
 *
 */
uint8_t** getConformingPair(uint8_t* key, unsigned int n,int* mask,int ammount){
    int i,j,k;
    uint8_t** texts = malloc(sizeof(uint8_t)*8*60+1);
    uint8_t cipher1[8];
    uint8_t cipher2[8];
    uint8_t message1[8];
    uint8_t message2[8];
    j = 1;
    for(i = 0; i<n; i++){
        if(j>ammount*2+1){
            break;
        }
        uint8_t* messages = generationPt(mask);

        for(k=0;k<16;k++){
            if(k<8){
                message1[k]=messages[k];
            }else if(k>=8){
                message2[k-8]=messages[k];
            }
        }
        free(messages);
        //displayAddText(message1,message2);
        klein64_encrypt(message1, key, cipher1);
        klein64_encrypt(message2, key, cipher2);

        InvMixcolumn(cipher1);
        InvMixcolumn(cipher2);
        //displayAddText(cipher1,cipher2);
        if(checkConformingPair(cipher1,cipher2)){
            // it is possible to unquote this part to examinate the corresponding pairs
/*
            printf("We find a conforming pair at iteration %d : \n",i);
            printf("difference : \n",i);
            displayAddText(cipher1,cipher2);
            printf("plaintext conforming pair : \n",i);
            display(message1);
            display(message2);
            printf("state before last mixcolumn : \n",i);
            display(cipher1);
            display(cipher2);
            printf("-----------------------------------\n");
*/
            texts[j] = memcpy(malloc(sizeof(uint8_t)*8),message1,sizeof(uint8_t)*8);
            texts[j+1] = memcpy(malloc(sizeof(uint8_t)*8),message2,sizeof(uint8_t)*8);

            j+=2;

        }

    }
    texts[0]=j-3;

    printf("   We have found %d pairs  \n\n",(j-3)/2);
    return(texts);
}

/*
 * This function tests the equality of two texts
 *
 * input :
 * text1, text2 (uint8_t*)
 *
 * output :
 * sum of both texts (uint8_t*)
 *
 */

int equals(uint8_t* text1,uint8_t* text2){
    unsigned  int i;
    uint8_t* res = malloc(sizeof(uint8_t)*16);
    for(i=0;i<8;i++){
        if((text1[i]^text2[i])!=0){
            return(0);
        }

    }
    return(1);
}

/*
 * This function allows you to add two texts
 *
 * input :
 * text1, text2 (uint8_t*)
 *
 * output :
 * sum of both texts (uint8_t*)
 *
 */

uint8_t * add_text(uint8_t* text1,uint8_t* text2){
    unsigned  int i;
    uint8_t* res = malloc(sizeof(uint8_t)*16);
    for(i=0;i<16;i++){
        res[i] = text1[i]^text2[i];
    }
    return(res);
}


/*
 * This function is useful because it allows you to generate a key from an integer. This allows loops to be made
 * and enumerate all the keys from an integer loop
 *
 * input :
 * n : unsigned int
 *
 * output :
 * key (uint_8*)
 */
uint8_t* keyGeneration(unsigned int n){
    // char array to store hexadecimal number
    unsigned int i,temp;
    uint8_t* key = malloc(sizeof(uint8_t)*8);
    for(i = 0; i<8;i++){
        key[i]=0;
    }
    // counter for hexadecimal number array
    i = 7;
    while (1) {
        // storing remainder in temp variable.
        if(n<16){
            key[i] = (uint8_t) n;
            break;
        }
        temp = n % 16;

        // check if temp < 10

        key[i] = temp;
        i--;
        n = n / 16;
    }

    return(key);
}


/*
 *
 * This method displays a text that is in the format uint8_t[8].
 *
 * input :
 * state (uint8_t*): text to display
 *
 */
void display(uint8_t* state){
    unsigned int i,j;
    for(i=0;i<8;i++){
        printf("%x ",state[i]);
        if(i%2!=0){
            printf("    ");
        }
    }
    printf("\n");
}


/*
 *
 * This method displays the sum of two texts that are in the format uint8_t[8].
 *
 * input :
 * text1 and text2 (uint8_t*): for which we want to display the sum
 *
 *
 */

void displayAddText(uint8_t* text1,uint8_t* text2){
    unsigned  int i;
    for(i=0;i<8;i++){
        printf("%x ",text1[i]^text2[i]);
        if(i%2!=0){
            printf("    ");
        }
    }
    printf("\n");
}

/*
 *
 * This method displays the key scheduling from the master key
 *
 * input :
 * key (uint8_t*) : master key
 *
 */


void displayRoundKey(uint8_t* key){
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

    printf("Round Key %d\n",0);
    display(round_key);
    //key expansion
    for(i = 1; i <= ROUNDS_64; i++)
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

        printf("Round Key %d\n",i);
        display(round_key);

    }
    printf("-----------------------------------\n");
}


/*
 *
 * This is the function that allows you to find the lower nibbles
 *
 * input :
 * conformingtexts(uint8_t**) : set of conforming pairs
 * part (int) : 1 or 2 -> if we want to attack the first or the second Mixcolumn
 * output :
 * Set of potential key (uint8_t**)
 *
 *
 */

 uint8_t** keyRecoveryPart(const uint8_t** conformingtexts,int part){
    unsigned int i,j,n;
    n = (unsigned int) pow(2,16);
    int* keyTable = malloc(sizeof(int)*n);
    uint8_t** candidatKey = malloc(sizeof(int)*n);
    int* mask = malloc(sizeof(int)*8);
    if(part == 1){
        mask[0]=1;
        mask[1]=1;
        mask[2]=1;
        mask[3]=1;
        mask[4]=0;
        mask[5]=0;
        mask[6]=0;
        mask[7]=0;

    } else if (part == 2){
        mask[0]=0;
        mask[1]=0;
        mask[2]=0;
        mask[3]=0;
        mask[4]=1;
        mask[5]=1;
        mask[6]=1;
        mask[7]=1;
    }

    for(i = 0; i<n;i++){
        keyTable[i]=0;
    }

    int nb = conformingtexts[0];
    nb = nb/2;
    for (i = 0 ; i < nb; i++){


        uint8_t *message1 = memcpy(malloc(sizeof(uint8_t)*8),conformingtexts[i*2+1],sizeof(uint8_t)*8);
        uint8_t *message2 = memcpy(malloc(sizeof(uint8_t)*8),conformingtexts[(i+1)*2],sizeof(uint8_t)*8);

        //displayAddText(message1,message2);
        //displayAddText(cipher1,cipher2);

        for (j = 0; j < n; j++) {
            uint8_t *keyGuess = keyGeneration(j);
            if(part == 1){
                RotateNibble(keyGuess);
            } else if (part == 2){
                InvRotateNibble(keyGuess);
            }

            uint8_t* state1 = add_text(message1,keyGuess);
            uint8_t* state2 = add_text(message2,keyGuess);
            Sbox(state1);
            Sbox(state2);

            RotateNibble(state1);
            RotateNibble(state2);

            Mixcolumn(state1);
            Mixcolumn(state2);

            if (checkPartConformingPair(state1, state2,mask)) {
                //displayAddText(state2,state1);
                keyTable[j] += 1;
            }
            free(keyGuess);
            free(state1);
            free(state2);
        }
        free(message2);
        free(message1);
    }


    int p,m;
    candidatKey[1] = 0;
    m = 0;
    p = 1;
    for (i = 0; i < n; i++) {
        if (keyTable[i] > m) {
            p = 1;
            uint8_t* keyCand = keyGeneration(i);
            if(part == 1){
                RotateNibble(keyCand);
            }else if(part == 2){
                InvRotateNibble(keyCand);
            }
            candidatKey[p] = memcpy(malloc(sizeof(uint8_t)*8),keyCand,sizeof(uint8_t)*8);
            free(keyCand);
            m = keyTable[i];
            p++;
        } else if (keyTable[i] == m) {
            uint8_t* keyCand = keyGeneration(i);
            if(part == 1){
                RotateNibble(keyCand);
            }else if(part == 2){
                InvRotateNibble(keyCand);
            }
            candidatKey[p] = memcpy(malloc(sizeof(uint8_t)*8),keyCand,sizeof(uint8_t)*8);
            free(keyCand);
            p++;
        }
    }
    candidatKey[0]=p-1;
    for (i = 1; i < p; i++) {
        display(candidatKey[i]);
    }

    free(keyTable);
    free(mask);
    printf("############  END PART %d #####################\n\n",part);

     return(candidatKey);

}

/*
 *
 * This is the function that allows you to find the top nibbles by brute force
 *
 * input :
 * keysLowerNibble(uint8_t*): the lowers nibbles we found
 * message (uint8_t*): input message from KLEIN64
 * cipher (uint8_t*): output of the message from KLEIN64
 * output :
 * good key if found
 *
 *
*/


uint8_t* keyBruteFroce(uint8_t* keysLowerNibble, uint8_t* message, uint8_t* cipher){
    unsigned int j;
    unsigned int i;
    uint8_t cipherTry[8];
    uint8_t* NotFind = malloc(sizeof(uint8_t)*8);
    for(i=0;i<8;i++){
        NotFind[i] = 0;
    }
    int keepGoing;
    unsigned int n  = (unsigned int ) pow(2,32);
    for(i = 0; i<n;i++){
        uint8_t* tryKey = keyGeneration(i);
        for(j=0;j<8;j++){
            tryKey[j] = (tryKey[j]<<4)^(keysLowerNibble[j]);
        }
        klein64_encrypt(message,tryKey,cipherTry);

        keepGoing = 0;
        for(j=0;j<8;j++){
            if(cipherTry[j]!=cipher[j]){
                keepGoing = 1;
            }
        }
        if(keepGoing==0){
            return(tryKey);
        }else{
            free(tryKey);
        }
    }
    printf("we don't find the right key\n");
    return(NotFind);

}

