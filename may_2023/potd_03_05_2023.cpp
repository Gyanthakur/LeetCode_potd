#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> ans =  {{},{}};
		
		// Create set with elements of the vector
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        
		// For every element in set A that is not present in set B
		// Add it to the answer, do this for both set
        for(auto x : s1) if(!s2.count(x)) ans[0].push_back(x);
        for(auto x : s2) if(!s1.count(x)) ans[1].push_back(x);
		
        return ans;
    }
};