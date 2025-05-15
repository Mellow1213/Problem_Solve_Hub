#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student(n+1, 1);
    student[0] = 0;
    for(const auto& p : reserve) { student[p]++; }
    for(const auto& p : lost) { student[p]--; }
    
    for(const auto& p : student) {
        if(p >= 1) {
            answer++;
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(student[i] == 0)
            if(student[i-1] == 2) {
                answer++;
            } else if(student[i+1] == 2) {
                student[i+1]--;
                answer++;
            }
    }
    
    return answer;
}