#include <string>
#include <iostream>
#include <cctype>

using namespace std;
bool validatePin(string pin) {
    if(pin.length() != 4 && pin.length() != 6){
        return false;
    }
    for(int i = 0; i < pin.length(); i++){
        if(!isdigit(pin[i])){
            return false;
        }
    }
    return true;
}
int main(){
   cout << validatePin("1234") << endl;
   cout << validatePin("12345") << endl;
   cout << validatePin("a234") << endl;
}