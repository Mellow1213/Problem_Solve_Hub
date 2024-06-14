#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<bool>> graph;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 깊이 우선 탐색(DFS) 함수
void DFS(int x, int y, int width, int length) {
    stack<pair<int, int>> s;
    s.push(make_pair(x, y));
    visited[x][y] = true;
    
    while (!s.empty()) {
        int curX = s.top().first;
        int curY = s.top().second;
        s.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if (nx >= 0 && nx < width && ny >= 0 && ny < length && !visited[nx][ny] && graph[nx][ny]) {
                s.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void SolveProblem() {
    int width, length, cabbageAmount;
    cin >> width >> length >> cabbageAmount;
    
    graph.assign(width, vector<bool>(length, false));
    visited.assign(width, vector<bool>(length, false));
    
    for (int i = 0; i < cabbageAmount; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = true;
    }
    
    int componentCount = 0;
    
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < length; ++j) {
            if (graph[i][j] && !visited[i][j]) {
                DFS(i, j, width, length);
                ++componentCount;
            }
        }
    }
    
    cout << componentCount << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for (int t = 0; t < testCase; ++t) {
        SolveProblem();
    }
    
    return 0;
}