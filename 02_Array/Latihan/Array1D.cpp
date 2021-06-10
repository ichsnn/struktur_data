#include <iostream>

using namespace std;

//DEKLARASI GLOBAL
const int NMAKS = 100;
typedef int LarikInt[NMAKS + 1];

//PURWARUPA PROCEDURE YANG AKAN DIGUNAKAN
void bacaData(LarikInt &data1, int N);                              // 1. Baca Data
float total(LarikInt data1, int N);                                 // 2. Tampilkan Total Penjumlahan Semua Elemen
float rerata(LarikInt data1, int N);                                // 3. Tampilkan Rata-Rata
void terkecil(LarikInt data1, int N, int &kecil, int &frek);        // 4. Tampilkan Terkecil dan Frekuensinya

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {

    //DEKLARASI
    LarikInt data;
    int banyakData;
    float sum;          //total data
    float u;            //rata - rata
    int min, fmin;      //nilai terkecil dan banyaknya
    int max, fmax;      //nilai terbesar dan banyaknya


    //PROGRAM UTAMA    
    cout<<"Banyak Data : ";cin>>banyakData;

    bacaData(data, banyakData); //1. Baca Data

    cout<<endl;

    sum = total(data, banyakData);
    u = rerata(data, banyakData);
    terkecil(data, banyakData, min, fmin);    

    cout<<"Total            : "<<sum<<endl;                         //2. Tampilkan Total Penjumlahan Semua Elemen
    cout<<"Rata - Rata      : "<<u<<endl;                           //3. Tampilkan Rata-Rata
    cout<<"Terkecil         : "<<min<<" sebanyak "<<fmin<<endl;     //4. Tampilkan Nilai Terkecil

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

void terkecil(LarikInt data1, int N, int &kecil, int &frek) {
//4. Tampilkan Nilai Terkecil dan Banyaknya
    //DEKLARASI
    int i;
    LarikInt countMin;
    //ALGORITMA
    kecil = data1[1];
    for(i=2;i<=N;i++) {
        if(data1[i] < kecil) {
            kecil = data1[i];
        }
    }
    for(i=1;i<=N;i++) {
        countMin[i] = 0;
    }
    for(i=1;i<=N;i++) {
        countMin[data1[i]] = countMin[data1[i]] + 1;
    }
    frek = countMin[kecil];
}