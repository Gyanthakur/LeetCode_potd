#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        std::vector<std::string> ranges;
        int start = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    ranges.push_back(std::to_string(start));
                } else {
                    ranges.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
                }
                start = nums[i];
            }
        }

        // Handle the last range
        if (start == nums.back()) {
            ranges.push_back(std::to_string(start));
        } else {
            ranges.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
        }

        return ranges;
    }
};