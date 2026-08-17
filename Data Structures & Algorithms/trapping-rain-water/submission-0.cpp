class Solution {
   public:
    int trap(vector<int>& height) {
        int ans = 0;

        const int n = height.size();

        vector<int> prefix(n,0), suffix(n,0);
        int i;
        for (i = 1; i < n; i++) {
            prefix[i] = max(height[i - 1], prefix[i - 1]);
        }

        for (i = n - 2; i >= 0; --i) {
            suffix[i] = max(height[i + 1], suffix[i + 1]);
        }

        for (i = 0; i < n; ++i) {
            
            ans += max(0, (min(prefix[i], suffix[i]) - height[i]));
        }

        return ans;
    }
};
