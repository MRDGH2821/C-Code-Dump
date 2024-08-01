#include <stdio.h>

int main(void)
{
   char buff[15];
   int  pass = 0;

   printf("\nEnter the password : \n");
   gets(buff);
   if (strcmp(buff, "thegeekstuff"))
   {
      printf("\nWrong Password\n");
   }
   else
   {
      printf("\nCorrect Password\n");
      pass = 1;
   }
   if (pass)
   {
      printf("\nRoot privileges given to the user \n");
   }
   return 0;
}
