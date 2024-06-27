#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string temp;
    vector<int> vec(5);
    int sum = 0;
    for(int i=0; i<5; i++){
        cin >> vec[i];
        sum += vec[i]*vec[i];
    }
    cout << sum%10;
}