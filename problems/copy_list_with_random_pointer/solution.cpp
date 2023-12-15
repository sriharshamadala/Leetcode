/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* prev = dummy;
        std::unordered_map<Node*, Node*> old_to_new;
        Node* ref_head = head;

        while(ref_head != nullptr) {
            // Create a new node and point prev to this.
            Node* curr = new Node(ref_head->val);
            prev->next = curr;

            old_to_new[ref_head] = curr;

            // Move the pointers
            prev = curr;
            ref_head = ref_head->next;
        }

        ref_head = head;
        while (ref_head != nullptr) {
            if (ref_head->random != nullptr) {
                old_to_new[ref_head]->random = old_to_new[ref_head->random];
            }
            ref_head = ref_head->next;
        }

        return dummy->next;
    }
};