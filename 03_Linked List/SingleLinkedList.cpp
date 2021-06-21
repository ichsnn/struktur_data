#include <iostream>

using namespace std;

//TIPE DATA STRUKTUR (SINGLE LINKED LIST)
struct Node {
    int info;
    Node *next;
};

//DEKLARASI GLOBAL
Node *list;

//PURWARUPA PROSEDURE ATAU FUNGSI YANG AKAN DIGUNAKAN
void inisialisasi();
Node *createNode(int data);
bool isEmpty();

/* PROGRAM UTAMA */
int main() {    

    //Deklarasi
    Node *a, *b, *c;    

    //Algroitma
    inisialisasi(); //inisialisasi linked list

    a = createNode(9);
    b = createNode(3);
    c = createNode(7);

    list = a;
    list->next = b;
    list->next->next = c;

    while(!isEmpty()) {
        cout<<list->info<<endl;
        list = list->next;                
    }
    
    return 0;
}

//PROSEDURE DAN FUNGSI
void inisialisasi() {
//inisialisasi linked list
    list = NULL;
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

bool isEmpty() {
    if(list==NULL) {
        return true;
    } else return false;
}