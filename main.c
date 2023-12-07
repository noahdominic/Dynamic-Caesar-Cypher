/*
 * main.c (Dynamic Caesar Cypher)
 *
 * A program containing functions for letter checking, modulo operation,
 * and text encryption.
 *
 * Written by: Noah Dominic Miranda Silvio
 *
 * Copyright (c) 2017, 2023  Noah Dominic Miranda Silvio
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1.  Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.   IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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

    printf("Here is your encrypted text     : %s\n", phrase);
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
