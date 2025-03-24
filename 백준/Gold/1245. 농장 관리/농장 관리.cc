#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> visit;
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool IsValid(int y, int x) {
    return y >= 0 && x >= 0 && y < N && x < M;
}

bool isPeak;
void DFS(int y, int x, int height) {
    visit[y][x] = true;
    
    for (int i = 0; i < 8; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!IsValid(ny, nx)) continue;

        if (map[ny][nx] > height)
            isPeak = false;  // 주변에 더 높은 애 있음 -> 봉우리 아님

        if (!visit[ny][nx] && map[ny][nx] == height)
            DFS(ny, nx, height);  // 같은 높이면 계속 탐색
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    map.assign(N, vector<int>(M));
    visit.assign(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    int topCnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visit[i][j]) {
                isPeak = true;
                DFS(i, j, map[i][j]);
                if (isPeak)
                    ++topCnt;
            }
        }
    }
    cout << topCnt;
}
