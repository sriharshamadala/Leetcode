class Solution {
public:
    int numDecodings(string s) {
        if (s.find("00") != string::npos) {
           return 0;
        }
        
        if (s[0] == '0') {
            return 0;
        }
        
        vector<int>DP(s.length() + 1, 0);
       
        DP[0] = 1;
        DP[1] = 1;
        for (int ii = 1; ii < s.length(); ++ii) {
            if (s[ii] != '0') {
                DP[ii + 1] += DP[ii];
            }
            
            int temp_num = atoi(s.substr(ii - 1, 2).c_str());
            if ((s[ii - 1] != '0') && (temp_num >= 1) && (temp_num <= 26)) {
                DP[ii + 1] += DP[ii - 1];
            }
        }
       
        //cout << DP[0] << DP[1] << DP[2] << DP[3] << endl;
        return DP[s.length()];
    }
};