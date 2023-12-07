#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 500
#define ISALPHAUPPER 1
#define ISALPHALOWER 2
#define ISALPHANOT 0

int is_a_letter(const char c);
int modulo(const int m, const int n);
int encrypt(char phrase[], int shift, int mode);

int main(void) {
  printf("%i\n", modulo(-1, 10));
  char phrase[MAX_CHARS];
  int shift, taskChoice;

  printf("Hello! \n"
         "This is a Dynamic Caesar Cypher Generator.\n"
         "What would you like to do? \n"
         "1 - Encrypt\n"
         "2 - Decrypt\n"
         "Other - Exit\n"
         "> ");
  scanf("%i", &taskChoice);

  if (taskChoice == 1) {
    printf("Please enter the text you want to encrypt: ");
    scanf(" %[^\n]s", phrase);

    printf("Please enter the initial shift: ");
    scanf("%i", &shift);

    encrypt(phrase, shift, 1);

    printf("Here is your encrypted text          : %s\n", phrase);
  } else if (taskChoice == 2) {
    printf("Please enter the initial shift: ");
    scanf("%i", &shift);

    printf("Please enter the text you want to decypher: ");
    scanf(" %[^\n]s", phrase);

    encrypt(phrase, shift, 0);

    printf("Here is your decrypted text...............: %s\n", phrase);
  }

  return 0;
}

int is_a_letter(const char c) {
  if (c >= 'A' && c <= 'Z') {
    return ISALPHAUPPER;
  } else if (c >= 'a' && c <= 'z') {
    return ISALPHALOWER;
  }

  return ISALPHANOT;
}

int modulo(const int n, const int M) { return ((n % M) + M) % M; }

int encrypt(char phrase[], int shift, int is_encrypt) {
  int i;

  int is_encrypt_multiplier = is_encrypt ? 1 : -1;

  for (i = 0; phrase[i] != '\0'; i++) {
    int is_alpha;
    if ((is_alpha = is_a_letter(phrase[i]))) {
      char first_letter = is_alpha == ISALPHAUPPER ? 'A' : 'a';
      /* NB: shift and 26 are ints here, while the rest of the
         equation are chars.  Will this cause a problem down
         the line?  I've casted the variables but will this
         also cause problems? */
      phrase[i] = modulo(phrase[i] - first_letter +
                             ((char)shift * is_encrypt_multiplier),
                         26) +
                  first_letter;
    }
    shift++; /* Hide just a tiny bit more complexity :) Shift even
                        if the character is NOT a letter*/
  }

  return 0;
}
