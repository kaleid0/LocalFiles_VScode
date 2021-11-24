#include"vector.h"
#include<iostream>

using namespace std;

int main(){
    vector<int> a(10);
    a.resize(100);
    for (int i = 0; i < 100; i++){
        a[i] = i + 10;
    }
    vector<int> b = a;
    for (int i = 0; i < 100; i++)
        cout << b[i] << ',';
    cout << endl;
}