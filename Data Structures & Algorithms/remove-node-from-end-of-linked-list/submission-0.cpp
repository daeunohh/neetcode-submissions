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

// two pointer
// tail = tail 
// n_1th = n-1th node from the current tail 

// time complexity O(N)
// space complexity o(1) 

// N = 3      
//  n       t   
//  1 2 3 4 5  

// initially 
// tail = head 
// n_1th = head 
// increase tail n+1 times

// if already at the real tail
// return n_1th->next;

// in loop to the end of the list 
// increase tail 1 time 
// increase n_1th 1 time 

// remove nth node 
// np1th = n_1th->next->next // n+1th node 
// n_1th->next = np1th 

// return head 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        ListNode* n_1th = head;

        for(int i=0;i<n+1;i++){
            if(tail == NULL){
            return head->next;
        }
            tail = tail->next;
        }
        
        while(tail != NULL){
            tail = tail->next;
            n_1th = n_1th->next;
        }

        ListNode* np1th = n_1th->next->next;
        n_1th->next = np1th;

        return head;
    }
};
