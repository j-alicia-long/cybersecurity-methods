/*
Jennifer Long
CS 4630 HW5: Lex
10/17/2018
filter.c
*/

#include <stdio.h>
#include <ctype.h>

int main() {
  freopen(NULL, "rb", stdin);
  if (stdin != NULL) {
    int ch;
    while ((ch = fgetc(stdin)) != EOF) {
      printf("%02x", ch);
    }
  }
  return 0;
}
