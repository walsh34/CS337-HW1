// Completed by Samuel Walsh

#include <string.h>

#define UPPER "upper"
#define LOWER "lower"
#define NOPUNC "nopunc"

//#define EXCLUDED_CHARACTERS 33,34,39,40,41,44,45,46,58,63,91,93,123,125
//#define EXCLUDED_CHARACTERS '.','?','!',',',':',';','-','{','}','[',']','(',')','‘','“','\'','"'

// Returns null character if value should be excluded
char applyMode(char current, char mode[]) {

  if (strcmp(mode,UPPER) == 0) {
    if (current >= 97 && current <= 122) {
      current -= 32;
    }
  } else if ((strcmp(mode,LOWER) == 0)) {
    if (current >= 65 && current <= 90) {
      current -= 32;
    }
  } else if ((strcmp(mode,NOPUNC) == 0)) {
    /*int excluded[] = {EXCLUDED_CHARACTERS};
    for (int i =  excluded) { // set current to null char if punctuation is found
      if (current == i) {
        current = 0;
        break;
      }*/

      if (current == '.' || current == '?' || current == '!' || current == ',' || current == ':' || current == ';' || current == '-' || current == '{' || current == '}' || current == '[' || current == ']' || current == '(' || current == ')' || current == '\'' || current == '"') {
        current = 0;
    }
  }

  return current;
}