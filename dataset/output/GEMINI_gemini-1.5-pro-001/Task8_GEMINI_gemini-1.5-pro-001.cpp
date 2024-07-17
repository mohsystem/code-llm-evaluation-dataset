#include <iostream>
#include <vector>
using namespace std;

char findMissingLetter(vector<char> array);
int main() {
    vector<char> arr1 = {'a', 'b', 'c', 'd', 'f'};
    vector<char> arr2 = {'O', 'Q', 'R', 'S'};
    
    cout << findMissingLetter(arr1) << endl;
    cout << findMissingLetter(arr2) << endl;
    
    return 0;
}

char findMissingLetter(vector<char> array) {
    for (int i = 1; i < array.size(); i++) {
        if (array[i] - array[i - 1] != 1) {
            return (char)(array[i] - 1);
        }
    }
    return ' ';
}