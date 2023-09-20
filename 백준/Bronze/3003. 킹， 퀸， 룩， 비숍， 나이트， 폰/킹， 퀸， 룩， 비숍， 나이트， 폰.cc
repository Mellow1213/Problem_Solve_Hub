#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    
    int cnt[6];
    int answer[6] = {1, 1, 2, 2, 2, 8};
     
    int a;
    int b;
    for(int i = 0; i<6; i++)
    {
        cin>>cnt[i];
    }
    for(int i = 0; i<6; i++)
    {
        cout<<(answer[i]-cnt[i])<<" ";
    }
    return 0;
}