#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int x){
    for(int i=0; i<adj[x].size(); i++){ // 해당 출발지에서의 인접 노드 전부 탐색
        if(!visited[adj[x][i]])
        {
            visited[adj[x][i]] = true;
            DFS(adj[x][i]);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    
    adj.assign(N, vector<int>());
    
    char temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> temp;
            if(temp == '1')
                adj[i].push_back(j);
        }
    }
    
    for(int i=0; i<N; i++){
        visited.assign(N, false);
        DFS(i);
        for(int j=0; j<N; j++){
            cout << visited[j] << ' ';
        }
        cout << '\n';
    }
}