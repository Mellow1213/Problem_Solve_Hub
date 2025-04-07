#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define row 12
#define column 6

vector<vector<char>> map;
vector<vector<bool>> visit;
const int dirY[4] = {0, 0, 1, -1};
const int dirX[4] = {1, -1, 0, 0};

bool IsValid(int y, int x) {
    return y >= 0 && x >= 0 && y < row && x < column;
}

void Show() {
    cout << "-----------------------\n";
    for(const auto& p : map) {
        for(const auto& q : p) {
            cout << q;
        }
        cout << '\n';
    }
}

void Show(string message) {
    Show();
    cout << message << '\n';
}

void Drop() {
    for(int z = 0; z<column; z++) {
        stack<char> q;
    
        for(int i=0; i<row; i++) {
            if(map[i][z] == '.' || map[i][z] == 'X') continue;
            q.push(map[i][z]);
        }
    
        int height = q.size();
        for(int i=row-1; i>=row-height; i--) {
            int lv = q.top();
            q.pop();
            map[i][z] = lv;
        }
        for(int i = row-height-1; i>=0; i--) {
            map[i][z] = '.';
        }
    }
}

bool BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;
    char color = map[y][x];
    int count = 1;
    vector<pair<int, int>> st;
    st.push_back({y, x});
    
    while(!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int moveY = curY + dirY[i];
            int moveX = curX + dirX[i];
            
            if(!IsValid(moveY, moveX))      continue;
            if(visit[moveY][moveX])         continue;
            if(map[moveY][moveX] != color)  continue;
            
            q.push({moveY, moveX});
            visit[moveY][moveX] = true;
            count++;
            st.push_back({moveY, moveX});
        }
    }
    
    if(count >= 4) {
        for(const auto& p : st) {
            map[p.first][p.second] = 'X';
        }
        return true;
    }
    return false;
}

int main()
{
    map.assign(row, vector<char>(column));
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            cin >> map[i][j];
        }
    }
    
    int cycle = 0;
    bool flag = true;
    while(flag) {
        visit.assign(row, vector<bool>(column, false));
        flag = false;
        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(map[i][j] == '.')
                    continue;
                flag |= BFS(i, j);
            }
        }
        
        if(flag) {
            Drop();
            cycle++;
        }
    }
    cout << cycle;
}