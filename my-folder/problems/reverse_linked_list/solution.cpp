/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    ListNode* reverseList(ListNode* head) {
        // Iterative
        ListNode * next_node, * prev_node = NULL, * curr_node = head;
        
        while (curr_node != NULL) {
            next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        
        return prev_node;
    }
    */

    ListNode * reverseRecur (ListNode * prev, ListNode * curr) {
       if (curr == NULL) {
           return prev;
       }
       
       ListNode * next = curr->next;
       curr->next = prev;
       return reverseRecur(curr, next);
    }
    
    ListNode* reverseList(ListNode* head) {
        // Recursive
        if (head == NULL) {
            return head;
        }
        ListNode * curr = head->next;
        head->next = NULL;
        return reverseRecur(head, curr);
    }
};