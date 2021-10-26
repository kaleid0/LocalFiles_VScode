#pragma once
#include<iostream>
#include"..\Stack\stack.h"
#include"..\Stack\stack.cpp"
#include"..\Queue\queue.h"
#include"..\Queue\queue.cpp"

using namespace std;

template<class T>
class BinaryTree{
public:
    // virtual friend BinaryTree<T> *pre_in_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2) = 0;
    // virtual friend BinaryTree<T> *post_in_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2) = 0;
    // virtual friend BinaryTree<T> *level_in_BuildBT(T level[], T in[], int level1, int level2, int in1, int in2) = 0;
    // virtual friend BinaryTree<T> *level_BuildBT(T A[], int n) = 0; //层序构造完全二叉树
    virtual void visit() = 0;

    void PreOrder();
    void InOrder();
    void PostOrder();
    void levelOrder();
    void PreOrder(T *A);
    void InOrder(T *A);
    void PostOrder(T *A);
    void levelOrder(T *A);
};

template<class T>
class BTree:public BinaryTree<T>{
public:
    T data;
    BTree<T> *lchild;
    BTree<T> *rchild;

    BTree(){
        data = 0;
        lchild = NULL;
        rchild = NULL;
    }
    BTree(T r){
        data = r;
        lchild = NULL;
        rchild = NULL;
    }

    virtual void visit(){
        cout << this->data << ',';
    }

    friend BTree<T> *pre_in_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2);
    friend BTree<T> *post_in_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2);
    friend BTree<T> *level_in_BuildBT(T level[], T in[], int level1, int level2, int in1, int in2);
    friend BTree<T> *level_BuildBT(T A[], int n); //层序构造完全二叉树

    // virtual void PreOrder();
    // virtual void InOrder();
    // virtual void PostOrder();
    // virtual void levelOrder();
    // virtual void PreOrder(T *A);
    // virtual void InOrder(T *A);
    // virtual void PostOrder(T *A);
    // virtual void levelOrder(T *A);

};
