"""
Remove Nth Node From End of List 
[https://leetcode.com/problems/remove-nth-node-from-end-of-list/]
Approach :
    1. Iterative using 2-passes to count total no of nodes
    then sub 'n' from total    T(n) = O(2N) and S(n) = O(1)

    2. Iteration using Single Pass, First move one pointer 
    by N-nodes ahead    T(n) = O(N) and S(n) = O(1)

    3. Iterative using Stack(pop n-node from top of stack)
        T(n) = O(N) and S(n) = O(N)

"""

# Remove Nth Node From End of List
# Iterative using 2-Passes(or times)
# T(n) = O(2N) and S(n) = O(1)
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        length = 0
        newhead = temp = head
        while(temp):
            length += 1
            temp = temp.next
        length -= (n+1)
        if length < 0: return newhead.next
        while(head and length):
            length -= 1
            head = head.next
        head.next = head.next.next
        return newhead



# Remove Nth Node From End of List
# Iterative using Stack
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        stack, newhead = [], head
        while head:
            stack.append(head)
            head = head.next
            
        while stack and n:
            stack.pop()
            n-=1
        if not stack: return newhead.next
        top = stack[-1]
        top.next = top.next.next
        return newhead



# Remove Nth Node From End of List
# First move one pointer by N-nodes ahead
# T(n) = O(N) and S(n) = O(1)
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        prev = curr = head
        while(n):
            n-=1
            curr = curr.next
        if(not curr): return head.next
        while(curr.next):
            prev = prev.next
            curr = curr.next
        prev.next = prev.next.next
        return head

