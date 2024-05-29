#include <iostream>

using namespace std;

int Power(int base, int exponent) {
    int answer = 1;
    for (int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

int CalcDivide(int N, int r, int c) {
    int target = Power(2, N - 1);
    int divide = (r < target) ? 0 : 2;
    if (c >= target) divide += 1;

    return divide;
}

void RetargetScale(int& r, int& c, int divide, int size) {
    if (divide == 2) {
        r -= size;
    } else if (divide == 1) {
        c -= size;
    } else if (divide == 3) {
        r -= size;
        c -= size;
    }
}

int SearchByZ(int N, int r, int c) {
    if (N == 0) {
        return 0;
    }

    int size = Power(2, N - 1);
    int area = size * size;
    int divide = CalcDivide(N, r, c);
    int local_cnt = area * divide;

    RetargetScale(r, c, divide, size);
    return local_cnt + SearchByZ(N - 1, r, c);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << SearchByZ(N, r, c);
    return 0;
}
