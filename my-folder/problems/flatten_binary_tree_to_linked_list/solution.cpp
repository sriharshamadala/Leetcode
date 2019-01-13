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
    void eliminateLeft (TreeNode * root) {
        if (root != NULL) {
            eliminateLeft(root->left);
            eliminateLeft(root->right);
            if (root->left != NULL) {
                TreeNode * temp = root->right;
                root->right = root->left;
                root->left = NULL;
                TreeNode * curr = root->right;
                while ((curr != NULL) && (curr->right != NULL)) {
                    curr = curr->right;
                }
                if (curr != NULL) {
                    curr->right = temp;
                }
            }
        }
    }
    
    void printInorder (TreeNode * root) {
        if (root != NULL) {
            printInorder(root->left);
            cout << root->val << " ";
            printInorder(root->right);
        }
    }
    
    void flatten(TreeNode* root) {
        eliminateLeft(root);
    }
};