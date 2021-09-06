/*
Remove duplicates from Sorted Linked List
[https://leetcode.com/problems/remove-duplicates-from-sorted-list/]
Approach : 
    1. Using Hashing, Set
        T(n) = O(N) and S(n) = O(N)

    2. By comparing adjacent node values, skip nodes
        while(curr.next and curr.val==curr.next.val)
        T(n) = O(N) and S(n) = O(1)

*/



// Remove Duplicates in a sorted Linked List.
// T(n) = O(n) and S(n) = O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newhead = head;
        while(head){
            while(head->next && head->val==head->next->val){
                head->next = head->next->next;
            }
            head = head->next;
        }
        return newhead;
    }
};



// Remove Duplicates in a sorted Linked List.
// Using Hashset,    T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        set<int> st;
        ListNode *temp = new ListNode(0);
        ListNode *newhead = temp;
        while(head){
            if ( st.find(head->val) != st.end()){
                head = head->next;
            }else{
                st.insert(head->val);
                temp->next = head;
                temp = temp->next;
                head = head->next;
            }
        }
        temp->next = NULL;
        return newhead->next;
    }
};



// Recursive Method (Use Auxilliary space Stack)
// T(n) = O(N) and S(n) = O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
                
        ListNode* next = deleteDuplicates(head->next);
        if(next != NULL && head->val == next->val)
            head->next = next->next;
        return head;
    }
};
