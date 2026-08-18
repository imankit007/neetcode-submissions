class Solution {
   public:
    int characterReplacement(string s, int k) {
        const int n = s.length();
        vector<int> count(26, 0);
        int ans = 0;

        int l = 0, r = 0;

        int maxCount = 0;
        for (; r < n; ++r) {
            maxCount = max(maxCount, ++count[s[r] - 'A']);
            while (maxCount + k < r - l + 1) {
                --count[s[l++] - 'A'];
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
