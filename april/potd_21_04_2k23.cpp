#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1000000007;
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = minProfit; i >= 0; i--) {
                for (int j = n - g; j >= 0; j--) {
                    int newProfit = min(i + p, minProfit);
                    dp[newProfit][j + g] += dp[i][j];
                    dp[newProfit][j + g] %= MOD;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += dp[minProfit][i];
            sum %= MOD;
        }
        return sum;
    }
};