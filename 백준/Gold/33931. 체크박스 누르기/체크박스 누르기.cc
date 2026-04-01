#include <iostream>

using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    
    long long a = M/N;
    long long b = M%N;
    
    long long answer = (a%2 == 0 ? b : N-b);
    cout << answer;
}