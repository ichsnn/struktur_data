#include <iostream>

using namespace std;

const int MAKS = 100;

typedef int tMatrik[MAKS][MAKS];

//DEKLARASI PURWARUPA FUNGSI YANG AKAN DIGUNAKAN
void tampilMatrik(tMatrik M, int b, int k);         
void inisialisasiMatrik(tMatrik &M, int b, int k);
void bacaMatrik(tMatrik &M, int b, int k);
void penjumlahanMatrik(tMatrik M1, tMatrik M2, int b1, int k1, int b2, int k2, tMatrik &M3, int &b3, int &k3);
void perkalianMatrik(tMatrik M1, tMatrik M2, int b1, int k1, int b2, int k2, tMatrik &M3, int &b3, int &k3);

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {

    //DEKLARASI
    tMatrik m1, m2, m3;        
    int i;
    int j;
    int baris1, kolom1, baris2, kolom2, baris3, kolom3;    

    //ALGORITMA    
    baris1 = 3; baris2 = 3;
    kolom1 = 3; kolom2 = 3; 
        
    //Matrik diinisialisasi    
    system("cls");
    cout<<"INISIALISASI MATRIK\n"<<endl;
    inisialisasiMatrik(m1, baris1, kolom1);    
    tampilMatrik(m1, baris1, kolom1);            
    cout<<endl;

    /*
    //Baca Matrik    
    system("cls");
    cout<<"BACA MATRIK\n"<<endl;
    bacaMatrik(m1, baris1, kolom1);
    fflush(stdin);cout<<endl;              
    tampilMatrik(m1, baris1, kolom1);                
    */

    //Penjumlahan Matrik
    system("cls");
    cout<<"PENJUMLAHAN MATRIKS\n"<<endl;
    bacaMatrik(m1, baris1, kolom1);
    fflush(stdin);cout<<endl;
    bacaMatrik(m2, baris2, kolom2);
    fflush(stdin);cout<<endl;
    penjumlahanMatrik(m1, m2, baris1, kolom1, baris2, kolom2, m3, baris3, kolom3);
    tampilMatrik(m3, baris3, kolom3);
    cout<<endl;
    perkalianMatrik(m1, m2, baris1, kolom1, baris2, kolom2, m3, baris3, kolom3);
    tampilMatrik(m3, baris3, kolom3);


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

void penjumlahanMatrik(tMatrik M1, tMatrik M2, int b1, int k1, int b2, int k2, tMatrik &M3, int &b3, int &k3) {
//penjumlahan matrik

    //DEKLARASI MATRIK
    int i, j;
    int baris, kolom ;    

    //ALGORITMA    
    if(b1 == b2 && k1 == k2) {
        baris = b1;
        kolom = k1;
        b3 = baris;
        k3 = kolom;
        for(i=0; i<b3; i++) {
            for(j=0; j<k3; j++) M3[i][j] = M1[i][j] + M2[i][j];        
        }    
    }
    else cout<<"-ordo tidak bersesuaian-\n"<<endl;
}

void perkalianMatrik(tMatrik M1, tMatrik M2, int b1, int k1, int b2, int k2, tMatrik &M3, int &b3, int &k3) {
//perkalian matrik

    //DEKLARASI
    int b, k, i;    
    if(k1 == b2) {
        b3 = b1;
        k3 = k2;
        for(b=0; b<b3; b++) {
            for(k=0; k<k3; k++) {
                M3[b][k] = 0;
                for(i=0; i<k1; i++) {                        
                    M3[b][k] += M1[b][i] * M2[i][k]; 
                }                    
            }                        
        }
    } else cout<<"-ordo tidak bersesuaian-\n"<<endl;
}

/*
    1  2  3     2  3  1      3  5  4
    4  5  6  +  2  3  1   =  6  8  7
    7  8  9     2  3  1   =  9  11 10

    1  2  3     2  3  1      2+4+6    3+6+9    1+2+3     12  18  6 
    4  5  6  x  2  3  1   =  8+10+12  12+15+18 4+5+6  =  30  45  15  
    7  8  9     2  3  1      14+16+18 21+24+27 7+8+9     48  72  24
*/