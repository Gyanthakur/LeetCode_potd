#include<bits/stdc++.h>
using namespace std;
int main(){


return 0;
}


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // creating a vector of n*n
        
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        //int row=matrix.size();
        //int col =matrix[0].size();
        int count =0;
        int total =n*n;
        
        //// all index 
        
        int startingrow=0;
        int startingcol=0;
        int endingrow=n-1;
        int endingcol=n-1;
        
        while(count<total)
        {
            for(int i=startingcol;count<total && i<=endingcol; i++)
            {
                count++;
                ans[startingrow][i]=count;
                
            }
            startingrow++;
            
            for(int i=startingrow;count<total && i<=endingrow; i++)
            {
            
                count++;
                ans[i][endingcol]=count;
            }
            endingcol--;
            
            for(int i=endingcol;count<total && i>=startingcol; i--)
            {
                 count++;
                ans[endingrow][i]=count;
            }
            endingrow--;
            
            for(int i=endingrow;count<total && i>=startingrow; i--)
            {
                 count++;
                ans[i][startingcol]=count;
            
            }
            startingcol++;
        }
        
        
        return ans;
        
        
    }
};