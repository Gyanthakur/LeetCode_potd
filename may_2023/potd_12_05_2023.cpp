#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n + 1, 0);

        
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(jump + i + 1, n);
            long long pointsFromThisQuestion = points + dp[nextQuestion];
            dp[i] = max(pointsFromThisQuestion, dp[i + 1]);
        }

        return dp[0];
    }
};