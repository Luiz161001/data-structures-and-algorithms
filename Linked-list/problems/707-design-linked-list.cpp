class Node {
    public:
        int val;
        Node *next;

        Node() {}
        Node(int value) : val(value), next(nullptr) {}
        Node(int value, Node *nxt) : val(value), next(nxt) {}
};

class MyLinkedList {
private:
    Node *head;
    Node *tail;
public:
    MyLinkedList() : head(nullptr), tail(nullptr) {}
    
    int get(int index) {
        if(index < 0) return -1;

        Node *tmp = head;
        for(int i = 0; i < index && tmp; i++){
            tmp=tmp->next;
        }
        return tmp ? tmp->val : -1;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val, head);
        head=newNode;
        if(!tail) tail = head;
    }
    
    void addAtTail(int val) {
        Node * newNode = new Node(val);
        if(!head){
            head=tail=newNode;
            return;
        }
        tail->next = newNode;
        tail=tail->next;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0) return;
        if(index==0){
            addAtHead(val);
            return;
        }

        Node *prev = head;
        for(int i = 0; i < index - 1 && prev; i++){
            prev=prev->next;
        }
        if(!prev) return;

        Node *newNode = new Node(val, prev->next);
        prev->next = newNode;
        if(prev==tail) tail = newNode;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || !head) return;
        if(index==0){
            Node *tmp = head;
            head=head->next;
            if(tail==tmp) tail = head;
            delete tmp;
            return;
        }

        Node *prev = head;
        for(int i = 0; i < index - 1 && prev; i++){
            prev=prev->next;
        }
        if(!prev || !prev->next) return;

        Node *tmp = prev->next;
        prev->next = tmp->next;
        if(tmp==tail) tail = prev;
        delete tmp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */