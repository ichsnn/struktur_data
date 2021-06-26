#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;    
};

void init(Node* &list);
Node* createNode(int data);
Node* getTail(Node* head);
void insertAtTail(Node* &head, int data);
void display(Node* head);

//---------------------------------------
// FUNGSI PENCARIAN NODE
Node* search(Node* head, int data) {
    Node* list;
    Node* temp;
    if(head==NULL) {
        return NULL;
    } else {
        list = head;
        while(list!=NULL) {
            if(list->info == data) {
                temp = list;
            }
            list = list->next;
        }
        return temp;
    }
}
//---------------------------------------

int main(int argc, char const *argv[])
{
    //Deklarasi
    Node* head; 
    Node *a, *b, *c, *d;
    //Algoritma 
    init(head);
    insertAtTail(head, 4);
    insertAtTail(head, 2);
    insertAtTail(head, 7);
    insertAtTail(head, 5);            
    display(head);
    cout<<search(head, 7)<<" = "<<search(head, 7)->info;

    return 0;
}

void init(Node* &list) {
    list = NULL;
}
Node* createNode(int data) {
    Node* newNode;
    newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;
    return newNode;    
}
Node* getTail(Node* head) {
    Node* tail;
    Node* empty;
    if(head==NULL) {        
        return NULL;
    } else {
        tail = head;    
        while(tail->next!=NULL) {
            tail=tail->next;
        }        
        return tail;
    }
}
void insertAtTail(Node* &head, int data) {
    Node* newNode;
    Node* tail;
    newNode = createNode(data);
    if(head==NULL) {
        head = newNode;
    } else {
        tail = getTail(head);
        tail->next = newNode;
    }
}
void display(Node* head) {
    Node* temp;    
    if(head==NULL) {
        cout<<"[Data Kosong]";        
    } else {
        temp = head;
        while(temp!=NULL) {
            cout<<temp->info<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}