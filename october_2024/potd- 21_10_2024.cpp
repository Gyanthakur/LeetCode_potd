class Solution {
public:
    // Main function to find the maximum number of unique substrings
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;  // Set to store unique substrings
        int maxCount = 0;  // Variable to store the maximum count of unique substrings
        
        // Call the backtracking function to find the maximum count
        backtrack(s, 0, seen, 0, maxCount);
        
        return maxCount;  // Return the final result
    }

private:
    // Backtracking function to explore all possible splits
    void backtrack(const string& s, int start, unordered_set<string>& seen,
                   int count, int& maxCount) {
        // Pruning: If the remaining characters plus current count can't exceed maxCount, return
        if (count + (s.size() - start) <= maxCount) return;

        // Base case: If we've reached the end of the string
        if (start == s.size()) {
            maxCount = max(maxCount, count);  // Update maxCount if necessary
            return;
        }

        // Try all possible substrings starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);  // Extract substring
            
            // If the substring is not in the set (i.e., it's unique)
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);  // Add the substring to the set
                
                // Recursively call backtrack with updated parameters
                backtrack(s, end, seen, count + 1, maxCount);
                
                seen.erase(substring);  // Remove the substring from the set (backtracking)
            }
        }
    }
};
