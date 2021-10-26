#pragma once
#include<iostream>

using namespace std;

//const int MAX = 100;

template<class T>
class queue{
private:
    T que[MAX];
    int _front;
    int _rear;
public:
    queue(){
        _front = 0;
        _rear = 0;
    }
    void push(T x);
    void pop();
    T front();
    T rear();
    bool empty();
};