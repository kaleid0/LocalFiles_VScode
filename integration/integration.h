#include<iostream>
#include<cmath>
#include"function.h"

using namespace std;

class integration{
public:
    integration(function fun){
        f = fun;
    }
    double operator()(double a, double b, double eps);

private:
    function f;
};

double integration::operator()(double a, double b, double eps){
    double dx = b - a; //取步长
    double tn = dx * (f(a) + f(b)) / 2; //一次划分步长
    double t2n = tn / 4 + dx * f((a + b) / 2); //二次划分步长为前一次的1/2
    int n = 1;
    while(fabs(t2n-tn)>eps){ //两次划分的误差是否满足精度要求
        tn = t2n;
        dx /= 2;//步长减半
        n *= 2;
        double sum = 0;
        for(int i = 0; i < n; i++){//使用前一次与后一次的关系公式
            double x = a + (i + 0.5) * dx;
            sum += f(x);
        }
        t2n = (tn + sum * dx) / 2.0;
        cout << t2n << endl;
    }
    return t2n;
}