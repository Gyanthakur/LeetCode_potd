#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;

        long long windowSum = 0;
        std::vector<int> result(n, -1);

        if (n < windowSize) {
            return result;
        }

        for (int i = 0; i < n; ++i) {
            windowSum += nums[i];

            if (i - windowSize >= 0) {
                windowSum -= nums[i - windowSize];
            }

            if (i >= windowSize - 1) {
                result[i - k] = static_cast<int>(windowSum / windowSize);
            }
        }

        return result;
    }
};
