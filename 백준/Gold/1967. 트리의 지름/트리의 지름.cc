// No.1967 트리의 지름 Gold IV
// https://www.acmicpc.net/problem/1967

#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj; // [1] -> {2, 10} == 1번 노드에서 2번 노드로 가는 간선의 비용은 10
vector<bool> visit;
vector<int> lens;

void DFS(int x, int len){
    visit[x] = true;
    for(const auto& p : adj[x]){
        if(!visit[p.first]){
            lens[p.first] = len+p.second;
            DFS(p.first, len+p.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    adj.assign(N+1, vector<pair<int, int>>());
    visit.assign(N+1, false);
    lens.assign(N+1, 0);

    int t0, t1, t2;
    for(int i=0; i<N-1; i++){
        cin >> t0 >> t1 >> t2;
        adj[t0].push_back({t1, t2});
        adj[t1].push_back({t0, t2});
    }

    DFS(1, 0);
    int big = -1;
    int idx;
    for(int i=1; i<lens.size(); i++){
        if(big < lens[i]){
            big = lens[i];
            idx = i;
        }
    }

    visit.assign(N+1, false);
    lens.assign(N+1, 0);

    DFS(idx, 0);

    big = -1;
    for(int i=1; i<lens.size(); i++){
        if(big < lens[i]){
            big = lens[i];
        }
    }
    cout << big;
}