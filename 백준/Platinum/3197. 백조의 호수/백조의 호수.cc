#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<char>> Graph;
typedef pair<int, int> Point;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool CheckBoundary(int y, int x, int R, int C){
    return x<0 || x>=C || y<0 || y>=R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int R, C;
    cin >> R >> C;
    
    Graph graph(R, vector<char>(C));
    queue<Point> waterQ, nextWaterQ;
    queue<Point> swanQ, nextSwanQ;
    Point swan1, swan2;
    bool isFirst = true;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'L') {
                if(isFirst) {
                    swan1 = {i, j};
                    isFirst = false;
                } else {
                    swan2 = {i, j};
                }
                graph[i][j] = '.';
                waterQ.push({i, j});
            }
            else if(graph[i][j] == '.') {
                waterQ.push({i, j});
            }
        }
    }
    
    swanQ.push(swan1);
    graph[swan1.first][swan1.second] = 'O';  // 백조가 지나간 자리를 O로 표시
    
    int days = 0;
    while(true) {
        // 백조 이동
        bool met = false;
        while(!swanQ.empty() && !met) {
            Point cur = swanQ.front();
            swanQ.pop();
            
            for(int i=0; i<4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                
                if(CheckBoundary(ny, nx, R, C)) continue;
                if(graph[ny][nx] == 'O') continue;  // 이미 방문한 곳
                
                if(ny == swan2.first && nx == swan2.second) {
                    met = true;
                    break;
                }
                
                if(graph[ny][nx] == '.') {
                    graph[ny][nx] = 'O';  // 방문 표시
                    swanQ.push({ny, nx});
                }
                else if(graph[ny][nx] == 'X') {
                    graph[ny][nx] = 'O';  // 방문 표시
                    nextSwanQ.push({ny, nx});
                }
            }
        }
        
        if(met) break;
        
        // 얼음 녹이기
        while(!waterQ.empty()) {
            Point cur = waterQ.front();
            waterQ.pop();
            
            for(int i=0; i<4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                
                if(CheckBoundary(ny, nx, R, C)) continue;
                
                if(graph[ny][nx] == 'X') {
                    graph[ny][nx] = '.';
                    nextWaterQ.push({ny, nx});
                }
            }
        }
        
        waterQ = nextWaterQ;
        swanQ = nextSwanQ;
        while(!nextWaterQ.empty()) nextWaterQ.pop();
        while(!nextSwanQ.empty()) nextSwanQ.pop();
        
        days++;
    }
    
    cout << days;
    return 0;
}