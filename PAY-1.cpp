#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float balance = 10000.0;

void makePayment(float amount) {
    if (amount <= balance) {
        int transactionID = rand() % 9000 + 1000;
        balance -= amount;
        printf("Payment successful! Transaction ID: %d\n", transactionID);
    } else {
        printf("Insufficient funds. Payment failed.\n");
}
}

int main() {

    char choice[10];
    int option;
        printf("\n1. card payment\n");
        printf("2. cash on delivary\n");

        printf("Select an option (yes/no): ");
        scanf("%s", &choice);

        if (strcmp(strupr(choice), "YES") == 0) {

            makePayment(finalPrice);
            delivarylocation();
        } 
		else if (strcmp(strupr(choice), "NO") == 0) {
            printf("Cash on delivery\n");
            delivarylocation();
            } 
		else {
            printf("Invalid choice. Please select a valid option.\n");
        }

    return 0;
}
