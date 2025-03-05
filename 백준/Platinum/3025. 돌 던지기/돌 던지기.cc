#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <string>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int R, C;
vector<vector<char>> grid;
vector<set<int>> walls;               // 각 열의 장애물(벽 또는 돌) 위치를 저장
vector<stack<pair<int, int>>> checkpoint;  // 각 열에 대해 돌이 떨어지는 마지막 분기점을 저장

// 돌을 떨어뜨리는 함수
void DropStone(int row, int col, int start) {
    // 현재 열 col에서 row 아래 첫 번째 장애물의 행 H를 찾음
    int H = *walls[col].upper_bound(row);
    
    if(grid[H][col] == 'O') { // 돌을 만난 경우 -> 좌/우 미끄러지기 시도
        // 왼쪽으로 미끄러질 수 있는지 검사
        if(col - 1 >= 1 && grid[H][col - 1] == '.' && grid[H - 1][col - 1] == '.') {
            checkpoint[start].push({H - 1, col});
            DropStone(H - 1, col - 1, start);
            return;
        }
        // 오른쪽으로 미끄러질 수 있는지 검사
        else if(col + 1 <= C && grid[H][col + 1] == '.' && grid[H - 1][col + 1] == '.') {
            checkpoint[start].push({H - 1, col});
            DropStone(H - 1, col + 1, start);
            return;
        }
        else { // 미끄러질 수 없으면 현재 위치에 돌을 놓음
            grid[H - 1][col] = 'O';
            // 기존 돌 장애물을 제거하고 새 돌의 위치를 업데이트
            walls[col].erase(H);
            walls[col].insert(H - 1);
            return;
        }
    }
    else { // 벽('X')을 만난 경우 -> 그대로 H-1 위치에 돌을 놓음
        grid[H - 1][col] = 'O';
        // 벽은 그대로 두고 새 돌 위치만 추가
        walls[col].insert(H - 1);
        return;
    }
}

int main() {
    FastIO;
    
    cin >> R >> C;
    // grid는 경계(0행, R+1행, 0열, C+1열)에 'X'를 두어 범위검사를 쉽게 함
    grid.assign(R + 2, vector<char>(C + 2, 'X'));
    walls.assign(C + 1, set<int>());
    checkpoint.assign(C + 1, stack<pair<int, int>>());
    
    // 1행부터 R행, 1열부터 C열에 입력 보드를 채움
    for (int i = 1; i <= R; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= C; j++) {
            grid[i][j] = s[j - 1];
            // 보드에 'X'이면 해당 위치를 walls에 추가
            if (grid[i][j] == 'X') {
                walls[j].insert(i);
            }
        }
    }
    // 각 열의 바닥(행 R+1)은 항상 벽이므로 추가
    for (int j = 1; j <= C; j++) {
        walls[j].insert(R + 1);
    }
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int start;
        cin >> start;
        int y, x;
        // 이전에 저장해둔 checkpoint가 있다면 사용
        while (!checkpoint[start].empty()) {
            y = checkpoint[start].top().first;
            x = checkpoint[start].top().second;
            if (grid[y][x] != '.')
                checkpoint[start].pop();
            else
                break;
        }
        if (checkpoint[start].empty()) {
            DropStone(1, start, start);
        } else {
            DropStone(y, x, start);
        }
    }
    
    // 최종 보드 상태 출력 (1행 ~ R행)
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
