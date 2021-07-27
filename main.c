#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* revThisString(char *string)
{
  /* To this is my function to reverse a word,
     which I will call once per word in the buffer */
  /* const int* myLength = sizeof(string) / sizeof(string[0]); */

  static char reversed[10];
  /* This hard coded 5 needs to be fixed */

  int j = 0;

  /* Ths 5 below is hard coded and needs to be fixed */
  for(int i = 10; i > -1;)
    {
      reversed[j] = string[i];
      i = i - 1;
      j = j + 1;
    }
  return reversed;
}

int ReverseText(FILE *FileIn, FILE *FileOut)
{
  int lSize;
  char* buffer;

  fseek( FileIn , 0L , SEEK_END);
  lSize = ftell( FileIn);
  rewind( FileIn );
  /* Getting the size of the text I am working with */

  buffer = calloc( 1, lSize+1 );
  if( !buffer ) fclose(FileIn),fputs("memory alloc fails",stderr),exit(1);

  if( 1!=fread( buffer , lSize, 1 , FileIn) )
    fclose(FileIn),free(buffer),fputs("entire read fails",stderr),exit(1);

  /* This makes an array called buffer for holding all the chars */

   const char delim[2] = " ";
   char *element = strtok(buffer, delim);
   char *normalWords[10];
   int i = 0;

   while( element != NULL ) {
     normalWords[i++] = element;
     element = strtok(NULL, delim);
   }
   /* This splits all the "words" into an array called normalWords */
   /*   so they can be reversed by calling reversr on them */

for(int m = 0; m < 9; m++){
  fprintf(FileOut,"%s",revThisString(normalWords[m]));
  fprintf(FileOut," ");
  }
/* writting the words to the file    */

 free(buffer);

  return 0;
}

int main(void)
{

  FILE *in, *out;

  in = fopen("FoxDog.txt" , "r");

  if ( !in ) {

    perror("FoxDog.txt");

    exit(1);

  }

  out = fopen("TextReverse.txt", "w");

  if (out == NULL) {

    fclose(in);

    printf("file can't be opened\n");

    exit(1);

  }

  ReverseText(in, out);

  fclose(out);

  fclose(in);

  return 0;

}
