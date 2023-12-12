class Solution {
public:
    void maxDP (deque<int>& dp_storage) {
        int size = dp_storage.size();
        if (size <= 3) {
            dp_storage.push_back(size + 1);
        } else {
            vector<int> temp_vec;
            // A
            temp_vec.push_back(dp_storage[size - 1] + 1);
            // ACV
            temp_vec.push_back(dp_storage[size - 3] * 2);
            // ACVV
            if (size >= 4) temp_vec.push_back(dp_storage[size - 4] * 3);
            // ACVVV
            if (size >= 5) temp_vec.push_back(dp_storage[size - 5] * 4);
            // ACVVVV
            if (size >= 6) temp_vec.push_back(dp_storage[size - 6] * 5);
            
            // calculate the max of the above temp_vec
            dp_storage.push_back(*max_element(temp_vec.begin(), temp_vec.end()));
            
            // pop if necessary
            if (dp_storage.size() > 6) dp_storage.pop_front();
        }
    }
    
    int maxA(int N) {
        deque<int> dp_storage;
        for (int ii = 0; ii < N ; ++ii) {
            maxDP(dp_storage);
        }
        return dp_storage.back();
    }
};