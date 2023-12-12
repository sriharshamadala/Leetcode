class Solution {
public:
    
    // Using Kadane's algorithm.
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int max_ending = 0;
        int max_so_far = 0;
        int max_negative_number = INT_MIN;
        for (auto num : nums) {
            max_ending += num;
            if (max_ending <= 0) {
                max_ending = 0;
                if (num > max_negative_number) {
                    max_negative_number = num;
                }
            } else if (max_ending > max_so_far) {
                max_so_far = max_ending;
            }            
        }
        
        if (max_so_far == 0) {
            // all negative nums
            return max_negative_number;
        } else {
            return max_so_far;
        }    
    }
};