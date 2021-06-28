#include <iostream>
using namespace std;

struct PNode
{
    int info;
    PNode *next;
};

typedef PNode TStack;

void init(TStack *&stack)
{
    stack = NULL;
}
bool isEmpty(TStack *stack)
{
    return stack == NULL;
}
int count(TStack *stack)
{
    PNode *node;
    int banyak = 0;
    node = stack;
    while (node != NULL)
    {
        banyak++;
        node = node->next;
    }
    return banyak;
}
void display(TStack *stack)
{
    PNode *node;
    cout << "List : " << endl;
    if (isEmpty(stack))
    {
        cout << "[Data Kosong]";
    }
    else
    {
        node = stack;
        while (node != NULL)
        {
            cout << node->info;
            if (node->info == stack->info)
            {
                cout << " <= TOP";
            }
            cout << endl;
            node = node->next;
        }
    }
    cout << endl;
    system("pause");
}
PNode *createNode(int data)
{
    PNode *node;
    node = new PNode;
    node->info = data;
    node->next = NULL;
    return node;
}
void push(TStack *&stack, int data)
{
    PNode *node;
    node = createNode(data);
    if (isEmpty(stack))
    {
        stack = node;
    }
    else
    {
        node->next = stack;
        stack = node;
    }
}
void pop(TStack* &stack, int &num)
{
    int elementInTop;
    PNode* topNode;
    if(isEmpty(stack)) {
        cout<<"Stack Kosong"<<endl;
    } else {
        topNode = stack;
        num = topNode->info;
        stack = stack->next;
        delete topNode;        
    }
}
int peek(TStack* stack)
{
    return stack->info;
}
void empty(TStack* &stack)
{   
    int temp;
    while(!isEmpty(stack)) {
        pop(stack, temp);
    }
}

int main(int argc, char const *argv[])
{
    //Deklarasi
    TStack* stack1;
    int popStack;
    //Algoritma    
    init(stack1);
    display(stack1);
    cout<<endl;
    push(stack1, 9);
    push(stack1, 7);
    push(stack1, 3);
    push(stack1, 5);
    display(stack1);
    cout<<endl;
    pop(stack1, popStack);
    cout<<"Pop : "<<popStack<<endl;    
    display(stack1);
    cout<<endl;    
    empty(stack1);
    display(stack1);

    return 0;
}