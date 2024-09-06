#include <string>
#include <algorithm>

bool XO(std::string text) {
  std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  return std::count(text.begin(), text.end(), 'x') == std::count(text.begin(), text.end(), 'o');
}