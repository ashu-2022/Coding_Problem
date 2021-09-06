/*
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
*/

// Both Pointer travels equal distance
// T(n) = O(N1+N2) and S(n) = O(1) 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a != b){
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        return a;
    }
};



// Move larger linkedlist head by diff forward then traverse parallely
// T(n) = O(N1 + N2)  and S(n) = O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *curr1 = headA, *curr2 = headB;
        int n1 =0, n2 =0;
        // count length of linked list
        while(curr1 || curr2){
            if(curr1 ){
                n1++;
                curr1 = curr1->next;
            }
            if(curr2){
                n2++;
                curr2 = curr2->next;
            }
        }
        
        // move larger linkedlist head ahead by diff
        if(n1>n2){
            while(n1 != n2){
                n1--;
                headA = headA->next;
            }
        }else{
            while(n1 != n2){
                n2--;
                headB = headB->next;
            }  
        }
        // check for intersection point
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
