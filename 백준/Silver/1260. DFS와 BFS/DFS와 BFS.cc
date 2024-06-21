#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph{
    private:
        vector<vector<int>> adjMat;
        vector<bool> visited;
        
    public:
        void InitData(int node, int link){
            adjMat.assign(node+1, vector<int>());
            ClearVisited();
            
            for(int i=0, N, L; i<link; i++){
                cin >> N >> L;
                adjMat[N].push_back(L);
                adjMat[L].push_back(N);
            }
            
            for(auto& edges : adjMat){
                sort(edges.begin(), edges.end());
            }
        }
        void ClearVisited(){
            visited.assign(adjMat.size(), false);
        }
        void DFS(int N);
        void BFS(int N);
};

void Graph::DFS(int N){
    visited[N] = true;
    cout << N << ' ';
    for(const auto& p : adjMat[N]){
        if(!visited[p]){
            DFS(p);
        }
    }
}

void Graph::BFS(int N){
    visited[N] = true;
    
    queue<int> q;
    q.push(N);
    cout << N << ' ';
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(const auto& p : adjMat[x]){
            if(!visited[p]){
                cout << p << ' ';
                visited[p] = true;
                q.push(p);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, V;
    cin >> N >> M >> V; 
    Graph graph;
    
    graph.InitData(N, M);
    graph.DFS(V);
    graph.ClearVisited();
    cout<<'\n';
    graph.BFS(V);
}