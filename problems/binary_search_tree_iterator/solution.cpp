/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> my_stack_;
    // Not necessary for this algo
    TreeNode * root_;
    
    void pushLeftViewToStack (TreeNode * curr_node) {
        TreeNode * temp_node = curr_node;
        while (temp_node != NULL) {
            my_stack_.push(temp_node);
            temp_node = temp_node->left;
        }
    }
    
    BSTIterator(TreeNode *root) {
        root_ = root;
        pushLeftViewToStack(root_);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !my_stack_.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * temp_node = my_stack_.top();
        my_stack_.pop();
        int next_val = temp_node->val;
        
        pushLeftViewToStack(temp_node->right);
        return next_val;        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */