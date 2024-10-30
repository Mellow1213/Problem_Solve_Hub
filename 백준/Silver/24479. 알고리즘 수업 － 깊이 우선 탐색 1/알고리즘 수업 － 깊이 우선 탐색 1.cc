#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> visit;
int visitLevel = 0;
void DFS(int x){
    visit[x] = ++visitLevel;
    for(const auto& p : adj[x]){
        if(visit[p] == 0){
            DFS(p);
        }
    }
}

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    
    adj.assign(N+1, vector<int>());
    visit.assign(N+1, 0);
    for(int i=0; i<N; i++){
        adj[i].reserve(2);
    }
    
    int tmp1, tmp2;
    for(int i=0; i<M; i++){
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    
    for(auto& p : adj){
        sort(p.begin(), p.end());
    }
    
    DFS(R);
    
    for(int i=1; i<=N; i++){
        cout << visit[i] << '\n';
    }
}