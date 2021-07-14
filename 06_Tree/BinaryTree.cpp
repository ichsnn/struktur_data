#include <iostream>
using namespace std;

struct TNode
{
    char info;
    TNode *left, *right;
};

void init(TNode *&node) //initialize node
{
    node = NULL;
}
bool isEmpty(TNode *&node) //check node content
{
    return node == NULL;
}

TNode *createNode(char data) // create new node
{
    // Declaration
    TNode *newNode;
    // Algorithm
    newNode = new TNode;
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(TNode *node) //penelusuran preOrder (N L R)
{
    cout << node->info << " ";
    if (node->left != NULL)
    {
        preOrder(node->left);
    }
    if (node->right != NULL)
    {
        preOrder(node->right);
    }
}

void inOrder(TNode *node) //penelusuran inOrder (L N R)
{
    if (node->left != NULL)
    {
        inOrder(node->left);
    }
    cout << node->info << " ";
    if (node->right != NULL)
    {
        inOrder(node->right);
    }
}

void postOrder(TNode *node) //penelusuran postOrder (L R N)
{
    if (node->left != NULL)
    {
        postOrder(node->left);
    }
    if (node->right != NULL)
    {
        postOrder(node->right);
    }
    cout << node->info << " ";
}

// Declaration Procedure or Function

// MAIN PROGRAM
int main(int argc, char const *argv[])
{
    // Declaration
    TNode *root1;
    TNode *a, *b, *c, *d, *e, *f, *g;
    // Algorithm

    a = createNode('A');
    b = createNode('B');
    c = createNode('C');
    d = createNode('D');
    e = createNode('E');
    f = createNode('F');
    g = createNode('G');

    root1 = a;
    root1->left = b;
    root1->right = c;
    root1->left->left = d;
    root1->left->right = e;
    root1->right->left = f;
    root1->right->right = g;

    cout<<"Pre Order  : ";preOrder(root1);
    cout<<endl;
    cout<<"In Order   : ";inOrder(root1);
    cout<<endl;
    cout<<"Post Order : ";postOrder(root1);

    return 0;
}