#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


#define vi vector<int>

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vi v(obstacles.size()+1, INT_MAX), ans;

        for(auto it : obstacles)   {
            int ind = upper_bound(v.begin(), v.end(), it) - v.begin();
            v[ind] = it;
            ans.push_back(ind+1);
        }

        return ans; 
    }
};