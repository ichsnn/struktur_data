#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//DEKLARASI GLOBAL
const int NMAKS = 100;
typedef int LarikInt[NMAKS + 1];

//PURWARUPA PROCEDURE YANG AKAN DIGUNAKAN
void bacaData(LarikInt &data1, int N);                              // 1. Baca Data
float total(LarikInt data1, int N);                                 // 2. Tampilkan Total Penjumlahan Semua Elemen
float rerata(LarikInt data1, int N);                                // 3. Tampilkan Rata-Rata
int frekuensi(LarikInt data1, int N, int x);                        // Pencari frekuensi
void terkecil(LarikInt data1, int N, int &min1, int &fmin1);        // 4. Tampilkan Nilai Terkecil dan Banyaknya    
void terbesar(LarikInt data1, int N, int &max1, int &fmax1);        // 5. Tampilkan Nilai Terbesar dan Banyaknya
float variansi(LarikInt data1, int N, float rata);                          // 6. Tampilkan Variansi Nilainya
                                      
//PROGRAM UTAMA
int main(int argc, char const *argv[]) {

    //DEKLARASI
    LarikInt data;
    int banyakData;
    float sum;          //total data
    float u;            //rata - rata
    int min, fmin;      //nilai terkecil dan banyaknya
    int max, fmax;      //nilai terbesar dan banyaknya
    float s;          //variansi


    //PROGRAM UTAMA    
    cout<<"Banyak Data : ";cin>>banyakData;

    bacaData(data, banyakData); //1. Baca Data

    cout<<endl;

    sum = total(data, banyakData);
    u = rerata(data, banyakData);
    terkecil(data, banyakData, min, fmin);    
    terbesar(data, banyakData, max, fmax);
    s = variansi(data, banyakData, u);

    cout<<"Total            : "<<sum<<endl;                         //2. Tampilkan Total Penjumlahan Semua Elemen
    cout<<"Rata - Rata      : "<<u<<endl;                           //3. Tampilkan Rata-Rata
    cout<<"Terkecil         : "<<min<<" sebanyak "<<fmin<<endl;     //4. Tampilkan Nilai Terkecil dan Banyaknya
    cout<<"Terbesar         : "<<max<<" sebanyak "<<fmax<<endl;     //5. Tampilkan Nilai Terbesar dan Banyaknya
    cout<<"Variansi         : "<<setprecision(4)<<s<<endl;                         //6. Tampilkan Variansi

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
int frekuensi(LarikInt data1, int N, int x) {
//Pencari Frekuensi
    //DEKLARASI
    int i;
    int count;
    //ALGORITMA
    count = 0;
    for(i=1;i<=N;i++) {
        if(data1[i] == x) {
            count++;
        }
    }
    return count;
    
}
void terkecil(LarikInt data1, int N, int &min1, int &fmin1) {
//4. Tampilkan Nilai Terkecil dan Banyaknya
    //DEKLARASI
    int i;     
    //ALGORITMA
    min1 = data1[1];
    for(i=2;i<=N;i++) {
        if(data1[i] < min1) {
            min1 = data1[i];
        }
    }
    fmin1 = frekuensi(data1, N, min1);    
}        
void terbesar(LarikInt data1, int N, int &max1, int &fmax1) {
//5. Tampilkan Nilai Terbesar dan Banyaknya    
    //DEKLARASI
    int i;
    //ALGORITMA
    max1 = data1[1];
    for(i=2;i<=N;i++) {
        if(data1[i] > max1) {
            max1 = data1[i];
        }
    }
    fmax1 = frekuensi(data1, N, max1);    
}        
float variansi(LarikInt data1, int N, float rata) {
//6. Tampilkan Variansi Nilainya
    //DEKLARASI
    int i;
    float e;
    //ALGORITMA
    e = 0;
    for(i=1;i<=N;i++) {
        e += pow(data1[i]-rata, 2);
    }
    return e/(N-1);
}                          