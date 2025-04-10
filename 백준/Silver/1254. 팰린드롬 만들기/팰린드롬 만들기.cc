#include <iostream>

using namespace std;

bool IsPalindrome(const string& s, int start) {
    int left = start;
    int right = s.size() -1;
    
    while(left < right) {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    
    return true;
}

int main()
{
    string str;
    cin >> str;
    
    int answer = str.size();
    for(int i=0; i<str.size(); i++) {
        if(IsPalindrome(str, i)) {
            answer += i;
            break;
        }
    }
    
    cout << answer;
}