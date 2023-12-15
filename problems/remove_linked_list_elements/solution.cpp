/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy_head = ListNode(0, head);

        ListNode * node = &dummy_head;
        ListNode * prev_node = node;
        node = node->next;

        while (node != nullptr) {
            if (node->val == val) {
                // Delete the node but don't move prev_node
                prev_node->next = node->next;
            }
            else {
                prev_node = node;
            }
            // Always move node
            node = node->next;
        }

        return dummy_head.next;
    }
};