#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int info;
    Node* next;
};

//--------------------------------------------------------------------------

//Deklarasi Purwarupa Prosedure atau Fungsi
void inisialisasi(Node* &head, Node* &tail);
Node* createNode(int data);
void insertAtHead(Node* &head, Node* &tail, int data);
void insertAtTail(Node* &tail, Node* &head, int data);
bool isEmpty(Node* list);
void displayHead(Node* head);
void displayTail(Node* tail);

//--------------------------------------------------------------------------

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {
    //Deklarasi
    Node* head1; Node* tail1;    
    inisialisasi(head1, tail1);
    displayHead(head1);
    insertAtHead(head1, tail1, 5);
    insertAtHead(head1, tail1, 7);
    insertAtHead(head1, tail1, 10);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<endl;    
    return 0;
}

//--------------------------------------------------------------------------

//Prosedure atau Fungsi

void inisialisasi(Node* &head, Node* &tail) {   
//Inisialisasi Double Linked List (1)
    head = NULL;
    tail = NULL;
}
Node* createNode(int data) {
//Membuat Node Baru (2)
    //Deklarasi
    Node* newNode;
    //Algoritma
    newNode = new Node;
    newNode->info = data;
    newNode->prev = NULL;    
    newNode->next = NULL;
    return newNode;    
}
void insertAtHead(Node* &head, Node* &tail, int data) {
//Tambah data di awal (3)
    //Deklarasi
    Node* newNode;
    //Algoritma
    newNode = createNode(data);
    if(isEmpty(head)) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtTail(Node* &tail, Node* &head, int data) {
//Tambah data di akhir (4)
    //Deklarasi
    Node* newNode;
    //Algoritma
    newNode = createNode(data);
    if(isEmpty(tail)) {
        tail = newNode;
        head = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;    
    }
}
bool isEmpty(Node* list) {
//Cek isi linked list (5)
    //Deklarasi
    if(list == NULL) return true;
    else return false;
}
void displayHead(Node* head) {
//Tampilkan data dari head (6)    
    //Deklarasi
    Node* temp;
    //Algoritma
    cout<<"List (Head) : ";
    if(isEmpty(head)) cout<<"[Data Kosong]";
    else {
        temp = head;
        while(temp != NULL) {
            cout<<temp->info<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}
void displayTail(Node* tail) {
//Tampilkan data dari tail (7)
    //Deklarasi
    Node* temp;
    //Algoritma
    cout<<"List (Tail) : ";
    if(isEmpty(tail)) cout<<"[Data Kosong]";
    else {
        temp = tail;
        while(temp != NULL) {
            cout<<temp->info<<" ";
            temp = temp->prev;
        }
    }
    cout<<endl;
}