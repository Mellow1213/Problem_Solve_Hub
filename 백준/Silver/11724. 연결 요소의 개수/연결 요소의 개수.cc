#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> inj;
vector<bool> visited;

void DFS(int x){
    visited[x] = true;
    for(int i=0; i<inj[x].size(); i++){
        if(!visited[inj[x][i]]){
            DFS(inj[x][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int node, link;
    int answer = 0;
    cin >> node >> link;
    
    inj.assign(node, vector<int>());
    visited.assign(node, false);
    
    for(int i=0; i<link; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        temp1--; temp2--;
        inj[temp1].push_back(temp2);
        inj[temp2].push_back(temp1);
    }
    
    for(int i=0; i<node; i++){
        if(!visited[i]){
            DFS(i);
            answer++;
        }   
    }
    
    cout << answer;
}