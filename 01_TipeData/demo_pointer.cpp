#include <iostream>

using namespace std;

int main() {

    short x;
    short y;
    short* p;

    x = 70; //x diisi 70
    cout<<"x : "<<x<<endl;  //tulis isi variabel x
    p = &x; //pointer p diisi alamat x
    cout<<"p : "<<*p<<endl; //menampilkan data di alamat p
    *p = 50;    //data di alamat p diubah menjadi 50
    cout<<"setelah perubahan data oleh pointer"<<endl;
    cout<<"x : "<<x<<endl;
    cout<<"p : "<<*p<<endl;

    return 0;

}