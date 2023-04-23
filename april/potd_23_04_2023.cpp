#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<long long> v(n + 1, 0);
        v[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                continue;
            }
            long long number = 0;
            int j = i;
            while (j < n) {
                try {
                    int x = stoi(s.substr(i, j-i+1));
                    if (x > k) {
                        break;
                    }
                    number += v[j+1];
                }
                catch (std::out_of_range& e) {
                    break;
                }
                j++;
            }
            v[i] = number % 1000000007;
        }
        
        return v[0];
    }
};
