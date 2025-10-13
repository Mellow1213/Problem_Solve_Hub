#include <iostream>
#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
int cnt = 0;
bool CheckPalindrome(std::string& str, int left, int right) {
    cnt++;
    if(left >= right) return true;
    else if(str[left] != str[right]) return false;
    else return CheckPalindrome(str, left+1, right-1);
}

int main()
{
    FastIO
    int N;
    std::cin >> N;
    
    std::string inputStr;
    for(int i=0; i<N; i++) {
        std::cin >> inputStr;
        cnt = 0;
        std::cout << CheckPalindrome(inputStr, 0, inputStr.size()-1) << ' ' << cnt << '\n';
    }
}