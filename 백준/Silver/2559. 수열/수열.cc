#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    for(int i=0; i<N; i++) {
        cin >> vec[i];
    }
    
    int tempSum = 0;
    for(int i=0; i<K; i++) {
        tempSum += vec[i];
    }
    int Answer = tempSum;
    for(int i=1; i<N-K+1; i++) {
        tempSum -= vec[i-1];
        tempSum += vec[i+K-1];
        if(tempSum > Answer) {
            Answer = tempSum;
        }
    }
    cout << Answer;
}