#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        int N, M, count = 0;
        cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선순위 큐를 사용하여 우선순위를 관리

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({i, priority}); // {문서의 초기 위치, 중요도}
            pq.push(priority); // 중요도만 따로 관리
        }

        while (!q.empty()) {
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();

            if (pq.top() == val) { // 큐의 앞부분의 문서가 가장 높은 우선순위를 가진 경우
                pq.pop();
                count++;
                if (idx == M) { // 요청한 문서가 인쇄되는 경우
                    cout << count << '\n';
                    break;
                }
            } else {
                q.push({idx, val}); // 우선순위가 높지 않으면 다시 큐의 뒤로
            }
        }
    }

    return 0;
}
