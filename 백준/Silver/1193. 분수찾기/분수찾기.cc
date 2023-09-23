#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;

    int sum = 1;
    int k = 1;
    while (sum < num) {
        k++;
        sum += k;
    }

    int gap = sum - num;

    if (k % 2 == 1) {
        cout << gap + 1 << "/" << k - gap << endl;
    } else {
        cout << k - gap << "/" << gap + 1 << endl;
    }

}
