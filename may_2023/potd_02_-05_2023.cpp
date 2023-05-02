#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int n = nums.size();
        int prod=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) return 0;
            if(nums[i]<0)
            prod++;
        }
        return prod%2 ? -1 : 1;
    }
};