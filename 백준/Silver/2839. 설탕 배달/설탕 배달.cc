#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int leastCnt = -1;
    
    int cnt = N/5+1;
    int flag = -1;
    
    for(int i=0; i<cnt; i++){
        int temp = N-5*i;
        if(temp%3 == 0){
            if(leastCnt != -1)
                leastCnt = leastCnt > i+temp/3 ? i+temp/3 : leastCnt;
            else
                leastCnt = i+temp/3;
        }
    }
    
    cout << leastCnt;
}