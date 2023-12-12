class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int num_len = nums.size();
        vector<int>indices;
        vector<string> result(num_len, "");
        for (int ii = 0; ii<num_len; ++ii) {
            indices.push_back(ii);
        }
        sort(indices.begin(), indices.end(), [&nums](int i1, int i2){return nums[i1] > nums[i2];});
        
        if (num_len == 0) return result;
        if (num_len == 1) {
            result[0] = "Gold Medal";
            return result;
        }
        if (num_len == 2) {
            result[indices[0]] = "Gold Medal";
            result[indices[1]] = "Silver Medal";
            return result;
        }
        if (num_len >= 3) {
            result[indices[0]] = "Gold Medal";
            result[indices[1]] = "Silver Medal";
            result[indices[2]] = "Bronze Medal";
        }
        for (int ii = 3; ii < num_len; ++ii) {
            result[indices[ii]] = to_string(ii + 1);
        }
        return result;
    }
};