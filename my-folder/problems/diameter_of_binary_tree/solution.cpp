/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorderUpdateDepth(TreeNode* curr_node, unordered_map<TreeNode*, pair<int, int>>& left_right_depths) {
        int left_depth, right_depth;
        if (curr_node == NULL) {
            return;
        } 
        if (curr_node->left == NULL) {
            left_depth = 0;
        } else {
            inorderUpdateDepth(curr_node->left, left_right_depths);
            pair<int, int> temp_pair = left_right_depths[curr_node->left];
            left_depth = max(temp_pair.first, temp_pair.second) + 1;
        }
        
        if (curr_node->right == NULL) {
            right_depth = 0;
        } else {
            inorderUpdateDepth(curr_node->right, left_right_depths);    
            pair<int, int> temp_pair = left_right_depths[curr_node->right];
            right_depth = max(temp_pair.first, temp_pair.second) + 1;
        }
        
        left_right_depths[curr_node] = make_pair(left_depth, right_depth);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        unordered_map<TreeNode*, pair<int, int>> left_right_depths;
        inorderUpdateDepth(root, left_right_depths);
        
        // Iterate the hash map to evaluate the diameter.
        int diameter = 0;
        for (unordered_map<TreeNode*, pair<int, int>>::iterator it = left_right_depths.begin(); it != left_right_depths.end(); it++) {
            int temp_diameter = (*it).second.first + (*it).second.second;
            if (temp_diameter > diameter) {
                diameter = temp_diameter;
            }
        }
        
        return diameter;
    }
};