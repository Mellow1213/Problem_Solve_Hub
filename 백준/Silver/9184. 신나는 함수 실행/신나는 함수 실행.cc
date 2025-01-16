/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int dp[21][21][21];
int w(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if(a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if(dp[a][b][c] != 0)    return dp[a][b][c];
    
    if(a < b && b < c) {
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else {
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return dp[a][b][c];
}

const void Print (int n1, int n2, int n3) {
    cout << "w(" << n1 << ", " << n2 << ", " << n3 << ") = " << w(n1, n2, n3) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n1, n2, n3;
    while(1) {
        cin >> n1 >> n2 >> n3;
        if(n1 == -1 && n2 == -1 && n3 == -1)    break;
        Print(n1, n2, n3);
    }
}