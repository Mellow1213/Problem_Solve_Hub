#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int treeAmount;
    long long needTree;
    long long max = 0;
    
    cin >> treeAmount >> needTree;
    
    vector<int> tree(treeAmount);
    
    for(int i=0; i<tree.size(); i++){
        cin >> tree[i];
    }
    
    sort(tree.begin(), tree.end());
    
    long long low = 0;
    long long high = tree[treeAmount - 1];
    
    while(low <= high){ //cut 가능할 때 까지
        long long sum = 0;
        long long cut = (low + high) / 2;
        
        for(int i = 0; i < treeAmount; i++) {
            if(tree[i] - cut > 0) sum += tree[i] - cut; // cut 하고 남는 게 있다면 가져감
        }
        
        if(sum >= needTree){ // m미터보다 가져간 나무가 같거나 많으면
            max = cut; // 현재 cut 지점을 최대 지점으로 저장
            low = cut + 1; // cut 가능 구간을 더 올림
        } else{
            high = cut - 1; // m미터가 안 되면 cut 가능 구간을 내림
        }
    }
    
    cout << max; // 최대 cut 지점 출력
    
    return 0;
}
