#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"
//#include"LinkList\\LinkList.h"

using namespace std;

const int num = 31;
int main(){
    int in[] = {9, 7, 10, 6, 2, 5, 4, 3, 8, 1};
    int pre[] = {1, 2, 6, 7, 9, 10, 3, 5, 4, 8};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char level2[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    char in2[] = {'G', 'D', 'H', 'B', 'E', 'A', 'F', 'I', 'C'};

    BinaryTree<char> *T0 = level_in_BuildBT(level2, in2, 0, 8, 9);
    T0->levelOrder();
    T0->InOrder();

    BinaryTree<int> *T1 = pre_in_BuildBT(pre, in, 0, 9, 0, 9);
    //BinaryTree<int> *T2 = post_in_BuildBT(post, in, 0, 8, 0, 8);
    BinaryTree<int> *T3 = level_BuildBT(level, 9);
    T1->levelOrder();

    ThreadTree<int> T4(T1);
    T4.postThread();

    delete T1;

    system("pause");
}

