"""
Skip Duplicate nodes from Sorted Linked List
[https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/]
Approach:
    1. Store the count of nodes value in map or dict
       skip those whose (count > 1)
       T(n) = O(N) and S(n) = O(N)

    2. By Pointer, skip Duplicate nodes
        T(n) = O(N) and S(n) = O(1)

"""

# Skip Duplicate nodes from Sorted Linked List
# T(n) = O(N) and S(n) = O(1)
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if(not head or not head.next): return head
        newhead = prev = ListNode(0, head)
        while head:
            if (head.next and head.val == head.next.val):  
                # Skip Duplicates Nodes
                while(head.next and head.val == head.next.val):
                    head = head.next
                prev.next = head.next
            else:
                prev = prev.next
            
            head = head.next
        return newhead.next



# Skip Duplicate nodes from Sorted Linked List
# Store count of nodes value in dict or map
# T(n) = O(N) and S(n) = O(N)
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if(not head or not head.next): return head
        hashmap, temp = {}, head
        while(temp):
            if temp.val in hashmap:
                hashmap[temp.val] += 1
            else:
                hashmap[temp.val] = 1
            temp = temp.next
        
        newhead = curr = ListNode(0)
        while(head):
            while(head and hashmap[head.val] > 1):
                head = head.next
            curr.next = head
            curr = curr.next
            if head:
                head = head.next
        return newhead.next
                
