#include <iostream>
#include <queue>

using namespace std;

int D(int reg){
    return (reg*2)%10000;
}
int S(int reg){
    return reg-1 < 0 ? 9999 : reg-1;
}
int L(int reg){
    return ((reg%1000)*10) + (reg/1000);
}
int R(int reg){
    return (reg/10) + ((reg%10)*1000);
}

string ch[4] = { "D", "S", "L", "R" };
int (*calcPtr[4])(int) = { D, S, L, R };

void BFS(int start, int target){
    queue<pair<int, string>> q; // pair ( 각 시점의 연산 결과 , 현재까지의 연산산 로그 )
    bool visited[10000] = { false, };
    
    q.push(make_pair(start, ""));
    visited[start] = true;
    
    while(!q.empty()){
        int calcNum = q.front().first;
        string calcLog = q.front().second;
            
        if(calcNum == target){
            cout << calcLog << '\n';
            break;
        }
            
        q.pop();
            
        for(int i=0; i<4; i++){
            int tempNum = calcPtr[i](calcNum); // 함수 포인터를 사용하여 함수 호출
            if(!visited[tempNum]){
                q.push(make_pair(tempNum, calcLog + ch[i]));
                visited[tempNum] = true;
            }
        }
    }
        
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int reg;
    int testCase;
    
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
        int beginNum, endNum;
        cin >> beginNum >> endNum;
        
        BFS(beginNum, endNum);
    }
}