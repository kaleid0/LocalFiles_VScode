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
        output << "学号:" << s.no << ',' << "姓名:" << s.name << endl;
        return output;
    }
    istream &operator>>(istream &input, student &s){
        cout << "学号:";
        input >> s.no;
        cout << "姓名:";
        input >> s.name;
        return input;
    }

int main(){
    fstream iofile("student.txt", ios::in | ios::out | ios::app);
    if(!iofile){
        cout <<"文件无法打开" << endl;
        return 0;
    }
    student s[10];
    for (int i = 0; i < 3; i++){
        iofile.write("success!", 8);
        cout << "输入:" << endl;
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