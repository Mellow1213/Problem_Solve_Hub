#include <vector>
#include <iostream>
using namespace std;

bool IsPrimeNum(int sum) {    
    if(sum <= 1) return false;
    
    for(int i=2; i*i <= sum; i++) {
        if(sum % i == 0)
            return false;
    }
    return true;
}

void BackTrack(const vector<int>& nums, int start, int depth, int sum, int& answer) {
    if(depth == 3) {
        if(IsPrimeNum(sum)) answer++;        
        return;
    }        
    
    for(int i=start; i< nums.size(); i++) {
        BackTrack(nums, i+1, depth+1, sum + nums[i], answer);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    BackTrack(nums, 0, 0, 0, answer);
    return answer;
}