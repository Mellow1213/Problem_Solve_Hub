#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
vector<vector<int>> vec;

bool OutOfBound(const int& x, const int& y){
    return x<0 || x>=vec.size() || y<0 || y>=vec.size();
}

void BFS(int& startX, int& startY, int& endX, int& endY){
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    vec[startX][startY] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(x==endX && y==endY){
            break;
        }
        q.pop();
        
        for(int i=0; i<8; i++){
            int curX = x + dx[i];
            int curY = y + dy[i];
            
            if(OutOfBound(curX, curY))
                continue;
                
            if(vec[curX][curY] == -1){
                vec[curX][curY] = vec[x][y]+1;
                q.push(make_pair(curX, curY));
            }
        }
    }
    
    cout << vec[endX][endY] << '\n';
}

void Solve(){
    int length;
    int startX, startY, destX, destY;
    cin >> length;
    cin >> startX >> startY;
    cin >> destX >> destY;
    
    vec.assign(length, vector<int>(length, -1));
    
    BFS(startX, startY, destX, destY);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int testCase;
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
        Solve();
    }
}