class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        vector<int> ans(n);

        int i;
        int prefix = 1;
        for (i = 0; i < n; ++i) {
            ans[i]  = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;

        for (i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

    
        return ans;
    }
};
