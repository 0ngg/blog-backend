#include "stdio.h"
#include <iostream>

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i+1], arr[high]);
  return (i+1);
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi-1);
    quicksort(arr, pi+1, high);
  }
}

int main(int argc, char *argv[]) {
  int *arr = new int[argc-1];
  for (int i = 1; i <= argc-1; i++) {
    arr[i] = std::stoi(argv[i]);
  }
  quicksort(arr, 0, argc-1);
  for (int i = 1; i <= argc-1; i++) {
    std::cout << arr[i] << std::endl;
  }
  delete[] arr;
  return 0;
}
