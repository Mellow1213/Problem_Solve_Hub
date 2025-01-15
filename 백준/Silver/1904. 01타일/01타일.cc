#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a>b ? a : b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N+1, 0);
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=N; i++) {
        dp[i] = dp[i-1] % 15746 + dp[i-2] % 15746;
    }
    
    cout << dp[N] % 15746;
}