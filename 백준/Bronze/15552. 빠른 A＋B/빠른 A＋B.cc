#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    
    int cnt;
    cin>>cnt;
    
    int a;
    int b;
    for(int i = 0; i<cnt; i++)
    {
        cin>>a>>b;
        cout<<(a+b);
        cout<<"\n";
    }
    return 0;
}