"""
white: This keeps track of how many '1's have been encountered as we iterate through the string. It starts at 0.
res: This accumulates the number of steps needed. It also starts at 0.
j: This is the index used to traverse the string.
n: This stores the length of the input string s

For example, if s = "001101":

    Start with white = 0, res = 0.
    At index 0: s[0] = '0', res += 0 (still 0). white = 0.
    At index 1: s[1] = '0', res += 0 (still 0). white = 0.
    At index 2: s[2] = '1', increment white to 1.
    At index 3: s[3] = '1', increment white to 2.
    At index 4: s[4] = '0', add white (2) to res (now res = 2).
    At index 5: s[5] = '1', increment white to 3.

Final res is 2, which represents the steps needed to convert all '0's.
"""
class Solution:
    def minimumSteps(self, s: str) -> int:
        white=0
        res=0
        j=0
        n=len(s)
        while(j<n):
            if s[j]=='0':
                res+=white
            white+=1 if s[j]=='1' else 0
            j+=1
            
            
        return res
