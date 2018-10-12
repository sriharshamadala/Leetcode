class Solution {
public:
    struct RetVal {
        int incl;
        int excl;
        RetVal () {
            incl = 0;
            excl = 0;
        }
    };
    
    RetVal robDP(vector<int>& nums, int end_index) {
        RetVal ret_val;
        if (end_index == 0) {
            ret_val.incl = nums[0];
        } else {
            RetVal temp_val = robDP(nums, end_index - 1);
            ret_val.incl = temp_val.excl + nums[end_index];
            ret_val.excl = max(temp_val.incl, temp_val.excl);
        }
        return ret_val;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        RetVal ret_val = robDP(nums, nums.size() - 1);
        return max(ret_val.incl, ret_val.excl);
    }
};