#include <iostream>

using namespace std;

//Deklarasi (GLOBAL)
const int Maks = 100;

    int Data[Maks];
    int BanyakData;       //masukan untuk panjang array

//Procedure tampil data 
//Penelusuran Array (Traversal)
void TampilData(int D[Maks], int N) {
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
int Inisialisasi(int D[Maks], int N) {
    int i;

    for(i = 1; i <= N; i++) {
        D[i] = 0;
    }
    return BanyakData = 0;    
}


//Penambahan Data (Add)

//Procedure Tambah di Akhir
void TambahDiAkhir(int DataBaru, int D[Maks], int BanyakData) {
    if(BanyakData < Maks) {
        D[BanyakData+1] = DataBaru;
        BanyakData += 1;
    } else cout<<"Data Telah Penuh\n";        
}

//Procedure Tambah di Tengah


//Program Utama
int main() {

    BanyakData = 5;
    Data[1] = 10;
    Data[2] = 5;
    Data[3] = 7;
    Data[4] = 12;
    Data[5] = 9;    
    //Inisialisasi(Data, BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;
    TambahDiAkhir(5, Data, BanyakData);
    TampilData(Data, BanyakData); //memanggil procedure tampil data    
    TambahDiAkhir(7, Data, BanyakData);
    TampilData(Data, BanyakData); //memanggil procedure tampil data

    return 0;
}