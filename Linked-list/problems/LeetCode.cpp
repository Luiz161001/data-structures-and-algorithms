#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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