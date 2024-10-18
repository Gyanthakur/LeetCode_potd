//1405. Longest Happy String

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        // Push in pq pairs of count and character
        if (a > 0) {
            pq.push({a, 'a'}); // Example input: a = 1, b = 1, c = 7
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        // Don't declare vector<string> silly mistake
        string res = "";

        // Dry run starts here
        /*
        Initial priority queue state:
        pq = [(7, 'c'), (1, 'a'), (1, 'b')]

        Result string starts as empty: res = ""
        */

        while (!pq.empty()) {
            auto [count1, char1] = pq.top(); // Get the character with the highest count
            pq.pop();

            // Check the 'three same characters constraint'
            //                               last                    second last
            if (res.size() >= 2 && res.back() == char1 && res[res.size() - 2] == char1) {
                // Condition is met, so we can't add char1
                if (pq.empty()) {
                    break; // No other characters available
                }
                // Take next most frequent character
                auto [count2, char2] = pq.top(); // Get the second most frequent character
                pq.pop();

                res += char2; // Add char2 to the result
                count2--;     // Decrement its count

                // Check if we can push char2 back into the queue
                if (count2 > 0) {
                    pq.push({count2, char2});
                }

                // Push char1 back into the queue as well
                pq.push({count1, char1});
            } else {
                // If adding char1 is okay
                res += char1; // Add char1 to the result
                count1--;     // Decrement its count

                // Push char1 back if there's still some left
                if (count1 > 0) {
                    pq.push({count1, char1});
                }
            }
        }

        return res; // Final result will be "ccaccbcc" or similar valid output
    }
};
// Dry run example updates:
/*
1st iteration:
count1 = 7, char1 = 'c', res = "c"
count1 decremented to 6. pq = [(6, 'c'), (1, 'a'), (1, 'b')]

2nd iteration:
count1 = 6, char1 = 'c', res = "cc" (not allowed)
count2 = 1, char2 = 'a', res = "cca", count2 decremented to 0. pq = [(6, 'c'),
(1, 'b')]

3rd iteration:
count1 = 6, char1 = 'c', res = "ccac"
count1 decremented to 5. pq = [(5, 'c'), (1, 'b')]

4th iteration:
count1 = 5, char1 = 'c', res = "ccaca" (not allowed)
count2 = 1, char2 = 'b', res = "ccacb", count2 decremented to 0. pq = [(5, 'c')]

5th iteration:
count1 = 5, char1 = 'c', res = "ccacbc"
count1 decremented to 4. pq = [(4, 'c')]

6th iteration:
count1 = 4, char1 = 'c', res = "ccacbcc"
count1 decremented to 3. pq = [(3, 'c')]

7th iteration:
count1 = 3, char1 = 'c', res = "ccacbcc"
...
Continue until the priority queue is empty.
*/
