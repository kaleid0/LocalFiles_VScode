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
    double dx = b - a; //ȡ����
    double tn = dx * (f(a) + f(b)) / 2; //һ�λ��ֲ���
    double t2n = tn / 4 + dx * f((a + b) / 2); //���λ��ֲ���Ϊǰһ�ε�1/2
    int n = 1;
    while(fabs(t2n-tn)>eps){ //���λ��ֵ�����Ƿ����㾫��Ҫ��
        tn = t2n;
        dx /= 2;//��������
        n *= 2;
        double sum = 0;
        for(int i = 0; i < n; i++){//ʹ��ǰһ�����һ�εĹ�ϵ��ʽ
            double x = a + (i + 0.5) * dx;
            sum += f(x);
        }
        t2n = (tn + sum * dx) / 2.0;
        cout << t2n << endl;
    }
    return t2n;
}