#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> box;
vector<vector<int>> visited; // 익는 속도
queue<pair<int, int>> q;
int M, N;

void BFS(){
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && box[nx][ny] == 0){
                if(visited[nx][ny] == -1){
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;
    
    box.assign(N, vector<int>(M));
    visited.assign(N, vector<int>(M, -1));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> box[i][j];
            if(box[i][j] == 1){
                q.push(make_pair(i, j));
                visited[i][j] = 0;
            }
            else if(box[i][j] == -1){
                visited[i][j] = -1;
            }
        }
    }
    
    BFS();
    
    int top = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(box[i][j] != -1 && visited[i][j] == -1){
                cout << -1;
                return 0;
            }
            if(visited[i][j] > top)
                top = visited[i][j];
        }
    }
    cout << top;
}