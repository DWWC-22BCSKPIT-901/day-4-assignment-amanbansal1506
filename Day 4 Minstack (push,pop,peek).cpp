#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class CustomStack {
private:
    stack<int> primaryStack;   // Stack to hold all elements
    stack<int> minTrackerStack;    // Stack to keep track of minimum elements

public:
    CustomStack() {}

    void add(int value) {
        primaryStack.push(value);
        if (minTrackerStack.empty() || value <= minTrackerStack.top()) {
            minTrackerStack.push(value);
        }
    }

    void remove() {
        if (!primaryStack.empty() && primaryStack.top() == minTrackerStack.top()) {
            minTrackerStack.pop();
        }
        primaryStack.pop();
    }

    int peek() {
        return primaryStack.top();
    }

    int getMinimum() {
        return minTrackerStack.top();
    }
};

int main() {
    vector<string> commands = {"CustomStack", "add", "add", "add", "getMinimum", "remove", "peek", "getMinimum"};
    vector<vector<int>> parameters = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};
    vector<string> results;

    CustomStack* customStack = nullptr;

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "CustomStack") {
            customStack = new CustomStack();
            results.push_back("null");
        } else if (commands[i] == "add") {
            customStack->add(parameters[i][0]);
            results.push_back("null");
        } else if (commands[i] == "remove") {
            customStack->remove();
            results.push_back("null");
        } else if (commands[i] == "peek") {
            results.push_back(to_string(customStack->peek()));
        } else if (commands[i] == "getMinimum") {
            results.push_back(to_string(customStack->getMinimum()));
        }
    }

    // Print the results
    cout << "[";
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i];
        if (i < results.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
