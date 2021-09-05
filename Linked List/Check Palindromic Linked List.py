"""
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
"""

# Reversed first half == Second half?
# Phase 1: Reverse the first half while finding the middle.
# Phase 2: Compare the reversed first half with the second half.
# T(n) = O(N)  and S(n) = O(1)
class Solution:
    def mid(self,head):
        slow=head
        fast=head.next
        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next
        return slow
    
    def reverse(self,head):
        prev=None
        curr=head
        while(curr):
            nxt=curr.next
            curr.next=prev
            prev=curr
            curr=nxt
        return prev
    
    def isPalindrome(self, head:[ListNode]) -> bool:
        mid=self.mid(head)
        tail=self.reverse(mid.next)
        mid.next = None
        while(head and tail):
            if (head.val != tail.val):
                return False
            head = head.next
            tail = tail.next
        return True

    

# Solution 1: Reversed first half == Second half?
# Phase 1: Reverse the first half while finding the middle.
# Phase 2: Compare the reversed first half with the second half.

def isPalindrome(self, head):
    rev = None
    slow = fast = head
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, slow = slow, rev, slow.next
    if fast:
        slow = slow.next
    while rev and rev.val == slow.val:
        slow = slow.next
        rev = rev.next
    return not rev
