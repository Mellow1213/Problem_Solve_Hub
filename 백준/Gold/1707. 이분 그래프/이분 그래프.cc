#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool BFS(const vector<vector<int>>& adj, vector<int>& visit, int start){
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    
    while(!q.empty()){
        int x = q.front();
        int color = visit[x];
        q.pop();
        
        for(auto& p : adj[x]){
            if(visit[p] == 0){
                visit[p] = color*-1;
                q.push(p);
            }
            else if(visit[p] == color){
                return false; // 하나라도 이분 그래프 조건에 맞지 않는 경우 false.
            }
        }
    }
    return true; // while문을 다 빠져나오면 이분 그래프의 조건을 충족.
}

void SolveProblem(){
    int V, E;
    bool result;
    cin >> V >> E;
    vector<vector<int>> adj(V+1, vector<int>());
    vector<int> visit(V+1, 0);
    
    int i1, i2;
    for(int i=0; i<E; i++){
        cin >> i1 >> i2;
        adj[i1].push_back(i2);
        adj[i2].push_back(i1);
    }
    
    for(int i=1; i<=V; i++){
        if(visit[i]==0){
            bool result = BFS(adj, visit, i);
            if(!result){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    FastIO();
    int testCase;
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
        SolveProblem();
    }
}
