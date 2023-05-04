#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}




class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        deque<int> radiant, dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push_back(i);
            } else {
                dire.push_back(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int r_idx = radiant.front();
            int d_idx = dire.front();
            radiant.pop_front();
            dire.pop_front();
            if (r_idx < d_idx) {
                radiant.push_back(r_idx + n);
            } else {
                dire.push_back(d_idx + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};