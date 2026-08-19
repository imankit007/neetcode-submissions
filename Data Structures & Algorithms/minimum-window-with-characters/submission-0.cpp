class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count;

        for (const char& c : t) {
            ++count[c];
        }

        const int n = s.size();

        int l = 0, r = 0;
        int bestLen = INT_MAX;
        int bestL = 0;
        int required = count.size();
        int formed = 0;
        unordered_map<char, int> count2;

        for (; r < n; ++r) {
            char c = s[r];
            if (count.count(c)) {
                ++count2[c];
                if (count2[c] == count[c]) {
                    formed++;
                }
            }
            while (formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }

                char leftChar = s[l];
                if (count.count(leftChar)) {
                    if (count2[leftChar] == count[leftChar]) {
                        formed--;
                    }
                    --count2[leftChar];
                }
                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};
