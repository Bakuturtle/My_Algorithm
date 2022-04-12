// #ifndef __SNAIL_ARRANGEMENT__
// #define __SNAIL_ARRANGEMENT__
// #include "../lib/standard_lib.h"

// class Snail_Arrangement{
// private:
// 	static MAX = 10;
//     int num,count,size,row,col,k;
// 	int** arr;
// 	num = MAX;
// 	k = 1;
// 	count = 0;
// 	size = num;
// 	row = 0;
// 	col = -1;
// 	arr = 

// public:
// 	Snail_Arrangement(void){
			
// 		while(true){  
// 			for (int i = 0; i < size; i++) {
// 				col += k;
// 				arr[row][col] = ++count;
// 			}
// 			if (--size == 0) break;

// 			for (int i = 0; i < size; i++) {
// 				row += k;
// 				arr[row][col] = ++count;
// 			}

// 			k = -k;
// 		}
// 	}

// 	void Show(void){
// 		for (row = 0, count=0; row < num; row++) {
// 			for (int col = 0; col < num; col++) {
// 				count++;
// 				printf("arr[%-d][%-d] vaule:%-4d", row,col,arr[row][col]);

// 			}
// 			printf("\n");
// 		}

// 	};
// };

// #endif