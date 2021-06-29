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
void enqueue(TQueue &queue, int newElement);
int count(TQueue queue);

//PROGRAM UTAMA
int main(int argc, char const *argv[])
{
    //Deklarasi
    TQueue queue1;
    //Algoritma
    init(queue1);    
    return 0;
}

//Prosedure atau Fungsi
void init(TQueue &queue)
{
    //inisialisasi queue
    queue.front = NULL;
    queue.rear = NULL;
}
bool isEmpty(TQueue queue)
{ //cek queue kosong
    return queue.front == NULL;
}
int count(TQueue queue)
{
    //hitung banyak elemen queue
    //Deklarasi
    int counter;
    Node *head;
    //Algoritma
    counter = 0;
    if(!isEmpty(queue)) {
        head = queue.front;
        while (queue.front->next != queue.rear->next)
        {
            counter++;
            queue.front = queue.front->next;
        }            
        counter++;
    }
    return counter;
}
void enqueue(TQueue &queue, int newElement)
{
    //tambah elemen queue
    //Deklarasi
    Node *newNode;
    newNode = new Node;
    newNode->element = newElement;
    newNode->next = NULL;
    //Algoritma
    if (isEmpty(queue))
    {
        queue.front = newNode;
        queue.rear = newNode;
    }
    else
    {
        queue.rear->next = newNode;
        queue.rear = newNode;
        queue.rear->next = queue.front;
    }
}
void dequeue(TQueue &queue, int dequeueElement)
{
    //hapus elemen queue / ambil elemen queue
    //Deklarasi
    Node *deletedNode;
    //Algoritma    
}