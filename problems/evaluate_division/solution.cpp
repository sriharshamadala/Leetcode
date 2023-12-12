class Solution {
public:
    typedef struct Node {
        vector<Node *> neighbors;
        vector<double> rhs;
        bool is_visited;        
        Node () {
            is_visited = false;
        }
    } Node;
    
    double DFS(Node * source, Node * dest, const unordered_map<string, Node *>& node_map) {
        if (source->is_visited) {
            return 0.0;
        }
        source->is_visited = true;
        for (int ii = 0; ii < source->neighbors.size(); ++ii) {
            if (source->neighbors[ii] == dest) {
                // Terminal condition
                return source->rhs[ii];
            } else {
                double tmp = DFS(source->neighbors[ii], dest, node_map) * (source->rhs[ii]);
                if (tmp != 0) {
                    // Found solution. break out.
                    return tmp;
                }
            }
        }
        // Leaf node.
        return 0.0;        
    }
    
    void resetIsVisited (unordered_map<string, Node *>& node_map) {
        for (auto node : node_map) {
            node.second->is_visited = false;
        }
    } 
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> result;
        unordered_map<string, Node *> node_map;
        // Iterate through the equations and populate the adjacency list.
        for (int ii = 0; ii < equations.size(); ++ii) {
            string num = equations[ii].first;
            string den = equations[ii].second;
            double rhs = values[ii];
            
            Node * num_node, * den_node;
            if (node_map.find(num) == node_map.end()) {
                num_node = new Node();
                node_map[num] = num_node;
            } else {
                num_node = node_map[num];
            }
            
            if (node_map.find(den) == node_map.end()) {
                den_node = new Node();
                node_map[den] = den_node;
            } else {
                den_node = node_map[den];
            }
            
            // Construct the edges.
            num_node->neighbors.push_back(den_node);
            num_node->rhs.push_back(rhs);
            den_node->neighbors.push_back(num_node);
            den_node->rhs.push_back(1/rhs);            
        }
                
        // Now that the graph is constructed, for each query, do DFS and find the path weight.
        for (auto query : queries) {
            if ((node_map.find(query.first) == node_map.end()) || (node_map.find(query.second) == node_map.end())) {
                result.push_back(-1.0);
            } else {
                double tmp_result = DFS(node_map[query.first], node_map[query.second], node_map);
                if (tmp_result == 0) {
                    // No path exists
                    result.push_back(-1.0);
                } else {
                    result.push_back(tmp_result);
                }
            }
            // Need to reset is_visited for each node after the query.
            resetIsVisited(node_map);
        }
        
        return result;
    }
};