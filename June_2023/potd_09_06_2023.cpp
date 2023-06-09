#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         for (char letter : letters) {
//             if (letter > target) {
//                 return letter;
//             }
//         }
//         return letters[0];
//     }
// };

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size()-1;
        int mid = 0;
        if (letters[right] <= target) {
            return letters[0];
        }
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return letters[left];
    }
};