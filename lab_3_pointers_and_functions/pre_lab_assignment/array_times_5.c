#include <stdio.h>
#include <stdlib.h>

void product(void *matrix_ptr, int row, int column){
    int i, j;
    int (*matrix)[column] = matrix_ptr;
    
	for(i=0; i<row; ++i){
	    for(j=0; j<column; ++j){
	        matrix[i][j] *= 5;
	    }
	}
}

int main(){
	int arr[2][4] = {
		{1,2,3,4},
		{5,6,7,8}
	};
	
	product(arr,2,4);
	
	for (int i=0;i<2;i++){
		for(int j = 0;j<4;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
