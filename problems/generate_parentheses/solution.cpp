class Solution {
public:
    
    bool isBalanced(int index, int total_nf_bits) {
        //cout << index ;
        int nf_opening_par = 0, nf_closing_par = 0;
        //cout << " " << total_nf_bits;
        int is_msb_set_pattern = (1 << (total_nf_bits- 1));
        //cout << " " << is_msb_set_pattern;
        
        for (int ii = 0; ii < total_nf_bits; ++ii) {
            if (index & is_msb_set_pattern) {
                nf_opening_par++;
            } else {
                nf_closing_par++;
            }
            if (nf_closing_par > nf_opening_par) {
                //cout <<" greater # closing par\n";
                return false;
            }
            if (nf_opening_par > total_nf_bits / 2) {
                //cout << " more than half opening par\n ";
                return false;
            }
            index <<= 1;
        }
        if (nf_opening_par == nf_closing_par) {
            //cout << " Equal # par\n ";
            return true;
        } else {
            //cout << " Unequal # par\n ";
            return false;
        }
    }
    
    string generateString(int index, int total_nf_bits) {
        string output;
        int is_msb_set_pattern = (1 << (total_nf_bits- 1));
        
        for (int ii = 0; ii < total_nf_bits; ++ii) {
            if (index & is_msb_set_pattern) {
                output.push_back('(');
            } else {
                output.push_back(')');
            }
            index <<= 1;
        }
        return output;
    }
    
    vector<string> generateParenthesis(int n) {
        // Using indexes to generate all possible combinations.
        // Then we use stack to filter out the unbalanced strings.
        // This is an iterative solution.
        vector<string> result;
        
        if (n <= 0) {
            result.push_back("");
            return result;
        }
        if (n > 15) return result;
        
        // No optimization. We evaluate all 2^2n combinations
        for (int index = 0; index < (1 << (2 * n)); ++index) {
            // a bit set in index's ith position implies opening paranthesis, else closing.
            if (isBalanced(index, 2 * n)) {
                result.push_back(generateString(index, 2 * n));
            }
        }
        
        return result;
    }
};