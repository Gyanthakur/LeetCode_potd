// 2696.  Minimum String Length After Removing Substrings

/*
Problem Description:
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

 

Example 1:

Input: s = "ABFCACDB"
Output: 2
Explanation: We can do the following operations:
- Remove the substring "ABFCACDB", so s = "FCACDB".
- Remove the substring "FCACDB", so s = "FCAB".
- Remove the substring "FCAB", so s = "FC".
So the resulting length of the string is 2.
It can be shown that it is the minimum length that we can obtain.

Example 2:

Input: s = "ACBBD"
Output: 5
Explanation: We cannot do any operations on the string so the length remains the same.
*/


// Solution:


class Solution {
public:
    int minLength(string s) {
        stack<char> st;               // Initialize an empty stack to store characters
        int n = s.size();              // Store the length of the string
        
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            if (!st.empty() && 
                ((st.top() == 'A' && curr == 'B') || st.top() == 'C' && curr == 'D')) {
                st.pop();              // Remove the top character if a valid pair is found
            } else {
                st.push(curr);         // Push the current character onto the stack if no pair is formed
            }
        }
        return st.size();              // Return the size of the stack, which gives the remaining unpaired characters
    }
};

