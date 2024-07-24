#include <iostream>
#include <iomanip>

int main()
{
    const double PI = 3.141592653589793;
    double d1, d2;
    std::cin >> d1 >> d2;
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << 2 * (PI * d2 + d1) << std::endl;
    
    return 0;
}