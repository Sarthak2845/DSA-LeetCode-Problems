class MyLinkedList {
private:
    int val;
    MyLinkedList* next;
    int size=0;
public:
    MyLinkedList() {
        val=0;
        next=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1; 
        MyLinkedList* curr=next;
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        MyLinkedList* prev = this; // dummy head
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        MyLinkedList* node = new MyLinkedList();
        node->val = val;
        node->next = prev->next;
        prev->next = node;

        size++;

    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        MyLinkedList* prev = this;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        MyLinkedList* temp = prev->next;
        prev->next = temp->next;
        delete temp;

        size--;
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