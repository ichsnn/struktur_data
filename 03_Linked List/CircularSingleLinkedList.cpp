#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
};

//-----------------------------------------------------------------
//Deklarasi Purwarupa Prosedure atau Fungsi
void init(Node* &list);
bool isEmpty(Node* list);
int size(Node* list);
Node* createNode(int data);
void insertAtFirst(Node* &list, int data);
void display(Node* list);
Node* getFirst(Node* list);
Node* get(Node* list, int posisi);
Node* getLast(Node* list);
void insertAtLast(Node* &list, int data);
void insert(Node* &list, int data, int posisi);

//-----------------------------------------------------------------

//PROGRAM UTAMA
int main() {
    system("cls");
    //Deklarasi
    Node* head;
    //Algoritma    
    init(head);
    display(head);
    cout<<"Size : "<<size(head)<<endl;
    cout<<endl;
    insertAtFirst(head, 3);   // 3        
    insertAtFirst(head, 5);   // 5 3 
    insertAtLast(head, 2);    // 5 3 2
    insert(head, 4, 2);       // 5 4 3 2
    insert(head, 1, 4);       // 5 4 3 2 1
    display(head);
    cout<<"Size : "<<size(head)<<endl;
    cout<<endl;
    cout<<"Data di awal  : "<<getFirst(head)->info<<endl;
    cout<<"Data di index : "<<get(head, 2)->info<<endl;
    cout<<"Data di akhir : "<<getLast(head)->info<<endl;    
    return 0;
}

//-----------------------------------------------------------------
//Prosedure atau Fungsi

void init(Node* &list) {
//inisialisasi
    list = NULL;
}
bool isEmpty(Node* list) {
//cek isi list   
    if(list == NULL) return true;
    else return false;
}
int size(Node* list) {
//hitung panjang atau banyak list    
    //Deklarasi
    Node* temp;
    int count;
    //Algoritma
    if(!isEmpty(list)) {
        count = 1;
        temp = list;        
        while(temp->next!=list) {
            count++;
            temp = temp->next;
        }
        return count;
    } else return 0;
}
Node* createNode(int data) {
//membuat node baru
    //Deklarasi
    Node* newNode;
    //Algoritma
    newNode = new Node;
    newNode->info = data;
    newNode->next = NULL;
    return newNode;
}
Node* getFirst(Node* list) {
//ambil data di awal    
    return list;
}
Node* get(Node* list, int posisi) {
//ambil data di posisi tertentu
    //Deklarasi
    Node* temp;
    int count;    
    //Algoritma
    if(isEmpty(list) || posisi<1 || posisi>size(list)) {
        return NULL;
    } else {
        temp = list;
        count = 1;
        while(count<posisi) {
            temp = temp->next;
            count++;
        } return temp;
    }
}
Node* getLast(Node* list) {
//ambil data di akhir
    //Deklarasi
    Node* temp;
    if(isEmpty(list)) {
        return NULL;
    } else {
        temp = list;
        while(temp->next!=list) {
            temp = temp->next;            
        }
        return temp;
    }
}
void insertAtFirst(Node* &list, int data) {
//tambahkan data di awal
    //Deklarasi
    Node* newNode;
    Node* bantu;
    //Algoritma
    if(isEmpty(list)) {
        list = createNode(data);
        list->next = list;
    } else {
        bantu = list;
        while(bantu->next!=list) {
            bantu = bantu->next;
        }
        newNode = createNode(data);          
        newNode->next = list;
        bantu->next = newNode;
        list = newNode;                                
    }
}
void insertAtLast(Node* &list, int data) {
//tambahkan data di akhir
    //Deklaraasi
    Node* newNode;
    Node* bantu;
    //Algoritma
    if(isEmpty(list)) {
        list = createNode(data);
        list->next = list;
    } else {        
        newNode = createNode(data);          
        bantu = getLast(list);
        bantu->next = newNode;        
        newNode->next = list;                                 
    }        
}
void insert(Node* &list, int data, int posisi) {
//tambahkan data di posisi tertentu
    //Deklarasi
    Node* newNode;
    Node* nodeSisip;
    //Algoritma        
    if(posisi==1) {
        insertAtFirst(list, data);
    } else if(posisi>1 && posisi<size(list)) {
        nodeSisip = get(list, posisi-1);
        newNode = createNode(data);
        newNode->next = nodeSisip->next;
        nodeSisip->next = newNode;
    } else if(posisi == size(list)) {
        insertAtLast(list, data);
    } else cout<<"Posisi sisip tidak sah!";
}
void display(Node* list) {
//tampilkan isi list
    //Deklarasi
    Node* temp;
    Node* head;
    //Algoritma
    cout<<"List : ";
    if(!isEmpty(list)) {       
        temp = list;        
        while(temp->next != list) {            
            cout<<temp->info<<" ";
            temp = temp->next;
        }
        cout<<temp->info;        
    } else cout<<"[Data Kosong]";    
    cout<<endl;
}