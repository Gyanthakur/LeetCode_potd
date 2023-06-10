#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    long long check(long long a, int index, int n) {
        long long leftOffset = std::max(a - static_cast<long long>(index), 0LL);
        long long result = (a + leftOffset) * (a - leftOffset + 1) / 2;
        long long rightOffset = std::max(a - static_cast<long long>((n - 1) - index), 0LL);
        result += (a + rightOffset) * (a - rightOffset + 1) / 2;
        return result - a;
    }

    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(mid, index, n) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left + 1;
    }
};