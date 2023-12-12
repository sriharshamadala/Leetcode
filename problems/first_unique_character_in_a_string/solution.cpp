class Solution {
public:
    const int kNumOfChars = 26;
    int firstUniqChar(string s) {
      int char_count[kNumOfChars] = {0};
      int result_index = -1;
      for (auto letter : s) {
        char_count[letter - 'a']++;
      }
      
      int temp_index = 0;
      for (auto letter : s) {
        if (char_count[letter - 'a'] == 1) {
          result_index = temp_index;
          break;
        }
        temp_index++;
      }
      
      return result_index;
    }
};