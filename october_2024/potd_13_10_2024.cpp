//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 
#include <bits/stdc++.h>

using namespace std;

struct Element {
    int value; // value of the element
    int listIndex; // index of the list from which the element is taken
    int elementIndex; // index of the element in its list

    // Define a comparison operator for the priority queue
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap; // min-heap
    int maxVal = numeric_limits<int>::min(); // to track the max value in the range
    int rangeStart = 0, rangeEnd = numeric_limits<int>::max();

    // Initialize the min-heap with the first element of each list
    for (int i = 0; i < nums.size(); ++i) {
        minHeap.push({nums[i][0], i, 0});
        maxVal = max(maxVal, nums[i][0]);
    }

    while (minHeap.size() == nums.size()) {
        auto current = minHeap.top();
        minHeap.pop();

        int minVal = current.value;

        // Check if the current range is smaller than the best range found so far
        if (maxVal - minVal < rangeEnd - rangeStart || 
            (maxVal - minVal == rangeEnd - rangeStart && minVal < rangeStart)) {
            rangeStart = minVal;
            rangeEnd = maxVal;
        }

        // If we can push the next element from the same list, do it
        if (current.elementIndex + 1 < nums[current.listIndex].size()) {
            int nextValue = nums[current.listIndex][current.elementIndex + 1];
            minHeap.push({nextValue, current.listIndex, current.elementIndex + 1});
            maxVal = max(maxVal, nextValue); // Update the maxVal
        }
    }

    return {rangeStart, rangeEnd};
}

int main() {
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> result = smallestRange(nums);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [20, 24]

    return 0;
}
