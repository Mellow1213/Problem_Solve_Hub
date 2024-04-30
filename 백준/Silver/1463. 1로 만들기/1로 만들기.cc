#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
    return a<b ? a : b;
}

int main()
{
    vector<int> vec;
    int N;
    
    cin >> N;
    vec.resize(N+1);
    
    vec[1] = 0;
    for(int i=2; i<=N; i++){
        vec[i] = vec[i-1] + 1;
        if(i%3 == 0) vec[i] = min(vec[i], vec[i/3]+1);
        if(i%2 == 0) vec[i] = min(vec[i], vec[i/2]+1);        
    }
    
    cout << vec[N];
}