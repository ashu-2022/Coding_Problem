"""
Rotate a Linked List [https://leetcode.com/problems/rotate-list/]
Approach :
    1. K-times remove the last node and add it to 1st place
        T(n) = O(NK) and S(n) = O(1)

    2. Push all nodes of LL in stack, pop k-times nodes then 
        shifting the link to give ans 
        T(n) = O(N) and S(n) = O(N)
    
    3. Count Total length and update k = k % length , link tail
    node to head , move head to (length-k) times then break by 
    link Null   T(n) = O(N) and S(n) = O(1)

"""

# Rotate a Linked List by move ahead by (length-k) nodes
# T(n) = O(N) and S(n) = O(1)
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if (not head): return head
        length , tail = 1 , head
        
        # Calc Length of LL
        while(tail.next):
            tail = tail.next
            length +=1
        k = k%length
        if (k==0): return head
        tail.next = head
        
        # Find the node where rotate
        for _ in range(length-k-1):
            head = head.next
        newhead = head.next
        head.next = None
        return newhead



# Rotate a Linked List Using Stack
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if (not head or k==0): return head
        stack, temp = [], head
        while(temp):
            stack.append(temp)
            temp = temp.next
        size = len(stack)
        k = (k % size)
        if (k==0): return head
        
        while(k):
            stack.pop()
            k -=1
        top = stack[-1]
        tail = newhead = top.next
        top.next = None
        
        while(tail.next):
            tail = tail.next
        tail.next = head
        return newhead
