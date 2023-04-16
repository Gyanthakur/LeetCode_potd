#include<bits/stdc++.h>
using namespace std;








class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int N = words.size();
        int W = words[0].size();
        int T = target.size();
        vector<vector<int>> freq(W, vector<int>(26, 0));
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < N; j++) {
                int let = words[j][i] - 'a';
                freq[i][let] += 1;
            }
        }
        vector<vector<long long>> dp(T+1, vector<long long>(W+1, 0));
        for (int i = 0; i <= W; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < T; i++) {
            int tar = target[i] - 'a';
            for (int j = 0; j < W; j++) {
                int num = freq[j][tar];
                dp[i+1][j+1] = (dp[i+1][j] + (dp[i][j]*num) % 1000000007) % 1000000007;
            }
        }
        return (int)dp[T][W];
    }
};