#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

//三个有序数组找差值最小的三元组
vector<int> minthree(int a[], int b[], int c[], int l, int m, int n);
//两个有序数组的中位数
int findmidnum(int a[], int b[], int n);
//荷兰国旗问题,数组只有三种元素,进行排序;
inline void swap(int &a, int &b);
void sort(int A[], int n);




vector<int> minthree(int a[],int b[],int c[],int l,int m,int n){
    int i=0,j=0,k=0;
    int r = abs(a[i] - b[j]), s = abs(a[i] - c[k]), t = abs(b[j] - c[k]);
    int sum = r + s + t;
    vector<int> v{0, 0, 0};
    while(i<n && j<m && k<n){
        if(r>s&&r>t)
            a[i] > b[j] ? j++ : i++;
        else if(s>r&&s>t)
            a[i] > c[k] ? k++ : i++;
        else
            b[j] > c[k] ? k++ : j++;
        if(i==l||j==m||k==n)
            break;
        r = abs(a[i] - b[j]), s = abs(a[i] - c[k]), t = abs(b[j] - c[k]);
        if((r+s+t)<sum){
            sum = r + s + t;
            v[0] = a[i];
            v[1] = b[j];
            v[2] = c[k];
        }
    }
    return v;
}

int findmidnum(int a[],int b[],int n){
    int s1 = 0, s2 = 0;
    int d1 = n - 1, d2 = n - 2;
    int m1, m2;
    while(s1!=d1||s2!=d2){
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if(a[m1]==b[m2])
            return a[m1];
        if(a[m1]<b[m2]){
            if((s1+d1)%2==0){
                s1 = m1;
                d2 = m2;
            }
            else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }
        else{
            if((s1+d1)%2==0){
                d1 = m1;
                s2 = m2;
            }
            else{
                d1 = m1 + 1;
                s2 = m2;
            }
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}

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





















