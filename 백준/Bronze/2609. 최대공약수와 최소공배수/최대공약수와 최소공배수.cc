#include <iostream>
using namespace std;

int GCD(int a, int b){
    return  a % b ? GCD(b, a % b) : b;
}

int LCD(int a, int b){
    return a * b / GCD(a, b);
}

int main()
{
    int a, b;
    
    cin >> a >> b;
    
    cout<< GCD(a, b) << '\n' << LCD(a, b);
}