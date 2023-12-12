class Solution {
public:
    string DP(string s, size_t new_index, list<int>&pald_mids) {
        int max_length = 0;
        string longest_pald;
        // go over the list to see if the new character increases the palindrome.
        for (auto iter = pald_mids.begin(); iter != pald_mids.end(); ) {
            int mid_index = *iter;
            //cout << mid_index << " " << new_index << endl;
            // same logic whether center is a space or a character.
            int temp_index = mid_index - new_index;
            if ((temp_index >= 0) && (s[temp_index] == s[new_index])) {
                //cout << "1";
                int temp_pald_length = new_index - temp_index + 1;
                if (temp_pald_length > max_length) {
                    max_length = temp_pald_length;
                    longest_pald = string(s, temp_index, temp_pald_length);
                    //cout << longest_pald << endl;                
                }
                iter++;
            } else {
                //cout << "2";
                // palindrome property broke. No changes.
                iter = pald_mids.erase(iter);
            }
        }
        
        // Two new potential centers arise
        if (s[new_index - 1] == s[new_index]) {
            //cout << 2 * new_index - 1 << endl;
            pald_mids.push_back(2 * new_index - 1);
            if (max_length == 0) {
                max_length = 2;
                longest_pald = string(s, new_index - 1, 2);
                //cout << longest_pald << endl;
            }
        }
        if ((new_index > 1) && (s[new_index - 2] == s[new_index])) {
            //cout << 2 * new_index - 2 << endl;
            pald_mids.push_back(2 * new_index - 2);
            if (max_length <= 2) {
                max_length = 3;
                longest_pald = string(s, new_index - 2, 3);
                //cout << longest_pald << endl;
            }
        }
        
        return longest_pald;
    }
    
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        if (s.length() == 1) return s;
        
        string longest_pald = string(s, 0, 1);
        size_t max_length = 1;
        // All possible centers of palindromes. 
        // Since centers can be spaces, the indices are diff. n chars have 2n-1 indices.
        list<int> pald_mids;
        
        for (size_t ii = 1; ii < s.length(); ++ii) {
            string temp_str = DP(s, ii, pald_mids);
            if (temp_str.length() > max_length) {
                max_length = temp_str.length();
                longest_pald = temp_str;
            }
        }
        
        return longest_pald;        
    }
};