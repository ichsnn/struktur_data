#include <iostream> 
#define MAX 100
using namespace std;

struct TStack {
    int elemen[MAX];
    int top;
};

void initStack(TStack &stack);
bool isEmpty(TStack stack);
bool isFull(TStack stack);
void push(TStack &stack, int sisa);
void pop(TStack &stack, int &hasil);


//PROGRAM UTAMA
int main() {
    //Deklarasi
    int desimal, biner;    
    TStack stack1;
    //Algoritma
    initStack(stack1);
    cout<<"Desimal : ";cin>>desimal;
    do
    {
        push(stack1, desimal%2);
        desimal/=2;
    } while (desimal!=0);
    cout<<"Biner  : ";
    do
    {
        pop(stack1, biner);
        cout<<biner;
    } while (!isEmpty(stack1));
    cout<<endl;    
}

void initStack(TStack &stack) {
    stack.top = 0;  //isi stack dimulai dari index 1
}
bool isEmpty(TStack stack) {
    return stack.top == 0;
}
bool isFull(TStack stack) {
    return stack.top == MAX;
}
void push(TStack &stack, int sisa) {
    if(isFull(stack)) {
        cout<<"ERROR : Stack Penuh";
    } else {
        stack.top++;
        stack.elemen[stack.top] = sisa;
    }
}
void pop(TStack &stack, int &hasil) {
    if(isEmpty(stack)) {
        cout<<"ERROR : Stack Kosong";
    } else {
        hasil = stack.elemen[stack.top];
        stack.top--;
    }
}