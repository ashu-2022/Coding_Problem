"""
Segregate even and odd nodes in a Link List 
[https://practice.geeksforgeeks.org/problems/segregate-even-and-odd
-nodes-in-a-linked-list5035/1]
Approach :
    1. create 2 dummy nodes, one track and link odd value nodes
        while other track and link even value nodes. in the last
        link tail of even LL to head of odd LL and return ans_head
"""

# Segregate even and odd nodes in a Link List 
# T(n) = O(N) and S(n) = O(1)
class Solution:
    def divide(self, N, head):
        # code here
        mid = odd = node()
        start = even = node()
        while(head):
            if (head.data%2 == 0):
                even.next = head
                even= even.next
            else:
                odd.next = head
                odd= odd.next
            head=head.next
        odd.next = None
        even.next=mid.next
        return start.next
