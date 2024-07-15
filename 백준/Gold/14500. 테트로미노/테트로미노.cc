#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
int answer = -1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int y, int x, int depth, int sum){
    if(depth == 4){
        answer = max(answer, sum);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int curX = x + dx[i];
        int curY = y + dy[i];
        
        if(curX < 0 || curX >= graph[0].size() || curY < 0 || curY >= graph.size())
            continue;
            
        if(visited[curY][curX])
            continue;
        
        visited[curY][curX] = true;
        DFS(curY, curX, depth + 1, sum + graph[curY][curX]);
        visited[curY][curX] = false;
    }
}

void HatShape(int i, int j){
    if (i - 1 >= 0 && j + 2 < graph[0].size()){
        int sum = 0;
        sum = graph[i][j] + graph[i][j + 1] + graph[i][j + 2] + graph[i - 1][j + 1];
        answer = max(answer, sum);
    }
    if (j + 2 < graph[0].size() && i + 1 < graph.size()){
        int sum = 0;
        sum = graph[i][j] + graph[i][j + 1] + graph[i][j + 2] + graph[i + 1][j + 1];
        answer = max(answer, sum);
    }
    if (i + 2 < graph.size() && j + 1 < graph[0].size()){
        int sum = 0;
        sum = graph[i][j] + graph[i + 1][j] + graph[i + 2][j] + graph[i + 1][j + 1];
        answer = max(answer, sum);
    }
    if (i + 1 < graph.size() && i - 1 >= 0 && j + 1 < graph[0].size()){
        int sum = 0;
        sum = graph[i][j] + graph[i - 1][j + 1] + graph[i][j + 1] + graph[i + 1][j + 1];
        answer = max(answer, sum);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    graph.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = true;
            DFS(i, j, 1, graph[i][j]);
            visited[i][j] = false;
            HatShape(i, j);
        }
    }
    cout << answer;
}
