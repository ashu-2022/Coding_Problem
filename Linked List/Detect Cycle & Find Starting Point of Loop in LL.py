"""
Find the starting point of the loop in Linked List 
[https://leetcode.com/problems/linked-list-cycle-ii/]
Approach :
    1. Using Hashing (or dict)
    check node(not value) present in hash before inserting
        T(n) = O(N) and S(n) = O(N)

    2. Using Slow, Fast Pointer
        T(n) = O(N) and S(n) = O(1)

"""

# Using Slow, Fast Pointer
# T(n) = O(N) and S(n) = O(1)
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = fast = head
        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next
            if (slow == fast):
                start=head
                while(start != slow):
                    start = start.next
                    slow = slow.next
                return start
        return None
        
    
# Using Hashing
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        s=set()
        while head:
            if head in s:
                return head
            s.add(head)
            head=head.next
        return None
