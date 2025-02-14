#include <iostream>
#include <vector>
#include <utility> // for pair
#include <climits> // for INT_MAX

using namespace std;

#define INF (INT_MAX / 2) // 무한대 값 정의

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    // 인접 리스트: adj[u] = {v, weight}
    vector<vector<pair<int, int>>> adj(N + 1);

    // 각 노드의 최단 거리 (초기값은 INF)
    vector<long long> nodeCost(N + 1, INF); // long long으로 선언하여 오버플로 방지

    // 간선 입력
    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
    }

    // 시작 노드의 거리를 0으로 설정
    nodeCost[1] = 0;

    // 벨만-포드 알고리즘
    for (int i = 0; i < N - 1; i++) { // N-1번 반복
        for (int u = 1; u <= N; u++) { // 모든 노드 u에 대해
            for (const auto& edge : adj[u]) { // u와 연결된 모든 간선
                int v = edge.first;
                int weight = edge.second;

                // 최단 경로 갱신
                if (nodeCost[u] != INF && nodeCost[u] + weight < nodeCost[v]) {
                    nodeCost[v] = nodeCost[u] + weight;
                }
            }
        }
    }

    // 음수 사이클 검출
    bool hasNegativeCycle = false;
    for (int u = 1; u <= N; u++) {
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // N-1번 이후에도 갱신이 발생하면 음수 사이클 존재
            if (nodeCost[u] != INF && nodeCost[u] + weight < nodeCost[v]) {
                hasNegativeCycle = true;
                break;
            }
        }
        if (hasNegativeCycle) break;
    }

    // 결과 출력
    if (hasNegativeCycle) {
        cout << -1 << endl; // 음수 사이클이 존재하면 -1 출력
    } else {
        for (int i = 2; i <= N; i++) {
            if (nodeCost[i] == INF) {
                cout << -1 << endl; // 도달할 수 없는 경우 -1 출력
            } else {
                cout << nodeCost[i] << endl; // 최단 경로 출력
            }
        }
    }

    return 0;
}