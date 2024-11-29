#include <iostream>
#include <vector>

using namespace std;
using Edge = pair<int, int>;


vector<vector<Edge>> adj;
vector<bool> visit;
vector<int> lens;

void DFS(int x, int depth, Edge& edge) {
    if(edge.second < depth){
        edge.first = x;
        edge.second = depth;
    }
    visit[x] = true;
    for(const auto& p : adj[x]){
        if(!visit[p.first]){
            DFS(p.first, depth+p.second, edge);
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.assign(N+1, vector<Edge>());
    visit.assign(N+1, false);

    for(int i=1; i<=N; i++){
        int node;
        cin >> node;
        int temp1, temp2;
        while(1){
            cin >> temp1;
            if(temp1 == -1) break;
            cin >> temp2;
            adj[node].push_back({temp1, temp2});
            adj[temp1].push_back({node, temp2});
        }
    }
    Edge edge;
    DFS(1, 0, edge);

    visit.assign(N+1, false);
    DFS(edge.first, 0, edge);
    
    cout << edge.second;
}