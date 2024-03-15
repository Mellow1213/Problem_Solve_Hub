#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int num = 0;
    for(int i = 0 ; i < N ; i++){
        int temp;
        cin >> temp;
        
        if(temp == 1)   continue;
        
        int flag = 1;
        
        for(int i = 2 ; i < temp-1 ; i++){
            if(temp % i == 0){
                flag = 0;
                break;
            }
        }
        
        num += flag;
    }
    
    cout << num;
}