class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0), count2(26,0);

        if(s1.length() > s2.length()){
            return false;
        }


        for(const char &c: s1){
            ++count1[c - 'a'];
        }

        int r = 0;
        for(; r<s2.length(); ++r){
                ++count2[s2[r] - 'a'];
                if(r > s1.length() - 1){
                    --count2[s2[r - s1.length()] - 'a'];
                }
                if(count1 == count2){
                    return true;
                }
        }
        return false;

    }
};
