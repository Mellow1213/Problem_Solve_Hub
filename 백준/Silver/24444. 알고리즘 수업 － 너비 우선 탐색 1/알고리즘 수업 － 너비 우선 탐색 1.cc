#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    
    vector<vector<int>> adj(N+1, vector<int>()); // 1-based indexing
    vector<int> visited(N+1, 0);
    int order = 1;
    
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    queue<int> q;
    q.push(R);
    visited[R] = order++;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(int next : adj[current]){
            if(visited[next] == 0){
                q.push(next);
                visited[next] = order++;
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        cout << visited[i] << '\n';
    }
    
    return 0;
}