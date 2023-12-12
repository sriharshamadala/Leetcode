class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        unordered_map<int, deque<int>> my_hash;
        vector<int> result;
        
        // add each temperature to the map.
        for (int ii = 0; ii < T.size(); ++ii) {
            if (my_hash.find(T[ii]) == my_hash.end()) {
                my_hash[T[ii]] = deque<int>(1, ii);
            } else {
                my_hash[T[ii]].push_back(ii);
            }
        }
        
        for (int ii = 0; ii < T.size(); ++ii) {
            int temp = T[ii];
            int curr_temp = temp + 1;
            int min_wait = INT_MAX;
            while ((curr_temp <= 100)) {
                if ((my_hash.find(curr_temp) != my_hash.end()) && !my_hash[curr_temp].empty()) {
                    int dur = my_hash[curr_temp].front() - ii;
                    if (dur < min_wait) {
                        min_wait = dur;
                    }
                }
                curr_temp++;
            }
            
            (min_wait == INT_MAX) ? result.push_back(0) : result.push_back(min_wait);
            my_hash[temp].pop_front();
        }
        
        return result;        
    }
};