void shellSort(int A[], int n){
    for(int d = n/2; d >= 1; d /= 2){
        for(int i = d; i < n; ++i){
            for(int j  = i; j >= d && A[j-d] > A[j]; j -= d){
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }
}
