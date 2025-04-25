#include <vector>
#include <queue>

using namespace std;

int LongBFS(int n, vector<vector<int>> edge, int start) {
    vector<bool> visit(n, false);
    queue<pair<int, int>> q; // node, depth;
    
    q.push({start, 0});
    visit[start] = true;
    int highDepth = 0;
    int highCnt = 0;
    
    while(!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(highDepth < depth) {
            highDepth = depth;
            highCnt = 1;
        } else if (highDepth == depth){
            highCnt++;
        }
        
        for(const auto p : edge[node]) {
            if(visit[p]) continue;
            
            visit[p] = true;
            q.push({p, depth+1});
        }
    }
    return highCnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = -1;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0; i<edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    answer = LongBFS(n, adj, 1);
    
    
    return answer;
}