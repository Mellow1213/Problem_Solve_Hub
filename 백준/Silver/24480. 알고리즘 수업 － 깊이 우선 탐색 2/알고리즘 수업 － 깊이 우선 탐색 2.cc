#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j){
    return j<i;
}

void DFS(vector<vector<int>>& adj, vector<int>& visit, int index){
    static int depth = 0;
    visit[index] = ++depth;
    
    for(const auto& p: adj[index]){
        if(visit[p] == 0){
            DFS(adj, visit, p);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M, R;
    cin >> N >> M >> R;
    
    vector<vector<int>> adj(N+1);
    vector<int> visit(N+1, 0);
    int inputBegin, inputEnd;
    for(int i=0; i<M; i++){
        cin >> inputBegin >> inputEnd;
        adj[inputBegin].push_back(inputEnd);
        adj[inputEnd].push_back(inputBegin);
    }
    
    for(auto& p : adj){
        sort(p.begin(), p.end(), compare);
    }
    
    DFS(adj, visit, R);
    
    for(int i=1; i<=N; i++){
        cout << visit[i] << '\n';
    }
}