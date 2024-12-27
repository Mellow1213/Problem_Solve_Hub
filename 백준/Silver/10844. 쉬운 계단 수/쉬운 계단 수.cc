#include <iostream>
#include <vector>
using namespace std;

#define moduler 1000000000
typedef long long ll;
int main()
{
    int N;
    cin >> N;
    
    vector<vector<ll>> dp(N+1, vector<ll>(11)); // dp[길이][끝자리 수];
    
    for(int i=1; i<=9; i++) {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
    
    for(int i=2; i<=N; i++) {
        
        for(int j=0; j<=9; j++) {
            if(j==0)
                dp[i][j] = dp[i-1][j+1] % moduler;
            else if (j==9)  
                dp[i][j] = dp[i-1][j-1] % moduler;
            else            
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % moduler;
        }
    }
    
    ll result = 0;
    for(int i=0; i<=9; i++) {
        result = (result+dp[N][i]) % moduler;
    }
    cout << result;
}