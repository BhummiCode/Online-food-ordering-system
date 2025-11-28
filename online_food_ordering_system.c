#include <stdio.h>
#include <string.h>

#define MAX 100   // Maximum number of orders

// Structure for order
struct Order {
    int order_id;
    char name[50];
    char item[50];
    float price;
};

// Queue variables
struct Order queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Add order (enqueue)
void placeOrder() {
    if (isFull()) {
        printf("\nQueue is full! Cannot place more orders.\n");
        return;
    }
    struct Order o; //temp. structure to store new coming order
    printf("\nEnter customer name: ");
    scanf(" %[^\n]", o.name);
    printf("Enter food item: ");
    scanf(" %[^\n]", o.item);
    printf("Enter total price: ");
    scanf("%f", &o.price);
    o.order_id = rear + 2; // simple order ID

    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = o;

    printf(" Order %d placed successfully!\n", o.order_id);
}

// Serve order (dequeue)
void serveOrder() {
    if (isEmpty()) {
        printf("\nNo orders to serve!\n");
        return;
    }
    printf("\nServing Order %d for %s (Item: %s, Price: %.2f)\n",
           queue[front].order_id, queue[front].name,
           queue[front].item, queue[front].price);
    front++;
}

// Display all pending orders
void displayOrders() {
    if (isEmpty()) {
        printf("\nNo pending orders.\n");
        return;
    }
    printf("\n--- Pending Orders ---\n");
    for (int i = front; i <= rear; i++) {
        printf("Order ID: %d | Name: %s | Item: %s | Price: %.2f\n",
               queue[i].order_id, queue[i].name,
               queue[i].item, queue[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Online Food Ordering System ===\n");
        printf("1. Place Order\n");
        printf("2. Serve Order\n");
        printf("3. Display Pending Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: placeOrder(); break;
            case 2: serveOrder(); break;
            case 3: displayOrders(); break;
            case 4: printf("Exiting... Thank you!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
