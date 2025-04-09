#include <iostream>

using namespace std;

void CustomPrint(int a, int b) {
    cout << "a = " << a << "\nb = " << b;
    return;
}

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    CustomPrint(a, b);
    return 0;
}