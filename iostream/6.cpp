#include<iostream>
#include<fstream>

using namespace std;

template<class T>
class a{
private:
    T *p;
    int length;
public:
    a(int n){
        p = new T(10);
        length = n;
    }
    ~a(){
        delete[] p;
    }
    T &operator[](int x){
        if(x>=length){
            cout << "·ÃÎÊÔ½½ç" << endl;
            return *p;
        }
        return *(p + x);
    }
    int size(){
        return length;
    }
    //friend ostream &operator<<(ostream &out, a t);
    //friend istream &operator>>(istream &in, a t);
};

template<class T>
istream &operator>>(istream &in, a<T> t){
    
}


int main(){
    a<int> t(2);
    for (int i = 0; i < 10; i++){
        cin >> t[i];
    }
    for (int i = 0; i < 10; i++){
        cout << t[i];
    }
}