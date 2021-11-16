#include<iostream>
#include<fstream>

using namespace std;

class student{
    int no;
    char name[10];
public:
    friend ostream &operator<<(ostream &output, student &s);
    friend istream &operator>>(istream &input, student &s);
};

    ostream &operator<<(ostream &output, student &s){
        output << "ѧ��:" << s.no << ',' << "����:" << s.name << endl;
        return output;
    }
    istream &operator>>(istream &input, student &s){
        cout << "ѧ��:";
        input >> s.no;
        cout << "����:";
        input >> s.name;
        return input;
    }

int main(){
    fstream iofile("student.txt", ios::in | ios::out | ios::app);
    if(!iofile){
        cout <<"�ļ��޷���" << endl;
        return 0;
    }
    student s[10];
    for (int i = 0; i < 3; i++){
        iofile.write("success!", 8);
        cout << "����:" << endl;
        cin >> s[i];
        iofile << s[i] << endl;
    }
    iofile.seekp(0, ios::beg);
    char c[20];
    while(iofile.getline(c,20)){
        cout << c;
    }
    
    cout << endl;
}