/**
 * Merge sort implementation.
 */

#include "SortHelper.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

/**
 * Merge sort the given range of elements.
 * @param elems Elements to sort.
 * @param first Index of the first element.
 * @param last Index of the last element.
 */
void mergeSort(vector<int>& elems,
                size_t first = 0,
                size_t last = std::numeric_limits<size_t>::max()) {
    // Validate args.
    if (elems.size() <= 1) {
        // If no more than 1 element, no need to sort.
        return;
    }
    last = std::min(last, elems.size() - 1);
    if (first >= last) {
        // No need to sort if no more than 1 element.
        return;
    }

    // TODO: merge sort.
}

static void testOneCase(vector<int>& elems) {
    cout << "before sorting:";
    printElems(elems);

    mergeSort(elems);

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

