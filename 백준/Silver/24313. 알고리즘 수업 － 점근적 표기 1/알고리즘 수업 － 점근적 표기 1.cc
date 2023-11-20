#include <iostream>

using namespace std;

int BigO(int fn1, int fn2, int c, int n0){
    
    return  fn1*n0 + fn2 <= c*n0 && fn1 <= c;
}

int main()
{
    int fn1, fn2;
    int c;
    int n0;
    
    cin >> fn1 >> fn2;
    cin >> c;
    cin >> n0;
    
    cout << BigO(fn1, fn2, c, n0);
}