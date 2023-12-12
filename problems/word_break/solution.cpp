class Solution {
public:
    unordered_set<string> dict_hash;
    
    // Returns true if the entire substring is a valid word in dict.
    // Inclusive of the edge indices.
    bool isSubstringInDict (string& s, int left_ind, int right_ind) {
        string sub_string(s, left_ind, right_ind - left_ind + 1);
        auto it = dict_hash.find(sub_string);
        if (it == dict_hash.end()) {
            return false;
        } else {
            return true;
        }
    }
    
    bool validWordBreak (string& s, vector<bool>& dp) {
        for (int ii = 1; ii <= s.length(); ++ii) {
            for (int jj = ii - 1; jj >= 0; --jj) {
               if (dp[jj]) {
                   // upto jj-1 is valid word break. we expect rest up to ii to be valid word in dict.
                   if (isSubstringInDict(s, jj, ii - 1)) {
                        dp[ii] = true;
                        break;
                   }
               } 
            }
        }
        
        return dp[s.length()];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_len = s.length();
        // dp[x] = true implies s[0:x-1] has a valid word break
        vector<bool>dp(s_len + 1, false);
        
        // Create a hash for easy search.
        for (auto word : wordDict) {
            dict_hash.insert(word);
        }
       
        dp[0] = true;
        return validWordBreak(s, dp);
        
    }
};