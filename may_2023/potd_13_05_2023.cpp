#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i <= high; i++) {
            
            int num_valid_strings_ending_with_zero = dp.count(i - zero) ? dp[i - zero] : 0;
            
            
            int num_valid_strings_ending_with_one = dp.count(i - one) ? dp[i - one] : 0;
            
            
            int num_valid_strings_of_length_i = (num_valid_strings_ending_with_zero + num_valid_strings_ending_with_one) % mod;
            
            
            dp[i] = num_valid_strings_of_length_i;
        }
        
        
        int total_num_valid_strings = 0;
        for (int i = low; i <= high; i++) {
            total_num_valid_strings = (total_num_valid_strings + (dp.count(i) ? dp[i] : 0)) % mod;
        }
        return total_num_valid_strings;
    }
};