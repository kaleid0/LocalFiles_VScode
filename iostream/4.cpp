#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

bool add(char A[],char B[],int lengthA,int lengthB){
    int d = lengthA - lengthB;
    bool r = false;
    int i = lengthA - 1;
    for (; i >= d; i--) {
        int a = r ? A[i] + B[i-d] + 1 - '0' * 2 : A[i] + B[i-d] - '0' * 2;
        if (a > 9) {
            a %= 10;
            r = true;
        }
        else
            r = false;
        A[i] = a + '0';
    }
    while(r&&i>=0){
        int a = A[i] + 1;
        if(a>9)
            A[i] = '0';
        else{
            A[i] = a + '0';
            r = false;
        }
        i--;
    }
    return r;
}

int main() {
    fstream file;
    file.open("file.txt", ios::in | ios::out);
    char A[100], B[100];
    int lengthA = 0, lengthB = 0;
    char c;
    while ((c = file.get() )&& c != '\n') 
        A[lengthA++] = c;
    while ((c = file.get() )&& c != EOF&&c!='\n')
        B[lengthB++] = c;
    fstream a;
    a.open("file.txt", ios::app);
    a.seekp(0, ios::end);
    a << endl;
    bool r;
    int length;
    if(lengthA>lengthB){
        r = add(A, B, lengthA, lengthB);
        length = lengthA;
        if(r)
            a << 1;
        a.write(A, length);
    }
    else{
        r = add(B, A, lengthB, lengthA);
        length = lengthB;
        if(r)
            a << 1;
        a.write(B, length);
    }
}