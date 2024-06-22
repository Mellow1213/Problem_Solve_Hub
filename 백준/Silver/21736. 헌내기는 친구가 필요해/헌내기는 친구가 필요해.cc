#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int BFS(pair<int, int> startPos){
    int meetPeople = 0;
    
    int y = startPos.first;
    int x = startPos.second;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    q.push(make_pair(y, x));
    visited[y][x] = true;
    
    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            if(curX+dx[i]<0 || curX+dx[i]>=graph[0].size() 
                || curY+dy[i]<0 || curY+dy[i]>=graph.size()){
                continue;
            }
            
            char status = graph[curY+dy[i]][curX+dx[i]];
            
            if(status == 'X')
                continue;
            
            if(!visited[curY+dy[i]][curX+dx[i]]){
                q.push(make_pair(curY+dy[i], curX+dx[i]));
                visited[curY+dy[i]][curX+dx[i]] = true;
                if(status == 'P')
                    meetPeople++;
            }
        }
    }
    
    return meetPeople;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    pair<int, int> startPos;
    cin >> N >> M;
    
    graph.assign(N, vector<char>(M));
    visited.assign(N, vector<bool>(M, false));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'I')
                startPos = make_pair(i, j);
        }
    }
    
    
    int answer = BFS(startPos);
    if(answer <= 0)
        cout << "TT";
    else
        cout << answer;
}