#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& elements, int windowSize) {
    deque<int> indexDeque; // Stores indices of array elements
    vector<int> maxValues;

    for (int idx = 0; idx < elements.size(); ++idx) {
        // Remove elements from deque that are out of the current window
        if (!indexDeque.empty() && indexDeque.front() == idx - windowSize) {
            indexDeque.pop_front();
        }

        // Remove elements from deque that are smaller than the current element
        while (!indexDeque.empty() && elements[indexDeque.back()] < elements[idx]) {
            indexDeque.pop_back();
        }

        // Add the current element's index to the deque
        indexDeque.push_back(idx);

        // Add the maximum element of the current window to the result
        if (idx >= windowSize - 1) {
            maxValues.push_back(elements[indexDeque.front()]);
        }
    }

    return maxValues;
}

int main() {
    vector<int> elements = {1, 3, -1, -3, 5, 3, 6, 7};
    int windowSize = 3;
    vector<int> maxValues = slidingWindowMaximum(elements, windowSize);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < maxValues.size(); i++) {
        cout << maxValues[i];
        if (i < maxValues.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
