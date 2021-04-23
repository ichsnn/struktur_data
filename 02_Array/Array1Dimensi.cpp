#include <iostream>

using namespace std;

//Deklarasi (GLOBAL)
const int Maks = 100;

    struct TArray {
        int Array[Maks];
    };
    TArray Data;
    int BanyakData;       //masukan untuk panjang array

//Procedure tampil data 
//Penelusuran Array (Traversal)
void TampilData(TArray D, int N) {
    int i;

    cout<<"Data : ";
    if(N > 0) {
        for(i = 1; i <= N; i++) {
            cout<<D.Array[i];
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
void Inisialisasi(TArray D, int N) {
    int i;

    for(i = 1; i <= N; i++) {
        D.Array[i] = 0;
    }
    N = 0;
}

//Program Utama
int main() {

    /*BanyakData = 5;
    Data.Array[1] = 10;
    Data.Array[2] = 5;
    Data.Array[3] = 7;
    Data.Array[4] = 12;
    Data.Array[5] = 9;*/
    Inisialisasi(Data, BanyakData);
    cout<<"Banyak Data  : "<<BanyakData<<endl;
    TampilData(Data, BanyakData); //memanggil procedure tampil data

}