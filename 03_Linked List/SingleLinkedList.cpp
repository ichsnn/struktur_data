#include <iostream>

using namespace std;

struct Node {
    int info;
    struct Node *next;
};

//inisialisasi
void inisialisasi(Node* &list) {
    list = NULL;
}
Node* createNode(int info) {
    //DEKLARASI
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;    
}

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {
    //DEKLARASI    
    Node* list1;    
    Node *a, *b, *c;

    //PROGRAM
    inisialisasi(list1);
    a = createNode(9);
    b = createNode(3);
    c = createNode(7);

    list1 = a;
    list1->next = b;
    list1->next->next = c;

    cout<<list1->info<<endl;
    cout<<list1->next->info<<endl;
    cout<<list1->next->next->info<<endl;

    return 0;
}

