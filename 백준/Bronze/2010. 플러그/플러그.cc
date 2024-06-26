#include <iostream>

using namespace std;
int main()
{
    int sum = 0;
    int cnt;
    
    cin >> cnt;
    
    for(int i=0; i<cnt; i++){
        int temp;
        cin >> temp;
        sum += temp;
    }
    sum -= (cnt-1);
    
    cout << sum;
}