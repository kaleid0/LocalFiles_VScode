#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"
//#include"LinkList\\LinkList.h"

using namespace std;

const int num = 31;
int main(){
    int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int pre1[] = {1, 2, 4, 8, 5, 9, 10, 11, 3, 6};
    int in1[] = {8, 4, 2, 9, 5, 10, 11, 1, 6, 3};

    BinaryTree<int> *T2 = pre_in_BuildBT(pre1, in1, 0, 9, 0, 9);
    BinaryTree<int> *T1 = level_BuildBT(level, 9);

    T2->levelOrder();
    int h = 0;
    bool balance = true;
    T2->printbalance(h, balance);

    system("pause");
}

