#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> Pos;

int N, M;
int maxSafeArea = 0;
const int dirY[] = { -1, 1, 0, 0 };
const int dirX[] = { 0, 0, -1, 1 };

vector<vector<int>> map;
vector<Pos> virusPos;
vector<Pos> emptyPos;

// BFS를 위한 맵 복사본
vector<vector<int>> tempMap;

// 지도 경계 및 벽 여부 확인
bool isValid(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M && tempMap[y][x] == 0;
}

// 바이러스 확산 시뮬레이션
void BFS() {
    queue<Pos> q;
    for (const auto& p : virusPos) {
        q.push(p);
    }
    
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dirY[i];
            int nx = cur.second + dirX[i];
            
            if (isValid(ny, nx)) {
                tempMap[ny][nx] = 2; // 바이러스 확산
                q.push({ny, nx});
            }
        }
    }
}

// 안전 영역의 크기를 계산
int CountSafeArea() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempMap[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

// 재귀를 이용해 벽 3개를 세우는 함수
void SetWalls(int startIdx, int count) {
    // 3개의 벽을 모두 세웠다면
    if (count == 3) {
        tempMap = map; // 원본 맵을 복사
        BFS(); // 바이러스 확산 시뮬레이션 실행
        maxSafeArea = max(maxSafeArea, CountSafeArea()); // 안전 영역 최댓값 갱신
        return;
    }

    // 빈 공간을 하나씩 선택하며 벽을 세우고 재귀 호출
    for (int i = startIdx; i < emptyPos.size(); i++) {
        map[emptyPos[i].first][emptyPos[i].second] = 1; // 벽 세우기
        SetWalls(i + 1, count + 1); // 다음 벽을 세우러 재귀 호출
        map[emptyPos[i].first][emptyPos[i].second] = 0; // 벽 허물기 (백트래킹)
    }
}

int main() {
    cin >> N >> M;
    map.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virusPos.push_back({i, j});
            } else if (map[i][j] == 0) {
                emptyPos.push_back({i, j});
            }
        }
    }

    SetWalls(0, 0); // 벽 세우기 시작
    
    cout << maxSafeArea;

    return 0;
}