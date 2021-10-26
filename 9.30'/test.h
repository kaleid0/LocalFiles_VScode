
#include<iostream>

using namespace std;

class person{
private:
    int no;
    char name[10];
public:
    void input(){
        cout << "编号:";
        cin >> no;
        cout << "姓名:";
        cin >> name;
    }
    void disp(){
        cout << "编号:" << no << ',';
        cout << "姓名:" << name << endl;
    }
};

class student:public person{
private:
    char depart[6];
    int degree;
public:
    void input(){
        person::input();
        cout << "班级:";
        cin >> depart;
        cout << "成绩:";
        cin >> degree;
    }
    void disp(){
        person::disp();
        cout << "班级:" << depart << ',';
        cout << "成绩:" << degree << endl;
    }
};

class teacher:public person{
private:
    char prof[10];
    char depart[10];
public:
    void input(){
        person::input();
        cout << "职称:";
        cin >> prof;
        cout << "部门:";
        cin >> depart;
    }
    void disp(){
        person::disp();
        cout << "职称:" << prof << ',';
        cout << "部门:" << depart << endl;
    }
};