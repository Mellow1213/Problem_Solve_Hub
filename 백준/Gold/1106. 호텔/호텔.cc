#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int main()
{
    int C, N;
    cin >> C >> N;
    
    vector<pair<int, int>> vec(N);
    
    // dp 배열의 크기를 C + 100으로 설정하여 충분히 큰 크기로 초기화
    vector<int> dp(C + 101, INF);
    
    for(int i = 0; i < N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vec[i] = make_pair(temp1, temp2);
    }
    
    dp[0] = 0;
    
    // 각 도시마다 고객 수와 비용을 이용하여 dp 배열 갱신
    for(int i = 0; i <= C + 100; i++){
        for(const auto& city : vec){
            int cost = city.first;
            int customer = city.second;
            if(i - customer >= 0){
                dp[i] = min(dp[i], dp[i - customer] + cost);
            }
        }
    }
    
    // 목표 고객 수 이상 중 최소 비용 찾기
    int result = INF;
    for(int i = C; i <= C + 100; ++i){
        result = min(result, dp[i]);
    }
    
    cout << result << endl;
    
    return 0;
}
