/*  
    ==== Terminal Banking System ====
    => Enables the user to Create an acc., Deposit, Withdraw, Save,
    => Send, Recieve and Get a loan( unique loan estimator)

*/

#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define NAME_LENGTH 16

// Parallel Arrays (Global Variables)
char names[MAX_USERS][NAME_LENGTH];
int ages[MAX_USERS];
int passwords[MAX_USERS];
int balances[MAX_USERS]; // Replaces global 'amount'

int userCount = 0; // Tracks total registered users
int currentUserIndex = -1; // Tracks who is currently logged in ( -1 means none )


// Create account
void myAccount(){
    printf("Enter your name: ");
    scanf("%s", names[userCount]);

    printf("Enter your age: ");
    scanf("%d", &ages[userCount]);

    printf("Enter your password: ");
    scanf("%d", &passwords[userCount]);

    balances[userCount] = 0; // Initialize balance to 0

    userCount++; // Move to the next slot for the next user
    printf("\n\n\t\t=== SignUp Successful ===\n\t\tPress Enter Continue.....");



}

// login - returns the index of the logged-in user, pr -1 if failed
int login() {
    char inputName[NAME_LENGTH];
    int inputPassword;

    printf("Enter your username: ");
    scanf("%s", inputName);

    printf("Enter your password: ");
    scanf("%d", &inputPassword);

    // Search through all existing users
    for (int i = 0; i < userCount; i++) {
        if (strcmp(inputName, names[i]) == 0 && inputPassword == passwords[i]) {
            return i;
        }
    }
    return -1; // Login failed

}

// Deposit
void depo() {
    int dep;
    printf("Enter your Deposit: ");
    scanf("%d", &dep);
    
    balances[currentUserIndex] += dep; // Update current user's balance
    printf("You have successfully Deposited %d\nBalance %d\n\n\tPress Enter to continue....", dep, balances[currentUserIndex]);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033[H\033[J");

 }

// Withdraw
void myWithdraw(){
    int withdraw;

    printf("Enter amount to withdraw: ");
    scanf("%d", &withdraw);

    if (withdraw > balances[currentUserIndex]){
        printf("Insufficient funds\n");
        return;
    }

    balances[currentUserIndex] -= withdraw; // Deduct from current user balance
    printf("You have successfully withdrawn %d\nBalance %d\n\n\tPress Enter to continue.....\n", withdraw,balances[currentUserIndex]);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033[H\033[J");

}

// Send money dynamically from the logged-in user to anaother
void transferMoney() {
    char recipientName[NAME_LENGTH];
    int amount;
    int recipientIndex = -1;

    printf("Enter recipient's username: ");
    scanf("%s", recipientName);

    // 1. Search for recipient index
    for (int i = 0; i < userCount; i++) {
        if (strcmp(recipientName, names[i]) == 0) {
            recipientIndex = i;
            break;
        }
    }

    printf("Enter amount to send: ");
    scanf("%d", &amount);

    if (amount > balances[currentUserIndex]) {
        printf("Error: Insuffiecient funds. Your balance is %d\n", balances[currentUserIndex]);
        return;
    }

}

int main() {
    int mainChoice;

    while(1) {
        printf("\n\t\t==== WELCOME TO THE BANK TERMINAL ====\n");
        printf("1. Register New Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &mainChoice);
        printf("\033[H\033[J"); /// CLEAR SCREEN
    
        if (mainChoice == 1) {
            myAccount();
            

            // Pauses the screen
            getchar();
            getchar();

            // Clear the screen
            printf("\033[H\033[J");
        } else if (mainChoice == 2) {
            currentUserIndex = login();

            if (currentUserIndex != -1) {
                printf("Login successful! Welcome, %s. \n\n\tPress Enter to continue.....", names[currentUserIndex]);

                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                printf("\033[H\033[J");

                int banking = 1;
                while (banking) {
                    printf("\n\n\t\t=== BANK SYSTEM (%s) ===\n1.Deposit\n2.Withdraw\n3.Logout\n", names[currentUserIndex]);
                    int option;

                    printf("\tBalance %d\n", balances[currentUserIndex]);
                    printf("\tSelect an option: ");
                    scanf("%d", &option);

                    switch(option) {
                        case 1:
                            depo();
                            break;
                        case 2:
                            myWithdraw();
                            break;
                        default:
                            printf("\n\n\t\t=== Loggin Out...... ===\n\nPress Enter To Continue\n");
                            currentUserIndex = -1; // Reset active user index
                            banking = 0; // Break out of the banking loop
                            int c;
                            while ((c = getchar()) != '\n' && c != EOF);
                            getchar();
                            printf("\033[H\033[J");
                            break;


                    }
                }
            } else {
                printf("\n\n\t\t!!!ACCESS DENIED!!!\n\n");
            }
        }
        else {
            printf("\n\n\t\t====== GOODBYE =====\n\n");
            break;
        }
    }

    

    
    return 0;
}
