#include <iostream>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    float d[3];
    float a = 0, b = 0, c = 0;
    for (int i = 0; i < 3; i++) {
        cin >> d[i];
    }

    b = (d[0] - d[1] + d[2]) / 2;
    c = d[2] - b;
    a = d[0] - b;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "-1";
    } else {
        cout << "1" << "\n";
        // 소수점 하나만 출력
        cout << fixed;
        cout.precision(1);
        cout << a << ' ' << b << ' ' << c;
    }

    return 0;
}
