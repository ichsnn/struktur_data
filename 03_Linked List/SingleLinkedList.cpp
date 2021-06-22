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

/* PROGRAM UTAMA */
int main() {    
    system("cls");
    //Deklarasi
    Node *list;
    Node *a, *b, *c;    

    //Algroitma
    inisialisasi(list); //inisialisasi linked list
    display(list);

    a = createNode(9);
    b = createNode(3);
    c = createNode(7);

    list = a;
    list->next = b;
    list->next->next = c;

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
    if(list1==NULL) {
        return true;
    } else return false;
}

void display(Node* list1) {
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