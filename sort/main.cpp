#include<iostream>
#include<time.h>
#include"sort.h"
#include"sort.cpp"
#include<iomanip>
using namespace std;


//const int num = 50000;


int main(){
    void (*fun[10])(int A[], int n);
    fun[0] = bubblesort;
    fun[1] = bubblesort2;
    fun[2] = insertsort;
    fun[3] = insertsort2;
    fun[4] = shellsort;
    fun[5] = quicksort;
    fun[6] = selectsort;
    fun[7] = heapsort;
    fun[8] = mergesort;

    // int A[12] = {7, 5, 12, 3, 2, 1, 6, 11, 10, 4, 8, 9};

    // mergesort(A, 12);

    // for (int i = 0; i < 12; i++)
    //     cout << A[i] << ',';

    double time[30][9];
    for (int i = 0; i < 10; i++){
        int *a = rondam(num);
        int B[num];
        copy(a, a + num-1000, B);
        cout << i << endl;
        for (int j = 0; j < 9;j++){
            time[i][j] = sort(fun[j], a, num-100);
        }
        delete[] a;
    }

    double avgtime[9];
    for (int i = 0; i < 9; i++){
        avgtime[i] = 0;
        for (int j = 0; j < 10; j++){
            avgtime[i] += time[j][i];
        }
        avgtime[i] /= 10;
        cout << fixed;
        cout << setprecision(5) << avgtime[i] << endl;
    }

    system("pause");

    return 0;
}
