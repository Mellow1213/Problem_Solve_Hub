#include <iostream>
#include <vector>
using namespace std;

bool IsHansu(int n) {
    if(n<100) return true;
    
    vector<int> nums;
    int temp = n;
    
    // 입력된 정수의 역순으로 Vector에 저장되나, 연산에는 문제 없음.
    while(temp > 0) {
        nums.push_back(temp % 10);
        temp /= 10;
    }
    
    int d = nums[0] - nums[1];
    // 공차를 0-1구간으로 설정했으므로 i=2부터 시작.
    for(int i=2; i<nums.size(); i++) {
        // 공차 계산 때의 뺄셈 순서를 연산때도 동일하게
        if(nums[i-1] - nums[i] != d) {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    int answer = 0;
    cin >> N;
    for(int i=1; i<=N; i++) {
        if(IsHansu(i)) answer++;
    }
    cout << answer;
}