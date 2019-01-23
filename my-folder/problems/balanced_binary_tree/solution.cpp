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
    int maxHeightSubtree (TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        int tmp_left = maxHeightSubtree(root->left);       
        int tmp_right = maxHeightSubtree(root->right); 
        if ((tmp_left == -1) || (tmp_right == -1)) {
            return -1;
        } else if (abs(tmp_left - tmp_right) > 1) {
            return -1;
        } else {
            return 1 + max(tmp_left, tmp_right);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        return (maxHeightSubtree(root) != -1);
    }
};