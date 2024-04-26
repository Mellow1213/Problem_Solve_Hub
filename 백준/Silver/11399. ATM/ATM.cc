#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main()
{
    vector<pair<int, int>> vec;
    int N;
    int sum = 0;
    int realTime = 0;
    
    cin >> N;
    
    int temp;
    for(int i=1; i<=N; i++){
        cin >> temp;
        vec.push_back(make_pair(i, temp));
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for(int i=0; i<vec.size(); i++){
        realTime += vec[i].second;
        sum += realTime;
    }
    
    cout << sum;
}