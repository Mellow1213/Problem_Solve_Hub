#include <iostream>

using namespace std;

inline int cell = 5;

int main()
{
    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N*cell; j++)
            cout << '@';
        cout << '\n';
    }
    
    for(int i=0; i<N*(cell-1); i++){
        for(int j=0; j<N; j++)
            cout << '@';
        cout << '\n';
    }
}
