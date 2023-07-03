#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int g=0;
        int n=s.length();
        int e=n;
        if(s==goal)
        {
            set<char>temp(s.begin(),s.end());
            return temp.size()<goal.size();
        }
         int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }
        return s == goal;
    }
};