#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
  char *consonants =(char*)calloc(strlen(str)+1, sizeof(char));
  char *vowels = (char*)calloc(11, sizeof(char));
  strcpy(vowels, "aeiouAEIOU\0");
  int j = 0;
  for(int i = 0; i < strlen(str); ++i) {
	if(strchr(vowels, str[i]) == NULL) {
		consonants[j++] = str[i];
	}
  }
  consonants[j] = '\0';

  char *result = (char*)calloc(strlen(consonants)+1, sizeof(char));
  strcpy(result, consonants);
  result[j] ='\0';

  free((char*) consonants);
  free((char*) vowels);
  return result;
}
