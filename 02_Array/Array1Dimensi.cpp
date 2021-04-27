#include <iostream>

using namespace std;

//Deklarasi (GLOBAL)
const int Maks = 100; //Maks Data[5]

    int Data[Maks];
    int BanyakData;       //masukan untuk panjang array

//Procedure tampil data 
//Penelusuran Array (Traversal)
void TampilData(int *D, int N) {
    int i;

    cout<<"Data : ";
    if(N > 0) {
        for(i = 1; i <= N; i++) {
            cout<<D[i];
            if(i<N) {
                cout<<" ";
            }            
        }
    } else cout<<" [Data Kosong]";

    cout<<"\nTekan Enter untuk Melanjutkan";
    getchar();
}

//Procedure Inisialisasi
//Inisialiasi Array (Initialize)
void Inisialisasi(int *D, int *N) {
    int i;

    for(i = 1; i <= (*N); i++) {
        D[i] = 0;
    }    
    N = 0;
}


//Penambahan Data (Add)

//Procedure Tambah di Akhir
void TambahDiAkhir(int DataBaru, int *D, int *N) {
    if(*N<Maks-1) {
        D[*N+1] = DataBaru;        
        *N += 1;
    } else cout<<"Data Telah Penuh!\n";
}

//Procedure Tambah di Tengah
void TambahDiTengah(int DataBaru, int PosisiSisip, int *D, int *N) {
    int i;
    if(*N<Maks-1) {
        if(PosisiSisip>=1 && PosisiSisip<=*N) {
            for(i=*N; i>=PosisiSisip; i--) D[i+1] = D[i];      //Penggeser Data            
            D[PosisiSisip] = DataBaru;              //Sisiip Data Baru
            *N += 1;
        } else cout<<"Posisi sisip tidak sah!\n";
    } else cout<<"Data Telah Penuh\n";
}

//Program Utama
int main() {

    BanyakData = 5;
    Data[1] = 10;
    Data[2] = 5;
    Data[3] = 7;
    Data[4] = 12; 
    Data[5] = 0;      
    Inisialisasi(Data, &BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;      
    TampilData(Data, BanyakData); //memanggil procedure tampil data            
    BanyakData = 5;
    Data[1] = 10;
    Data[2] = 5;
    Data[3] = 7;
    Data[4] = 12; 
    Data[5] = 9;
    cout<<"Banyak Data  : "<<BanyakData<<endl;      
    TampilData(Data, BanyakData); //memanggil procedure tampil data            
    TambahDiTengah(8, 6, Data, &BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;          
    TampilData(Data, BanyakData); //memanggil procedure tampil data      

    return 0;
}