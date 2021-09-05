"""
Merge Two Sorted Lists
[https://leetcode.com/problems/merge-two-sorted-lists/]
Approach:
    1. By Pointing LinkedList by pointer,comparing values and create a 
        dummy node of smaller pointer value before moving forward
        T(n) = O(M+N) and S(n) = O(M+N)

    2. By create a dummy Node then simple Follow Merge Method and 
        update node in each iteration.
        T(n) = O(M+N) and S(n) = O(1)

    3. By using Recursion but it give stackoveflow when list too long
        T(n) = O(M+N) and S(n) = O(M+N)

"""

# Merge Two Sorted Lists by itertion 2-Pointer
# T(n) = O(M+N) and S(n) = O(1)
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        mergehead = dummy = ListNode(0)
        while(l1 and l2):
            if (l1.val <= l2.val):
                dummy.next = l1
                l1 = l1.next
            else:
                dummy.next = l2
                l2 = l2.next
            dummy = dummy.next

        dummy.next = l1 or l2
        return mergehead.next



# Recursive Method 
# stack will overflow while the list is too long
# T(n) = O(M+N) and S(n) = O(M+N)
def mergeTwoLists2(self, l1, l2):
    if not l1 or not l2:
        return l1 or l2
    if l1.val < l2.val:
        l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
    else:
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2
      
      
