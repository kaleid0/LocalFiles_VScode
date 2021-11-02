#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<time.h>

using namespace std;

inline void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int A[],int n){
    int begin = 0, end = n - 1, i = 0;
    while(i<end){
        if(A[i]==2){
            int temp = A[i];
            A[i] = A[end];
            A[end] = temp;
            end--;
        }
        else if(A[i]==1){
            i++;
        }
        else{
            if(i!=begin){
                int temp=A[i];
                A[i] = A[begin];
                A[begin] = temp;
            }
            i++;
            begin++;
        }
    }
}

int main(){
    int A[100];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
        A[i] = rand()%3;
    for (int i = 0; i < 100;i++)
        cout << A[i] << ' ';
    cout << endl;
    sort(A, 100);
    for (int i = 0; i < 100;i++)
        cout << A[i] << ' ';

    cout << endl;
}

