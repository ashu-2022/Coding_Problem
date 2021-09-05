/*
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

*/

// Merge K Sorted Linked List (Sol-->Merge lists one by one)
// Convert merge k lists problem to merge 2 lists (k-1) times.
// T(n) = O(kN) and S(n) = O(1)
class Solution{   
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
        


// Merge K Sorted Linked List --> store nodes value in array 
// create new linked list by traversing over sorted array
// T(n) = O(NlogN) and S(n) = O(N)
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



// Divide and Conquer Approach (MergeSort)
// T(n) = O(Nlogk) and S(n) = O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partition(lists, 0, lists.size()-1);
    }
    
    ListNode* partition(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];

        if(start < end){
            int mid = (end+start)/2;
            ListNode* l1 = partition(lists, start, mid);
            ListNode* l2 = partition(lists, mid+1, end);
            return merge(l1, l2);
        }
        return NULL;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};


/*
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
*/

// Priority Queue (Uses MinHeap)
// T(n) = O(NlogK) and S(n) = O(K)
class Solution {
public:
    struct compare{
        bool operator()(ListNode* &a,ListNode* &b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minh;
        for(int i=0;i<lists.size();i++)
        {
           if(lists[i]!=NULL) minh.push(lists[i]);
        }
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(minh.size()>0)
        {
            ListNode* p=minh.top();
            minh.pop();
            temp->next=new ListNode(p->val);
            temp=temp->next;
            if(p->next!=NULL) minh.push(p->next);
        }
        return head->next;
    }
};



class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min priority queue
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        
        for(int i = 0; i < lists.size(); i++)
            if(lists[i] != nullptr) 
                q.push(lists[i]);
        ListNode* dummy = new ListNode(0);
        ListNode* cursor = dummy;
        while(!q.empty()){
            ListNode* curr = q.top();
            q.pop();
            if(curr->next != nullptr) q.push(curr->next);
            cursor->next = curr;
            cursor = curr;
        }
        return dummy->next;
    }
}
