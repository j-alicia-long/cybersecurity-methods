#include <stdio.h>
#include <string.h>
char attackString[] = "Ministry of Magic\n";
int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
 putchar(*p);
 p++;
 }
 return 1;
}
