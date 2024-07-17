#include <string>

std::string toJadenCase(std::string str)
{
  if (str.empty())
    return "";

  str[0] = std::toupper(str[0]);

  for (unsigned int i = 1; i < str.size(); i++) {
    if (str[i - 1] == ' ')
      str[i] = std::toupper(str[i]);
    else
      str[i] = std::tolower(str[i]);
  }

  return str;
}