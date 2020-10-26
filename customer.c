// Impleting this with file handling
// giving the option to log in and register
#include<stdio.h>
#include<string.h>
#include "airportDetails.c"

void registerIntoFile(char userName[], char password[], int userNumber){
    // appending the information into a file
    FILE *fp, *updateUser;
    updateUser = fopen("totalUser.txt", "w");
    printf("\n User number : %d", userNumber);
    userNumber = userNumber+1;
    printf("\n User number : %d", userNumber);
    fprintf(updateUser, "%d", userNumber);
    fp = fopen("customerLogin.txt", "a");
    fprintf(fp, "%s\n%s\n", userName, password);
    fclose(fp);
    fclose(updateUser);
}

void registerCustomer(){
    char customerUserName[20];
    char firstPassword[30];
    printf("Enter the user name : ");
    scanf("%s", customerUserName);
    printf("Enter the password : ");
    scanf("%s",firstPassword);

    // condition to check if the username already exists or not
    char checkUserName[20];
    int netUser;
    FILE *fpLogin, *totalUser;
    totalUser = fopen("totalUser.txt", "r");
    fscanf(totalUser, "%d", &netUser);
    printf("\n Net User : %d", netUser);
    fpLogin = fopen("customerLogin.txt", "r");
    int i = 0, flag = 0;
    while(i<10){
        fscanf(fpLogin, "%s\n", checkUserName);
        if(strcmp(customerUserName, checkUserName) == 0){
            flag = 1;
            printf("\n\n Error: User Already exists, please enter a new user name\n\n");
            break;
        }
        i++;
    }
    fclose(fpLogin);
    fclose(totalUser);
    if(flag == 1)
        registerCustomer();
    else
    {
        registerIntoFile(customerUserName, firstPassword, netUser);
    }
    
}


void loginCheck(){
    char customerUser[20];
    char password[30];

    printf("\nEnter customer user ID : ");
    scanf("%s", &customerUser);
    printf("Enter password : ");
    scanf("%s", &password);

    char checkUser[20];
    int netUser;
    FILE *fpLogin, *totalUser;
    fpLogin = fopen("customerLogin.txt","r");
    totalUser = fopen("totalUSer.txt", "r");
    fscanf(totalUser, "%d", &netUser);
    int i = 0;
    int flag = 0;
    while(i<netUser*2){
        fscanf(fpLogin, "%s\n", checkUser);
        if(strcmp(customerUser, checkUser) == 0){
            fscanf(fpLogin, "%s\n", checkUser);
            if(strcmp(password, checkUser) == 0){
                printf("\n----------   Logged In   --------\n");
                flag = 1;
                print_routeDetails();
            }
            else{
                printf("Password Did Not match.....\n");
                flag = 2;
            }
            if(flag == 1 || flag == 2)
                break;
        }
        i++;
    }

    if(flag == 0){
        printf("\n\n*****No user Found as such*****\n\n");
        loginCheck();
    }
    else if(flag == 2){
        loginCheck();
    }
}


void loginOrRegister(){
    int opt;
    printf("\nEnter 1. To Register\n");
    printf("Enter 2. TO Login\n");
    scanf("%d", &opt);

    if(opt == 1)
        registerCustomer();
    else if(opt == 2)
        loginCheck();
    else{
        printf("\n\nEnter Valid option \n\n");
        loginOrRegister();
    }
}