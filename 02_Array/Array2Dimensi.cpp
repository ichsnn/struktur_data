#include <iostream>

using namespace std;

const int MAKS = 100;

typedef int tMatrik[MAKS][MAKS];

//DEKLARASI PURWARUPA FUNGSI YANG AKAN DIGUNAKAN
void tampilMatrik(tMatrik M, int b, int k);         
void inisialisasiMatrik(tMatrik &M, int b, int k);
void bacaMatrik(tMatrik &M, int b, int k);
void penjumlahanMatrik(tMatrik M1, tMatrik M2, int b, int k, tMatrik &M3);
//PROGRAM UTAMA
int main(int argc, char const *argv[]) {

    //DEKLARASI
    tMatrik m1, m2, m3;        
    int i;
    int j;
    int baris, kolom;    

    //ALGORITMA    
    baris = 3;
    kolom = 3; 
        
    //Matrik diinisialisasi    
    system("cls");
    cout<<"INISIALISASI MATRIK\n"<<endl;
    inisialisasiMatrik(m1, baris, kolom);
    tampilMatrik(m1, baris, kolom);            
    cout<<endl;

    //Baca Matrik    
    system("cls");
    cout<<"BACA MATRIK\n"<<endl;
    bacaMatrik(m1, baris, kolom);
    fflush(stdin);cout<<endl;              
    tampilMatrik(m1, baris, kolom);                

    //Penjumlahan Matrik
    system("cls");
    cout<<"PENJUMLAHAN MATRIKS\n"<<endl;
    bacaMatrik(m1, baris, kolom);
    fflush(stdin);cout<<endl;
    bacaMatrik(m2, baris, kolom);
    fflush(stdin);cout<<endl;
    penjumlahanMatrik(m1, m2, baris, kolom, m3);
    tampilMatrik(m3, baris, kolom);

    system("cls");
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

void bacaMatrik(tMatrik &M, int b, int k) {
//baca matrik

    //DEKLARASI MATRIK
    int i, j;

    //ALGORITMA
    for(i=0; i<b; i++) {
        for(j=0; j<k; j++) {
            cout<<"Data Baris "<<i<<", Kolom "<<j<<" : ";cin>>M[i][j];
        }
    }    
}

void penjumlahanMatrik(tMatrik M1, tMatrik M2, int b, int k, tMatrik &M3) {
//penjumlahan matrik

    //DEKLARASI MATRIK
    int i, j;

    //ALGORITMA    
    for(i=0; i<b; i++) {
        for(j=0; j<k; j++) M3[i][j] = M1[i][j] + M2[i][j];        
    }    
}