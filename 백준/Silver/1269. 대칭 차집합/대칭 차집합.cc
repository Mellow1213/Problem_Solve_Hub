#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int sizeA, sizeB;
    int answerCnt = 0;
    unordered_set<int> mySet;
    
    cin >> sizeA >> sizeB;
    int tempNum;
    for(int i=0; i<sizeA; i++) {
        cin >> tempNum;
        mySet.insert(tempNum);
        answerCnt++;
    }
    
    for(int i=0; i<sizeB; i++) {
        cin >> tempNum;
        if(mySet.find(tempNum) == mySet.end()) {
            mySet.insert(tempNum);
            answerCnt++;
        } else {
            mySet.erase(tempNum);
            answerCnt--;
        }
    }
    
    cout << answerCnt;
    
}