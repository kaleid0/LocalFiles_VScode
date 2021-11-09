#include<iostream>
#include<cmath>
#include"function.h"//被积函数
#include"integration.h"//等步长划分积分

using namespace std;

double f2(double x){
    return x * x;
}

double e(double x){
    return exp(-x * x);
}


int main(){
    double (*ptr)(double x) = e;
    function f1(ptr);
    integration i1(f1);
    cout << exp(0) << endl;
    cout << i1(0, 1000, 0.00001);
    
}