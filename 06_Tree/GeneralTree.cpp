#include <iostream>
using namespace std;

struct TNode
{
    char nama;
    TNode *firstChild;
    TNode *nextSibling;
};

void init(TNode *&node);
bool isEmpty(TNode *node);
TNode *createNode(char data);
void addChild(TNode *&parent, char data);
void displayChild(TNode *parent);
TNode *getLastChild(TNode *parent);

// MAIN PROGRAM
int main()
{
    // Declaration
    TNode *root;
    // Algorithm
    init(root);    
    addChild(root, 'A');
    addChild(root, 'B');
    addChild(root, 'C');
    addChild(root, 'D');    
    displayChild(root);

    return 0;
}

// Procedure or Function
void init(TNode *&node)
{
    node = NULL;
}
bool isEmpty(TNode *node)
{
    return node == NULL;
}
TNode *createNode(char nama)
{
    TNode *newNode;
    newNode = new TNode;
    newNode->nama = nama;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}
TNode *getLastChild(TNode *parent) {
    TNode *temp;
    if(isEmpty(parent))
    {
        return NULL;        
    }
    else
    {        
        temp = parent->firstChild;
        while(temp->nextSibling!=NULL) {
            temp = temp->nextSibling;
        }
        return temp;
    }
}
void addChild(TNode *&parent, char nama)
{
    TNode *newNode;
    TNode *lastChild;
    newNode = createNode(nama);
    if (isEmpty(parent))
    {
        parent = newNode;
    }
    else
    {
        if (parent->firstChild == NULL)
        {            
            parent->firstChild = newNode;            
        }
        else{
            lastChild = getLastChild(parent);
            lastChild->nextSibling = newNode;
        }
    }
}
void displayChild(TNode *parent)
{    
    TNode* child;    
    child = parent->firstChild;
    cout<<"Parent : "<<parent->nama<<endl;    
    while(child != NULL) {
        cout<<"Child  : "<<child->nama<<endl;
        child = child->nextSibling;
    }    
}