#include <stdio.h>
struct date
{
    int month;
    int day;
    int year;
};

struct account
{
    int number;
    int acc_no;
    char name[100];
    char street[100];
    char city[100];
    float mobile_no;
    float payment;
    struct date;
} customer;

int i, n;
char ch;
int main()

{

    printf("   CUSTOMER BILLING SYSTEM:\n\n");
    printf("===============================\n");
}
FILE *fp = fopen("payment.dat", "a");
printf("\n Account number:");
scanf("%d", &customer.acct_no);
printf("\n Name:");
scanf("%s", customer.name);
printf("\n mobile no:");
scanf("%f", &customer.mobile_no);
printf(" Street:");
scanf("%s", customer.street);
printf(" City:");
scanf("%s", customer.city);
printf(" Payment date(mm/dd/yyyy):");

return 0;
}