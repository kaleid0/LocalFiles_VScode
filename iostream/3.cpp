#include<fstream>
#include<iostream>

using namespace std;

int main(){
    fstream infile("text3.txt", ios::in);
    if(!infile){
        cout << "文件打开失败" << endl;
        return 0;
    }
    streampos begin = infile.tellg();
    infile.seekg(0, ios::end);
    streampos end = infile.tellg();
    cout << begin << ' ' << end << endl;
    infile.seekg(0, ios::beg);
    char c;
    int i = 0;
    while(infile.get(c)){
        cout << ++i << ":" << c << endl;
    }
    cout << endl;
}