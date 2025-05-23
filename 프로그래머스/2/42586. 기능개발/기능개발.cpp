#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    queue<int> q;
    for(int i=0; i<size; i++) {
        int leftTime = 100-progresses[i];
        int queueData = (leftTime + speeds[i] -1) / speeds[i]; // ceil 연산
        q.push(queueData);
    }
    
    while(!q.empty()) {
        int popCnt = 1; // 우선 front 기능도 배포되었으므로.
        int curFront = q.front();
        q.pop();
        
        while(!q.empty() && q.front() <= curFront) {
            popCnt++;
            q.pop();
        }
        
        answer.push_back(popCnt);
    }
    return answer;
    
}