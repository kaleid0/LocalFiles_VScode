
#include<iostream>

using namespace std;

class person{
private:
    int no;
    char name[10];
public:
    void input(){
        cout << "���:";
        cin >> no;
        cout << "����:";
        cin >> name;
    }
    void disp(){
        cout << "���:" << no << ',';
        cout << "����:" << name << endl;
    }
};

class student:public person{
private:
    char depart[6];
    int degree;
public:
    void input(){
        person::input();
        cout << "�༶:";
        cin >> depart;
        cout << "�ɼ�:";
        cin >> degree;
    }
    void disp(){
        person::disp();
        cout << "�༶:" << depart << ',';
        cout << "�ɼ�:" << degree << endl;
    }
};

class teacher:public person{
private:
    char prof[10];
    char depart[10];
public:
    void input(){
        person::input();
        cout << "ְ��:";
        cin >> prof;
        cout << "����:";
        cin >> depart;
    }
    void disp(){
        person::disp();
        cout << "ְ��:" << prof << ',';
        cout << "����:" << depart << endl;
    }
};