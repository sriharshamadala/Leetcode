class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
      vector<string> result;
      if (s.length() < 2) return result;
      
      for (int ii = 0; ii < s.length() - 1; ++ii) {
        if ((s[ii] == '+') && (s[ii + 1] == '+')) {
          string temp_string(s);
          temp_string[ii] = '-';
          temp_string[ii + 1] = '-';
          result.push_back(temp_string);
        }
      }
      
      return result;
    }
};