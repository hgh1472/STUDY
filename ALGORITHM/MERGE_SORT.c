#include <stdio.h>
#define MAX_SIZE 10 // 배열의 사이즈
int sorted[MAX_SIZE]; //전역변수로 선언해야 메모리 낭비 줄일수있다.

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) // i와 j 둘 중 하나가 끝에 도달하기까지
	{
		if (list[i] <= list[j]) //list[i]가 더 작으면 
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++]; //list[j]가 더 작으면
	}

	if (i > mid) //i가 먼저 도달
	{
		for (l = j; j <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void mergeSort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
