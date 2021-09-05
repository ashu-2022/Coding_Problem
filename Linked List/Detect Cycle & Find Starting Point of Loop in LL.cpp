/*
Find the starting point of the loop in Linked List 
[https://leetcode.com/problems/linked-list-cycle-ii/]
Approach :
    1. Using Hashing (or dict)
    check node(not value) present in hash before inserting
        T(n) = O(N) and S(n) = O(N)

    2. Using Slow, Fast Pointer
        T(n) = O(N) and S(n) = O(1)

*/

// Using Slow, Fast Pointer
// T(n) = O(N) and S(n) = O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow=head, *fast=head, *start=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                while(slow != start){
                    slow = slow->next;
                    start = start->next;
                }  
                return start;
            }
        }
        return NULL;  
    }
};



// Using Hashing
// T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        
        while(head){
            if(s.find(head)!=s.end()){
                return head;
            }
            else{
                s.insert(head);
                head=head->next;
            }
        }
        return NULL;
    }
};
