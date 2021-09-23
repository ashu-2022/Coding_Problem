"""
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

"""


# Add two numbers represented by linked lists.
# T(n) = O(max(N1,N2)) and S(n) = O(max(N1,N2))
class Solution:    
    def addTwoNumbers(self, l1, l2) -> [ListNode]:
        tail1 = self.reverse(l1)
        tail2 = self.reverse(l2)
        newhead = temp = ListNode(0)
        carry = 0
        while(tail1 or tail2 or carry):
            if tail1:
                carry += tail1.val
                tail1 = tail1.next 
            if tail2:
                carry += tail2.val
                tail2 = tail2.next
            temp.next = ListNode(carry % 10)
            temp = temp.next
            carry = carry//10
        return self.reverse(newhead.next)
    
    def reverse(self, head):
        if (not head  or not head.next): return head
        prev = None
        while head :
            nxt = head.next
            head.next = prev
            prev = head
            head = nxt
        return prev
