class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        const int m = matrix.size();
        const int n = matrix[0].size();

        int l = 0;
        int r = (m*n) - 1;

        while (l <= r) {
            int mid = l + ((r - l) / 2);

            const int row = mid / n;
            const int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
