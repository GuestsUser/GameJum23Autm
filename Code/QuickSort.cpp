#include "QuickSort.h"
#include "Charactor.h"

void Swap(Charactor** a, Charactor** b)
{
	Charactor* tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(std::vector<Charactor*>& array, int start, int end)
{
	int pivot = array[end]->GetDrawPriority();
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++)
	{
		if (array[j]->GetDrawPriority() <= pivot)
		{
			i++;
			Swap(&array[i], &array[j]);
		}
	}
	Swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void QuickSort(std::vector<Charactor*>& array, int start, int end)
{
	if (start < end)
	{
		int pivot = Partition(array, start, end);
		QuickSort(array, start, pivot - 1);
		QuickSort(array, pivot + 1, end);
	}
}