/*
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
*/


// Rotate a Linked List
// T(n) = O(N) and S(n) = O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode *tail = head, *newhead;
        int length = 1;
        while(tail->next){
            tail = tail->next;
            length++;
        }
        k = k % length ;
        if (k==0) return head;
        tail->next = head;
        for(int i=0; i<length-k-1; i++){
            head = head->next;
        }
        newhead = head->next;
        head->next = NULL;
        return newhead;
    }
};


// Rotate a Linked List Using Stack
// T(n) = O(N) and S(n) = O(N)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        stack<ListNode *> st;
        ListNode *temp = head, *top, *newhead, *tail;

        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        int size = st.size();
        k = (k % size) ;
        if (k==0) return head;

        while(k--){
            st.pop();
        }
        top = st.top();
        tail = newhead = top->next;
        top->next = NULL;

        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;
        return newhead;
    }
};
