#include <iostream>
#include <cstdlib>
using namespace std;

#define max 5

struct TQueue
{
    int element[max + 1]; // array 1..5
    int front, rear;
};

//DEKLARASI PURWARUPA FUNGSI ATAU PROSEDURE YANG AKAN DIGUNAKAN
void init(TQueue &queue);
int count(TQueue queue);
bool isEmpty(TQueue queue);
bool isFull(TQueue queue);
void display(TQueue queue);
int peek(TQueue queue);
void enqueue(TQueue &queue, int newElement);
void dequeue(TQueue &queue, int dequeueElement);

//PROGRAM UTAMA
int main(int argc, char const *argv[])
{
    //Deklarasi
    system("cls");
    TQueue queue1;
    int take;
    //ALGORTIMA
    init(queue1);
    display(queue1);
    cout << endl;
    enqueue(queue1, 1);
    display(queue1);
    cout << endl;
    enqueue(queue1, 2);
    display(queue1);
    cout << endl;
    enqueue(queue1, 3);
    display(queue1);
    cout << endl;
    enqueue(queue1, 4);
    display(queue1);
    cout << endl;
    enqueue(queue1, 5);
    display(queue1);
    cout << endl;
    dequeue(queue1, take);
    display(queue1);
    cout << endl;
    enqueue(queue1, 6);
    display(queue1);
    cout << endl;
    while (!isEmpty(queue1))
    {
        dequeue(queue1, take);
        display(queue1);
        cout << endl;
    }
    enqueue(queue1, 1);
    display(queue1);
    cout<<endl;
    dequeue(queue1, take);
    display(queue1);
}

//PROSEDURE ATAU FUNGSI
void init(TQueue &queue)
{
    //inisialisasi
    queue.front = 0;
    queue.rear = 0;
    for (int i = 1; i <= max; i++)
    {
        queue.element[i] = 0;
    }
}
bool isEmpty(TQueue queue)
{
    //cek queue kosong
    return queue.front == 0;
}
bool isFull(TQueue queue)
{
    //cek queue penuh
    if (queue.front <= queue.rear)
        return (queue.rear - queue.front) == max - 1;
    else
        return (queue.front - queue.rear) == 1;
}
int count(TQueue queue)
{
    //hitung banyak element queue
    //Deklarasi
    int counter; //penampung banyak element
    int i;       //indeks element
    //Algoritma
    counter = 0;
    if (!isEmpty(queue))
    {
        i = queue.front;
        while (i != queue.rear)
        {
            counter++;
            if (i == max)
            {
                i = 1;
            }
            else
                i++;
        }
        counter++;
    }
    return counter;
}
void display(TQueue queue)
{
    //tampilkan element queue
    //Deklarasi
    int i;
    //Algoritma
    cout << "Isi Queue : ";
    if (isEmpty(queue))
        cout << "[Data Kosong]";
    else
    {
        i = 1;
        while (i != max)
        {
            cout << queue.element[i] << " ";
            i++;
        }
        cout << queue.element[i];
    }
    cout << endl;
    system("pause");
}
int peek(TQueue queue)
{
    //melihat front queue;
    return queue.element[queue.front];
}
void enqueue(TQueue &queue, int newElement)
{
    //menambah elemen queue
    if (isFull(queue))
    {
        cout << "[Antrian Penuh]" << endl;
    }
    else
    {
        if (isEmpty(queue))
        {
            queue.front++;
            queue.rear++;
        }
        else
        {
            if (queue.rear == max)
                queue.rear = 1;
            else
                queue.rear++;
        }
        queue.element[queue.rear] = newElement;
    }
}
void dequeue(TQueue &queue, int dequeueElement)
{
    //menghapus atua mengambil elemen queue
    if (isEmpty(queue))
    {
        cout << "[Queue Kosong]" << endl;
    }
    else
    {
        dequeueElement = queue.element[queue.front];
        queue.element[queue.front] = 0;
        if (queue.front == queue.rear)
        {
            queue.front = 0;
            queue.rear = 0;
        }
        else
        {
            if (queue.front == max)
                queue.front = 1;
            else
                queue.front++;
        }
    }
}