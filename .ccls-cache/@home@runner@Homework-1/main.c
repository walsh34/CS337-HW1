// CS337 Homework 1
// Completed by Samuel Walsh

#include <string.h>
#include <stdio.h>
#include "util.h"

#define FILE_SIZE 60
#define READER_SIZE 20

int main(int argc, char *argv[]) {
	// Make sure at least one additional argument is given
	if (argc <= 1) {
		printf("Not enough arguments to run program, Terminating.\n");
		return 1;
	}

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
  char inputName[fileLength];
	inputName[0] = 0; // I dont know why this is needed, but it adds something at inputName[0] this
  strcat(inputName, DEFAULT_IN);
  strcat(inputName, inputFile);
  FILE *input = fopen(inputName, "r");
  if (input != NULL) printf("input is defined\n");
  else {
		printf("input not defined, Terminating.\n");
		return 1;
	}
  
	fileLength = strlen(DEFAULT_OUT) + strlen(outputFile) + 1;
  char outputName[fileLength];
	outputName[0] = 0; // I dont know why this is needed, but it adds a 0 at outputName[0] without this
  strcat(outputName, DEFAULT_OUT);
  strcat(outputName, outputFile);
  FILE *output = fopen(outputName, "w");
  if (output != NULL) printf("output is defined\n");
  else {
		printf("output not defined, Terminating.\n");
		return 1;
	}
	
	if (input != NULL && output != NULL){
		// Create buffer for file contents
  	char reader[READER_SIZE];
  	while(fgets(reader, READER_SIZE, input)!=NULL) { // fgets did not read anything new
			// apply mode to all chars in reader
			for (int i = 0; i < READER_SIZE; i++) {
				if (reader[i] == 0) break; // if reached the end of file, stop writing
				char writeChar = applyMode(reader[i], argv[1]);
				if (writeChar!=0) fprintf(output,"%c",writeChar);
			}
		}
		printf("Input writen to output file\n");
	}
  
  // Close files
  if (input != NULL) fclose(input);
  if (output != NULL) fclose(output);
  return 0;
}





