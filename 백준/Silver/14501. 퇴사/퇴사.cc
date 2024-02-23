#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16], P[16];
int dp[17];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = N; i > 0; i--) {
        int next = i + T[i];
        if (next > N + 1) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], P[i] + dp[next]);
        }
    }

    cout << dp[1] << endl;
    return 0;
}
