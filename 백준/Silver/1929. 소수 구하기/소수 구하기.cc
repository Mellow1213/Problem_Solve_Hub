#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, N;
    cin >> M >> N;
    
    vector<bool> isPrime(N+1, true);
    
    for(int i=2; i<=N; i++){
        if(isPrime[i]){
            if(i >= M)
                cout << i << '\n';
            for(int j=i; j<=N; j += i){
                isPrime[j] = false;
            }
        }
    }
}