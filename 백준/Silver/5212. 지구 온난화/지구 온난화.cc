#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> originMap;
vector<vector<bool>> visit;
vector<pair<int, int>> shrinkQueue;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool IsValidBoundary(int y, int x) {
    return y >= 0 && x >= 0 && y < originMap.size() && x < originMap[0].size();
}

void DFS(int y, int x) { 
    int destroyCnt = 0;
    visit[y][x] = true;
    
    for(int i=0; i<4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];
        
        if(!IsValidBoundary(newY, newX)){
            destroyCnt++;
            continue;
        }
        
        if(originMap[newY][newX] == '.') {
            destroyCnt++;
            continue;
        }
        
        if(!visit[newY][newX])
            DFS(newY, newX);
    }
    
    if(destroyCnt >= 3) {
        shrinkQueue.push_back({y, x});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int row, column;
    cin >> row >> column;
    
    originMap.assign(row, vector<char>(column, ' '));
    visit.assign(row, vector<bool>(column, false));
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            cin >> originMap[i][j];
        }
    }
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            if(originMap[i][j] == '.' && !visit[i][j]) {
                DFS(i, j);
            }
        }
    }
    
    for(auto& p : shrinkQueue) {
        originMap[p.first][p.second] = '.';
    }
    
    int range[4] = { row, column, -1, -1 };
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            if(originMap[i][j] == 'X') {
                range[0] = min(range[0], i);
                range[1] = min(range[1], j);
                range[2] = max(range[2], i);
                range[3] = max(range[3], j);
            }
        }
    }
    
    for(int i = range[0]; i <= range[2]; i++) {
        for(int j=range[1]; j <= range[3]; j++) {
            cout << originMap[i][j];
        }
        cout << '\n';
    }
    
    
}