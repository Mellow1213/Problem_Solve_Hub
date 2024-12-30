#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> glass(N+1);
    vector<int> DP(N+1);
    for(int i=1; i<=N; i++) {
        cin >> glass[i];
    }
    DP[0] = 0;
    DP[1] = glass[1];
    if(N==1) {
        cout << DP[1];
        return 0;
    }
    DP[2] = glass[1]+glass[2];
    if(N==2) {
        cout << DP[2];
        return 0;
    }
    
    for(int i=3; i<=N; i++) {
        DP[i] = max({DP[i-3]+glass[i-1]+glass[i], DP[i-2]+glass[i], DP[i-1]});
    }
    
    cout << DP[N];
}