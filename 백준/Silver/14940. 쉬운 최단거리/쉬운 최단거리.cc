#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graphField;
vector<vector<bool>> visited;
vector<vector<int>> distanceMap;
queue<pair<int, int>> q;

void BFS(int x, int y){
    visited[x][y] = true;
    distanceMap[x][y] = 0;
    
    q.push(make_pair(x, y));
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            
            if(nx >= 0 && nx < graphField.size() && ny >= 0 && ny < graphField[0].size()){
                if(graphField[nx][ny] == 1 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    distanceMap[nx][ny] = distanceMap[current.first][current.second]+1;
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
    
    int n, m;
    int startX = -1;
    int startY = -1;
    cin >> n >> m;
    
    graphField.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<bool>(m, false));
    distanceMap.assign(n, vector<int>(m, -1));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graphField[i][j];
            if(graphField[i][j] == 2){
                startX = i;
                startY = j;
            }
            else if(graphField[i][j] == 0){
                distanceMap[i][j] = 0;
            }
        }
    }
    
    BFS(startX, startY);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << distanceMap[i][j] << ' ';
        }
        cout << '\n';
    }
}