#include"stack.h"

template<class T>
void stack<T>::push(T x){
    if(_top==MAX-1){
        cout << "栈满" << endl;
        return;
    }
    sta[++_top] = x;
}

template<class T>
void stack<T>::pop(){
    if(this->empty()){
        cout << "栈空" << endl;
        return;
    }
    _top--;
}

template<class T>
T stack<T>::top(){
    if(this->empty()){
        cout << "栈空" << endl;
        exit(-1);
    }
    return sta[_top];
}

template<class T>
bool stack<T>::empty(){
    if(_top==-1)
        return true;
    else
        return false;
}