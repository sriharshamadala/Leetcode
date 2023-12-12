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
    ListNode *detectCycle(ListNode *head) {
        ListNode * result = NULL;
        
        // Detect cycle
        ListNode * slow_ptr = head;
        ListNode * fast_ptr = head;
        
        do {
            if (slow_ptr != NULL) {
                slow_ptr = slow_ptr->next;
            } else {
                // No cycle since reached end.
                return result;
            }
            
            if (fast_ptr != NULL) {
                fast_ptr = fast_ptr->next;
                if (fast_ptr != NULL) {
                    fast_ptr = fast_ptr->next;
                } else {
                    // No cycle since reached end.
                    return result;
                }
            } else {
                // No cycle since reached end.
                return result;
            }
        } while (slow_ptr != fast_ptr) ;
        
        // Now start another pointer from head, it should meet the slow_ptr at the beginning of the cycle.
        ListNode * slow_ptr_2 = head;
        while (slow_ptr_2 != slow_ptr) {
            slow_ptr_2 = slow_ptr_2->next;
            slow_ptr = slow_ptr->next;
        }
        
        return slow_ptr;
    }
};