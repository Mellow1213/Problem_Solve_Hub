#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int start;
    int end;
    int value;

    Edge(int s, int e, int v) : start(s), end(e), value(v) {}
};

vector<vector<Edge>> adj;
vector<vector<Edge>> adj_reverse;
int N, M, X;

vector<int> Dijkstra(int node, const vector<vector<Edge>>& graph) {
    vector<int> arr(N+1, 2147483647);
    vector<bool> visit(N+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    arr[node] = 0;
    pq.push({0, node});  // {거리, 노드}

    while(!pq.empty()) {
        int curr = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if(arr[curr] < dist) continue;

        for(const auto& edge : graph[curr]) {
            int next = edge.end;
            int nextDist = dist + edge.value;

            if(nextDist < arr[next]) {
                arr[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> X;
    adj.assign(N+1,vector<Edge>());
    adj_reverse = adj;

    for(int i=0; i<M; i++){
        int st, ed, va;
        cin >> st >> ed >> va;
        Edge edge(st, ed, va);
        adj[st].push_back(edge);
        edge.start = ed;    
        edge.end = st;
        adj_reverse[ed].push_back(edge);
    }

    // X에서 각 정점으로의 최단거리
    vector<int> fromX = Dijkstra(X, adj);
    // 각 정점에서 X로의 최단거리
    vector<int> toX = Dijkstra(X, adj_reverse);

    int maxDist = 0;
    for(int i = 1; i <= N; i++) {
        if(i != X) {
            maxDist = max(maxDist, fromX[i] + toX[i]);
        }
    }

    cout << maxDist << '\n';
    return 0;
}