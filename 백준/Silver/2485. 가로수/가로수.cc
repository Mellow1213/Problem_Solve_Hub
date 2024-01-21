#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void calculateIntervals(int trees[], int intervals[], int n) {
    for (int i = 0; i < n - 1; i++) {
        intervals[i] = trees[i + 1] - trees[i];
    }
}

int findGCDOfIntervals(int intervals[], int n) {
    int result = intervals[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, intervals[i]);
    }
    return result;
}

int countAdditionalTrees(int intervals[], int n, int gcd) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += (intervals[i] / gcd) - 1;
    }
    return count;
}

int main() {
    int numCnt;
    cin >> numCnt;

    int trees[numCnt];
    for (int i = 0; i < numCnt; i++) {
        cin >> trees[i];
    }

    int intervals[numCnt - 1];
    calculateIntervals(trees, intervals, numCnt);

    int gcdValue = findGCDOfIntervals(intervals, numCnt - 1);

    cout << countAdditionalTrees(intervals, numCnt - 1, gcdValue);

    return 0;
}
