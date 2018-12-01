class Solution {
public:
    int countSubstrings(string s) {
        
        int s_len = s.length();
        int nf_pal = 0;
        
        for (int center = 0; center < 2 * s_len - 1; ++center) {
            int offset;
            if (center & 0x1) {
               offset = 1; 
            } else {
                nf_pal++;   // since the center is itself a palindrome.
                offset = 2;
            }
            while ((center >= offset) && (center + offset < 2 * s_len - 1)) {
                if (s[(center - offset) / 2] == s[(center + offset) / 2]) {
                    nf_pal++;
                } else {
                    break;
                }
                offset += 2;
            }
        }
        return nf_pal;
    }
};