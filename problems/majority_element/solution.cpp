class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int majority_number_so_far = 0;
      int majority_count = 0;
      for (int num : nums) {
        if (majority_count == 0) {
          majority_number_so_far = num;
          majority_count++;
        } else {
          if (num == majority_number_so_far) {
            majority_count++;
          } else {
            majority_count--;
          }
        }
      }
      
      // Since we are given that the majority number exists, no need to check again
      return majority_number_so_far;
    }
};