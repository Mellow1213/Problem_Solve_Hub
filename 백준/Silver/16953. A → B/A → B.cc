#include <iostream>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    
    int cnt = 1;
    bool flag = false;
    
    while(A < B){
        if(B % 10 == 1){
            B = (B-1) / 10;
            cnt++;
        }
        else if(B % 2 == 0){
            B = B/2;
            cnt++;
        }
        else{
            break;
        }
    }
    
    cout << (A != B ? -1 : cnt);
}