#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int left = 0;
    
    for(const auto& p : s) {
        if(p == '(') {
            left++;
        } else {
            if(left > 0) left--;
            else {
                answer=false;
                break;
            }
        }
    }
    
    if(left > 0) answer = false;
    
    return answer;
}