#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    
    int left = 0;
    int right = 0;
    
    bool Init0 = false;
    
    while(left < X.size() && right < Y.size()) {
        if(X[left] == Y[right]) {
            answer += X[left];
            right++;
            left++;
        } else if(X[left] < Y[right]) {
            right++;
        } else {
            left++;
        }
    }
    
    if(answer == "") {
        answer = "-1";
    }
    else {        
        bool isFlag = true;
        for(const auto& p : answer) {
            isFlag &= (p == '0');
        }
        if(isFlag) answer = "0"; 
    }
    return answer;
}