#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  FILE *fp;
  long lSize;
  char *buffer;

  fp = fopen ( "FoxDog.txt" , "r" );
  if( !fp ) perror("FoxDog.txt"),exit(1);

  fseek( fp , 0L , SEEK_END);
  lSize = ftell( fp );
  rewind( fp );

  buffer = calloc( 1, lSize+1 );
  if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

  if( 1!=fread( buffer , lSize, 1 , fp) )
    fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

/* do your work here, buffer is a string contains the whole text */
   const char delim[2] = " ";
   char *element = strtok(buffer, delim);
   char *normalWords[10];
   int i = 0; 
      
   while( element != NULL ) {
     normalWords[i++] = element;
     element = strtok(NULL, delim);
   }
/* At this point, all the words of the file are in normalWords. Need to write reversed versions to the file I am about to defie below */

   char result[9][20];
   for(int i = 0; i < 9; i++){
     int j = 0;
     int k = 0;
     int theIndex = 0;
     while (normalWords[i][k] != '\0'){
       j++;
       k++;
     };
     /* hacky way of getting the legnth of this element into j */
     k = 0;
     
     while (normalWords[i][k] != '\0'){
       theIndex = (j - k) -1;
       result[i][k] = normalWords[i][theIndex];
       k++;
     };
     result[i][k] = '\0';
   };
/* wish this could have been cleaner */
   
   FILE *out;
   out = fopen("Reversed.txt", "w");
  
   if(out == NULL) {
     printf("file can't be opened\n");
     exit(1);
   }

for(int m = 0; m < 9; m++){
  fprintf(out,"%s",result[m]);
  fprintf(out," ");
  }
   
   fclose(out);
   fclose(fp);
   free(buffer);

   return 0;
}
