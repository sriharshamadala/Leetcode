class Solution {
public:
    int max3 (int n1, int n2, int n3) {
        int temp = max(n1, n2);
        return max(temp, n3);
    }
    
    int min3 (int n1, int n2, int n3) {
        int temp = min(n1, n2);
        return min(temp, n3);
    }
    
    int maxProduct(vector<int>& nums) {
        int num_len = nums.size();
        if (num_len == 0) {
            return 0;
        }
        if (num_len == 1) {
            return nums[0];
        }
        
        int curr_max = nums.back();
        int curr_min = nums.back();
        int overall_max = curr_max;
        for (int ii = num_len - 2; ii >= 0; --ii) {
            int temp = nums[ii];
            int temp_curr_max = max3(temp, temp * curr_max, temp * curr_min);
            int temp_curr_min = min3(temp, temp * curr_max, temp * curr_min);
            curr_max = temp_curr_max;
            curr_min = temp_curr_min;
            if (curr_max > overall_max) {
                overall_max = curr_max;
            }
        }
        
        return overall_max;
    }
};