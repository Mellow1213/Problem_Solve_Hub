#include <iostream>
using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

void solve() {
    int testCase;
    cin >> testCase;
    
    while (testCase--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        
        int lcm = LCM(M, N);
        bool found = false;
        
        // `x`에서 시작해 `M`씩 증가하면서 `y`와 비교
        for (int k = x; k <= lcm; k += M) {
            if ((k - 1) % N + 1 == y) {
                cout << k << '\n';
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    return 0;
}
