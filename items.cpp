#include <stdio.h>
#include <string.h>
#include <windows.h>

int total = 0;
char choice[3];

void cart();

void payment() {
	//yeta kei pani na garne
}

void addtocart(int id) {

    printf("\n\n\n\n\t*****************************Cart*******************************\n");
    printf("\n\nYour Total Order Amount is : %d\n", total);
    printf("\n\nDo You wish to order (Yes/No) : ");
    scanf("%s", choice);

    if (strcmp(strupr(choice), "YES") == 0) {
        printf("\n\nLoading Order...");
        Sleep(3000);
        payment();
    } else if (strcmp(strupr(choice), "NO") == 0) {
        printf("To cancel Your Order = Yes\nTo Exit = No\n");
        printf("Select option : ");
        scanf("%s", choice);

        if (strcmp(strupr(choice), "YES") == 0) {
            // Failed to cancel
            printf("\n\nOops! Your item is cancelled!! Exiting..\n\n");
            printf("Thank You visit again!\n");
            mainmenu();
        } else {
            // Product is bought
            printf("\n\n\t\t************Thank You******************\n\n");
			mainmenu();
        }
    } else {
        // Invalid choice
        printf("\n\nPlease Enter the correct choice\n\n ");
        cart();
    }
}

