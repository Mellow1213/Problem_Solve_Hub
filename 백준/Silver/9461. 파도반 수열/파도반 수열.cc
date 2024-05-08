#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    
    cin >> testCase;
    for(int t=0; t<testCase; t++){        
        vector<long long> vec;
        int index;
        cin >> index;
        int fixArr[5] = {0, 1, 1, 1, 2};
        vec.resize(index+1);
        for(int i=0; i<(index+1>5?5:index+1); i++){
            vec[i] = fixArr[i];
        }
        
        for(int i=5; i<=index; i++){
            vec[i] = vec[i-1] + vec[i-5];
        }
        
        cout << vec[index] << '\n';
    }
}
