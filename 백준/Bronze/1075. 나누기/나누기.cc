#include <iostream>

using namespace std;

int main()
{
    int N, F;
    
    cin >> N >> F;
    
    N = (N/100)* 100;
    while(N % F != 0){
        N++;
    }
    int answer = N%100;
    if(answer / 10 == 0)
        cout << '0';
        
    cout << N%100;
}