#include <iostream>
using namespace std;

// 조합을 계산하는 함수
unsigned long long CalCombination(int n, int m){
    if (n > m-n) 
        n = m-n;
    
    unsigned long long ans = 1;
    for (int i = 0; i < n; ++i){
        ans *= (m-i);
        ans /= (i+1);
    }

    return ans;
}

int main() {
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++){
        int n, m;
        cin >> n >> m;
        cout << CalCombination(n, m) << endl;
    }
    
    return 0;
}
