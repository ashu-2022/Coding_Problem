/*
Remove Nth Node From End of List [https://leetcode.com/problems/remove-nth-node-from-end-of-list/]
Approach :
    1. Iterative using 2-passes to count total no of nodes
    then sub 'n' from total    T(n) = O(2N) and S(n) = O(1)

    2. Iteration using Single Pass, First move one pointer 
    by N-nodes ahead    T(n) = O(N) and S(n) = O(1)

    3. Iterative using Stack(pop n-node from top of stack)
        T(n) = O(N) and S(n) = O(N)

*/


// Remove Nth Node From End of List
// Iterative using 2-Passes(or times)
// T(n) = O(2N) and S(n) = O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode *temp = head, *newhead = head;
        while(temp){
            count++;
            temp=temp->next;
        }
        // if 1st Node Remove (Handle Corner Case)
        if(count==n){
            return head->next;
        }
        for(int i=1;i<count-n;i++){
            head=head->next;        
        }
        head->next=head->next->next;
        return newhead;
    }
};


// Remove Nth Node From End of List
// First move one pointer by N-nodes ahead
// T(n) = O(N) and S(n) = O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head , *newhead = head;
        while(temp && n){
            n--;
            temp = temp->next;
        }
        if(!temp) return head->next;
        while(temp->next){
            temp = temp->next;
            head = head->next;
        }
        head->next = head->next->next;
        return newhead;
    }
};



// Remove Nth Node From End of List
// Iterative using Stack
// T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode *> st;
        ListNode *newhead = head, *temp;
        while(head){
            st.push(head);
            head = head->next;
        }
        while(n && !st.empty()){
            st.pop();
            n--;
        }
        if (st.empty()) return newhead->next;
        temp = st.top();
        temp->next = temp->next->next;
        return newhead;
    }
};

