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


// Global Variables
char name[16];
int age, password;
int amount = 0;

// Create account
int myAccount(){
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your password: ");
    scanf("%d", &password);

    return 0;

}

// login 
int login() {
    char inputName[16];
    int inputPassword;

    printf("Enter your username: ");
    scanf("%s", inputName);

    printf("Enter your password: ");
    scanf("%d", &inputPassword);

    if(strcmp(inputName, name) == 0 && inputPassword == password) {
        return 1;
    } else {
        return 0;
    }
}

// Deposit
int depo(int amount) {
    int dep;
    printf("Enter your Deposit: ");
    scanf("%d", &dep);
    
    int new_balance = amount + dep;
    printf("You have successfully Deposited %d\nBalance %d\n\n\tPress Enter to continue....", dep, new_balance);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033[H\033[J");

    return new_balance;
 }

// Withdraw
int myWithdraw(int amount){
    int withdraw;

    printf("Enter amount to withdraw: ");
    scanf("%d", &withdraw);

    if (withdraw > amount){
        printf("Insufficient funds\n");
        return amount;

    }

    int new_balance = amount - withdraw;
    printf("You have successfully withdrawn %d\nBalance %d\n\n\tPress Enter to continue.....\n", withdraw,new_balance);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
    printf("\033[H\033[J");
    
    return new_balance;

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
    
    
    int withdrawAmount = 0;


    if (loginStatus == 1) {
        printf("Login successful! Welcome, %s.\n\n\tPress Enter to continue......", name);
        // clear screen 
        int c;
        while ((c = getchar()) != '\n' && c != EOF);;
        getchar();
        printf("\033[H\033[J");

        do{
            printf("\n\n\t\t=== BANK SYSTEM ===\n1.Deposit\n2.Withdraw\n3.Send\n4.Save\n5.Get a loan\n");
            int option;

            //deposit = depo(amount);
            printf("\tBalance %d\n", amount);
            printf("\tSelect an option: ");
            scanf("%d", &option);


            switch(option) {
                case 1:
                    amount = depo(amount);
                    
                    break;
                case 2:
                    amount = myWithdraw(amount);
                    break;
                default:
                    printf("\n\t\t=== Goodbye===\n\n");
                    return 0;
            }
            
        } while (loginStatus == 1);

    } else {
        printf("\033[H\033[J");
        printf("\n\n\t\t!!!ACCESS DENIED!!!\n\n");
        return 0;
        
    }

    
    return 0;
}