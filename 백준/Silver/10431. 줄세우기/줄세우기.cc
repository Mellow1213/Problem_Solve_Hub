#include <iostream>
#include <vector>
using namespace std;

int InsertSort(vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int curElement = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > curElement)
            {
                arr[j + 1] = arr[j];
                cnt++;
            }
            else
                break;
        }
        arr[j + 1] = curElement;  // break 했거나 j가 -1이 된 경우 모두 처리
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int p;
    cin >> p;

    for (int t = 1; t <= p; t++)
    {
        int testCase;
        vector<int> vec(20);

        cin >> testCase;
        for (int i = 0; i < 20; i++)
        {
            cin >> vec[i];
        }

        cout << testCase << ' ' << InsertSort(vec) << '\n';
    }
}