#include <iostream>
#define MAX_ELEMENT_STACK 100
using namespace std;

struct TStack {
    int element[MAX_ELEMENT_STACK];
    int top;
};

//Deklarasi Purwarupa Fungsi Atau Prosedur yang Akan Digunakan
void init(TStack &stack);
bool isEmpty(TStack stack);
bool isFull(TStack stack);
//PROGRAM UTAMA
int main() {
    //Deklarasi
    TStack stack;
    //Algoritma
    init(stack);    //inisialisasi
    isEmpty(stack) ? cout<<"Kosong\n":cout<<"Isi\n";
    cout<<endl;
    stack.top++;
    isFull(stack) ? cout<<"Penuh\n":cout<<"Tidak Penuh\n";
    isEmpty(stack) ? cout<<"Kosong\n":cout<<"Isi\n";
    stack.top = 100;
    cout<<endl;
    isEmpty(stack) ? cout<<"Kosong\n":cout<<"Isi\n";
    isFull(stack) ? cout<<"Penuh\n":cout<<"Tidak Penuh\n";

    return 0;
}

void init(TStack &stack) {       //nilai stack atau element dimulai dari index - 1
//inisialisasi stack
    stack.top = 0;
}

bool isEmpty(TStack stack) {
    return stack.top == 0;
}

bool isFull(TStack stack) {
    return stack.top == MAX_ELEMENT_STACK;
}