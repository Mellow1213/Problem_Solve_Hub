#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int sum = 0;
    
    string inputNum;
    getline(cin, inputNum);
    vector<int> result;
    stringstream ss(inputNum);
    string temp;
    
    while(getline(ss, temp, ' '))
        result.push_back(stoi(temp));
    
    for(const auto& p : result)
    {
        sum += p;
    }
    
    cout << sum;
    
}