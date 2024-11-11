#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class MiddleQueue {
private:
    int upqSize = 0;
    int dpqSize = 0;
    priority_queue<int> upq;                                  // 최대 힙 (작은 수들)
    priority_queue<int, vector<int>, greater<int>> dpq;       // 최소 힙 (큰 수들)
    
public:
    void push(int element) {
        // 첫 번째 원소는 upq에
        if(upq.empty()) {
            upq.push(element);
            upqSize++;
            return;
        }
        
        // 두 번째 원소는 dpq에
        if(dpq.empty()) {
            if(upq.top() > element) {
                dpq.push(upq.top());
                upq.pop();
                upq.push(element);
            } else {
                dpq.push(element);
            }
            dpqSize++;
            return;
        }
        
        // 이후 원소들 처리
        if(upqSize == dpqSize) {
            if(dpq.top() < element) {
                upq.push(dpq.top());
                dpq.pop();
                dpq.push(element);
            } else {
                upq.push(element);
            }
            upqSize++;
        }
        else {  // upqSize > dpqSize
            if(upq.top() > element) {
                dpq.push(upq.top());
                upq.pop();
                upq.push(element);
            } else {
                dpq.push(element);
            }
            dpqSize++;
        }
    }
    
    int top() {
        if(upqSize >= dpqSize)
            return upq.top();
        return dpq.top();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    MiddleQueue mq;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        mq.push(x);
        cout << mq.top() << '\n';
    }
    
    return 0;
}