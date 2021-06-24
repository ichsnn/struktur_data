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
    insertAtFirst(head, 5);
    insertAtFirst(head, 7);
    insertAtFirst(head, 2);    
    insertAtFirst(head, 8);                   
    display(head);
    cout<<"Size : "<<size(head)<<endl;
    cout<<endl;
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
void insertAtFirst(Node* &list, int data) {
//tambahkan data di awal
    //Deklarasi
    Node* newNode;
    Node* bantu;
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