/*
Merge Two Sorted Lists
[https://leetcode.com/problems/merge-two-sorted-lists/]
Approach:
    1. By Pointing LinkedList by pointer,comparing values and create a 
        dummy node of smaller pointer value before moving forward
        T(n) = O(M+N) and S(n) = O(M+N)

    2. By create a dummy Node then simple Follow Merge Method and 
        update node in each iteration.
        T(n) = O(M+N) and S(n) = O(1)

    3. By using Recursion but it give stackoveflow when list too long
        T(n) = O(M+N) and S(n) = O(M+N)
*/

// Merge Two Sorted Lists by itertion 2-Pointer
// T(n) = O(M+N) and S(n) = O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* mergehead = temp;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else if(l1->val > l2->val){
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        temp->next = l1 ? l1 : l2;
        return mergehead->next; 
    }
};


// Recursive Solution 
// T(n) = O(M+N) and S(n) = O(M+N)
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
