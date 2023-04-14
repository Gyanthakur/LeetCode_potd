#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s1.begin(),s1.end());
        int n = s1.length(),i,j;
        vector<vector<int>> dp(n+1,vector<int> (n+2,0));
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};