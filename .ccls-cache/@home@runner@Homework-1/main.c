// Completed by Samuel Walsh

#include <stdio.h>
#include "util.h"

#define FILE_SIZE 60
#define READER_SIZE 60

int main(int argc, char *argv[]) {
  // Create buffers for file names
  char inputFile[FILE_SIZE];
  char outputFile[FILE_SIZE];

  // Get input and output file names
  printf("Type the input file name\n");
  fgets(inputFile, FILE_SIZE, stdin);
  printf("Type the output file name\n");
  fgets(outputFile, FILE_SIZE, stdin);

  // Setup file structs for input and output
  char temp[FILE_SIZE+50];
  strcat(temp, DEFAULT_IN);
  strcat(temp, inputFile);
  FILE *input = fopen(temp, "r");
  
  temp[0] = '\0';
  strcat(temp, DEFAULT_OUT);
  strcat(temp, outputFile);
  //FILE *output = fopen(temp, "w");
  stdin = input;

  // Create buffer for file contents
  char reader[READER_SIZE];
  do {
    scanf("%s",reader); 
    for (int i = 0; i < READER_SIZE; i++) {
      char temp;
      if(argc > 1)
        temp = applyModee(reader[i], argv[1]);
      else
        temp = applyModee(reader[i], "none");

      printf("%c",temp);
      //for (int i = 0; i < argc; i++) {
     //   printf("%d: %s\n", i, argv[i]);
      //}
    }
  } while(reader[0] != '\0');

  // Close files (fclose(input); will error if input file is invalid)
  fclose(input);
  //fclose(output);

  return 0;
}