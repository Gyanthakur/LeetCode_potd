#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // Sort in descending order of frequency
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        
        for (const auto& entry : counter) {
            heap.push(entry);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top().first);
            heap.pop();
        }
        
        return result;
    }
};