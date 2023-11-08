#include <stdio.h>

int main()
{
    FILE *fd = fopen("deserts.txt", "a");
    char drinks[600];
    int id, i;
    float price;
    do
    {
        printf("Enter id::");
        scanf("%d", &id);
        printf("Enter drinks::");
        scanf("%s", &drinks);
        printf("Enter price::");
        scanf("%f", &price);

        fprintf(fd, "%d %s	%.2f\n", id, drinks, price);

        printf("Enter I(1/2)::");
        scanf("%d", &i);
    } while (i == 1);

    fclose(fd);
    return 0;
}