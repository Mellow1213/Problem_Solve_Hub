#include <iostream>
#include <vector>
#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
using namespace std;
void Recurv(vector<bool>& arr, int left, int right) {
    if(left >= right) return;
    
    int length = right - left + 1;
    int third = length / 3;
    for(int i = left+third; i<left+2*third; i++) {
        arr[i] = false;
    }
    Recurv(arr, left, left+third-1);
    Recurv(arr, left+2*third, right);
}

int main() {
    FastIO
    int N;
    while(std::cin >> N){
        int originLength = 1;
        for(int i=0; i<N; i++) {
            originLength *= 3;
        }
        std::vector<bool> arr(originLength, true);
        Recurv(arr, 0, arr.size()-1);
        for(const auto& p : arr) {
            cout << (p ? '-' : ' ');
        }
        cout << '\n';
        
    }
}