#include <iostream>

int Fibonacci(int num) {
    if(num == 1) {
        return 1;
    } else if (num == 0) {
        return 0;
    } else {
        return Fibonacci(num-1) + Fibonacci(num-2);
    }
}

int main()
{
    int inputNumber;
    
    std::cin >> inputNumber;
    std::cout << Fibonacci(inputNumber);
    
}