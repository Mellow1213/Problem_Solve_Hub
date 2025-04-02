#include <iostream>
#include <cmath>
using namespace std;

double Distance(int a, int b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}

int main() {
    int x1, y1, x2, y2;
    int r1, r2;
    int tc;
    cin >> tc;

    while(tc-- > 0) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = Distance(x1 - x2, y1 - y2);
        int answer = -1;

        if(x1 == x2 && y1 == y2) {
            answer = (r1 == r2) ? -1 : 0;
        } else {
            if(dist > r1 + r2) {
                answer = 0;
            } else if(dist == r1 + r2) {
                answer = 1;
            } else if(dist < abs(r2 - r1)) {
                answer = 0;
            } else if(dist == abs(r2 - r1)) {
                answer = 1;
            } else {
                answer = 2;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
