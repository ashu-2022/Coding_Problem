"""
Reverse Nodes in k-Group
[https://leetcode.com/problems/reverse-nodes-in-k-group/]
Approach :
    1. Iterative method using stack, Run loop k times and if nodes 
        not Null then push into stack, check size of stack if found
        less than k, then return as it otherwise link in reverse order
        by popping top element utill stack empty
            T(n) = O(N) and S(n) = O(K)

    2. count the length of LL, then find no of times loop run for 
        reversing by (length//k), in each loop call k-nodes for 
        reverse by keep track of head_prev, tail_next
            T(n) = O(2N) and S(n) = O(1)

    3. create a tail pointer, and move ahead k nodes which tell us 
        length is sufficient or not after that using 2-pointer method
        reverse in k-group,     Run in single pass
            T(n) = O(N) and S(n) = O(1)

"""

# Reverse Nodes in k-Group, Iteratively using Pointer
# T(n) = O(2N) and S(n) = O(1), Two-Pass
class Solution:        
    def reverseKGroup(self, head:[ListNode], k) -> [ListNode]:
        no_of_nodes = 0
        head2 = head
        while (head2):
            no_of_nodes +=1
            head2 = head2.next
        newhead = dummy = ListNode(0)
        for i in range(no_of_nodes //k):
            length = k - 1
            beg = head
            while(length and head):
                length-=1
                head = head.next

            tail = head
            head = head.next
            tail.next = None
            reverse = self.reverse(beg)
            dummy.next = reverse[0] 
            dummy = reverse[1]
        if(head):
            dummy.next = head
        return newhead.next

    def reverse(self,head):
        prev = None
        tail = curr = head
        while(curr):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return [prev, tail] 


# Reverse Nodes in k-Group, Iteratively using Pointer
# T(n) = O(N) and S(n) = O(1), Single-Pass
class Solution:
    def reverseKGroup(self, head: [ListNode], k) -> [ListNode]:
        if (head == None or head.next == None or (k==1)):
            return head
        newhead = dummy= ListNode(0,head)
        curr = tail = head
        prev = None
        while tail:
            n = 0
            for i in range(k):
                if(tail):
                    n += 1
                    tail = tail.next

            if(n < k): return newhead.next
            mid = curr
            while(n):
                n -= 1
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt
            dummy.next = prev
            dummy = mid
            dummy.next = curr
        return newhead.next
        

# Reverse Nodes in k-Group, Iteratively using Stack
# T(n) = O(N) and S(n) = O(K)
class Solution:
    def reverseKGroup(self, head: [ListNode], k) -> [ListNode]:
        if (head == None or head.next == None):
            return head
        newhead = prev = ListNode(0,head)
        curr, stack = head, []
        while curr:
            for i in range(k):
                if curr:
                    stack.append(curr)
                    curr = curr.next

            if len(stack)<k:
                return newhead.next
            while(stack):
                prev.next = stack.pop()
                prev = prev.next
            prev.next=curr
        return newhead.next
        
            

                
        
