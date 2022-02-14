// Completed by Samuel Walsh

#include <string.h>

#define UPPER "upper"
#define LOWER "lower"
#define NOPUNC "nopunc"

// Returns null character if value should be excluded
char applyMode(char current, char mode[]) {

  if (strcmp(mode,UPPER) == 0) {
    if (current >= 97 && current <= 122) {
      current -= 32;
    }
  } else if ((strcmp(mode,LOWER) == 0)) {
    if (current >= 65 && current <= 90) {
      current += 32;
    }
  } else if ((strcmp(mode,NOPUNC) == 0)) {
      if (current == '.' || current == '?' || current == '!' || current == ',' || current == ':' || current == ';' || current == '-' || current == '{' || current == '}' || current == '[' || current == ']' || current == '(' || current == ')' || current == '\'' || current == '"') {
        current = 0;
    }
  }

  return current;
}