#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> answer;
int N, M, K, X;

int main()
{
    FastIO
    cin >> N >> M >> K >> X;
    
    adj.assign(N+1, vector<int>());
    visit.assign(N+1, false);
    
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    queue<pair<int, int>> q;
    q.push({X, 0});
    visit[X] = true;
    while(!q.empty()) {
        int curNode = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(depth == K) {
            answer.push_back(curNode);
        }
        
        for(const auto& p : adj[curNode]) {
            if(visit[p]) continue;
            
            visit[p] = true;
            q.push({p, depth+1});
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(!answer.empty()) {
        for(const auto& p : answer) {
            cout << p << '\n';
        }
    } else {
        cout << -1;
    }
    
    
}