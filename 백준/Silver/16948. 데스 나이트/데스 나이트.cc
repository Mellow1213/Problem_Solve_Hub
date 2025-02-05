#include <iostream>
#include <vector>
#include <queue>

/*
std::ostream& operator<<(std::ostream& os, const pos& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
*/

struct pos {
    int x;
    int y;
};

pos operator+(const pos& posA, const pos& posB) { return {posA.x + posB.x, posA.y + posB.y}; }
bool operator==(const pos& posA, const pos& posB) { return posA.x == posB.x && posA.y == posB.y; }
bool CheckBoundary(const int boardSize, const pos& chkPos) {
    return chkPos.x >= 0 && chkPos.y >= 0 
            && chkPos.x < boardSize && chkPos.y < boardSize;
}

int BFS(const int boardSize, const pos startPos, const pos endPos) {
    std::queue<std::pair<pos, int>> q;
    std::vector<std::vector<bool>> visit(boardSize, std::vector<bool>(boardSize, false));
    
    const pos dir[6] = { {-2, -1}, {-2, 1}, {0, -2}, 
                            {0, 2}, {2, -1}, {2, 1}};
    
    q.push({startPos, 0});
    
    while(!q.empty()) {
        pos curPos = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(curPos == endPos) {
            return depth;
        }
        
        
        for(int i=0; i<6; i++) {
            pos nextPos = curPos + dir[i];
            if(!CheckBoundary(boardSize, nextPos)) {
                continue;
            }
            if(!visit[nextPos.x][nextPos.y]) {
                visit[nextPos.x][nextPos.y] = true;
                q.push({nextPos, depth+1});
            }
        }
    }
    return -1;
}
       

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int boardSize;
    std::cin >> boardSize;
    
    int startX, startY, endX, endY;
    std::cin >> startX >> startY >> endX >> endY;
    
    int travel = BFS(boardSize, {startX, startY}, {endX, endY});
    std::cout << travel;
}