#include <iostream>
#include <vector>

#define HashKey 10007

using namespace std;

int CalcTilePossibility(int width){
    vector<unsigned int> dp(width);
    dp[0] = 1;
    dp[1] = 3;
    for(int i=2; i<width; i++)
        dp[i] = dp[i-2] % HashKey + dp[i-1] % HashKey + dp[i-2] % HashKey;
    return dp[width-1] % HashKey;
}

int main()
{
    int width;
    
    cin >> width;
    
    cout << CalcTilePossibility(width);
}