//
// Created by Alan on 2019-03-13.
//
#include "sorting.h"
void arrayPrinter(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}

//O(n^2)
void SelectionSort(int A[], int n) {
    int position;
    for (position = 0; position < n; position++) {
        int selected, i;
        selected = position;
        /* ELse */
        for (i = position + 1; i < n; i++)if (A[i] < A[selected]) selected = i;
        {
            int tmp;
            tmp = A[position];
            A[position] = A[selected];
            A[selected] = tmp;
        }
    }
}

void Merge(int result[], int a1[], int n1, int a2[], int n2) {
    int p=0, p1=0, p2=0;
    while (p1 < n1 && p2 < n2) {
        if (a1[p1] < a2[p2])
            result[p++] = a1[p1++];
        else
            result[p++] = a2[p2++];
    }
    while (p1<n1) result[p++] = a1[p1++];
    while (p2<n2) result[p++] = a2[p2++];
}

//O(logn)
void MergeSort(int array[], int n) {
    int n1, n2, *a1, *a2;
    if (n<=1) return; /* Because array is already sorted! */
    n1 = n/2;
    n2 = n - n1;
    a1 = (int*) malloc(n1*sizeof(int));
    for (int i=0; i<n1; i++) a1[i]=array[i];
    a2 = (int*) malloc(n2*sizeof(int));
    for (int i=0; i<n2; i++) a2[i]=array[i+n1];
    MergeSort(a1,n1); MergeSort(a2,n2);
    Merge(array, a1, n1, a2, n2);
}

static int Partition(int array[], int n) {
    int p, q, pivot; pivot=array[0]; p=1; q=n-1;
    while (1) {
        while (p < q && array[q] >= pivot) q--;
        while (p < q && array[p] < pivot) p++;
        if (p == q) break;
        //else
        {
            int tmp;
            tmp = array[p];
            array[p] = array[q];
            array[q] = tmp;
        }
    }
    if (array[p] >= pivot) return(0);
    array[0]=array[p];
    array[p]=pivot;
    return(p);
}
//O(logn)
void QuickSort(int array[], int n) {
    int pivotPosition;
    if (n<=1) return;
    pivotPosition = Partition(array, n);
    QuickSort(array, pivotPosition);
    QuickSort(array+pivotPosition+1, n-pivotPosition-1);
}
