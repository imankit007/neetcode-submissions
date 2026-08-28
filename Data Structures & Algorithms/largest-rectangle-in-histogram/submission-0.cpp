class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monoToneStack;
        const int n = heights.size();
        vector<int> right(n, n), left(n,-1);

        for (int i = 0; i < heights.size(); ++i) {
            while (!monoToneStack.empty() && heights[monoToneStack.top()] >= heights[i]) {
                right[monoToneStack.top()] = i;
                monoToneStack.pop();
            }

            if (!monoToneStack.empty()) {
                left[i] = monoToneStack.top();
            }
            monoToneStack.push(i);
        }

        int ans = 0;

        for (int i = 0; i < heights.size(); ++i) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }

        return ans;
    }
};
