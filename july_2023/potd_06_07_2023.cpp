#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX; // minimum length of subarray
        int n = nums.size(); // size of the input array
        int left = 0; // left pointer
        int sum = 0; // current sum of elements in subarray

        for(int right = 0; right < n; right++){
            sum += nums[right]; // include current element in the sum

            // check if the sum exceeds or equals the target
            while(sum >= target){
                sum -= nums[left]; // subtract the leftmost element from the sum
                ans = min(ans, right - left + 1); // update the minimum length
                left++; // move the left pointer to the right
            }
        }

        // if no valid subarray is found, return 0
        if(ans == INT_MAX){
            return 0;
        }

        return ans;
    }
};