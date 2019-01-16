class Solution {
public:
    void letterCasePermutRecur (string S, int index, vector<string>& result) {
        if ((index < S.length()) ) {
            if (isalpha(S[index])) {
                letterCasePermutRecur(S, index + 1, result);
                // toggle case
                if (isupper(S[index])) {
                    S[index] = tolower(S[index]);
                } else {
                    S[index] = toupper(S[index]);
                }
                result.push_back(S);
                letterCasePermutRecur(S, index + 1, result);
            } else {
                letterCasePermutRecur(S, index + 1, result);
            }
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        result.push_back(S);
        letterCasePermutRecur(S, 0, result);
        
        return result;
    }
};