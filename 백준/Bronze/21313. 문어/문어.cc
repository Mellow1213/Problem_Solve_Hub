#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        cout << (i%2==0 ? 1 : 2) << ' ';
    }
    cout << (N%2==0 ? 2 : 3);
}