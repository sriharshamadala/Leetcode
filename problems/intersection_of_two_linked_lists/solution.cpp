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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Move equally on A and B until one hits tail
        ListNode * ptr_a = headA;
        ListNode * ptr_b = headB;
        while ((ptr_a != NULL) && (ptr_b != NULL)) {
            ptr_a = ptr_a->next;
            ptr_b = ptr_b->next;
        }
        
        // Depending on whether A or B reched NULL first, start another pointer from head.
        ListNode * tmp_ptr1, *tmp_ptr2, *curr_ptr;
        if (ptr_a != NULL) {
            tmp_ptr1 = headA;
            tmp_ptr2 = headB;
            curr_ptr = ptr_a;
        } else {
            tmp_ptr1 = headB;
            tmp_ptr2 = headA;
            curr_ptr = ptr_b;
        }
       
        while (curr_ptr != NULL) {
            curr_ptr = curr_ptr->next;
            tmp_ptr1 = tmp_ptr1->next;
        }
        
        while ((tmp_ptr1 != tmp_ptr2) && (tmp_ptr1 != NULL)) {
            tmp_ptr1 = tmp_ptr1->next;
            tmp_ptr2 = tmp_ptr2->next;
        }
        
        return tmp_ptr1;
    }
};