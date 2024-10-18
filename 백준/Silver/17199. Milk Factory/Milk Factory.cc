#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

void DFS(int x){
    visit[x] = true;
    
    for(const auto& p : graph[x])
        if(!visit[p])
            DFS(p);
}

bool CheckTravel(){
    for(int i=1; i<graph.size(); i++){
        if(!visit[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    graph.assign(N+1, vector<int>());
    visit.assign(N+1, false);
    for(int i=0; i<N-1; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        graph[temp2].push_back(temp1);
    }
    
    int answer = -1;
    for(int i=0; i<N; i++){
        if(!graph[i].empty()){
            DFS(i);
            if(CheckTravel()){
                answer = i;
                break;
            }
            visit.assign(N+1, false);
        }
    }
    cout << answer;
}