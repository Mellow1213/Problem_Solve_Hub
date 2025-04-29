#include <iostream>
#include <cmath>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        long long x, y;
        std::cin >> x >> y;
        long long distance = y - x;
        long long n = std::sqrt(distance);
        if (distance == n * n) {
            std::cout << 2 * n - 1 << "\n";
        } else if (distance <= n * n + n) {
            std::cout << 2 * n << "\n";
        } else {
            std::cout << 2 * n + 1 << "\n";
        }
    }
    return 0;
}
