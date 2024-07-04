#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int reg;
    
    int testCase;
    
    cin >> testCase;
    
    
    char ch[4] = { 'D', 'S', 'L', 'R' };
    while(testCase>0){
        queue<pair<int, string>> q; // pair ( 각 시점의 연산 결과 , 현재까지의 연산산 로그 )
        bool visited[10000] = { false, };
        int beginNum, endNum;
        string answer;
        
        cin >> beginNum >> endNum;
        visited[beginNum] = true;
        q.push(make_pair(beginNum, ""));
        
        while(!q.empty()){
            int calcNum = q.front().first;
            string calcLog = q.front().second;
            
            if(calcNum == endNum){
                answer = calcLog;
                break;
            }
            
            q.pop();
            
            int tempNum;
            
            tempNum = (calcNum*2)%10000;
            if(!visited[tempNum]){
                q.push(make_pair(tempNum, calcLog+"D"));
                visited[tempNum] = true;
            }
            
            tempNum = calcNum-1 < 0 ? 9999 : calcNum-1;
            if(!visited[tempNum]){
                q.push(make_pair(tempNum, calcLog+"S"));
                visited[tempNum] = true;
            }
            
            tempNum = ((calcNum%1000)*10) + (calcNum/1000);
            if(!visited[tempNum]){
                q.push(make_pair(tempNum, calcLog+"L"));
                visited[tempNum] = true;
            }
            
            tempNum = (calcNum/10) + ((calcNum%10)*1000);
            if(!visited[tempNum]){
                q.push(make_pair(tempNum, calcLog+"R"));
                visited[tempNum] = true;
            }
        }
        
        cout << answer << '\n';
        testCase--;
    }
}