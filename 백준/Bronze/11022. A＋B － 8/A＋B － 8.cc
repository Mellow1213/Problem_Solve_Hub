#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num1, num2;
        cin >> num1 >> num2;
        cout << "Case #" << i+1 << ": " << num1 << " + " << num2 << " = " << num1+num2 << '\n'; 
    }
}