"""
Middle of the Linked List                                           
[https://leetcode.com/problems/middle-of-the-linked-list/]
Approach :
    1. By Transversing linked list 2 times(or passes)
        1st time to count no of node, 
        2nd time visit (N/2) times to find middle node
        T(n) = O(2N) and S(n) = O(1)

    2. By using slow,fast pointer in single pass
        T(n) = O(N) and S(n) = O(1)

"""


# Middle of the Linked List
# Give middle node in right part in case of even nodes
# T(n) = O(N) and S(n) = O(1)
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = fast = head
        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next
        return slow
        
