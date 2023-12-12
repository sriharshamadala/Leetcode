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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        int curr_level_count = 1;
        int temp_sum = 0;
        queue<TreeNode*> bfs_queue;
        
        if (root != NULL) {
            bfs_queue.push(root);
        } else {
            return right_view;
        } 
        do {
            TreeNode * temp = bfs_queue.front();
            if (temp->left != NULL) {
                bfs_queue.push(temp->left);
                temp_sum++;
            }
            if (temp->right != NULL) {
                bfs_queue.push(temp->right);
                temp_sum++;
            }
            bfs_queue.pop();
            curr_level_count--;
            if (curr_level_count == 0) {
                curr_level_count = temp_sum;
                temp_sum = 0;
                right_view.push_back(temp->val);
            }
        } while (!bfs_queue.empty());
            
        return right_view;
    }
};