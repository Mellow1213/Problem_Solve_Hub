#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int data;
            cin >> data;
            dp[i][j] = data + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    int x1, x2, y1, y2;
    for(int t=0; t<M; t++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
    }
}