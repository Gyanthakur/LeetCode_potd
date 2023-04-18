#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0;
        int j = 0;
        int k = 0;
        while(i != word1.length() && j != word2.length()) {
            if(k % 2 == 0) {
                res += word1[i++];
                k++;
            } else {
                res += word2[j++];
                k++;
            }
        }
        while(i != word1.length()) {
            res += word1[i++];
        }
        while(j != word2.length()) {
            res += word2[j++];
        }
        return res;
    }
};