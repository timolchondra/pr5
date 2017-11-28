#include "pr5.h"

void function1(FILE *fptr);
void function2(FILE *fptr) {
  int temp, count, i, j=0;
  fseek(fptr, 0, SEEK_END);
  count = ftell(fptr);
  rewind(fptr);
  
  for(i = 0; i < count/4; i++) {
    fread(&temp, sizeof(int), 1, fptr);
    printf("%d ", temp);
    j++;
    
    if(j>80/5) {
      printf("\n");
      j=0;
    }
  }
  printf("\n");
  rewind(fptr);
}
void function3(FILE *fptr) {
  int i, count;
  char buffer;
  short int findid;
  fseek(fptr, 0, SEEK_END);
  count = ftell(fptr);
  rewind(fptr);
  
  printf("Please input the id you want to search for: ");
  scanf("%d", &findid);
  buffer = getchar();
  Animal animal;
  for(i=0; i < count/sizeof(Animal); i++) {
    fread(&animal.id, sizeof(animal.id),1,fptr);
    fread(animal.name, sizeof(animal.name),1,fptr);
    fread(animal.species,sizeof(animal.species),1,fptr);
    fread(&animal.size,sizeof(animal.size),1,fptr);
    fread(&animal.age,sizeof(animal.age),1,fptr);
    
    if(animal.id == findid) {
      printf("%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age); 
      break;
    }
  }
  if(i > count/sizeof(Animal) - 1){
    printf("Can't find id. Try Again\n");
  }
  
}
void function4(FILE *fptr);
void function5(FILE *fptr);
