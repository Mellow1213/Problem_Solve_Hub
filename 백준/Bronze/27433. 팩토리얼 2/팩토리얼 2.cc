#include <iostream>

long long int Factorial(long long int num) {
    if(num == 0) return 1;
    return Factorial(num-1) * num;
}

int main()
{
    int N;
    std::cin >> N;
    std::cout << Factorial(N);
}