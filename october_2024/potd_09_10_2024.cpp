/*  
Problem Description:
A parentheses string is considered valid if it meets one of the following conditions:

It is an empty string.
It can be written as a concatenation of two valid strings, i.e., AB, where both A and B are valid.
It can be written as (A), where A is a valid string.

Example 1:
Input:
s = "())"

Output:
1

Explanation:
One move is required to insert an opening parenthesis at the beginning or at the second position to balance the string.

Example 2:
Input:
s = "((("

Output:
3

Explanation:
Three closing parentheses are required to balance the string.

Constraints:
1 ≤ s.length ≤ 1000
The string s contains only the characters '(' and ')'.
*/

//--------------Solution-------------------------------

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // To track unmatched opening parentheses '('
        int close = 0; // To track unmatched closing parentheses ')'
        
        for (char c : s) {
            if (c == '(') {
                open++;  // Every opening parenthesis needs a corresponding closing one
            } else {
                if (open > 0) {
                    open--;  // Match an open parenthesis with this closing one
                } else {
                    close++; // No open parenthesis to match, so we need an extra '('
                }
            }
        }
        
        // Total unmatched parentheses will be the result
        return open + close;
    }
};
