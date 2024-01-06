#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void addFractions(int num1[], int num2[]) {
    int initial_denominator = num1[1];

    num1[0] *= num2[1];
    num2[0] *= initial_denominator;
    num1[0] += num2[0];
    num1[1] *= num2[1];
}

int main() {
    int num1[2];
    int num2[2];
    
    cin >> num1[0] >> num1[1];
    cin >> num2[0] >> num2[1];

    addFractions(num1, num2);

    int g = gcd(abs(num1[0]), num1[1]);
    num1[0] /= g;
    num1[1] /= g;

    cout << num1[0] << " " << num1[1] << endl;

    return 0;
}
