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