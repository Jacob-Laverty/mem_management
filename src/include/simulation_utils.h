#ifndef MEM_UTILS_H
#define MEM_UTILS_H
#include <stdlib.h>
#include <stdio.h>
#include "tokens.h"

#define MAX_PROCESSES 20
#define DEBUG 1

//Defines for reading files with lex.
int yylex();

// Gotta be careful with these. Lex doesn't give you an option to grab the text.
// Its set to yytext when you call yylex(); and then you kinda just access it...sketchy...
extern char* yytext;
extern FILE* yyin;

void set_input(char* file);
void set_output(char* file);
void write_to_output(char* output);
int read_input();
void debug(char* debug);

char* get_token();
int get_token_value();
#endif
