#include <iostream>
#include <queue>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int Strategy(int num, int state) {
    if (state == 0) return num * 3;
    if (state == 1) return num * 2;
    return num + 1;
}

void CalcRoute(int targetNum) {
    int start = 1;

    queue<pair<int, int>> q;
    vector<bool> isVisit(targetNum + 2, false);
    vector<int> from(targetNum + 2, -1);

    q.push({start, 0});
    isVisit[start] = true;

    int answer = -1;

    while (!q.empty()) {
        int num = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (num == targetNum) {
            answer = depth;
            break;
        }

        for (int i = 0; i < 3; i++) {
            int next = Strategy(num, i);
            if (next > targetNum + 1) continue;
            if (isVisit[next]) continue;

            isVisit[next] = true;
            from[next] = num;
            q.push({next, depth + 1});
        }
    }

    // 출력 1: 최소 연산 횟수
    cout << answer << '\n';

    // 출력 2: 경로 복원 (벡터 + 역인덱싱)
    vector<int> path;
    for (int cur = targetNum; cur != -1; cur = from[cur]) {
        path.push_back(cur);
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    cout << '\n';
}

int main() {
    FastIO
    int X;
    cin >> X;
    CalcRoute(X);
}
