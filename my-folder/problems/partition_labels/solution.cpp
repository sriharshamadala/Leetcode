class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> last_ind_hash;
        vector<int> result;
        
        for (int ii = 0; ii < S.length(); ++ii) {
            last_ind_hash[S[ii]] = ii;
        }
        
        int curr_part = 0;
        int prev_ind = -1;
        for (int ii = 0; ii < S.length(); ++ii) {
            if (ii <= curr_part) {
                // Move the curr_part
                if (last_ind_hash[S[ii]] > curr_part) {
                    curr_part = last_ind_hash[S[ii]];
                }
            } else {
                result.push_back(curr_part - prev_ind);
                prev_ind = curr_part;
                curr_part = ii;
                if (last_ind_hash[S[ii]] > curr_part) {
                    curr_part = last_ind_hash[S[ii]];
                }
            }
        }
        result.push_back(S.length() - 1 - prev_ind);
        
        // Need to return lengths
        /*
        vector<int> result;
        int prev_ind = -1;
        for (int ii = 0; ii < part_index.size(); ++ii) {
            result.push_back(part_index[ii] - prev_ind);
            prev_ind = part_index[ii];
        }
        */
        return result;
    }
};