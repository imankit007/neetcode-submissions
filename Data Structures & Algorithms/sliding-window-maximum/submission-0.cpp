class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        priority_queue<int, vector<int>> maxHeap;

        vector<int> ans;

        int l = 0, r = 0;
        for (; r < nums.size(); ++r) {
            ++freq[nums[r]]; 
            maxHeap.push(nums[r]);
            if (r - l + 1 >= k) {
                
                while(freq[maxHeap.top()] == 0 ){
                    maxHeap.pop();
                }

                ans.push_back(maxHeap.top());

                --freq[nums[l++]];
            }
        }
        return ans;
    }
};
