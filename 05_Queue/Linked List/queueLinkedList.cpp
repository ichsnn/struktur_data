#include <iostream>
using namespace std;

struct Node
{
    int element;
    Node *next;
};

struct TQueue
{
    Node *front;
    Node *rear;
};

//Deklarasi Purwarupa Fungsi atau Prosedur yang Digunakan
void init(TQueue &queue);
bool isEmpty(TQueue queue);
int count(TQueue queue);
void display(TQueue queue);
void enqueue(TQueue &queue, int newElement);
void dequeue(TQueue &queue, int &dequeueElement);

//Program Utama
int main(int argc, char const *argv[])
{
    //Deklarasi
    TQueue queue1;
    int element;
    //Algoritma
    init(queue1);
    display(queue1);
    enqueue(queue1, 1);
    display(queue1);
    enqueue(queue1, 2);
    display(queue1);
    enqueue(queue1, 3);
    display(queue1);
    enqueue(queue1, 4);
    display(queue1);    
    dequeue(queue1, element);    
    cout<<"dequeue : "<<element<<endl;
    display(queue1);
    dequeue(queue1, element);
    cout<<"dequeue : "<<element<<endl;
    display(queue1);
    dequeue(queue1, element);
    cout<<"dequeue : "<<element<<endl;
    display(queue1);
    dequeue(queue1, element);    
    display(queue1);

    return 0;
}

//Prosedur atau Fungsi
void init(TQueue &queue)
{
    queue.front = NULL;
    queue.rear = NULL;
}
bool isEmpty(TQueue queue)
{
    return queue.front == NULL;
}
int count(TQueue queue)
{
    //Deklarasi
    Node *head;
    int counter;
    //Algoritma
    counter = 0;
    head = queue.front;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}
void display(TQueue queue)
{
    //Deklarasi    
    Node *head;
    //Algoritma
    head = queue.front;
    cout << "Isi Queue : ";
    if (isEmpty(queue))
    {
        cout << "[Data Kosong]";
    }
    else
    {
        cout << "[Front] ";
        while (head != NULL)
        {
            cout << head->element << " ";
            head = head->next;
        }
        cout << "[Rear]";
    }
    cout << endl;
    system("pause");
}
void enqueue(TQueue &queue, int newElement)
{
    //Deklarasi
    Node *newNode;
    //Algoritma
    newNode = new Node;
    newNode->element = newElement;
    newNode->next = NULL;
    if (isEmpty(queue))
    {
        queue.front = newNode;
        queue.rear = newNode;
    }
    else
    {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}
void dequeue(TQueue &queue, int &dequeueElement)
{
    //Deklarasi
    Node *temp;
    //Algoritma
    dequeueElement = queue.front->element;
    temp = queue.front;
    if (queue.front == queue.rear)
    {
        queue.front = NULL;
        queue.rear = NULL;
    }
    else
    {
        queue.front = queue.front->next;
    }
    delete temp;
}
int peek(TQueue queue)
{
    return queue.front->element;
}