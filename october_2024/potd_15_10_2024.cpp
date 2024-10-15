// Traversal: We traverse the string from right to left. For every '1' encountered, we add the number of '0's seen so far (in count) to the total ans because each '1' has to move past those '0's.

class Solution {
public:
    // Function to calculate the minimum number of steps required
    // based on the string 's' containing '0's and '1's.
    long long minimumSteps(string s) 
    {
        long long ans = 0;  // Variable to store the final answer (minimum steps).
        
        // If the string is empty or has only one character, no steps are needed.
        if(s.length() == 0 || s.length() == 1)
            return 0;
        
        int r = s.length() - 1;  // Set 'r' to the index of the last character in the string.
        long long count = 0LL;   // 'count' keeps track of the number of '0's encountered.
        
        // Traverse the string from the last character to the first.
        while(r >= 0)
        {
            // If the current character is '1', we add the current count of '0's to 'ans'.
            // This is because each '1' should move past all the '0's seen so far.
            if(s[r] == '1')
                ans += count;
            else
                // If the current character is '0', increment the 'count' of '0's.
                count += 1LL;
            
            r--;  // Move to the previous character in the string.
        }
        
        // Return the total number of steps (ans).
        return ans;
    }
};

// Main function to test the minimumSteps function
int main() {
    Solution solution;

    // Example input string
    string s = "1010010001";

    // Call the function and store the result
    long long result = solution.minimumSteps(s);

    // Output the result
    cout << "Minimum number of steps required: " << result << endl;  // Output should be 5

    return 0;
}

// Expected Output : Minimum number of steps required: 14
