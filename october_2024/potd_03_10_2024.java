class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;

        long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // Edge case
        if (sum % p == 0) {
            return 0;
        }
        if (sum < p) {
            return -1;
        }

        Map<Long, Integer> map = new HashMap<>();
        map.put(0l, -1);

        long rem = sum % p;
        sum = 0;
        int res = n;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum %= p;

            long rem_ = sum - rem;
            if (rem_ < 0) {
                rem_ += p;
            }

            Integer val = map.get(rem_);
            if (val != null) {
                res = Math.min(res, i - val);
            }
            map.put(sum, i);
        }
        return res == n ? -1 : res;
    }
}
