#include <iostream>
#define SIZE 5
using namespace std;

class Dequeue {
    int arr[SIZE];
    int front, rear;

public:
    Dequeue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void addAtBeginning(int item) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at beginning.\n";
        } else if (isEmpty()) {
            front = rear = 0;
            arr[front] = item;
        } else {
            for (int i = rear; i >= front; --i) {
                arr[i + 1] = arr[i];
            }
            arr[front] = item;
            rear++;
        }
    }

    void addAtEnd(int item) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at end.\n";
        } else if (isEmpty()) {
            front = rear = 0;
            arr[rear] = item;
        } else {
            arr[++rear] = item;
        }
    }

    void deleteFromFront() {
        if (isEmpty()) {
            cout << "Underflow! Dequeue is empty.\n";
        } else {
            cout << "Deleted: " << arr[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void deleteFromRear() {
        if (isEmpty()) {
            cout << "Underflow! Dequeue is empty.\n";
        } else {
            cout << "Deleted: " << arr[rear] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                rear--;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Dequeue is empty.\n";
        } else {
            cout << "Dequeue elements: ";
            for (int i = front; i <= rear; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Dequeue dq;
    int choice, item;

    do {
        cout << "\n*** DEQUEUE OPERATIONS ***\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Display\n";
        cout << "4. Delete from Front\n";
        cout << "5. Delete from Rear\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to insert: ";
            cin >> item;
            dq.addAtBeginning(item);
            break;
        case 2:
            cout << "Enter the element to insert: ";
            cin >> item;
            dq.addAtEnd(item);
            break;
        case 3:
            dq.display();
            break;
        case 4:
            dq.deleteFromFront();
            break;
        case 5:
            dq.deleteFromRear();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
