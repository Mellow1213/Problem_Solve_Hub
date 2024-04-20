#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second)
    {
        return a.second<b.second;
    }
    else
    {
        return a.first<b.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    vector<pair<int, int>> v;
    
    for(int i=0; i<testCase; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1, temp2));
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}