#include <iostream>
using namespace std;
struct Node {
    Node* prev;
    int info;          //[prev][info][next]
    Node* next;
};

void inisialisasi(Node *&list1);
bool isEmpty(Node* list1);
Node* createNode(int data);
void insertList(Node* &list1, int data);
void display(Node* list1);

int main(int argc, char const *argv[]) {
    //Deklarasi    
    Node* list;
    int i, n, x;
    //Algoritma    
    inisialisasi(list);    
    display(list);    
        
    cout<<"Banyak Data ? : ";cin>>n;
    for(i=1;i<=n;i++) {
        cout<<"Data ke-"<<i<<" : ";cin>>x;
        insertList(list, x);
        display(list);
    }
    return 0;
}
//inisialisasi
void inisialisasi(Node *&list1) {
    list1 = NULL;                
}
//cek isi list
bool isEmpty(Node* list1) {
    if(list1 == NULL) return true;
    else return false;
}
//createNode
Node* createNode(int data) {
    //Deklarasi
    Node* newNode;
    //Algoritma
    newNode = new Node;
    newNode->info = data;   //[prev][info][next] => [?][data][?]
    newNode->prev = NULL;   //[?][data][?] => [NULL][data][?]
    newNode->next = NULL;   //[NULL][data][?] =? [NULL][data][NULL]
    return newNode;
}
void insertList(Node* &list1, int data) {
    //Deklarasi
    Node* newNode;    
    //Algoritma
    newNode = createNode(data);    
    if(list1==NULL) {   //list == NULL ? => [][][]
        list1 = newNode;        //[NULL][data][NULL]
    } else {                    //                                                          
        list1->prev = newNode;  //list1.prev -> newNode
        newNode->next = list1;  //newNode.next -> list      ===>   newNode.next <=> list1.prev
        list1 = newNode;                 
    } 
}
void display(Node *list1) {
    //Deklarasi
    Node* temp;
    //Algoritma
    cout<<"List : ";
    if(isEmpty(list1)) {
        cout<<"[Data Kosong]";
    } else {
        temp = list1;
        while(temp!=NULL) {
            cout<<temp->info<<" ";            
            temp = temp->next;
        }
    }    
    fflush(stdin);
    cout<<"\nTekan Enter Untuk Lanjut...";getchar();cout<<endl;
}

