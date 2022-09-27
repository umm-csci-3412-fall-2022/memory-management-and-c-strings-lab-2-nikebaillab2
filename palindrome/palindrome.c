#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "palindrome.h"

char *str_reverse(char const *str) {
  int len, i;
  char *result; // Need to free this pointer

  len = strlen(str);
  result = (char*) calloc(len+1, sizeof(char));
  for (i=0; i<len; ++i) {
    result[i] = str[len-i-1];
  }
  result[len] = '\0';
  
  /*
   * Since *str_reverse() is called
   * in other funcitons, it would be
   * inappropriate to free result now
   */
  return result;
}

char *palindrome(char const *str) {
  char *rev; // Need to free this pointer
  int i;
  bool result = true;
  char *answer; // Need to free this pointer

  rev = str_reverse(str);
  i = 0;
  while (result && str[i]) {
    if (str[i] != rev[i]) { // After this we can free rev whenever
      result = false;
    }
    ++i;
  }

  if (result) {
    answer = (char*) calloc(4, sizeof(char));
    answer[0] = 'Y';
    answer[1] = 'e';
    answer[2] = 's';
    answer[3] = '\0';
  } else {
    answer = (char*) calloc(3, sizeof(char));
    answer[0] = 'N';
    answer[1] = 'o';
    answer[2] = '\0';
  }

  // Freeing the memory stored in rev and in answer
  free((char*)rev);
  free((char*)answer);

  return answer;
}
