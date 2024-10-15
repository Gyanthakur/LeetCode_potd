/*
Example 1:
Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
Output: 3
Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].

Example 2:
Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
Output: 1
Explanation: Subarray with sum 33 is: [20,3,10].

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int>& arr, int tar) {
    // Hash map to store the cumulative sum frequencies
    unordered_map<int, int> sum_map;
    int current_sum = 0;
    int count = 0;
    
    // Initialize sum_map with sum 0 seen once (base case)
    sum_map[0] = 1;
    
    for (int num : arr) {
        // Update the cumulative sum
        current_sum += num;
        
        // Check if there's a subarray (ending here) whose sum is target
        if (sum_map.find(current_sum - tar) != sum_map.end()) {
            count += sum_map[current_sum - tar];
        }
        
        // Add the current cumulative sum to the map
        sum_map[current_sum]++;
    }
    
    return count;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int tar = -10;
    
    int result = subarraySum(arr, tar);
    cout << "Number of subarrays with sum " << tar << ": " << result << endl;  // Output: 3
    
    return 0;
}

