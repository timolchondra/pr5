#include <stdio.h>

int main(void) {
  
   FILE *fileP;

   int z;

   char current;
   
   fileP = fopen("animals.dat", "rb");

   if(fileP == NULL )  {

     printf("Error opening file\n");

     return(-1);

   }

   fseek(fileP, 0, SEEK_END);

   z = ftell(fileP);

   rewind(fileP);
   
   int a, b = 1;

   for (a = 0; a < z; a++) {

     fread(&current,sizeof(char),1,fileP);

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

   fclose(fileP);
  
   return(0);
}
