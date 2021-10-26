#include<iostream>

using namespace std;

const int MAX = 100;

template<class T>
class stack{
private:
    T sta[MAX];
    int top;
public:
    stack(){
        top = -1;
    }
    void push(T x);
    void pop();
    T gettop();
    bool empty();
};





template<class T>
void stack<T>::push(T x){
    if(top==MAX-1){
        cout << "???¨²" << endl;
        return;
    }
    sta[++top] = x;
}

template<class T>
void stack<T>::pop(){
    if(this->empty()){
        cout << "????" << endl;
        return;
    }
    top--;
}

template<class T>
T stack<T>::gettop(){
    if(this->empty()){
        cout << "????" << endl;
        exit(1);
    }
    return sta[top];
}

template<class T>
bool stack<T>::empty(){
    if(top==-1)
        return true;
    else
        return false;
}