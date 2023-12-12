class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int maj_contenders[2] = {0};
      int maj_count[2] = {0};
      vector<int> result;
      int input_size = nums.size();
      
      for (int num : nums) {
        //cout << maj_contenders[0] << " " << maj_count[0] << "; ";
        //cout << maj_contenders[1] << " " << maj_count[1] << endl;
        // Check if num matches either of the two contenders
        if ( (maj_count[0] != 0) && (num == maj_contenders[0]) ) {
          maj_count[0]++;
        } else if ( (maj_count[1] != 0) && (num == maj_contenders[1]) ) {
          maj_count[1]++;
        } else if (maj_count[0] == 0) {
          // num did not match. check for count 0.
          maj_contenders[0] = num;
          maj_count[0]++;
        } else if (maj_count[1] == 0) {
          maj_contenders[1] = num;
          maj_count[1]++;
        } else {
          // decrement both counts
          maj_count[0]--;
          maj_count[1]--;
        }
      }
      
      // Since we don't know how many majority elements exist, search again.
      int count1 = 0; 
      int count2 = 0;
      for (int num : nums) {
        if (num == maj_contenders[0]) {
          count1++;
        } else if (num == maj_contenders[1]) {
          count2++;
        }
      }
      
      if (count1 > (input_size / 3)) {
        result.push_back(maj_contenders[0]);
      }
      if (count2 > (input_size / 3)) {
        result.push_back(maj_contenders[1]);
      }
      
      return result;
    }
};