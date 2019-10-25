/**
 *@author Joshua Landron 
 *based on program 4, CSS 342, Dr.Munehiro Fukuda
 *@date 15Feb2019
 *
 *This is a semi in place mergesort. it is an improvment over the standard recursive mergesort
 *due to the fact that there is much less writing to memory in this algorithm.
**/
#include <vector>

using namespace std;
/**
 *@desc merge function for semi-in-place mergesort. takes in two vectors, and merges from the first
 * into the second.
 *@param vector<Comparable> &, vector<Comparable> &, int , int , int 
 *@return none, works directly on the passed vectors

**/
template <class Comparable>
void merge(vector<Comparable> &arr, vector<Comparable> &temp, int first, int mid, int last) {
	int first1 = first;
	int first2 = mid + 1;
	int last1 = mid;
	int last2 = last;
	int index = first1;
	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (arr[first1] < arr[first2]) {
			temp[index] = arr[first1];
			++first1;
		}
		else {
			temp[index] = arr[first2];
			++first2;
		}
	}
	//go through first half
	for (; (first1 <= last1); ++first1, ++index) {
		temp[index] = arr[first1];
	}
	//go through second half 
	for (; (first2 <= last2); ++first2, ++index) {
		temp[index] = arr[first2];
	}
	//leaves all data in "temp"
}
/**
 *@desc semi-inplace mergesort
 *@param vector<Comparable> &
 *@return none
 *@required The vector passed in must be of type Comparable,
 *@provided A fast, memory friendly non recursive mergesort alorithm
**/
template <class Comparable>
void mergesort(vector<Comparable> &arr) {
	vector<Comparable> tempArray(arr.size());
	int currSize;
	int currLeft;
	bool inTempArray = false; //simple way to keep track of where our 
                              //sorted data is currently stored.

	for (currSize = 1; currSize < arr.size(); currSize *= 2) {
		for (currLeft = 0; currLeft < arr.size() - 1; currLeft += (2 * currSize)) {
			int currMid = currLeft + currSize - 1;
			int currRight = min(currLeft + 2 * currSize - 1, (int)(arr.size() - 1));
			if (inTempArray) {
				merge(tempArray, arr, currLeft, currMid, currRight);
			}
			else {
				merge(arr, tempArray, currLeft, currMid, currRight);
			}
		}
		//switch inTempArray as the group size changes
		if (inTempArray) {
			inTempArray = false;
		}
		else {
			inTempArray = true;
		}
	}
	if (inTempArray) { //copy values from temp array to original if needed
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = tempArray[i];
		}
	}
}


