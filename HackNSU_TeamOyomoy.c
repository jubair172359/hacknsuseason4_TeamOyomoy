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
    char loc[10], fid[20];
};

void main(){

    int choice; int se;
    char arrfid[20];

    printf("Please select your choice.\n1 => Departure\n2 => Arriving\n");
    printf("Yourv choice => ");
    scanf("%d", &se);

    if(se == 1){

    while(choice!=5){

    printf("\t\t\t=====: PREPAID MANAGEMENT SYSTEM :=====\n");
    printf("\t\t\t________________________________________\n\n\n\n");
    printf("\t\t\t     1: Add your transportation record\n");
    printf("\t\t\t     2: Previous Records (Admin Only)\n");
    printf("\t\t\t     3: Search yourself\n");
    printf("\t\t\t     4: Delete record (Admin Only)\n");
    printf("\t\t\t     5: Exit\n");
    printf("\t\t\t    _____________________\n\n\n\n");
    printf("\t\t\tPlease enter your choice: ");
    scanf("%d", &choice);

    switch(choice){

        case 1:

            addPass();


            break;

        case 2:

            record();
            printf("\t\t\t\t  Press any key to exit...\n");
            getch();


            break;

        case 3:

            search();
            printf("\n\t\t\t\t  Press any key to exit...\n");
            getch();


            break;

        case 4:

            delete();
            printf("\n\t\t\t\tPress any key to exit...\n");
            getch();


            break;

        case 5:

            printf("\n\t\t\t\tThanks for using this software.\n\n");
            exit(0);

            break;

        default :

            getch();
            printf("\n\t\t\t\t\tEnter a valid choice\n\n");
            printf("\t\t\t\tPress any key to continue...");
            getch();

            break;
    }

    }

    }

    else if(se == 2){
          printf("\n\n\t\t\tEnter your fingerprint ID in the following bar.");
          printf("\n\t\t\t\t\t\t==========\n\t\t\t\t\t");
          scanf("%s", &arrfid);
          printf("\n\t\t\t\t\t\t==========\n");
          printf("\n\t\t\t______________________________\n\n\n");
          printf("You have travelled 'X' km during this journey.\nBDT 'Y' has been deducted from your assisted account.\nThanks for travelling!");
          printf("\nCheck your SMS for confirmation.\n");
    }

    getch();

}

 void addPass(){

     char or;
     FILE *fp;
     int n,i;
     struct pass info;

   do{

       printf("\n\n\n\t\t\t\t=====: ADD PASSANGER INFO :=====\n");
       printf("\t\t\t\t____________________________________\n\n");
       fp=fopen("information.txt","a");

          /*printf("\n\t\t\tEnter Name        : ");
          scanf("%s",&info.firstName);*/
          printf("\n\t\t\tEnter NID number  : ");
          scanf("%lf",&info.nidNo);
          printf("\n\t\t\tEnter location    : ");
          scanf("%s",&info.loc);
          printf("\n\n\t\t\tEnter your fingerprint ID in the following bar.");
          printf("\n\t\t\t\t\t\t==========\n\t\t\t\t\t");
          scanf("%s", &info.fid);
          printf("\n\t\t\t\t\t\t==========\n");
          printf("\n\t\t\t______________________________\n");

      if(fp==NULL){
        fprintf(stderr,"Can't open your record file.");
      }

      else{
        printf("\t\t\tYour record(s) has been stored successfully.\n");
      }

    fwrite(&info, sizeof(struct pass), 1, fp);
    fclose(fp);

    printf("\n\n\t\t\tDo you want to add another record? [y/n] : ");
    scanf("%s", &or);


   }    while(or=='y'||or=='Y');
}

 void record(){

     FILE *fp;

    struct pass info;
    fp=fopen("information.txt","r");

     printf("\t\t\t\t=====: RECORD(S) :=====\n");
     printf("\t\t\t\t________________________\n\n\n\n");

    if(fp==NULL){

        fprintf(stderr, "Can't open your record file.");
        exit(0);
    }
    else{
        printf("\t\t\t\tRecord(s):\n");
    }

        while(fread(&info, sizeof(struct pass), 1, fp)){

        //printf("\n\t\t\t\t Name     : %s", info.firstName);
        printf("\n\t\t\t\t NID no   : %.1lf", info.nidNo);
        printf("\n\t\t\t\t Location : %s",  info.loc);
        printf("\n\t\t\t\t  : %s",  info.loc);
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
        printf("\t\t\t\t=====: SEARCH PASSANGER RECORD :=====\n");
        printf("\t\t\t\t_____________________________________\n");
        printf("\t\t\tEnter NID number : ");
        scanf("%lf",&nidNo);



    while(fread(&info,sizeof(struct pass),1,fp)>0){

        if(info.nidNo == nidNo){

        found = 1;

        //printf("\n\n\t\t\tName       : %s",info.firstName);
        printf("\n\t\t\tNID Number : %lf",info.nidNo);
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


 void delete(){

      struct pass info;
      FILE *fp, *fp1;


    double nidNo; int found = 0;

    printf("\t\t\t\t=====: DELETE PASSANGER RECORD :=====\n");
    printf("\t\t\t\t_________________________________________\n\n\n");
    fp = fopen("information.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\t\t\t\tEnter your NID no : ");
    scanf("%lf",&nidNo);

    if(fp==NULL){
         fprintf(stderr,"Can't open your record file. Sorry.\n");
         exit(0);
    }

    while(fread(&info, sizeof(struct pass), 1, fp)){

        if(info.nidNo == nidNo){

            found = 1;
        }

        else{

           fwrite(&info, sizeof(struct pass), 1, fp1);
        }

    }

     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\t\tRecord not found. Sorry.\n");
        }

    if(found){

        remove("information.txt");

        rename("temp.txt", "information.txt");

        printf("\n\t\t\t\tRecord has been deleted successfully.\n");
    }

  getch();
  }

