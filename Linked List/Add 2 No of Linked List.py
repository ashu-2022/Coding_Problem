"""
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

"""


# Add two numbers represented by linked lists.
# T(n) = O(max(N1,N2)) and S(n) = O(max(N1,N2))
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        ans = dummy = ListNode(0)
        while(l1 or l2 or carry):
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            dummy.next = ListNode(carry % 10)
            dummy= dummy.next
            carry = carry//10
        return ans.next


