class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

        map<array<int,26>, vector<string>> mp;


        for(const string &word: strs){
            array<int,26> count{};

            for(const int &ch : word){
                count[ch - 'a']++;
            }

            mp[count].push_back(word);
        }

        for(const auto& [key, arr]: mp){
            ans.push_back(arr);
        }

        return ans;

    }
};
