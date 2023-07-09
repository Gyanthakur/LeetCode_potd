#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
public:
    int largestVariance(string s) {
        int count1 = 0;
        int count2 = 0;
        int max_variance = 0;

        // Create a distinct set of character pairs
        unordered_set<char> distinct_chars(s.begin(), s.end());

        // Run once for original string order, then again for reverse string order
        for (int runs = 0; runs < 2; runs++) {
            for (char l1 : distinct_chars) {
                for (char l2 : distinct_chars) {
                    if (l1 == l2) {
                        continue;
                    }
                    count1 = count2 = 0;
                    for (char letter : s) {
                        if (letter == l1) {
                            count1++;
                        } else if (letter == l2) {
                            count2++;
                        }
                        if (count1 < count2) {
                            count1 = count2 = 0;
                        } else if (count1 > 0 && count2 > 0) {
                            max_variance = max(max_variance, count1 - count2);
                        }
                    }
                }
            }

            // Reverse the string for the second time around
            reverse(s.begin(), s.end());
        }

        return max_variance;
    }
};