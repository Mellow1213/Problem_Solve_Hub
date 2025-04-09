#include <iostream>
#include <string>

using namespace std;

void PrintStr(const string& str) {
    cout << str;
}

int main(void) {
    string str;
    cin >> str;
    PrintStr(str);
    return 0;
}