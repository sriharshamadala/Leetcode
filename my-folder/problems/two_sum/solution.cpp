class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (int num : nums) {
            if (hash.find(num) == hash.end()) {
                hash[num] = 1;
            } else {
                hash[num]++;
            }
        }
       
        int compliment;
        for (int ii = 0; ii < nums.size(); ++ii) {
            compliment = target - nums[ii];
            if (hash.find(compliment) != hash.end()) {
                if (compliment == nums[ii]) {
                    if (hash[nums[ii]] >= 2) {
                        result.push_back(ii);
                        break;
                    }
                } else {
                    result.push_back(ii);
                    break;
                }
            }
        }
        
        // Find compliment's index;
        for (int ii = 0; ii < nums.size(); ++ii) {
            if ((nums[ii] == compliment) && (ii != result[0])) {
                result.push_back(ii);
                break;
            }
        }
        
        return result;
    }
};