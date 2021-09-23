/*
Segregate even and odd nodes in a Link List 
[https://practice.geeksforgeeks.org/problems/segregate-even-and-odd
-nodes-in-a-linked-list5035/1]
Approach :
    1. create 2 dummy nodes, one track and link odd value nodes
        while other track and link even value nodes. in the last
        link tail of even LL to head of odd LL and return ans_head

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Segregate even and odd nodes in a Link List 
// T(n) = O(N) and S(n) = O(1)
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(!head || !head->next) return head;
        Node *odd = new Node(0);
        Node *even = new Node(0);
        Node *start = even, *mid = odd;

        while(head){
            if (head->data % 2 == 0){
                even->next = head;
                even = even->next;
            }else{
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
        }
        odd->next = NULL;
        even->next = mid->next;
        return start->next;
    }
};
