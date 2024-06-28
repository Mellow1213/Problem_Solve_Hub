#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    int cnt = 0;
    string temp;
    getline(cin, temp);
    vector<int> result;
    stringstream ss(temp);
    string nums;
    while(getline(ss, nums, ' '))
        result.push_back(stoi(nums));
    
    
    for(const auto& p : result){
        if(p > 0)
            cnt++;
    }
    
    cout << cnt;
}