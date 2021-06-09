#include <iostream>

using namespace std;

//DEKLARASI GLOBAL
const int NMAKS = 100;
typedef int LarikInt[NMAKS + 1];

//PURWARUPA PROCEDURE YANG AKAN DIGUNAKAN
void bacaData(LarikInt &data1, int N);      // 1. Baca Data
float total(LarikInt data1, int N);           // 2. Tampilkan Total Penjumlahan Semua Elemen
float rerata(LarikInt data1, int N);          // 3. Tampilkan Rata-Rata

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {

    //DEKLARASI
    LarikInt data;
    int banyakData;

    //PROGRAM UTAMA    
    cout<<"Banyak Data : ";cin>>banyakData;

    bacaData(data, banyakData); //1. Baca Data

    cout<<endl;

    cout<<"Total            : "<<total(data, banyakData)<<endl;     //2. Tampilkan Total Penjumlahan Semua Elemen
    cout<<"Rata - Rata      : "<<rerata(data, banyakData)<<endl;    //3. Tampilkan Rata-Rata

    return 0;
}


//PROCEDURE atau FUNGSI yang AKAN DIGUNAKAN

void bacaData(LarikInt &data1, int N) {
//1. Baca Data
    //DEKLARASI
    int i;
    //ALGORITMA
    for(i=1;i<=N;i++) {
        cout<<"Data "<<i<<" : ";cin>>data1[i];
    }
}

float total(LarikInt data1, int N) {
//2. Tampilkan Total Penjumlahan Semua Elemen
    //DEKLARASI
    int i;
    float sum;
    //ALGORITMA
    sum = 0;
    for(i=1;i<=N;i++) {
        sum += data1[i];
    }
    return sum;
}           
float rerata(LarikInt data1, int N) {
//3. Tampilkan Rata-Rata    
    //DEKLARASI
    int i;
    //ALGORITMA
    return total(data1, N)/N;    
}         