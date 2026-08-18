class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> count;


        const int n = s.length();

        int ans = 0;
        int l = 0;
        int r = 0;

        for(; r < n ; ++r){
            int curr = ++count[s[r]];

            while(count[s[r]] > 1){
              --count[s[l++]];
            }
            ans = max(ans, r - l + 1);
        }

        return ans;

    }
};
