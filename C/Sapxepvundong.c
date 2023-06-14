#include "stdio.h"
#include "stdlib.h"

void printArray(int *a, int n) {
	int i;
	for (i = 0; i < n; i++) {

		printf("%d \t", *(a + i));
	}
}

void heap(int *myList, int lastIndex) {

	if (lastIndex == 0) {

		return;
	} else {

		int i = lastIndex;
		while (i >= 1) {
			int parentIndex = (i - 1) / 2;
			// Co the thay the bang cach
			// if (lastIndex % 2 == 0){
			//    parentIndex = (i - 2) / 2;
			// } else {
			//    parentIndex = (i - 1) / 2;
			// }

			if (*(myList + parentIndex) > *(myList + i)) {
				int temp = *(myList + i);
				*(myList + i) = *(myList + parentIndex);
				*(myList + parentIndex) = temp;
			}

			i--;
		}
	}
}

void heapsort(int *myList, int listSize) {
	int i;
	for (i = 1; i < listSize; i++) {

		heap(myList, listSize - i);
		int temp = *(myList + 0);
		*(myList + 0) = *(myList + listSize - i);
		*(myList + listSize - i) = temp;
	}
}

int main(int argc, char **argv) {

	int n = 12, i;
	int *a = (int*) calloc(n, sizeof(int));

	*(a + 0) = 3;
	*(a + 1) = 6;
	*(a + 2) = 9;
	*(a + 3) = 2;
	*(a + 4) = 6;
	*(a + 5) = 8;
	*(a + 6) = 9;
	*(a + 7) = 1;
	*(a + 8) = 7;
	*(a + 9) = 21;
	*(a + 10) = 7;
	*(a + 11) = 12;

	printf("\nBefore sorting: ");
	printArray(a, n);

	heapsort(a, n);

	printf("\nAfter  sorting: ");
	printArray(a, n);

	printf("\nAfter reversed: ");
	for (i = n - 1; i >= 0; --i) {
		printf("%d\t", a[i]);
	}

	return 0;
}