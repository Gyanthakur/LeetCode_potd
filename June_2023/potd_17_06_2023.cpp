#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}



class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();

        sort(arr2.begin(), arr2.end());
        vector<int> uniqueArr2;
        for (int i = 0; i < arr2.size(); i++) {
            if (i + 1 < arr2.size() && arr2[i] == arr2[i + 1]) {
                continue;
            }
            uniqueArr2.push_back(arr2[i]);
        }
        arr2 = uniqueArr2;

        vector<int> newArr1(n + 2);
        for (int i = 0; i < n; i++) {
            newArr1[i + 1] = arr1[i];
        }
        newArr1[n + 1] = INT_MAX;
        newArr1[0] = INT_MIN;
        arr1 = newArr1;

        vector<int> dp(n + 2, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n + 2; i++) {
            for (int j = 0; j < i; j++) {
                if (arr1[j] < arr1[i] && dp[j] != INT_MAX) {
                    int change = check(arr1, arr2, j, i);
                    if (change >= 0) {
                        dp[i] = min(dp[i], dp[j] + change);
                    }
                }
            }
        }
        return dp[n + 1] == INT_MAX ? -1 : dp[n + 1];
    }

private:
    int check(const vector<int>& arr1, const vector<int>& arr2, int start, int end) {
        if (start + 1 == end) {
            return 0;
        }
        int minVal = arr1[start];
        int maxVal = arr1[end];
        int idx = upper_bound(arr2.begin(), arr2.end(), minVal) - arr2.begin();
        int maxCount = end - start - 1;
        int endIdx = idx + maxCount - 1;
        if (endIdx < arr2.size() && arr2[endIdx] < maxVal) {
            return maxCount;
        } else {
            return -1;
        }
    }
};