/*
Add two numbers represented by linked lists
[https://leetcode.com/problems/add-two-numbers/]
Approach:
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
        ListNode *dummy = new ListNode(0);
        ListNode *newnode = dummy;
        int sum=0;
        while(l1||l2||sum>0){
            if(l1){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            ListNode *tempnode = new ListNode(sum%10);
            sum=sum/10;
            dummy->next = tempnode;
            dummy = dummy->next;
        }
        return newnode->next;
    } 
};
