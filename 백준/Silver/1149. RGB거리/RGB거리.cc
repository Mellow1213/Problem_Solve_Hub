#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct House{
	char currentColor = 'X';
	int redCost;
	int greenCost;
	int blueCost;
};

vector<House> arr;

void Solve(){
    int costSum = 0;
    
    int R = arr[0].redCost;
    int G = arr[0].greenCost;
    int B = arr[0].blueCost;
    vector<int> DP_R(arr.size());
    vector<int> DP_G(arr.size());
    vector<int> DP_B(arr.size());
    DP_R[0] = R;
    DP_G[0] = G;
    DP_B[0] = B;
    
    for(int i=1; i<= arr.size()-1; i++){
        DP_R[i] = arr[i].redCost + min(DP_G[i-1], DP_B[i-1]);
        DP_G[i] = arr[i].greenCost + min(DP_R[i-1], DP_B[i-1]);
        DP_B[i] = arr[i].blueCost + min(DP_G[i-1], DP_R[i-1]);
    }
    
    cout << min({DP_R[arr.size()-1], DP_G[arr.size()-1], DP_B[arr.size()-1]});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int houseAmount;
    cin >> houseAmount;
    
    
    for(int i=0; i<houseAmount; i++){
        House house;
        cin >> house.redCost >> house.greenCost >> house.blueCost;
        arr.push_back(house);
    }
    
    Solve();
}