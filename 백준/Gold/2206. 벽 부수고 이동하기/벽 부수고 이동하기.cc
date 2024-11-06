#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int distance;
    bool isBreak;
    Node(int _x, int _y, int _distance, bool _isBreak) : x(_x), y(_y), distance(_distance), isBreak(_isBreak) {}
};

int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;
bool IsBoundary(int x, int y){
    return x>=0 && x<N && y>=0 && y<M;
}

int main() {
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<pair<bool, bool>>> visit(N, vector<pair<bool, bool>>(M, make_pair(false, false)));
    
    string line;
    for(int i=0; i<N; i++){
        cin >> line;
        for(int j=0; j<M; j++){
            graph[i][j] = line[j] - '0';
        }
    }
    
    queue<Node> q;
    q.push(Node(0, 0, 0, false));
    visit[0][0] = make_pair(true, true);
    int answer = -1;
    while(!q.empty()){
        Node curNode = q.front();
        q.pop();
        
        if(curNode.x == N-1 && curNode.y == M-1){
            answer = curNode.distance+1;
            break;
        }
        
        for(int i=0; i<4; i++){
            int nextX = curNode.x + dx[i];
            int nextY = curNode.y + dy[i];
            int nextDist = curNode.distance + 1;
            if(!IsBoundary(nextX, nextY))
                continue;
            if(graph[nextX][nextY] == 0){
                if(!curNode.isBreak && !visit[nextX][nextY].first){
                    visit[nextX][nextY].first = true;
                    q.push(Node(nextX, nextY, nextDist, curNode.isBreak));
                }
                else if(curNode.isBreak && !visit[nextX][nextY].second){
                    visit[nextX][nextY].second = true;
                    q.push(Node(nextX, nextY, nextDist, curNode.isBreak));
                }
            }
            else if(graph[nextX][nextY] == 1){
                if(!curNode.isBreak && !visit[nextX][nextY].first){
                   visit[nextX][nextY].second = true;
                    q.push(Node(nextX, nextY, nextDist, true));
                 }
            }
        }
    }
    cout << answer;
}