class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while (n != 1) {
            if (visited.count(n))
                return false;

            visited.insert(n);
            n = solve(n);
        }

        return true;
    }

   private:
      int solve(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
};
