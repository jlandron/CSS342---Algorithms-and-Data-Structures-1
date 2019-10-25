#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//merge the left and right of an array assuming the left and right are sorted
void mergeSort(vector<int> &arr, int first, int last);

int main(){
    srand (time(NULL));
    vector<int> arr;
    for(int i = 0; i < 15; i++){
        arr.push_back(rand() % 100 + 1);
    }
    cout << "The original Array is: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ", ";
    }
    mergeSort(arr, 0, arr.size() - 1);
    cout << "\nThe array is now sorted as: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}
void merge(vector<int> &arr, int first, int mid, int last){
    vector<int> tempArray(arr.size());
    int first1 = first;
    int first2 = mid + 1;
    int last1  = mid;
    int last2  = last;
    int index = first1;
    for( ; (first1 <= last1) && (first2 <= last2); ++index){
        if(arr[first1] < arr[first2]){
            tempArray[index] = arr[first1];
            ++first1;
        }else{
            tempArray[index] = arr[first2];
            ++first2;
        }
    }
    //go through first half
    for( ; (first1 <= last1); ++first1, ++index){
        tempArray[index] = arr[first1];
    }
    //go through second half 
    for( ; (first2 <= last2); ++first2, ++index){
        tempArray[index] = arr[first2];
    }
    //copy temp to original
    for(index = first; index <= last; ++index){
        arr[index] = tempArray[index];
    }
}
void mergeSort(vector<int> &arr, int first, int last){
    if(first < last){
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}
