#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vec;

int CalculatePerson(int k, int n){
    
    if(k==0) { return n; }

    if (vec.size() <= k) {
        vec.resize(k + 1);
    }
    if (vec[k].size() <= n) {
        vec[k].resize(n + 1, 0);
    }
    else{
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += CalculatePerson(k-1, i);
        }
        
        return sum;
    }
    
    // 이미 계산된 값이 있다면 그 값을 반환
    if (vec[k][n] != 0) {
        return vec[k][n];
    }

    // 값이 계산되지 않았다면 새로 계산
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += CalculatePerson(k - 1, i);
    }

    // 계산된 값을 vec에 저장하고 반환
    vec[k][n] = sum;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    
    cin >> testCase;
    
    for(int t=0; t<testCase; t++){
        int k, n;
        cin >> k >> n;
        
        cout << CalculatePerson(k, n) << '\n';
    }
}
