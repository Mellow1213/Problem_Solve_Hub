#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b) {
    return a>b ? a : b;
}

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
    
    int Answer = -1e9;
    for(int i=0; i<N-K+1; i++) {
        int sum = 0;
        for(int j=0; j<K; j++) {
            sum += vec[i+j];
        }
        Answer = Max(sum, Answer);
    }
    
    cout << Answer;
}