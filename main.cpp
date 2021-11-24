#include<iostream>
#include<string>

using namespace std;


class SintRING{
private:
    char *str;
    int length;
public:
    SintRING(char *s){
        length = 0;
        for (int i = 0; s[i] != '\0'; i++)
            length++;
        str = new char[length];
        for (int i = 0; i<length; i++)
            str[i] = s[i];
    }
    SintRING(SintRING &s){
        length = s.length;
        str = new char[length];
        for (int i = 0; i < length; i++){
            str[i] = s[i];
        }
    }
    ~SintRING(){
        if(str!=NULL)
            delete[] str;
    }
    char &operator[](int pos){
        if(pos<0&&pos>=length){
            cout << "¡¤???????";
            exit(0);
        }
        return str[pos];
    }
    friend ostream &operator<<(ostream &out, SintRING &s);
};

ostream &operator<<(ostream &out, SintRING &s){
    for (int i = 0; i < s.length; i++)
        cout << s.str[i];
}

// template<class int>
// class base1{
// public:
//     const int base1_data;
//     base1(int a):base1_data(a){
//         cout << "base1 constuctor" << endl;
//     }
//     void print(){
//         cout << "base1" << endl;
//     }
// };

// template<class int>
// class base2{
// public:
//     const int base2_data;
//     base2(int a):base2_data(a){
//         cout << "base2_constuctor" << endl;
//     }
//     void print(){
//         cout << "base2" << endl;
//     }
// };

// template<class int>
// class derived:public base1<int>{
// public:
//     const int derived_data;
//     derived(int a, int b):derived_data(a), base<int>::base1(b){
//         cout << "derived constructor" << endl;
//     }
//     void print(){
//         cout << "derived" << endl;
//     }
//     void f(){
//         base<int>1::print();
//         cout << base1<int>::base1_data << endl;
//     }
//     friend ostream &operator<<(ostream &out,derived<int> &d){
//         out << "base:" <<d. base1<int>::base1_data << endl
//             << "derived:" << d.derived_data << endl;
//     }
// };

// class base1{
// public:
//     const int base1_data;
//     base1(int a):base1_data(a){
//         cout << "base1 constuctor" << endl;
//     }
//     void print(){
//         cout << "print base1" << endl;
//     }
// };

// class base2{
// public:
//     const int base2_data;
//     base2(int a):base2_data(a){
//         cout << "base2_constuctor" << endl;
//     }
//     void print(){
//         cout << "print base2" << endl;
//     }
// };

// class derived:public base1,public base2{
// public:
//     const int derived_data;
//     derived(int a, int b, int c):derived_data(a), base1(b),base2(c){
//         cout << "derived constructor" << endl;
//     }
//     void print(){
//         cout << "print derived" << endl;
//     }
//     void f(){
//         base1::print();
//         base2::print();
//     }
//     friend ostream &operator<<(ostream &out,derived &d){
//         out << "base1:" << d.base1_data << endl
//             << "base2:" << d.base2_data << endl
//             << "derived:" << d.derived_data << endl;
//     }
// };

double e_(int x){
    int n = 1;
    double result = 1;
    double t1 = 1;
    double t2 = 1;
    while((t1/t2)>1e-9){    
        t1 *= x;
        t2 *= n;
        n++;
        result += t1 / t2;
    }
    return result;
}

class Exception{
    string msg;
public:
    Exception() : msg("Except:Myexcept!"){
        cout << "Except Constructor" << msg << endl;
    }
    Exception(const Exception &e){
        cout << "Copy Constructor" << endl;
    }
    void what(){
        cout << msg << endl;
    }
};

class A{
public:
    A(){
        cout << "A Constructor" << endl;
    }
    ~A(){
        cout << "A Desconstructor" << endl;
    }
};

void fun(){
    A a;
    cout << "Before Except" << endl;
    throw Exception();
    cout << "After Except" << endl;
}

class base{
    public:
    virtual void fun(int a,int i=10){
        cout << "base" << endl;
    }
};

class derived:public base{
    public:
    void fun(int i=22){
        cout << i << endl;
        cout << "derived" << endl;
    }
};

int f(int a,int b){
    if(a>b)
        return a + b;
    else
        f(++a, --b);
    return a * f(a, b);
}

int main(){
    cout << f(1, 3);
}