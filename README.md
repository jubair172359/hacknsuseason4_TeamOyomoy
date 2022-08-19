#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

void addpass();
void record();
void search();
void delete();

  struct pass {
    char firstName[20];
    double nidNo;
    char Class[10];
    float per;
};

void main(){

    int choice;

    while(choice!=5){

    printf("\t\t\t=====PREPAID MANAGEMENT SYSTEM=====\n");
    printf("\t\t\t___________________________________\n");
    printf("\n\n\n\t\t\t\t     1. Add your transportation record\n");
    printf("\t\t\t\t     2. Previous Records (Admin Only)\n");
    printf("\t\t\t\t     3. Search yourself\n");
    printf("\t\t\t\t     4. Delete record (Admin Only)\n");
    printf("\t\t\t\t     5. Exit\n");
    printf("\t\t\t\t    _____________________\n");
    printf("\t\t\t\t     ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            clrscr();
            addpass();
            clrscr();

            break;

        case 2:
            clrscr();
            record();
            printf("\t\t\t\t  Press any key to exit...\n");
            getch();
            clrscr();

            break;

        case 3:
            clrscr();
            search();
            printf("\n\t\t\t\t  Press any key to exit...\n");
            getch();
            clrscr();

            break;

        case 4:
            clrscr();
            delete();
            printf("\n\t\t\t\tPress any key to exit...\n");
            getch();
            clrscr();

            break;
        case 5:
            clrscr();
            printf("\n\t\t\t\tThanks for using this software.\n\n");
            exit(0);

            break;

     default :
            clrscr();
            getch();
            printf("\n\t\t\t\t\tEnter a valid choice\n\n");
            printf("\t\t\t\tPress any key to continue...");
            getch();
            clrscr();
            break;
    }

    }

    getch();

}
