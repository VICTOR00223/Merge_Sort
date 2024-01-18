#include <stdio.h>

void mergesort(int array[], int lb, int ub);
void merge(int array[], int lb, int mid, int ub);
int main()
{
	int a[8], i;
	for(i=0; i<8; ++i)
	{
		printf("\na[%d] = ", i);
		scanf("%d", &a[i]);
	}
	mergesort(a, 0, 7);
	for(i=0; i<8; ++i)
		printf("\na[%d] = %d", i, a[i]);
    return 0;   
}
void mergesort(int array[], int lb, int ub)
{
	if(lb < ub)
	{
		int mid = (lb+ub)/2;
		mergesort(array, lb, mid);
		mergesort(array, mid+1, ub);
		merge(array, lb, mid, ub);
	}
}
void merge(int array[], int lb, int mid, int ub)
{
	int b[8];
	int i = lb;
	int j = mid+1;
	int k = lb;
	while(i <= mid && j <= ub)
	{
		if(array[i] < array[j])
		{
			b[k] = array[i];
			i++;
		}
		else
		{
			b[k] = array[j];
			j++;
		}
		k++;
	}
	if(i > mid)
	{
		while(j <= ub)
		{
			b[k] = array[j];
			j++;
			k++;
		}
	}
	if(j > ub)
	{
		while(i <= mid)
		{
			b[k] = array[i];
			i++;
			k++;
		}
	}
	for(k=lb; k<=ub; k++)
		array[k] = b[k];
}
