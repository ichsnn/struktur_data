#include <iostream>

using namespace std;

//TIPE DATA STRUKTUR (SINGLE LINKED LIST)
struct Node {
    int info;
    Node *next;
};


//PURWARUPA PROSEDURE ATAU FUNGSI YANG AKAN DIGUNAKAN
void inisialisasi(Node *&list1);
Node *createNode(int data);
bool isEmpty(Node *list1);
void display(Node *list1);
int size(Node *list1);
Node *getFirst(Node *list1);
Node *getLast(Node *list1);
Node *get(Node *list1, int x);

/* PROGRAM UTAMA */
int main() {    
    system("cls");
    //Deklarasi
    Node *list;
    Node *a, *b, *c;    

    //Algroitma
    inisialisasi(list); //inisialisasi linked list
    cout<<"Panjang List : "<<size(list)<<endl;
    display(list);

    a = createNode(9);
    b = createNode(3);
    c = createNode(7);

    list = a;
    list->next = b;
    list->next->next = c;

    cout<<"Panjang List  : "<<size(list)<<endl;
    cout<<"Data di Awal  : "<<getFirst(list)->info<<endl;   //data di indeks pertama
    cout<<"Data di i-2   : "<<get(list, 2)->info<<endl;     //data di indeks-2
    cout<<"Data di Akhir : "<<getLast(list)->info<<endl;    //data di indeks terakhir
    display(list);

    return 0;
}

//PROSEDURE DAN FUNGSI
void inisialisasi(Node *&list1) {
//inisialisasi linked list
    list1 = NULL;
}

Node *createNode(int data) {
//membuat node baru    
    //Deklarasi
    Node *newNode = new Node;
    //Algoritma
    newNode->info = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Node* list1) {
//cek isi linked list    
    if(list1==NULL) {
        return true;
    } else return false;
}

void display(Node* list1) {
//tampilkan semua linked list    
    //DEKLARASI
    Node *temp;    
    cout<<"List : " ;
    if(!isEmpty(list1)) {
        temp = list1;
        while(temp!=NULL) {
            cout<<temp->info<<" ";
            temp = temp->next;            
        }
    } else cout<<"[List Kosong]";
    cout<<endl;
    cout<<"Tekan Enter Untuk Melanjutkan...";getchar();cout<<endl;
}

int size(Node *list1) {
//hitung panjang linked list    
    //DEKLARASI
    Node *temp;
    int count;
    //ALGORITMA
    count = 1;
    if(!isEmpty(list1)) {
        temp = list1;        
        while(temp->next!=NULL) {
            count++;
            temp = temp->next;
        }
        return  count;
    } else return 0;
}

Node *getFirst(Node *list1) {
//Nilai linked list di awal
    return list1;    
}

Node *getLast(Node *list1) {
//Nilai linked list di akhir
    //DEKLARASI
    Node *temp;
    //ALGORITMA
    if(!isEmpty(list1)) {
        temp = list1;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        return temp;        
    } else return NULL;
}

Node *get(Node *list1, int x) {
//Nilai linked list di tengah
    //DEKLARASI
    Node *temp;
    int counter;
    //ALGORITMA
    if(isEmpty(list1) || x<1 || x>size(list1)) {
        return NULL;
    } else {
        temp = getFirst(list1);
        counter = 1;
        while(counter<x) {
            temp = temp->next;         
            counter++;;
        } return temp;
    }
}