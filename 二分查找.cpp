#include <stdio.h>
int binary_search(int *arr, int  key, int left, int right)
{
	while (left <= right)
	{
		int mid = left+ (right - left) / 2;
		if (key == arr[mid])
		{
			return mid;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int key = 16;
	int sz = sizeof(arr) / sizeof(arr[10]) - 1;
	int ret = binary_search(arr, key, 0, sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了%d\n", ret);
	}
	return 0;
}