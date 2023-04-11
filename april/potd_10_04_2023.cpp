#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            st.push(s[i]);
            else if((s[i]== ')' && st.top()== '(' )|| (s[i]== '}' && st.top()== '{')||(s[i]== ']' && st.top()== '['))
            st.pop();
            else
            st.push(s[i]);
        }
        if(st.empty())
        return 1;
        else
        return 0;
    }
};