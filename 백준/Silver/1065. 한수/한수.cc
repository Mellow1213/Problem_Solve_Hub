#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    int answer = 0;
    vector<int> temp(4);
    cin >> N;
    
    if(N<100) {
        answer = N;
    } else if(N == 1000) {
        answer = 144;
    } else {
        answer = 99;
        for(int i=100; i<=N; i++) {
            int curNum = i;
            for(int j=2; j>=0; j--) {
                temp[j] = curNum%10;
                curNum /= 10;
            }
            if(temp[2]-temp[1] == temp[1]-temp[0]) {
                answer++;
            }
            fill(temp.begin(), temp.end(), 0);
        }
    }
    
    cout << answer;
}