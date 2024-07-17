#include <vector>

int findOutlier(std::vector<int> arr)
{
  int even_count = 0;
  int odd_count = 0;
  int even_num = 0;
  int odd_num = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] % 2 == 0) {
      even_count++;
      even_num = arr[i];
    } else {
      odd_count++;
      odd_num = arr[i];
    }
  }

  if (even_count > 1) {
    return odd_num;
  } else {
    return even_num;
  }
}