#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

/**
 * Bubble sort the given range of elements.
 * Sorted elements will be returned to `elems`.
 * @param elems Elements to sort.
 * @param first Index of the first element to sort.
 * @param last Index of the last element to sort.
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

// Test main.
int main() {
    // Print unsorted elements.
    vector<int> elems({1, 3, 5, 7, 9, 2, 4, 6, 8, 10});
    cout << "before sorting:";
    for (int elem : elems) {
        cout << " " << elem;
    }
    cout << endl;

    bubbleSort(elems);

    // Print sorted elements.
    cout << "after sorting:";
    for (int elem : elems) {
        cout << " " << elem;
    }
    cout << endl;

    // Validate sorted elements.
    bool sorted = true;
    for (int i = 0; i < elems.size() - 1; i++) {
        if (elems[i] > elems[i + 1]) {
            sorted = false;
            break;
        }
    }
    cout << "sorting ";
    if (sorted) {
        cout << "SUCCEEDED" << endl;
    }
    else {
        cout << "FAILED" << endl;
    }

    return 0;
}
