#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> dataset;
vector<int> selection;
vector<bool> visit;

void Backtrack(int depth){
	if(depth >= M){
		for(const auto& p : selection){
			cout << p << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = 0;
	for(int i=0; i<N; i++){
		if(!visit[i] && temp != dataset[i]){ // 이전 데이터와 중복되지 않는다면
			temp = dataset[i]; // 다음 비교를 위해 temp 최신화
			selection[depth] = dataset[i];
			visit[i] = true;
			Backtrack(depth+1);
			visit[i] = false;
		}
	}
}

int main(){	
	cin >> N >> M;
	dataset.resize(N);
	selection.resize(M);
	visit.assign(N, false);

	for(int i=0; i<N; i++){
		cin >> dataset[i];
	}

	sort(dataset.begin(), dataset.end());
	Backtrack(0);
}