#include "pr5.h"

void function1(FILE *fptr,int filesize) {
  //int z;

  char current;

  int a, b = 1;

  for (a = 0; a < filesize; a++) {

    fread(&current,sizeof(char),1,fptr);

    if(((int) current) >= 32 && ((int) current) <= 127) {

      printf("%c",current);
      b++;

    }

    printf(" ");

    b++;

    if (b > 80) {

      printf("\n");

      b = 0;

    }
       
  }

  printf("\n");

  rewind(fptr);

}
void function2(FILE *fptr, int filesize) {
  int temp, i, j=0;
 
  
  for(i = 0; i < filesize/4; i++) {
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
void function3(FILE *fptr,int filesize) {
  int i;
  char buffer;
  short int findid;
  
  printf("Please input the id you want to search for: ");
  scanf("%hd", &findid);
  buffer = getchar();
  Animal animal;
  
  if(findid * sizeof(Animal) <= filesize) {
    fseek(fptr, sizeof(Animal)* (findid - 1), SEEK_SET);
    fread(&animal, sizeof(Animal),1,fptr);
    
    printf("%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age);
  } else {
    printf("Can't find id. Please try again.\n");
  }
  rewind(fptr);
}

void function4(FILE *fptr,int filesize) {
  Animal animal;
  int a, b;
  short int c;
  char buffer;
  
  printf("Enter the id you want to add: ");
  scanf("%hd",&animal.id);
  buffer = getchar();
  
  printf("Enter the name you want to add: ");
  scanf("%[^\n]",animal.name);
  buffer = getchar();
  
  printf("Enter the species you want to add: ");
  scanf("%[^\n]",animal.species);
  buffer = getchar();

  printf("Enter the size you want the add: ");
  scanf("%c", &animal.size);
  buffer = getchar();

  printf("Enter the age you want the add: ");
  scanf("%hd", &animal.age);
  buffer = getchar();

  if(animal.id * sizeof(Animal) <= filesize) {
    fseek(fptr, sizeof(Animal)* (animal.id - 1), SEEK_SET);
    fwrite(&animal, sizeof(Animal), 1, fptr);
    printf("%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age);
  } else {
    printf("Can't find id. Please try again.\n");
  }
  
  
  
  rewind(fptr);
  
}

void function5(FILE *fptr,int *filesize) {
  Animal animal;
  int i, locate;
  short int findid;
  char buffer;

  
  printf("Enter the id you want to delete: ");
  scanf("%hd",&findid);
  buffer = getchar();
  
  
  if(findid * sizeof(Animal) <= *filesize) {
    fseek(fptr, findid * sizeof(Animal), SEEK_SET);
    locate = ftell(fptr) - sizeof(Animal);
    
    for(i = 0; i < (*filesize - locate - sizeof(Animal))/sizeof(Animal); i++) {
      fread(&animal, sizeof(Animal), 1, fptr); 
      animal.id--;
      
      fseek(fptr,  - sizeof(Animal)*2,SEEK_CUR);
      fwrite(&animal, sizeof(Animal), 1, fptr);
  
      fseek(fptr, sizeof(Animal), SEEK_CUR);
    }
  
    truncate("animals.dat", *filesize - sizeof(Animal));
    fseek(fptr,0,SEEK_END);
    *filesize = ftell(fptr);
    rewind(fptr);
  } else {
    printf("Can't find id. Try again\n");
  }
}
void fprintfCSV(FILE *fptr, int filesize) {
  int i;
  Animal animal;
  FILE* animalscsv = fopen("animals.csv","w");
  
  for(i = 0; i < filesize/sizeof(Animal); i++) {
    fread(&animal, sizeof(Animal), 1, fptr);
    fprintf(animalscsv,"%hd,%s,%s,%c,%hd\n", animal.id, animal.name, animal.species, animal.size, animal.age);
  
  }
  fclose(animalscsv);
}

  
  
  
 
