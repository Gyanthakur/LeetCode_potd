#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) {
        std::unordered_set<int> destinations;
        
        for (const std::vector<int>& edge : edges) {
            destinations.insert(edge[1]);
        }
        
        std::vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (destinations.find(i) == destinations.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};