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
    int closestValue(TreeNode* root, double target) {
      double min_ge = LONG_MAX;
      double max_le = LONG_MIN;
      TreeNode * temp = root;
      while (temp != NULL) {
        // nothing is said about equal-to; assume it is stored to left.
        if ( target <= temp->val ) {
          if (temp->val < min_ge) {
            min_ge = temp->val;
          }
          temp = temp->left;
        } else {
          if (temp->val > max_le) {
            max_le = temp->val;
          }
          temp = temp->right;
        }
      }
      
      // which of the two is the closest?
      if ((target - max_le) > (min_ge - target)) {
        return min_ge;
      } else {
        return max_le;
      }
    }
};