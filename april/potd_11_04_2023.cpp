#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        deque<char> f;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
               f.pop_back();
            }
            else
                f.push_back(s[i]);
        }
        string p;
        while(!f.empty())
        {
            p.push_back(f.front());
            f.pop_front();
        }
        return p;
    }
};