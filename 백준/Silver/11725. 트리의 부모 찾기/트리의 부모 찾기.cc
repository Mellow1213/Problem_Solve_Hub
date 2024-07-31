#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class FindTreeParent{
    private:
        int N;
        vector<int> parentInfo; // first: child, second: parent
        vector<vector<int>> adj;
        queue<int> q;
    public:
        FindTreeParent(int n){
            N = n;
            parentInfo.assign(N+1, -1);
            adj.assign(N+1, vector<int>());
        }
        void BFS(int x){
           q.push(x);
            while(!q.empty()){
                int index = q.front();
                q.pop();
        
                for(const auto& p : adj[index]){
                    if(parentInfo[p] == -1){
                        parentInfo[p] = index;
                        q.push(p);
                    }
                }
            }    
        }
        void InputData(){
            for(int i=0; i<N-1; i++){
                int x, y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
        void Print(){
            for(int i=2; i<=N; i++){
                cout << parentInfo[i] << '\n';
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    FindTreeParent F(N);
    F.InputData();
    F.BFS(1);
    F.Print();
    
}