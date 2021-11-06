#include<fstream>
#include<iostream>

using namespace std;

int main(){
    ifstream infile("text3.txt", ios::in);
    if(!infile){
        cout << "文件打开失败" << endl;
        return 0;
    }
    ofstream outfile1("data1.dat", ios::trunc);
    if(!outfile1){
        cout << "打开文件失败" << endl;
        return 0;
    }
    ofstream outfile2("data2.dat", ios::trunc);
    if(!outfile2){
        cout << "打开文件失败" << endl;
        return 0;
    }
    char c;
    while(infile.get(c)){
        cout << c;
        outfile1 << c;
        outfile2.put(c);
    }
    infile.close();
    outfile1.close();
    outfile2.close();
}