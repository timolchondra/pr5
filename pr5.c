#include "pr5.h"

void function1(FILE *fptr,int count);
void function2(FILE *fptr, int count) {
  int temp, i, j=0;
 
  
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
void function3(FILE *fptr,int count) {
  int i;
  char buffer;
  short int findid;
  
  printf("Please input the id you want to search for: ");
  scanf("%hd", &findid);
  buffer = getchar();
  Animal animal;
  
  if(findid * sizeof(Animal) <= count){
    fseek(fptr, sizeof(Animal)* (findid - 1), SEEK_SET);
    fread(&animal, sizeof(Animal),1,fptr);
    
    printf("%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age);
  } else {
    printf("Can't find id. Please try again.\n");
  }
  
  
  
 /* for(i=0; i < count/sizeof(Animal); i++) {
    fread(&animal, sizeof(Animal), 1, fptr);
    
    if(animal.id == findid) {
      printf("%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age); 
      break;
    }
  }
  
  if(i > count/sizeof(Animal) - 1){
    printf("Can't find id. Try Again\n");
  }*/
  rewind(fptr);
}
void function4(FILE *fptr,int count);

void function5(FILE *fptr,int *count) {
  Animal animal;
  int i, locate;
  short int findid;
  char buffer;

  
  printf("Enter the id you want to delete: ");
  scanf("%hd",&findid);
  buffer = getchar();
  
  
  
  /*for(i=0; i < *count/sizeof(Animal); i++) {
    fread(&animal, sizeof(Animal), 1, fptr);     
    if(animal.id == findid) {
      locate = ftell(fptr) - sizeof(Animal);
      break;
    }
  }
  if(i > *count/sizeof(Animal) - 1){
    printf("Can't find id. Try Again\n");
    exit(0);
  }*/
  
  
  if(findid * sizeof(Animal) <= *count) {
    fseek(fptr, findid * sizeof(Animal), SEEK_SET);
    locate = ftell(fptr) - sizeof(Animal);
    
    for(i = 0; i < (*count - locate - sizeof(Animal))/sizeof(Animal); i++) {
      fread(&animal, sizeof(Animal), 1, fptr); 
      animal.id--;
      
      fseek(fptr,  - sizeof(Animal)*2,SEEK_CUR);
      fwrite(&animal, sizeof(Animal), 1, fptr);
  
      fseek(fptr, sizeof(Animal), SEEK_CUR);
    }
  
    truncate("animals.dat", *count - sizeof(Animal));
    fseek(fptr,0,SEEK_END);
    *count = ftell(fptr);
    rewind(fptr);
  } else {
    printf("Can't find id. Try again\n");
  }
}
void fprintfCSV(FILE *fptr, int count) {
  int i;
  Animal animal;
  FILE* animalscsv = fopen("animals.csv","w");
  
  for(i = 0; i < count/sizeof(Animal); i++) {
    fread(&animal, sizeof(Animal), 1, fptr);
    fprintf(animalscsv,"%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age);
  
  }
  fclose(animalscsv);
}

  
  
  
 
