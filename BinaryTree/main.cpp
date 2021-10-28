#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"
//#include"LinkList\\LinkList.h"

using namespace std;

const int num = 31;
int main(){
    int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int pre1[] = {1, 2, 4, 6, 7, 5, 3};
    int in1[] = {6, 7, 4, 2, 5, 1, 3};

    BinaryTree<int> *T2 = pre_in_BuildBT(pre1, in1, 0, 6, 0, 6);
    BinaryTree<int> *T1 = level_BuildBT(level, 9);

    int h = 0;
    bool b1 = T2->isbalance(h);

    system("pause");
}

