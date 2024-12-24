#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class PlateStacks {
private:
    int stackCapacity;
    vector<stack<int>> plateStacks;
    int nextAvailableStack;

public:
    // Constructor to initialize the PlateStacks object
    PlateStacks(int capacity) {
        this->stackCapacity = capacity;
        this->nextAvailableStack = 0;
        cout << "null" << endl; // Output null for constructor
    }

    // Pushes a value into the leftmost stack with available space
    void addPlate(int value) {
        while (nextAvailableStack < plateStacks.size() && plateStacks[nextAvailableStack].size() == stackCapacity) {
            nextAvailableStack++;
        }
        
        if (nextAvailableStack == plateStacks.size()) {
            plateStacks.push_back(stack<int>());
        }
        
        plateStacks[nextAvailableStack].push(value);
        cout << "null" << endl; // Output null for addPlate
    }

    // Removes the top plate from the rightmost non-empty stack
    int removePlate() {
        if (plateStacks.empty()) {
            return -1;
        }
        
        while (!plateStacks.empty() && plateStacks.back().empty()) {
            plateStacks.pop_back();
        }

        if (plateStacks.empty()) {
            return -1;
        }

        int topPlate = plateStacks.back().top();
        plateStacks.back().pop();
        return topPlate;
    }

    // Removes the top plate from a specific stack
    int removePlateAt(int index) {
        if (index >= plateStacks.size() || plateStacks[index].empty()) {
            return -1;
        }

        int topPlate = plateStacks[index].top();
        plateStacks[index].pop();
        return topPlate;
    }
};

int main() {
    PlateStacks ps(2);  // Constructor call, should output 'null'
    
    ps.addPlate(1);  // Should output 'null'
    ps.addPlate(2);  // Should output 'null'
    ps.addPlate(3);  // Should output 'null'
    ps.addPlate(4);  // Should output 'null'
    ps.addPlate(5);  // Should output 'null'
    
    cout << ps.removePlateAt(0) << endl; // 2
    ps.addPlate(20);  // Should output 'null'
    ps.addPlate(21);  // Should output 'null'
    
    cout << ps.removePlateAt(0) << endl; // 20
    cout << ps.removePlateAt(2) << endl; // 21
    cout << ps.removePlate() << endl;    // 5
    cout << ps.removePlate() << endl;    // 4
    cout << ps.removePlate() << endl;    // 3
    cout << ps.removePlate() << endl;    // 1
    cout << ps.removePlate() << endl;    // -1
    
    return 0;
}
