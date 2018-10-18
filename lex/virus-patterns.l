
%{
/*
 * Jennifer Long
 * CS 4630 HW5: Lex
 * 10/17/2018
 * virus-patterns.l
 * This program scans for three viruses: Wahoo, Cavalier, and Rotunda
 */
 int byteCount = 0;
%}
%%
68[a-zA-Z0-9]{8}c3        printf("WARNING! Tricky Jump: byte number: 0x%x\n%s\n\n", byteCount, yytext); byteCount+=6;
bc[a-zA-Z0-9]{8}31363126  printf("WARNING! Cavalier Virus: byte number: 0x%x\n%s\n\n", byteCount, yytext); byteCount+=9;
89ec50583b45fe            printf("WARNING! Rotunda Virus: byte number: 0x%x\n%s\n\n", byteCount, yytext); byteCount+=7;

[a-zA-Z0-9]{2}            byteCount++;

. ;
%%

main(){
  yylex();
//  printf("Total bytes in file: %d\n", byteCount);
}
