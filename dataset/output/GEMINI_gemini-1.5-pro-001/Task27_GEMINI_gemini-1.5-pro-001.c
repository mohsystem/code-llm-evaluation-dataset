#include <stdio.h>
#include <stdlib.h>

int find_outlier(int *values, size_t count) {
  int even_count = 0;
  int odd_count = 0;
  int even_num = 0;
  int odd_num = 0;

  for (size_t i = 0; i < count; i++) {
    if (values[i] % 2 == 0) {
      even_count++;
      even_num = values[i];
    } else {
      odd_count++;
      odd_num = values[i];
    }
  }

  if (even_count > 1) {
    return odd_num;
  } else {
    return even_num;
  }
}