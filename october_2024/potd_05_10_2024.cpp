// Below is the question for finding the container with most water.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// optimal approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right = height.size()-1;
        int area = 0;
        while(left<right){
            int width = right-left;
            int h = min(height[left], height[right]);
            int curr = width*h;
            area = max(area, curr);
            if(height[left]<height[right]? left++ : right--);
        }
        return area;
        
    }
};
// Brute force approach

int maxContainer(vector<int> &height){
int ans = 0;
for(int i=0; i<height.size(); i++){
    for(int j = i+1; j<height.size(); j++){
        int width = j-1;
        int h = min(height[i], height[j]);
        int curr = width * h;
        ans = max(ans,curr);
    }
}
    return ans;

}
int main(){
vector<int>v = {1,8,6,2,5,4,8,3,7};
Solution s;
cout<<s.maxArea(v)<<endl;
cout<<maxContainer(v)<<endl;
}