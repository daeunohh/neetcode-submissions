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

// reverse single linked list 
// return new head 
// Solution: Two pointers  
//      - traverse through the List 
//      - reverse the next pointer 
//      - Use two pointers: l, r
// l    r
// a <- b <- c <- d
// Time:O(N), Space:O(1) (N: the number of the nodes in the list) 
// save original r->next in rNextOriginal 
// switch r->next into l
// if rNextOriginal == nullptr: return r 
// else:
//      move l to r, r to rNextOriginal    

// + if loop inside the linked list: use additional data structure (set) 
//      Time: O(1), Space:O(N)  -> Time: O(N), Space:O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* l = head;
        ListNode* r = head->next;
        l->next = nullptr;
        
        while(1){                               // O(N)
            ListNode* rNextOriginal = r->next;
            r->next = l;

            if(rNextOriginal == nullptr){
                return r;
            }
            else{
                l = r;
                r = rNextOriginal;
            }
        }
    }
};
