#include<fstream>
#include<iostream>

using namespace std;

void dec_bin(int x,char *c,int &n){
    int i = 0;
    while(x!=0){
        c[i++] = x % 2 + '0';
        x /= 2;
    }
    n = i-1;
}

void dec_oct(int x,char *c,int &n){
    int i = 0;
    while(x!=0){
        c[i++] = x % 8 + '0';
        x /= 8;
    }
    n = i-1;
}

void dec_hex(int x,char *c,int &n){
    int i = 0;
    while(x!=0){
        int t = x % 16;
        if(t<10)
            c[i++] = t + '0';
        else
            c[i++] = t + 'A' - 10;
        x /= 16;
    }
    n = i-1;
}


void converse(){
    cout << "输入一个整数:";
    ofstream file;
    int x;
    cin >> x;
    file.open("text2.txt", ios::trunc);
    file << "dec:" << x << endl;
    char c[20];
    int n = 0;
    dec_bin(x, c, n);
    file << "bin:";
    for (int i = n; i >= 0; i--)
        file.put(c[i]);
    file << endl;
    dec_oct(x, c, n);
    file << "oct:";
    for (int i = n; i >= 0; i--)
        file.put(c[i]);
    dec_hex(x, c, n);
    file << endl;
    file << "hex:";
    for (int i = n; i >= 0; i--)
        file.put(c[i]);
    file << endl;
    file.close();
}

int main(){
    converse();
}



