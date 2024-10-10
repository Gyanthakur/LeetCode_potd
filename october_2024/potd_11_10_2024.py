Longest Substring Without Repeating Characters
Problem Statement
Given a string s, find the length of the longest substring without repeating characters.

Examples
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Constraints
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols, and spaces.

  Solution
The solution employs a sliding window technique to track the longest substring without repeating characters.
def length_of_longest_substring(s: str) -> int:
    char_set = set()
    left = 0
    max_length = 0
    
    for right in range(len(s)):
        while s[right] in char_set:
            char_set.remove(s[left])
            left += 1
        char_set.add(s[right])
        max_length = max(max_length, right - left + 1)
    
    return max_length
