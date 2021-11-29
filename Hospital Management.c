#include<stdio.h>
#include<windows.h>  //gotoxy()
#include<conio.h>    //Use for delay(),getch(),etc
#include<ctype.h>    //use for toupper(), tolower(),etc
#include<string.h>   //use  for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>

// Variables required further are defined globally
char ans=0;
int ok;
int b, valid=0;

//Function Declaration
void WelcomeScreen(void); //Welcome Screen function declaration
void Title(void);  // Title function declaration
void MainMenu(void); //Main Menu functiondeclaration
void LoginScreen(void); //Login Screen function declaration
void Add_rec(void); // Adding record function declaration
void func_list(); //func_list function declaration
void Search_rec(void); //Search_rec function declaration
void Edit_rec(void); // Edit_rec function declaration
void Dlt_rec(void); // Delete record function declaration
void ex_it(void); // Exit function declaration

void gotoxy(short x, short y)
{
    COORD pos = {x, y}; //sets co-ordinates in (x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//List of global Variables
struct patient  // Defining Structure function and some important variables in it like age, etc
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Doctor[20];
    char Problem[20];
};

struct patient p, temp_c;
main(void) // declaring main function
{
    WelcomeScreen();
    Title();
    LoginScreen();
}

// Welcome Screen

void WelcomeScreen(void)
{
    system("Color 2B");
    printf("\n\n\n\n\n\n\n\t\t\t\t###################################################################");
    printf("\n\t\t\t\t#\t\t Welcome To\t\t#");
    printf("\n\t\t\t\t#   24 HOURS EMERGENCY Hospital Management System   #");
    printf("\n\t\t\t\t###################################################################");
    printf("\n\n\n\n\n Press any key to continue.......\n");
    getch();  // Use to hold the screen
    system("cls"); // use to clear screen

}

void Title(void)  // Function for Title Screen
{
    system("Color 1C");
    printf("\n\n\t\t\t------------------------------------------------");
    printf("\n\t\t\t\t       24 HOURS EMERGENCY HOSPITAL       ");
    printf("\n\t\t\t------------------------------------------------");
}

//************     Main Menu     **************
void MainMenu(void) // function declaration
{
    system("Color 4D");
    system("cls");
    int choose; // Defined choose variable
    Title(); // Calling title function so that it prints name of the hospital above main menu
    printf("\n\n\n\n\t\t\t\t 1. Add Patients Record\n");
    printf("\n\t\t\t 2. List Patients Record\n");
    printf("\n\t\t\t 3. Search Patients Record\n");
    printf("\n\t\t\t 4. Edit Patients Record\n");
    printf("\n\t\t\t 5. Delete Patients Record\n");
    printf("\n\t\t\t 6. Exit\n");
    printf("\n\n\n\t\t\t Choose from 1 to 6");
    scanf("%i", &choose);

    switch(choose) // using switch statement after making choice and using it as per requirement
    {
    case 1:
        Add_rec(); //if user clicks 1 Add records function will be called
        break;

    case 2:
        func_list(); //if user clicks 2 func_list function will be called
        break;
    case 3:
        Search_rec(); //if user clicks 3 search records function will be called
        break;
    case 4:
        Edit_rec(); //if user clicks 4 edit records function will be called
        break;
    case 5:
        Dlt_rec(); //if user clicks 5 delete records function will be called
        break;
    case 6:
        ex_it(); //if user clicks 6 exit function will be called
        break;
    default:
        printf("\t\t\tInvalid entry. Please enter right right option :)");  // if user inputs invalid number default statement will be printed
        getch();
    }
}

//************    Exit Function     **************//
void ex_it(void)
{
    system("Color 5D");
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\tTHANK YOU FOR VISITING, Hope Everything be fine :)");
    getch();
}


//*********      Login Screen    **************//
void LoginScreen(void)
{
    //list of variables
    system("Color 3F");
    int e=0;
    char Username[15];
    char Password[15];
    //To make project Authenticated for user username and password is asked and only if it matches with code's then only screen will move further
    char original_Username[25]="Aniket";
    char original_Password[15]="4353";
    do  // Using do while loop as it once runs without any condition and i require it
    {
        printf("\n\n\n\n\t\t\tEnter your Username and Password :");
        printf("\n\n\n\t\t\t\tUSERNAME:");
        scanf("%s", &Username);
        printf("\n\n\t\t\t\tPASSWORD:");
        scanf("%s", &Password);
        if (strcmp(Username, original_Username)==0 && strcmp(Password, original_Password==0))  //using if else for matching username and pasword between o/p screen and in code for which we have use string comparison i.e strcmp
        {
            printf("\n\n\n\t\t\t\t\t....Login Successful...");
            getch();
            MainMenu(); // once login is complete it will Call MainMenu function
            break;

        }
        else
        {
            printf("\n\t\t\tPassword is incorrect:( Try Again :)");
            e++;  // if it not matches then the loop will again go to if part and run atleast for 2 times as condition given below
            getch();
        }
    }while(e<=2);
    if(e>2)
    {
        printf("You have cross the limit. You cannot login. :( :("); // if you will try to run more than 2 times it will print this message
        getch();
        ex_it(); // After printing message it will call the exit function
    }
    system("cls"); // it will clear the screen
}

//*******************     Add Record Function       ****************//

void Add_rec(void)
{
    system("cls");
    Title();  // Call Title Function

    char ans;
    // File Handling is required in project
    FILE*ek;
    ek=fopen("Record2.dat", "a");  // open file in write mode
    printf("\n\n\t\t\t!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!\n");

    //****************    First Name    *****************//
    A:  // If you want to come here again just call A or anything with colon :, and call by saying goto A
        printf("\n\t\tFirstName: ");
        scanf("%s", p.First_Name); // p. is used bcoz in structure one we have defined on variable named First_Name
        p.First_Name[0]=toupper(p.First_Name[0]);
        if(strlen(p.First_Name)>20||strlen(p.First_Name)<2) // for valid size of name strlen is used
        {
            printf("\n\tInvalid :(\t The max range for first name is 20 and min range is 2:)");
            goto A;

        }
        else{
            for (b=0; b<strlen(p.First_Name);b++)
            {
                if (isalpha(p.First_Name[b]))  // isalpha checks that all the are alphabets or not
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if (!valid) // if value is invalid i.e valid=0 then print message and again goto A
            {
                printf("\n\t\t First name contain Invalid character :( Enter again :)");
                goto A;
            }
        }

        //**********   Last Name     ***********//

        // Everything similar to A is done just value B is changed
        B:
            printf("\n\t\t Last Name: ");
            scanf("%s", p.Last_Name[0]);
            p.Last_Name[0]=toupper(p.Last_Name[0]);
            if(strlen(p.Last_Name)>20||strlen(p.Last_Name)>2)
            {
                printf("\n\tInvalid :( \t The max for last name is 20 and min range is 2 :)");
                goto B;
            }
            else
            {
                for (b=0; b<strlen(p.Last_Name); b++)
                {
                    if (isalpha(p.Last_Name[b]))
                    {
                        valid=1;
                    }
                    else
                    {
                        valid=0;
                        break;
                    }
                }
                if(!valid)
                {
                    printf("\n\t\t Last name contain Invalid Character :( Enter again :)");
                    goto B;
                }
            }

            do
            {
                printf("\n\t\tGender[F/M]: ");
                scanf("%c", &p.Gender);
                if (toupper(p.Gender)=='M' || toupper(p.Gender)=='F') // it means only M And F are the valid values for this input
                {
                    ok = 1;
                }
                else {
                    ok = 0;
                }
                if(!ok) // if the value is invalid print the message
                {

                    printf("\n\t\t Gender contain Invalid character :( Enter either F or M :)");

                }

            }while(!ok);

            //*****************      Age       *****************//
            printf("\n\t\tAge:");
            scanf("%i", &p.age);

            //*****************       Address     ***************//

            do
            {
                C:
                    printf("\n\t\tAddress: ");
                    scanf("%s", p.Address);
                    p.Address[0]=toupper(p.Address[0]);
                    if (strlen(p.Address)>20 || strlen(p.Address)<4)
                    {
                        printf("\n\t Invalid :( \t The max range for Address is 20 and min range is 4 :)");
                        goto C;
                    }
            }while(!valid);

            //***************     Contact Number     **************//
            do
            {
                D:
                    printf("\n\t\tContact no.: ");
                    scanf("%s", p.Contact_no);
                    if (strlen(p.Contact_no)>10 || strlen(p.Contact_no)!=10)  // string length must be 10 so the condition is taken to satisfy it
                    {
                        printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
                        goto D;
                    }
                    else
                    {
                        for (b=0; b<strlen(p.Contact_no); b++)
                        {
                            if (!isalpha(p.Contact_no[b]))// this means that value should not have any alphabet
                            {
                                valid=1;
                            }
                            else
                            {
                                valid=0;
                                break;
                            }
                        }
                        if(!valid)
                        {
                            printf("\n\t\t Contact no. contain Invalid character :( Enter again :)");
                            goto D;
                        }
                    }

            }while(!valid);


            //***************       Email       ******************//

            do
            {
                printf("\n\t\tEmail: ");
                scanf("%s", p.Email);
                if (strlen(p.Email)>30 || strlen(p.Email)<8)
                {
                    printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");

                }
            }while(strlen(p.Email)>30||strlen(p.Email)<8);


            //*************     Problem      ******************//

            E:
                printf("\n\t\t\t Problem: ");
                scanf("%s", p.Problem);
                p.Problem[0]=toupper(p.Problem[0]);   // Many of the place toupper i.e uppercase is used to have the input in uppercase
                if (strlen(p.Problem)>15||strlen(p.Problem)<3)
                {
                    printf("\n\t Invalid :( \t The max range of first name is 15 and min range is 3 :)");
                    goto E;
                }
                else
                {
                    for (b=0; b<strlen(p.Problem); b++)
                    {
                        if (isalpha(p.Problem[b]))
                        {
                            valid=1;
                        }
                        else
                        {
                            valid=0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n\t\t Problem contain Invalid character :( Enter again :)");
                        goto E;
                    }

                }


                //******************       Prescribed Problem      ******************//

                F:
                    printf("\n\t\t\t Prescribed Doctor:");
                    scanf("%s", p.Doctor);
                    p.Doctor[0]=toupper(p.Doctor[0]);
                    if (strlen(p.Doctor)>30||strlen(p.Doctor)>3)
                    {
                        printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
                        goto F;
                    }
                    else
                    {



                        for (b=0; b<strlen(p.Doctor); b++)
                            {
                                if (isalpha(p.Doctor[b]))
                                {
                                    valid=1;
                                }
                                else
                                    {
                                        valid=0;
                                        break;
                                    }

                             }
                             if(!valid)
                                {
                                    printf("\n\t\t Doctor name contain Invalid character :( Enter again :)");
                                    goto F;
                                }
                     }
                     fprintf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);// character i.e %c means single value and %s i.e string means multiple values
                     printf("\n\n\t\t\t... Information Record Successful ...");
                     fclose(ek); // It means ek fk file is closed
                     sd:
                     getch(); // Hol the screen
                     printf("\n\n\t\tDo you want to add more[Y/N]??");
                     scanf("%c", &ans);
                     if (toupper(ans)=='Y') // toupper will convert your input in upper case and then compare it with Y
                     {
                         Add_rec();
                     }
                     else if(toupper(ans)=='N')
                     {
                         printf("\n\t\t Thank You :) :)");
                         getch();
                         MainMenu();
                     }
                     else
                     {
                         printf("\n\t\t Invalid Input\n");
                         goto sd;
                     }
}


//****************      View Record     *******************//
void func_list() // To print your patients record
{

    int row;
    system("Color 7B");
    system("cls");
    Title(); // Call Title function
    FILE *ek;
    ek=fopen("Record2.dat", "r");
    printf("\n\n\t\t\t !!!!!!!!! List Patients Record !!!!!!!!!!!!!!!\n");
    gotoxy(1, 15); // parameters of gotoxy means it has left 1 space from left screen i.e x-axis and 15 spaces from top i.e y-axis similarly for all informations in record
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(32, 15);
    printf("Age");
    gotoxy(37, 15);
    printf("Address");
    gotoxy(49, 15);
    printf("Contact No.");
    gotoxy(64, 15);
    printf("Email");
    gotoxy(88, 15);
    printf("Problem");
    gotoxy(98, 15);
    printf("Prescribed Doctor\n");
    printf("==================================================================");
    row=17;
    while(fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email,p.Problem,p.Doctor)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s", p.First_Name, p.Last_Name);
        gotoxy(20, row);
        printf("%c", p.Gender);
        gotoxy(32, row);
        printf("%i", p.age);
        gotoxy(37, row);
        printf("%s", p.Address);
        gotoxy(49, row);
        printf("%s", p.Contact_no);
        gotoxy(64, row);
        printf("%s", p.Email);
        gotoxy(88, row);
        printf("%s", p.Problem);
        gotoxy(98, row);
        printf("%s", p.Doctor);
        row++;
    }
    fclose(ek);
    getch();
    MainMenu();
}

//*************   Search Patients Record         *************//

void Search_rec(void)
{
    char name[20];
    system("Color 5A");
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat", "r");
    printf("\n\n\t\t !!!!!!!!! Search Patients Record !!!!!!!!!!!");
    gotoxy(12, 8);
    printf("\n Enter Patient Name to be viewed:");
    scanf("%s", name);
    fflush(stdin); // To search for anything after entering name fflush is used
    name[0]=toupper(name[0]);
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no))
    {
        if(strcmp(p.First_Name, name)==0) // strcmp is used to compare the name in record if it matches then the loop will run
        {
            gotoxy(1, 15);
            printf("Full Name");
            gotoxy(25, 15);
            printf("Gender");
            gotoxy(32, 15);
            printf("Age");
            gotoxy(37, 15);
            printf("Address");
            gotoxy(52, 15);
            printf("Contact No.");
            gotoxy(64, 15);
            printf("Email");
            gotoxy(80, 15);
            printf("Problem");
            gotoxy(95, 15);
            printf("%s", p.Doctor);
            printf("\n");
            break;

        }
    }
    if(strcmp(p.First_Name, name)!=0)
    {
        gotoxy(5, 10);
        printf("Record not found!");
        getch();
    }
    fclose(ek);

    L:
        getch();
        printf("\n\n\t\t\tDo you want to view more[Y/N]??");
        scanf("%c", &ans);
        if (toupper(ans)=='Y')
        {
            Search_rec();
        }
        else if(toupper(ans)=='N')
        {
            printf("\n\t\t Thank You :) :)");
            getch();
            MainMenu();
        }
        else
        {
            printf("\n\t Invalid Input. \n");
            goto L;
        }
}


//***********   Edit Record     ***********//
void Edit_rec(void)
{
    FILE *ek, *ft; // Two file pointers are take bcoz one file will be edited and saved and another will be deleted
    int i, b, valid=0;
    char ch;
    char name[20];
    system("cls");
    system("Color 4C");
    Title();
    ft=fopen("temp2.dat", "w+");
    ek=fopen("Record2.dat", "r");
    if(ek==NULL)
    {
        printf("\n\t Can notopen file!!");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t!!!!!!!!!! Edit Patients Record !!!!!!!!");
    gotoxy(12, 13);
    printf("Enter the First Name of the Patient : ");
    scanf("%s", name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12, 15);
    if(ft==NULL)
    {
        printf("\n Can not open file");
        getch();
        MainMenu();

    }
    while(fscanf(ek, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no))
    {
        if(strcmp(p.First_Name, name)==0)
        {
            valid=1;
            gotoxy(25, 17);
            printf("*** Existing Record ***");
            gotoxy(10, 19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no);
            gotoxy(12, 22);
            printf("Enter New First Name: ");
            scanf("%s", p.First_Name);
            gotoxy(12, 24);
            printf("Enter Last Name");
            scanf("%s", p.Last_Name);
            gotoxy(12, 26);
            printf("Enter Gender");
            scanf("%c", &p.Gender);
            p.Gender=toupper(p.Gender);
            gotoxy(12, 28);
            printf("Enter Age: ");
            scanf("%i", &p.age);
            gotoxy(12, 30);
            printf("Enter Address: ");
            scanf("%s", p.Address);
            gotoxy(12, 32);
            printf("Enter Contact no. :");
            scanf("%s", p.Contact_no);
            gotoxy(12, 34);
            printf("Enter New Email: ");
            scanf("%s", p.Email);
            gotoxy(12, 36);
            printf("Enter Problem: ");
            scanf("%s", p.Problem);
            gotoxy(12, 38);
            printf("Enter Doctor: ");
            scanf("%s", p.Doctor);
            p.Doctor[0]=toupper(p.Doctor[0]);
            printf("\nPress U character for the Updating operation: ");
            ch=getch();
            if(ch=='u' || ch=='U')
            {
                fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.age, p.Address, p.Contact_no);
                printf("\n\n\t\t\tPatient record updated successfully...");
            }
        }
        else
        {
            fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no);
        }

    }
    if(!valid)
    {
        printf("\n\t\tNo Record Found...");
    }
    fclose(ft);
    fclose(ek);
    remove("Record2.dat");
    rename("temp2.dat", "Record2.dat");
    getch();
    MainMenu();
}

//****************   Delete Record      *****************//
void Dlt_rec()
{
    char name[20];
    int found=0;
    system("Color 5E");
    system("cls");
    Title();
    FILE *ek, *ft;
    ft=fopen("temp_file2.dat", "w+");
    ek=fopen("Record2.dat", "r");
    printf("\n\n\t\t\t!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!!!!");
    gotoxy(12, 8);
    printf("\n Enter Patient Name to delete: ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);
    while (fscanf(ek, "%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no))
    {
        if (strcmp(p.First_Name, name)!=0)

        fprintf(ft, "%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no);

        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no);
            found=1;
        }

    }
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found.....");
        getch();
        MainMenu();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Record2.dat");
        rename("temp_file2.dat", "Record2.dat");
        printf("\n\n\t\t\t Record deleted successfully :)");
        getch();
        MainMenu();
    }
}
