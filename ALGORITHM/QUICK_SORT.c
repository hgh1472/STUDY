#include <stdio.h>

int partition(int list[], int left, int right)
{
	int pivot;
	int tmp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[low];
	do
	{
		do
		{
			low++;
		} while (low <= right && list[low] < pivot);

		do
		{
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high)
		{
			tmp = list[low];
			list[low] = list[high];
			list[high] = tmp;
		}
	} while (low < high);
	tmp = list[left];
	list[left] = list[high];
	list[high] = tmp;
	return high;
}
void QuickSort(int list[], int left, int right)
{
	int p;

	if (left < right)
	{
		p = partition(list, left, right);
		QuickSort(list, left, p - 1);
		QuickSort(list, p + 1, right);
	}
}

int main()
{
	int i;
	int n = 10;
	int list[10] = { 5,3,8,4,9,1,6,2,7 };
	QuickSort(list, 0, n - 1);

	for (i = 0; i < 10; i++)
		printf("%d\n", list[i]);
	return 0;
}
