#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int arr_size, int current_index)
{

  int largest = current_index;
  int left_index = largest * 2;
  int right_index = largest * 2 + 1;

  if (left_index <= arr_size && arr[largest] < arr[left_index])
    largest = left_index;
  if (right_index <= arr_size && arr[largest] < arr[right_index])
    largest = right_index;

  if (largest != current_index)
  {
    swap(arr[current_index], arr[largest]);
    heapify(arr, arr_size, largest);
  }
  else
    return;
}

void sorted(int arr[], int n)
{
  int size = n;

  while (size > 1)
  {

    swap(arr[size], arr[1]);

    size--;

    heapify(arr, size, 1);
  }
}

int main()
{

  int arr[6] = {-1, 10, 12, 3, 40, 90};
  int n = 5;

  for (int i = n / 2; i > 0; i--)
  {
    heapify(arr, n, i);
  }
  cout << "Printing heapify array : ";
  for (int i = 1; i <= 5; i++)
  {
    cout << arr[i] << " ";
  }

  sorted(arr, n);
  cout << "\nPrinting sorted array : ";
  for (int i = 1; i <= 5; i++)
  {
    cout << arr[i] << " ";
  }
}