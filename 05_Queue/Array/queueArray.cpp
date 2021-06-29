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

//PROGRAM UTAMA
int main()
{
    //Deklarasi
    TQueue queue1;
    //Algoritma
    init(queue1);
    cout<<"Front : "<<queue1.front<<"\n";
    cout<<"Rear  : "<<queue1.rear<<"\n";
}

//Prosedure atau Fungsi
void init(TQueue &queue)
{
    queue.front = 0;
    queue.rear = 0;
}
bool isEmpty(TQueue queue)
{
    return queue.front == 0;
}