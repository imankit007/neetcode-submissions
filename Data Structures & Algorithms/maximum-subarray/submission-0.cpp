class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;

        int curr = 0;
        for (int r = 0; r < nums.size(); r++) {
            curr += nums[r];
            ans = max(ans, curr);
            if (curr < 0) {
                curr = 0;
            }
        }

        return ans;
    }
};
