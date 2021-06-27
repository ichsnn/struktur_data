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
int count(TStack stack);
void push(TStack &stack, int newElement);
void pop(TStack &stack);
void display(TStack stack);
int peek(TStack stack);
void empty(TStack &stack);
//PROGRAM UTAMA
int main() {
    //Deklarasi
    TStack stack;
    //Algoritma
    init(stack);    //inisialisasi
    display(stack);  //tampilkan stack
    cout<<endl;
    push(stack, 5);   //push        
    push(stack, 7);
    push(stack, 10);    
    push(stack, 3);    
    push(stack, 4);    
    display(stack);  //tampilkan stack
    cout<<endl;
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);    
    return 0;
}

void init(TStack &stack) {       
//inisialisasi stack
    stack.top = 0; //nilai stack atau element dimulai dari index - 1
}

bool isEmpty(TStack stack) {
//cek array kosong atau tidak    
    return stack.top == 0;
}

bool isFull(TStack stack) {
//cek array penuh atau tidak    
    return stack.top == MAX_ELEMENT_STACK;
}

int count(TStack stack) {
//hitung banyak elemen array    
    return stack.top;
}

void push(TStack &stack, int newElement) {
//tambah elemen stack
    if(isFull(stack)) {
        cout<<"ERROR : Data Penuh";
    } else {
        stack.top++;
        stack.element[stack.top] = newElement;
    }
}

void display(TStack stack) {
//tampilkan elemen stack   
    cout<<"Stack : "<<endl;
    if(isEmpty(stack)) {
        cout<<"[Data Kosong]"<<endl;
    } else {
        for(int i = stack.top; i >= 1; i-- ) {
            cout<<stack.element[i];
            if(i == stack.top) {
                cout<<" <= TOP";
            }
            cout<<endl;
        }
    }        
}

void pop(TStack &stack) {
//ambil data atau hapus stack
    int data;
    if(isEmpty(stack)) {
        cout<<"ERROR : Data Kosong";              
    } else {
        data = stack.element[stack.top];
        stack.top--;        
        cout<<data;
    }
    cout<<endl;
}
int peek(TStack stack) {
//melihat isi posisi terakhir stack atau top
    return stack.element[stack.top];
}
void empty(TStack &stack) {
//kosongkan stack
    stack.top = 0;    
}