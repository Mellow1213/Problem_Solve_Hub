#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int testCase;

void InitVector(int N){
    dp.resize(N > 3 ? N+1 : 3);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
}

int CalComb(int N){
    for(int i=4; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[N];
}

void Solve(){
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
        int N;
        cin >> N;
        InitVector(N);
        
        if(N<=3){
            cout << dp[N] << '\n';
            continue;
        }
        
        cout << CalComb(N) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    Solve();
}
