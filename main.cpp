#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

void add(){
    fstream file;
    file.open("file.txt");
    if(!file){
        cout << "error";
        return;
    }
    int A[100], B[100];
    int lengthA = 0, lengthB = 0, length, x;
    char c;
    while ((c = file.get())&&c!='\n')
        A[lengthA++] = (int)c - 48;
    while((c=file.get())&&c!=EOF)
        B[lengthB++] = int(c) - 48;
    int d = abs(lengthA - lengthB);
    length = lengthA > lengthB ? lengthA - 1 : lengthB - 1;
    bool r = false;
    for (int i = length; i >= 0; i--){
        int a = (r ? A[i] + B[i - d] + 1 : A[i] + B[i - d]);
        if(a>9){
            a = a % 10;
            r = true;
        }
        else
            r = false;
        A[i] = a;
    }
    file.put('\n');
    for (int i = 0; i < length; i++)
        file << A[i];
    file.close();
}

int main(){
    fstream file;
    file.open("file.txt");
    if(!file){
        cout << "error";
    }
    int A[100], B[100];
    int lengthA = 0, lengthB = 0, length, x;
    char c;
    while ((c = file.get())&&c!=' ')
        A[lengthA++] = (int)c - 48;
    while((c=file.get())&&c!=EOF)
        B[lengthB++] = int(c) - 48;
    int d = abs(lengthA - lengthB);
    length = lengthA > lengthB ? lengthA - 1 : lengthB - 1;
    bool r = false;
    for (int i = length; i >= d; i--){
        int a = (r ? A[i] + B[i - d] + 1 : A[i] + B[i - d]);
        if(a>9){
            a = a % 10;
            r = true;
        }
        else
            r = false;
        A[i] = a;
    }
    //file.put('\n');
    fstream a;
    a.open("file1.txt");
    a.get();
    file.seekp(0, ios::end);
    for (int i = 0; i < length; i++){
        char c = A[i] + '0';
        a<< c;
    }
    file << "#3333333333333333333333333";
    file.close();
    
}


