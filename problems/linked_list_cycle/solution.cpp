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
    bool hasCycle(ListNode *head) {
        bool result = false;
        if (head == NULL) return result;
        
        ListNode * slow_ptr = head;
        ListNode * fast_ptr = head->next;
        while ((fast_ptr != NULL) && (slow_ptr != NULL)) {
            if (fast_ptr == slow_ptr) {
                result = true;
                break;
            }
            fast_ptr = fast_ptr->next;
            if (fast_ptr == NULL) {
                break;
            } else {
                fast_ptr = fast_ptr->next;
            }
            slow_ptr = slow_ptr->next;
        }
        return result;
    }
};