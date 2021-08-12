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

int main() {
  char ch;
  FILE *fp;
  FILE *out;

  fp = fopen("FoxDog.txt", "r");
  out = fopen("TextReverse.txt", "w");

  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  int breakme = 0;
  while (breakme == 0) {
    print_next_word(fp, out);
    if (feof(fp)) {
      breakme = 1;
      break;
    }
  }

  fclose(fp);
  fclose(out);
  return 0;
}
