#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> status(N);
    vector<int> skipvalue;
    skipvalue.reserve(N);
    for (int i = 0; i < N; i++)
    {
        cin >> status[i];
    }
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if(status[i] == 0){
            skipvalue.push_back(temp);
        }
    }
    reverse(skipvalue.begin(), skipvalue.end());
    int e;
    cin >> e;

    int t;
    for(int i=0; i<e; i++){
        cin >> t;
        skipvalue.push_back(t);
    }

    for(int i=0; i<e; i++){
        cout << skipvalue[i] << ' ';
    }
}