#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    const int money[4] = { 25, 10, 5, 1 };
    int testCase;
    cin >> testCase;
    
    while(testCase > 0) {
        
    int change;
    cin >> change;
    
    for(int i=0; i<4; i++) {
        int curMoney = change / money[i];
        cout << curMoney << ' ';
        change %= money[i];
    }
    cout << '\n';
    testCase--;
    }
}