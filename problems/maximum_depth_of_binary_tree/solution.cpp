/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
class Solution {
    
public:
    struct TreeNodeList {
        TreeNode * NodePointer;
        int depth;
        TreeNodeList * next;
    };
    int maxDepth(TreeNode *root) {
        TreeNodeList * head = new TreeNodeList;
        TreeNodeList * tail;
        TreeNodeList * temp1;
        int maxDepth = 0;
        
        if (root == NULL)
            return maxDepth;
        else {
            head->NodePointer = root;
            head->depth = 1;
            head->next = NULL;
            tail = head;
    
            while(head != NULL) {
                // add the children of head to the list
                if (head->NodePointer->left != NULL) {
                    temp1 = new TreeNodeList;    // create new element in the list
                    temp1->NodePointer = head->NodePointer->left;
                    temp1->depth = head->depth + 1;
                    temp1->next = NULL;
                    tail->next = temp1;
                    tail = temp1;
                }
                if (head->NodePointer->right != NULL) {
                    temp1 = new TreeNodeList;    // create new element in the list
                    temp1->NodePointer = head->NodePointer->right;
                    temp1->depth = head->depth + 1;
                    temp1->next = NULL;
                    tail->next = temp1;
                    tail = temp1;
                }
                // dequeue the head
                maxDepth = tail->depth;
                head = head->next;
            }
        }
        return maxDepth;
    }
};