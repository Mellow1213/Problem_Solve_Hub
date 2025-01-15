#include <iostream>
#include <vector>
using namespace std;

const int MDR = 15746;

int max(int a, int b) {
    return a>b ? a : b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N+1, 0);
    
    dp[1] = 1;
    if(N >= 2)  dp[2] = 2;
    
    for(int i=3; i<=N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MDR;
    }
    
    cout << dp[N];
}