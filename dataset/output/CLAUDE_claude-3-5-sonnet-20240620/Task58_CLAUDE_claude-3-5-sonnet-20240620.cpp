
#include <string>
#include <algorithm>

bool XO(const std::string& str)
{
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return std::count(lower_str.begin(), lower_str.end(), 'x') == 
           std::count(lower_str.begin(), lower_str.end(), 'o');
}
