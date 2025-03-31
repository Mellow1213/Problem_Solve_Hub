#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> damage(N);
    vector<int> happy(N);
    
    for(int i = 0; i < N; i++) cin >> damage[i];
    for(int i = 0; i < N; i++) cin >> happy[i];

    vector<int> dp(101, 0); // 체력은 최대 100까지만 유지 가능

    for(int i = 0; i < N; i++) {
        for(int hp = 100; hp > damage[i]; hp--) {
            dp[hp] = max(dp[hp], dp[hp - damage[i]] + happy[i]);
        }
    }

    // 체력이 1~100일 때의 최대 행복을 출력
    int answer = 0;
    for(int i = 1; i <= 100; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';
    return 0;
}
