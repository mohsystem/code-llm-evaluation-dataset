#include <stdio.h>
#include <stdlib.h>
char * odd_or_even(int *arr, int sz) {
  int sum = 0;
  for(int i=0; i<sz; i++) {
    sum += arr[i];
  }
  char * result = malloc(5); 
  if(sum % 2 == 0){
    result = "even";
  } else {
    result = "odd";
  }
  return result;
}