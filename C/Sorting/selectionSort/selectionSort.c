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