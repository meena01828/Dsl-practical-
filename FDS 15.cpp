#include <iostream>
using namespace std;

const int MAX = 5;

class PizzaParlour {
    int front, rear;
    int orders[MAX];

public:
    PizzaParlour() : front(-1), rear(-1) {}

    bool addOrder(int id) {
        if ((rear + 1) % MAX == front) {
            cout << "\nCafe is Full. Please wait.\n";
            return false;
        }
        if (front == -1) front = 0; // Initialize front if the queue was empty
        rear = (rear + 1) % MAX;
        orders[rear] = id;
        return true;
    }

    void serveOrder() {
        if (front == -1) {
            cout << "\nNo Orders in Cafe. [Cafe is Empty]\n";
            return;
        }
        cout << "\nOrder No. " << orders[front] << " is processed.\n";
        if (front == rear) {
            front = rear = -1; // Reset queue if it becomes empty
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "\nCafe is Empty. No orders.\n";
            return;
        }
        cout << "\nCurrent Orders: ";
        for (int i = front; i != rear; i = (i + 1) % MAX) {
            cout << orders[i] << " ";
        }
        cout << orders[rear] << endl;
    }
};

int main() {
    PizzaParlour parlour;
    int choice, orderId = 0;

    do {
        cout << "\n***** Pizza Parlour *****\n";
        cout << "1. Accept Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            orderId++;
            if (parlour.addOrder(orderId)) {
                cout << "Order accepted. Order ID: " << orderId << endl;
            } else {
                orderId--;
            }
            break;
        case 2:
            parlour.serveOrder();
            break;
        case 3:
            parlour.display();
            break;
        case 4:
            cout << "\nThank You! Visit Again.\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}