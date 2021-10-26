#pragma once
#include<iostream>

using namespace std;

template<class T>
class LinkList{
public:
    T data;
    LinkList *next;
    LinkList(){
        T = 0;
        next = NULL;
    }
    LinkList(T x){
        data = x;
        next = NULL;
    }
};