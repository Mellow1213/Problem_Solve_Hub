#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int main()
{
    int N;
    vector<int> arrA, arrB;
    
    cin >> N;
    arrA.assign(N, 0);
    arrB.assign(N, 0);
    
    for(int i=0; i<N; i++) {
        cin >> arrA[i];
    }
    
    sort(arrA.begin(), arrA.end());
    
    for(int i=0; i<N; i++) {
        cin >> arrB[i];
    }
    
    sort(arrB.begin(), arrB.end(), compare);
    
    int answer = 0;
    
    for(int i=0; i<N; i++) {
        answer += arrA[i] * arrB[i];
    }
    
    cout << answer;
}