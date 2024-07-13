#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int temp;
        string output = "";
        cin >> temp;
        
        cout << "Case #" << i+1 << ": ";
        if(temp > 4500){
            cout << "Round 1\n";
        }
        else if(temp <= 4500 && temp > 1000){
            cout << "Round 2\n";
            
        }
        else if(temp <= 1000 && temp > 25){
            cout << "Round 3\n";
            
        }
        else{
            cout << "World Finals\n";
            
        }
    }
    
}