
// Question 1

#include <iostream>
#include <cmath>

using namespace std;
double summation = 0;

double recursive_sum(int n) {

    if (n == 0) {
        return summation;
    }
    double term = pow(-1, n + 1) / n;
    summation += term;
    return recursive_sum(n - 1);

}
int main() {
    int k;
    cout << "Enter your number: ";
    cin >> k;
    double summation = recursive_sum(k);
    cout << "Summation: " << summation << endl;
    return 0;
}
