/*
Skip Duplicate nodes from Sorted Linked List
[https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/]
Approach:
    1. Store the count of nodes value in map or dict
       skip those whose (count > 1)
       T(n) = O(N) and S(n) = O(N)

    2. By Pointer, skip Duplicate nodes
        T(n) = O(N) and S(n) = O(1)

*/



// Skip Duplicate nodes from Sorted Linked List
// T(n) = O(N) and S(n) = O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)  return head;
        ListNode *prev = new ListNode(0, head);
        ListNode *newhead = prev;
        while(head){
            if (head->next && head->val == head->next->val){
                // skip duplicates nodes 
                while(head->next && head->val == head->next->val){
                    head = head->next;
                }
                prev->next = head->next;
            }else{
                prev = prev->next;
            }
            head = head->next;
        }
        return newhead->next;
    }
};




// Recursive Solution
class Solution {
public:
    ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        
        if (head.next != null && head.val == head.next.val) {
            while (head.next != null && head.val == head.next.val) {
                head = head.next;
            }
            return deleteDuplicates(head.next);
        } else {
            head.next = deleteDuplicates(head.next);
        }
        return head;
    }
}




// Skip Duplicate nodes from Sorted Linked List
// Store count of nodes value in dict or map
// T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)  return head;
        unordered_map<int, int> hashmap;
        ListNode *temp = head;
        while(temp){
            hashmap[temp->val]++;
            temp = temp->next;
        }

        ListNode *curr = new ListNode(0);
        ListNode *newhead = curr;
        while(head){
            while(head && hashmap[head->val]>1){
                head = head->next;
            }
            curr->next = head;
            curr = curr->next;
            head = head ? head->next : NULL;
        }
        return newhead->next;
    }
};
