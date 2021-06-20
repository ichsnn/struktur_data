#include <iostream>

using namespace std;

const int BARIS = 100;  //BATAS MAKSIMAL BARIS YANG BISA DIISI
const int KOLLOM = 100; //BATAS MAKSIMAL KOLOM YANG BISA DIISI

int main(int argc, char const *argv[]) {
    int matriks[BARIS][KOLLOM] = { 
        {1, 2},
        {2, 3},         //Baris 3,   Kolom 2
        {3, 2},
    };    
    for(int i = 0; i<3; i++) {
        for(int j=0; j<2; j++) {
            cout<<matriks[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
