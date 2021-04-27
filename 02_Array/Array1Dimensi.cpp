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


//PENAMBAHAN DATA (ADD)

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

//Procedure Tambah di Awal
void TambahDiAwal(int DataBaru, int *D, int *N) {
    TambahDiTengah(DataBaru, 1, D, N);
}

//PENGEDITAN ARRAY
void UpdateData(int DataBaru, int PosisiUpdate, int *D, int *N) {
    if(PosisiUpdate>=1 && PosisiUpdate<=*N) {
        D[PosisiUpdate] = DataBaru;
    } else cout<<"Posisi update tidak sah!\n";
}



//Program Utama
int main() {

    BanyakData = 5;
    Data[1] = 10;
    Data[2] = 5;
    Data[3] = 7;
    Data[4] = 12; 
    Data[5] = 0;      

    //Inisialiasi Data
    Inisialisasi(Data, &BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;      
    TampilData(Data, BanyakData); //memanggil procedure tampil data            

    //DataBaru
    BanyakData = 5;
    Data[1] = 10;
    Data[2] = 5;
    Data[3] = 7;
    Data[4] = 12; 
    Data[5] = 9;
    cout<<"Banyak Data  : "<<BanyakData<<endl;          
    TampilData(Data, BanyakData); //memanggil procedure tampil data 

    //TambahData

    TambahDiAkhir(20, Data, &BanyakData);       //Di Akhir
    cout<<"Banyak Data  : "<<BanyakData<<endl;          
    TampilData(Data, BanyakData); //memanggil procedure tampil data    

    TambahDiTengah(8, 3, Data, &BanyakData);    //Di Tengah
    cout<<"Banyak Data  : "<<BanyakData<<endl;          
    TampilData(Data, BanyakData); //memanggil procedure tampil data      

    TambahDiAwal(5, Data, &BanyakData);         //Di Awal
    cout<<"Banyak Data  : "<<BanyakData<<endl;      
    TampilData(Data, BanyakData); //memanggil procedure tampil data  

    //UPDATE
    UpdateData(30, 2, Data, &BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;          
    TampilData(Data, BanyakData); //memanggil procedure tampil data  


    return 0;
}