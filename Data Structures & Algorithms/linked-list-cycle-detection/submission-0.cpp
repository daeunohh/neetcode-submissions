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

// -> Constraints 
// head: empty list, list w/ one node, single cycle 
// list: len 0~3000, val:-1000~1000
// true if cycle exists, false if not 

// -> Methods 
// To find a cycle in the linked list 
//  - make an array -> check if the Node is visited 
//  - * use a set -> check if the Node is visited
//      Time: O(N), Spatial:O(N) (N: # of nodes)
//  - * use two pointers -> run pointers until those two are on the same node
//      Time: O(N), Spatial:O(1) (N: # of nodes) 

// Two pointers
// s: slower (a += 1)
// f: faster (b += 2)
// loop until s == f or s/f finishes the iteration through the linked list 

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr){
            return false;
        }

        ListNode* s = head;    // slower ptr
        ListNode* f = head;    // faster ptr 

        while(1){
            if((s->next == nullptr) || (f->next == nullptr) || (f->next->next == nullptr)){
                return false;
            }
            s = s->next;
            f = f->next->next;

            if(s == f){
                return true;
            }
        }

        return false;
    }
};
