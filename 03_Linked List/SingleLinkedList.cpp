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
void addFirst(Node *&list1, int x);
void addLast(Node *&list1, int x);
void add(Node *&list1, int x, int i);
void update(Node *&list1, int i, int x);
void removeFirst(Node *&list1);
void remove(Node *&list1, int i);
void removeLast(Node *&list1);

/* PROGRAM UTAMA */
int main() {    
    system("cls");
    //Deklarasi
    Node *list;
    Node *a, *b, *c;    

    //Algroitma
    inisialisasi(list); //inisialisasi linked list
    cout<<"Panjang List : "<<size(list)<<endl;
    display(list);  //tampilkan list

    a = createNode(9);     //buat node baru
    b = createNode(3);
    c = createNode(7);

    list = a;
    list->next = b;
    list->next->next = c;
        
    cout<<"Panjang List  : "<<size(list)<<endl;    //panjang list
    cout<<"Data di Awal  : "<<getFirst(list)->info<<endl;   //data di indeks pertama
    cout<<"Data di i-2   : "<<get(list, 2)->info<<endl;     //data di indeks-2
    cout<<"Data di Akhir : "<<getLast(list)->info<<endl;    //data di indeks terakhir
    display(list);

    //menambahkan data diawal, ditengah dan diakhir
    addFirst(list, 8);
    addLast(list, 2);
    add(list, 5, 5);
    cout<<"Panjang List  : "<<size(list)<<endl;    
    display(list);

    update(list, 1, 5);
    cout<<"Panjang List  : "<<size(list)<<endl;    
    display(list);

    removeFirst(list);  //hapus di awal
    display(list);

    remove(list, 2);    //hapus di index tertentu
    display(list);

    removeLast(list);    //hapus di index tertentu
    display(list);

    system("cls");
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

void addFirst(Node *&list1, int x) {
//Tambah data di awal
    //DEKLARASI
    Node *newNode;
    //ALGORITMA
    newNode = createNode(x);
    newNode->next = list1;
    list1 = newNode;
}

void addLast(Node *&list1, int x) {
//Tambah data di akhir    
    //DEKLARASI
    Node *newNode;
    Node *last;
    //ALGORITMA
    if(isEmpty(list1)) {
        addFirst(list1, x);
    } else {
        newNode = createNode(x);
        last = getLast(list1);
        last->next = newNode;        
    }
}

void add(Node *&list1, int x, int i) {
//Tambah data di tengah
    //DEKLARASI
    Node *newNode;
    Node *prevNode;
    //ALGORITMA
    if(i==1) {
        addFirst(list1, x);
    } else if(i>1 && i<=size(list1)) {
        prevNode = get(list1, i-1);
        newNode = createNode(x);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    } else cout<<"Posisi sisip tidak sah!";
}

void update(Node *&list1, int i, int x) {
//Update data
    //DEKLARASI
    Node *nodeUpdate;
    //ALGORITMA
    nodeUpdate = get(list1, i);
    if(nodeUpdate!=NULL) {
        nodeUpdate->info = x;         
    } else cout<<"Posisi update tidak sah!";
}

void removeFirst(Node *&list1) {
//hapus data di awal
    //DEKLARASI
    Node *first;
    //ALGORITMA
    if(!isEmpty(list1)) {
        first = getFirst(list1);
        list1 = list1->next;
        delete first;
    } else cout<<"Penghapusan Gagal Karena Data Kosong"<<endl;
}

void remove(Node *&list1, int i) {
//hapus data di index ke - ...
    //DEKLARASI
    Node *prevNode;
    Node *removeNode;
    //ALGORITMA
    if(!isEmpty(list1)) {
        if(i==1) {
            removeFirst(list1);
        } else {
            prevNode = get(list1, i-1);
            if(prevNode != NULL) {
                removeNode = prevNode->next;
                prevNode->next = removeNode->next;
                delete removeNode;
            } else {
                cout<<"Penghapusan Gagal Karena Index Tidak Ditemukan"<<endl;
            }
        }
    } else cout<<"Penghapusan Gagal Karena Index Hapus Tidak Ditemukan"<<endl;
}

void removeLast(Node *&list1) {
//hapus data di index akhir
    //DEKLARASI
    Node *last;
    Node *prevNode;    
    //ALGORITMA    
    if(!isEmpty(list1)) {
        if(size(list1) == 1){   
            removeFirst(list1);
        } else {
            prevNode = get(list1, size(list1)-1);            
            if(prevNode != NULL) {
                last = prevNode->next;
                prevNode->next = last->next;
                delete last;
            } else cout<<"Penghapusan Gagal Karena Index Tidak Ditemukan"<<endl;            
        }
    } else cout<<"Penghapusan Gagal Karena Index Hapus Tidak Ditemukan"<<endl;
}