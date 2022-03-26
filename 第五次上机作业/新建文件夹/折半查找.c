#include <stdio.h> 
#define N 15
int main()
{
	int a[N]={1,2,3,4,5,13,19,21,37,56,64,75,80,88,92};
	int key, low=0, mid, high=N-1;
	printf("Input key: \n");
	scanf("%d", &key);
	while (low <= high) 
	{
		mid = (low + high) / 2;
		if (key > a[mid])
			low = mid + 1;
		else if (key == a[mid])
			{
				printf("a[%d]=%d\n", mid, key);
				return 0;
			}
			else
				high = mid - 1; 
	}
printf("ÎŞ´ËÊı!\n");
return -1;
}
