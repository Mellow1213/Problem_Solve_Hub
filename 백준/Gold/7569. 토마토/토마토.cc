#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<vector<int>>> tomatoBox;
int M, N, H;
int totalTomatoes = 0;  
int ripeTomatoes = 0;

struct Box
{
    int H;
    int N;
    int M;
    int date;
};

queue<Box> q;

int BFS(){
    
    int dx[] = {0, 0, 0, 0, 1, -1};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dz[] = {1, -1, 0, 0, 0, 0};
    int ripDate = 0;
    
    while(!q.empty()){
        Box box = q.front();
        ripDate = box.date;
        q.pop();
        
        for(int i=0; i<6; i++){
            int x = box.M + dx[i];
            int y = box.N + dy[i];
            int z = box.H + dz[i];
            
            if(x < 0 || y < 0 || z < 0 || x >= M || y >= N || z >= H)
                continue;
            
            if(tomatoBox[z][y][x] == 0){
                tomatoBox[z][y][x] = 1;
                q.push({z, y, x, box.date+1});
                ripeTomatoes++;
            }
        }
    }
    
    return ripDate;
}

void InputData(){
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> tomatoBox[i][j][k];
            
                if(tomatoBox[i][j][k]==0){
                    totalTomatoes++;
                }
                else if(tomatoBox[i][j][k] == 1){
                    totalTomatoes++;
                    ripeTomatoes++;
                    q.push({i, j, k, 0});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N >> H;
    
    tomatoBox.assign(H, vector<vector<int>>(N, vector<int>(M)));
    
    InputData();
    
    if(totalTomatoes == ripeTomatoes){ // 받은 토마토가 이미 다 익은 상태인 경우
        cout << 0;
        return 0;
    }
    
    int answer = BFS();
    cout << (totalTomatoes==ripeTomatoes ? answer : -1);
}