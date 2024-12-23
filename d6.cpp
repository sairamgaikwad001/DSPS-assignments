// DSPS Assignment No. 6

/* Perform the following operation on the Double Ended Queue. 
	-Check Empty
	-Check full
	-EnQueue
	-DeQueue
	-Display      */


#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor to initialize the deque
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Enqueue at the front
    void enQueueFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at front.\n";
            return;
        }

        if (front == -1) {  // If deque is empty
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = value;
        size++;
    }

    // Enqueue at the rear
    void enQueueRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at rear.\n";
            return;
        }

        if (rear == -1) {  // If deque is empty
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        size++;
    }

    // Dequeue from the front
    void deQueueFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;  // Reset when the deque becomes empty
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        size--;
    }

    // Dequeue from the rear
    void deQueueRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;  // Reset when the deque becomes empty
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        size--;
    }

    // Display the elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << arr[rear] << endl; // Display the rear element
    }
};

int main() {
    int capacity, choice, value;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;
    Deque dq(capacity); // Create a deque with given capacity

    do {
        cout << "\nDouble Ended Queue (Deque) Operations Menu:\n";
        cout << "1. Enqueue at Front\n";
        cout << "2. Enqueue at Rear\n";
        cout << "3. Dequeue from Front\n";
        cout << "4. Dequeue from Rear\n";
        cout << "5. Display\n";
        cout << "6. Check if Empty\n";
        cout << "7. Check if Full\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue at front: ";
                cin >> value;
                dq.enQueueFront(value);
                break;

            case 2:
                cout << "Enter value to enqueue at rear: ";
                cin >> value;
                dq.enQueueRear(value);
                break;

            case 3:
                dq.deQueueFront();
                break;

            case 4:
                dq.deQueueRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Is deque empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;
                break;

            case 7:
                cout << "Is deque full? " << (dq.isFull() ? "Yes" : "No") << endl;
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

