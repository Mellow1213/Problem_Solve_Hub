#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int v) {
    visited[v] = 1;
    for(int i=0; i<graph[v].size(); ++i){
        if(graph[v][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}

int Answer(){
    int sum = -1;
    for(const auto& p : visited){
        sum += (int)p;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int computerAmount;
    int linkCnt;
    cin >> computerAmount >> linkCnt;
    graph.resize(computerAmount, vector<int>(computerAmount, 0));
    visited.resize(computerAmount, 0);
    for(int i=0; i<linkCnt; i++){
        int node, link;
        cin >> node >> link;
        graph[node-1][link-1] = 1;
        graph[link-1][node-1] = 1;
    }
    
    DFS(0);
    
    cout << Answer();
}