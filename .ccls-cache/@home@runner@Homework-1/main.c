// Completed by Samuel Walsh

#include <string.h>
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
	inputFile[strlen(inputFile) - 1] = 0; // change \n to null
	outputFile[strlen(outputFile) - 1] = 0;

  // Setup file structs for input and output
	int fileLength = strlen(DEFAULT_IN) + strlen(inputFile) + 1;
	printf("A%d\n", fileLength);
  char inputName[fileLength];
  strcat(inputName, DEFAULT_IN);
  strcat(inputName, inputFile);
  strcat(inputName, "\0");
  printf("this %s %d\n",inputName, strcmp("/home/runner/Homework-1/infiles/hello",inputName));
  FILE *input = fopen(inputName, "r");
  if (input != NULL) printf("input is defined\n");
  if (input == NULL) printf("input not defined\n");
  
	fileLength = strlen(DEFAULT_OUT) + strlen(outputFile) + 1;
  char outputName[fileLength];
  strcat(outputName, DEFAULT_OUT);
  strcat(outputName, outputFile);
  printf("%s %d",outputName, strcmp("infiles/hello",outputName));
  FILE *output = fopen(outputName, "w");
  if (output == NULL) printf("output not defined\n");
  if (output != NULL) printf("output is defined\n");
  
  //stdin = input;
  //stdout = output;
/*
  // Create buffer for file contents
  char reader[READER_SIZE];
  while(fgets(reader, READER_SIZE, input)!=NULL) { // fgets did not read anything new
    
    //scanf("%s",reader); 
    for (int i = 0; i < READER_SIZE; i++) {
      char writeChar;
//      if(argc > 1)
//        writeChar = applyMode(reader[i], argv[1]);
 //     else
//        writeChar = applyMode(reader[i], "none");

      printf("%c",writeChar);
      //for (int i = 0; i < argc; i++) {
     //   printf("%d: %s\n", i, argv[i]);
      //}
    }
  } while(reader[0] != '\0');

  // Close files (fclose(input); will error if input file is invalid)
  fclose(input);
  fclose(output);
//*/
  return 0;
}





