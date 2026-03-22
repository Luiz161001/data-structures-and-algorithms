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