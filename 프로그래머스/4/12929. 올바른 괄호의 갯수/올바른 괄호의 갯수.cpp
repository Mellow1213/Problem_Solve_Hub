#include <stack>
#include <vector>

using namespace std;

stack<int> st;

int answer = 0;
int N;

void BackTrack(int leftUse, int rightUse) {
    if (leftUse == N && rightUse == N) {
        answer++;
        return;
    }

    if (leftUse < N) {
        BackTrack(leftUse + 1, rightUse);
    }
    if (rightUse < leftUse) {
        BackTrack(leftUse, rightUse + 1);
    }
}

int solution(int n) {
    N = n;
    BackTrack(0, 0);    
    return answer;
}