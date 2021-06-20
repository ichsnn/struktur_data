#include <iostream>

using namespace std;

const int MAKS = 100;

typedef int tMatrik[MAKS][MAKS];

//DEKLARASI PURWARUPA FUNGSI YANG AKAN DIGUNAKAN
void tampilMatrik(tMatrik M, int b, int k);         
void inisialisasiMatrik(tMatrik &M, int b, int k);


//PROGRAM UTAMA
int main(int argc, char const *argv[]) {

    //DEKLARASI
    int m1[MAKS][MAKS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int i;
    int j;
    int baris, kolom;    

    //ALGORITMA    
    baris = 3;
    kolom = 3; 
        
    tampilMatrik(m1, baris, kolom);
    cout<<endl;

    //setelah diinisialisasi
    inisialisasiMatrik(m1, baris, kolom);
    tampilMatrik(m1, baris, kolom);            
    return 0;
}

//FUNGSI YANGA AKAN DIGUNAKAN

void tampilMatrik(tMatrik M, int b, int k) {
//tampil matrik

    //DEKLARASI
    int i;
    int j;        

    //ALGORITMA
    cout<<"Isi Matrik : \n"<<endl;
    i = 0;
    while(i<b) {
        j=0;
        while(j<k) {
            cout<<M[i][j]<<"\t";
            j++;
        }        
        cout<<endl;
        i++;
    }
    cout<<endl;
    cout<<"Tekan Enter Untuk Lanjut... ";   
    getchar();         
}

void inisialisasiMatrik(tMatrik &M, int b, int k) {
//inisialisasi matrik

    //DEKLARASI
    int i;
    int j;

    //ALGORITMA        
    i = 0;
    while(i<b) {
        j=0;
        while(j<k) {
            M[i][j] = 0;
            j++;
        }                
        i++;
    }    
}