#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> visited;
bool isColorBlind = false;
bool IsSameColor(char a, char b){
    if(isColorBlind && a!='B'){
        return (b!='B' ? true : false);
    }
    return a == b;
}

void BFS(int i, int j){
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = true;
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int range = graph.size(); // 그래프의 x와 y의 길이는 N으로 같음.
    char areaColor = graph[i][j];
    
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        
        for(int i=0; i<4; i++){
            int curX = x+dx[i];
            int curY = y+dy[i];
            
            if(curX<0 || curX>=range || curY<0 || curY>=range){
                continue;
            }
            
            if(IsSameColor(graph[curY][curX], areaColor) && !visited[curY][curX]){
                q.push(make_pair(curY, curX));
                visited[curY][curX] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    graph.assign(N, vector<char>(N));
    visited.assign(N, vector<bool>(N, false));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> graph[i][j];
        }
    }
    
    int area = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                BFS(i, j);
                area++;
            }
        }
    }
    cout << area;
    
    visited.assign(N, vector<bool>(N, false));
    isColorBlind = true;
    area = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                BFS(i, j);
                area++;
            }
        }
    }
    cout << ' ' << area;
}