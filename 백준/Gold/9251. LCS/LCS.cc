#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    int ASize = a.size();
    int BSize = b.size();
    vector<vector<int>> dp(ASize+1, vector<int>(BSize+1, 0));
    
    for(int i=1; i<=ASize; i++){
        for(int j=1; j<=BSize; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[ASize][BSize];
}