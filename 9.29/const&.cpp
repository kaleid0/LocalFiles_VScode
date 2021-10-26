#include<iostream>

using namespace std;

int main(){
    cout << "dksl" << endl;
    const double &d = 12.3;
    double dr = 12.4;
    double *ptr = &dr;
    cout << &dr << endl;
    cout << &d << endl;
}