#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}



// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* prevPtr = nullptr;

        // Reverse the first half of the linked list
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            fastPtr = fastPtr->next->next;
            ListNode* nextNode = slowPtr->next;
            slowPtr->next = prevPtr;
            prevPtr = slowPtr;
            slowPtr = nextNode;
        }

        // Adjust pointers if the length of the linked list is odd
        if (fastPtr != nullptr) {
            slowPtr = slowPtr->next;
        }

        int maxSum = std::numeric_limits<int>::min();
        while (slowPtr != nullptr) {
            maxSum = std::max(maxSum, slowPtr->val + prevPtr->val);
            slowPtr = slowPtr->next;
            prevPtr = prevPtr->next;
        }
        return maxSum;
    }
};