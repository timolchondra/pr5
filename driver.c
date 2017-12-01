#include "pr5.h"
////////////////////////////////////////////////////////////////////////////////////////
///            __________                   __               __     .________        ///
///            \______   \_______  ____    |__| ____   _____/  |_   |   ____/        ///
///             |     ___/\_  __ \/  _ \   |  |/ __ \_/ ___\   __\  |____  \         ///
///             |    |     |  | \(  <_> )  |  \  ___/\  \___|  |    /	\            ///
///             |____|     |__|   \____/\__|  |\___  >\___  >__|   /______  /        ///
///                                    \______|    \/     \/              \/         ///
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
///   This was made by Tim Olchondra and Jake McKenzie. Jake ran the file on         ///
///   Ubuntu 16.4 and Tim ran it on Windows. Both used gcc -std=gnu90 driver.c       ///
///   pr5.c                                                                          ///
////////////////////////////////////////////////////////////////////////////////////////

int main(void) {
  
  int userinput = 1, filesize;
  
  FILE* fptr = fopen("animals.dat","rb+");

  if(fptr == NULL) {

    printf("File does not exist");

    return -1;

  }

////////////////////////////////////////////////////////////////////////////////////////  
///   This is how we get the size of the file to use in our functions.               ///
////////////////////////////////////////////////////////////////////////////////////////  
  
  fseek(fptr, 0, SEEK_END);

  filesize = ftell(fptr);

  rewind(fptr);
  
  while(userinput != 0) {

    printf("Enter your input: ");

    scanf("%d", &userinput);
  
    while(getchar() != '\n');
    
    if(userinput != 0 && userinput != 1 && userinput != 2 && userinput != 3 && userinput != 4 && userinput != 5) {

      printf("Wrong input please try again\n");

    }
    
////////////////////////////////////////////////////////////////////////////////////////  
///   This is where we call each function.                                           ///
////////////////////////////////////////////////////////////////////////////////////////

    if(userinput == 1) {
  
      function1(fptr,filesize);

    }

    if(userinput == 2) {
    
     function2(fptr,filesize);
     
    }

    if(userinput == 3) {

    function3(fptr,filesize);

    }

    if(userinput == 4) {

      function4(fptr,filesize);

    }

    if(userinput == 5) {

      function5(fptr,&filesize);

    }

  }

  printf("Have a good weekend\n");

  fprintfCSV(fptr, filesize);

  fclose(fptr);

  return 0;
}
