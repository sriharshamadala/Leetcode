class Solution {
public:
    bool isAlphaNumeric (char letter) {
      if ((letter >= 65) && (letter <=90) || ((letter >= 97) && (letter <=122)) || ((letter >= 48) && (letter <=57))) {
        return true;
      } else {
        return false;
      }
    }
  
    bool isCharEqual (char letter1, char letter2) {
      if (letter1 == letter2) {
        return true;
      } else {
        // If the letters are not equal and if either of them are numeric, we can return false.
        if ((letter1 < 65) || (letter2 < 65)) return false;
        int diff = (letter1 - letter2);
        cout << diff << endl;
        if ((diff == 32) || (diff == -32)) {
          return true;
        } else {
          return false;
        }
      } 
    }
  
    bool isPalindrome(string s) {
      string clean_str;
      // Strip all non-alpha numeric chars.
      for (auto letter : s) {
        if (isAlphaNumeric(letter))  {
          clean_str.push_back(letter);
        }
      }
      
      if (clean_str.length() <= 1) return true;
      
      int left_index = 0;
      int right_index = clean_str.length() - 1;
      bool result = true;
      
      while (left_index < right_index) {
        if (!isCharEqual(clean_str[left_index], clean_str[right_index])) {
          result = false;
          break;
        }
        left_index++;
        right_index--;
      }
      
      return result;
    }
};