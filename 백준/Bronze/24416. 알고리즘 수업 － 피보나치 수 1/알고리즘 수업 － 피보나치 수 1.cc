#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

int fib(int n){
    if(n==1 || n == 2){
        cnt++;
        return 1;
    }  
    else    
        return fib(n-1)+fib(n-2);
        
}

vector<int> cache;
int fibo(int n){
    if(n == 1 || n == 2)
        return 1;
    else{
        cache[1] = 1;
        cache[2] = 1;
        for(int i=3; i<=n; i++){
            cnt++;
            cache[i] = cache[i-1]+cache[i-2];
        }
        return cache[n];
    }
}

int main()
{
    int N;
    cin >> N;
    cache = vector<int>(N+1);
    
    fib(N);
    cout << cnt;
    cnt = 0;
    fibo(N);
    cout << ' ' << cnt;
}