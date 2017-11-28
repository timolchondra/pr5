#include "pr5.h"

int main() {
  int userinput = 1, count;
  FILE* fptr = fopen("animals.dat","rb+");
  if(fptr == NULL) {
    printf("File does not exist");
    return -1;
  }
  fseek(fptr, 0, SEEK_END);
  count = ftell(fptr);
  rewind(fptr);
  
  while(userinput != 0) {
    printf("Enter your input: ");
    scanf("%d", &userinput);
  
    while(getchar() != '\n');
    
    if(userinput != 0 && userinput != 1 && userinput != 2 && userinput != 3 && userinput != 4 && userinput != 5) {
      printf("Wrong input please try again\n");
    }
    if(userinput == 1) {
      //read as ascii
    }
    if(userinput == 2) {
     //read as int
     function2(fptr,count);
     
    }
    if(userinput == 3) {
     //animal stuff
     function3(fptr,count);
    }
    if(userinput == 4) {
      //other stuff
    }
    if(userinput == 5) {
      //stuff
      function5(fptr,count);
    }
  }
  fprintfCSV(fptr, count);
  fclose(fptr);
  return 0;
}
