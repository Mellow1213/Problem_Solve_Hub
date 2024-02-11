#include <iostream>
#include <string>
using namespace std;


int main()
{
    int N;
    cin >> N;
    
    int searchNum = 666;
    int cnt = 1;
    
    int flag = 0;
    while(cnt < N){
        searchNum += 1;
        
        string target = to_string(searchNum);
        
        for(int i = 0 ; i<target.length()-2; i++)
            if(target[i] == '6' && target[i+1] == '6' && target[i+2] == '6'){
                cnt++;
                break;
            }
    }
    
    cout<<searchNum;
}