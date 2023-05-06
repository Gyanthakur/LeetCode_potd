#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), left = 0, right = n - 1, mod = 1e9 + 7;
        vector<int> pows(n);
        pows[0] = 1;
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                res = (res + pows[right - left++]) % mod;
            }
        }
        return res;
    }
};