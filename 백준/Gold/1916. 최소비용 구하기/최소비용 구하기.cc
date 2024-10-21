#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<vector<pii>> graph;
vector<int> dist;

void dijkstra(int start, int end) {
    dist.assign(N + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if (current == end) break;  // 목적지에 도달하면 종료
        
        if (cost > dist[current]) continue;
        
        for (auto &edge : graph[current]) {
            int next = edge.first;
            int nextCost = cost + edge.second;
            
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    graph.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back({end, cost});
    }
    
    int start, end;
    cin >> start >> end;
    
    dijkstra(start, end);
    
    cout << dist[end] << '\n';
    
    return 0;
}