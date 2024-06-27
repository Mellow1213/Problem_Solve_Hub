#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=N; j>0; j--){
            cout << (j<=i+1 ? '*' : ' ');
        }
        cout << '\n';
    }
}