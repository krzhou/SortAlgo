/**
 * Helper functions for sorting algorithms.
 */

#include "SortHelper.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/**
 * Print the given range of elements.
 * @param elems Elements to print.
 * @param first Index of the first element.
 * @param last Index of the last element.
 */
void printElems(vector<int>& elems, size_t first, size_t last) {
    // Validate args.
    if (elems.size() == 0) {
        // Empty array.
        cout << endl;
        return;
    }
    last = std::min(last, elems.size() - 1);
    if (first > last) {
        // Empty range.
        cout << endl;
        return;
    }

    for (int i = first; i < last; i++) {
        cout << elems[i] << " ";
    }
    cout << elems[last] << endl;
}

/**
 * Check if the given range of elements are in order,
 * i.e. for all i's, elems[i] <= elems[i + 1].
 * @param elems Elements to check.
 * @param first Index of the first element.
 * @param last Index of the last element.
 * @return true if the given range of elements are in order; false otherwise.
 */
bool isInorder(vector<int>& elems, size_t first, size_t last) {
    // Validate args.
    if (elems.size() <= 1) {
        // Empty array is always in-order.
        return true;
    }
    last = std::min(last, elems.size() - 1);

    for (int i = first; i < last; i++) {
        if (elems[i] > elems[i + 1]) {
            return false;
        }
    }
    return true;
}
