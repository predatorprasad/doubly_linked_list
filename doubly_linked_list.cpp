#include<iostream>

using namespace std;

class node{
public:
    int data;
    node* prev;
    node* next;

    node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node(){
        int value = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"node of vale: "<<value<<" successfully deleted"<<endl;
    }


};

void print(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
//gives length

int getLength(node* head){
    node* temp = head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    
    return length;
}

void insertAtHead(node* &tail, node* &head, int d){

    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
}

void insertAtTail(node* &tail,node* &head, int d){

    if(tail==NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else{
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        
        tail = temp;
    }
    
}

void insertAtPosition(node* &tail, node* &head, int position, int d){
    if(position == 1){
        insertAtHead(tail,head, d);
        return;
    }

    else{
        node* temp = head;
        int cnt = 1;

        while(cnt<position-1){
            temp = temp->next;
            cnt++;
        }

        //inserting at last node
        if(temp->next==NULL){
            insertAtTail(tail, head, d);
            return;
        }
        node* nodeToInsert = new node(d);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }


}

void deleteNode(int position, node* &head){
    //deleting 1st node
    if(position == 1){
        node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting other nodes
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    node* node1 = new node(12);
    node* head = node1;
    node* tail = node1;
    //print(head);

    
    insertAtHead(tail, head, 18);
    print(head);

   
    insertAtTail(tail,head, 45);
    print(head);

    insertAtPosition(tail, head, 4, 69);
    print(head); 

    deleteNode(4, head);
    print(head);
    return 0;
}
