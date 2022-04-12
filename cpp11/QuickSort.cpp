#include "SortHelper.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::swap;

/**
 * Partition the given range of elements according to a randomly selected pivot.
 * After partition, all the elements before the pivot is no larger than it and
 * all the elements after the pivot is no smaller than it.
 * @param elems Collection of elements.
 * @param first Index of the first element in the range.
 * @param last Index of the last element in the range.
 * @return Pivot index after partition.
 */
size_t partition(vector<int>& elems,
                 size_t first = 0,
                 size_t last = std::numeric_limits<size_t>::max()) {
    // Validate args.
    if (elems.size() <= 1) {
        // If no more than 1 element, no need to partition.
        return 0;
    }
    last = std::min(elems.size() - 1, last); // Make `last` in bound.
    if (first >= last) {
        // If no more than 1 element in range, no need to sort.
        return first;
    }

    // Randomly pick a pivot in [first, last] and move it to the first place.
    size_t pivot = rand() % (last - first + 1) + first;
    swap(elems[first], elems[pivot]);

    size_t left = first;
    size_t right = last;
    while (left < right) {
        // Find the first element < pivot on the right.
        while (left < right && elems[right] >= elems[first]) {
            right--;
        }
        // Find the first element > pivot on the left.
        while (left < right && elems[left] <= elems[first]) {
            left++;
        }
        // Swap elements on the wrong side.
        swap(elems[left], elems[right]);
    }
    // Put the pivot into the right place.
    swap(elems[first], elems[left]);
    return left;
}

/**
 * Quick sort the given range of elements.
 * Sorted elements will be returned to `elems`.
 * @param elems Elements to sort.
 * @param first Index of the first element.
 * @param last Index of the last element.
 */
void quickSort(vector<int>& elems,
               size_t first = 0,
               size_t last = std::numeric_limits<size_t>::max()) {
    // Validate args.
    if (elems.size() <= 1) {
        // If no more than 1 element, no need to sort.
        return;
    }
    last = std::min(elems.size() - 1, last); // Make `last` in bound.
    if (first >= last) {
        // If no more than 1 element in range, no need to sort.
        return;
    }

    size_t pivot = partition(elems, first, last);
    // `pivot` is unsigned, so assure it positive before minus 1.
    if (pivot > 0) {
        quickSort(elems, first, pivot - 1);
    }
    quickSort(elems, pivot + 1, last);
}

void testOneCase(vector<int>& elems) {
    cout << "before sorting:";
    printElems(elems);

    quickSort(elems);

    cout << "after sorting:";
    printElems(elems);

    // Validate sorted elements.
    assert(isInorder(elems));
    cout << "SUCCEEDED" << endl;

    cout << endl;
}

// Test main.
int main() {
    // Sort empty array.
    vector<int> emtpy;
    testOneCase(emtpy);

    // Sort a single element.
    vector<int> singleElem(1);
    testOneCase(singleElem);

    // Sort elements that are mostly in order.
    vector<int> nearlyInorder({1, 2, 7, 4, 5, 6, 3, 8, 9, 10});
    testOneCase(nearlyInorder);

    // Sort elements that are in reverse order.
    vector<int> reverseOrder({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    testOneCase(reverseOrder);

    // Sort elements that are in random order.
    vector<int> randomOrder({1, 3, 5, 7, 9, 10, 8, 6, 4, 2});
    testOneCase(randomOrder);

    // Sort duplicate elements that contain only a few unique value.
    vector<int> fewUnique({2, 1, 2, 1, 2, 1, 2, 1, 2, 1});
    testOneCase(fewUnique);

    return 0;
}
