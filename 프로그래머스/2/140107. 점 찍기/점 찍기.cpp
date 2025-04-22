#include <string>
#include <vector>
#include <cmath>

using namespace std;


long long solution(int k, int d) {
    long long answer = 0;
    
    for(int i=0; i<=d; i+=k) {
        long long maxY = sqrt(1LL * d * d  -  1LL * i * i);
        answer += floor(maxY) / k + 1;
    }
    
    return answer;
}