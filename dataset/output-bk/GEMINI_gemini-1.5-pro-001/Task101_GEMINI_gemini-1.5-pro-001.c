++
#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main() {
  // Create the file
  std::ofstream file("script.sh");
  if (!file.is_open()) {
    return 1;
  }
  file.close();

  // Make it executable
  if (chmod("script.sh", S_IRWXU) == -1) {
    return 1;
  }

  return 0;
}