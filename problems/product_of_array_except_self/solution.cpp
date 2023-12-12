class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        
        int prod_from_start = 1;
        output.push_back(prod_from_start);
        for (int ii = 1; ii < nums.size(); ++ii) {
            prod_from_start *= nums[ii - 1];
            output.push_back(prod_from_start);
        }
        
        int prod_from_end = 1;
        for (int ii = nums.size() - 2; ii >= 0; ii--) {
            prod_from_end *= nums[ii + 1];
            output[ii] *= prod_from_end;
        }
        
        return output;
    }
};