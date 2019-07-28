void gnome_sort(int A[n], int n) {
	int i = 0;
	while (i < n) { 
		if (i == 0 || A[i-1] <= arr[i]) {
		i++;
		}
		else {
			int tmp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = tmp;
			i--;
		}
	}
}
