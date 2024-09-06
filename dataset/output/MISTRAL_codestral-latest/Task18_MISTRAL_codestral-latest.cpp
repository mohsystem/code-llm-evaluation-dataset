#include <vector>
#include <bitset>

int binaryArrayToNumber(std::vector<int> arr) {
    std::bitset<32> bs;
    for (int i = 0; i < arr.size(); i++) {
        bs[i] = arr[i];
    }
    return bs.to_ulong();
}