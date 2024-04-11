#include <iostream>

using namespace std;

int sum(int num)
{
    int returnNum = num;
    
    while(num > 0){
        returnNum += num % 10;
        num /= 10;
    }
    
    return returnNum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    bool flag = false;
    for(int i=0; i<N; i++){
        int temp = sum(i);
        if(temp == N){
            cout << i;
            flag = true;
            break;
        }
    }
    
    if(!flag)
        cout << 0;
}
