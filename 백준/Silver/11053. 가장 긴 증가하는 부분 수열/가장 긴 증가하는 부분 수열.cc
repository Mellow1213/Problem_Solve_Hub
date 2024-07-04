#include <iostream>
#include <vector>

using namespace std;

vector<int> list;

int BinarySearch(int target) {
    int left = 0, right = list.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (list[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sequence(n);
    
    for(int i=0; i<n; i++){
        cin >> sequence[i];
    }
    
    for(int i=0; i<n; i++){
        int idx = BinarySearch(sequence[i]);
        if(idx == list.size()){
            list.push_back(sequence[i]);
        }
        else{
            list[idx] = sequence[i];
        }
    }
    
    cout << list.size();
}