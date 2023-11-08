#include<stdio.h>
#include<conio.h>
#include <ctype.h> 
#include <math.h> 
#include <stdio.h> 
#include <string.h> 
#include <time.h> 
// Structure to store details about 
// foods 
struct foods { 
	char food[100]; 
	char item1[20]; 
	char item2[20]; 
	char item3[20]; 
	char item4[25]; 
	int first, second, third, fourth; 
}; 
// item_order function to process items ordered 
void item_order(int item) 
{ 

	if (item >= 1 && item <= 3) 
		food_id = 1; 
	else if (item >= 4 && item <= 6) 
		shop_id = 2; 
	else
		food_id = 3; 
	if ((item % 3) == 1) { 
		// Asking for choice of product 
		printf("Please Enter the"); 
		printf(" Count of %s : ", m[food_id].item1); 
		scanf("%d", &n); 
		total = total + (n * m[food_id].first); 
	} 
	else if ((item % 3) == 2) { 
		// Asking for choice of product 
		printf("Please Enter the "); 
		printf("Count of %s\t", m[food_id].item2); 
		scanf("%d", &n); 
		total = total + (n * m[food_id].second); 
	} 
	else if ((item % 3) == 0) { 
		// Asking for choice of product 
		printf("Please Enter the Count of %s\t", 
			m[food_id].item3); 
		scanf("%d", &n); 
		total = total + (n * m[food_id].third); 
	} 
} 

// Function to implement the cart 
void cart() 
{ 
	// details about the products in cart 
	printf("\n\n\n\n\t*****************************Cart*******************************"); 
	printf("\n\nYour Total Order Amount is : %d\n", total); 
	printf("\n\nDo You wish to order (y=1/n=0) : "); 
	scanf("%d", &ch); 
	if (ch == 1) { 
		printf("\n\nThank You for your Order"); 
		printf("\nYour item is on the way. Welcome again "
			"\n\n "); 

		main(); 
		return; 
	} 
	else if (ch == 0) { 
		printf("To cancel Your Order = 1 \nTo Exit = 0 "); 
		printf("Select option : "); 
		scanf("%d", &confirm); 
		if (confirm == 1) { 
			//Failed 
			printf("\n\nOops! Your item is cancelled!! "
				"Exiting..\n\n"); 
			printf("Thank You visit again!\n"); 
			main(); 
			return; 
		} 
		else { 
			// Product is bought 
			printf("\n\n\t\t************Thank "
				"You******************\n\n"); 
			login(); 
		} 
	} 
	else { 
		// Asking for choice 
		printf("\n\nPlease Enter the correct choice\n\n "); 
		cart(); 
	} 
} 
int main()
{
	/* code */
	return 0;
}
