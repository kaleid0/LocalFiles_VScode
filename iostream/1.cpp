#include<iostream>
#include<fstream>
#include<vector>

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

void showhere(char *filename){
    ifstream infile(filename);
    ofstream outfile("text5.txt", ios::trunc);
    char c;
    while(!infile.eof()){
        streampos here = infile.tellg();
        infile.get(c);
        if(c=='\n'){
            outfile << here << endl;
        }
    }
}

void getsize(char *filename){
    ifstream infile(filename);
    streampos begin = infile.tellg();
    infile.seekg(0, ios::end);
    streampos end = infile.tellg();
    cout << begin << ' ' << end << endl;
}


int main(){
    addlineNo("text3.txt");
    showhere("text3.txt");
    getsize("text3.txt");

    vector<int> v = {1, 2, 3, 4};
}