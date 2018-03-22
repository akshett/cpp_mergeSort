#include <iostream>

template <typename T>
void merge(T& arr,T& aux, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
	{
	    arr[k] = aux[j++];
	    continue;
	}
	if (j  > hi)
	{
	    arr[k] = aux[i++];
	    continue;
	}
	if (aux[i] <= aux[j])
	    arr[k] = aux[i++];
	else
            arr[k] = aux[j++];
    }
}

template <typename T>
void sort(T& arr,T& aux, int lo, int hi)
{
    if (lo >= hi) return;
    int mid = lo + (hi - lo)/2;
    sort(aux, arr, lo, mid);
    sort(aux, arr, mid+1,hi);
    merge(arr, aux, lo, mid, hi);
}

int main()
{
    int arr_size;
    std::cout << "Enter array size: ";
    std::cin >> arr_size;
    int* input_arr = new int[arr_size];
    int* aux_arr = new int[arr_size];
    std::cout << "Enter array elements" << '\n';
    for (int i = 0; i < arr_size; i++)
    {
        int temp;
	std::cin >> temp;
        input_arr[i] = temp;
	aux_arr[i] = temp;
    }
    sort(input_arr, aux_arr, 0, arr_size - 1);
    std::cout << "Sorted array" << '\n';
    for (int i =0; i < arr_size; i++)
    {
        std::cout << input_arr[i] << " ";
    }
    std::cout << "\n";
}
