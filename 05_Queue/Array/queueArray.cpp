#include <iostream>
using namespace std;

const int MAX_ELEMENT_QUEUE = 100;

struct TQueue
{
    int element[MAX_ELEMENT_QUEUE];
    int front, rear;
};

//Deklarasi Purwarupa Prosedur atau Fungsi yang Digunakan
void init(TQueue &queue);
bool isEmpty(TQueue queue);
bool isFull(TQueue queue);
void display(TQueue queue);
void enqueue(TQueue &queue, int newElement);
void dequeue(TQueue &queue, int &elementFront);
//PROGRAM UTAMA
int main()
{
    //Deklarasi
    TQueue queue1;
    int keluar;
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
    enqueue(queue1, 5);
    display(queue1);
    dequeue(queue1, keluar);    
    display(queue1);
    dequeue(queue1, keluar);    
    display(queue1);
    dequeue(queue1, keluar);    
    display(queue1);
    dequeue(queue1, keluar);    
    display(queue1);
    dequeue(queue1, keluar);            
    display(queue1);
}

//Prosedure atau Fungsi
void init(TQueue &queue)
{ //Inisisalisasi antrian
    queue.front = 0;
    queue.rear = 0;
}
bool isEmpty(TQueue queue)
{
    //Cek antrian kosong
    return queue.front == 0;
}
bool isFull(TQueue queue)
{
    //Cek antrian penuh
    return queue.rear == MAX_ELEMENT_QUEUE;
}
int count(TQueue queue)
{
    //Cek banyak antrian
    return queue.rear;
}
void display(TQueue queue)
{
    //Menampilkan elemen dalam antrian
    int i;
    cout << "Isi Queue : ";
    if (isEmpty(queue))
    {
        cout << "[Data Kosong]";
    }
    else
    {
        cout << " [Front] ";
        for (i = queue.front; i <= queue.rear; i++)
        {
            cout << queue.element[i] << " ";
        }
        cout << "[Rear]";
    }
    cout << endl;
    system("pause");
}
void enqueue(TQueue &queue, int newElement)
{
    //Menambah elemen antrian
    if (isFull(queue))
    {
        cout << " [Antrian Penuh] ";
    }
    else
    {
        if (isEmpty(queue))
        {
            queue.rear++;
            queue.front++;
        }
        else
        {
            queue.rear++;
        }
        queue.element[queue.rear] = newElement;
    }
}
void dequeue(TQueue &queue, int &elementFront)
{
    //Mengambil elemen antrian    
    int i;
    if (isEmpty(queue))
    {
        cout << " [Antrian Kosong] ";        
    }
    else
    {
        elementFront = queue.element[queue.front];
        for (i = queue.front + 1; i <= queue.rear; i++)
        {
            queue.element[i - 1] = queue.element[i];
        }
        queue.rear--;
        if(queue.rear == 0) queue.front = 0;        
    }
}