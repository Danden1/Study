#include <stdio.h>

void SelSort(int arr[], int n){
	int i,j;
	int maxIdx;
	int tmp;
	
	for(i = 0; i < n-1; i++){
		maxIdx = 1;
		
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		
		tmp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = tmp;
	}
}

int main(void){
	int arr[4] = {3,2,4,1}
	int i;
	
	SelSort(arr, sizeof(arr)/sizeof(int));
	
	for(i=0; i< 4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
