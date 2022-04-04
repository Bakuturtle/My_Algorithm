#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int main(void) {
    int num,count,size,row,col,k;
    int arr[MAX][MAX] = {0,};
	num = MAX;
    k = 1;
	count = 0;
	size = num;
	row = 0;
	col = -1;

	while(true){  
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
	}


	for (row = 0, count=0; row < num; row++) {
		for (int col = 0; col < num; col++) {
			count++;
			printf("arr[%-d][%-d] vaule:%-4d", row,col,arr[row][col]);

		}
		printf("\n");
	}
	return 0;
}