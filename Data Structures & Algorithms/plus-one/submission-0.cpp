class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int curr  = carry + digits[i];

            if(curr > 9){
                carry = 1;
                curr = 0;
            }else{
                carry = 0;
            }

            ans.push_back(curr);
        }

        if(carry){
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
