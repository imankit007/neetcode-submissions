class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype([](const pair<int,int> &a, const pair<int,int> &b){
            return a.second < b.second;
        })> maxHeap;        

        unordered_map<int,int> count;

        vector<int> ans;

        for(const int &n: nums){
            ++count[n];
        }

        for(const auto &p : count){
            maxHeap.push(p);
        }

        while(k--){
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return ans;


    }
};
