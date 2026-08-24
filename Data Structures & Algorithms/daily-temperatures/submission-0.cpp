class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        const int n = temperatures.size();

        stack<int> st;
        vector<int> ans(n);
        for(int i =0 ; i < n; ++i){
            
            int today = temperatures[i];
            
            while(!st.empty() && temperatures[st.top()] < today){
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            } 
            st.push(i);

        }
        return ans;

    }
};
