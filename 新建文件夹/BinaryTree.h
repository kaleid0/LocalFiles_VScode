#pragma once
#include<iostream>
#include"..\Stack\stack.h"
#include"..\Stack\stack.cpp"
#include"..\Queue\queue.h"
#include"..\Queue\queue.cpp"

using namespace std;

int maxsize = 100;

template<class T>
class BinaryTree{
public:
    T data;
    BinaryTree<T> *lchild;
    BinaryTree<T> *rchild;

    BinaryTree(){
        data = 0;
        lchild = NULL;
        rchild = NULL;
    }
    BinaryTree(T r){
        data = r;
        lchild = NULL;
        rchild = NULL;
    }
    friend BinaryTree<T> *pre_in_BuildBT(T pre[], T in[], int pre1, int pre2, int in1, int in2);
    friend BinaryTree<T> *post_in_BuildBT(T post[], T in[], int post1, int post2, int in1, int in2);
    friend BinaryTree<T> *level_in_BuildBT(T level[], T in[], int in1, int in2, int n);
    friend BinaryTree<T> *level_BuildBT(T A[], int n); //层序构造完全二叉树
    void visit(BinaryTree<T> *t){
        cout << t->data << ',';
    }
    void PreOrder();
    void InOrder();
    void PostOrder();
    void levelOrder();
    void PreOrder(T *A);
    void InOrder(T *A);
    void PostOrder(T *A);
    void levelOrder(T *A);
    friend BinaryTree<T> *treetoBinarytree(T level[], int grade[], int k);//树的层序和度构造二叉树
    void disp(int deep);
    BinaryTree<T> *findk(BinaryTree<int> t, int k);//找到第K小的元素
    int WPL(int k = 0);//带权路径长度
    void swapBinarytree();//交换所有左右子树
    int generation();//递归求高度
    int hight();//非递归求高度
    bool iscomplete();//是否是完全二叉树
    int dson();//有多少双分支(度为2)的结点
    void deletevalue(T x);
    void deleteroot();
    void printroute(T x);//求路径
    BinaryTree<T> *ancestor(BinaryTree<T> *p, BinaryTree<T> *q);//找到共同祖先
    BinaryTree<T> *find(T x);//找到值为x的结点
    int width();//求宽度
    BinaryTree<T> *linkLeaf();
    bool isSame(BinaryTree<T> *tr);
    int level(BinaryTree<T> *p, int n = 1); //所在层次
    bool isbalance(int &h, bool &balance);
    virtual void Insert(int x);
    void lastgen();
};

void preTopost(int pre[], int begin, int end);

template<class T>
class HFMtree:public BinaryTree<T>{
public:
    HFMtree(){
        this->data = 0;
        this->lchild = NULL;
        this->rchild = NULL;
    }
    HFMtree(T r){
        this->data = r;
        this->lchild = NULL;
        this->rchild = NULL;
    }
    friend HFMtree<T>* buildHFM(T A[], int n);//构造哈夫曼树
};


class BinarySearchTree:public BinaryTree<int>{
public:
    BinarySearchTree(){
        this->data = 0;
        this->lchild = NULL;
        this->rchild = NULL;
    }
    BinarySearchTree(int r){
        this->data = r;
        this->lchild = NULL;
        this->rchild = NULL;
    }
    friend BinarySearchTree *BuildBinarySearchTree(int A[], int n);
    virtual void Insert(int x);
    void showk(int k);//由大到小输出BST大于等于K的节点
};

template<class T>
class ThreadTree{
public:
    T data;
    bool ltag, rtag;
    ThreadTree<T> *lchild;
    ThreadTree<T> *rchild;

    ThreadTree(){
        this->data = 0;
        lchild = NULL;
        rchild = NULL;
        ltag = rtag = false;
    }
    ThreadTree(T r){
        this->data = r;
        lchild = NULL;
        rchild = NULL;
        ltag = rtag = false;
    }
    ThreadTree(BinaryTree<T> *tr);

    void preThread();
    void preThread(ThreadTree<T> *&pre);
    void inThread();
    void inThread(ThreadTree<T> *&pre);
    void postThread();
    void postThread(ThreadTree<T> *&pre);
};

// template<class T>
// class ThreadBinaryTree:public BinaryTree<T>{
// public:
//     bool ltag;
//     bool rtag;

    // ThreadBinaryTree(){
    //     this->data = 0;
    //     this->lchild = NULL;
    //     this->rchild = NULL;
    //     ltag = false;
    //     rtag = false;
    // }
    // ThreadBinaryTree(T x){
    //     this->data = x;
    //     this->lchild = NULL;
    //     this->rchild = NULL;
    //     ltag = false;
    //     rtag = false;
    // }
    // ThreadBinaryTree(ThreadBinaryTree<T> *tr){
    //     this->data = tr->data;
    //     if(tr.lchild!=NULL){   
    //         ThreadBinaryTree l(dynamic_cast<ThreadBinaryTree<T> *>(tr.lchild));
    //         this->lchild = &l;
    //     }
    //     else
    //         this->lchild = NULL;
    //     if(tr.rchild!=NULL){   
    //         ThreadBinaryTree r(dynamic_cast<ThreadBinaryTree<T> *>(tr.rchild));
    //         this->rchild = &r;
    //     }
    //     else
    //         this->rchild = NULL;
    //     ltag = false;
    //     rtag = false;
    // }
    // ThreadBinaryTree(BinaryTree<T> *tr){
    //     this->data = tr.data;
    //     if(tr.lchild!=NULL){   
    //         ThreadBinaryTree l(dynamic_cast<ThreadBinaryTree<T> *>(tr.lchild));
    //         this->lchild = &l;
    //     }
    //     else
    //         this->lchild = NULL;
    //     if(tr.rchild!=NULL){   
    //         ThreadBinaryTree r(dynamic_cast<ThreadBinaryTree<T> *>(tr.rchild));
    //         this->rchild = &r;
    //     }
    //     else
    //         this->rchild = NULL;
//     //     ltag = false;
//     //     rtag = false;
//     // }
// };

// typedef struct BinaryTreeNode{
//     BinaryTreeNode(){
//         data = 0;
//         lchild = NULL;
//         rchild = NULL;
//     }
//     BinaryTreeNode(int r){
//         data = r;
//         lchild = NULL;
//         rchild = NULL;
//     }
//     int data;
//     struct BinaryTreeNode *lchild;
//     struct BinaryTreeNode *rchild;
// } *BinaryTree, BinaryTreeNode;

// typedef struct node{
//     node(){
//         lchild = NULL;
//         rchild = NULL;
//     }
//     node(char c){
//         data = c;
//         lchild = NULL;
//         rchild = NULL;
//     }

//     char data;
//     struct node *lchild, *rchild;
// } node;

// typedef struct Tree{
//     int data;
//     struct Tree *firstchild, *nextsibling;
// } *Tree, TreeNode;

// BinaryTree BuildBinarytree(int pre[], int in[], int pre1, int pre2, int in1, int in2);
// template <class T>
// void visit(T t);
// template <class T>
// void InOrder(T t);
// void PostOrder(BinaryTree T);
// void levelOrder(BinaryTree T);
// BinaryTree treetoBinarytree(int level[], int grade[], int k);//树的层序和度构造二叉树
// void showk(BinaryTree T, int k);//由大到小输出BST大于等于K的节点
// BinaryTreeNode *findk(BinaryTree T, int k);//找到第K小的元素
// int WPL(BinaryTree T, int k = 0);//带权路径长度
// void swapBinarytree(BinaryTree T);//交换所有左右子树
// BinaryTree buildHFM(int A[], int n);//构造哈夫曼树
// int generation(BinaryTree T);

// BinaryTreeNode *findk(BinaryTree T, int k){

// }








