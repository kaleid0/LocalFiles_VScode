#pragma once
#include"queue.h"

template<class T>
void queue<T>::push(T x){
    if((_rear+1)%MAX==_front){
        cout << "队满" << endl;
    }
    que[_rear] = x;
    _rear = (_rear + 1) % MAX;
}

template<class T>
void queue<T>::pop(){
    if(this->empty()){
        cout << "队空" << endl;
    }
    _front = (_front+1) % MAX;
}

template<class T>
T queue<T>::front(){
    if(this->empty()){
        cout << "队空" << endl;
        exit(-1);
    }
    return que[_front];
}

template<class T>
T queue<T>::rear(){
    if(this->emmpty()){
        cout << "队空" << endl;
        exit(-1);
    }
    return que[(_rear - 1) % MAX];
}

template<class T>
bool queue<T>::empty(){
    if(_front==_rear)
        return true;
    return false;
}