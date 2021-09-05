/*
Reverse Linked List. (Both Iterative and recursive)
    [https://leetcode.com/problems/reverse-linked-list/]
Approach:
    1. Iterative by 2-Pointer T(n) = O(N) and S(n) = O(1)

    2. Using Recursion T(n) = O(N) and S(n) = O(N)

    3. Iterative using Stack T(n) = O(N) and S(n) = O(N)
*/

//Iterative by 2-Pointer T(n) = O(N) and S(n) = O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL, *curr=head, *nxt;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};



// Using Recursion T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL; 
        return temp;   
    }
};



// Iterative using Stack T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        stack<ListNode *> st;
        ListNode* curr = NULL;
        while(head->next){
            st.push(head);
            head = head->next;
        }
        while(!st.empty()){
            curr = st.top();
            st.pop();
            curr->next->next = curr;
            curr->next = NULL;
        }
        return head;
    }
};
