#include<iostream>
#include<time.h>
#include"sort.h"

using namespace std;


const int num = 50000;


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

    // int begin = clock();
    // bubblesort2(a, num);
    // int end = clock();
    // show(a, 20);
    // cout << double(end - begin) / CLOCKS_PER_SEC;

    double time[30][8];
    for (int i = 0; i < 1; i++){
        int *a = rondam(num);
        int B[num];
        copy(a, a + num-1000, B);
        cout << i << endl;
        for (int j = 0; j < 8;j++){
            time[i][j] = sort(fun[j], a, num-100);
        }
        delete[] a;
    }

    double avgtime[8];
    for (int i = 0; i < 8; i++){
        avgtime[i] = 0;
        for (int j = 0; j < 30; j++){
            avgtime[i] += time[j][i];
        }
        avgtime[i] /= 30;
        cout << avgtime[i] << endl;
    }

    
    return 0;
}
