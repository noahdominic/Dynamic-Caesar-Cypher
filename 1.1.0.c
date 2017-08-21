#include <stdio.h>

char* encrypt(char*, int);
int main(void) {
    char phrase_raw[100], encrypted[100];
    char* phrase_encrypted;
    unsigned int shift = 0, i =0;
    printf("Hello. This is a Dynamic Caesar Generator. \nPlease enter the initial shift: ");
    scanf("%i", &shift);
    printf("Please enter the text to be encrypted: ");
    scanf(" %[^\n]s", phrase_raw);
    phrase_encrypted = encrypt(phrase_raw, shift);
    printf("Here is your encrypted text          : %s", phrase_encrypted);
    return 0;
}

char* encrypt(char *raw, int shift) {
    char* encrypted;
    int i = 0;
    do {
        if(raw[i] >= 'A' && raw[i] <= 'Z'){
            encrypted[i] = ((raw[i] - 'A') + shift) % 26 + 'A';
        }
        else {
            encrypted[i] = raw[i];
        }
        shift++;
        i++;
    } while (raw[i] != '\0');
    encrypted[i] = raw[i];
    return encrypted;
}
