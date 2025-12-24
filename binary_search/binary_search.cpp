#include <iostream>


using namespace std;

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
