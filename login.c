#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.c"

int main()
{

    FILE *file = fopen("credentials.txt", "a");
    FILE *file1 = fopen("credentials.txt", "r");
    char storedUsername[20];
    char storedPassword[20];
    char username[20];
    char password[20];
    int n, flag;

    system("cls");
    printf("Welcome to the login page!\n");
    printf("***********************(login/signup page)**************************\n");
    printf("1.login/signin\t\t\t 2.signup/register\n");
    printf("********************************************************************\n");

    printf("which task you want to perform? ");
    scanf("%d", &n);
    switch (n)
    {

    case 1:

        printf("Please enter your username: ");
        scanf("%s", username);

        printf("\nPlease enter your password: ");
        scanf("%s", password);

        while (fscanf(file1, "%s %s", storedUsername, storedPassword) != EOF)
        {
            if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
            {
                flag = 1;
            }
        }

        ;
        if (flag == 1)
        {
            system("cls");
            printf("Welcome, %s!\n", username);
            fclose(file1);
            mainmenu();
        }

        else
        {
            printf("Incorrect username or password. Please try again.");
        }
        break;

    case 2:

        printf("Please enter your username: ");
        scanf("%s", username);

        printf("Please enter your password: ");
        scanf("%s", password);

        fprintf(file, "%s %s", username, password);
        fclose(file);
        printf("Account created successfully!");
        sleep(1);
        main();

    default:
        break;
    }
    return 0;
}
