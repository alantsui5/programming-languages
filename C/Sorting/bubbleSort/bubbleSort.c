void bubbleSort(int A[], int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(A[j] < A[j+1])
            {
                int temp;
                temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            } 
        }
    }
}


