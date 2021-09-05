"""
Write a Program to reverse the Linked List. (Both Iterative and recursive)
    [https://leetcode.com/problems/reverse-linked-list/]
Approach:
    1. Iterative by 2-Pointer T(n) = O(N) and S(n) = O(1)

    2. Using Recursion T(n) = O(N) and S(n) = O(N)

    3. Iterative using Stack T(n) = O(N) and S(n) = O(N)
"""


# iterative method (using Pointer)
# T(n) = O(n) and S(n) = O(1) 
def reverseList(self, head):
    prev = None
    curr = head
    while curr:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    return prev



# recursive method
# T(n) = O(n) and S(n) = O(n) 
def reverseList_r(self, head: ListNode) -> ListNode: 
    if (not head or not head.next): 
        return head
    newhead = self.reverseList(head.next)
    head.next.next = head
    head.next = None
    return newhead



# iterative using stack
# T(n) = O(n) and S(n) = O(n) 
def reverseList(self, head):
    if not head: return None
    stack = []
    while head.next:
        stack.append(head)
        head = head.next
    
    while stack:
        curr = stack.pop()
        curr.next.next = curr
        curr.next = None
    return head


# iterative using stack
# T(n) = O(n) and S(n) = O(n)
class Solution:
    def reverseList(self, head:ListNode) ->ListNode:
        if(head == None or head.next == None):
            return head
        stack = []
        while(head):
            temp = head
            head = head.next
            temp.next = None
            stack.append(temp)
            
        reversehead = temp = stack.pop()
        while(stack):
            temp.next = stack.pop()
            temp = temp.next
        return reversehead
