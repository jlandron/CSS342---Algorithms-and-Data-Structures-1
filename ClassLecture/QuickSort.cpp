#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void partition(std::vector<int> & arr, int first, int last, int &pivotIndex);

void quickSort(vector<int> &arr, int first, int last);

int main() {
	srand(time(NULL));
	vector<int> arr;
	for(int i = 0; i < 15; i++){
        arr.push_back(rand() % 100 + 1);
    }
	cout << "The original Array is: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	quickSort(arr, 0, arr.size() - 1);
	cout << "\nThe array is now sorted as: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
	return 0;
}
void swap(vector<int> &arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void partition(std::vector<int> & arr, int first, int last, int &pivotIndex)
{
	int pivot = arr[first];
	int left = first;
	for (int right = first + 1; right <= last; right++) {
		if (arr[right] <= pivot) {
			left++;
			swap(arr, left, right);
		}
	}
	swap(arr, left, first);
	pivotIndex = left;
}

void quickSort(vector<int> &arr, int first, int last) {
	int pivotIndex;
	if (first < last) {
		partition(arr, first, last, pivotIndex);
		quickSort(arr, first, pivotIndex - 1); //left of pivot
		quickSort(arr, pivotIndex + 1, last); //right of pivot
	}
}