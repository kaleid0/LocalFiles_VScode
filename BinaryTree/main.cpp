#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"
//#include"LinkList\\LinkList.h"

using namespace std;

const int num = 31;
int main(){
    int pre1[] = {1, 2, 4, 8, 5, 9, 10, 11, 3, 6};
    int in1[] = {8, 4, 2, 9, 5, 10, 11, 1, 6, 3};

    int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int grade[] = {3, 3, 1, 2, 0, 0, 0, 0, 0, 0};

    BinaryTree<int> *T1 = level_BuildBT(level, 10);
    BinaryTree<int> &T2 = *T1;
    BinarySearchTree *T3;
    T3 = BuildBinarySearchTree(pre1, 10);
    T3->PreOrder();
    T3->levelOrder();
    bool i = T1->isBST();
    cout << T1;
    system("pause");
}

