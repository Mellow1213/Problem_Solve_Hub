#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> portal(101, -1);

void BFS() {
    queue<pair<int, int>> q;
    vector<bool> visited(101, false);
    int dx[6] = {1, 2, 3, 4, 5, 6};
    
    q.push(make_pair(1, 0));
    visited[1] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if(x == 100) {
            cout << depth << endl;
            return;
        }
        
        for(int i = 0; i < 6; i++) {
            int curX = x + dx[i];
            if(curX <= 100 && !visited[curX]) {
                visited[curX] = true;
                if(portal[curX] != -1) {
                    curX = portal[curX];
                }
                q.push(make_pair(curX, depth + 1));
            }
        }
    }
}

int main() {
    int ladder, snake;
    cin >> ladder >> snake;
    
    int temp1, temp2;
    for(int i = 0; i < ladder + snake; i++) {
        cin >> temp1 >> temp2;
        portal[temp1] = temp2;
    }
    
    BFS();
    return 0;
}
