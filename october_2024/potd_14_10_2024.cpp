class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        

        long long score = 0;
        priority_queue<int> pq;
        for(int i=0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k > 0){
            int max = pq.top();
            if(max == 1)    //this condition helps to exit early hence more efficient
                return score + k;
            score += max;
            pq.pop();
            pq.push(ceil(max / 3.0));
            k--;
        }

        return score;

    }
};