#include<iostream>
#include<fstream>

using namespace std;

void addlineNo(char *filename){
    ifstream infile(filename);
    ofstream outfile("text4.txt", ios::trunc);
    char c[100];
    int i = 0;
    while(infile.getline(c, 100)){
        outfile << i++ << ' ' << c << endl;
    }
}


int main(){
    addlineNo("text3.txt");
}