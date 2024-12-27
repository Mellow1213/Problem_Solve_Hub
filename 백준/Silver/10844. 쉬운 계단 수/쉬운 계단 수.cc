#include <iostream>
#include <vector>
using namespace std;

#define moduler 1000000000

int main()
{
    int N;
    cin >> N;
    if(N==1) {
        cout << 9;
        return 0;
    }
    
    vector<vector<int>> dp(N+1, vector<int>(10)); // dp[길이][끝자리 수];
    
    for(int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1; j<=8; j++) {
            dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) % moduler;
        }
    }
    
    int result = 0;
    for(int i=0; i<=9; i++) {
        result = (result+dp[N][i]) % moduler;
    }
    cout << result;
}