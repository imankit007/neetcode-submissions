class Solution {
   public:
    const char DELIMITER = '#';

    string encode(vector<string>& strs) {
        string encoded = "";

        for (const string& s : strs) {
            const int n = s.length();
            encoded += to_string(n);
            encoded += DELIMITER;
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != DELIMITER) {
                j++;
            }

            int size = stoi(s.substr(i, j - i));

            j++;

            ans.push_back(s.substr(j, size));

            i = j + size;
        }

        return ans;
    }
};
