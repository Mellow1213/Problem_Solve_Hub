#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compareLess(int a, int b){
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M, R;
    int depth = 0;
    cin >> N >> M >> R;
    
    vector<vector<int>> adj(N+1, vector<int>());
    vector<int> visit(N+1, 0);
    queue<int> q;
    
    {
        int temp1, temp2;
        for(int i=0; i<M; i++){
            cin >> temp1 >> temp2;
            adj[temp1].push_back(temp2);
            adj[temp2].push_back(temp1);
        }
    }
    
    for(auto& p : adj){
        sort(p.begin(), p.end(), compareLess);
    }
    
    q.push(R);
    visit[R] = ++depth;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        
        for(const auto& p : adj[top]){
            if(visit[p] == 0){
                visit[p] = ++depth;
                q.push(p);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        cout << visit[i] << '\n';
    }
}