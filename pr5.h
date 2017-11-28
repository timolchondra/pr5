#ifndef pr5
#define pr5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#pragma pack(1)

struct animal {
  short int id;
  char name[20];
  char species[35];
  char size;
  short int age;
};

typedef struct animal Animal;

void function1(FILE *fptr,int count);
void function2(FILE *fptr,int count);
void function3(FILE *fptr,int count);
void function4(FILE *fptr,int count);
void function5(FILE *fptr,int count);
void fprintfCSV(FILE *fptr, int count);


#endif
