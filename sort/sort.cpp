#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void selection_sort(vector<T>& arr) 
{
    int len = arr.size();

    for(int i = 0; i < len; i++)
    {
        T min_value = arr[i];
        int min_index = i;

        for(int j = i+1; j < len; j++)
        {
            if(min_value > arr[j])
            {
                min_value = arr[j];
                min_index = j;
            }
        }

        T temp = arr[i];
        arr[i] = min_value;
        arr[min_index] = temp;
    }
}

template <typename T>
void insertion_sort(vector<T>& arr)
{
    int len = arr.size();

    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                T temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
                break;
        }
    }
}

template <typename T>
void original_sort(vector<T>& arr) //insertion sort - original
{
    int len = arr.size();
    for(int i = 1; i < len; i++)
    {
        T key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

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

void count_sort(vector<int>& arr)
{
    int len = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max + 1, 0); 

    for (int i = 0; i < len; i++)
    {
        count[arr[i]] += 1;
    }

    vector<int> new_arr;
    
    for(int j = 0; j < max + 1; j++)
    {
        if(count[j] == 0)
            continue;
        else
        {
            for(int k = 1; k <= count[j]; k++)
            {
                new_arr.push_back(j);
            }
        }
    }

    for (int m = 0; m < len; m++)
    {
        arr[m] = new_arr[m];
    }
}

template <typename T>
int binary_search(vector<T>& arr, int start, int end, int target)
{
    int mid = (start + end) / 2;
    int target_idx;

    if(arr[mid] < target)
    {
        binary_search(arr, start, mid, target);
    }

    else if (arr[mid] > target)
    {
        binary_search(arr, mid+1, end, target);
    }
    else if (arr[mid] == target)
    {
        return mid;
    }
}
