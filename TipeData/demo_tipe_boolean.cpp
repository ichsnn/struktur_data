#include <iostream>

using namespace std;

int main() {

    bool dewasa;
    int umur;

    cout<<"Umur : ";cin>>umur;

    if(umur >= 17) dewasa = true;
    else dewasa = false;

    if(dewasa) {
        cout<<"Anda sudah dewasa\n";
    } else cout<<"Anda belum dewasa\n";


    return 0;
    
}