#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    int pa, ch;
    cin >> pa >> ch;
    vector<vector<int>> adj(N+1, vector<int>());
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);
    }
    
    queue<pair<int, int>> q;
    vector<bool> visit(N+1, false);
    q.push({pa, 0});
    visit[pa] = true;
    
    int answer = -1;
    while(!q.empty()){
        int x = q.front().first;
        int depth = q.front().second;
        
        if(x == ch){
            answer = depth;
            break;
        }
        
        q.pop();
        
        for(const auto& p : adj[x]){
            if(!visit[p]){
                visit[p] = true;
                q.push({p, depth+1});
            }
        }
    }
    cout << answer;
    
}