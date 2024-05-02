#include <iostream>
#include <vector>

int max(int a, int b){
    return a>b ? a : b;
}

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int stairCnt;
    vector<int> stairScore;
    vector<int> dp;
    
    cin >> stairCnt;
    stairScore.resize(stairCnt);
    dp.resize(stairCnt);
    
    for(int i=0; i<stairCnt; i++){
        cin >> stairScore[i];
    }
    
    if(stairCnt == 1){
        cout <<stairScore[0];
        return 0;
    }
    
    
    dp[0] = stairScore[0];
    dp[1] = dp[0] + stairScore[1];
    
    for(int i=2; i<stairCnt; i++){
        dp[i] = max(dp[i-2] + stairScore[i], dp[i-3] + stairScore[i-1] + stairScore[i]);
    }
    
    cout << dp[stairCnt - 1];
}