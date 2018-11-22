class Solution {
public:
    string lcp2(string s1, string s2) {
        string small;
        string big;
        string result;
        
        if (s1.size() >= s2.size()) {
            small = s2;
            big = s1;
        } else {
            small = s1;
            big = s2;
        }
        for (int ii = 0; ii < small.size(); ++ii) {
            if (small[ii] == big[ii]) {
                result.push_back(small[ii]);
            } else {
                break;
            }
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
       string result;
       if (strs.size() == 0) {
           result = "";
       } else if (strs.size() == 1) {
           result = strs[0];
       } else {
           result = strs[0];
           for (int ii = 0; ii < strs.size() - 1; ++ii) {
             result = lcp2(result, strs[ii + 1]);
           }           
       }
        
       return result;
    }
};