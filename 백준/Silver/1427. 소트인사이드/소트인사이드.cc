#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    vector<char> vec;
    cin >> str;
    vec.reserve(str.size());
    
    for(const auto& p : str) {
        vec.push_back(p);
    }
    
    sort(vec.begin(), vec.end(), greater<char>());
    
    for(const auto& p : vec) {
        cout << p;
    }
}