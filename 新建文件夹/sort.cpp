#include<iostream>
#include<time.h>
#include"sort.h"


using namespace std;

const int num = 50000;


int* rondam(int n){
    int *a = new int[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand();
    return a;
}

void show(int A[],int n){
    for (int i = 0; i < n; i++){
        cout << A[i] << ',';
    }
    cout << endl;
}

void swap(int &A, int &B){
    int temp = A;
    A = B;
    B = temp;
}

double sort(void (*fun)(int A[], int n), int A[], int n){
    time_t begin,end;
    double res;
    int B[num];
    copy(A, A + num, B);
    begin=clock();
    fun(B, n);
    end=clock();
    show(B, 10);
    res = double(end - begin) / CLOCKS_PER_SEC;
    cout << "runtime:" << res << endl
         << endl;
    return res;
}

void bubblesort(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    bool flag;
    for (int i = n; i > 0; i--)
    {
        flag = false;
        for (int j = 1; j < i; j++)
            if(A[j]<A[j-1]){
                swap(A[j], A[j - 1]);
                flag = true;
            }
        if(!flag)
            return;
    }
}

void bubblesort2(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    bool flag = true;
    int low = 0, high = n - 1;
    while(low<high&&flag){
        flag = false;
        for (int i = low; i < high; i++)
            if(A[i]>A[i+1]){
                swap(A[i], A[i + 1]);
                flag = true;
            }
        high--;
        for (int i = high; i > low; i--)
            if(A[i]<A[i-1]){
                swap(A[i], A[i - 1]);
                flag = true;
            }
        low++;
    }
}

void insertsort(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    for (int i = 1; i < n; i++)
        if (A[i] < A[i - 1]){
            int temp = A[i];
            int j;
            for (j = i - 1; temp < A[j] && j >= 0; --j)
                A[j + 1] = A[j];
            A[j + 1] = temp;
        }
}

void insertsort2(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    int i, j, low, high, mid;
    for (i = 1; i < n; i++){
        int temp = A[i];
        low = 0;
        high = i - 1;
        while(low<=high){
            mid = (low + high) / 2;
            if(A[mid]>temp)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            A[j + 1] = A[j];
        A[high + 1] = temp;
    }
}

void shellsort(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    for (int d = n / 2; d >= 1; d /= 2)
        for (int i = d; i < n; ++i)
            if(A[i]<A[i-d]){
                int temp = A[i];
                int j;
                for (j = i - d; j > 0 && temp < A[j]; j -= d)
                    A[j + d] = A[j];
                A[j + d] = temp;
            }
}

int partition(int A[],int low,int high){
    int pivot = A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot)
            high--;
        A[low] = A[high];
        while(low<high&&A[low]<=pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void quicksort(int A[],int low,int high){
    if(low<high){
        int pos = partition(A, low, high);
        quicksort(A, low, pos-1);
        quicksort(A, pos + 1, high);
    }
}

void quicksort(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    quicksort(A, 0, n - 1);
}

void selectsort(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++)
            if(A[j]<A[min])
                min = j;
        if(min!=i)
            swap(A[i], A[min]);
    }
}

void heapadjust(int A[],int k,int n){
    A[0] = A[k];
    for (int i = 2 * k; i < n; i *= 2){
        if(i<n&&A[i]<A[i+1])
            i++;
        if(A[0]>=A[i])
            break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void buildheap(int A[],int n){
    for (int i = n / 2; i > 0; i--)
        heapadjust(A, i, n);
}

void heapsort(int A[],int n){
    cout << __FUNCTION__ << ':' << endl;
    buildheap(A, n);
    for (int i = n - 1; i >= 1; i--){
        swap(A[i], A[1]);
        heapadjust(A, 1, i - 1);
    }
}

