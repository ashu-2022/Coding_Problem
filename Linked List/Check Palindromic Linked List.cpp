/*
Palindrome Linked List 
[https://leetcode.com/problems/palindrome-linked-list/]
Approach :
    1. copy value of nodes of linked list into Array then 
    check for Palindrome using start and end pointer
    T(n) = O(2N) and S(n) = O(N)


    2.Reversed Second Half == First Half ?
        step 1 : Reverse the Second half (using Pointer or stack)
                 while finding the middle.
        step 2 : Compare the reversed second half with the first half.
        T(n) = O(N)  and S(n) = O(1)
*/

// Reversed first half == Second half?
// Phase 1: Reverse the first half while finding the middle.
// Phase 2: Compare the reversed first half with the second half.
// T(n) = O(N)  and S(n) = O(1)
class Solution {
private:
    ListNode * midelement(ListNode* head){
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode * head){
        ListNode *prev = NULL, *curr = head, *nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode *start = head, *end, *mid;
        mid = midelement(head);
        end = reverse(mid->next);
        mid->next = NULL;
        while(start && end){
            if (start->val != end->val){
                return false;
            }
            start = start->next;
            end = end->next;
        }
        return true;
    }
};
