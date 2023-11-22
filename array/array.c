#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
int move_count = 0;
int compare_count = 0;
int move_count_all = 0;
int compare_count_all = 0;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {		// 최솟값 탐색
			compare_count++;
			if (list[j] < list[least]) {
				least = j;
				move_count++;
			}
		}
		SWAP(list[i], list[least], temp);
		for (int k = 0; k < n; k++)
			printf("%d ", list[k]);
			
		printf("\n");
	}
	printf("Compare Count : %d\n", compare_count);
	printf("Move Count : %d\n\n", move_count);

	move_count_all += move_count;
	compare_count_all += compare_count;
	move_count = 0;
	compare_count = 0;
}

// 삽입정렬
void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (int j = 0; j < n; j++)
			printf("%d ", list[j]);

		printf("\n");

		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
			move_count++;
			compare_count++;
		}	
		list[j + 1] = key;
	}
	printf("\n");
	printf("Compare Count : %d\n", compare_count);
	printf("Move Count : %d\n", move_count);
	move_count_all += move_count;
	compare_count_all += compare_count;
	compare_count = 0;
	move_count = 0;
	
}
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
		for (j = 0; j < i; j++) {	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				move_count++;
			}
			compare_count++;
		}
	
	}
	printf("Compare Count : %d\n", compare_count);
	printf("Move Count : %d\n\n", move_count);
	move_count_all += move_count;
	compare_count_all += compare_count;
	compare_count = 0;
	move_count = 0;
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99

	for (int a = 0; a < 20; a++) {
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100;
		printf("Original List\n");
		for (i = 0; i < n; i++)
			printf("%d ", list[i]);
		printf("\n\n");
		printf("Selection_sort\n");
		selection_sort(list, n); // 선택정렬 호출 	
	}
	printf("Compare Count Avg!!! : %d\n", compare_count_all / 20);
	printf("Move Count Avg!!! : %d\n\n", move_count_all / 20);
	compare_count_all = 0;
	move_count_all = 0;
	printf("\n");
	for (int a = 0; a < 20; a++) {
		for (i = 0; i < n; i++)  	// 난수 생성 및 출력 
			list[i] = rand() % 100;
		printf("Original List\n");
		for (i = 0; i < n; i++)
			printf("%d ", list[i]);
		printf("\n\ninsertion_sort\n");
		insertion_sort(list, n); // 삽입정렬 호출 
	}

	printf("Compare Count Avg!!! : %d\n", compare_count_all / 20);
	printf("Move Count Avg!!! : %d\n\n", move_count_all / 20);
	compare_count_all = 0;
	move_count_all = 0;
	printf("\n");
	
	for (int a = 0; a < 20; a++) {
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100;
		printf("\nOriginal List\n");
		for (i = 0; i < n; i++)
			printf("%d ", list[i]);
		printf("\n\nbubble_sort\n");
		bubble_sort(list, n); // 버블정렬 호출 
	}
	printf("\nCompare Count Avg!!! : %d\n", compare_count_all / 20);
	printf("Move Count Avg!!! : %d\n\n", move_count_all / 20);
	
}
