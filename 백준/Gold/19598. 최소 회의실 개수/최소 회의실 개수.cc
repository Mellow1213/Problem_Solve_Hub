#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
    int N;
    int roomCnt = 0;
    vector<pair<int, int>> arr;
    priority_queue<int,vector<int>, greater<int>> q;
    cin >> N;
    arr.reserve(N);
    
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    
    sort(arr.begin(), arr.end());
    
    q.push(arr[0].second);
    roomCnt++;
    for(int i=1; i<N; i++) {
        int t = q.top();
        if(t <= arr[i].first) {
            q.pop();
            q.push(arr[i].second);
        } else {
            q.push(arr[i].second);
            roomCnt++;
        }
    }
    
    cout << roomCnt;
}