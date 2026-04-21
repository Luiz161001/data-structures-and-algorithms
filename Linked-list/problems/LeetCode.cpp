#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
    public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


// 206 Reverse Linked List
ListNode* reverseList(ListNode* head) {
    ListNode *curr=head, *prev=nullptr, *next=head;

    while(next){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return curr;
}

// 141 Linked List Cycle
/**
 * This solution was not the most efficient one
 * It was the one that came up faster to my mind.
 * I will optimize it later
 */
bool hasCycle(ListNode *head) {
    ListNode *tmp = head;
    std::unordered_set<ListNode*> set;
    while(tmp){
        if(set.find(tmp->next)!=set.end())
            return true;
        set.insert(tmp);
        tmp=tmp->next;
    }
    return false;
}

// 2 Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *newList= new ListNode(0), *tail=newList;
    while(l1 || l2 || carry!=0){
        int sum = carry;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        ListNode *newNode = new ListNode(sum%10);
        carry = sum/10;    
        tail->next=newNode;
        tail=tail->next;
    }  
    ListNode *answer = newList->next;
    delete newList;
    return answer; 
}

// 83 Remove Duplicates from Sorted List
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *newList= new ListNode(head->val), *dummie=newList;
    int cur = head->val;
    while(head){
        if(head->val!=cur){
            cur = head->val;
            dummie->next= new ListNode(cur);
            dummie=dummie->next;
        }
        head=head->next;
    }
    return newList;
}

// 708 Insert into a Sorted Circular LinkedList
Node* insert(Node* head, int insertVal) {
    if(!head){
        Node *newList = new Node(insertVal);
        newList->next=newList;
        return newList;
    }
    Node *tmp = head;
    while(tmp->next!=head){
        if(tmp->val > tmp->next->val){
            if(insertVal >= tmp->val || insertVal <= tmp->next->val) break;
        }
        if(tmp->val <= insertVal && insertVal <= tmp->next->val) break;  
        tmp = tmp->next;
    }
    tmp->next = new Node(insertVal, tmp->next);
    return head;
}


// 24 Swap Nodes in Pairs
ListNode* swapPairs(ListNode* head) {
    ListNode *tmp = head;
    while(tmp){ 
        if(tmp && tmp->next){
            int temp = tmp->val;
            tmp->val = tmp->next->val;
            tmp->next->val = temp;
        }
        if(tmp->next)
            tmp=tmp->next->next;
        else
            tmp=tmp->next;
    }
    return head;
}

// 19 Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int len=0;
    ListNode *tmp=head;
    while(tmp){
        len++;
        tmp=tmp->next;
    }
    len-=n;
    tmp=dummy;
    while(len>0){
        len--;
        tmp=tmp->next;
    }
    tmp->next=tmp->next->next;
    return dummy->next;
}

// 82 Remove Duplicates from Sorted List II
// Reviewwww
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *sentinel = new ListNode(0,head);
    ListNode *pred = sentinel;
    while(head){
        if(head->next && head->val==head->next->val){
    while(head->next && head->val==head->next->val){
        head=head->next;
    }
    pred->next=head->next;
        }
        else{
    pred=pred->next;
        }
        head=head->next;
    }
    return sentinel->next;
}

// 141 Linked List Cycle 
// Better solution - Floyd's Cycle Finding Algorithm
bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(slow!=fast){
        if(fast==nullptr || fast->next==nullptr) return false;
        slow=slow->next;
        fast=fast->next->next;
    }
    return true;
}