#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

void addPass();
void record();
void search();
void delete();

  struct pass {
    char firstName[20];
    double nidNo;
    char loc[10];

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
            addPass();
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

 void addPass(){

     char or;
     FILE *fp;
     int n,i;
     struct pass info;

   do{
       clrscr();
       printf("\t\t\t\t=======ADD PASSANGER INFO=======\n");
       printf("\t\t\t\t____________________________________\n\n\n");
       fp=fopen("information.txt","a");

          printf("\n\t\t\tEnter First Name  : ");
          scanf("%s",&info.firstName);

          printf("\n\t\t\tEnter NID number  : ");
          scanf("%lf",&info.nidNo);
          printf("\n\t\t\tEnter location    : ");
          scanf("%s",&info.loc);

          printf("\n\t\t\t______________________________\n");

      if(fp==NULL){
        fprintf(stderr,"Can't open your record file.");
      }

      else{
        printf("\t\t\tYour record(s) has been stored successfully.\n");
      }

    fwrite(&pass, sizeof(struct pass), 1, fp);
    fclose(fp);

    printf("\t\t\tDo you want to add another record?(y/n) : ");


    scanf("%s",&another);


   }    while(or=='y'||or=='Y');
}

 void record(){

     FILE *fp;

    struct pass info;
    fp=fopen("information.txt","r");

     printf("\t\t\t\t===== RECORD(S) =====\n");
     printf("\t\t\t\t_______________________n\n\n");

    if(fp==NULL){

        fprintf(stderr, "Can't open your record file.");
        exit(0);
    }
    else{
        printf("\t\t\t\tRecord(s):\n");
        printf("\t\t\t\t_________\n\n");
    }

        while(fread(&info, sizeof(struct pass), 1, fp)){

        printf("\n\t\t\t\t Name  : %s", info.firstName);
        printf("\n\t\t\t\t NID no   : %d", info.nidNo);
        printf("\n\t\t\t\t Location : %s",  info.loc);
        printf("\n\t\t\t\t ________________________________\n");

        }
        fclose(fp);
        getch();

  }

void search(){

      struct pass info;
      FILE *fp;
      double nidNo; int found = 0;

        fp=fopen("information.txt", "r");
        printf("\t\t\t\t=======SEARCH PASSANGER RECORD=======\n");
        printf("\t\t\t\t_________________________________________");
        printf("\t\t\tEnter NID number : ");
        scanf("%lf",&nidNo);



    while(fread(&info,sizeof(struct pass),1,fp)>0){

        if(info.nidNo == nidNo){

        found = 1;

        printf("\n\n\t\t\tName     : %s",info.firstName);
        printf("\n\t\t\tNID Number : %d",info.nidNo);
        printf("\n\t\t\tLocation   : %s",info.loc);
        printf("\n\t\t\t______________________________________\n");

        }

    }

    if(!found){

       printf("\n\t\t\tRecord not found. Sorry.\n");
    }

    fclose(fp);
    getch();

}
