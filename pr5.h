#ifndef pr5
#define pr5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#pragma pack(1)
//This initializes the structs and functions used by our driver.c and pr5.c 
struct animal {
  short int id;
  char name[20];
  char species[35];
  char size;
  short int age;
};

typedef struct animal Animal;

void function1(FILE *fptr,int filesize);
void function2(FILE *fptr,int filesize);
void function3(FILE *fptr,int filesize);
void function4(FILE *fptr,int filesize);
void function5(FILE *fptr,int *filesize);
void fprintfCSV(FILE *fptr, int filesize);


#endif
