#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAKS = 100;

struct kuliah {
    string nama_matkul;
    string nama;
    int nim;
    int sks;    
    char nilai;
    float ip;
};

typedef kuliah tabel[MAKS][MAKS];

//DEKLARASI PURWARUPA FUNGSI YANG AKAN DIGUNAKAN
void mataKuliah(tabel &tbl, int n);
void mahasiswa(tabel &tbl, int n);
void nilai(tabel &tbl, int b, int k);
void gambar(tabel tbl, int b, int k);

//PROGRAM UTAMA
int main(int argc, char const *argv[]) {
    system("cls");

    //DEKLARASI
    tabel data;    
    int banyak_matkul;
    int banyak_mhs;
    int baris;
    int kolom;

    //ALGRORITMA    
    cout<<"Banyak Mata Kuliah \t: ";cin>>banyak_matkul;     
    mataKuliah(data, banyak_matkul);

    cout<<endl;
    cout<<"Banyak Mahasiswa \t: ";cin>>banyak_mhs;     
    mahasiswa(data, banyak_mhs);

    baris = banyak_mhs;
    kolom = banyak_matkul;

    cout<<endl;
    nilai(data, baris, kolom);

    cout<<endl;
    gambar(data, baris, kolom);

    return 0;
}


void mataKuliah(tabel &tbl, int n) {
//input daftar matakuliah (nama matakuliah dan SKS)
    //DEKLARASI
    int i, j;

    //ALGORITMA
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(i==1) {
                fflush(stdin);
                cout<<"Nama Mata Kuliah "<<j<<"\t: ";getline(cin, tbl[i][j].nama_matkul);
                cout<<"SKS Mata Kuliah "<<j<<"\t: ";cin>>tbl[i][j].sks;
            }
        }
    }     
}
void mahasiswa(tabel &tbl, int n) {
//input data mahasiswa (nim dan nama)    
    //DEKLARASI
    int i, j;
    //ALGORITMA
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            if(j==1) {                            
                cout<<"Nim Mahasiswa  "<<i<<"\t: ";cin>>tbl[i][j].nim;
                fflush(stdin);
                cout<<"Nama Mahasiswa "<<i<<"\t: ";getline(cin, tbl[i][j].nama);
            }
        }        
    }
}
void nilai(tabel &tbl, int b, int k) {
//input nilai mahasiswa
    //DEKLARASI
    int i, j;
    //ALGORITMA    
    for(i=1;i<=b;i++) {
        for(j=1;j<=k;j++) {                                                    
            cout<<"Nilai Mhs "<<tbl[i][1].nim<<" mata kuliah "<<tbl[1][j].nama_matkul<<"\t";
            if(tbl[1][j].nama_matkul.size()<=8) cout<<"\t";
            cout<<": ";cin>>tbl[i][j].nilai;            
        }
        cout<<endl;
    }
}
void gambar(tabel tbl, int b, int k) {
//tabel ouput    
    //DEKLARASI
    int i, j;  
    int sum_sks = 0;             

    //ALGORITMA
    for(i=1;i<=k;i++) {                     
        if(i==1) cout<<"\t\t";
        cout<<tbl[1][i].nama_matkul<<"\t";                     
    }
    cout<<"IP";
    cout<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    for(i=1;i<=k;i++) {
        sum_sks += tbl[1][i].sks;        
    }  

    k++;
    for(i=1;i<=b;i++) {         
        tbl[i][k].ip = 0;
        for(j=1;j<=k;j++) {
            if(j<k) {
                switch (tbl[i][j].nilai) {
                case 'A':
                    tbl[i][k].ip += 4.0 * tbl[1][j].sks;                            
                    break;
                case 'B':
                    tbl[i][k].ip += 3.0 * tbl[1][j].sks;                            
                    break;
                case 'C':
                    tbl[i][k].ip += 2.0 * tbl[1][j].sks;                            
                    break;
                case 'D':
                    tbl[i][k].ip += 1.0 * tbl[1][j].sks;                            
                    break;                            
                default:
                    tbl[i][k].ip += 0;                            
                    break;
                }
            }           
        }     
        tbl[i][k].ip = (tbl[i][k].ip / sum_sks);  
    }
    for(i=1;i<=b;i++) {         
        for(j=1;j<=k;j++) {
            if(j<k) {
                if(j==1) {
                    cout<<tbl[i][j].nim<<"\t";
                }                       
                cout<<tbl[i][j].nilai<<"\t"; 
                if(tbl[1][j].nama_matkul.size()>5) cout<<"\t";
            } else {
                cout<<fixed<<setprecision(2)<<tbl[i][j].ip;
            }
        }        
        cout<<endl;               
    }
}    