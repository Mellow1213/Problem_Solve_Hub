#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> dp;
vector<vector<int>> stickers;

void CalcSticker(){
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = stickers[0][1];
    dp[1][1] = stickers[1][1];
    
    for(int i=2; i<n+1; i++){
        dp[0][i] = stickers[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = stickers[1][i] + max(dp[0][i-1], dp[0][i-2]);
    }
    
    cout << max(dp[0][n], dp[1][n]) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    
    cin >> T;
    while(T>0){
        cin >> n;
        stickers.assign(2, vector<int>(n+1));
        dp.assign(2, vector<int>(n+1));
        
        for(int i=0; i<2; i++){
            for(int j=1; j<n+1; j++){
                cin >> stickers[i][j];
            }
        }
        CalcSticker();
        T--;
    }
}