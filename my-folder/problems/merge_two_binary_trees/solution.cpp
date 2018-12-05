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
    void mergeTreeRecur (TreeNode* t1, TreeNode* t2, TreeNode*& to) {
        int val1, val2;
        to = new TreeNode(0);
        TreeNode * t1_left, *t1_right, *t2_left, *t2_right;
        
        if ((t1 == NULL) && (t2 == NULL)) {
            delete to;
            to = NULL;
            return;
        } else if (t1 == NULL) {
            val1 = 0;
            val2 = t2->val;
            t1_left = NULL;
            t1_right = NULL;
            t2_left = t2->left;
            t2_right = t2->right;
            //cout << "1null" << val2 << endl;
        } else if (t2 == NULL) {
            val2 = 0;
            val1 = t1->val;
            t1_left = t1->left;
            t1_right = t1->right;
            t2_left = NULL;
            t2_right = NULL;
            //cout << "2null" << val1 << endl;
        } else {
            val1 = t1->val;
            val2 = t2->val;
            t1_left = t1->left;
            t1_right = t1->right;
            t2_left = t2->left;
            t2_right = t2->right;
            //cout << val1 << val2 << endl;
        }
        to->val = val1 + val2;
        
        mergeTreeRecur(t1_left, t2_left, to->left);
        mergeTreeRecur(t1_right, t2_right, to->right);
        
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* result_root;
        mergeTreeRecur(t1, t2, result_root);
        return result_root;
    }
};