#include <iostream>
using namespace std;

struct Node
{
    int elements;
    Node *next;
};

typedef Node TStack;

void init(TStack *&stack)
{
    stack = NULL;
}
bool isEmpty(TStack *stack)
{
    return stack == NULL;
}
Node *createTemp(int sisa)
{
    Node *temp;
    temp = new Node;
    temp->elements = sisa;
    temp->next = NULL;
    return temp;
}
void push(TStack *&stack, int sisa)
{
    Node *temp;
    temp = createTemp(sisa);
    if (isEmpty(stack))
    {
        stack = temp;
    }
    else
    {
        temp->next = stack;
        stack = temp;        
    }
}
void display(TStack *stack) {
    Node* temp;
    if(isEmpty(stack)) {
        cout<<"Kosong";
    } else {
        temp = stack;
        while (temp!=NULL)
        {
            cout<<temp->elements<<endl;
            temp = temp->next;
        }
        
    }
}
void pop(TStack *&stack, int &biner)
{
    Node *topStack;
    if (isEmpty(stack))
    {
        cout << "Stack Kosong" << endl;
    }
    else
    {
        topStack = stack;
        biner = topStack->elements;
        stack = stack->next;
        delete topStack;
    }
}

//PROGRAM UTAMA
int main(int argc, char const *argv[])
{
    //Deklarasi
    int desimal, biner;
    TStack *stack1;
    //Algoritma
    init(stack1);
    cout << "Desimal : ";
    cin >> desimal;
    do
    {
        push(stack1, desimal % 2);
        desimal /= 2;
    } while (desimal != 0);    
    cout << "Biner   : ";
    do
    {
        pop(stack1, biner);
        cout << biner;        
    } while (!isEmpty(stack1));    
    cout << endl;
    system("pause");
    return 0;
}