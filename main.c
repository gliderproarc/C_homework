#include <stdio.h>
#include <stdlib.h>

void print_next_word(FILE *filePointer, FILE *outPointer) {
  char word[10];
  char stopper = 'a';
  int i = 0;
  int length = 0;
  while (stopper != ' ') {
    word[i] = fgetc(filePointer);
    stopper = word[i];
    if (feof(filePointer)) {
      word[i] = ' ';
      i++;
      break;
    }
    i++;
  }
  length = i;
  int j = 0;
  i = i - 1;
  for (j = 0; j < length;) {
    fprintf(outPointer, "%c", word[i]);
    j++;
    i = i - 1;
  }
}

int main(int argc, char *argv[])
{
  FILE *in, *out;

  /* printf("P name %s\n", argv[0]); */
  /* printf("p1 is %s\n", argv[1]); */
  /* printf("p2 is %s\n", argv[2]); */

  in = fopen(argv[1], "r");
  out = fopen(argv[2], "w");

  if (in == NULL) {
    printf("file can't be opened.\n");
    exit(1);
  }

  if (out == NULL) {
    printf("file can't be opened.\n");
    exit(1);
  }

  int breakme = 0;
  while (breakme == 0) {
    print_next_word(in, out);
    if (feof(in)) {
      breakme = 1;
      break;
    }
  }

  fclose(in);
  fclose(out);
  return 0;
}
