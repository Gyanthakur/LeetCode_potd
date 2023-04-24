#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> max_heap;
        for (auto stone : stones) {
            max_heap.push(stone);
        }
        while (max_heap.size() != 1) {
            int stone1 = max_heap.top();
            max_heap.pop();
            int stone2 = max_heap.top();
            max_heap.pop();
            max_heap.push(max(stone1, stone2) - min(stone1, stone2));
        }
        return max_heap.top();
    }
};