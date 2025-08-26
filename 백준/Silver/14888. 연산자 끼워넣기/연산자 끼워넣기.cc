#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int N;
vector<int> numbers;
vector<char> operation;
vector<bool> isUsed;
int minNum;
int maxNum;
void BackTrack(int depth, int sum) {
    if(depth >= N-1) {
        if(sum > maxNum) {
            maxNum = sum;
        }
        if(sum < minNum) {
            minNum = sum;
        }
        return;
    }
    
    for(int i=0; i<N-1; i++) {
        if(isUsed[i]) {
           continue; 
        }
        
        int nextSum = sum;
        switch(operation[i]) {
            case '+':
                nextSum += numbers[depth+1];
                break;
            case '-':
                nextSum -= numbers[depth+1];
                break;
            case '*':
                nextSum *= numbers[depth+1];
                break;
            case '/':
                nextSum /= numbers[depth+1];
                break;
        }
        isUsed[i] = true;
        BackTrack(depth+1, nextSum);
        isUsed[i] = false;
    }
}


int main()
{
    cin >> N;
    numbers.assign(N, 0);
    isUsed.assign(N-1, false);
    minNum = INT_MAX;
    maxNum = INT_MIN;
    
    for(int i=0; i<N; i++) {
        cin >> numbers[i];
    }
    
    for(int i=0; i<4; i++) {
        char curChar;
        switch(i) {
            case 0:
                curChar = '+';
                break;
            case 1:
                curChar = '-';
                break;
            case 2:
                curChar = '*';
                break;
            case 3:
                curChar = '/';
                break;
        }
        int num;
        cin >> num;
        for(int j=0; j<num; j++) {
            operation.push_back(curChar);
        }
    }
    
    BackTrack(0, numbers[0]);
    
    cout << maxNum << '\n' << minNum;
}