#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int a = M/N;
    int b = M%N;
    
    int answer = (a%2 == 0 ? b : N-b);
    cout << answer;
}