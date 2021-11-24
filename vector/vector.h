#pragma once
#include<iostream>

using namespace std;

template<class T>
class vector{
public:
    vector():size(0),list(NULL){}
    vector(int n){
        list = new T[n];
        size = n;
    }
    vector(vector<T>& v){
        size = v.size;
        list = new T[size];
        for (int i = 0; i < size; i++){
            list[i] = v[i];
        }
    }
    ~vector(){
        delete[] list;
    }
    void resize(int x);
    T& operator[](int x){
        if(x>=size)
            exit(0);
        return list[x];
    }
    operator T*(){
        return list;
    }
    vector<T> &operator=(const vector<T> &v);

private:
    int *list;
    int size;
};

template<class T>
void vector<T>::resize(int x){
    if(x==size)
        return;
    T *newlist = new T[x];
    size = x;
    int n = x < size ? x : size;
    for (int i = 0; i < n;i++){
        newlist[i] = list[i];
    }
    delete[] list;
    list = newlist;
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T> &v){
    if(size!=v.size){
        size = v.size;
        delete[] list;
        list = new T[size];
    }
    for (int i = 0; i < size; i++)
        list[i] = v[i];
    return *this;
}
