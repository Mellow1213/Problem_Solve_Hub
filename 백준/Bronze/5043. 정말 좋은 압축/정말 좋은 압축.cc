#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;
    long long b;

    cin >> N >> b;

    long long sum = 1; 
    for (int i = 1; i <= b; i++)
        sum += (1LL << i);
    
    cout << (sum >= N ? "yes\n" : "no\n");
}