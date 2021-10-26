#include"stack.h"

template<class T>
void stack<T>::push(class T){
    if(top==MAX-1){
        cout << "ջ��" << endl;
        return;
    }
    sta[++top] = T;
}

template<class T>
void stack<T>::pop(){
    if(this->empty()){
        cout << "ջ��" << endl;
        return;
    }
    top--;
}

template<class T>
T stack<T>::gettop(){
    if(this.empty()){
        cout << "ջ��" << endl;
        return;
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