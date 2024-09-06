#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * highestScoringWord(char *str) {
  char *word, *highest_word;
  int score, highest_score = 0;
  word = strtok(str, " ");
  highest_word = word;
  while (word != NULL) {
    score = 0;
    for (int i = 0; i < strlen(word); i++) {
      score += tolower(word[i]) - 'a' + 1;
    }
    if (score > highest_score) {
      highest_score = score;
      highest_word = word;
    }
    word = strtok(NULL, " ");
  }
  return highest_word;
}