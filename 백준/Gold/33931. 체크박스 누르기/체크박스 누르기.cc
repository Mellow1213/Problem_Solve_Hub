#include <iostream>

using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    
    // 누르는 횟수와 버튼 개수를 나눈 몫의 크기만큼 각 버튼은 무조건 눌림
    // 이후 나머지의 개수만큼 임의의 버튼들이 추가로 한번 더 눌림
    // M = a*N + b
    long long a = M/N;
    long long b = M%N;

    // a가 짝수면 모든 버튼이 꺼져있는 상태, 홀수면 모든 버튼이 켜져있는 상태
    // 해당 경우에 따라 b가 버튼을 켜는 동작, 끄는 동작임이 나누어지므로 구분하여 계산 
    long long answer = (a%2 == 0 ? b : N-b);
    cout << answer;
}
