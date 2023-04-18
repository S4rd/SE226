#include <iostream>
#include <cmath>

using namespace std;

double recursive_sum() {

    int n;
    cout << "Enter your number: ";
    cin >> n;

    double summation = 0;
    for (int i = 1; i <= n; i++) {
        double term = pow(-1, i + 1) / i;
        summation += term;
    }
    return summation;
}

int main() {
    double summation = recursive_sum();
    cout << "Summation: " << summation << endl;
    return 0;
}