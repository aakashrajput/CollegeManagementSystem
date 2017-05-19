#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct date{
    int month,day,year;
};

struct {
    char name[50];
    int usr_no,age;
    char address[60];
    char subject[15];
    char branch[15];
    double phone;
    struct date dob;
}add,upd,check,rem;

struct {
    char name[50];
    int usn_no,age;
    char address[60];
    char email[15];
    char branch[15];
    double phone;
    struct date dob;
}addstu,updstu,checkstu,remstu;

int i,j;
int main_exit;
void menu();
void welcome();
void teacher();
void add_teacher();
void edit_teacher();
void erase_teacher();
void search_teacher();
void teacher_list();
void student();
void add_student();
void edit_student();
void erase_student();
void search_student();
void student_list();
void login();
void load();

int main()
{
   _setcursortype(0);
   welcome();
   clrscr();
   login();
   return 0;
}

void login()
{
int i,counter=0,flag=0;
char uid[25],pwd[25],s_uid[][25]={"admin1","aakash","admin2"};
char s_pwd[][25]={"rrce@123","1998","RRCE@123"},ch='a';/*dummy character in ch */
 clrscr();
gotoxy(40,4);printf("\n USERID : ");
scanf("%s",uid);
gotoxy(40,6);printf("\n PASSWORD: ");
i=0;
while(1)
{
    ch=getch();
    if(ch==13)
    break;
    else if(ch==8)
    {       if(i!=0) /*this is for avoiding the ENTER instructions getting deleted */
        {
            printf("\b");  /*printing backspace to move cursor 1 pos back*/
            printf("%c",32);/*making the char invisible which is already on console*/
            printf("\b"); /*printing backspace to move cursor 1 pos back*/
            i--;
            pwd[i]='\0';
        }
        else
        continue;
    }
    else
    {
    putchar('*');/* char - '*' will be printed instead of the character */
    pwd[i]=ch;
    i++;
    }
}
pwd[i]='\0';
for(i=0;i<=2;i++)
{
    if((stricmp(uid,s_uid[i]))==0 && (strcmp(pwd,s_pwd[i]))==0)
    {
        flag=1;
        break;
    }
}
if(flag){
printf("\n\n\nCorrect Password");delay(1000);
clrscr();
load();
}

else {
textcolor(RED);printf("\n\nWrong Password");
}
getch();
}


void welcome()
{
    int i;
    clrscr();

    textcolor(WHITE);gotoxy(27,1);cprintf("==== College MANAGEMENT SYSTEM ====");

    gotoxy(1,4);printf("\t\t\t\xB2\xB2\xB2\ GROUP PROJECT DESIGN AND PROGRAMMED BY \xB2\xB2\xB2\xB2");

    textcolor(WHITE);gotoxy(30,6);cprintf("Aakash Singh\n");
    gotoxy(30,7);cprintf("Arpit Singh\n");
    gotoxy(30,8);cprintf("Ankita suman\n");
    gotoxy(30,9);cprintf("Anikesh Kumar\n");
    gotoxy(30,10);cprintf("KeerthiPriya\n");


do{
  gotoxy(30,24); printf("  < Press any key >  ");
  delay(500);if(kbhit()){getch();break;}
  gotoxy(30,24); printf(" << Press any key >> ");
  delay(500);if(kbhit()){getch();break;}
  gotoxy(30,24); printf("<<< Press any key >>>");
  delay(500);if(kbhit()){getch();break;}
 }while(1);
}


void menu(void)
{   int choice;
    clrscr();
    textcolor(9);
    gotoxy(12,1);cprintf("RAJARAJESWARI COLLEGE OF ENGINEERING MANAGEMENT SYSTEM\n");
    gotoxy(24,3);cprintf("WELCOME TO THE MAIN MENU\n");
    gotoxy(8,10);cprintf("1.Teacher\n");
    gotoxy(8,11);cprintf("2.Students\n");
    gotoxy(8,12);cprintf("3.Marks Seet\n");
    gotoxy(8,14);cprintf("Enter your Choice:");
    scanf("%d",&choice);

    clrscr();
    switch(choice)
    {
	case 1:teacher();
	break;
	case 2:student();
    break;

    }



}

void teacher()
{
    int choice;
    clrscr();
    textcolor(9);
    gotoxy(12,1);cprintf("RAJARAJESWARI COLLEGE OF ENGINEERING MANAGEMENT SYSTEM\n");
    gotoxy(24,3);cprintf("WELCOME TO THE MAIN MENU\n");
    gotoxy(8,10);cprintf("1.Add New Teacher\n");
    gotoxy(8,11);cprintf("2.Remove Teacher\n");
    gotoxy(8,12);cprintf("3.Update Teacher\n");
    gotoxy(8,13);cprintf("4.Search Teacher\n");
    gotoxy(8,14);cprintf("5.View all\n");
    gotoxy(8,20);printf("Enter 6 to go to the main menu and 0 to exit");
    gotoxy(8,16);cprintf("Enter your Choice:");
    scanf("%d",&choice);



    clrscr();
    switch(choice)
    {
	case 0:close();
	break;
	case 1:add_teacher();
	break;
    case 2:erase_teacher();
    break;
	case 3:edit_teacher();
	break;
	case 4:search_teacher();
	break;
    case 5:teacher_list();
    break;
    case 6:menu();
    break;



    }



}

void add_teacher()

{
    int choice;
    FILE *ptr;

    ptr=fopen("teacher.dat","a+");
    user_no:
    clrscr();
    printf("\t\t\t\xB2\xB2\xB2\ ADD NEW TEACHER RECORD  \xB2\xB2\xB2\xB2");
    printf("\nEnter the user ID:");
    scanf("%d",&check.usr_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch)!=EOF)
    {
	if (check.usr_no==add.usr_no)
	    {printf("User ID. already in exist!");
	    delay(10000);
		goto user_no;

	    }
    }
    add.usr_no=check.usr_no;
    printf("\nEnter the name:");
    scanf("%s",&add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the Subject:");
    scanf("%s",add.subject);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the Branch: ");
    scanf("%s",&add.branch);

	fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s\n",add.usr_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.subject,add.phone,add.branch);


    fclose(ptr);
    printf("\nTeacher Added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    clrscr();

    if (main_exit==1)
	menu();
    else if(main_exit==0)
	    close();
    else
	{
	    printf("\nInvalid!\a");
	    goto add_invalid;
	}
}

void edit_teacher()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("teacher.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the User ID. of the Teacher whose info you want to change:");
    scanf("%d",&upd.usr_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch)!=EOF)
    {
	if (add.usr_no==upd.usr_no)
	{   test=1;
	    printf("\nWhich information do you want to change?\n1.Address\n2.Phone\\n\nEnter your choice(1 for address and 2 for phone):");
	    scanf("%d",&choice);
	    system("cls");
	    if(choice==1)
		{printf("Enter the new address:");
		scanf("%s",upd.address);
		fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch);
		system("cls");
		printf("Changes saved!");
		}
	    else if(choice==2)
		{
		    printf("Enter the new phone number:");
		scanf("%lf",&upd.phone);
		fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch);
		system("cls");
		printf("Changes saved!");
		}

	}
	else
	    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch);
    }
    fclose(old);
    fclose(newrec);
    remove("teacher.dat");
    rename("new.dat","teacher.dat");

if(test!=1)
	{   system("cls");
	    printf("\nRecord not found!!\a\a\a");
	    edit_invalid:
	      printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	      scanf("%d",&main_exit);
	      system("cls");
		 if (main_exit==1)

		    menu();
		else if (main_exit==2)
		    close();
		else if(main_exit==0)
		    edit_teacher();
		else
		    {printf("\nInvalid!\a");
		    goto edit_invalid;}
	}
    else
	{printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if (main_exit==1)
	    menu();
	else
	    close();
	}
}

void erase_teacher()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("teacher.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the User ID. of the Teacher you want to remove:");
    scanf("%d",&rem.usr_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch)!=EOF)
   {
	if(add.usr_no!=rem.usr_no)
	    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch);

	else
	    {test++;
	    printf("\nRecord deleted successfully!\n");
	    }
   }
   fclose(old);
   fclose(newrec);
   remove("teacher.dat");
   rename("new.dat","teacher.dat");
   if(test==0)
	{
	    printf("\nRecord not found!!\a\a\a");
	    erase_invalid:
	      printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	      scanf("%d",&main_exit);

		 if (main_exit==1)
		    menu();
		else if (main_exit==2)
		    close();
		else if(main_exit==0)
		    erase_teacher();
		else
		    {printf("\nInvalid!\a");
		    goto erase_invalid;}
	}
    else
	{printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if (main_exit==1)
	    menu();
	else
	    close();
	}

}

void search_teacher()
{
    FILE *ptr;
    int test=0;
    int choice;
    float time;
    ptr=fopen("teacher.dat","r");
    printf("Do you want to check by\n1.User Id\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the User ID:");
	scanf("%d",&check.usr_no);

	while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch)!=EOF)
	{
	    if(add.usr_no==check.usr_no)
	    {
		clrscr();
		test=1;

		printf("\nUser ID.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s\nPhone number:%.0lf\nBranch:%s\n\n",add.usr_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.branch);


	    }
	}
    }
    else if (choice==2)
    {   printf("Enter the name:");
	scanf("%s",&check.name);
	while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch)!=EOF)
	{
	    if(add.name==check.name)
	    {
		clrscr();
		test=1;
	    printf("\nUsr ID.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s\nPhone number:%.0lf\nBranch:%s\n\n",add.usr_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone,add.branch);

	    }
	}
    }


    fclose(ptr);
     if(test!=1)
	{   system("cls");
	    printf("\nRecord not found!!\a\a\a");
	    see_invalid:
	      printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	      scanf("%d",&main_exit);
	      system("cls");
		 if (main_exit==1)
		    menu();
		else if (main_exit==2)
		    close();
		else if(main_exit==0)
		    search_teacher();
		else
		    {
			system("cls");
			printf("\nInvalid!\a");
			goto see_invalid;}
	}
    else
	{printf("\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);}
	if (main_exit==1)
	{
	    system("cls");
	    menu();
	}

	else
	   {

	     system("cls");
	    close();
	    }

}

void teacher_list()
{
int test=0;
    FILE *view;
    view=fopen("teacher.dat","r");
    clrscr();
    printf("\nUSER ID.\tNAME\t\t\tBRANCH\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s\n",&add.usr_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.subject,&add.phone,&add.branch)!=EOF)
       {
	   printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf\t\t%10s",add.usr_no,add.name,add.branch,add.phone);
	   test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

/** students **/

void student()
{
    int choice;
    clrscr();
    textcolor(9);
    gotoxy(12,1);cprintf("RAJARAJESWARI COLLEGE OF ENGINEERING MANAGEMENT SYSTEM\n");
    gotoxy(24,3);cprintf("WELCOME TO THE MAIN MENU\n");
    gotoxy(8,10);cprintf("1.Add New student\n");
    gotoxy(8,11);cprintf("2.Remove student\n");
    gotoxy(8,12);cprintf("3.Update student\n");
    gotoxy(8,13);cprintf("4.Search student\n");
    gotoxy(8,14);cprintf("5.View all\n");
    gotoxy(8,20);printf("Enter 6 to go to the main menu and 0 to exit");
    gotoxy(8,16);cprintf("Enter your Choice:");
    scanf("%d",&choice);



    clrscr();
    switch(choice)
    {
    case 0:close();
    break;
    case 1:add_student();
    break;
    case 2:erase_student();
    break;
    case 3:edit_student();
    break;
    case 4:search_student();
    break;
    case 5:student_list();
    break;
    case 6:menu();
    break;



    }



}

void add_student()

{
    int choice;
    FILE *ptr;

    ptr=fopen("student.dat","a+");
    user_no:
    clrscr();
    printf("\t\t\t\xB2\xB2\xB2\ ADD NEW student RECORD  \xB2\xB2\xB2\xB2");
    printf("\nEnter the USN:");
    scanf("%d",&checkstu.usn_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch)!=EOF)
    {
    if (checkstu.usn_no==addstu.usn_no)
        {printf("USN. already in exist!");
        delay(10000);
        goto user_no;

        }
    }
    addstu.usn_no=checkstu.usn_no;
    printf("\nEnter the name:");
    scanf("%s",&addstu.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&addstu.dob.month,&addstu.dob.day,&addstu.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&addstu.age);
    printf("\nEnter the address:");
    scanf("%s",addstu.address);
    printf("\nEnter the email:");
    scanf("%s",addstu.email);
    printf("\nEnter the phone number: ");
    scanf("%lf",&addstu.phone);
    printf("\nEnter the Branch: ");
    scanf("%s",&addstu.branch);

    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s\n",addstu.usn_no,addstu.name,addstu.dob.month,addstu.dob.day,addstu.dob.year,addstu.age,addstu.address,addstu.email,addstu.phone,addstu.branch);


    fclose(ptr);
    printf("\nstudent Added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    clrscr();

    if (main_exit==1)
    menu();
    else if(main_exit==0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void edit_student()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("student.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the USN. of the student whose info you want to change:");
    scanf("%d",&updstu.usn_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch)!=EOF)
    {
    if (addstu.usn_no==updstu.usn_no)
    {   test=1;
        printf("\nWhich information do you want to change?\n1.Address\n2.Phone\\n\nEnter your choice(1 for address and 2 for phone):");
        scanf("%d",&choice);
        system("cls");
        if(choice==1)
        {printf("Enter the new address:");
        scanf("%s",updstu.address);
        fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch);
        system("cls");
        printf("Changes saved!");
        }
        else if(choice==2)
        {
            printf("Enter the new phone number:");
        scanf("%lf",&updstu.phone);
        fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch);
        system("cls");
        printf("Changes saved!");
        }

    }
    else
        fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch);
    }
    fclose(old);
    fclose(newrec);
    remove("student.dat");
    rename("new.dat","student.dat");

if(test!=1)
    {   system("cls");
        printf("\nRecord not found!!\a\a\a");
        edit_invalid:
          printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
          scanf("%d",&main_exit);
          system("cls");
         if (main_exit==1)

            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            edit_student();
        else
            {printf("\nInvalid!\a");
            goto edit_invalid;}
    }
    else
    {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else
        close();
    }
}

void erase_student()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("student.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the USN. of the student you want to remove:");
    scanf("%d",&remstu.usn_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch)!=EOF)
   {
    if(addstu.usn_no!=remstu.usn_no)
        fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch);

    else
        {test++;
        printf("\nRecord deleted successfully!\n");
        }
   }
   fclose(old);
   fclose(newrec);
   remove("student.dat");
   rename("new.dat","student.dat");
   if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        erase_invalid:
          printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
          scanf("%d",&main_exit);

         if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            erase_student();
        else
            {printf("\nInvalid!\a");
            goto erase_invalid;}
    }
    else
    {printf("\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else
        close();
    }

}

void search_student()
{
    FILE *ptr;
    int test=0;
    int choice;
    float time;
    ptr=fopen("student.dat","r");
    printf("Do you want to check by\n1.USN\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the USN:");
    scanf("%d",&checkstu.usn_no);

    while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.email,&addstu.branch)!=EOF)
    {
        if(addstu.usn_no==checkstu.usn_no)
        {
        clrscr();
        test=1;

        printf("\nUSN.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s\nPhone number:%.0lf\nEmail:%s\nBranch:%s\n\n",addstu.usn_no,addstu.name,addstu.dob.month,addstu.dob.day,addstu.dob.year,addstu.age,addstu.address,addstu.phone,addstu.email,addstu.branch);


        }
    }
    }
    else if (choice==2)
    {   printf("Enter the name:");
    scanf("%s",&checkstu.name);
    while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.email,&addstu.branch)!=EOF)
    {
        if(addstu.name==checkstu.name)
        {
        clrscr();
        test=1;
        printf("\nusn ID.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s\nPhone number:%.0lf\nEmail:%s\nBranch:%s\n\n",addstu.usn_no,addstu.name,addstu.dob.month,addstu.dob.day,addstu.dob.year,addstu.age,addstu.address,addstu.phone,addstu.email,addstu.branch);

        }
    }
    }


    fclose(ptr);
     if(test!=1)
    {   system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
          printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
          scanf("%d",&main_exit);
          system("cls");
         if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            search_student();
        else
            {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;}
    }
    else
    {printf("\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);}
    if (main_exit==1)
    {
        system("cls");
        menu();
    }

    else
       {

         system("cls");
        close();
        }

}

void student_list()
{
int test=0;
    FILE *view;
    view=fopen("student.dat","r");
    clrscr();
    printf("\nUSN.\tNAME\t\t\tBRANCH\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s\n",&addstu.usn_no,addstu.name,&addstu.dob.month,&addstu.dob.day,&addstu.dob.year,&addstu.age,addstu.address,addstu.email,&addstu.phone,&addstu.branch)!=EOF)
       {
       printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf\t\t%10s",addstu.usn_no,addstu.name,addstu.branch,addstu.phone);
       test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

/** students end **/


void load(){
    gotoxy(40,7);printf("LOADING");
        for(i=0;i<=6;i++)
        {
            delay(1000);
            printf(".");
        }
        clrscr();
menu();
getch();
}
