//tipe data terstruktur

#include <iostream>
#include <string>

using namespace std;

int main() {

    struct TMhs {
        char nim[8];
        char nama[30];
        short uts, uas;
        float nilai_akhir;        
    };
    
    TMhs mhs;
    cout<<"NIM  : ";cin.getline(mhs.nim, sizeof(mhs.nim)+1);
    cout<<"Nama : ";cin.getline(mhs.nama, sizeof(mhs.nama));
    cout<<"UTS  : ";cin>>mhs.uts;
    cout<<"UAS  : ";cin>>mhs.uas;
    mhs.nilai_akhir = 0.40 * mhs.uts + 0.60 * mhs.uas;
    cout<<"Mahasiswa yang bernama "<<mhs.nama<<" mempunyai nilai "<<mhs.nilai_akhir<<endl;


    return 0;

}