#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CheckValidity(vector<int> &house, int C, int length)
{
    int cnt = 1;
    int last_pos = house[0];
    for (int i = 0; i < house.size(); i++)
    {
        if(house[i] >= last_pos + length) {
            cnt++;
            last_pos = house[i];
            if(cnt == C)
                return true;
        }
    }
    return false;
}

int main()
{
    int N, C;
    cin >> N >> C;
    vector<int> house(N);

    for (int i = 0; i < N; i++)
    {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    int low = 1;
    int high = house[N - 1] - house[0];
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (CheckValidity(house, C, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << high;
}