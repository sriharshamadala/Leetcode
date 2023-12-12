class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int sum = 0;
        if (s.length() == 0) {
            return sum;
        } else if (s.length() == 1) {
            return roman_map[s[0]];
        }
        int temp_curr, temp_next;
        for (int ii = 0; ii < s.length() - 1; ++ii) {
            temp_curr = roman_map[s[ii]];
            temp_next = roman_map[s[ii + 1]];
            if (temp_curr < temp_next) {
                sum -= temp_curr;
            } else {
                sum += temp_curr; 
            }
        }
        
        sum += temp_next;
        return sum;
    }
};