#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int choice, id, order;
int total = 0;
char Fooditem[70], choiceRepeat[10];
float prices, finalPrice = 0;
float balance = 10000.0;

int addtocart();
void bill();
void cartt();
int delivarylocation();
int redeemCart();
int display();
int mainmenu();
int cuisinemenu();
int foods();
int drinks();
int deserts();
int local();
int international();
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

// food displays ways
int display(FILE *filename, char name[100])
{
    system("cls");
    rewind(filename);
    printf("***************************%s menu********************************\n", name);
    printf("No. %s Name \t\t    price\n", name);
    while (fscanf(filename, "%d %s %f", &id, Fooditem, &prices) != EOF)
    {
        printf("%-5d %-29s %.2f\n", id, Fooditem, prices);
    }
    printf("********************************************************************\n");
}

// adds to cart
int addtocart(FILE *filename, int enteredId)
{
    FILE *cart = fopen("cart.txt", "a");
    rewind(filename);
    while (fscanf(filename, "%d %s %f", &id, Fooditem, &prices) != EOF)
    {
        if (enteredId == id)
        {
            fprintf(cart, "%s %f\n", Fooditem, prices);
        }
    }
    fclose(cart);
}

int mainmenu()
{
    system("cls");
    int choice;
    printf("***************************Main menu********************************\n");
    printf("1.Cuisine Menu\t\t2.Bill\t\t3.Cart\t\t4.Exit\n");
    printf("********************************************************************\n");
    printf("Enter your choice of action ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        cuisinemenu();
        break;
    case 2:
        bill();
        break;
    case 3:
        cartt();
        break;
    case 4:
        getch();
        break;

    default:
        printf("sorry that option currently doesnot exist");
        break;
    }
}

int cuisinemenu()
{
    system("cls");
    int choice;
    printf("***************************Food menu********************************\n");
    printf("1.Food\t\t2.Drinks\t\t3.Back\n");
    printf("********************************************************************\n");
    printf("What do you wanna have? ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        foods();
        break;
    case 2:
        drinks();
        break;
    case 3:
        mainmenu();
        break;

    default:
        printf("sorry that option currently doesnot exist");
        break;
    }
}

int foods()
{
    system("cls");
    FILE *fl = fopen("local.txt", "r");
    FILE *italian = fopen("international-italian.txt", "r");
    FILE *fl2 = fopen("desert.txt", "r");

    printf("***************************Cuisine menu********************************\n");
    printf("1.Local cuisine\t\t2.International cuisine\t\t3.Deserts\t\t4.Back\n");
    printf("********************************************************************\n");
    printf("What do you wanna have? ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        local();
        break;
    case 2:
        international();
        break;

    case 3:
        deserts();
        break;

    case 4:
        cuisinemenu();
        break;

    default:
        printf("sorry that option currently doesnot exist");
        break;
    }
}

int drinks()
{
    FILE *drinks = fopen("DrinksList.txt", "r");

    system("cls");

    display(drinks, "Drinks");

    do
    {
        printf("What do you wanna order? ");
        scanf("%d", &order);

        addtocart(drinks, order);
        printf("What do you wanna order? (YES/NO): ");
        scanf("%s", &choiceRepeat);

    } while (strcmp(strupr(choiceRepeat), "YES") == 0);

    fclose(drinks);
}

int deserts()
{
    FILE *deserts = fopen("deserts.txt", "r");

    system("cls");

    display(deserts, "Deserts");

    do
    {
        printf("What do you wanna order? ");
        scanf("%d", &order);

        addtocart(deserts, order);
        printf("What do you wanna order? (YES/NO): ");
        scanf("%s", &choiceRepeat);

    } while (strcmp(strupr(choiceRepeat), "YES") == 0);

    if (strcmp(strupr(choiceRepeat), "NO") == 0)
    {
        foods();
    }
    else
    {
        printf("\nNo such option exists\n");
        sleep(2000);
        foods();
    }

    fclose(deserts);
}

int local()
{
    FILE *local = fopen("local.txt", "r");

    display(local, "Local food");

    do
    {
        printf("What do you wanna order? ");
        scanf("%d", &order);

        addtocart(local, order);
        printf("What do you wanna order? (YES/NO): ");
        scanf("%s", &choiceRepeat);

    } while (strcmp(strupr(choiceRepeat), "YES") == 0);

    if (strcmp(strupr(choiceRepeat), "NO") == 0)
    {
        foods();
    }
    else
    {
        printf("\nNo such option exists\n");
        sleep(2000);
        foods();
    }

    fclose(local);
}

void makePayment(float amount)
{
    if (amount <= balance)
    {
        int transactionID = rand() % 9000 + 1000;
        balance -= amount;
        printf("Payment successful! Transaction ID: %d\n", transactionID);
    }
    else
    {
        printf("Insufficient funds. Payment failed.\n");
    }
}

void payment()
{
    char choice[10];
    int option;
    FILE *fp = fopen("payment.txt", "a");
    printf("   CUSTOMER BILLING SYSTEM:\n\n");
    printf("===============================\n");
    printf("\n1. card payment\n");
    printf("2. cash on delivary\n");

    printf("Select an option (1/2): ");
    scanf("%s", &choice);

    if (choice == 1)
    {
        printf("\n Account number:");
        scanf("%d", &customer.acc_no);

        makePayment(finalPrice);
        delivarylocation();
    }
    else if (choice == 2)
    {
        printf("Cash on delivery\n");
        delivarylocation();
    }
    else
    {
        printf("Invalid choice. Please select a valid option.\n");
        Sleep(1000);
        payment();
    }
}

int delivarylocation()
{
    printf("\n Name:");
    scanf("%s", customer.name);
    printf("\n mobile no:");
    scanf("%f", &customer.mobile_no);
    printf(" Street:");
    scanf("%s", customer.street);
    printf(" City:");
    scanf("%s", customer.city);

    printf("\n\n your order is set to delivary\n");
    printf("\n\n press any key to continue");
    getch();
    printf("   :RECEIPT:\n\n");
    printf("===============================\n");
    printf("\nName: %s\n", customer.name);
    printf("Number: %f\n", customer.mobile_no);
    printf(" Location: %s,%s\n", customer.street, customer.city);
    printf("\n\n thank you for the patronage\n");
    printf("\n\n press any key to continue");
    getch();
    mainmenu();
}

int redeemCart()
{
    char choice[3];

checkPoint:

    printf("\n\n\n\n\t*****************************Cart*******************************\n");
    printf("\n\nYour Total Order Amount is : %d\n", total);
    printf("\n\nDo You wish to order (Yes/No) : ");
    scanf("%s", choice);

    if (strcmp(strupr(choice), "YES") == 0)
    {
        printf("\n\nLoading Order...");
        Sleep(3000);
        payment();
    }
    else if (strcmp(strupr(choice), "NO") == 0)
    {
        printf("To cancel Your Order = Yes\nTo Exit = No\n");
        printf("Select option : ");
        scanf("%s", choice);

        if (strcmp(strupr(choice), "YES") == 0)
        {

            remove("cart.txt");
            FILE *cart = fopen("cart.txt", "a");

            printf("\n\nOops! Your order is cancelled!! Exiting..\n\n");
            printf("Thank You visit again!\n");
            mainmenu();
        }
        else
        {
            // Product is bought
            printf("\n\n\t\t************Thank You******************\n\n");
            mainmenu();
        }
    }
    else
    {
        // Invalid choice
        printf("\n\nPlease Enter the correct choice\n\n ");
        goto checkPoint;
    }
}

int international()
{
    FILE *italian = fopen("international-italian.txt", "r");
    FILE *korean = fopen("international-korean.txt", "r");
    FILE *japanese = fopen("international-japanese.txt", "r");

    system("cls");
    printf("***************************Food menu********************************\n");
    printf("1.Italian\t\t2.Korean\t\t3.Japanese\t\t4.Back\n");
    printf("********************************************************************\n");
    printf("What do you wanna have? ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // italian

        display(italian, "Italian food");

        do
        {
            printf("What do you wanna order? ");
            scanf("%d", &order);

            addtocart(italian, order);
            printf("What do you wanna order? (YES/NO): ");
            scanf("%s", &choiceRepeat);

        } while (strcmp(strupr(choiceRepeat), "YES") == 0);

        if (strcmp(strupr(choiceRepeat), "NO") == 0)
        {
            international();
        }
        else
        {
            printf("\nNo such option exists\n");
            sleep(2000);
            international();
        }

        fclose(italian);
        break;

    case 2:
        // korean

        display(korean, "Korean food");

        do
        {
            printf("What do you wanna order? ");
            scanf("%d", &order);

            addtocart(korean, order);
            printf("What do you wanna order? (YES/NO): ");
            scanf("%s", &choiceRepeat);

        } while (strcmp(strupr(choiceRepeat), "YES") == 0);

        if (strcmp(strupr(choiceRepeat), "NO") == 0)
        {
            international();
        }
        else
        {
            printf("\nNo such option exists\n");
            sleep(2000);
            international();
        }

        fclose(korean);
        break;

    case 3:
        // japanese

        display(japanese, "Japanese food");

        do
        {
            printf("What do you wanna order? ");
            scanf("%d", &order);

            addtocart(japanese, order);
            printf("What do you wanna order? (YES/NO): ");
            scanf("%s", &choiceRepeat);

        } while (strcmp(strupr(choiceRepeat), "YES") == 0);

        if (strcmp(strupr(choiceRepeat), "NO") == 0)
        {
            international();
        }
        else
        {
            printf("\nNo such option exists\n");
            sleep(2000);
            international();
        }

        fclose(japanese);
        break;
    case 4:
        foods();
        break;
    default:
        printf("Invalid choice.\n");
    }
}

void bill()
{
    system("cls");
    printf("\t\t\t\t*Your Bill*\n");
    printf("*********************************************************************\n");
    printf("Item\t\t  price\n");
    FILE *fr = fopen("cart.txt", "r");
    float pricesumarr[50];
    int i = 1;

    while (fscanf(fr, "%s %f", Fooditem, &prices) != EOF)
    {
        pricesumarr[i] = prices;
        printf("%-30s   %.2f\n", Fooditem, prices);
        finalPrice = finalPrice + pricesumarr[i];
        i++;
    }

    printf("********************************************************************\n");
    printf("Your total is\t\t %.2f\n", finalPrice);
    getch();
    fclose(fr);
    mainmenu();
}

void cartt()
{
    FILE *cart = fopen("cart.txt", "r");
    int total = 0;
    char choice[3];

    system("cls");
    rewind(cart);
    printf("***************************cart********************************\n");
    printf("itemName \t\t      price\n");
    while (fscanf(cart, "%s %f", Fooditem, &prices) != EOF)
    {
        printf("%-29s %.2f\n", Fooditem, prices);
    }
    printf("********************************************************************\n");

    printf("\n\nDo You wish to order (Yes/No) : ");
    scanf("%s", choice);

    if (strcmp(strupr(choice), "YES") == 0)
    {
        printf("\n\nLoading Order...");
        Sleep(3000);
        payment();
    }
    else if (strcmp(strupr(choice), "NO") == 0)
    {
        printf("\nTo cancel Your Order = Yes\nTo Exit = No\n");
        printf("Select option : ");
        scanf("%s", choice);

        if (strcmp(strupr(choice), "YES") == 0)
        {

            remove("cart.txt");
            FILE *cart = fopen("cart.txt", "w");
            fclose(cart);
            printf("\n\nOops! Your order is cancelled!! Exiting..\n\n");
            Sleep(3000);
            mainmenu();
        }
        else if (strcmp(strupr(choice), "NO") == 0)
        {
            printf("\n\n\t\tPlease wait we are taking you to main menu\n\n");
            Sleep(3000);
            mainmenu();
        }
    }
    else
    {
        // Invalid choice
        printf("\n\nPlease Enter the one of the listed choice\n\n ");
        cartt();
    }

    fclose(cart);
}
