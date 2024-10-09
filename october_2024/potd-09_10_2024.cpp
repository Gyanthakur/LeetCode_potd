/*
Minimum Add to Make Parentheses Valid
Solved
Medium
Topics
Companies
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3

Constraints:
1 <= s.length <= 1000
s[i] is either '(' or ')'.

*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves=0,open=0;
        for(char ch:s)
        {
            if(ch=='(')
            //increase count of open brackets
            open++;
            else
            // if its a close brackey
            {
                if(open!=0)
                // if open exists then reduce its count 
                open--;
                else
                // no open brackets there to match close so increase moves
                moves++;
            }
        }
        //add open count to total moves as these open brackets remain in the end without a close
        moves+=open;
        return moves;
    }
};