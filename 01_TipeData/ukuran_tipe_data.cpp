//Menampilkan ukuran tipe data bilangan

#include <iostream>

using namespace std;

int main() {

    cout<<"Tipe Integer (Signed)"<<endl;
    cout<<"signed char            : "<<sizeof(signed char)<<endl;
    cout<<"signed short int       : "<<sizeof(signed short int)<<endl;
    cout<<"signed int             : "<<sizeof(signed int)<<endl;
    cout<<"signed long int        : "<<sizeof(signed long int)<<endl;
    cout<<"signed long long int   : "<<sizeof(signed long long int)<<endl;
    cout<<endl;

    cout<<"Tipe Integer (Unsigned)"<<endl;
    cout<<"unsigned char          : "<<sizeof(unsigned char)<<endl;
    cout<<"unsigned short int     : "<<sizeof(unsigned short int)<<endl;
    cout<<"unsigned int           : "<<sizeof(unsigned int)<<endl;
    cout<<"unsigned long int      : "<<sizeof(unsigned long int)<<endl;
    cout<<"unsigned long long int : "<<sizeof(unsigned long long int)<<endl;
    cout<<endl;

    cout<<"Tipe Data Pecahana - Desimal"<<endl;
    cout<<"float                  : "<<sizeof(float)<<endl;
    cout<<"double                 : "<<sizeof(double)<<endl;
    cout<<"long double            : "<<sizeof(long double)<<endl;
    
    return 0;

}