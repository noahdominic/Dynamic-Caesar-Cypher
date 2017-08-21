#include <stdio.h>

char* encrypt(char*, int);

int main(void) {
    char phrase_raw[100], phrase_encrypted[100];
    char* phrase_encrypted2;
    unsigned int shift = 0, i =0;
    printf("Hello. This is a Dynamic Caesar Generator. \nPlease enter the initial shift: ");
    scanf("%i", &shift);
    printf("Please enter the text to be encrypted: ");
    scanf(" %[^\n]s", phrase_raw);
    phrase_encrypted2 = encrypt(phrase_raw, shift);
    // do {
    //     if(phrase_raw[i] >= 'A' && phrase_raw[i] <= 'Z'){
    //         phrase_encrypted[i] = ((phrase_raw[i] - 'A') + shift) % 26 + 'A';
    //     }
    //     else {
    //         phrase_encrypted[i] = phrase_raw[i];
    //     }
    //     shift++;
    //     i++;
    // } while (phrase_raw[i] != '\0');
    // phrase_encrypted[i] = phrase_raw[i];
    //phrase_encrypted2 = dynamicCaesarEncrypt(phrase_raw,  shift);
    printf("Here is your encrypted text          : %s", phrase_encrypted2);
    return 0;
}

char* encrypt(char *phrase_raw, int shift) {
    char* phrase_encrypted;
    int i = 0;
    do {
        if(phrase_raw[i] >= 'A' && phrase_raw[i] <= 'Z'){
            phrase_encrypted[i] = ((phrase_raw[i] - 'A') + shift) % 26 + 'A';
        }
        else {
            phrase_encrypted[i] = phrase_raw[i];
        }
        shift++;
        i++;
    } while (phrase_raw[i] != '\0');
    phrase_encrypted[i] = phrase_raw[i];
    return phrase_encrypted;
}
