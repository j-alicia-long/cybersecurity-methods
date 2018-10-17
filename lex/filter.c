/*
Jennifer Long
CS 4630 Assignment 4
10/11/2018
infect.c
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
