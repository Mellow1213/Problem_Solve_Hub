#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    string S;
    string currentStr;
    unordered_set<string> us;
    
    cin >> S;
    
    for(int ln = 1; ln <= S.length(); ln++) {
        for(int i=0; i<S.length()-ln+1; i++) {
            currentStr = S.substr(i, ln);
            us.insert(currentStr);
        }
    }
    
    cout << us.size();
}