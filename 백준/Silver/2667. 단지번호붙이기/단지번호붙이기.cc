#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<char>> graph;
vector<vector<bool>> visited;

int BFS(int b, int a){
    queue<pair<int, int>> q;
    int sum = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    q.push(make_pair(b, a));
    visited[b][a] = true;
    sum++;
    
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        
        for(int i=0; i<4; i++){
            int curY = y+dy[i];
            int curX = x+dx[i];
            
            if(curX<0 || curX >= graph[0].size() || curY < 0 || curY >= graph.size()){
                continue;
            }
            
            if(graph[curY][curX] == '1' && !visited[curY][curX]){
                visited[curY][curX] = true;
                q.push(make_pair(curY, curX));
                sum++;
            }
        }
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    vector<int> apartment;
    cin >> N;
    graph.assign(N, vector<char>(N));
    visited.assign(N, vector<bool>(N, false));
    
    for(int j=0; j<N; j++){
        string temp;
        cin >> temp;
        for(int i=0; i<N; i++){
            graph[j][i] = temp[i];
        }
    }
    
    for(int j=0; j<N; j++){
        for(int i=0; i<N; i++){
            if(!visited[j][i] && graph[j][i]=='1'){
                apartment.push_back(BFS(j, i));
            }
        }
    }
    
    sort(apartment.begin(), apartment.end());
    cout << apartment.size();
    for(const auto& p : apartment){
        cout << '\n' << p;
    }
}