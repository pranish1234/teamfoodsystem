#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int choice, id, order;
int total = 0;
char Fooditem[70], choiceRepeat[10];
float prices;

int addtocart();
int redeemCart();
int display();
int mainmenu();
int cuisinemenu();
int foods();
int drinks();
int deserts();
int local();
int international();

// food displays ways
int display(FILE *filename, char name[100])
{
    system("cls");
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
            fprintf(cart, "%d %s %f\n", id, Fooditem, prices);
        }
    }
    fclose(cart);
}

int mainmenu()
{
    int choice;
    printf("***************************Main menu********************************\n");
    printf("1.Cuisine Menu\t\t2.Bill\t\t3.Cart\n");
    printf("********************************************************************\n");
    printf("Enter your choice of action ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        cuisinemenu();
        break;
    case 2:
        // bill();
        break;
    case 3:
        // cart();
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
    printf("1.Food\t\t2.Drinks\n");
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
    printf("1.Local cuisine\t\t2.International cuisine\t\t3.Deserts\n");
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

    fclose(local);
}

void payment()
{
    // yeta kei pani na garne
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
    printf("1.italian\t\t2.korean\t\t3.japanese\n");
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

        fclose(japanese);
        break;
    default:
        printf("Invalid choice.\n");
    }
}
int main()
{
    mainmenu();
}