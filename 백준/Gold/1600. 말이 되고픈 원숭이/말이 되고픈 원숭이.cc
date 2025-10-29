#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

struct Pos {
    int y;
    int x;
    int depth;
    Pos operator+(Pos p2) {
        Pos ret;
        ret.y = y + p2.y;
        ret.x = x + p2.x;
        ret.depth = depth + p2.depth;
        return ret;
    }
    Pos(int _y, int _x, int _depth) {
        y = _y;
        x = _x;
        depth = _depth;
    }
    Pos() { }
};
int K; // 원숭이가 말처럼 움직일 수 있는 횟수
int W, H; // 격자의 가로, 세로
vector<vector<int>> maps; // 격자판
vector<vector<vector<int>>> visit;
queue<pair<Pos, int>> que;

const int dx[4] = {1, -1, 0, 0}; // 원숭이 X 움직임
const int dy[4] = {0, 0, 1, -1}; // 원숭이 Y 움직임
const int horseDx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // 말 X 움직임
const int horseDy[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // 말 Y 움직임

bool IsValidPosition(int y, int x) {
    bool isValid = x >= 0 && y >= 0 && x < W && y < H;
    return isValid;
}

int main()
{
    FastIO
    cin >> K;
    cin >> W >> H;
    
    maps.assign(H, vector<int>(W));
    visit.assign(H, vector<vector<int>>(W, vector<int>(K+1)));
    
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> maps[i][j];
        }
    }
    
    que.push({{0, 0, 0},0});
    visit[0][0][0] = true;
    int answer = -1;
    while(!que.empty()) {
        Pos curPos = que.front().first;
        int level = que.front().second;
        que.pop();
        
        if(curPos.y == H-1 && curPos.x == W-1) {
            answer = level;
            break;
        }
        
        for(int i=0; i<4; i++) {
            Pos nextPos = curPos + Pos(dy[i], dx[i], 0);
            if(!IsValidPosition(nextPos.y, nextPos.x)) continue;
            if(visit[nextPos.y][nextPos.x][nextPos.depth]) continue;
            if(maps[nextPos.y][nextPos.x] == 1) continue;
            visit[nextPos.y][nextPos.x][nextPos.depth] = true;
            que.push({nextPos, level+1});
        }
        for(int i=0; i<8; i++) {
            Pos nextPos = curPos + Pos(horseDy[i], horseDx[i], 1);
            if(nextPos.depth > K) continue;
            if(!IsValidPosition(nextPos.y, nextPos.x)) continue;
            if(visit[nextPos.y][nextPos.x][nextPos.depth]) continue;
            if(maps[nextPos.y][nextPos.x] == 1) continue;
            visit[nextPos.y][nextPos.x][nextPos.depth] = true;
            que.push({nextPos, level+1});
        }
    }
    cout << answer;
}