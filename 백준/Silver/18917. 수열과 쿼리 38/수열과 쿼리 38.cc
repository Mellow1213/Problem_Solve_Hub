#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    long long sum = 0; 
    int xr = 0;
    int query;
    int x;
    
    for(int i=0; i<t; i++){
        cin >> query;
        
        switch(query){
            case 1:
            {
                cin >> x;
                sum += x;
                xr ^= x;
                break;
                
            }
            case 2:
            {
                cin >> x;
                sum -= x;
                xr ^= x;
                break;
            }
            case 3:
            {
                cout << sum << '\n';
                break;
            }
            case 4:
            {
                cout << xr << '\n';   
                break;
            }
        }
    }
}