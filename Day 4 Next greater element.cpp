#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNextGreaterElements(vector<int>& elements) {
    int size = elements.size();
    vector<int> nextGreater(size, -1); // Initialize the result array with -1
    stack<int> indexStack;            // Monotonic stack to store indices

    // Traverse the array twice to handle the circular nature
    for (int index = 0; index < 2 * size; index++) {
        while (!indexStack.empty() && elements[indexStack.top()] < elements[index % size]) {
            nextGreater[indexStack.top()] = elements[index % size];
            indexStack.pop();
        }
        if (index < size) {
            indexStack.push(index);
        }
    }

    return nextGreater;
}

int main() {
    vector<int> elements = {1, 2, 1};
    vector<int> nextGreater = findNextGreaterElements(elements);

    cout << "[";
    for (size_t i = 0; i < nextGreater.size(); i++) {
        cout << nextGreater[i];
        if (i < nextGreater.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
