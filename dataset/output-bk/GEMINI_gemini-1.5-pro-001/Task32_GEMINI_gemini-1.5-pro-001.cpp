#include <iostream>
#include <cmath>
using namespace std;

int calculateYears(double principal, double interest, double tax, double desired) {
    int years = 0;
    while(principal < desired){
        principal += (principal * interest)*(1 - tax);
        years++;
    }
        return years;
}
int main(){
    double principal, interest, tax, desired;
    cin >> principal;
    cin >> interest;
    cin >> tax;
    cin >> desired;
    int result = calculateYears(principal, interest, tax, desired);
    cout << result;
    return 0;
}