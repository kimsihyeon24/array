#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
int move_count;
int compare_count;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
	
			if (list[j] < list[least]){
			 least = j; 
		
			}
		SWAP(list[i], list[least], temp);

	}

}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + i] = list[j];
		}
		list[j + 1] = key;
	}
}

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				move_count++;
			}
		}
	}
}

int main(void) {
	int i;
	n = MAX_SIZE;
	printf("Original List \n");
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		list[i] = rand() % 100;
		
		printf("%d ", list[i]);
	}
	printf("\n"); printf("\n");
	
	printf("Selection Sort\n");
	for (int k = 0; k < 20; k++) {
		selection_sort(list, n);
		for (i = 0; i < n; i++) {
			printf("%d ", list[i]);	
		}
		printf("\n");
	}

		printf("\n");
		printf("Insertion Sort\n");
		for (int k = 0; k < 20; k++) {
			insertion_sort(list, n);
			for (i = 0; i < n; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}

		printf("\n");
		printf("Bubble Sort\n");
		for (int k = 0; k < 20; k++) {
			bubble_sort(list, n);
			for (i = 0; i < n; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}

		return 0;
	}
