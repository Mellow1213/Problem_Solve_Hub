#include <iostream>

using namespace std;

int factorial(int n){
    if(n>1) return factorial(n-1)*n;
    else return 1;
}
int main()
{
    int N;
    float K;
    
    cin >> N >> K;
    
    float answer = factorial(N) / (factorial(N-K) * factorial(K));
    
    cout << answer;
}
