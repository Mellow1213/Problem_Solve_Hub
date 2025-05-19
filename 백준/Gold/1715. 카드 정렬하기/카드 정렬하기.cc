#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

int GetOptimizeSortCount(const vector<int>& arr) {
    assert(arr.size() > 0);
    
    if(arr.size() <= 1) { // early-return
        return 0;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순. 낮은 것부터 계산해야 하니까
    
    for(const auto p : arr) {
        pq.push(p);
    }
    
    int sum = 0;
    while(pq.size() > 1) {
        int temp = 0;
        for(int i=0; i<2; i++) {
            temp += pq.top();
            pq.pop();
        }
        sum += (temp);
        pq.push(temp);
    }
    
    return sum;
}

int main()
{
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++) {
        cin >> vec[i];
    }
    
    cout << GetOptimizeSortCount(vec);
}