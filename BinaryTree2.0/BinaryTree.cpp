#pragma once
#include"BinaryTree.h"




template<class T>
void BinaryTree<T>::PreOrder(){
    cout << "前序遍历:";
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this;
    S.push(NULL);
    while(p!=NULL){
        visit(p);
        if(p->rchild!=NULL)
            S.push(p->rchild);

        if(p->lchild!=NULL)
            p = p->lchild;
        else{
            p=S.top();
            S.pop();
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::InOrder(){
    cout << "中序遍历:";
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            S.pop();
            visit(p);
            p = p->rchild;
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::PostOrder(){
    cout << "后序遍历:";
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this, *r = NULL;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if(p->rchild!=NULL&&p->rchild!=r){
                p = p->rchild;
                S.push(p);
                p = p->lchild;
            }
            else{
                S.pop();
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::levelOrder(){
    cout << "层序遍历:";
    queue<BinaryTree<T> *> Q;
    BinaryTree<T> *p;
    Q.push(this);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        visit(p);
        if(p->lchild!=NULL)
            Q.push(p->lchild);
        if(p->rchild!=NULL)
            Q.push(p->rchild);
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::PreOrder(T *A){
    stack<BinaryTree<T> *> S;
    int i = 0;
    BinaryTree<T> *p = this;
    S.push(NULL);
    while(p!=NULL){
        A[i++] = p->data;
        if(p->rchild!=NULL)
            S.push(p->rchild);

        if(p->lchild!=NULL)
            p = p->lchild;
        else{
            p=S.top();
            S.pop();
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::InOrder(T *A){
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this;
    int i = 0;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            S.pop();
            A[i++] = p->data;
            p = p->rchild;
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::PostOrder(T *A){
    stack<BinaryTree<T> *> S;
    BinaryTree<T> *p = this, *r = NULL;
    int i = 0;
    while(p!=NULL||!S.empty()){
        if(p!=NULL){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if(p->rchild!=NULL&&p->rchild!=r){
                p = p->rchild;
                S.push(p);
                p = p->lchild;
            }
            else{
                S.pop();
                A[i++] = p->data;
                r = p;
                p = NULL;
            }
        }
    }
    cout << endl;
}

template<class T>
void BinaryTree<T>::levelOrder(T *A){
    queue<BinaryTree<T> *> Q;
    BinaryTree<T> *p;
    int i = 0;
    Q.push(this);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        A[i++] = p->data;
        if(p->lchild!=NULL)
            Q.push(p->lchild);
        if(p->rchild!=NULL)
            Q.push(p->rchild);
    }
    cout << endl;
}


template<class T>
BTree<T>* pre_in_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2){
    BTree<T> *root = new BTree<T>(pre[pre1]);
    int i;
    for (i = in1; in[i] != root->data; i++);
    int llen = i - in1;
    int rlen = in2 - i;
    if(llen)
        root->lchild = pre_in_BuildBT(pre, in, pre1 + 1, pre1 + llen, in1, in1 + llen - 1);
    else
        root->lchild = NULL;
    if(rlen)
        root->rchild = pre_in_BuildBT(pre, in, pre2 - rlen + 1, pre2, in2 - rlen + 1, in2);
    else
        root->rchild = NULL;
    return root;
}