



void shakerSort(int A[], int n) {

    int left = 1,
    right = n - 1,
    k = n - 1,
    counter = 0;
    int j;

    do {
        for (j = right; j >= left; j--) {
            if (A[j-1] > A[j]) {

                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
                
                k = j;
                counter++;
            } //if
        }
        left = k + 1;
        for (j = left; j <= right; j++) {
            if (A[j-1] > A[j]) {
                
                nt temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;

                k = j;
                counter++;
            } //if
        }//for j = right

        right = k - 1;
    } while (left < right);

} 
