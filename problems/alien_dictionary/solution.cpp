class Node {
    private:
        char key_;
        list<Node*> children_;
        bool is_visited_;
    
    public:
        Node (char key) {
            key_ = key;
            is_visited_ = false;
        }
        char getKey () {
            return key_;
        }
        list<Node*>& getChildren () {
            return children_;
        }
        void visited () {
            is_visited_ = true;
        }
        bool isVisited () {
            return is_visited_;
        }
    
};

class Solution {
public:
    
    bool reverseDfs (Node *curr_node, stack<char>& out, deque<char>& ancestors) {
        //cout << "DFS of " << curr_node->getKey() << endl;
        if (!curr_node->isVisited()) {
            curr_node->visited();
            //cout << "pushing ancestor " << curr_node->getKey() << endl;
            ancestors.push_back(curr_node->getKey());
            for (auto node : curr_node->getChildren()) {
                if (!(node->isVisited())) {                    
                    if (!reverseDfs(node, out, ancestors)) {
                        return false;
                    }
                } else {
                    // Check for back-edge. shows cycle.
                    for (auto ancestor : ancestors) {
                        if (node->getKey() == ancestor) {
                            return false;
                        }
                    }
                }
            }
            //cout << "popping ancestor " << ancestors.back() << endl;
            ancestors.pop_back();
            out.push(curr_node->getKey());
        }
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        // Stores only the unique chars.
        unordered_set<char> alphabets;
        unordered_map<char, Node*> adj_map;
        stack<char> dfs_out;
        string result;
        
        for (int ii = 0; ii < words.size(); ++ii) {
            for (int jj = 0; jj < words[ii].length(); ++jj) {
                alphabets.insert(words[ii][jj]);
            }    
        }
        
        // Create nodes for each char in the set.
        for (auto character : alphabets) {
            Node * temp = new Node(character);
            adj_map[character] = temp;
        }
        
        // Compare the adjacent words to draw edges.
        for (int ii = 0; ii < words.size() - 1; ++ii) {
            int word_len_1 = words[ii].length();
            int word_len_2 = words[ii + 1].length();
            int min_length = (word_len_1 < word_len_2) ? word_len_1 : word_len_2;
            for (int jj = 0; jj < min_length; ++jj) {
                if (words[ii][jj] != words[ii + 1][jj]) {
                    // Draw edge.
                    (adj_map[words[ii][jj]]->getChildren()).push_back(adj_map[words[ii + 1][jj]]);
                    break;
                }
            }
        }
        
        // Do reverse DFS and print the result in reverse to get topological sort.
        deque<char> ancestors;
        for (auto character : alphabets) {
            if (!reverseDfs(adj_map[character], dfs_out, ancestors)) {
                // Found cycle.
                return "";
            }
            //curr_nodes_dfs.clear();
        }
     
        // Pop the stack and store in string to return.
        while (!dfs_out.empty()) {
            result.push_back(dfs_out.top());
            dfs_out.pop();
        }
        
        return result;
    }
};