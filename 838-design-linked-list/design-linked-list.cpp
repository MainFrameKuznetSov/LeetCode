class MyLinkedList {
public:

    struct Node
    {
        int data;
        Node* next;
        Node(int val):data(val),next(NULL){}
    };

    Node* head;

    MyLinkedList() {
        head=NULL;
    }
    
    int get(int index) {
        Node* curr=head;
        int ind=0;
        while(curr)
        {
            if(ind==index)
                return curr->data;
            ++ind;
            curr=curr->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
    }
    
    void addAtTail(int val) {
        Node* curr=head;
        Node* temp=new Node(val);
        if(!head)
        {
            head=temp;
            return ;
        }
        while(curr->next)
            curr=curr->next;
        curr->next=temp;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        int ind=0;
        Node* curr=head;
        while(curr)
        {
            if(ind==index-1)
            {
                Node* temp=new Node(val);
                temp->next=curr->next;
                curr->next=temp;
                return ;
            }
            ++ind;
            curr=curr->next;
        }
    }
    
    void deleteAtIndex(int index) {
        if(!head)
            return ;
        if(index==0)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return ;
        }
        int ind=0;
        Node* curr=head;
        while(curr && curr->next)
        {
            if(ind==index-1)
            {
                Node* temp=curr->next;
                curr->next=temp->next;
                delete temp;
                return ;
            }
            ++ind;
            curr=curr->next;
        }
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