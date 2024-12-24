#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue recursively
void reverseQueue(queue<int>& q) {
    // Base case: if the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Step 1: Remove the front element of the queue
    int front = q.front();
    q.pop();

    // Step 2: Recursively reverse the remaining queue
    reverseQueue(q);

    // Step 3: Add the removed element to the back of the queue
    q.push(front);
}

int main() {
    // Input queue
    queue<int> Q;
    Q.push(5);
    Q.push(24);
    Q.push(9);
    Q.push(6);
    Q.push(8);
    Q.push(4);
    Q.push(1);
    Q.push(8);
    Q.push(3);
    Q.push(6);

    // Print original queue
    cout << "Original Queue: ";
    queue<int> tempQ = Q; // Temporary queue to preserve original for printing
    while (!tempQ.empty()) {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << endl;

    // Reverse the queue
    reverseQueue(Q);

    // Print reversed queue
    cout << "Reversed Queue: ";
    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;

    return 0;
} 
