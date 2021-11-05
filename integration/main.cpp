#include<iostream>
#include<cmath>
#include"function.h"
#include"integration.h"

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