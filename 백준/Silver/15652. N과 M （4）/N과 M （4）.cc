#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int N, M;

void Backtrack(int num, int depth){
    if(depth == M){
        for(const auto& p : vec){
            cout << p << ' ';
        }
        cout << '\n';
        return;
    }
    
    
    for(int i=num; i<=N; i++){
        vec[depth] = i;
        Backtrack(i, depth+1);
    }
}

int main()
{
    cin >> N >> M;
    vec.assign(M, -1);
    
    Backtrack(1, 0);
}