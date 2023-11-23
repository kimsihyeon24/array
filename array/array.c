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
//��������
void selection_sort(int list[], int n , int a)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {		// �ּڰ� Ž��
			compare_count++;
			if (list[j] < list[least]) {
				least = j;
			}
		}
		SWAP(list[i], list[least], temp);
		move_count++;
		if (a == 0) {
			for (int k = 0; k < n; k++)
				printf("%d ", list[k]);
			printf("\n");
		}	
	}
	move_count_all += move_count;
	compare_count_all += compare_count;
	move_count = 0;
	compare_count = 0;
}

// ��������
void insertion_sort(int list[], int n, int a)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		if (a == 0) {
			for (int j = 0; j < n; j++)
				printf("%d ", list[j]);
			printf("\n");
		}

		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j]; 		// ���ڵ��� ������ �̵�
			move_count++;
			compare_count++;
		}	
		list[j + 1] = key;
	}
	

	move_count_all += move_count;
	compare_count_all += compare_count;
	compare_count = 0;
	move_count = 0;
	
}

//��������
void bubble_sort(int list[], int n, int a) {
	int i, j, temp;
	int is_sorted = 0; // ���� �Ϸ� ���θ� ��Ÿ���� ����

	do {
		is_sorted = 1; // �ϴ� ���� �Ϸ�� ����
		for (i = 0; i < n - 1; i++) {
			int swapped = 0; // ��Ұ� ��ȯ�Ǿ����� ���θ� ��Ÿ���� ����
			for (j = 0; j < n - i - 1; j++) {
				if (list[j] > list[j + 1]) {
					SWAP(list[j], list[j + 1], temp);
					move_count++;
					swapped = 1; // ��Ұ� ��ȯ�Ǿ����� ǥ��
				}
				compare_count++;
			}
			// ���� ������ ���
			if (a == 0) {
				for (j = 0; j < n; j++) {
					printf("%d ", list[j]);
				}
				printf("\n");
			}
			// ������ �Ϸ�Ǿ����� Ȯ��
			if (swapped == 0) {
				is_sorted = 1; // ������ �Ϸ�Ǿ��ٸ� ǥ��
				break; // �� �̻� ������ �ʿ� �����Ƿ� ����
			}
		}
	} while (is_sorted == 0 && a == 0); // ������ �Ϸ�ǰų� Ž���� �����ϴ� ��� ����

	if (is_sorted == 1 && a == 0) {
		return; // ������ �Ϸ�Ǹ� �Լ� ����
	}

	move_count_all += move_count;
	compare_count_all += compare_count;
	compare_count = 0;
	move_count = 0;
}

int main(void)
{
	int i;
	int a = 0;
	n = MAX_SIZE;
	srand(time(NULL));
	
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100;     // ���� �߻� ���� 0~99
	for (a = 0; a < 20; a++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100;
		if (a == 0) {
			printf("Original List\n");
			for (i = 0; i < n; i++)
				printf("%d ", list[i]);
			printf("\n\n");
			printf("Selection_sort\n");
		}
		selection_sort(list, n, a); // �������� ȣ�� 	//
	}
	printf("\nCompare Count Avg!!! : %d\n", compare_count_all / 20);  
	printf("Move Count Avg!!! : %d\n\n", move_count_all / 20);
	compare_count_all = 0;
	move_count_all = 0;
	printf("\n");
	
	for (a = 0; a < 20; a++) {
		for (i = 0; i < n; i++)  	// ���� ���� �� ��� 
			list[i] = rand() % 100;
		if (a == 0) {
			printf("Original List\n");
			for (i = 0; i < n; i++)
				printf("%d ", list[i]);
			printf("\n\ninsertion_sort\n");
		}
		insertion_sort(list, n, a); // �������� ȣ�� 
	}

	printf("\nCompare Count Avg!!! : %d\n", compare_count_all / 20);
	printf("Move Count Avg!!! : %d\n\n", move_count_all / 20);
	compare_count_all = 0;
	move_count_all = 0;
	printf("\n");
	
	for (a = 0; a < 20; a++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100;
		if (a == 0) {
			printf("\nOriginal List\n");
			for (i = 0; i < n; i++)
				printf("%d ", list[i]);
			printf("\n\nbubble_sort\n");
		}
		bubble_sort(list, n, a); // �������� ȣ�� 
	}
	printf("\nCompare Count Avg!!! : %d\n", compare_count_all / 20);
	printf("Move Count Avg!!! : %d\n\n", move_count_all / 20);
	
}
