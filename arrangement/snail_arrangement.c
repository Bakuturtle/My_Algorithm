#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int num,count,size,row,col,k;
    int arr[5][5] = {0,};
	num = 5;
    k = 1;
	count = 0;
	size = num;
	row = 0;
	col = -1;

	do{
		for (int i = 0; i < size; i++) {
			col += k;
			arr[row][col] = ++count;
		}
		if (--size == 0) break;

		for (int i = 0; i < size; i++) {
			row += k;
			arr[row][col] = ++count;
		}

		k = -k;
	}while(true);   


	for (row = 0; row < num; row++) {
		for (int col = 0; col < num; col++) {
			printf("%-3d", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}