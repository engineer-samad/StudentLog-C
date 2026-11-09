#include <stdio.h>
#include <string.h>
#include "auth.h"

int adminLogin()
{
    char username[30];
    char password[30];

    printf("\n----- ADMIN LOGIN -----\n");

    printf("Enter Username: ");
    scanf("%29s", username);

    printf("Enter Password: ");
    scanf("%29s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "1234") == 0)
    {
        printf("\nLogin Successful!\n");
        return 1;
    }
    else
    {
        printf("\nIncorrect Username or Password!\n");
        return 0;
    }
}