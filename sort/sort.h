#pragma once

int *rondam(int n);
void show(int A[], int n);
void swap(int &A, int &B);
double sort(void (*fun)(int A[], int n), int A[], int n);
void bubblesort(int A[], int n);
void bubblesort2(int A[], int n); 
void insertsort(int A[], int n);
void insertsort2(int A[], int n); 
void shellsort(int A[], int n);
void quicksort(int A[], int n);
void selectsort(int A[], int n);
void heapsort(int A[], int n);
void mergesort(int A[], int n);
void mergesort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);