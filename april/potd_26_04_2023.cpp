#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}



class Solution {
public:
    int addDigits(int num) {

    int ans = 0;
    if (num <= 9)
        return num;
    while (num != 0)
    {
        ans = ans + num % 10;
        num = num / 10;
        if (ans > 9 && num == 0)
        {
            num = ans;
            ans = 0;
        }
    }
    return ans;

    }
};