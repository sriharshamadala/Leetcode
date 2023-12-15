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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode l1_dummy = ListNode(0, list1);
        struct ListNode* l1_prev = &l1_dummy;
        struct ListNode* l1_curr = l1_dummy.next;
        struct ListNode* l2_curr = list2;
        struct ListNode* temp = nullptr;

        while (l1_curr != nullptr) {
            if (l2_curr == nullptr) {
                // no more elements to insert
                break;
            }
            if (l2_curr->val >= l1_curr->val) {
                // simply move l1_curr
                l1_prev = l1_curr;
                l1_curr = l1_curr->next;
            }
            else {
                // insert l2 node into l1 and move l2
                l1_prev->next = l2_curr;
                temp = l2_curr->next;
                l2_curr->next = l1_curr;
                l1_prev = l2_curr;
                l2_curr = temp;                
            }
        }

        // Its possible we have reached end of l1, but l2 is not empty; append
        if (l2_curr != nullptr) {
            l1_prev->next = l2_curr;
        }

        return l1_dummy.next;
    }
};