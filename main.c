#include <stdio.h>
#include <stdlib.h>

int choice, id, order;
char Fooditem[70];
float prices;

int cart();
int display(FILE *filename, char name[100]);
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
        cart();
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
        // for desert
        deserts();

        break;

    default:
        printf("sorry that option currently doesnot exist");
        break;
    }
}
int cart()
{
    FILE *cart = fopen("cart.txt", "r");
    display(cart, "cart");
    fclose(cart);
}
int drinks()
{
    FILE *drinks = fopen("DrinksList.txt", "r");

    system("cls");

    display(drinks, "Drinks");

    printf("What do you wanna order? ");
    scanf("%d", &order);
    fclose(drinks);
}
int deserts()
{
    FILE *deserts = fopen("deserts.txt", "r");

    system("cls");

    display(deserts, "Deserts");

    printf("What do you wanna order? ");
    scanf("%d", &order);
    fclose(deserts);
}
int local()
{
    FILE *local = fopen("local.txt", "r");

    display(local, "Local food");

    printf("What do you wanna order? ");
    scanf("%d", &order);
    fclose(local);
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

        printf("What do you wanna order? ");
        scanf("%d", &order);
        fclose(italian);
        break;

    case 2:
        // korean

        display(korean, "Korean food");

        printf("What do you wanna order? ");
        scanf("%d", &order);
        fclose(korean);
        break;

    case 3:
        // japanese

        display(japanese, "Japanese food");

        printf("What do you wanna order? ");
        scanf("%d", &order);
        fclose(japanese);
        break;
    default:
        printf("Invalid choice.\n");
    }
}
