#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

/**
 * Bubble sort the given range of elements.
 * Sorted elements will be returned to `elems`.
 * @param elems Elements to sort.
 * @param first Index of the first element.
 * @param last Index of the last element.
 */
void bubbleSort(vector<int>& elems,
                size_t first = 0,
                size_t last = std::numeric_limits<size_t>::max()) {
    // Validate args.
    last = std::min(last, elems.size() - 1);
    if (first > last) {
        // If range is invalid, `elems` will stay untouched.
        return;
    }

    // Bubble sort.
    for (size_t i = 0; i < last - first; i++) {
        bool inorder = true; // Whether every element <= its next element.
        for (size_t j = first; j < last - i; j++) {
            if (elems[j] > elems[j + 1]) { // Stable sort.
                std::swap(elems[j], elems[j + 1]);
                inorder = false;
            }
        }
        if (inorder) {
            // All elements are in-order. No need to sort further.
            break;
        }
    }
}

/**
 * Print the given range of elements.
 * @param elems Elements to print.
 * @param first Index of the first element.
 * @param last Index of the last element.
 */
void printElems(vector<int>& elems,
                size_t first = 0,
                size_t last = std::numeric_limits<size_t>::max()) {
    // Validate args.
    last = elems.size() - 1;
    if (first > last) {
        // Invalid range.
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
 * i.e. elems[i] <= elems[i + 1].
 * @param elems Elements to check.
 * @param first Index of the first element.
 * @param last Index of the last element.
 * @return
 */
bool isInorder(vector<int>& elems,
                size_t first = 0,
                size_t last = std::numeric_limits<size_t>::max()) {
    // Validate args.
    last = elems.size() - 1;
    if (first > last) {
        // Invalid range.
        return false;
    }

    for (int i = first; i < last; i++) {
        if (elems[i] > elems[i + 1]) {
            return false;
        }
    }
    return true;
}

void test(vector<int>& elems) {
    cout << "before sorting:";
    printElems(elems);

    bubbleSort(elems);

    cout << "after sorting:";
    printElems(elems);

    // Validate sorted elements.
    assert(isInorder(elems));
    cout << "SUCCEEDED" << endl;

    cout << endl;
}

// Test main.
int main() {
    // Sort elements that are mostly in order.
    vector<int> nearlyInorder({1, 2, 7, 4, 5, 6, 3, 8, 9, 10});
    test(nearlyInorder);

    // Sort elements that are in reverse order.
    vector<int> reverseOrder({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
    test(reverseOrder);

    // Sort elements that are in random order.
    vector<int> randomOrder({1, 3, 5, 7, 9, 10, 8, 6, 4, 2});
    test(randomOrder);

    // Sort duplicate elements that contain only a few unique value.
    vector<int> fewUnique({2, 1, 2, 1, 2, 1, 2, 1, 2, 1});
    test(fewUnique);

    return 0;
}
