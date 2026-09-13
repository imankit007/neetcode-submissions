class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (check(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

   private:
    bool check(vector<int>& piles, int h, int k) {
        int curr = 0;

        for (const int p : piles) {
             curr += (p + k - 1) / k;
        }

        return curr <= h;
    }
};
