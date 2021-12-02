#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"

using namespace std;

const int num = 31;
int main(){
    int pre1[] = {1, 2, 4, 8, 5, 9, 10, 11, 3, 6};
    int in1[] = {8, 4, 2, 9, 5, 10, 11, 1, 6, 3};

    int level[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int grade[] = {3, 3, 1, 2, 0, 0, 0, 0, 0, 0};

    int level2[] = {1, 2, 3, 4, 5, 6, 7};
    int in2[] = {4, 2, 5, 1, 6, 3, 7};

    BinaryTree<int> *T1 = level_BuildBT(level, 10);
    cout << T1 << endl;
    Tree<int> *T = level_grade_build2(level, grade, 10);
    ListTree<int> T3(T);
    cout << T3;
    system("pause");
}

