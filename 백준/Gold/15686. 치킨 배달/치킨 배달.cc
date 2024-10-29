#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int,int>> house;    // 집 좌표
vector<pair<int,int>> chicken;  // 치킨집 좌표
vector<pair<int,int>> selected; // 선택된 치킨집
int answer = 987654321;

// 두 좌표 사이의 거리 계산
int getDistance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// idx: 현재 보고 있는 치킨집 인덱스
// cnt: 현재까지 선택한 치킨집 개수
void combination(int idx, int cnt) {
    // M개를 모두 선택했으면
    if(cnt == M) {
        int total_dist = 0;
        // 각 집에서
        for(auto& h : house) {
            int min_dist = 987654321;
            // 선택된 치킨집들과의 거리 중 최소값
            for(auto& s : selected) {
                min_dist = min(min_dist, getDistance(h, s));
            }
            total_dist += min_dist;
        }
        answer = min(answer, total_dist);
        return;
    }
    
    // 남은 치킨집들 중에서 하나를 선택
    for(int i = idx; i < chicken.size(); i++) {
        selected.push_back(chicken[i]);     // 선택
        combination(i + 1, cnt + 1);        // 다음 치킨집 선택하러
        selected.pop_back();                // 선택 취소
    }
}

int main() {
    cin >> N >> M;
    
    // 입력 받기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if(x == 1) house.push_back({i, j});
            else if(x == 2) chicken.push_back({i, j});
        }
    }
    
    combination(0, 0);  // 치킨집 조합 만들기
    cout << answer;
    return 0;
}