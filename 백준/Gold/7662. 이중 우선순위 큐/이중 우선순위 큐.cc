#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq; // 최소 힙
priority_queue<int, vector<int>, less<int>> max_pq; // 최대 힙
map<int, int> cnt; // 각 숫자의 빈도

void insert(int n) {
    min_pq.push(n);
    max_pq.push(n);
    cnt[n]++;
}

void deleteMin() {
    while (!min_pq.empty() && cnt[min_pq.top()] == 0) {
        min_pq.pop();
    }
    if (!min_pq.empty()) {
        cnt[min_pq.top()]--;
        min_pq.pop();
    }
}

void deleteMax() {
    while (!max_pq.empty() && cnt[max_pq.top()] == 0) {
        max_pq.pop();
    }
    if (!max_pq.empty()) {
        cnt[max_pq.top()]--;
        max_pq.pop();
    }
}

void cleanPqs() {
    while (!min_pq.empty() && cnt[min_pq.top()] == 0) {
        min_pq.pop();
    }
    while (!max_pq.empty() && cnt[max_pq.top()] == 0) {
        max_pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, k, n;
    char cmd;

    cin >> T;
    while (T--) {
        min_pq = priority_queue<int, vector<int>, greater<int>>(); // 최소 힙 초기화
        max_pq = priority_queue<int, vector<int>, less<int>>(); // 최대 힙 초기화
        cnt.clear(); // 빈도 맵 초기화

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> cmd >> n;

            if (cmd == 'I') {
                insert(n);
            } else if (cmd == 'D') {
                if (n == 1) {
                    deleteMax();
                } else if (n == -1) {
                    deleteMin();
                }
            }
        }

        cleanPqs(); // 최종 정리 작업
        if (max_pq.empty() || min_pq.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_pq.top() << " " << min_pq.top() << "\n";
        }
    }

    return 0;
}
