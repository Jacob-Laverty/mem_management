#ifndef TOKENS_H
#define TOKENS_H

//Lex uses 0 to return an EOF...
#define LEX_EOF 0

//Defines for memory initialization
#define MEMORY_SIZE 1
#define MEMORY_POLICY 2
#define POLICY 3

//Defines for process initialization
#define PID 4
#define ARRIVAL 5
#define LIFETIME 6
#define ADDRESS 7

//Defines for mem policies
#define VSP_TOKEN 8
#define PAG_TOKEN 9
#define SEG_TOKEN 10

//Defines for mem policy parameters
#define FF_TOKEN 0
#define BF_TOKEN 1
#define WF_TOKEN 2

#endif
