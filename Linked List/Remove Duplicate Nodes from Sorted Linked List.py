"""
Remove duplicates from Sorted Linked List
[https://leetcode.com/problems/remove-duplicates-from-sorted-list/]
Approach : 
    1. Using Hashing, Set
        T(n) = O(N) and S(n) = O(N)

    2. By comparing adjacent node values, skip nodes
        while(curr.next and curr.val==curr.next.val)
        T(n) = O(N) and S(n) = O(1)

"""

# Remove Duplicates in a sorted Linked List.
# T(n) = O(n) and S(n) = O(1)
class Solution:
    def deleteDuplicates(self, head):
        cur = head
        while cur:
            # skip duplicated node
            while (cur.next and cur.next.val == cur.val):
                cur.next = cur.next.next
        
            cur = cur.next     
        return head


# Remove Duplicates in a sorted Linked List.
# T(n) = O(n) and S(n) = O(1)
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        cur=head
        while cur:
            if cur.next and cur.next.val==cur.val:
                cur.next=cur.next.next
            else:
                cur=cur.next
        return head


# Remove Duplicates in a sorted Linked List.
# Recursive Solution,   T(n) = O(N) and S(n) = O(N)
def deleteDuplicates(self, head):
	if not head or not head.next:
		return head
	h = self.deleteDuplicates(head.next)
	head.next = h if head.val != h.val else h.next
	return head



# Remove Duplicates in a sorted Linked List.
# Using Hashing,    T(n) = O(N) and S(n) = O(N)
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if (not head or not head.next): return head
        hashmap = set()
        newhead = temp = ListNode(0)
        while(head):
            if head.val in hashmap:
                head = head.next
            else:
                hashmap.add(head.val)
                temp.next = head 
                temp = temp.next
                head = head.next
        temp.next = None
        return newhead.next
                
                
