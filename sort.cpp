template <typename T>
void quick_sort(vector<T>& arr, int start, int end)
{
	if (start >= end)
		return;

	int pivot = start;
	int left_idx = start + 1;
	int right_idx = end;
	while (left_idx <= right_idx)
	{
		while (left_idx <= end && arr[left_idx] <= arr[pivot])
			left_idx += 1;

		while (right_idx > start && arr[right_idx] >= arr[pivot])
			right_idx -= 1;

		if (left_idx > right_idx)
		{
			T temp = arr[right_idx];
			arr[right_idx] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			T temp = arr[left_idx];
			arr[left_idx] = arr[right_idx];
			arr[right_idx] = temp;
		}
	}

	quick_sort(arr, start, right_idx - 1);
	quick_sort(arr, right_idx + 1, end);
}
