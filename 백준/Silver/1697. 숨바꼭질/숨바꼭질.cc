#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int finder, const int target) {
    if (finder == target) return 0;

    const int MAX = 200000;  // 충분히 큰 크기로 설정
    vector<bool> visited(MAX + 1, false);
    queue<pair<int, int>> q;

    q.push(make_pair(finder, 0));
    visited[finder] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x == target) {
            return cnt;
        }

        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.push(make_pair(x - 1, cnt + 1));
        }
        if (x + 1 <= MAX && !visited[x + 1]) {
            visited[x + 1] = true;
            q.push(make_pair(x + 1, cnt + 1));
        }
        if (2 * x <= MAX && !visited[2 * x]) {
            visited[2 * x] = true;
            q.push(make_pair(2 * x, cnt + 1));
        }
    }
    return -1;
}

int main() {
    int finderPos, targetPos;

    cin >> finderPos >> targetPos;

    cout << BFS(finderPos, targetPos) << endl;
}
