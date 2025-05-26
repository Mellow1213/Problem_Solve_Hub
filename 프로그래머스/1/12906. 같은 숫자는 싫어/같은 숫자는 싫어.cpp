#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prevNum = -1;
    for(const int& p : arr) {
        if(p != prevNum) {
            answer.push_back(p);
        }        
        prevNum = p;
    }

    return answer;
}