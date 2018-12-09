class LRUCache {
public:
    int cap_;
    list<int> dll_;
    unordered_map<int, pair<int, list<int>::iterator>> my_hash_;
   
    // We assume key is found.
    int moveToMru (int key, int value) {
        dll_.erase(my_hash_[key].second);
        dll_.push_front(key);
        my_hash_[key] = make_pair(value, dll_.begin());
        return value;
    }
    
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        if (cap_ == 0) return -1;
        if (my_hash_.find(key) == my_hash_.end()) {
            return -1;
        } else {
            // Key found. Move it to MRU.
            int val = my_hash_[key].first;
            return moveToMru(key, val);   
        }        
    }
    
    void put(int key, int value) {
        if (cap_ == 0) return;
        if (my_hash_.find(key) == my_hash_.end()) {
            // key not found, insert
            if (dll_.size() >= cap_) {
                int temp_key = dll_.back();
                my_hash_.erase(my_hash_.find(temp_key));
                dll_.pop_back();
            } 
            dll_.push_front(key);
            cout << value << endl;
            my_hash_[key] = make_pair(value, dll_.begin());
        } else {
            // key found.
            moveToMru(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */