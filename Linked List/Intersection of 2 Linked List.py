"""
Intersection Point of two Linked Lists.
[https://leetcode.com/problems/intersection-of-two-linked-lists/]
Approach:
    1. Comparing each nodes of 2nd LL with whole 1st LL
        T(n) = O(N1 * N2) and S(n) = O(1)

    2. Hashing node(not values) and check exits before inserting
        T(n) = O(N1 + N2) and S(n) = O(N1 + N2)

    3. first move larger linked list head by diff in forward direction
        Now move both linked list head pointer to detect interect point
        T(n) = O(N1 + N2)  and S(n) = O(1)

    4. One pointer point 1st LL, other points 2nd LL. As reach end of LL
        point the pointer on other linked list. In this way both pointer
        travel same distance to detect point
        T(n) = O(N1+N2) and S(n) = O(1)
"""


# By travelling Both Pointers travel equal distance
# T(n) = O(N1+N2) and S(n) = O(1) 
class Solution:
    def getIntersectionNode(self,headA: ListNode,headB: ListNode)->ListNode:
        if (not headA or not headB): return None
        a, b = headA, headB
        while(a != b):
            a = a.next if a else headB
            b = b.next if b else headA
        return a
            

# Move larger linkedlist head by diff forward then traverse parallely
# T(n) = O(N1 + N2)  and S(n) = O(1)
class Solution:
    def getIntersectionNode(self,headA: ListNode,headB: ListNode)->ListNode:
        n1 = n2 =0
        curr1, curr2 = headA, headB
        while(curr1 or curr2):
            if(curr1):
                n1 +=1
                curr1 = curr1.next
            if(curr2):
                n2 +=1
                curr2 = curr2.next
         
        if (not n1 or not n2): return None
        if n1>n2:
            while(n1!=n2):
                n1-=1
                headA=headA.next
        elif n1<n2:
            while(n1!=n2):
                n2-=1
                headB=headB.next
                
        while(headA != headB):
            headA=headA.next
            headB=headB.next
        return headA
                


        
