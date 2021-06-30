#include <iostream>
#include <string>
#include <Windows.h>
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

void init(TQueue &queue);                                                                                       //inisialisasi antrian
bool isEmpty(TQueue queue);                                                                                     //cek antrian kosong
void displayQueue(TQueue queue);                                                                                //tampilkan isi nomor antrian
void enqueue(TQueue &queue, int newElement);                                                                    //tambah antrian
void dequeue(TQueue &queue, int &dequeueElement);                                                               //menghapus antrian
void choice(TQueue &queue, int &enqueueElement, int &dequeueElement, int menu, string &loket1, string &loket2); //event ketika memilih menu
void displayMenu(TQueue queue, int enqueueElement, int dequeueElement, int menu, string loket1, string loket2); //menampilkan output event memilih menu
void sound(int dequeueElement);
void soundSatuan(int satuan);
void soundBelasan();
void soundPuluhan();

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
        cout << "-----------SISTEM ANTRIAN S.A.T. BANK-----------\n";
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
        choice(queue1, nomorAntrian, nomorPanggilan, opsi, loket1, loket2);
        cout << endl;
        system("cls");
    } while (opsi != 4);
    return 0;
}

void init(TQueue &queue) //inisialisasi
{
    queue.front = NULL;
    queue.rear = NULL;
}
bool isEmpty(TQueue queue) //cek antrian kosong
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
void choice(TQueue &queue, int &enqueueElement, int &dequeueElement, int menu, string &loket1, string &loket2) //event memilih menu
{
    switch (menu)
    {
    case 1:
        enqueue(queue, ++enqueueElement);
        break;
    case 2:
        if (isEmpty(queue))
        {
            cout << "ERROR : Antrian Kosong!";
            fflush(stdin);
            getchar();
        }
        else
        {
            dequeue(queue, dequeueElement);
            loket1 = to_string(dequeueElement);
            PlaySound(TEXT("sound/nomor-antrian.wav"), NULL, SND_SYNC);
            sound(dequeueElement);
            PlaySound(TEXT("sound/ke-loket-1.wav"), NULL, SND_ASYNC);
        }
        break;
    case 3:
        if (isEmpty(queue))
        {
            cout << "ERROR : Antrian Kosong!";
            fflush(stdin);
            getchar();
        }
        else
        {
            dequeue(queue, dequeueElement);
            loket2 = to_string(dequeueElement);
            PlaySound(TEXT("sound/nomor-antrian.wav"), NULL, SND_SYNC);
            sound(dequeueElement);
            PlaySound(TEXT("sound/ke-loket-2.wav"), NULL, SND_ASYNC);
        }
        break;
    case 4:
        cout << "Terimakasih Sudah Menggunakan Aplikasi Ini";
        fflush(stdin);
        getchar();
        break;
    default:
        break;
    }
}
void displayMenu(TQueue queue, int enqueueElement, int dequeueElement, int menu, string loket1, string loket2)
{
    cout << "Loket 1\t\tLoket 2\t\tNomor Berikutnya";
    cout << endl;
    cout << "  " << loket1 << "\t\t  " << loket2 << "\t\t     ";
    peek(queue);
    cout << endl;
}
void sound(int dequeueElement)
{
    int angka = dequeueElement;
    if (angka > 0 && angka <= 11)
        soundSatuan(angka);
    if (angka > 11 && angka <= 19)
    {
        soundSatuan(angka % 10);
        soundBelasan();
    }
    if (angka >= 20 && angka <= 99)
    {
        soundSatuan(angka/10);
        soundPuluhan();
        soundSatuan(angka%10);
    }
}

void soundSatuan(int satuan)
{
    if (satuan == 1)
        PlaySound(TEXT("sound/1.wav"), NULL, SND_SYNC);
    if (satuan == 2)
        PlaySound(TEXT("sound/2.wav"), NULL, SND_SYNC);
    if (satuan == 3)
        PlaySound(TEXT("sound/3.wav"), NULL, SND_SYNC);
    if (satuan == 4)
        PlaySound(TEXT("sound/4.wav"), NULL, SND_SYNC);
    if (satuan == 5)
        PlaySound(TEXT("sound/5.wav"), NULL, SND_SYNC);
    if (satuan == 6)
        PlaySound(TEXT("sound/6.wav"), NULL, SND_SYNC);
    if (satuan == 7)
        PlaySound(TEXT("sound/7.wav"), NULL, SND_SYNC);
    if (satuan == 8)
        PlaySound(TEXT("sound/8.wav"), NULL, SND_SYNC);
    if (satuan == 9)
        PlaySound(TEXT("sound/9.wav"), NULL, SND_SYNC);
    if (satuan == 10)
        PlaySound(TEXT("sound/10.wav"), NULL, SND_SYNC);
    if (satuan == 11)
        PlaySound(TEXT("sound/11.wav"), NULL, SND_SYNC);
}
void soundBelasan()
{
    PlaySound(TEXT("sound/belas.wav"), NULL, SND_SYNC);
}
void soundPuluhan()
{
    PlaySound(TEXT("sound/puluh.wav"), NULL, SND_SYNC);
}