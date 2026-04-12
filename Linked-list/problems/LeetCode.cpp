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
// It is not working to pass all of the tests
// Check it out tomorrow
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return nullptr;

    if(n==1 && !head->next){
        delete head;
        return nullptr;
    }
    
    ListNode *tmp = head;
    int count = 1;
    while(tmp){
        count++;
        tmp = tmp->next;
    }

    tmp = head;
    for(int i = 1; i < count - n - 1 && tmp; i++){
        tmp=tmp->next;
    }
    ListNode *deleted = tmp->next;
    if(!deleted) return head;

    tmp->next = deleted->next;
    delete deleted;
    return head;
}