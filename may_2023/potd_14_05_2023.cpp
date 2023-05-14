#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution 
{
    public:
    int dp[1<<14];
    int gcd(int num1,int num2)
    {
        if(num2==0) return num1;
        return gcd(num2,num1%num2);
    }
    int dfs(vector<int>& nums,int state,int current)
    {
        if(current==0) return 0;
        if(dp[state]) return dp[state];
        int result=0,n=nums.size();
        
        vector<int> total;
		
		//remaining element
        for(int i=0;i<n;i++)
            if(state&(1<<i))
                total.push_back(i);
				
        
        for(int i=0;i<total.size();i++)
            for(int j=i+1;j<total.size();j++)
                result=max(result,gcd(nums[total[i]],nums[total[j]])*current+dfs(nums,(state&(~((1<<total[i])|(1<<total[j])))),current-1));
        
        dp[state]=result;
        return result;
    }
    int maxScore(vector<int>& nums) 
    {
        memset(dp,0,sizeof(dp));
        return dfs(nums,(1<<14)-1,nums.size()/2);
    }
};