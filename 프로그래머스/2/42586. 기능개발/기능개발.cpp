#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    int releaseDate = 0;
    for(int i=0; i<size; i++) {
        int leftTime = 100-progresses[i];
        int queueData = (leftTime + speeds[i] -1) / speeds[i]; // ceil 연산
        
        if(answer.empty() || releaseDate < queueData) {
            answer.push_back(1);
            releaseDate = queueData;
        } else {
            answer.back()++;  
        }
    }
    
    return answer;    
}