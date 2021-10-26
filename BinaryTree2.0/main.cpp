#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"
//#include"LinkList\\LinkList.h"

using namespace std;

const int num = 31;
int main(){
    int in[] = {4, 2, 7, 5, 1, 3, 6,8};
    int pre[] = {1, 2, 4, 5, 7, 3, 6,8};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    BinaryTree<int> *T1 = pre_in_BuildBT(pre, in, 0, 6, 0, 6);
    T1->levelOrder();
    cout << 0;

}