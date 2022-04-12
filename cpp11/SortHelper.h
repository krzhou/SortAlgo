/**
 * Helper functions for sorting algorithms.
 */

#ifndef SORTALGOCPP11_SORTHELPER_H
#define SORTALGOCPP11_SORTHELPER_H

#include <vector>

/**
 * Print the given range of elements.
 * @param elems Elements to print.
 * @param first Index of the first element.
 * @param last Index of the last element.
 */
void printElems(std::vector<int>& elems,
                size_t first = 0,
                size_t last = std::numeric_limits<size_t>::max());
/**
 * Check if the given range of elements are in order,
 * i.e. for all i's, elems[i] <= elems[i + 1].
 * @param elems Elements to check.
 * @param first Index of the first element.
 * @param last Index of the last element.
 * @return true if the given range of elements are in order; false otherwise.
 */
bool isInorder(std::vector<int>& elems,
               size_t first = 0,
               size_t last = std::numeric_limits<size_t>::max());

#endif //SORTALGOCPP11_SORTHELPER_H
