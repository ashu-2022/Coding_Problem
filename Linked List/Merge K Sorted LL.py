"""
Merge K Sorted Linked List
[https://leetcode.com/problems/merge-k-sorted-lists/]
Approach :
    1. Traverse over linked lists & store nodes value into an array.
       Sort Array and Create a new sorted linked list by creating new nodes.
       T(n) = O(NlogN) and S(n) = O(N)

    2. Convert merge k lists problem to merge 2 lists (k-1) times
       Merge lists one by one,      T(n) = O(kN) and S(n) = O(1)

    3. Merge with Divide And Conquer
        T(n) = O(Nlogk) and S(n) = O(1)

    4. Add all lists in Priority Queue in form (list.val,list)
       Then pop-out smallest val, Add(list.next.val, list.next)
       untill Queue is empty,       T(n) = O(NlogK) and S(n) = O(K)


"""

# Merge K Sorted Linked List (Sol-->Merge lists one by one)
# Convert merge k lists problem to merge 2 lists (k-1) times.
# T(n) = O(kN) and S(n) = O(1)
class Solution:    
    def merge2Lists(self, head1, head2):
        newhead = dummy = ListNode(0)
        while (head1 and head2):
            if (head1.val<=head2.val):
                dummy.next = head1
                head1 = head1.next
            elif (head2.val<head1.val):
                dummy.next = head2
                head2 = head2.next
            dummy = dummy.next
        dummy.next = head1 or head2
        return newhead.next
    
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not len(lists):
            return None
        while len(lists)>1:
            head1 = lists.pop(0)
            head2 = lists.pop(0)
            newhead = self.merge2Lists(head1, head2)
            lists.append(newhead)
        return lists[0]
        


# Merge K Sorted Linked List --> store nodes value in array 
# create new linked list by traversing over sorted array
# T(n) = O(NlogN) and S(n) = O(N)
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> [ListNode]:
        nodes_list = []
        for l in lists:
            while l:
                nodes_list.append(l.val)
                l = l.next
        nodes_list.sort()
        newhead = temp = ListNode(0)
        for i in nodes_list:
            temp.next = ListNode(i)
            temp = temp.next
        return newhead.next



# Divide and Conquer Approach 
# T(n) = O(Nlogk) and S(n) = O(1)
class Solution(object):
    def mergeKLists(self, lists):
        if not lists: return None
        if len(lists) == 1: return lists[0]
        mid = len(lists) // 2
        l, r = self.mergeKLists(lists[:mid]), self.mergeKLists(lists[mid:])
        return self.merge(l, r)
    
    # Iterative Merge of 2 ll
    def merge(self, l, r):
        dummy = p = ListNode(0)
        while l and r:
            if l.val < r.val:
                p.next = l
                l = l.next
            else:
                p.next = r
                r = r.next
            p = p.next
        p.next = l or r
        return dummy.next
    
    # Recursive Merge of 2 LL
    def merge1(self, l, r):
        if not l or not r:
            return l or r
        if l.val< r.val:
            l.next = self.merge(l.next, r)
            return l
        r.next = self.merge(l, r.next)
        return r



"""
Time Complexity: O(n·log(m)) , Space Complexity: O(n)
where n is the total number of elements and m is the number of lists

Approach:

Take the first node of each of the linked lists
and add it into a heap. When you add it to the heap
add (node.val, i) where i is the ith list.

Create a dummy node head.

Pop the first node from the heap and make it the
next node in the dummy-list. Remember to add the
first node from the ith linked list into the heap
since we just removed a node from this list from the heap.

Repeat until the heap is empty.

"""
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        head = ListNode(None)
        curr = head
        h = []
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(h, (lists[i].val, i))
                lists[i] = lists[i].next
        
        while h:
            val, i = heapq.heappop(h)
            curr.next = ListNode(val)
            curr = curr.next
            if lists[i]:
                heapq.heappush(h, (lists[i].val, i))
                lists[i] = lists[i].next
        
        return head.next




from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        dummy = ListNode(None)
        curr = dummy
        q = PriorityQueue()
        for node in lists:
            if node: q.put((node.val,node))
        while q.qsize()>0:
            curr.next = q.get()[1]
            curr=curr.next
            if curr.next: q.put((curr.next.val, curr.next))
        return dummy.next


