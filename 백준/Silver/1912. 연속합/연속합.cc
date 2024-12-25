#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> dp(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<N; i++) 
        dp[i] = arr[i];
    
    int answer = dp[0];
    for(int i=1; i<N; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        answer = max(answer, dp[i]);
    }
    cout << answer;
}