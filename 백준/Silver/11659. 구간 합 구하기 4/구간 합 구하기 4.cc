#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    int numAmount;
    vector<int> nums;
    
    cin >> numAmount >> testCase;
    
    nums.push_back(0);
    for(int i=1; i<=numAmount; i++){
        int temp;
        cin >> temp;
        nums.push_back((temp+nums[i-1]));
    }
    
    for(int t=0; t<testCase; t++){
        int i; int j;
        cin >> i >> j;
        cout << nums[j] - nums[i-1] << '\n';
    }
}
