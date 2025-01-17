#include <iostream>
#include <vector>

using namespace std;

int N, K;
int cnt = 0;
int result = -1;

void merge(vector<int>& vec, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    vector<int> temp(right - left + 1);
    
    while(i <= mid && j <= right) {
        if(vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }
    
    while(i <= mid) temp[k++] = vec[i++];
    while(j <= right) temp[k++] = vec[j++];
    
    for(i = left, k=0; i<=right; ++i, ++k) {
        vec[i] = temp[k];
        cnt++;
        if(cnt == K)
            result = vec[i];
    }
}

void mergeSort(vector<int>& vec, int left, int right) {
	if(left < right) {
		int mid = (left + right) / 2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid+1, right);
		merge(vec, left, mid, right);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
	cin >> N >> K;
	vector<int> arr(N);

	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}
	
	mergeSort(arr, 0, N-1);

    cout << result << '\n';
}