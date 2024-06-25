#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    
    vector<vector<char>> graph(N, vector<char>(M));
    vector<vector<int>> distance(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    
    string temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<M; j++){
            graph[i][j] = temp[j];
        }
    }
    
    q.push(make_pair(0, 0));
    distance[0][0] = 1;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int curX = x+dx[i];
            int curY = y+dy[i];
            
            if(curX<0 || curY<0 || curX>=M || curY>=N){
                continue;
            }
            
            if(graph[curY][curX] == '1' && distance[curY][curX] == 0){
                distance[curY][curX] = distance[y][x]+1;
                q.push(make_pair(curY, curX));
            }
        }
    }
    
    cout << distance[N-1][M-1];
}