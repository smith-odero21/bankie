/* Terminal Banking System
Enables the user to Create an acc., Deposit, Withdraw, Save ,
Send ,Recieve and Get a loan( unique loan estmator)
*/

#include <stdio.h>
#include <string.h>


// Global Variables
char name[16];
int age, password;


int myAccount(){
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your password: ");
    scanf("%d", &password);

    return 0;

}

int login() {
    char inputName[16];
    int inputPassword;

    printf("Enter your username: \n");
    scanf("%s", inputName);

    printf("Enter your password:\n");
    scanf("%d", &inputPassword);

    if(strcmp(inputName, name) == 0 && inputPassword == password) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    myAccount();
    printf("\t\t=== SignUp Successful ===\n\t\tPress Enter to continue......");

    // Pauses the screen
    getchar();
    getchar();

    // Clear the screen
    printf("\033[H\033[J");

    int loginStatus = 0;

    loginStatus = login();

    if (loginStatus == 1) {
        printf("\033[H\033[J");
        printf("Login successful! Welcome, %s.\n", name);
    } else {
        printf("\033[H\033[J");
        printf("Access Denied\n");
    }




    return 0;
}