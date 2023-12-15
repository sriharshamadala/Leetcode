/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // 0 nodes
        if (head == nullptr) {
            Node* new_head = new Node(insertVal);
            new_head->next = new_head;
            return new_head;
        }

        // 1 node
        if (head->next == head) {
            Node* new_head = new Node(insertVal);
            head->next = new_head;
            new_head->next = head;
            return head;
        }

        // at least 2 nodes
        // find the knot by travelling until the non-decreasing order condition is broken
        // its possible all nodes are equal. If this is the case, we can insert anywhere.
        Node* curr = head;
        while (curr->next != head) {
            if (curr->val > curr->next->val) {
                break;
            }
            curr = curr->next;
        }
        //cout << "found knot " << curr->val << endl;

        // compare with the knot
        if (insertVal >= curr->val) {
            // insert after the knot
            Node* new_node = new Node(insertVal, curr->next);
            curr->next = new_node;
        }
        else {
            // travel the list and find the right location
            Node* prev = curr;
            curr = curr->next;
            while (insertVal > curr->val) {
                prev = curr;
                curr = curr->next;
            }
            Node* new_node = new Node(insertVal, curr);
            prev->next = new_node;
        }

        return head;
    }
};