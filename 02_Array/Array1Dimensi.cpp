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

//Procedure Tambah di Akhir
//Penambahan Data (Add)
int TambahDiAkhir(int DataBaru, int D[Maks], int N) {
    if(N < Maks) {
        D[N+1] = DataBaru;
        N += 1;
    } else cout<<"Data Telah Penuh";
    BanyakData = N;
    return BanyakData;
}

//Program Utama
int main() {

    BanyakData = 5;
    Data[1] = 10;
    Data[2] = 5;
    Data[3] = 7;
    Data[4] = 12;
    Data[5] = 9;    
    //Inisialisasi(Data, BanyakData);
    TambahDiAkhir(5, Data, BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;
    TampilData(Data, BanyakData); //memanggil procedure tampil data

}