#include <stdio.h>

char* encrypt(char*, int);
int main(void) {
    char phrase_raw[100];
    char* phrase_encrypted;
    unsigned int shift = 0, i = 0;
    unsigned int taskChoice = 0;
    printf("Hello! \nThis is a Dynamic Caesar Cypher Generator. What would you like to do? \n1 - Encrypt\n2 - Decrypt\nOther - Exit");
    scanf("%i", &taskChoice);
    if(taskChoice == 1){
        printf("Please enter the initial shift: ");
        scanf("%i", &shift);
        printf("Please enter the text to be encrypted: ");
        scanf(" %[^\n]s", phrase_raw);
        phrase_encrypted = encrypt(phrase_raw, shift);
        printf("Here is your encrypted text          : %s", phrase_encrypted);
        free(phrase_encrypted);
    } else if(taskChoice == 2) {
        //TODO insert call for decrypt function here
    } else {
        exit(EXIT_SUCCESS);
    }
    return 0;
}

// accepts a clean, raw phrase to be encrypted and an initial shift value, returns pointer to the encrypted phrase
char* encrypt(char *raw, int shift) {
    char* encrypted;
    encrypted = (char *)malloc(strlen(raw) + 1);
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
