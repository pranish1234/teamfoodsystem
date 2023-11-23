#include <stdio.h>
struct account
{
    int number;
    int acc_no;
    char name[100];
    char street[100];
    char city[100];
    float mobile_no;
    float payment;
} customer;

int i, n;
char ch;
int main()

{

    printf("   CUSTOMER BILLING SYSTEM:\n\n");
    printf("===============================\n");

    FILE *fp = fopen("payment.txt", "a");
    printf("\n Account number:");
    scanf("%d", &customer.acc_no);
    printf("\n Name:");
    scanf("%s", customer.name);
    printf("\n mobile no:");
    scanf("%f", &customer.mobile_no);
    printf(" Street:");
    scanf("%s", customer.street);
    printf(" City:");
    scanf("%s", customer.city);

    return 0;
}