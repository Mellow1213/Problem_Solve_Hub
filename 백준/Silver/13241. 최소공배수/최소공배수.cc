#include <iostream>

using namespace std;

int main()
{
    long long int A, B;
    long long int temp;
    long long int answer;
    
    cin>>A>>B;
    
    answer = A*B;
    
    while (B!=0){
        temp = A % B;
        A = B;
        B = temp;
    }
    
    answer /= A;
    
    cout<<answer;
}