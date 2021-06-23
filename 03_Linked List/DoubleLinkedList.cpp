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
void insertAtTail(Node* &head, Node* &tail, int data);
int sizeAtHead(Node* head);
Node* getFirst(Node* head);
Node* getAtHead(Node* head, int posisi);
void insert(Node* &head, Node* &tail, int data, int posisi);
bool isEmpty(Node* list);
void displayHead(Node* head);
void displayTail(Node* tail);
void removeAtHead(Node* &head, Node* &tail);
void removeAtTail(Node* &head, Node* &tail);
void removeAt(Node* &head, Node* &tail, int posisi);
void removeAll(Node* &head, Node* &tail);
//--------------------------------------------------------------------------

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {
    system("cls");
    //Deklarasi
    Node* head1; Node* tail1;    
    inisialisasi(head1, tail1);
    displayHead(head1);
    displayTail(tail1);
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;
    cout<<endl;                 
    insertAtHead(head1, tail1, 5);    
    insertAtHead(head1, tail1, 7);
    insertAtHead(head1, tail1, 10);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;
    cout<<endl;
    insertAtTail(head1, tail1, 20);
    insertAtTail(head1, tail1, 9);
    insertAtTail(head1, tail1, 5);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;
    cout<<endl;       
    insert(head1, tail1, 19, 2);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;    
    cout<<endl;            
    removeAtHead(head1, tail1);
    removeAtTail(head1, tail1);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;    
    cout<<endl;       
    removeAt(head1, tail1, 5);    
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;        
    cout<<endl;       
    removeAt(head1, tail1, 4);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;        
    cout<<endl;       
    removeAll(head1, tail1);
    displayHead(head1);    
    displayTail(tail1);    
    cout<<"Panjang List: "<<sizeAtHead(head1)<<endl;        
    cout<<endl;       
    return 0;
}

//--------------------------------------------------------------------------

//Prosedure atau Fungsi

void inisialisasi(Node* &head, Node* &tail) {   
//Inisialisasi Double Linked List 
    head = NULL;
    tail = NULL;
}
Node* createNode(int data) {
//Membuat Node Baru 
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
//Tambah data di awal 
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
void insertAtTail(Node* &head, Node* &tail, int data) {
//Tambah data di akhir 
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
int sizeAtHead(Node* head) {
//Panjang list 
    //Deklarasi
    Node* temp;
    int counter;
    //Algoritma    
    if(!isEmpty(head)) {
        counter = 1;
        while(head->next!=NULL) {
            counter++;
            head = head->next;
        }
        return counter;
    } return 0;
}
Node* getFirst(Node* head) {
    return head;
}
Node* getAtHead(Node* head, int posisi) {
//Ambil data dari head 
    //Deklarasi
    Node* temp;
    int counter;
    //Algoritma
    if(isEmpty(head) || posisi < 1 || posisi>sizeAtHead(head)) {
        return NULL;
    } else {
        temp = getFirst(head);
        counter = 1;
        while(counter<posisi) {
            temp = temp->next;
            counter++;            
        }                 
        return temp;
    }
}
void insert(Node* &head, Node* &tail, int data, int posisi) {
//Tambah Data di Posisi Tertentu     
    //Deklarasi
    Node* newNode;    
    Node* nodeSisip;    
    int counter;
    //Algoritma
    newNode = createNode(data);    
    if(isEmpty(head)) {
        head = newNode;
        tail = newNode;
    } else if (posisi>1 && posisi<=sizeAtHead(head)) {
        nodeSisip = getAtHead(head, posisi);
        newNode->prev = nodeSisip->prev;
        newNode->next = nodeSisip;
        nodeSisip->prev->next = newNode; 
        nodeSisip->prev = newNode;
    } else cout<<"posisi tidak sah!";
}
bool isEmpty(Node* list) {
//Cek isi linked list
    //Deklarasi
    if(list == NULL) return true;
    else return false;
}
void displayHead(Node* head) {
//Tampilkan data dari head     
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
//Tampilkan data dari tail 
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
void removeAtHead(Node* &head, Node* &tail) {
//Hapus node dari head (awal)
    //Deklarasi
    Node* removedNode;
    //Agoritma
    if(sizeAtHead(head) == 1) {
        head = NULL;
        tail = NULL;        
    } else if(sizeAtHead(head) > 1) {
        removedNode = head;
        head = head->next;
        head->prev = NULL;
        delete removedNode;
    } else cout<<"Penghapusan Gagal Karena Data Kosong"<<endl;
}
void removeAtTail(Node* &head, Node* &tail) {
//Hapus node dari tail (terakhir)    
    //Deklarasi
    Node* removedNode;
    //Algoritma
    if(sizeAtHead(head) == 1) {
        head = NULL;
        tail = NULL;
    } else if(sizeAtHead(head) > 1) {
        removedNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete removedNode;
    } else cout<<"Penghapusan Gagal Karena Data Kosong"<<endl;
}
void removeAt(Node* &head, Node* &tail, int posisi) {
//Hapus node dari posisi tertentu (ambil dari head)    
    //Deklarasi
    Node* removedNode;    
    int size = sizeAtHead(head);
    //Algoritma     
    if(size == 1) {
        head = NULL;
        tail = NULL;
    } else if(size > 1) {
        if(posisi == 1) {
            removeAtHead(head, tail);        
        }            
        else if(posisi == sizeAtHead(head)) {
            removeAtTail(head, tail);
        } else if(posisi>1 && posisi<size) {
            removedNode = getAtHead(head, posisi);
            removedNode->prev->next = removedNode->next;
            removedNode->next->prev = removedNode->prev;
            delete removedNode;
        } else cout<<"Penghapusan Gagal Karena Data Tidak Ditemukan"<<endl;
    } else cout<<"Penghapusan Gagal Karena Data Kosong"<<endl;
}
void removeAll(Node* &head, Node* &tail) {    
    while(!isEmpty(head)) {
        removeAtHead(head, tail);
    }
}