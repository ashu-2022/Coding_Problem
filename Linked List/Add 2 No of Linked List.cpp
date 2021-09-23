/*
Add two numbers represented by linked lists
[https://leetcode.com/problems/add-two-numbers-ii/]
Approach:
first reverse both no to get tail, then after calculate sum
reverse the sum to return ans.
 1. By transversing LL convert nodes value in Numbers then do 
    Arithmetic Addition. Create new linked list node to 
    represent sum   T(n) = O(2(N1+N2)) and S(n) = O(N1+N2) 

 2. Keep track of the carry using a variable and simulate 
    digits-by-digits sum starting from the head of lists
    by creating new linked-list node
    T(n) = O(N1+N2) and S(n) = O(N1+N2)

*/

// Add Two Numbers of Linked List
// T(n) = O(N1 + N2) and S(n) = O(N1 + N2)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *tail1 = reverse(l1);
        ListNode *tail2 = reverse(l2);
        ListNode *newhead = new ListNode(0);
        ListNode *temp = newhead;
        int carry = 0;
        while(tail1 || tail2 || carry){
            if(tail1){
                carry += tail1->val;
                tail1 = tail1->next;
            }
            if(tail2){
                carry += tail2->val;
                tail2 = tail2->next;
            }
            temp->next = new ListNode(carry%10);
            temp = temp->next;
            carry = carry/10;
        }
        return reverse(newhead->next);
    }
    
private:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *prev = NULL, *nxt ;
        while(head){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
};
