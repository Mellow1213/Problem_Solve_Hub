#include <iostream>

using namespace std;

long long power(long long A, long long B, long long C){
    if(B == 0)  return 1;
    
    long long temp = power(A, B/2, C); // A^(B/2)로 분할함.
    temp = (temp * temp) % C; // 분할해서 구한 A^(B/2)를 다시 합쳐줌 -> A^8 = A^4 * A^4
    
    if(B%2==0)  return temp;
    else    return (temp * A) % C; // 홀수일 경우 곱셈이 한번 빠짐.
    // eg. A^7 -> 분할 시 A^3 * A^3이 됨. (B/2로 분할하므로)
    // 그래서 마지막에 한번 A를 더 곱해줘서 A^6 * A^1 = A^7로 만들어줌.
}

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    
    cout << power(A, B, C);
}