#include <iostream>
using namespace std;

int main() {
    int up, down, stick;
    cin >> up >> down >> stick;

    int day = (stick - down-1) / (up - down) + 1;
    cout << day;
}
