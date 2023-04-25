#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

#include <queue>
#include <unordered_set>

class SmallestInfiniteSet {
private:
    int min_num = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    std::unordered_set<int> nums;

public:
    int popSmallest() {
        if (!heap.empty()) {
            int smallest = heap.top();
            heap.pop();
            nums.erase(smallest);
            return smallest;
        }
        min_num++;
        return min_num - 1;
    }

    void addBack(int num) {
        if (min_num > num && nums.find(num) == nums.end()) {
            heap.push(num);
            nums.insert(num);
        }
    }
};