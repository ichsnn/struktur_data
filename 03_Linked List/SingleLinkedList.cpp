#include <iostream>

using namespace std;

struct Node {
    int info;
    struct Node* next;
};

//DEKLARASI GLOBAL
Node* list;


//PURWARUPA FUNGSI ATAU PROSEDURE YANG AKAN DIGUNAKAN
void inisialisasi(Node* list1) {
//inisialisasi linked list
    list1 = NULL;
}

void createNode(int data) {
//membuat node baru    
    //DEKLARASI
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = data;
    newNode->next = list;
    list = newNode;
}

void display() {
    Node* temp = list;
    cout<<"List is : ";
    while(temp!=NULL) {
        cout<<temp->info<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {
    //DEKLARASI LOKAL
    int n;  //banyak angka (data)
    int i;  //index looping
    int x;  //nilai data baru
    //PROGRAM
    inisialisasi(list); //inisialisasi linked list  
    cout<<"Berapa banyak angka ? ";cin>>n;
    for(i=0; i<n; i++) {
        cout<<"Masukkan angka : ";cin>>x;
        createNode(x);
        display();
    }
    return 0;
}