class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> sum_nf_ways_map;
        int result = 0;
        if (nums.size() == 0) return result;
        
        if (nums[0] == 0) {
            sum_nf_ways_map[0] = 2;
        } else {
            sum_nf_ways_map[nums[0]] = 1;
            sum_nf_ways_map[-nums[0]] = 1;
        }
        for (int ii = 1; ii < nums.size(); ++ii) {
            unordered_map<int, int> tmp_map;
            
            for (auto tmp_pair : sum_nf_ways_map) {
                int tmp_num = tmp_pair.first + nums[ii];
                if (tmp_map.find(tmp_num) == tmp_map.end()) {
                    tmp_map[tmp_num] = tmp_pair.second;
                } else {
                    tmp_map[tmp_num] += tmp_pair.second;
                }
                
                tmp_num = tmp_pair.first - nums[ii];
                if (tmp_map.find(tmp_num) == tmp_map.end()) {
                    tmp_map[tmp_num] = tmp_pair.second;
                } else {
                    tmp_map[tmp_num] += tmp_pair.second;
                }
            }
            sum_nf_ways_map = tmp_map;
        }
        
        if (sum_nf_ways_map.find(S) != sum_nf_ways_map.end()) {
            result = sum_nf_ways_map[S];
        }
        return result;
    }
};