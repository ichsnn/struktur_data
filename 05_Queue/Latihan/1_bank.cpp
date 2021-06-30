#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int info;
    Node *next;
};
struct TQueue
{
    Node *front;
    Node *rear;
};

void init(TQueue &queue);   //inisialisasi antrian
bool isEmpty(TQueue queue); //cek antrian kosong
void displayQueue(TQueue queue); //tampilkan isi nomor antrian
void enqueue(TQueue &queue, int newElement); //tambah antrian
void dequeue(TQueue &queue, int &dequeueElement);   //menghapus antrian
void choice(TQueue &queue, int &enqueueElement, int &dequeueElement, int menu); //event ketika memilih menu
void displayMenu(TQueue queue, int enqueueElement, int dequeueElement, int menu, string &loket1, string &loket2);   //menampilkan output event memilih menu

int main(int argc, char const *argv[])
{
    //Deklarasi
    int opsi = 0;
    TQueue queue1;
    int nomorAntrian = 0;
    int nomorPanggilan;
    string loket1 = "-";
    string loket2 = "-";
    //Algoritma
    system("cls");
    init(queue1);
    do
    {
        cout<<"-----------SISTEM ANTRIAN S.A.T. BANK-----------\n";
        cout << endl;
        displayMenu(queue1, nomorAntrian, nomorPanggilan, opsi, loket1, loket2);
        cout << endl;
        cout << "1. Tambah Antrian\n";
        cout << "2. Loket 1 Memanggil\n";
        cout << "3. Loket 2 Memanggil\n";
        cout << "4. Keluar dari Aplikasi\n";
        cout << endl;
        cout << "Masukkan pilihan (1-4) : ";
        cin >> opsi;
        choice(queue1, nomorAntrian, nomorPanggilan, opsi);
        cout << endl;
        system("cls");
    } while (opsi != 4);
    return 0;
}

void init(TQueue &queue)    //inisialisasi
{
    queue.front = NULL;
    queue.rear = NULL;
}
bool isEmpty(TQueue queue)  //cek antrian kosong
{
    return queue.front == NULL;
}
void displayQueue(TQueue queue) //menampilkan isi antrian
{
    Node *head;
    head = queue.front;
    if (isEmpty(queue))
    {
        cout << "[Tidak Ada Antrian]";
    }
    else
    {
        while (head != NULL)
        {
            cout << head->info << " ";
            head = head->next;
        }
    }
    cout << endl;
}
void enqueue(TQueue &queue, int newElement) //menambah antrian
{
    //Deklarasi
    Node *newNode;
    newNode = new Node;
    newNode->info = newElement;
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
void dequeue(TQueue &queue, int &dequeueElement) //menghapus antrian
{
    Node *temp;
    dequeueElement = queue.front->info;
    temp = queue.front;
    if (isEmpty(queue))
    {
        cout << "ERROR : Antrian Kosong" << endl;
    }
    else
    {
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
}
void peek(TQueue queue) //melihat nomor paling depan yang akan di hapus berikutnya
{
    if (isEmpty(queue))
    {
        cout << "-";
    }
    else
        cout << queue.front->info;
}
void choice(TQueue &queue, int &enqueueElement, int &dequeueElement, int menu) //event memilih menu
{
    switch (menu)
    {
    case 1:
        enqueue(queue, ++enqueueElement);
        break;
    case 2:
    case 3:
        if (isEmpty(queue))
        {
            cout << "ERROR : Antrian Kosong!";
            fflush(stdin);
            getchar();
        }
        else
            dequeue(queue, dequeueElement);
        break;
    case 4: 
        cout<<"Terimakasih Sudah Menggunakan Aplikasi Ini";
        fflush(stdin);
        getchar();
        break;
    default:
        break;
    }
}
void displayMenu(TQueue queue, int enqueueElement, int dequeueElement, int menu, string &loket1, string &loket2)
{
    cout << "Loket 1\t\tLoket 2\t\tNomor Berikutnya";
    cout << endl;
    switch (menu)
    {
    case 2:
        if (!isEmpty(queue))
            loket1 = to_string(dequeueElement);
        break;
    case 3:
        if (!isEmpty(queue))
            loket2 = to_string(dequeueElement);
        break;

    default:
        break;
    }
    cout << "  " << loket1 << "\t\t  " << loket2 << "\t\t     ";
    peek(queue);
    cout << endl;
}