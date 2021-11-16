#pragma once
#include<iostream>
#include"..\Stack\stack.h"
#include"..\Stack\stack.cpp"
#include"..\Queue\queue.h"
#include"..\Queue\queue.cpp"

using namespace std;

const int maxsize = 100;

template<class T>
class Tree;//二叉链表存储树
template <class T>
class BinaryTree;//二叉树
template <class T>
class HFMtree;//哈夫曼树
class BinarySearchTree;//二叉搜索树,二叉排序树
template <class T>
class ThreadTree;//线索二叉树

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
    void disp(int deep);//输出树存储的表达式
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
    BinaryTree<T> *linkLeaf();//链接叶结点
    bool isSame(BinaryTree<T> *tr);
    int level(BinaryTree<T> *p, int n = 1); //所在层次
    bool isbalance(int &h);
    virtual void Insert(int x);
    void lastgen();//输出最后一层结点
    void printbalance(int &h, bool &balance); //输出平衡节点(非平衡二叉树的根节点依然可能是平衡节点)
    friend ostream &operator<<(ostream &out, BinaryTree<T> tr);
};

void preTopost(int pre[], int begin, int end);//满二叉树前序序列转后序序列

template<class T>
class HFMtree:public BinaryTree<T>{
public:
    HFMtree(){
        BinaryTree<T>::data = 0;
        BinaryTree<T>::lchild = NULL;
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
        data = 0;
        lchild = NULL;
        rchild = NULL;
        ltag = rtag = false;
    }
    ThreadTree(T r){
        data = r;
        lchild = NULL;
        rchild = NULL;
        ltag = rtag = false;
    }
    ThreadTree(BinaryTree<T> *tr);

    void preThread();//前序线索化
    void preThread(ThreadTree<T> *&pre);
    void inThread();//中序线索化
    void inThread(ThreadTree<T> *&pre);
    void postThread();//后续线索化
    void postThread(ThreadTree<T> *&pre);
};


template<class T>
class Tree{
public:
    T data;
    Tree *firstchild, *nextsibling;

    Tree(){
        data = 0;
        firstchild = nextsibling = NULL;
    }
    Tree(T r){
        data = r;
        firstchild = nextsibling = NULL;
    }

    void visit(){
        cout << data << ',';
    }

    Tree(BinaryTree<T> *tr);

    void LevelOrder();
    void PreOrder();

    int depth();//二叉链表对应树的高度
    friend Tree<T> *level_grade_build(T level[], int grade[], int n);//给定层序序列,结点的度构造二叉链表树
    friend Tree<T> *level_grade_build2(T level[], int grade[], int n);
    bool isSame(Tree<T> *tr);
};
